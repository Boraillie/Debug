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
#ifndef _SAM4SH1_QFP100_BIB_H
#define _SAM4SH1_QFP100_BIB_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAM4SH1 (=SH4) QFP100
*
*
*----------------------------------------------------------------------------
----------------------------------------------
|    Board         |        PIO              |
______________________________________________
| UART0 (DBG)      |  PA9=URXD0 / PA10=UTXD0 |   
| Gr LED (DS1/DS2) |  PA19 (1 => LED off)    |
==============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"



/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (1)
//#define BRD_PIOC_HAS_IO (0)
//#define BRD_PIOD_HAS_IO (0)
//#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_LED  PIOA
#define BRD_ID_PIO_LED    ID_PIOA

#define BRD_DS_MASK     (1<<19) // PA19 DS1 (DS2)

#define BRD_DS_POLARITY 0 // (0 => LED On)

#define BRD_PIOA_LED_MASK  (BRD_DS_MASK)
#define BRD_PIOB_LED_MASK  (0) 
//#define BRD_PIOC_LED_MASK  (0) 
//#define BRD_PIOD_LED_MASK  (0) // none
//#define BRD_PIOE_LED_MASK  (0) // none

#define BRD_TURN_ON_DS   pio_clear(BRD_BASE_PIO_LED,BRD_DS_MASK)
#define BRD_TURN_OFF_DS  pio_set(BRD_BASE_PIO_LED,BRD_DS_MASK)
#define BRD_TOGGLE_DS    pio_toggle(BRD_BASE_PIO_LED,BRD_DS_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_S5   PIOA
#define BRD_ID_PIO_S5     ID_PIOA
#define BRD_S5_MASK  (1<<1) // PA1 B5 input (100K ext PU on 3V3) //ERr //???

#define BRD_BASE_PIO_S6   PIOA
#define BRD_ID_PIO_S6     ID_PIOA
#define BRD_S6_MASK  (1<<2) // PA2 B6 input (100K ext PU on 3V3) //ERr //???

#define BRD_GET_S5_INPUT  pio_get(BRD_BASE_PIO_S5,PIO_INPUT,BRD_S5_MASK)
#define BRD_GET_S6_INPUT  pio_get(BRD_BASE_PIO_S6,PIO_INPUT,BRD_S6_MASK)

#define BRD_PIOA_INPUT_MASK    (BRD_S5_MASK | BRD_S6_MASK)
#define BRD_PIOB_INPUT_MASK    (0) // none
#define BRD_PIOC_INPUT_MASK    (0) // none
#define BRD_PIOD_INPUT_MASK    (0) // none
#define BRD_PIOE_INPUT_MASK    (0) // none

#define BRD_GET_S5  pio_get(BRD_BASE_PIO_S5,PIO_INPUT,BRD_S5_MASK)
#define BRD_GET_S6  pio_get(BRD_BASE_PIO_S6,PIO_INPUT,BRD_S6_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // default = DNP  / Y1 (Y3)
#define BRD_SLOW_XTAL    		(0)   // none
#define BRD_MAIN_XTAL    		(0)   // default = DNP  / Y2 (Y4)
#define BRD_SLOW_XTAL_FREQ          (32768)   //
#define BRD_MAIN_XTAL_FREQ       (12000000)   //
#define BRD_MAIN_OSC_FREQ         (3000000)   //
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------
// ---- Board Clocks ----
//-----------------------
#define BRD_SLOW_OSC   (0)        //
#define BRD_MAIN_OSC   (3000000)  
#define BRD_SLOW_XTAL  (0)        //

#define BRD_MAIN_XTAL  (12000000) 
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
//#define BRD_DBGU   (01)
#define BRD_UART0  (10) // UART0 on J3 connector (extension board mandatory)
//#define BRD_UART1  (11)
//#define BRD_USART0 (20)
//#define BRD_USART1 (21)
//#define BRD_USART2 (22)
//#define BRD_USART3 (23)
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/

// SAM4C ////////////////////////////////////////////////////
#if (SAM4SH1==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0  
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0 
  #define BRD_PERIPH_UART0    PIO_PERIPH_A 
#elif (SAMG53==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0  
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0 
  #define BRD_PERIPH_UART0    PIO_PERIPH_A 
#else
  #error board.h file does not support the specified device.
#endif
/////////////////////////////////////////////////////////////




#endif // _SAM4SH1_QFP100_BIB_H
