/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : 
* Object              : 
*
* Creation            : 
*----------------------------------------------------------------------------
*/
#ifndef _PRG_MONITOR_H
#define _PRG_MONITOR_H


#ifndef CODE_VERSION
  #define CODE_VERSION CODE_PRD // CODE_PRD or CODE_DBG (defined in project.h)
#endif


#ifdef INSERT_MEASURE_POINTS
  #warning Timing measures debug inserted: do not use for production..
  #define _MEASURE_BUSYPIN_POSITIVE_PULSE   BRD_SET_BUSY_CKOUT;BRD_CLR_BUSY_CKOUT
  #define _MEASURE_BUSYPIN_NEGATIVE_PULSE   BRD_CLR_BUSY_CKOUT;BRD_SET_BUSY_CKOUT
  #define _MEASURE_BUSYPIN_SET              BRD_SET_BUSY_CKOUT
  #define _MEASURE_BUSYPIN_CLR              BRD_CLR_BUSY_CKOUT
#else
  #define _MEASURE_BUSYPIN_POSITIVE_PULSE
  #define _MEASURE_BUSYPIN_NEGATIVE_PULSE
  #define _MEASURE_BUSYPIN_SET
  #define _MEASURE_BUSYPIN_CLR
#endif


// PRG text information, stored in binary file ////////////////////////////////
#define PRG_ID_STRING_SIZE (4*4*6)
#define PRG_ID_S1 "Serial com link used is:
#define PRG_ID_S2 #SERIAL_COM_LINK_PERIPH
#define PRG_ID_S3 .
#define PRG_ID_S4 "
#define PRG_ID_STRING_CONTENT MERGE(PRG_ID_S1,PRG_ID_S2,PRG_ID_S3,PRG_ID_S4)
//#define PRG_ID_STRING_CONTENT "Serial com link used is: ## #SERIAL_COM_LINK_PERIPH ## "
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////
#define PRG_MAX_TEST_IDENTIFIERS  (32)       //
///////////////////////////////////////////////
#define CLK_SET_USED_PARAM32 (5) //significant parameters, excluding PARAM0/TAG


// -- Ccommands definition ----------------------------------------------------
#define CMD_CHAR_DUMMY_CMD             (0)
#define CMD_CHAR_SW_RESET              ('x')
#define CMD_CHAR_RESTORE_SYSIO         ('s')
#define CMD_CHAR_GET_PRG_INFO          ('i')
#define CMD_CHAR_WRITE_WORD32          ('w')
#define CMD_CHAR_WRITE_CLK_SETTING     ('c')
#define CMD_CHAR_WRITE_TEST_PARAMETERS ('W')
#define CMD_CHAR_READ_WORD32           ('r')
#define CMD_CHAR_DUMP_AREA             ('d')
#define CMD_CHAR_READ_TEST_RESULTS     ('R')  // 'R'=82 => 48 to 81 available (34)
#define CMD_CHAR_RUN_TEST_BASE         (48)   //'0'=>TEST0, '1'=>TEST1... aso (10=':',11=';'...)

#define CMD_CHAR_BYTE_IDX        (0)
#define CMD_SIZE_BYTE_IDX        (1) 
#define CMD_CLK_SETTING_BYTE_IDX (1) //RUN_TEST command only

#define CMD_ADDR_WORD32_IDX      (1) //read or write word32 only
#define CMD_DATA_WORD32_IDX      (2) //write word32 only

#define CMD_MAX_ARG32_SW_RESET              (0)
#define CMD_MAX_ARG32_RESTORE_SYSIO         (0)
#define CMD_MAX_ARG32_GET_PRG_INFO          (0)
#define CMD_MAX_ARG32_WRITE_WORD32          (2)
#define CMD_MAX_ARG32_WRITE_CLK_SETTING     (CLK_SET_MAX_PARAM32)
#define CMD_MAX_ARG32_WRITE_TEST_PARAMETERS (TEST_MAX_PARAM32)
#define CMD_MAX_ARG32_READ_WORD32           (1)
#define CMD_MAX_ARG32_DUMP_AREA             (2)
#define CMD_MAX_ARG32_READ_TEST_RESULTS     (1)
#define CMD_MAX_ARG32_RUN_TEST              (0)

