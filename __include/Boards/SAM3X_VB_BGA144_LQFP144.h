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
#ifndef _SAM3X_VB_BGA144_LQFP144_H
#define _SAM3X_VB_BGA144_LQFP144_H

//---------------------------------------------------------------------------
//    Board level definitions
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// !!!!! SAM3X-VB definitions !!!!!!
// --------------------------------------------
// |    Board       |        PIO              |
// ____________________________________________
// | UART     (J13) |  PA8=URXD  / PA9=UTXD   |   
// | USART1   (J14) |  PA12=RXD1 / PA13=TXD1  |
// | Power LED (D2) |  PA19 (1 => LED On)     |
// | Gr LED    (D3) |  PA20 (1 => LED off)    |
// | Bl LED    (D4) |  PA21 (1 => LED off)    |
// | RClick   (BP4) |  PA10 (push => 0)       |
// | LClick   (BP5) |  PA11 (push => 0)       |
// ============================================
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


#include "device.h"



/*----------------------------------------------------------------------------*/
/* -------- General purpose I/Os                                              */
/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (0)
#define BRD_PIOC_HAS_IO (0)
#define BRD_PIOD_HAS_IO (0)
//#define BRD_PIOE_HAS_IO (0)
//#define BRD_PIOF_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- GPIO: LEDs definition (outputs)                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_D2  PIOA
#define BRD_BASE_PIO_D3  PIOA
#define BRD_BASE_PIO_D4  PIOA
#define BRD_ID_PIO_D2    ID_PIOA
#define BRD_ID_PIO_D3    ID_PIOA
#define BRD_ID_PIO_D4    ID_PIOA
#define BRD_D2_MASK      (1<<19)  // PA19 POWER LED
#define BRD_D3_MASK      (1<<20)  // PA20
#define BRD_D4_MASK      (1<<21)  // PA21

#define BRD_D2_POLARITY 1 // (1 => LED On)
#define BRD_D3_POLARITY 0 // (0 => LED On)
#define BRD_D4_POLARITY 0 // (0 => LED On)

#define BRD_PIOA_LED_MASK  (BRD_D2_MASK|BRD_D3_MASK|BRD_D4_MASK)
#define BRD_PIOB_LED_MASK  (0) // none
#define BRD_PIOC_LED_MASK  (0) // none
#define BRD_PIOD_LED_MASK  (0) // none
//#define BRD_PIOE_LED_MASK  (0) // none
//#define BRD_PIOF_LED_MASK  (0) // none

#define BRD_TURN_ON_D2   pio_set(BRD_BASE_PIO_D2,BRD_D2_MASK)
#define BRD_TURN_OFF_D2  pio_clear(BRD_BASE_PIO_D2,BRD_D2_MASK)
#define BRD_TOGGLE_D2    pio_toggle(BRD_BASE_PIO_D2,BRD_D2_MASK)
#define BRD_TURN_ON_D3   pio_clear(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TURN_OFF_D3  pio_set(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TOGGLE_D3    pio_toggle(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TURN_ON_D4   pio_clear(BRD_BASE_PIO_D4,BRD_D4_MASK)
#define BRD_TURN_OFF_D4  pio_set(BRD_BASE_PIO_D4,BRD_D4_MASK)
#define BRD_TOGGLE_D4    pio_toggle(BRD_BASE_PIO_D4,BRD_D4_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- GPIOs: inputs definition                                          */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_BP4   PIOA
#define BRD_BASE_PIO_BP5   PIOA
#define BRD_ID_PIO_BP4     ID_PIOA
#define BRD_ID_PIO_BP5     ID_PIOA
#define BRD_BP4_MASK       (1<<10)	// PA10
#define BRD_BP5_MASK       (1<<11)	// PA11

#define BRD_PIOA_INPUT_MASK    (BRD_BP4_MASK | BRD_BP5_MASK)
#define BRD_PIOB_INPUT_MASK    (0) // none
#define BRD_PIOE_INPUT_MASK    (0) // none
#define BRD_PIOF_INPUT_MASK    (0) // none
//#define BRD_PIOB_INPUT_MASK    (0) // none
//#define BRD_PIOC_INPUT_MASK    (0) // none

#define BRD_GET_BP4  pio_get(BRD_BASE_PIO_BP4,PIO_INPUT,BRD_BP4_MASK)
#define BRD_GET_BP5  pio_get(BRD_BASE_PIO_BP5,PIO_INPUT,BRD_BP5_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(1)   // Y1
#define BRD_SLOW_XTAL    		(1)   // Y4
#define BRD_MAIN_XTAL    		(1)   // Y2 or Y3
#define BRD_SLOW_XTAL_FREQ          (32768)   //
#define BRD_MAIN_XTAL_FREQ       (12000000)   //
#define BRD_MAIN_OSC_FREQ        (12000000)   //
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART   (10) // UART
#define BRD_USART1 (21) // USART1
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// SAM3X ////////////////////////////////////////////////////
#if (SAM3X==1)
  #define BRD_BASE_PIO_UART    PIOA
  #define BRD_ID_PIO_UART      ID_PIOA
  #define BRD_UART_RXD	       PIO_PA8A_URXD
  #define BRD_UART_TXD	       PIO_PA9A_UTXD
  #define BRD_PERIPH_UART      PIO_PERIPH_A
  #define BRD_BASE_PIO_USART1  PIOA
  #define BRD_ID_PIO_USART1    ID_PIOA
  #define BRD_USART1_RXD       PIO_PA12A_RXD1
  #define BRD_USART1_TXD       PIO_PA13A_TXD1
  #define BRD_PERIPH_USART1    PIO_PERIPH_A
#else
  #error board.h file does not support the specified device.
#endif
/////////////////////////////////////////////////////////////





#endif // _SAM3X_VB_BGA144_LQFP144_H
