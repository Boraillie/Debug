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
#ifndef _ISLERO_VB_H
#define _ISLERO_VB_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : ISLERO
*
*
*----------------------------------------------------------------------------
-------------------------------------------------
|    Board             |        PIO             |
_________________________________________________
| UART0 		(J12)  |  PE29=URXD0/PB30=UTXD0 |   
| USART3 		(J13)  |  PE16=RXD3 / PE17=TXD3 |
|                        |  PE24=RTS3 / PE05=CTS3 |
|				                          |
| Blue LED 		(D1)   |  PB27 (1 => LED off)   |
| Green LED 	(D2)   |  PB28 (1 => LED off)   |
| Power LED red	(D3)   |  VDDMAIN               |
|								  |
| Right click 	(BP3   |  PD30  (push => 0)     |
| Left click 	(BP4   |  PE31  (push => 0)     |
=================================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (0)
#define BRD_PIOB_HAS_IO (1)
#define BRD_PIOC_HAS_IO (0)
#define BRD_PIOD_HAS_IO (1)
#define BRD_PIOE_HAS_IO (1)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_D1  PIOB
#define BRD_BASE_PIO_D2  PIOB

#define BRD_ID_PIO_D1    ID_PIOB
#define BRD_ID_PIO_D2    ID_PIOB

#define BRD_D1_MASK      (1<<27)  // PB27 D1
#define BRD_D2_MASK      (1<<28)  // PB28 D2

#define BRD_D1_POLARITY 0 // (0 => LED On)
#define BRD_D2_POLARITY 1 // (1 => LED On)


#define BRD_PIOA_LED_MASK  (0) // none
#define BRD_PIOB_LED_MASK  (BRD_D1_MASK|BRD_D2_MASK) 
#define BRD_PIOC_LED_MASK  (0) // none
#define BRD_PIOD_LED_MASK  (0) // none
#define BRD_PIOE_LED_MASK  (0) // none

#define BRD_TURN_ON_D1   pio_set(BRD_BASE_PIO_D1,BRD_D1_MASK)
#define BRD_TURN_OFF_D1  pio_clear(BRD_BASE_PIO_D1,BRD_D1_MASK)
#define BRD_TOGGLE_D1    pio_toggle(BRD_BASE_PIO_D1,BRD_D1_MASK)
#define BRD_TURN_ON_D2   pio_clear(BRD_BASE_PIO_D2,BRD_D2_MASK)
#define BRD_TURN_OFF_D2  pio_set(BRD_BASE_PIO_D2,BRD_D2_MASK)
#define BRD_TOGGLE_D2    pio_toggle(BRD_BASE_PIO_D2,BRD_D2_MASK)
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_BP3   		PIOE
#define BRD_BASE_PIO_BP4   		PIOD
#define BRD_ID_PIO_BP3     		ID_PIOE
#define BRD_ID_PIO_BP4    	 	ID_PIOD
#define BRD_BP3_MASK       		(uint32_t)(1<<31)  // PE31  LEFT CLICK 
#define BRD_BP4_MASK       		(uint32_t)(1<<30)  // PD30  RIGHT CLICK

#define BRD_PIOA_INPUT_MASK    	(0) // none
#define BRD_PIOB_INPUT_MASK    	(0) // none
#define BRD_PIOC_INPUT_MASK    	(0) // none
#define BRD_PIOD_INPUT_MASK    	(BRD_BP4_MASK)
#define BRD_PIOE_INPUT_MASK    	(BRD_BP3_MASK)

#define BRD_GET_BP3    pio_get(BRD_BASE_PIO_BP3,PIO_INPUT,BRD_BP3_MASK)
#define BRD_GET_BP4    pio_get(BRD_BASE_PIO_BP4,PIO_INPUT,BRD_BP4_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC           (0)
#define BRD_MAIN_OSC           (0)
#define BRD_SLOW_XTAL          (1)      // Y1(R8 & R9)
#define BRD_MAIN_XTAL          (1)      // Y2(R14 & R16)
#define BRD_SLOW_XTAL_FREQ     (32768)  // Y1(R8 & R9)
#define BRD_MAIN_XTAL_FREQ  (12000000)  // Y2(R14 & R16)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board available serial links                                      */
/*----------------------------------------------------------------------------*/
#define BRD_UART0   (0x10)  // UART0 (J12)
// UART0 = (0x10)
// UART1 = (0x11)
// ...
#define BRD_USART3  (0x23)  // USART3 (J13)
// USART1 = (0x21)
// USART2 = (0x22)
// ...



/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// ISLERO ////////////////////////////////////////////////////
#if (ISLERO==1)
// ---- UART0 on J12 -------------------------------------
  #define BRD_BASE_PIO_UART0  PIOE
  #define BRD_ID_PIO_UART0    ID_PIOE
  #define BRD_UART0_RXD	      PIO_PE29B_URXD0
  #define BRD_UART0_TXD	      PIO_PE30B_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_B
// ---- USART3 on J13 ----------------------------------
  #define BRD_BASE_PIO_USART3  PIOE
  #define BRD_ID_PIO_USART3    ID_PIOE
  #define BRD_USART3_RXD       PIO_PE16B_RXD3
  #define BRD_USART3_TXD       PIO_PE17B_TXD3
  #define BRD_USART3_RTS3      PIO_PE24B_RTS3
  #define BRD_USART3_CTS3      PIO_PE5B_CTS3
  #define BRD_PERIPH_USART3    PIO_PERIPH_B
/////////////////////////////////////////////////////////////
//#elif (ISLERO_yy==1)
#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////




#endif // _ISLERO_VB_H
