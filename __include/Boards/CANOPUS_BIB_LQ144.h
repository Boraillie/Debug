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
#ifndef _CANOPUS_BIB_LQ144_H
#define _CANOPUS_BIB_LQ144_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : CANOPUS
*
*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO              |
____________________________________________
| UART0 (J19)    |   |   
| USART1 (J21)   |   |   
| 		 |   |   
| Gr LED (D2)    |   |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (0)
#define BRD_PIOC_HAS_IO (0)
#define BRD_PIOD_HAS_IO (0)
#define BRD_PIOE_HAS_IO (1)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_OUTPUT  PIOE
#define BRD_ID_PIO_OUTPUT    ID_PIOE

#define BRD_DS_MASK      (1<<4)  	// PE4 DS

#define BRD_DS_POLARITY  (0) // (0 => LED On)

#define BRD_PIOA_OUTPUT_MASK  (0)
#define BRD_PIOB_OUTPUT_MASK  (0) 
#define BRD_PIOC_OUTPUT_MASK  (0) // none
#define BRD_PIOD_OUTPUT_MASK  (0) // none
#define BRD_PIOE_OUTPUT_MASK  (BRD_DS_MASK)

#define BRD_TURN_ON_DS   pio_clear(BRD_BASE_PIO_OUTPUT,BRD_DS_MASK)
#define BRD_TURN_OFF_DS  pio_set(BRD_BASE_PIO_OUTPUT,BRD_DS_MASK)
#define BRD_TOGGLE_DS    pio_toggle(BRD_BASE_PIO_OUTPUT,BRD_DS_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition ( user bottons)                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_S5   PIOA
#define BRD_BASE_PIO_S6   PIOA

#define BRD_ID_PIO_S5     ID_PIOA
#define BRD_ID_PIO_S6     ID_PIOA

#define BRD_S5_MASK       (1<<2)   //PA2
#define BRD_S6_MASK       (1<<16)  //PA16


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
#define BRD_MAIN_OSC     		(0)   // default = DNP  / Y1
#define BRD_SLOW_XTAL    		(0)   // default = DNP  / Yx00
#define BRD_MAIN_XTAL    		(0)   // default = DNP  / Yx01
#define BRD_SLOW_XTAL_FREQ          (32768)   //
#define BRD_MAIN_XTAL_FREQ       (12000000)   //
#define BRD_MAIN_OSC_FREQ         (3000000)   //
/*----------------------------------------------------------------------------*/



//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART0 (10) // UART0 on J3 connector (extension board mandatory)
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




#endif /* _CANOPUS_BIB_LQ144_H */
