 /*-----------------------------------------------------------------------------
 *         ATMEL Microchip  Software Validation   -  ROUSSET  -
 *------------------------------------------------------------------------------
 * File Name    : ddr_initialization.c
 * Object       : 
 * Creation     : Stephan Cadene
 * Change 15-Mar-17 JPP : Adapt to Winbon die datasheet
 * Reference document 
 *  Winbond 
 *  DDR2 128 Mbits (16 MBytes) W971216KG_P07
 *  DDR2 512 Mbits (64 MBytes) W975116KG_P04
 *  DDR2 1 Gbits  (128 MBytes) W971G16SG_P02
 * Atmel 
 *  SAMA5D2 series  Atmel-11267E-ATARM-SAMA5D2-Datasheet_25-Jul-16
 *  SAMA5D2 SIP     170302_SAMA5D2 Plus DDR2 System in Package
 *----------------------------------------------------------------------------*/

#include "project.h"
#include "device.h"
#include "board.h"
#include "ddr_initialization.h" 
#include "v_chipid.h"
#include "v_utils.h"


// -----------------------------------------------------------------------------
// ----------------------  Constan definition ----------------------------------
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// ----------------------  Internal function -----------------------------------
// -----------------------------------------------------------------------------


//*-----------------------------------------------------------------------------
//* Function    : Wait 
//* Object      : Waiting Loop
//* Input       : Number of waiting loops
// output       : None 
//*-----------------------------------------------------------------------------
static void Wait (unsigned int myLoopNumber)
{
  unsigned int x;
  
  for (x=myLoopNumber ; x>0 ; x-- )
  {
    __asm("nop");
  }
}

