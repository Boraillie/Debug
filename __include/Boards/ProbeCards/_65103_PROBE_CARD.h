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
#ifndef _65103_PROBE_CARD_H
#define _65103_PROBE_CARD_H


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

============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (1)
#define BRD_PIOC_HAS_IO (0)
#define BRD_PIOD_HAS_IO (1)
#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Outputs Definition                                                */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_RDY_CKOUT  PIOA
#define BRD_ID_PIO_RDY_CKOUT    ID_PIOA
#define BRD_BASE_PIO_MISO       PIOD
#define BRD_ID_PIO_MISO         ID_PIOD

#define BRD_RDY_CKOUT_MASK     (1<<4)  //PA4
#define BRD_MISO_MASK          (1<<12) //PD12

//______________________________________________________________________________
#define BRD_PIOA_OUTPUT_MASK  (BRD_RDY_CKOUT_MASK | BRD_MISO_MASK)
#define BRD_PIOB_OUTPUT_MASK  (0) // none
#define BRD_PIOC_OUTPUT_MASK  (0) // none
#define BRD_PIOD_OUTPUT_MASK  (0) // none
#define BRD_PIOE_OUTPUT_MASK  (0) // none

#define BRD_SET_RDY_CKOUT    pio_set(BRD_BASE_PIO_RDY_CKOUT,BRD_RDY_CKOUT_MASK)
#define BRD_CLR_RDY_CKOUT    pio_clear(BRD_BASE_PIO_RDY_CKOUT,BRD_RDY_CKOUT_MASK)
#define BRD_TOGGLE_RDY_CKOUT pio_toggle(BRD_BASE_PIO_RDY_CKOUT,BRD_RDY_CKOUT_MASK)
#define BRD_SET_MISO         pio_set(BRD_BASE_PIO_MISO,BRD_MISO_MASK)
#define BRD_CLR_MISO         pio_clear(BRD_BASE_PIO_MISO,BRD_MISO_MASK)
#define BRD_TOGGLE_MISO      pio_toggle(BRD_BASE_PIO_MISO,BRD_MISO_MASK)

//RDY_CKOUT naming changed for BUSY_CKOUT: both definitions kept for compatibility
#define BRD_SET_BUSY_CKOUT    pio_set(BRD_BASE_PIO_RDY_CKOUT,BRD_RDY_CKOUT_MASK)
#define BRD_CLR_BUSY_CKOUT    pio_clear(BRD_BASE_PIO_RDY_CKOUT,BRD_RDY_CKOUT_MASK)
#define BRD_TOGGLE_BUSY_CKOUT pio_toggle(BRD_BASE_PIO_RDY_CKOUT,BRD_RDY_CKOUT_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_WKUP_STOP   PIOA
#define BRD_BASE_PIO_SPCK        PIOB
#define BRD_BASE_PIO_MOSI        PIOB
#define BRD_BASE_PIO_CSS         PIOB

#define BRD_ID_PIO_WKUP_STOP  ID_PIOA
#define BRD_ID_PIO_SPCK       ID_PIOB
#define BRD_ID_PIO_MOSI       ID_PIOB
#define BRD_ID_PIO_CSS        ID_PIOB

#define BRD_WKUP_STOP_MASK  (1<<9)   //PA9
#define BRD_SPCK_MASK       (1<<6)   //PB6
#define BRD_MOSI_MASK       (1<<12)  //PB12
#define BRD_CSS_MASK        (1<<7)   //PB7

#define BRD_PIOA_INPUT_MASK    (BRD_WKUP_STOP_MASK)
#define BRD_PIOB_INPUT_MASK    (BRD_SPCK_MASK | BRD_MOSI_MASK | BRD_CSS_MASK)
#define BRD_PIOC_INPUT_MASK    (0) // none
#define BRD_PIOD_INPUT_MASK    (0) // none
#define BRD_PIOE_INPUT_MASK    (0) // none

#define BRD_GET_WKUP_STOP pio_get(BRD_BASE_PIO_WKUP_STOP,PIO_INPUT,BRD_WKUP_STOP_MASK)
#define BRD_GET_SPCK      pio_get(BRD_BASE_PIO_SPCK,PIO_INPUT,BRD_SPCK_MASK)
#define BRD_GET_MOSI      pio_get(BRD_BASE_PIO_MOSI,PIO_INPUT,BRD_MOSI_MASK)
#define BRD_GET_CSS       pio_get(BRD_BASE_PIO_CSS,PIO_INPUT,BRD_CSS_MASK)
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC        (0)   // none
#define BRD_MAIN_OSC        (0)   // none
#define BRD_SLOW_XTAL       (0)   // none
#define BRD_MAIN_XTAL       (0)   // none
#define BRD_SLOW_XTAL_FREQ  (0)   // none
#define BRD_MAIN_XTAL_FREQ  (0)   // none
#define BRD_MAIN_OSC_FREQ   (0)   // none
/*----------------------------------------------------------------------------*/



//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// CANOPUS //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////




#endif // _65103_PROBE_CARD_H
