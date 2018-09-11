/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : prg_monitor.c
* Object              :
*
* Creation            : ERr / Jan 2015
*----------------------------------------------------------------------------
*/
/*---------------------------------------------------------------------------
*----------------------------------------------------------------------------
* Product compliance (tested):
*                   __________________
*                   | Build  |  Exec  |
*                   -------------------
*  63917 SAMG51     |        |        |
* -------------------------------------
*  63918 SAMG53/G54 |        |        |
* -------------------------------------
*  65105 SAMG55     |        |        |
* -------------------------------------
*  65103 CANOPUS    |   OK   |   OK   |
* -------------------------------------                
*  65108 CAPELLA    |   OK   |   OK   |
* -------------------------------------
*  65100 SIRIUS     |        |        |
* -------------------------------------
*  92U01 SAMA5D2    |   OK   |   OK   |
* -------------------------------------
*        SAM9X6     |   OK   |        |
* -------------------------------------
*----------------------------------------------------------------------------
*/

//sspi_is_rdr_full () { return REG_SSPI_SR & SPI_SR_RDRF;  } ///< @return \c REG_SSPI_SR \& SPI_SR_RDRF
//sspi_is_rdr_ovres() { return REG_SSPI_SR & SPI_SR_OVRES; } ///< @return \c REG_SSPI_SR \& SPI_SR_OVRES
//sspi_is_tdr_empty() { return REG_SSPI_SR & SPI_SR_TDRE;  } ///< @return \c REG_SSPI_SR \& SPI_SR_TDRE
//sspi_is_tdr_undes(
//sspi_read_rdr()
//sspi_write_tdr(uint8_t data)
//sspi_read_sr()


// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"

// ---- Peripherals (ASF drivers) includes ----------------------------------
//#include "drivers/pio/pio.h"

// ---- VDE includes --------------------------------------------------------
#include "v_utils.h"
#include "v_clocks_management.h"


// ---- Specific includes ---------------------------------------------------
#include "cbuf.h" //circular buffer management
#include "sspi.h"
#include "prg_mode\prg_tests_list.h"
#include "prg_mode\prg_test_tools.h"
#include "prg_mode\prg_settings.h"
#include "prg_mode\prg_monitor.h"
#if (DEVICE_CORE_0_TYPE==CORE_TYPE_CA5)
  #include "prg_mode\perform.h"
#endif
//---------------------------------------------------------------------------


#if (CODE_VERSION==CODE_DBG)
#warning DEBUG_MODE !!!!!!!!!!!!!!!!
/////////////////////
#define SYST_CVR *((volatile uint32_t*)(0xE000E018))
int dbg_cnt_rx=0;
int dbg_cnt_tx=0;
uint32_t spi0_sr_history [200];
uint32_t ccycnt_history [280];
uint32_t spi0_sr_history_cnt=0;
uint32_t ccycnt_history_cnt=0;
#define _DBG_LOG_SR(ou) spi0_sr_history[spi0_sr_history_cnt++]=(sspi_read_sr()|(ou<<24))
#define _DBG_COUNT_RX  (dbg_cnt_rx++)
#define _DBG_COUNT_TX  (dbg_cnt_tx++)
#define _DBG_RAZ_COUNT (dbg_cnt_rx=dbg_cnt_tx=0)
#define _DBG_LOG_CYCCNT ccycnt_history[ccycnt_history_cnt++]=DWT->CYCCNT
/////////////////////
#else
uint32_t ccycnt_history[280];
uint32_t ccycnt_history_cnt=0;
#define _DBG_LOG_SR(ou)
#define _DBG_COUNT_RX
#define _DBG_COUNT_TX
#define _DBG_RAZ_COUNT
#define _DBG_LOG_CYCCNT
#endif


// ---- Processor cycles counter management ---------------------------------
uint32_t proc_cycles_count;
//#define INIT_CYCLE_COUNTER (proc_cycles_count=(DWT->CYCCNT))
//#define GET_CYCLE_COUNT    (proc_cycles_count=(DWT->CYCCNT)-proc_cycles_count)