#define EOF_CMD_CHAR   (0x0D) // carriage return / enter key on terminal
#define NO_CLK_SETTING (0xFF)
#define MONITOR_RESERVED_CLK_SET (0x0)
#define MONITOR_RESERVED_TST_IDX (0x0)

#define CMD_SIZE_SW_RESET              (2+1+1+(CMD_MAX_ARG32_SW_RESET*4)+1)
#define CMD_SIZE_RESTORE_SYSIO         (2+1+1+(CMD_MAX_ARG32_RESTORE_SYSIO*4)+1)
#define CMD_SIZE_GET_PRG_INFO          (2+1+1+(CMD_MAX_ARG32_GET_PRG_INFO*4)+1)
#define CMD_SIZE_WRITE_WORD32          (2+1+1+(CMD_MAX_ARG32_WRITE_WORD32*4)+1)
#define CMD_SIZE_WRITE_CLK_SETTING     (2+1+1+(CMD_MAX_ARG32_WRITE_CLK_SETTING*4)+1)
#define CMD_SIZE_WRITE_TEST_PARAMETERS (2+1+1+(CMD_MAX_ARG32_WRITE_TEST_PARAMETERS*4)+1)
#define CMD_SIZE_READ_WORD32           (2+1+1+(CMD_MAX_ARG32_READ_WORD32*4)+1)
#define CMD_SIZE_DUMP_AREA             (2+1+1+(CMD_MAX_ARG32_DUMP_AREA*4)+1)
#define CMD_SIZE_READ_TEST_RESULTS     (2+1+1+(CMD_MAX_ARG32_READ_TEST_RESULTS*4)+1)
#define CMD_SIZE_RUN_TEST              (2+1+1+(CMD_MAX_ARG32_RUN_TEST*4)+1) // no CMD_SIZE field

#define CMD_MAX_BYTES  CMD_SIZE_WRITE_TEST_PARAMETERS //max size
// Alignement: 
//         2 dummy bytes added for alignment (not sent by tester)
//         1 byte for CMD_SIZE
//         1 byte for CMD_CHAR
//         4 bytes for each param
//         1 byte for EOF_CMD
// ----------------------------------------------------------------------------


// -- PRG monitor states definition -------------------------------------------
#define PRG_STATE_RESET        (0x00)
#define PRG_STATE_WAIT_FOR_CMD (0x01)
//#define PRG_STATE_DECODE_CMD   (0x02)
#define PRG_STATE_SEND_DATA    (0x03)
// -----------------------------------------------------------------
#define PRG_STATE_CMD_SW_RESET                 CMD_CHAR_SW_RESET
#define PRG_STATE_CMD_RESTORE_SYSIO            CMD_CHAR_RESTORE_SYSIO
#define PRG_STATE_CMD_GET_PRG_INFO             CMD_CHAR_GET_PRG_INFO
#define PRG_STATE_CMD_WRITE_WORD32             CMD_CHAR_WRITE_WORD32
#define PRG_STATE_CMD_WRITE_CLK_SETTING        CMD_CHAR_WRITE_CLK_SETTING
#define PRG_STATE_CMD_WRITE_TEST_PARAMETERS    CMD_CHAR_WRITE_TEST_PARAMETERS
#define PRG_STATE_CMD_READ_WORD32              CMD_CHAR_READ_WORD32
#define PRG_STATE_CMD_DUMP_AREA                CMD_CHAR_DUMP_AREA
#define PRG_STATE_CMD_READ_TEST_RESULTS        CMD_CHAR_READ_TEST_RESULTS
#define PRG_STATE_CMD_RUN_TEST                 CMD_CHAR_RUN_TEST_BASE
// ----------------------------------------------------------------------------


