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
#ifndef _SAM3X_BIB_LQ144_H
#define _SAM3X_BIB_LQ144_H

//---------------------------------------------------------------------------
//    Board level definitions
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// !!!!! SAM3X-BIB definitions !!!!!!
// --------------------------------------------
// |    Board       |        PIO              |
// ____________________________________________
// | UART      (J3) |  PA8=URXD  / PA9=UTXD   |   
// | Gr LED    (DS) |  PA20 (1 => LED off)    |
// | S5 input       |  PA11                   |
// | S6 input       |  PA10                   |
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
#define BRD_BASE_PIO_DS  PIOA
#define BRD_ID_PIO_DS    ID_PIOA
#define BRD_DS_MASK      (1<<20)  // PA19 POWER LED

#define BRD_DS_POLARITY 0 // (0 => LED On)

#define BRD_PIOA_LED_MASK  (BRD_DS_MASK)
#define BRD_PIOB_LED_MASK  (0) // none
#define BRD_PIOC_LED_MASK  (0) // none
#define BRD_PIOD_LED_MASK  (0) // none
//#define BRD_PIOE_LED_MASK  (0) // none
//#define BRD_PIOF_LED_MASK  (0) // none

#define BRD_TURN_ON_DS   pio_set(BRD_BASE_PIO_DS,BRD_DS_MASK)
#define BRD_TURN_OFF_DS  pio_clear(BRD_BASE_PIO_DS,BRD_DS_MASK)
#define BRD_TOGGLE_DS    pio_toggle(BRD_BASE_PIO_DS,BRD_DS_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- GPIOs: inputs definition                                          */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_S6   PIOA
#define BRD_BASE_PIO_S5   PIOA
#define BRD_ID_PIO_S6     ID_PIOA
#define BRD_ID_PIO_S5     ID_PIOA
#define BRD_S6_MASK       (1<<10)	// PA10
#define BRD_S5_MASK       (1<<11)	// PA11

#define BRD_PIOA_INPUT_MASK    (BRD_S6_MASK | BRD_S5_MASK)
#define BRD_PIOB_INPUT_MASK    (0) // none
#define BRD_PIOE_INPUT_MASK    (0) // none
#define BRD_PIOF_INPUT_MASK    (0) // none
//#define BRD_PIOB_INPUT_MASK    (0) // none
//#define BRD_PIOC_INPUT_MASK    (0) // none

#define BRD_GET_S6  pio_get(BRD_BASE_PIO_S6,PIO_INPUT,BRD_S6_MASK)
#define BRD_GET_S5  pio_get(BRD_BASE_PIO_S5,PIO_INPUT,BRD_S5_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(1)   // Y1 DNP
#define BRD_SLOW_XTAL    		(1)   // Yxx0 DNP
#define BRD_MAIN_XTAL    		(1)   // Yxx1 DNP
#define BRD_SLOW_XTAL_FREQ          (32768)   //
#define BRD_MAIN_XTAL_FREQ       (12000000)   //
#define BRD_MAIN_OSC_FREQ         (3000000)   //
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART   (10) // UART
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
#else
  #error board.h file does not support the specified device.
#endif
/////////////////////////////////////////////////////////////





#endif // _SAM3X_BIB_LQ144_H