#define DECLARE_CBUF_TYPE(_typename, _indexType, _entryType, _size) \
typedef struct                    \
{                                 \
    _indexType  m_getIdx;         \
    _indexType  m_putIdx;         \
    _entryType  m_entry[ _size ]; \
} CBUF_##_typename;

#define squeue_SIZE 0x100u
DECLARE_CBUF_TYPE(squeue_t, uint32_t, uint8_t, squeue_SIZE)


// ---- Global variables ----------------------------------------------------
//#pragma location = "._xxx_TBD"
#pragma data_alignment=0x10
unsigned char prg_identification_string[PRG_ID_STRING_SIZE]="Serial com link used is: XXXXXX";
//unsigned char prg_identification_string[PRG_ID_STRING_SIZE]=PRG_ID_STRING_CONTENT;

//#pragma location = "._prg_monitor_fast"
#pragma data_alignment=0x10
unsigned char received_cmd_buffer[CMD_MAX_BYTES];

//#pragma location = "._prg_monitor_fast"
unsigned char monitor_current_state;
unsigned int current_clock_set_idx;

//#pragma location = "._prg_monitor_fast"
static volatile uint8_t* data_buffer;
//static unsigned char *data_buffer;

//#pragma location = "._prg_monitor_fast"
volatile CBUF_squeue_t rx_circular_buff;
#define rx_circular_buff_SIZE squeue_SIZE

//#pragma location = "._prg_monitor_fast"
static volatile int nb_char_to_send;

uint32_t ccfg_sysio_reset_value;
uint32_t reset_cause;
volatile unsigned char restore_clocks_after_test;
extern unsigned int binary_tag; // main.c
extern unsigned int  MCK_clock_speed; // main.c
extern const prg_test_func _prg_test_table_[]; // prg_tests_list.c
extern const Clk_Setting CkSettingsInit[PRG_MAX_CLK_SETS]; // prg_sram_init_xxxxx.c


// prototypes
void monitor(void);
void monitor_tdre_handler(void);
void monitor_rdrf_handler(void);
void pas_bien(void);
void ram_data_area_init(void);
void init_default_fast_ckset(uint32_t CkSetIdx);
void init_default_monitor_ckset(uint32_t CkSetIdx);
void init_default_test_idx(uint32_t TestIdx);
void apply_monitor_clock_settings(void);
void fill_prg_info_area(uint32_t padding_pattern);
void ProcCyclesCounterInit(void);
void SysIoSetUp(void);
void SysIoRestore(void);

