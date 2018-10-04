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
#ifndef _SAM4SP32_QFP128_HTB_H
#define _SAM4SP32_QFP128_HTB_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAM3S1BA-AU
*/
#include <device.h>

/*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board        |        PIO             |
____________________________________________
| PASS FLAG (LD1) |  PA30 (1 => LED On)    |
| B5 input        |  PA29 (10K PU 3V3)     |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (0)
#define BRD_PIOB_HAS_IO (0)
#define BRD_PIOC_HAS_IO (1)
//#define BRD_PIOD_HAS_IO (0)
//#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_LD1  PIOC
#define BRD_ID_PIO_LD1    ID_PIOC
#define BRD_LD1_MASK  (1<<0) // PA30 PASS FLAG //ERr //?????

#define BRD_LD1_POLARITY 0 //ERr //?????

#define BRD_BASE_PIO_ALL_LED  PIOC
#define BRD_ID_PIO_ALL_LED    ID_PIOC
#define BRD_ALL_LED_MASK (BRD_LD1_MASK)

//#define BRD_LED_POLARITY(led) led ## _POLARITY

#define BRD_TURN_ON_LD1   pio_set(BRD_BASE_PIO_LD1,BRD_LD1_MASK)
#define BRD_TURN_OFF_LD1  pio_clear(BRD_BASE_PIO_LD1,BRD_LD1_MASK)
#define BRD_TOGGLE_LD1    pio_toggle(BRD_BASE_PIO_LD1,BRD_LD1_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_B5   PIOC
#define BRD_ID_PIO_B5     ID_PIOC
#define BRD_B5_MASK  (1<<5) // PC5 B5 input (10K ext PU on 3V3) //ERr //???

#define BRD_BASE_PIO_ALL_INPUT  PIOC
#define BRD_ID_PIO_ALL_INPUT    ID_PIOC
#define BRD_ALL_INPUT_MASK (BRD_B5_MASK)

#define BRD_GET_B5_INPUT  pio_get(BRD_BASE_PIO_B5,PIO_INPUT,BRD_B5_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // none
#define BRD_SLOW_XTAL    		(0)   // none
#define BRD_MAIN_XTAL    		(0)   // default = DNP
#define BRD_SLOW_XTAL_FREQ    		(32768)      //
#define BRD_MAIN_XTAL_FREQ    		(12000000)   //
//#define BRD_MAIN_OSC_FREQ    		 (3000000)   //
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// SAM3S ////////////////////////////////////////////////////
//#ifdef sam3s
  //#define
// SAM4S ////////////////////////////////////////////////////
//#elif defined sam4s
  //#define
//#else
//  #error board.h file does not support the specified device.
//#endif
/*----------------------------------------------------------------------------*/
/////////////////////////////////////////////////////////////




#endif //_SAM4SP32_QFP128_HTB_H