// -- Diagnosis bytes ---------------------------------------------------------
#define DIAG_BYTE_NO_EOFCMD      0xE0
#define DIAG_BYTE_UNKNOWN_STATE  0xB5
// ----------------------------------------------------------------------------



// -- Misc definitions --------------------------------------------------------
//#define PRG_RESERVED_PATTERN  (0xCAFEFADE)
#define RESTORE_SYSIO_ALLOWED (1) //To do: allow if 0 on a NC pulled-up IO
#define DUMMY_CHAR_MASTER     ('m')
#define DUMMY_CHAR_SLAVE      ('s')
#define RFU_CHAR_CMD          (0xFF)
#define TEST_IDX_TAG          (0xA0000000)
#define CLK_SET_IDX_TAG       (0xCCCC0000)
// ----------------------------------------------------------------------------


// -- I/O operations ----------------------------------------------------------
// ----------------------------------------------------------------------------



/*
// -- Communication link abstraction level ------------------------------------
#define SERIAL_COM_LINK_USED  SSPI // HW_SPI, SW_SPI, UART, USART
#define SERIAL_COM_LINK_IDX   0    // 0, 1, 2...
#include "serial_com_link.h"
// ----------------------------------------------------------------------------
*/

// -- PRG Information ---------------------------------------------------------
/*
#define PRG_CODE_REVISION (0x65103001)
// PRG_CODE_CRC            =
// PRG_CODE_REVISION       =
// PRG_CLK_SETS_BASE_ADDR  =
// PRG_TESTS_BASE_ADDR     =
// PRG_RESULTS_BASE_ADDR   =
//
// -- Other definitions to report in PRG release notes ------------------------
#define FLASH_WS (0)
*/
// ----------------------------------------------------------------------------

/*
// -- Memory mapping ----------------------------------------------------------
#define PRG_INFO_OFFSET      (0x0)
#define PRG_INFO_MAX_SIZE    (0x100)
//------------------------------------

// -- Fields definition -------------------------------------------------------
#define PRG_MAX_TESTS        (16)// Test number: Ox0 to 0xF
#define TEST_MAX_PARAM32     (8) // Parameters: 1 to 7 (0 reserved for TEST_ID)
#define TEST_MAX_RESULTS32   (32)// Results:    1 to 31 (0 reserved for TEST_ID)
#define PRG_MAX_CLK_SETS     (10)
#define CLK_SET_MAX_PARAM32  (8)
#define CLK_SET_USED_PARAM32 (5)
//#define PRG_CLK_SETS_SIZE32 (8)
// ----------------------------------------------------------------------------
//
//
//_____________________________________________________________________________
#define PRG_CLK_SETS_OFFSET  (PRG_INFO_OFFSET + PRG_INFO_MAX_SIZE)
#define PRG_CLK_SETS_SIZE    (PRG_MAX_CLK_SETS * CLK_SET_MAX_PARAM32 * 4)
#define PRG_TESTS_OFFSET     (PRG_CLK_SETS_OFFSET + PRG_CLK_SETS_SIZE)
#define PRG_TESTS_MAX_SIZE   (PRG_MAX_TESTS * TEST_MAX_PARAM32 * 4)
#define PRG_RESULTS_OFFSET   (PRG_TESTS_OFFSET + PRG_TESTS_MAX_SIZE)
#define PRG_RESULTS_MAX_SIZE (PRG_MAX_TESTS * TEST_MAX_RESULTS32 * 4)
//_____________________________________________________________________________
#define PRG_INFO_BASE_ADDR     (IRAM_ADDR + SRAM_BASE_SIZE + PRG_INFO_OFFSET)
#define PRG_CLK_SETS_BASE_ADDR (IRAM_ADDR + SRAM_BASE_SIZE + PRG_CLK_SETS_OFFSET)
#define PRG_TESTS_BASE_ADDR    (IRAM_ADDR + SRAM_BASE_SIZE + PRG_TESTS_OFFSET)
#define PRG_RESULTS_BASE_ADDR  (IRAM_ADDR + SRAM_BASE_SIZE + PRG_RESULTS_OFFSET)
// ----------------------------------------------------------------------------
*/

