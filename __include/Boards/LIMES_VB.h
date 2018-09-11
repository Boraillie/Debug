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
#ifndef _LIMES_VB_H
#define _LIMES_VB_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : LIMES BGA96
*/
#include <device.h>

/*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board        |        PIO             |
____________________________________________
| PASS FLAG (D9)  |  PB10 (1 => LED On)    |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (0)
#define BRD_PIOB_HAS_IO (1)
//#define BRD_PIOC_HAS_IO (0)
//#define BRD_PIOD_HAS_IO (0)
//#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_D9   PIOB
#define BRD_BASE_PIO_D10  PIOB
#define BRD_ID_PIO_D9     ID_PIOB
#define BRD_ID_PIO_D10    ID_PIOB
#define BRD_D9_MASK      (1<<10) //
#define BRD_D10_MASK     (1<<11) //

#define BRD_D9_POLARITY  (1) // (1 => LED On)
#define BRD_D10_POLARITY (1) // (1 => LED On)

#define BRD_PIOA_LED_MASK   (0)
#define BRD_PIOB_LED_MASK   (BRD_D9_MASK | BRD_D10_MASK)
//#define BRD_PIOC_LED_MASK   (0)
//#define BRD_PIOD_LED_MASK   (0)
//#define BRD_PIOE_LED_MASK   (0)

#define BRD_TURN_ON_D9   pio_set(BRD_BASE_PIO_D9,BRD_D9_MASK)
#define BRD_TURN_OFF_D9  pio_clear(BRD_BASE_PIO_D9,BRD_D9_MASK)
#define BRD_TOGGLE_D9    pio_toggle(BRD_BASE_PIO_D9,BRD_D9_MASK)
#define BRD_TURN_ON_D10   pio_set(BRD_BASE_PIO_D10,BRD_D10_MASK)
#define BRD_TURN_OFF_D10  pio_clear(BRD_BASE_PIO_D10,BRD_D10_MASK)
#define BRD_TOGGLE_D10    pio_toggle(BRD_BASE_PIO_D10,BRD_D10_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_BP1   PIOB
#define BRD_BASE_PIO_BP2   PIOB
#define BRD_ID_PIO_BP1     ID_PIOB
#define BRD_ID_PIO_BP2     ID_PIOB
#define BRD_BP1_MASK       (1<<8) // B5 input (100K ext PU on 3V3)
#define BRD_BP2_MASK       (1<<9) // B5 input (100K ext PU on 3V3)

#define BRD_PIOA_INPUT_MASK (0)
#define BRD_PIOB_INPUT_MASK (BRD_BP1_MASK | BRD_BP2_MASK)
//#define BRD_PIOC_INPUT_MASK (0)
//#define BRD_PIOD_INPUT_MASK (0)
//#define BRD_PIOE_INPUT_MASK (0)

#define BRD_GET_BP1  pio_get(BRD_BASE_PIO_BP1,PIO_INPUT,BRD_BP1_MASK)
#define BRD_GET_BP2  pio_get(BRD_BASE_PIO_BP2,PIO_INPUT,BRD_BP2_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   //none
#define BRD_MAIN_OSC     		(0)   //none
#define BRD_SLOW_XTAL    		(1)   //
#define BRD_MAIN_XTAL    		(1)   //
#define BRD_SLOW_XTAL_FREQ    		(32768)      //
#define BRD_MAIN_XTAL_FREQ    		(12000000)   //
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board available serial links                                      */
/*----------------------------------------------------------------------------*/
#define BRD_UART (0x10) //UART
// UART0 = (0x10)
// UART1 = (0x11)
// ...

#define BRD_USART0 (0x20) //USART0
// USART1 = (0x21)
// USART2 = (0x22)
// ...


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// ISLERO ////////////////////////////////////////////////////
#if (LIMES==1)
// ---- UART on J3 -------------------------------------
  #define BRD_BASE_PIO_UART  PIOB
  #define BRD_ID_PIO_UART    ID_PIOB
  #define BRD_UART_RXD       PIO_PB14A_URXD
  #define BRD_UART_TXD       PIO_PB21A_UTXD
  #define BRD_PERIPH_UART    PIO_PERIPH_A
// ---- USART0 on J3 -------------------------------------
  #define BRD_BASE_PIO_USART0  PIOB
  #define BRD_ID_PIO_USART0    ID_PIOB
  #define BRD_USART0_RXD       PIO_PB13A_RXD0
  #define BRD_USART0_TXD       PIO_PB20A_TXD0
  #define BRD_PERIPH_USART0    PIO_PERIPH_A
//#elif (xxx==1)
#else
  #error board.h file does not support the specified device.
#endif
/*----------------------------------------------------------------------------*/
/////////////////////////////////////////////////////////////




#endif // _LIMES_VB_H
