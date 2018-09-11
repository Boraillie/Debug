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
#ifndef _CANOPUS_EMC_LQ144_H
#define _CANOPUS_EMC_LQ144_H

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
| 	         |                         |   
| LED (D1)       |        PA3              |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


#define BRD_GET_PB12 pio_get(PIOB,PIO_INPUT,(1<<12))

/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (1)
#define BRD_PIOC_HAS_IO (1)
#define BRD_PIOD_HAS_IO (1)
#define BRD_PIOE_HAS_IO (1)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- System dedicated I/Os                                             */
/*----------------------------------------------------------------------------*/
#define BRD_PIOA_SYSIO (PIO_PA7 | PIO_PA8)
#define BRD_PIOB_SYSIO (PIO_PB4 | PIO_PB5 | PIO_PB6 | PIO_PB7 | PIO_PB8 | PIO_PB9)
#define BRD_PIOC_SYSIO (0)
#define BRD_PIOD_SYSIO (0)
#define BRD_PIOE_SYSIO (0)
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
// Pins dedicated for reception (NC for default assembly)
#define BRD_PIOA_INPUT_MASK (PIO_PA2 | PIO_PA12 | PIO_PA30)
#define BRD_PIOB_INPUT_MASK (PIO_PB0)
#define BRD_PIOC_INPUT_MASK (PIO_PC14 | PIO_PC18 | PIO_PC27)
#define BRD_PIOD_INPUT_MASK (PIO_PD1 | PIO_PD4 | PIO_PD10 | PIO_PD23 | PIO_PD30)
#define BRD_PIOE_INPUT_MASK (0) // none
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Outputs Definition                                                */
/*----------------------------------------------------------------------------*/
//------ LEDs ----------------------------------------------------
#define BRD_D1_BASE_PIO  PIOA
#define BRD_D1_ID_PIO    ID_PIOA
#define BRD_D1_MASK      (1<<3)  	// PA3 D1
#define BRD_D1_POLARITY  (0) // (0 => LED On)
#define BRD_TURN_ON_D1   pio_clear(BRD_D1_BASE_PIO,BRD_D1_MASK)
#define BRD_TURN_OFF_D1  pio_set(BRD_D1_BASE_PIO,BRD_D1_MASK)
#define BRD_TOGGLE_D1    pio_toggle(BRD_D1_BASE_PIO,BRD_D1_MASK)
//----------------------------------------------------------------

//------ Charged outputs -----------------------------------------
#define BRD_PIOA_EMC_OUTPUT_MASK  ((~BRD_PIOA_INPUT_MASK)&(~BRD_PIOA_SYSIO)&(~BRD_D1_MASK))
#define BRD_PIOB_EMC_OUTPUT_MASK  ((~BRD_PIOB_INPUT_MASK)&(~BRD_PIOB_SYSIO)&(0x000033FF))
#define BRD_PIOC_EMC_OUTPUT_MASK  ((~BRD_PIOC_INPUT_MASK)&(~BRD_PIOC_SYSIO))
#define BRD_PIOD_EMC_OUTPUT_MASK  ((~BRD_PIOD_INPUT_MASK)&(~BRD_PIOD_SYSIO))
#define BRD_PIOE_EMC_OUTPUT_MASK  ((~BRD_PIOE_INPUT_MASK)&(~BRD_PIOE_SYSIO)&(0x0000003F))
//----------------------------------------------------------------

#define BRD_PIOA_OUTPUT_MASK  (BRD_D1_MASK | BRD_PIOA_EMC_OUTPUT_MASK)
#define BRD_PIOB_OUTPUT_MASK  (BRD_PIOB_EMC_OUTPUT_MASK)
#define BRD_PIOC_OUTPUT_MASK  (BRD_PIOC_EMC_OUTPUT_MASK)
#define BRD_PIOD_OUTPUT_MASK  (BRD_PIOD_EMC_OUTPUT_MASK)
#define BRD_PIOE_OUTPUT_MASK  (BRD_PIOE_EMC_OUTPUT_MASK)
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // none
#define BRD_SLOW_XTAL    		(1)   // Y4
#define BRD_MAIN_XTAL    		(1)   // Y3
#define BRD_SLOW_XTAL_FREQ          (32768)   //
#define BRD_MAIN_XTAL_FREQ       (12000000)   //
//#define BRD_MAIN_OSC_FREQ         (3000000)   // no on-board osc
/*----------------------------------------------------------------------------*/



//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
//
//------------------------------------------------------------------------------


//----------------------------------------------------------------------------*/
//---------------------------------------------------------
// Peripherals Definition (Device dependant)               
//---------------------------------------------------------
// CANOPUS ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////




#endif // _CANOPUS_EMC_LQ144_H
