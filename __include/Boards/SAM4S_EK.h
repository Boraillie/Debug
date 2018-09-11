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
#ifndef _SAM4S_EK_H
#define _SAM4S_EK_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAM3S1BA-AU
*
*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO              |
____________________________________________
| UART (J7)      |  PA9=URXD0 / PA10=UTXD0 |   
| USART (J5)     |  PA21=URXD1/PA22=UTXD1  |
| bL LED (D2)    |  PA19 (1 => LED off)    |
| Gr LED (D3)    |  PA20 (1 => LED off)    |
| Power LED (D1) |  PC20 (1 => LED On)     |
| USER_PB1 (BP2) |  PB3  (push => 0)       |
| USER_PB2 (BP3) |  PC12 (push => 0)       |
============================================
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
#define BRD_BASE_PIO_D1  PIOC
#define BRD_BASE_PIO_D3  PIOA
#define BRD_BASE_PIO_D2  PIOA
#define BRD_ID_PIO_D1    ID_PIOC
#define BRD_ID_PIO_D3    ID_PIOA
#define BRD_ID_PIO_D2    ID_PIOA
#define BRD_D1_MASK      (1<<20)  /* PA15 POWER LED*/ 
#define BRD_D3_MASK      (1<<20)  /* PA16 D3 */
#define BRD_D2_MASK      (1<<19)	  /* PA6  D2 */

#define BRD_D1_POLARITY 1 // (1 => LED On)
#define BRD_D3_POLARITY 0 // (0 => LED On)
#define BRD_D2_POLARITY 0 // (0 => LED On)

//#define BRD_BASE_PIO_ALL_LED  PIOA
//#define BRD_BASE_PIO_LED 	  		PIOA	
//#define BRD_BASE_PIO_POWER_LED 	 	PIOC
//#define BRD_ID_PIO_LED    			ID_PIOA
//#define BRD_LED_MASK      			(BRD_D3_MASK|BRD_D2_MASK)
#define BRD_POWER_LED_MASK  (BRD_D1_MASK)

#define BRD_PIOA_LED_MASK   (BRD_D3_MASK|BRD_D2_MASK)
#define BRD_PIOB_LED_MASK   (0)
#define BRD_PIOC_LED_MASK   (BRD_D1_MASK)
//#define BRD_PIOD_LED_MASK   (0)
//#define BRD_PIOE_LED_MASK   (0)

#define BRD_TURN_ON_D1   pio_set(BRD_BASE_PIO_D1,BRD_D1_MASK)
#define BRD_TURN_OFF_D1  pio_clear(BRD_BASE_PIO_D1,BRD_D1_MASK)
#define BRD_TOGGLE_D1    pio_toggle(BRD_BASE_PIO_D1,BRD_D1_MASK)
#define BRD_TURN_ON_D3   pio_clear(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TURN_OFF_D3  pio_set(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TOGGLE_D3    pio_toggle(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TURN_ON_D2   pio_clear(BRD_BASE_PIO_D2,BRD_D2_MASK)
#define BRD_TURN_OFF_D2  pio_set(BRD_BASE_PIO_D2,BRD_D2_MASK)
#define BRD_TOGGLE_D2    pio_toggle(BRD_BASE_PIO_D2,BRD_D2_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_BP2   PIOB
#define BRD_BASE_PIO_BP3   PIOC
#define BRD_ID_PIO_BP2     ID_PIOB
#define BRD_ID_PIO_BP3     ID_PIOC
#define BRD_BP2_MASK       (1<<3)	// PB3  RIGHT CLICK 
#define BRD_BP3_MASK       (1<<12)	// PC12  LEFT CLICK

//#define BRD_BASE_PIO_ALL_INPUT  PIOA
//#define BRD_ID_PIO_ALL_INPUT    ID_PIOA
//#define BRD_ALL_INPUT_MASK      (BRD_BP2_MASK | BRD_BP3_MASK)
#define BRD_PIOA_INPUT_MASK (0)
#define BRD_PIOB_INPUT_MASK (BRD_BP2_MASK)
#define BRD_PIOC_INPUT_MASK (BRD_BP3_MASK)
//#efine BRD_PIOD_INPUT_MASK (0)
//#define BRD_PIOE_INPUT_MASK (0)

#define BRD_GET_BP2  pio_get(BRD_BASE_PIO_BP2,PIO_INPUT,BRD_BP2_MASK)
#define BRD_GET_BP3  pio_get(BRD_BASE_PIO_BP3,PIO_INPUT,BRD_BP3_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0) // NONE bypass through J7 connector
#define BRD_MAIN_OSC     		(0) // NONE bypass through J6 connector
#define BRD_SLOW_XTAL    		(1) // Y3(R28 & R30)
#define BRD_MAIN_XTAL    		(1) //
#define BRD_SLOW_XTAL_FREQ          (32768) //

#ifdef SAM7
  #define BRD_MAIN_XTAL_FREQ   (18432000)  // Y4(JP29 & JP30)
#else
  #define BRD_MAIN_XTAL_FREQ   (12000000)  // Y2(JP31 & JP32) or Y1(R21 & R24)
#endif//sam7
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART0 (10) // UART0 on J7

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

// SAM4N ////////////////////////////////////////////////////
#elif (SAM4N==1)
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
#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////




#endif /* _SAM4S_EK_H */
