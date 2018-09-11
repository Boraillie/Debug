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
#ifndef _ISLERO_BIB_H
#define _ISLERO_BIB_H

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
#define BRD_BASE_PIO_DS  PIOB
#define BRD_ID_PIO_DS    ID_PIOB
#define BRD_DS_MASK      (1<<27)  // PB27 DS
#define BRD_DS_POLARITY  (0) // (0 => LED On)

#define BRD_PIOA_LED_MASK  (0) // none
#define BRD_PIOB_LED_MASK  (BRD_DS_MASK) 
#define BRD_PIOC_LED_MASK  (0) // none
#define BRD_PIOD_LED_MASK  (0) // none
#define BRD_PIOE_LED_MASK  (0) // none

#define BRD_TURN_ON_DS   pio_set(BRD_BASE_PIO_DS,BRD_DS_MASK)
#define BRD_TURN_OFF_DS  pio_clear(BRD_BASE_PIO_DS,BRD_DS_MASK)
#define BRD_TOGGLE_DS    pio_toggle(BRD_BASE_PIO_DS,BRD_DS_MASK)
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_S5                 PIOE
#define BRD_BASE_PIO_S6                 PIOD
#define BRD_ID_PIO_S5                   ID_PIOE
#define BRD_ID_PIO_S6                   ID_PIOD
#define BRD_S5_MASK                    (uint32_t)(1<<31) // PE31  LEFT CLICK 
#define BRD_S6_MASK                    (uint32_t)(1<<30) // PD30  RIGHT CLICK

#define BRD_PIOA_INPUT_MASK    	(0) // none
#define BRD_PIOB_INPUT_MASK    	(0) // none
#define BRD_PIOC_INPUT_MASK    	(0) // none
#define BRD_PIOD_INPUT_MASK    	(BRD_S6_MASK)
#define BRD_PIOE_INPUT_MASK    	(BRD_S5_MASK)

#define BRD_GET_S5    pio_get(BRD_BASE_PIO_S5,PIO_INPUT,BRD_S5_MASK)
#define BRD_GET_S6    pio_get(BRD_BASE_PIO_S6,PIO_INPUT,BRD_S6_MASK)
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   //none
#define BRD_MAIN_OSC     		(0)   //default=DNP
#define BRD_SLOW_XTAL    		(0)   //default=DNP  
#define BRD_MAIN_XTAL    		(0)   //default=DNP
#define BRD_MAIN_OSC_FREQ     		(3000000)    //default=DNP
#define BRD_SLOW_XTAL_FREQ    		(32768)      //default=DNP  
#define BRD_MAIN_XTAL_FREQ    		(12000000)   //default=DNP
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board available serial links                                      */
/*----------------------------------------------------------------------------*/
#define BRD_UART0   (0x10) // UART0 on J3 connector (extension board mandatory)
// UART0 = (0x10)
// UART1 = (0x11)
// ...
#define BRD_USART3  (0x23)  // USART3 (J13) - BIB prototypes only
// USART1 = (0x21)
// USART2 = (0x22)
// ...



/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// ISLERO ////////////////////////////////////////////////////
#if (ISLERO==1)
// ---- UART0 on J3 -------------------------------------
  #define BRD_BASE_PIO_UART0  PIOE
  #define BRD_ID_PIO_UART0    ID_PIOE
  #define BRD_UART0_RXD	      PIO_PE29B_URXD0
  #define BRD_UART0_TXD	      PIO_PE30B_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_B

// ---- USART3 on J3 - patch done on prototypes only ----
  #define BRD_BASE_PIO_USART3  PIOE
  #define BRD_ID_PIO_USART3    ID_PIOE
  #define BRD_USART3_RXD       PIO_PE16B_RXD3
  #define BRD_USART3_TXD       PIO_PE17B_TXD3
  #define BRD_PERIPH_USART3    PIO_PERIPH_B
//#elif (ISLERO_yy==1)
#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////




#endif // _ISLERO_BIB_H
