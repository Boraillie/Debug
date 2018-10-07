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
#ifndef _SAM4S_XPLAINED_PRO_H
#define _SAM4S_XPLAINED_PRO_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAM3S1BA-AU
*
*
*----------------------------------------------------------------------------
------------------------------------------------------
|    Board              |        PIO                  |
______________________________________________________
| Ye LED (LED0)         |  PC23  ( 0 => LED off)      |
| SW0 (User boutton)    |  PC24  ( push => 0)         |
======================================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (1)
#define BRD_PIOC_HAS_IO (1)
//#define BRD_PIOD_HAS_IO (0)
//#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_D0  PIOC
#define BRD_ID_PIO_D0    ID_PIOC
#define BRD_D0_MASK      (1<<23)	  /* PC23  D0 */

#define BRD_D0_POLARITY 0 // (0 => LED On)

#define BRD_ALL_LED_MASK      (BRD_D0_MASK)/////////////

#define BRD_PIOA_LED_MASK  (0)
#define BRD_PIOB_LED_MASK  (0) // none
#define BRD_PIOC_LED_MASK  (BRD_D0_MASK) // none
#define BRD_PIOD_LED_MASK  (0) // none
#define BRD_PIOE_LED_MASK  (0) // none

#define BRD_TURN_OFF_D0   pio_set(BRD_BASE_PIO_D0,BRD_D0_MASK)
#define BRD_TURN_ON_D0  pio_clear(BRD_BASE_PIO_D0,BRD_D0_MASK)
#define BRD_TOGGLE_D0    pio_toggle(BRD_BASE_PIO_D0,BRD_D0_MASK)

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_SW0   PIOA       //User button
#define BRD_ID_PIO_SW0     ID_PIOA
#define BRD_SW0_MASK       (1<<2)	


#define BRD_BASE_PIO_ALL_INPUT  PIOC ///////////////////////////////////////////
#define BRD_ID_PIO_ALL_INPUT    ID_PIOC ////////////////////////////////////////
#define BRD_ALL_INPUT_MASK      (BRD_SW0_MASK) //////////////////

#define BRD_PIOA_INPUT_MASK    (0)
#define BRD_PIOB_INPUT_MASK    (0) // none
#define BRD_PIOC_INPUT_MASK    (BRD_SW0_MASK) // none
#define BRD_PIOD_INPUT_MASK    (0) // none
#define BRD_PIOE_INPUT_MASK    (0) // none


#define BRD_GET_SW0  pio_get(BRD_BASE_PIO_SW0,PIO_INPUT,BRD_SW0_MASK)
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0) // NONE bypass through J7 connector
#define BRD_MAIN_OSC     		(0) // NONE bypass through J6 connector
#define BRD_SLOW_XTAL    		(1) // Y3(R28 & R30)
#define BRD_MAIN_XTAL    		(1) //
#define BRD_SLOW_XTAL_FREQ          (32768) //

#define BRD_MAIN_XTAL_FREQ   (12000000)  // Y2(JP31 & JP32) or Y1(R21 & R24)

/*----------------------------------------------------------------------------*/



//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART0 (10) // UART0 on J10
#define BRD_UART1 (11) // UART1 on J12
#define BRD_USART1 (21) // UART1 on J12

//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// SAM3S ////////////////////////////////////////////////////
#if (SAM3S==1 || SAM3S8==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_A
  #define BRD_BASE_PIO_UART1  PIOB
  #define BRD_ID_PIO_UART1    ID_PIOB
  #define BRD_UART1_RXD	      PIO_PB2A_URXD1
  #define BRD_UART1_TXD	      PIO_PB3A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
// SAM4S ////////////////////////////////////////////////////
#elif (SAM4S==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_A
  #define BRD_BASE_PIO_UART1  PIOB
  #define BRD_ID_PIO_UART1    ID_PIOB
  #define BRD_UART1_RXD	      PIO_PB2A_URXD1
  #define BRD_UART1_TXD	      PIO_PB3A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
  #define BRD_BASE_PIO_USART1  PIOB
  #define BRD_ID_PIO_USART1    ID_PIOB
  #define BRD_USART1_RXD	      PIO_PB2A_URXD1
  #define BRD_USART1_TXD	      PIO_PB3A_UTXD1
  #define BRD_PERIPH_USART1    PIO_PERIPH_A

#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////




#endif /* _SAM4S_XPLAINED_PRO_H */