//----------------------------------------------------------------------------
#pragma location = ".prg_monitor"
void run_prg_monitor(void)
{
  reset_cause = (RSTC->RSTC_SR & RSTC_SR_RSTTYP_Msk);
 
  // Configure system I/Os before entering monitor!!!
  SysIoSetUp();
  _MEASURE_BUSYPIN_NEGATIVE_PULSE;//1
  
  // Configure debug proc cycles counter
  ProcCyclesCounterInit();
  _MEASURE_BUSYPIN_NEGATIVE_PULSE;//2

  // Configure low level communication link
  sspi_register_rdrf_handler(monitor_rdrf_handler);
  sspi_register_tdre_handler(monitor_tdre_handler);
  _MEASURE_BUSYPIN_NEGATIVE_PULSE;//3

  // Fill PRG_INFO area
  fill_prg_info_area(PRG_RESERVED_PATTERN);
  _MEASURE_BUSYPIN_NEGATIVE_PULSE;//4

  // RAM data area initialization
  //if((reset_cause==RSTC_SR_RSTTYP_GENERAL_RST)||(reset_cause==RSTC_SR_RSTTYP_BACKUP_RST))
     {ram_data_area_init();}
  #warning To do only in case of SRAM content loss!  
/*
  if (check_reset_source()==RSTC_SR_RSTTYP_GENERAL_RST)
  //if (check_reset_source()==RSTC_SR_RSTTYP_BACKUP_RST)
    {ram_data_area_init();}
*/
  _MEASURE_BUSYPIN_NEGATIVE_PULSE;//5

  // Set default tests:
  //   =>configure test ID0 at IDX0 (reserved test to change monitor frequency)
  init_default_test_idx(MONITOR_RESERVED_TST_IDX);
  _MEASURE_BUSYPIN_NEGATIVE_PULSE;//6
  
  // Set clocks with default configuration for monitor => ~35-40ms
  init_default_monitor_ckset(MONITOR_RESERVED_CLK_SET);
  apply_monitor_clock_settings();
  current_clock_set_idx = MONITOR_RESERVED_CLK_SET;
  _MEASURE_BUSYPIN_NEGATIVE_PULSE;//7
  //#warning Clock setting moved after RAM init
  
#warning fast clock configured in clk set 1: to document...
  init_default_fast_ckset(1);
  _MEASURE_BUSYPIN_NEGATIVE_PULSE;//8
  
  // Run monitor
  monitor_current_state = PRG_STATE_RESET;
  EnableICache();
  _MEASURE_BUSYPIN_NEGATIVE_PULSE;//9
  #warning iCache enable
  monitor();
}
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
#pragma location = ".prg_monitor_fsm"
//#pragma location = ".prg_monitor"
//#pragma location = ".itcm_code"
void monitor(void)
{
 unsigned char* const received_cmd = received_cmd_buffer+2; //2 dummy bytes for alignment
 unsigned char test_idx, test_id, nb_param, clk_set;
 uint32_t prg_info_base_addr_var;
 uint32_t *addr32;
 uint32_t test_descriptor;
 uint32_t i;

  _DBG_RAZ_COUNT; //debug only
  
  while(1){
    switch(monitor_current_state){
      // ----------------------------------------------------------------------
      case PRG_STATE_RESET:
        prg_info_base_addr_var = PRG_INFO_BASE_ADDR;
        CBUF_Init(rx_circular_buff);
        COM_LINK_RESET;
        SET_RX_MODE;
        monitor_current_state = PRG_STATE_WAIT_FOR_CMD;
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_WAIT_FOR_CMD:
        _DBG_LOG_SR(0x60);
        SET_RX_MODE;
        _DBG_LOG_SR(0x061);
        BRD_CLR_BUSY_CKOUT; //BUSY=0
        while(CBUF_IsEmpty(rx_circular_buff));
        received_cmd[0]=CBUF_Pop(rx_circular_buff);
        while(CBUF_IsEmpty(rx_circular_buff));
        received_cmd[1]=CBUF_Pop(rx_circular_buff);
        
        #warning timeout to manage ? (any while(CBUF_IsEmpty(....)); statement)
        if(received_cmd[CMD_CHAR_BYTE_IDX]<(CMD_CHAR_RUN_TEST_BASE+PRG_MAX_TESTS)){//run test command
          while(CBUF_IsEmpty(rx_circular_buff));
          if((CBUF_Pop(rx_circular_buff))!=EOF_CMD_CHAR){ //sanity check
            pas_glop(DIAG_BYTE_NO_EOFCMD);
            }
          else{ //run test
            monitor_current_state = PRG_STATE_CMD_RUN_TEST;
            }
          }
        else{ //other command: command length to manage
          for(i=2;i<received_cmd[CMD_SIZE_BYTE_IDX];++i){
            while(CBUF_IsEmpty(rx_circular_buff));
            received_cmd[i]=CBUF_Pop(rx_circular_buff);
            }
          if((received_cmd[i-1])!=EOF_CMD_CHAR){ //sanity check
            pas_glop(DIAG_BYTE_NO_EOFCMD);
            }
          else {monitor_current_state = received_cmd[CMD_CHAR_BYTE_IDX];}
          #warning Possible only because PRG_STATE_CMD_xxx = CMD_CHAR_xxx
          }
        BRD_SET_BUSY_CKOUT; //BUSY=1
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_CMD_SW_RESET: // DUT software reset
        REG_RSTC_CR = RSTC_CR_KEY_PASSWD | RSTC_CR_PROCRST;
        monitor_current_state = PRG_STATE_WAIT_FOR_CMD; // not reachable
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_CMD_RESTORE_SYSIO: // Restore JTAG link & ERASE pin
        if(RESTORE_SYSIO_ALLOWED){
          SysIoRestore();
          }
        monitor_current_state = PRG_STATE_WAIT_FOR_CMD;
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_CMD_GET_PRG_INFO: // 4 bytes to send to tester
        data_buffer = (uint8_t*)(&prg_info_base_addr_var);
        nb_char_to_send = 4;
        monitor_current_state = PRG_STATE_SEND_DATA;
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_CMD_WRITE_WORD32: // address & data stored in command
        addr32 = (uint32_t*)(*((uint32_t*)(received_cmd+2)));
        (*addr32)=(uint32_t)(*((uint32_t*)(received_cmd+2+4)));
        monitor_current_state = PRG_STATE_WAIT_FOR_CMD;
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_CMD_WRITE_CLK_SETTING:
        clk_set = received_cmd[2]; //index
        //addr32 = ((uint32_t*)PRG_CLK_SETS_BASE_ADDR)+(CLK_SET_MAX_PARAM32*received_cmd[2]);
        //*(addr32)= CLK_SET_IDX_TAG | clk_set;
        CLK_SET_PARAMETER(clk_set,0)=(CLK_SET_IDX_TAG|clk_set);
        for(i=1;i<=CLK_SET_USED_PARAM32;++i){
          CLK_SET_PARAMETER(clk_set,i)=(*(((uint32_t*)(received_cmd+2))+i));
          //*(addr32+i)=(*(((uint32_t*)(received_cmd+2))+i));
          }
        monitor_current_state = PRG_STATE_WAIT_FOR_CMD;
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_CMD_WRITE_TEST_PARAMETERS:
        test_idx = received_cmd[2];
        test_id  = received_cmd[3];
        nb_param = received_cmd[4];
        test_descriptor=TEST_IDX_TAG|(test_idx<<24)|(test_id<<16)|(nb_param<<8);
        TEST_PARAMETER(test_idx,0)=test_descriptor;
        for(i=1;i<received_cmd[4];++i){
          TEST_PARAMETER(test_idx,i)=(*(((uint32_t*)(received_cmd+2))+i));
          }
        for(;i<TEST_MAX_PARAM32;++i) //RAZ unused parameters
          {TEST_PARAMETER(test_idx,i)=0x00000000;}
        monitor_current_state = PRG_STATE_WAIT_FOR_CMD;
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_CMD_READ_WORD32: // 4 bytes to send to tester
        data_buffer = (uint8_t*)(*((uint32_t*)(received_cmd+2)));
        nb_char_to_send = 4;
        monitor_current_state = PRG_STATE_SEND_DATA;
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_CMD_DUMP_AREA: // N bytes to send to tester
        data_buffer = (uint8_t*)(*((uint32_t*)(received_cmd+2)));
        nb_char_to_send = (*((uint32_t*)(received_cmd+6)));
        monitor_current_state = PRG_STATE_SEND_DATA;
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_CMD_READ_TEST_RESULTS: // N bytes to send to tester
        //data_buffer = (unsigned char*)(PRG_RESULTS_BASE_ADDR+((TEST_MAX_RESULTS32*4)*received_cmd[2]));
        test_idx = received_cmd[2];
        data_buffer = TEST_RESULTS_PT8(test_idx);
        nb_char_to_send = 4*(received_cmd[5]);
        monitor_current_state = PRG_STATE_SEND_DATA;
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_CMD_RUN_TEST:
        test_idx = received_cmd[CMD_CHAR_BYTE_IDX]-CMD_CHAR_RUN_TEST_BASE;
        clk_set = received_cmd[CMD_CLK_SETTING_BYTE_IDX];
        if(clk_set==NO_CLK_SETTING){
          restore_clocks_after_test=0;
          clk_set=current_clock_set_idx; //no clk set to apply
          }
        else{
          restore_clocks_after_test=1;
          clk_apply_settings((Clk_Setting*)(CLK_SET_PARAMETERS_PT32(clk_set)));
          current_clock_set_idx=clk_set; //new clk set to applied
          }
        test_id = TEST_IDENTIFER(test_idx);
        TEST_RESULT(test_idx,0)=TEST_PARAMETER(test_idx,0); //test descriptor
        INIT_CYCLE_COUNTER;
        // =>
        _prg_test_table_[test_id](test_idx,clk_set); //test function call
        // =>
        TEST_RESULT(test_idx,1)=GET_CYCLE_COUNT;
        if(restore_clocks_after_test){apply_monitor_clock_settings();}
#warning To add: restore I/O configuration for PRG communication
        monitor_current_state = PRG_STATE_WAIT_FOR_CMD;
        break;
      // ----------------------------------------------------------------------
      case PRG_STATE_SEND_DATA: // send N bytes to tester
        _DBG_LOG_SR(0x1);//debug only
        SET_TX_MODE;
        _DBG_LOG_SR(0x2);//debug only
        while(nb_char_to_send>0);
        sspi_set_mode(SSPI_MODE_DISABLED);//disable_interrupt(SSPI_IRQn);
        _DBG_LOG_SR(0x3);//debug only
        while(!sspi_is_tdr_empty()); // wait for last char transmission start
        _DBG_LOG_SR(0x31);//debug only
        //while(!sspi_is_tx_empty());  // eof last char transmit
        while(!sspi_has_nss_rised());  // wait next chip select rising edge
        _DBG_LOG_SR(0x32);//debug only
        sspi_read_rdr();             // flush rx to clear RDRF flag
        //sspi_set_mode(SSPI_MODE_DISABLED);
        #warning timeouts to manage ? 
        //while(!sspi_is_rdr_full());
        //sspi_read_rdr(); // flush rx buffer    

        _DBG_LOG_SR(0x4);//debug only
#warning To confirm: ERr cleaning//SET_RX_MODE;
        _DBG_LOG_SR(0x5);//debug only
        monitor_current_state = PRG_STATE_WAIT_FOR_CMD;
        break;
      // ----------------------------------------------------------------------
      default: //unsupported state
        pas_glop(DIAG_BYTE_UNKNOWN_STATE);
        break;
      }//monitor main switch
  }//while
}//monitor
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// -- Generic SPI handler (HW SPI or emulated)
//----------------------------------------------------------------------------
//#pragma location = ".prg_monitor"
//#pragma location = ".itcm_code"
#pragma inline=forced
inline void monitor_tdre_handler()
{
  _DBG_LOG_SR(0x10);//debug only
  _DBG_COUNT_TX;    //debug only
  
  _MEASURE_BUSYPIN_CLR; //Timing measure mode only
  sspi_write_tdr(*(data_buffer++));
  _MEASURE_BUSYPIN_SET; //Timing measure mode only
  //_MEASURE_BUSYPIN_NEGATIVE_PULSE; //Timing measure mode only

  --nb_char_to_send;
  _DBG_LOG_SR(0x11); //debug only
}

