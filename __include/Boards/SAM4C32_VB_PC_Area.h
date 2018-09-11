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
#ifndef _SAM4C32_VB_PC_AREA_H
#define _SAM4C32_VB_PC_AREA_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAM4C
*
*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO              |
____________________________________________
| UART0 (J7)     |  PB4=URXD0 / PB5=UTXD0 |   
| Power LED (D2) |  VDDMAIN                |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (0)
#define BRD_PIOB_HAS_IO (0)
#define BRD_PIOC_HAS_IO (0)
#define BRD_PIOD_HAS_IO (0)
//#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*


#define BRD_PIOA_LED_MASK  (0)
#define BRD_PIOB_LED_MASK  (0) 
#define BRD_PIOC_LED_MASK  (0) 
//#define BRD_PIOD_LED_MASK  (0) // none
//#define BRD_PIOE_LED_MASK  (0) // none


#define BRD_TURN_ON_D3   #error board has no led D3
#define BRD_TURN_OFF_D3  #error board has no led D3
#define BRD_TOGGLE_D3    #error board has no led D3
#define BRD_TURN_ON_D4   #error board has no led D4
#define BRD_TURN_OFF_D4  #error board has no led D4
#define BRD_TOGGLE_D4    #error board has no led D4
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_BP3   PIOB
#define BRD_ID_PIO_BP3     ID_PIOB
#define BRD_BP6_MASK       (1<<16)

//#define BRD_BASE_PIO_ALL_INPUT  PIOA ///////////////////////////////////////////
//#define BRD_ID_PIO_ALL_INPUT    ID_PIOA ////////////////////////////////////////
//#define BRD_ALL_INPUT_MASK      (BRD_BP2_MASK | BRD_BP3_MASK) //////////////////
#define BRD_PIOA_INPUT_MASK    (0)
#define BRD_PIOB_INPUT_MASK    (BRD_BP3_MASK) // none
#define BRD_PIOC_INPUT_MASK    (0) // none
#define BRD_PIOD_INPUT_MASK    (0) // none
//#define BRD_PIOE_INPUT_MASK    (0) // none

#define BRD_GET_BP3  pio_get(BRD_BASE_PIO_BP3,PIO_INPUT,BRD_BP3_MASK)

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // default = DNP  / Y1 (Y3)
#define BRD_SLOW_XTAL    		(1)   // Y3(R35 & R36)
#define BRD_MAIN_XTAL    		(1)   // Y4((R40 & R44)
#define BRD_SLOW_XTAL_FREQ          (32768)   //
#define BRD_MAIN_XTAL_FREQ       (12000000)   //
//#define BRD_MAIN_OSC_FREQ         (3000000)   //
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART0 (10) // UART0 on J7
#define BRD_UART1 (11) // UART1 on J8
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/

// SAM4C ////////////////////////////////////////////////////

#if (SAM4C32==1)
  #define BRD_BASE_PIO_UART0  PIOB
  #define BRD_ID_PIO_UART0    ID_PIOB
  #define BRD_UART0_RXD	      PIO_PB4A_URXD0
  #define BRD_UART0_TXD	      PIO_PB5A_UTXD0 
  #define BRD_PERIPH_UART0    PIO_PERIPH_A 
  #define BRD_BASE_PIO_UART1  PIOC
  #define BRD_ID_PIO_UART1    ID_PIOC
  #define BRD_UART1_RXD	      PIO_PC1A_URXD1
  #define BRD_UART1_TXD	      PIO_PC0A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A

#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////




#endif //_SAM4C32_VB_V_AREA_H
