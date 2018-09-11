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
#ifndef _CANOPUS_VB_V_H
#define _CANOPUS_VB_V_H

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
| UART0 (J19)    |  PA9=URXD0 / PA10=UTXD0 |   
| USART1 (J21)   |  PA21=RXD1 / PB4=TXD1  |   
| 		 |  PA24=RTS1 / PA25=CTS1  |   
| Gr LED (D2)    |  PD31 (1 => LED off)    |
| Gr LED (D3)    |  PD30 (1 => LED off)    |
| Power LED (D4) |  VDDMAIN                |
============================================
*----------------------------------------------------------------------------
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
#define BRD_BASE_PIO_OUTPUT  PIOD
#define BRD_ID_PIO_OUTPUT    ID_PIOD

#define BRD_D2_MASK      (1u<<31)  	/* PD31 D2 */
#define BRD_D3_MASK      (1u<<30)	/* PD30  D3 */

#define BRD_D2_POLARITY 0 // (0 => LED On)
#define BRD_D3_POLARITY 0 // (0 => LED On)

#define BRD_PIOA_OUTPUT_MASK  (0)
#define BRD_PIOB_OUTPUT_MASK  (0) 
#define BRD_PIOC_OUTPUT_MASK  (0) // none
#define BRD_PIOD_OUTPUT_MASK  (BRD_D2_MASK|BRD_D3_MASK) // D2 D3
#define BRD_PIOE_OUTPUT_MASK  (0) // none

#define BRD_TURN_ON_D2   pio_clear(BRD_BASE_PIO_OUTPUT,BRD_D2_MASK)
#define BRD_TURN_OFF_D2  pio_set(BRD_BASE_PIO_OUTPUT,BRD_D2_MASK)
#define BRD_TOGGLE_D2    pio_toggle(BRD_BASE_PIO_OUTPUT,BRD_D2_MASK)
#define BRD_TURN_ON_D3   pio_clear(BRD_BASE_PIO_OUTPUT,BRD_D3_MASK)
#define BRD_TURN_OFF_D3  pio_set(BRD_BASE_PIO_OUTPUT,BRD_D3_MASK)
#define BRD_TOGGLE_D3    pio_toggle(BRD_BASE_PIO_OUTPUT,BRD_D3_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition ( user bottons)                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_BP2   PIOA
//#define BRD_BASE_PIO_BP3   PIOA NRST
#define BRD_BASE_PIO_BP4   PIOA
#define BRD_BASE_PIO_BP5   PIOA
 
//#define BRD_ID_PIO_BP3     ID_PIOA
#define BRD_ID_PIO_BP2     ID_PIOA	//PA11
#define BRD_ID_PIO_BP4     ID_PIOA   	//PA2
#define BRD_ID_PIO_BP5     ID_PIOA	//PA16

#define BRD_BP2_MASK       (1<<11)
#define BRD_BP4_MASK       (1<<2)
#define BRD_BP5_MASK       (1<<16)


#define BRD_PIOA_INPUT_MASK    (BRD_BP2_MASK | BRD_BP4_MASK | BRD_BP5_MASK)
#define BRD_PIOB_INPUT_MASK    (0) // none
#define BRD_PIOC_INPUT_MASK    (0) // none
#define BRD_PIOD_INPUT_MASK    (0) // none
#define BRD_PIOE_INPUT_MASK    (0) // none

#define BRD_GET_BP2  pio_get(BRD_BASE_PIO_BP2,PIO_INPUT,BRD_BP2_MASK)
#define BRD_GET_BP4  pio_get(BRD_BASE_PIO_BP4,PIO_INPUT,BRD_BP4_MASK)
#define BRD_GET_BP5  pio_get(BRD_BASE_PIO_BP5,PIO_INPUT,BRD_BP5_MASK)

/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // none
#define BRD_SLOW_XTAL    		(1)   // Y3(R48 & R51)
#define BRD_MAIN_XTAL    		(1)   // Y4((R9 & R50)
#define BRD_SLOW_XTAL_FREQ    		(32768)      //
#define BRD_MAIN_XTAL_FREQ    		(12000000)   //
//#define BRD_MAIN_OSC_FREQ    		 (3000000)   //
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART0 (10) // UART0 on J19
#define BRD_USART1 (21) // USART1 on J21
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/

// CANOPUS ///////////////////////////////////////////////////
#define BRD_BASE_PIO_UART0  	PIOA
#define BRD_ID_PIO_UART0    	ID_PIOA
#define BRD_UART0_RXD	     	PIO_PA9A_URXD0  
#define BRD_UART0_TXD	     	PIO_PA10A_UTXD0 
#define BRD_PERIPH_UART0    	PIO_PERIPH_A 

/////////////////////////////////////////////////////////////




#endif /* _CANOPUS_VB_V_H */