//#pragma location = ".prg_monitor"
//#pragma location = ".itcm_code"
#pragma inline=forced
inline void monitor_rdrf_handler()
{
  _DBG_LOG_SR(0x20); //debug only
  _DBG_COUNT_RX; //debug only
 
  //_MEASURE_BUSYPIN_POSITIVE_PULSE; //Timing measure mode only
  _MEASURE_BUSYPIN_SET; //Timing measure mode only
  CBUF_Push(rx_circular_buff,RX_CHAR);
  _MEASURE_BUSYPIN_CLR; //Timing measure mode only
  
  _DBG_LOG_SR(0x21); //debug only
}

/// This function can be used as a true interrupt handler or as an emulated one
//#pragma location = ".prg_monitor"
//#pragma location = ".itcm_code"
//void COM_LINK_HANDLER()
__ramfunc void COM_LINK_HANDLER()
{
 _DBG_LOG_CYCCNT; //debug only
 _DBG_LOG_CYCCNT; //debug only
 const uint32_t spi_sr = sspi_read_sr();
 
  if (sspi_get_mode() & SSPI_MODE_RECEIVE){
    if((spi_sr & SPI_SR_RDRF) != 0){monitor_rdrf_handler();}
    }    
  if (sspi_get_mode() & SSPI_MODE_TRANSMIT){
    if((spi_sr & SPI_SR_TDRE) != 0){monitor_tdre_handler();}
    }
 _DBG_LOG_CYCCNT; //debug only
 _DBG_LOG_CYCCNT; //debug only
}

