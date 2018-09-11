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
#ifndef _SAM4SH1_VB_PC_H
#define _SAM4SH1_VB_PC_H

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
| UART0 (J8)     |  PA9=URXD0 / PA10=UTXD0 |   
| Power LED (D4) |  VDDMAIN                |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (0)
//#define BRD_PIOC_HAS_IO (0)
//#define BRD_PIOD_HAS_IO (0)
//#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/

#define BRD_BASE_PIO_D2  PIOA
#define BRD_BASE_PIO_D3  PIOA
#define BRD_ID_PIO_D2    ID_PIOA
#define BRD_ID_PIO_D3    ID_PIOA

#define BRD_D2_MASK      (1<<19)  	/* PA19 D2 */
#define BRD_D3_MASK      (1<<20)	/* PA20  D3 */


#define BRD_D2_POLARITY 0 // (0 => LED On)
#define BRD_D3_POLARITY 0 // (0 => LED On)



#define BRD_PIOA_LED_MASK  (0)
#define BRD_PIOB_LED_MASK  (0) 
#define BRD_PIOC_LED_MASK  (0) 
#define BRD_PIOD_LED_MASK  (0) // none
#define BRD_PIOE_LED_MASK  (0) // none


#define BRD_TURN_ON_D2   pio_clear(BRD_BASE_PIO_D2,BRD_D2_MASK)
#define BRD_TURN_OFF_D2  pio_set(BRD_BASE_PIO_D2,BRD_D2_MASK)
#define BRD_TOGGLE_D2    pio_toggle(BRD_BASE_PIO_D2,BRD_D2_MASK)
#define BRD_TURN_ON_D3   pio_clear(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TURN_OFF_D3  pio_set(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TOGGLE_D3    pio_toggle(BRD_BASE_PIO_D3,BRD_D3_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
//#define BRD_BASE_PIO_BP2   PIOA
//#define BRD_BASE_PIO_BP3   PIOA
//#define BRD_ID_PIO_BP2     ID_PIOA
//#define BRD_ID_PIO_BP3     ID_PIOA
//#define BRD_BP2_MASK       (1<<2)	// PA2  RIGHT CLICK 
//#define BRD_BP3_MASK       (1<<5)	// PA5  LEFT CLICK

//#define BRD_BASE_PIO_ALL_INPUT  PIOA ///////////////////////////////////////////
//#define BRD_ID_PIO_ALL_INPUT    ID_PIOA ////////////////////////////////////////
//#define BRD_ALL_INPUT_MASK      (BRD_BP2_MASK | BRD_BP3_MASK) //////////////////

//#define BRD_PIOA_INPUT_MASK    (BRD_BP2_MASK | BRD_BP3_MASK)
//#define BRD_PIOB_INPUT_MASK    (0) // none
//#define BRD_PIOC_INPUT_MASK    (0) // none
//#define BRD_PIOD_INPUT_MASK    (0) // none
//#define BRD_PIOE_INPUT_MASK    (0) // none


//#define BRD_GET_BP2  pio_get(BRD_BASE_PIO_BP2,PIO_INPUT,BRD_BP2_MASK)
//#define BRD_GET_BP3  pio_get(BRD_BASE_PIO_BP3,PIO_INPUT,BRD_BP3_MASK)
/*----------------------------------------------------------------------------*/


 
/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // none
#define BRD_SLOW_XTAL    		(1)   // Y3(R25 & R26)
#define BRD_MAIN_XTAL    		(1)   // Y4((Jumpers)
#define BRD_SLOW_XTAL_FREQ          (32768)   //
#define BRD_MAIN_XTAL_FREQ       (12000000)   //
//#define BRD_MAIN_OSC_FREQ       (3000000)   //
/*----------------------------------------------------------------------------*/



//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART0 (10) // UART0 on J8
#define BRD_UART1 (11) //
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/

// SAM4C ////////////////////////////////////////////////////
//AYI to be checked PIO Periph ???
#if (SAM4SH1==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9_URXD0
  #define BRD_UART0_TXD	      PIO_PA10_UTXD0 
  #define BRD_PERIPH_UART0    PIO_PERIPH_A 

#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////




#endif /* _SAM4SH1_VB_PC_H */

