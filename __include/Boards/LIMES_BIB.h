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
#ifndef _LIMES_BIB_H
#define _LIMES_BIB_H

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
| PASS FLAG (DS1) |  PB10 (1 => LED Off)   |
| B5 input        |  PB8  (100K PU)        |
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
#define BRD_BASE_PIO_DS  PIOB
#define BRD_ID_PIO_DS    ID_PIOB
#define BRD_DS_MASK      (1<<10) // PASS FLAG

#define BRD_DS_POLARITY (0) // (1 => LED Off)

#define BRD_PIOA_LED_MASK   (0)
#define BRD_PIOB_LED_MASK   (BRD_DS_MASK)
//#define BRD_PIOC_LED_MASK   (0)
//#define BRD_PIOD_LED_MASK   (0)
//#define BRD_PIOE_LED_MASK   (0)

#define BRD_TURN_ON_DS   pio_clear(BRD_BASE_PIO_DS,BRD_DS_MASK)
#define BRD_TURN_OFF_DS  pio_set(BRD_BASE_PIO_DS,BRD_DS_MASK)
#define BRD_TOGGLE_DS    pio_toggle(BRD_BASE_PIO_DS,BRD_DS_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_S5   PIOB
#define BRD_BASE_PIO_S6   PIOB
#define BRD_ID_PIO_S5     ID_PIOB
#define BRD_ID_PIO_S6     ID_PIOB
#define BRD_S5_MASK       (1<<8) // B5 input (100K ext PU on 3V3)
#define BRD_S6_MASK       (1<<9) // B5 input (100K ext PU on 3V3)

#define BRD_PIOA_INPUT_MASK (0)
#define BRD_PIOB_INPUT_MASK (BRD_S5_MASK | BRD_S6_MASK)
//#define BRD_PIOC_INPUT_MASK (0)
//#define BRD_PIOD_INPUT_MASK (0)
//#define BRD_PIOE_INPUT_MASK (0)

#define BRD_GET_S5  pio_get(BRD_BASE_PIO_S5,PIO_INPUT,BRD_S5_MASK)
#define BRD_GET_S6  pio_get(BRD_BASE_PIO_S6,PIO_INPUT,BRD_S6_MASK)
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
// UART0 = (0x10)
// UART1 = (0x11)
// ...
#define BRD_USART0 (0x20) //USART0 on J3 connector (extension board mandatory)
// USART1 = (0x21)
// USART2 = (0x22)
// ...


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// ISLERO ////////////////////////////////////////////////////
#if (LIMES==1)
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




#endif // _LIMES_BIB_H