//----------------------------------------------------------------------------
// -- PIO handlers for SPI emulation
//----------------------------------------------------------------------------
#ifndef SSPI_WRAPPER_SPI_IDX
/// overload the weak, predefined PIO IRQ handlers
#if (BRD_ID_PIO_NSS == ID_PIOA)
#pragma location = ".prg_monitor"
void PIOA_IrqHandler()
{
    const uint32_t pioa_isr = REG_PIOA_ISR;

    if ((pioa_isr & BRD_NSS_MASK) != 0)
        sspi_nss_handler();
#ifdef SSPI_IRQ_ON_SPCK
    else if ((pioa_isr & BRD_SPCK_MASK) != 0)
        sspi_spck_handler();
#endif
    // else handle other PIO interrupt sources
}
#elif (BRD_ID_PIO_NSS == ID_PIOB)
#pragma location = ".prg_monitor"
void PIOB_IrqHandler()
{
    const uint32_t piob_isr = REG_PIOB_ISR;

    if ((piob_isr & BRD_NSS_MASK) != 0)
        sspi_nss_handler();
    // else handle other PIO interrupt sources
}
#elif (BRD_ID_PIO_NSS == ID_PIOC)
#pragma location = ".prg_monitor"
void PIOC_IrqHandler()
{
    const uint32_t pioc_isr = REG_PIOC_ISR;

    if ((pioc_isr & BRD_NSS_MASK) != 0)
        sspi_nss_handler();
    // else handle other PIO interrupt sources
}
#elif (BRD_ID_PIO_NSS == ID_PIOD)
#pragma location = ".prg_monitor"
void PIOD_IrqHandler()
{
    const uint32_t piod_isr = REG_PIOD_ISR;

    if ((piod_isr & BRD_NSS_MASK) != 0)
        sspi_nss_handler();
    // else handle other PIO interrupt sources
}
#elif (BRD_ID_PIO_NSS == ID_PIOE)
#pragma location = ".prg_monitor"
void PIOE_IrqHandler()
{
    const uint32_t pioe_isr = REG_PIOE_ISR;

    if ((pioe_isr & BRD_NSS_MASK) != 0)
        sspi_nss_handler();
    // else handle other PIO interrupt sources
}
#endif
#endif