/*
// -- Clock settings access macro ---------------------------------------------
#define CLK_SET_PARAMETERS_PT32(idx) (volatile uint32_t*)(PRG_CLK_SETS_BASE_ADDR  \
                                            +(CLK_SET_MAX_PARAM32*4*(idx)))
#define CLK_SET_PARAMETERS_PT8(idx) (volatile uint8_t*)(PRG_CLK_SETS_BASE_ADDR  \
                                            +(CLK_SET_MAX_PARAM32*4*(idx)))
#define CLK_SET_PARAMETER(idx,param_num) (*((CLK_SET_PARAMETERS_PT32(idx))+(param_num)))
// ----------------------------------------------------------------------------

// -- Test parameters access macro --------------------------------------------
#define TEST_PARAMETERS_PT32(idx) (volatile uint32_t*)(PRG_TESTS_BASE_ADDR  \
                                            +(TEST_MAX_PARAM32*4*(idx)))
#define TEST_PARAMETERS_PT8(idx) (volatile uint8_t*)(PRG_TESTS_BASE_ADDR  \
                                            +(TEST_MAX_PARAM32*4*(idx)))
#define TEST_PARAMETER(idx,param_num) (*((TEST_PARAMETERS_PT32(idx))+(param_num)))

#define TEST_IDENTIFER(idx) ((uint8_t)((TEST_PARAMETER(idx,0))>>16))
// ----------------------------------------------------------------------------

// -- Test result access macro ------------------------------------------------
#define TEST_RESULTS_PT32(idx) (volatile uint32_t*)(PRG_RESULTS_BASE_ADDR  \
                                            +(TEST_MAX_RESULTS32*4*(idx)))
#define TEST_RESULTS_PT8(idx) (volatile uint8_t*)(PRG_RESULTS_BASE_ADDR  \
                                            +(TEST_MAX_RESULTS32*4*(idx)))
#define TEST_RESULT(idx,res_num) (*((TEST_RESULTS_PT32(idx))+(res_num)))
// ----------------------------------------------------------------------------
*/



// -- Prototypes --------------------------------------------------------------
extern void run_prg_monitor(void);
extern void pas_glop(unsigned char);
//unsigned char monitor_next_state(void);
// ----------------------------------------------------------------------------



// -- SSPI driver relative definitions ----------------------------------------
/*
// Virual SPI registers definition
#define V_REG_SPI_RDR
#define V_REG_SPI_TDR
#define V_REG_SPI_SR

typedef enum CmdMonitorModesEnum
{
    CMD_MONITOR_MODE_BUSY   ,  ///< Command Monitor is not ready for SPI communication
    CMD_MONITOR_MODE_RECEIVE,  ///< Command Monitor is waiting for REG_SSPI_RDR to be filled from MOSI channel and RDRF flag to be set
    CMD_MONITOR_MODE_TRANSMIT  ///< Command Monitor has written REG_SSPI_TDR (to be sent on MISO) and is waiting for the sending acknowledge (TDRE flag cleared)
} CmdMonitorModes;
extern CmdMonitorModes cmd_monitor_mode;
*/
// ----------------------------------------------------------------------------

/*
typedef enum COM_LINK_TYPES
{
   COM_SSPI  = 0x0,
   COM_UART  = 0x1,
   COM_USART = 0x2
}COM_LINK_TYPES_t;
*/
/*
#define SSPI  (0x0)
#define UART  (0x1)
#define USART (0x2)
*/


#endif //_PRG_MONITOR_H

