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
#ifndef _SAMG55_VB_V_H
#define _SAMG55_VB_V_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAMG55
*
*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO              |
____________________________________________
| USART0 (J15)   |  PA9=RXD0 / PA10=TXD0   |   
| USART2 (J22)   |  PA5=RXD2 / PA6=TXD2    |   
| 		 |  PA15=RTS2 / PA16=CTS2  |   
| Gr LED (D2)    |  PA19 (1 => LED off)    |
| Gr LED (D3)    |  PA20 (1 => LED off)    |
| Power LED (D4) |  VDDMAIN                |
============================================
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

#define BRD_D2_MASK      (1<<19)  	/* PA19 D2 */
#define BRD_D3_MASK      (1<<20)	/* PA20  D3 */

#define BRD_D2_POLARITY 0 // (0 => LED On)
#define BRD_D3_POLARITY 0 // (0 => LED On)

#define BRD_PIOA_LED_MASK  (BRD_D2_MASK|BRD_D3_MASK)
#define BRD_PIOB_LED_MASK  (0) 
//#define BRD_PIOC_LED_MASK  (0) // none
//#define BRD_PIOD_LED_MASK  (0) // none
//#define BRD_PIOE_LED_MASK  (0) // none

#define BRD_TURN_ON_D2   pio_clear(BRD_BASE_PIO_LED,BRD_D2_MASK)
#define BRD_TURN_OFF_D2  pio_set(BRD_BASE_PIO_LED,BRD_D2_MASK)
#define BRD_TOGGLE_D2    pio_toggle(BRD_BASE_PIO_LED,BRD_D2_MASK)
#define BRD_TURN_ON_D3   pio_clear(BRD_BASE_PIO_LED,BRD_D3_MASK)
#define BRD_TURN_OFF_D3  pio_set(BRD_BASE_PIO_LED,BRD_D3_MASK)
#define BRD_TOGGLE_D3    pio_toggle(BRD_BASE_PIO_LED,BRD_D3_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_BP3   PIOA
#define BRD_BASE_PIO_BP5   PIOA
#define BRD_BASE_PIO_BP6   PIOA
#define BRD_BASE_PIO_BP7   PIOB
#define BRD_BASE_PIO_BP8   PIOB
#define BRD_ID_PIO_BP3     ID_PIOA
#define BRD_ID_PIO_BP5     ID_PIOA
#define BRD_ID_PIO_BP6     ID_PIOA
#define BRD_ID_PIO_BP7     ID_PIOB
#define BRD_ID_PIO_BP8     ID_PIOB
#define BRD_BP3_MASK       (1<<0)
#define BRD_BP5_MASK       (1<<1)
#define BRD_BP6_MASK       (1<<2)
#define BRD_BP7_MASK       (1<<2)
#define BRD_BP8_MASK       (1<<3)

#define BRD_PIOA_INPUT_MASK    (BRD_BP3_MASK | BRD_BP5_MASK | BRD_BP6_MASK)
#define BRD_PIOB_INPUT_MASK    (BRD_BP7_MASK | BRD_BP8_MASK)
//#define BRD_PIOC_INPUT_MASK    (0) // none
//#define BRD_PIOD_INPUT_MASK    (0) // none
//#define BRD_PIOE_INPUT_MASK    (0) // none

#define BRD_GET_BP3  pio_get(BRD_BASE_PIO_BP3,PIO_INPUT,BRD_BP3_MASK)
#define BRD_GET_BP5  pio_get(BRD_BASE_PIO_BP5,PIO_INPUT,BRD_BP5_MASK)
#define BRD_GET_BP6  pio_get(BRD_BASE_PIO_BP6,PIO_INPUT,BRD_BP6_MASK)
#define BRD_GET_BP7  pio_get(BRD_BASE_PIO_BP7,PIO_INPUT,BRD_BP7_MASK)
#define BRD_GET_BP8  pio_get(BRD_BASE_PIO_BP8,PIO_INPUT,BRD_BP8_MASK)
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // none
#define BRD_SLOW_XTAL    		(1)   // Y3(R25 & R26)
#define BRD_MAIN_XTAL    		(1)   // Y4((Jumpers)
#define BRD_SLOW_XTAL_FREQ    		(32768)      //
#define BRD_MAIN_XTAL_FREQ    		(12000000)   //
//#define BRD_MAIN_OSC_FREQ    		 (3000000)   //
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_USART0 (20) // USART0 on J15
#define BRD_USART1 (22) // USART2 on J22
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/

// SAM4C ////////////////////////////////////////////////////
#define BRD_BASE_PIO_USART0  PIOA
#define BRD_ID_PIO_USART0    ID_PIOA
#define BRD_USART0_RXD	     PIO_PA9A_RXD0  
#define BRD_USART0_TXD	     PIO_PA10A_TXD0 
#define BRD_PERIPH_USART0    PIO_PERIPH_A 

/////////////////////////////////////////////////////////////




#endif /* _SAMG55_VB_V_H */