//----------------------------------------------------------------------------
// -- Infinite error loop
//----------------------------------------------------------------------------
#pragma location = ".prg_monitor"
void pas_glop(unsigned char diagnosis)
{
#warning wait tdre?
  sspi_write_tdr(diagnosis);
  while(1){
    BRD_SET_BUSY_CKOUT;
    wait_time(500);//for(int i=10000;--i;);
    BRD_CLR_BUSY_CKOUT;
    wait_time(500);//for(int i=10000;--i;);
    }
}


//----------------------------------------------------------------------------
// -- Initialize RAM data area
//----------------------------------------------------------------------------
void ram_data_area_init(void)
{
  // Initialize clock settings area
  for(int i=0;i<PRG_MAX_CLK_SETS;++i){
/*    
    for(int j=0;j<CLK_SET_MAX_PARAM32;++j){
      CLK_SET_PARAMETER(i,j)=0xCCCCCCCCu;
      }
*/  
    *((Clk_Setting*)CLK_SET_PARAMETERS_PT32(i))=CkSettingsInit[i];
    }
  // Initialize test definitions area
  for(int i=0;i<PRG_MAX_TESTS;++i){
    for(int j=0;j<TEST_MAX_PARAM32;++j){
      TEST_PARAMETER(i,j)=0xAAAAAAAAu;
      }
    }

  // Initialize test results area
  for(int i=0;i<PRG_MAX_TESTS;++i){
    for(int j=0;j<TEST_MAX_RESULTS32;++j){
      TEST_RESULT(i,j)=0xBBBBBBBBu;
      }
    }
  
  // Copy PRG identification string at beginning of shared buffer
  for(int i=0;i<PRG_ID_STRING_SIZE;++i){
    *(((unsigned char*)PRG_SHARED_BUFFER_ADDR)+i)=prg_identification_string[i];
    }


}