//*-----------------------------------------------------------------------------
//* Function Name: InitDDR2_16 bits data field 
//* Object       : Initialize the DDR2
//* Input        : DDR2 description
//  output       : None 
//*-----------------------------------------------------------------------------
 void  Init_DDR2_16(const DDR2 *ddr2)  
{  
  unsigned int   dummy_value ;
   
    // Enable the DDR Controller clock signal at PMC level for the periph. ID 13
    PMC->PMC_PCR = (PMC_PCR_EN | PMC_PCR_CMD | PMC_PCR_GCKCSS_MCK_CLK | (ID_MPDDRC))    ;
    // enable ddrclk
    PMC->PMC_SCER |= PMC_SCER_DDRCK;
// -------------- Memory Device Register  :  32bit mode - DDR2 mode
  // Program the memory device type in the MPDDRC Memory Device Register
   MPDDRC->MPDDRC_MD   =  MPDDRC_MD_MD_DDR2_SDRAM |MPDDRC_MD_DBW_DBW_16_BITS ;
  // Sampling point is shifted by one cycle
   MPDDRC->MPDDRC_RD_DATA_PATH = MPDDRC_RD_DATA_PATH_SHIFT_SAMPLING_SHIFT_ONE_CYCLE;
   
// ------------------ Timing 0-3 Parameter Registers ---------------------------
  
   MPDDRC->MPDDRC_TPR0  =  ddr2->t_tras  | ddr2->t_trcd  | ddr2->t_twr    | ddr2->t_trc  | ddr2->t_trp | ddr2->t_trrd | ddr2->t_twtr | ddr2->t_tmrd;
   MPDDRC->MPDDRC_TPR1  =  ddr2->t_trfc  | ddr2->t_txsnr | ddr2->t_txsrd  | ddr2->t_txp;
   MPDDRC->MPDDRC_TPR2  =  ddr2->t_txard | ddr2->t_tards | ddr2->t_trpa   | ddr2->t_trtp | ddr2->t_tfaw; 

   MPDDRC->MPDDRC_LPR = 0;  

// --------------- Additional DDR2 setting - Hidden Registers ------------------

   dummy_value  =  MPDDRC->MPDDRC_IO_CALIBR;

   dummy_value &= ~MPDDRC_IO_CALIBR_RDIV_Msk;
   dummy_value &= ~MPDDRC_IO_CALIBR_TZQIO_Msk;

//    dummy_value |= MPDDRC_IO_CALIBR_RDIV_RZQ_40_RZQ_38_RZQ_37_RZQ_35 ;  
//       dummy_value |=  MPDDRC_IO_CALIBR_RDIV_RZQ_48_RZQ_46_RZQ_44_RZQ_43;         // winbond 128
 
      dummy_value |= MPDDRC_IO_CALIBR_RDIV_RZQ_60_RZQ_57_RZQ_55_RZQ_52 ;   // MICRON
//      dummy_value |= MPDDRC_IO_CALIBR_RDIV_RZQ_80_RZQ_77_RZQ_73_RZQ_70;
//    dummy_value |= MPDDRC_IO_CALIBR_RDIV_RZQ_120_RZQ_115_RZQ_110_RZQ_105 ;
   dummy_value |= MPDDRC_IO_CALIBR_TZQIO(76);
   dummy_value |= MPDDRC_IO_CALIBR_EN_CALIB_ENABLE_CALIBRATION;

   MPDDRC->MPDDRC_IO_CALIBR = dummy_value;

   // -------------------------- DDR2 Initialization --------------------------
   // -------------------------------------------------------------------------
   // -------------- Configuration Register  :  CAS 3, ROW 3, COLUMN 10
   MPDDRC->MPDDRC_CR    =  ddr2->n_row                  |
                           ddr2->n_col                  |
                           MPDDRC_CR_CAS_DDR_CAS3       |
                           MPDDRC_CR_DLL_RESET_DISABLED |
                           MPDDRC_CR_DQMS_NOT_SHARED    |
                           MPDDRC_CR_ENRDM_OFF          |
                           ddr2 -> n_bank               |
                           MPDDRC_CR_NDQS_DISABLED      |
                           MPDDRC_CR_UNAL_SUPPORTED     |
                           MPDDRC_CR_OCD_DDR2_EXITCALIB; 
   
   // -------------- Mode Register : command  NOP --> ENABLE CLOCK output

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_NOP_CMD;     

   *(unsigned short *)DDR_CS_ADDR  = 0x0000000;   
   
   Wait (20000);   // NEED tempo

   // A minimum pause of 200 µs is provided to precede any signal toggle
   
   // -------------- Mode Register : command  NOP --> CKE is driven high

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_NOP_CMD;       
   *(unsigned short *)DDR_CS_ADDR   = 0x0000000;
   
   // -------------- Mode Register : command  All Banks Precharge

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_PRCGALL_CMD;   
   *(unsigned short *)DDR_CS_ADDR   = 0x0000000;
     
// 7 - Mode Register : command  Extended Load Mode Register (EMRS2): Set EMR Ext Mode Reg EMR2 BA0=0 BA1=1

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_EXT_LMR_CMD;   
   *(unsigned short *)(DDR_CS_ADDR | ddr2 -> ba1)  = 0x0000000;

// - Mode Register : command  Extended Load Mode Register  (EMRS3): Set EMR Ext Mode Reg EMR3 BA0=1 BA1=1

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_EXT_LMR_CMD;   
   *(unsigned short *)(DDR_CS_ADDR | ddr2 -> ba1 | ddr2 -> ba0)  = 0x0000000; 

// Mode Register : command  Extended Load Mode Register  (EMRS1): Set EMR Ext Mode Reg EMR1 BA0=1 BA1=0
//  enable DLL and to program D.I.C. (Output Driver Impedance Control)
                                          
   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_EXT_LMR_CMD;   
   *(unsigned short *)(DDR_CS_ADDR | ddr2 -> ba0)  = 0x0000000; 

   // A minimum pause of 200 cycles of clock are required for locking DLL
   
   // Configuration Register: Enable DLL reset
   
   MPDDRC->MPDDRC_CR  |= MPDDRC_CR_DLL_RESET_ENABLED;  
   
   // Mode Register: command  Load Mode Register  (MRS) : Mode Register set (MRS) BA0=0 BA1=0 --> issue RESET DLL

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_LMR_CMD;  
   *(unsigned short *)DDR_CS_ADDR   = 0x0000000; 
      
   // -------------- Mode Register : command  All Banks Precharge
 
   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_PRCGALL_CMD;  
   *(unsigned short *)DDR_CS_ADDR   = 0x0000000; 

   // -------------- Mode Register : command  Auto-Refresh

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_RFSH_CMD;   
   *(unsigned short *)DDR_CS_ADDR   = 0x0000000;

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_RFSH_CMD;   
   *(unsigned short *)DDR_CS_ADDR   = 0x0000000;

   // -------------- Configuration Register  : disable DLL reset
   
   MPDDRC->MPDDRC_CR   &= ~MPDDRC_CR_DLL_RESET_ENABLED;  

   // -------------- Mode Register : command  Load Mode Register  (MRS) : Mode Register set (MRS) BA0=0 BA1=0 --> disable RESET DLL

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_LMR_CMD;   
   *(unsigned short *)DDR_CS_ADDR   = 0x0000000;

   // -------------- Configuration Register  : OCD default value = high
   
   MPDDRC->MPDDRC_CR   |= MPDDRC_CR_OCD_DDR2_DEFAULT_CALIB;

   // -------------- Mode Register : command  Extended Load Mode Register  (EMRS1) : set OCD default value BA0=1 BA1=0
                                          
   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_EXT_LMR_CMD;  
   *(unsigned short *)(DDR_CS_ADDR | ddr2 -> ba0)  = 0x0000;

   // -------------- Configuration Register  : OCD exit
   
   MPDDRC->MPDDRC_CR   &= ~MPDDRC_CR_OCD_DDR2_DEFAULT_CALIB;
   
   // -------------- Mode Register : command  Extended Load Mode Register  (EMRS1) : OCD exit BA0=1 BA1=0

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_EXT_LMR_CMD; 
   *(unsigned short *)(DDR_CS_ADDR | ddr2 -> ba0)  = 0x0000;

   // -------------- Mode Register : command  Normal mode

   MPDDRC->MPDDRC_MR	= MPDDRC_MR_MODE_NORMAL_CMD; 
   *(unsigned short *)DDR_CS_ADDR   = 0x0000;

   // -------------- dummy write access

   *(unsigned short *)DDR_CS_ADDR   = 0x0000;
   
    // -------------- Refresh Time Register
   
   MPDDRC->MPDDRC_RTR   =  ddr2->t_refresh  ; 
}


