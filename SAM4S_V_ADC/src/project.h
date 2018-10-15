#ifndef _PROJECT_H
#define _PROJECT_H
// ----------------------------------------------------------------------------
//  Device (one define only)
//A
//B
//#define __SAM4S2C__
//A
//B
//#define __SAM4S4C__
//#define __SAM4S8B__
//#define __SAM4S8C__
//#define __SAM4S16B__
//#define __SAM4S16C__
//#define __SAM4SA16B__
//#define __SAM4SA16C__
//#define __SAM4SD16B__
//#define __SAM4SD16C__
//#define __SAM4SD32B__
#define __SAM4SD32C__
// ----------------------------------------------------------------------------
//  Package
//#define DEVICE_PACKAGE _QFP64_
#define DEVICE_PACKAGE _QFP100_
// ----------------------------------------------------------------------------
// Board (one define only)
#define SAM4S_XPLAINED_PRO
// ----------------------------------------------------------------------------


#include "global.h"
// ----------------------------------------------------------------------------
//  Clock config
// ----------------------------------------------------------------------------
#define MAIN_CLK_CONFIG  USE_XTAL  // USE_RC_xMHZ or USE_EXT_CLK or USE_XTAL
#define MCK_CONFIG  USE_PLLA  // USE_MAIN_CLK or USE_PLLx or USE_SLOW_CLK
#define PLLA_MUL 10
#define PLLA_DIV 1
#define PLLB_MUL 8
#define PLLB_DIV 2
#define PCK_PRESCALER   1             // divider value 1,8,16,32,64
#define SLOW_CLK_CONFIG USE_RC_32KHZ  // USE_RC_32KHZ or USE_EXT_CLK or USE_XTAL
#define EXT_CLOCK_FREQ  1200000       // Value (Hz) (for external clock only)
#define SLOW_CLOCK_FREQ 32768         // Value (Hz)
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//  Debug configuration
// ----------------------------------------------------------------------------
#define USE_PCK                 (1)
#define USE_DEBUG_MENU          (1)             // 1=enable 0=disable
#define DEBUG_MODE              (SERIAL_DEBUG)  // SERIAL_DEBUG or NO_DEBUG
#define DEBUG_LINK_USED         UART            // DBG_UNIT,UART,USART... (board dependant)
#define DEBUG_LINK_NUMBER       1               // X for UARTX Nothing for DBG_UNIT)
#define DEBUG_BAUD_RATE         (9600)          // Value (bauds)
#define ERRLOG_MODE             (ISRAM)         // ISRAM, FLASH or NONE
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//  User reset
// ----------------------------------------------------------------------------
#define ENABLE_USER_RESET 1       // 1=enable 0=disable
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//  Watchdog Timer
// ----------------------------------------------------------------------------
#define ENABLE_WDT 0       // 1=enable 0=disable
#define WDT_TIME   5000    // value (ms) or WDT_MAX
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//  Supply Controller settings
// ----------------------------------------------------------------------------
#define ENABLE_VREG 1       // Internal Voltage Regulator: 1=enable 0=disable
#define ENABLE_BOD  1       // Brownout detector: 1=enable 0=disable

#define ENABLE_SM    1                   // 1=enable 0=disable
#define SM_THRESHOLD SUPC_SMMR_SMTH_2_80V // Supply monitor threshold
//SUPC_SMMR_SMTH_x_xV : between UPC_SMMR_SMTH_1_9V and UPC_SMMR_SMTH_3_4V 
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#if ((DEBUG_MODE==SERIAL_DEBUG)||USE_DEBUG_MENU)
  #define USE_DEBUG
#endif
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
#define MAX_CODE_SIZE (0x7FE0) //(0x8000-0x20)
// WARNING: update .icf and project link options when changing this value

#define FLASH_TAG_ADDR (unsigned int*)(IFLASH_ADDR+MAX_CODE_SIZE+0x1C)//FLASH config
#define ISRAM_TAG_ADDR (unsigned int*)(IRAM_ADDR+MAX_CODE_SIZE+0x1C)  //ISRAM config

#ifdef _LINK_TO_ISRAM_ // defined in IAR project options
  #define BINARY_TAG_ADDR   ISRAM_TAG_ADDR
#else
  #define BINARY_TAG_ADDR   FLASH_TAG_ADDR // default=FLASH config
#endif

//#define DEFAULT_BINARY_TAG (0xDEFA0000)

// IAR definitions 
#define INFO_SECTION _Pragma("location=\".info_section\"") // .icf definition
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//   Advanced debug Macros 
// ----------------------------------------------------------------------------

//DEMOS
#define DEMO_PIPELINE                   (0)
#define DEMO_PIO_MEASURE_ATOMIC         (0)
#define DEMO_PIO_MEASURE_CALL           (1)

//BUG LIST 
#define BUG_WDT                         (0)
#define BUG_PRINTF                      (0)
#define IT_PIO_L1_BUG                   (0)
#define IT_PIO_L2_BUG                   (0)



//#define DONT_USE_CMSIS_INIT //system_samxxx files


#endif /* _PROJECT_H */