//----------------------------------------------------------------------------
// -- Init test index with default configuration
//----------------------------------------------------------------------------
#pragma location = ".prg_monitor"
void init_default_test_idx(uint32_t TestIdx)
{ 
 TestParamSet *test;

  test = (TestParamSet*)TEST_PARAMETERS_PT32(TestIdx);
  test->TEST_DESCIPTOR = 0xA0000000u;
  for(int i=1;i<TEST_MAX_PARAM32;++i){
    test->TEST_PARAMS[i-1] = 0x00000000u;
    }
}


//----------------------------------------------------------------------------
// -- Init CK set with default configuration for monitor
//----------------------------------------------------------------------------
#pragma location = ".prg_monitor"
void init_default_fast_ckset(uint32_t CkSetIdx)
{ 
 Clk_Setting *clk_set;

  clk_set = (Clk_Setting*)CLK_SET_PARAMETERS_PT32(CkSetIdx);
  clk_set->CLK_SET_TAG       = FAST_CKSET_TAG | TAG_IDX(CkSetIdx);
  clk_set->CLK_SET_MAIN_CK   = FAST_CKSET_MAIN_CK;
  clk_set->CLK_SET_MASTER_CK = FAST_CKSET_MASTER_CK;
  clk_set->CLK_SET_PLL       = FAST_CKSET_PLL;
  clk_set->CLK_SET_SLOW_CK   = FAST_CKSET_SLOW_CK;
  clk_set->CLK_SET_EFC       = FAST_CKSET_EFC; //Used on MCUs only
}


//----------------------------------------------------------------------------
// -- Init CK set with default configuration for monitor
//----------------------------------------------------------------------------
#pragma location = ".prg_monitor"
void init_default_monitor_ckset(uint32_t CkSetIdx)
{ 
 Clk_Setting *clk_set;

  clk_set = (Clk_Setting*)CLK_SET_PARAMETERS_PT32(CkSetIdx);
  clk_set->CLK_SET_TAG       = MONITOR_CKSET_TAG | TAG_IDX(CkSetIdx);
  clk_set->CLK_SET_MAIN_CK   = MONITOR_CKSET_MAIN_CK;
  clk_set->CLK_SET_MASTER_CK = MONITOR_CKSET_MASTER_CK;
  clk_set->CLK_SET_PLL       = MONITOR_CKSET_PLL;
  clk_set->CLK_SET_SLOW_CK   = MONITOR_CKSET_SLOW_CK;
  clk_set->CLK_SET_EFC       = MONITOR_CKSET_EFC;
}


//----------------------------------------------------------------------------
// -- Set clocks with default configuration for monitor
//----------------------------------------------------------------------------
#pragma location = ".prg_monitor"
void apply_monitor_clock_settings(void)
{ 
  clk_apply_settings((Clk_Setting*)(CLK_SET_PARAMETERS_PT32(MONITOR_RESERVED_CLK_SET)));
  
  
/*
  //Configure clocks on fastest RC available (no PLL)

  REG_PMC_WPMR = PMC_WPMR_WPKEY_PASSWD | 0x00; // Unprotect PMC
  
  pmc_switch_mck_to_sclk(PMC_MCKR_PRES_CLK_1);
#warning: switch on SLK will impact timings for startup and return from tests!
  
  pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_12_MHz>>CKGR_MOR_MOSCRCF_Pos); 
  //REG_CKGR_MOR = PRG_MONITOR_MOR_VAL;
  //while (!(PMC->PMC_SR & PMC_SR_MOSCRCS));//Wait the Fast RC to stabilize
  //while (!(PMC->PMC_SR & PMC_SR_MOSCSELS));//Wait Fast RC selection done
  
  REG_PMC_MCKR = PMC_MCKR_CSS_MAIN_CLK | PMC_MCKR_PRES_CLK_1;
  REG_PMC_WPMR = PMC_WPMR_WPKEY_PASSWD | PMC_WPMR_WPEN; // Protect PMC
 
  // ------------ Define Master Clock speed (global)
  MCK_clock_speed = 12000000; //12MHz RC
#warning not generic

  // Configure flash wait states on MCU products
  #if(DEVICE_HAS_EFC0==1)
  #endif
  #if(DEVICE_HAS_EFC1==1)
    REG_EFC0_FMR = (REG_EFC0_FMR&(~EEFC_FMR_FWS_Msk)|(EEFC_FMR_FWS(PRG_MONITOR_FLASH_WS)));
    REG_EFC1_FMR = (REG_EFC1_FMR&(~EEFC_FMR_FWS_Msk)|(EEFC_FMR_FWS(PRG_MONITOR_FLASH_WS)));
  #elif (DEVICE_HAS_EFC==1)
    REG_EFC_FMR = (REG_EFC_FMR&(~EEFC_FMR_FWS_Msk)|(EEFC_FMR_FWS(PRG_MONITOR_FLASH_WS)));
  #endif
*/
}



