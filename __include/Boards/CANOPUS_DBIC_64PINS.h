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
#ifndef _CANOPUS_DBIC_64PINS_H
#define _CANOPUS_DBIC_64PINS_H



/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : CANOPUS 65103, 65107
* Boards compliance : 65103_DBIC : TFBGA100, TFBGA144
*                     65107_DBIC : LQFP100, LQFP144
*----------------------------------------------------------------------------
*/



#include "device.h"


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (0)
#define BRD_PIOC_HAS_IO (0)
#define BRD_PIOD_HAS_IO (1)
#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_LED  PIOD       // PASS_FLAG
#define BRD_ID_PIO_LED    ID_PIOD

#define BRD_PASS_FLAG_MASK      (1<<31)  	// PD31

//#define BRD_DS_POLARITY  (0) // (0 => LED On)

#define BRD_PIOA_LED_MASK  (0) // none
#define BRD_PIOB_LED_MASK  (0) // none
#define BRD_PIOC_LED_MASK  (0) // none
#define BRD_PIOD_LED_MASK  (BRD_PASS_FLAG_MASK)
#define BRD_PIOE_LED_MASK  (0) // none

#define BRD_TURN_ON_PASS_FLAG   pio_clear(BRD_BASE_PIO_LED,BRD_PASS_FLAG_MASK)
#define BRD_TURN_OFF_PASS_FLAG  pio_set(BRD_BASE_PIO_LED,BRD_PASS_FLAG_MASK)
#define BRD_TOGGLE_PASS_FLAG    pio_toggle(BRD_BASE_PIO_LED,BRD_PASS_FLAG_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition ( user bottons)                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_S5   PIOA
#define BRD_BASE_PIO_S6   PIOA

#define BRD_ID_PIO_S5     ID_PIOA
#define BRD_ID_PIO_S6     ID_PIOA

#define BRD_S5_MASK       (1<<22)   //PA22
#define BRD_S6_MASK       (1<<21)  //PA21


#define BRD_PIOA_INPUT_MASK    (BRD_S5_MASK | BRD_S6_MASK)
#define BRD_PIOB_INPUT_MASK    (0) // none
#define BRD_PIOC_INPUT_MASK    (0) // none
#define BRD_PIOD_INPUT_MASK    (0) // none
#define BRD_PIOE_INPUT_MASK    (0) // none

#define BRD_GET_S5 pio_get(BRD_BASE_PIO_S5,PIO_INPUT,BRD_S5_MASK)
#define BRD_GET_S6 pio_get(BRD_BASE_PIO_S6,PIO_INPUT,BRD_S6_MASK)
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // none
#define BRD_SLOW_XTAL    		(0)   // none
#define BRD_MAIN_XTAL    		(0)   // none
#define BRD_SLOW_XTAL_FREQ          (32768)   //
#define BRD_MAIN_XTAL_FREQ       (12000000)   //
#define BRD_MAIN_OSC_FREQ         (3000000)   //
/*----------------------------------------------------------------------------*/



//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART0 (10) // UART0 on debug site only (extension board mandatory)
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/

// CANOPUS ////////////////////////////////////////////////////
#define BRD_BASE_PIO_UART0  	PIOA
#define BRD_ID_PIO_UART0    	ID_PIOA
#define BRD_UART0_RXD	     	PIO_PA9A_URXD0  
#define BRD_UART0_TXD	     	PIO_PA10A_UTXD0 
#define BRD_PERIPH_UART0    	PIO_PERIPH_A 
/////////////////////////////////////////////////////////////




#endif // _CANOPUS_DBIC_64PINS_H