//----------------------------------------------------------------------------
// -- Fill PRG information area
//----------------------------------------------------------------------------
void fill_prg_info_area(uint32_t padding_pattern)
{
 uint32_t i;

  i=0;
  PRG_INFO(i++) = PRG_CODE_REVISION | CODE_VERSION;
  PRG_INFO(i++) = binary_tag;
  PRG_INFO(i++) = PRG_CLK_SETS_BASE_ADDR;
  PRG_INFO(i++) = PRG_TESTS_BASE_ADDR;
  PRG_INFO(i++) = PRG_RESULTS_BASE_ADDR;
  PRG_INFO(i++) = (uint32_t)PRG_SHARED_BUFFER_ADDR;
  PRG_INFO(i++) = reset_cause;
  for(;i<PRG_INFO_MAX_WORD32;i++){
    PRG_INFO(i) = padding_pattern;
    }
}


void ProcCyclesCounterInit(void)
{
#if (DEVICE_CORE_0_TYPE==CORE_TYPE_CM7)
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  //#warning The following line applies only to Cortex-M7 based products
  DWT->LAR = 0xC5ACCE55; //unlock access to DWT
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
  DWT->CYCCNT=0;
#elif (DEVICE_CORE_0_TYPE==CORE_TYPE_CA5)
  PMN_Reset();
  #warning cycle counter management still to implement on A5!!!
#else
  #error cycle counter not implemented on this product!!!
#endif
}


void SysIoSetUp(void)
{
//#if (CAPELLA || CANOPUS)
#if (CANOPUS==1)
  // Configure PIO instead of ERASE and JTAG functions
  ccfg_sysio_reset_value = REG_MATRIX_CCFG_SYSIO;
    #warning CCFG_SYSIO config commented for dev only 
  /*
  REG_MATRIX_CCFG_SYSIO |= (MATRIX_CCFG_SYSIO_SYSIO4 |MATRIX_CCFG_SYSIO_SYSIO5 \
                           |MATRIX_CCFG_SYSIO_SYSIO6 |MATRIX_CCFG_SYSIO_SYSIO7 \
                           |MATRIX_CCFG_SYSIO_SYSIO12);
  */
  
#elif (CAPELLA==1)
  #warning System I/Os management still to implement on CAPELLA!!!
#elif (SAMA5D2)
  #warning System I/Os management still to implement on SAMA5D2!!!
#elif (SAM9X6)
  #warning System I/Os management still to implement on SAM9X6!!!
#else
  #error System I/Os management not implemented on this product!!!
#endif
}


void SysIoRestore(void)
{
//#if (CAPELLA || CANOPUS)
#if (CANOPUS==1)
  REG_MATRIX_CCFG_SYSIO = ccfg_sysio_reset_value;
#elif (CAPELLA==1)
  #warning System I/Os management still to implement on CAPELLA!!!
#elif (SAMA5D2)
  #warning System I/Os management still to implement on SAMA5D2!!!
#elif (SAM9X6)
  #warning System I/Os management still to implement on SAM9X6!!!
#else
  #error System I/Os management not implemented on this product!!!
#endif
}
