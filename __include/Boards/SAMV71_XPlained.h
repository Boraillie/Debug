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
#ifndef _SAMV71_XPLAINED_H
#define _SAMV71_XPLAINED_H


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
#define BRD_PIOC_HAS_IO (1)
#define BRD_PIOD_HAS_IO (1)
#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/




/*----------------------------------------------------------------------------*/
/* -------- Outputs Definition                                                */
/*----------------------------------------------------------------------------*/
// User LEDs /////////////////////////////////////////////////////////////////
#define BRD_PIO_BASE_LED0 PIOA
#define BRD_PIO_BASE_LED1 PIOC
#define BRD_PIO_ID_LED0 ID_PIOA
#define BRD_PIO_ID_LED1 ID_PIOC
#define BRD_PIO_MASK_LED0 (1<<23)//PA23
#define BRD_PIO_MASK_LED1 (1<<9)//PC09
#define BRD_TURN_OFF_LED0 pio_set(BRD_PIO_BASE_LED0,BRD_PIO_MASK_LED0)
#define BRD_TURN_ON_LED0  pio_clear(BRD_PIO_BASE_LED0,BRD_PIO_MASK_LED0)
#define BRD_TOGGLE_LD0    pio_toggle(BRD_PIO_BASE_LED0,BRD_PIO_MASK_LED0)
#define BRD_TURN_OFF_LED1 pio_set(BRD_PIO_BASE_LED1,BRD_PIO_MASK_LED1)
#define BRD_TURN_ON_LED1  pio_clear(BRD_PIO_BASE_LED1,BRD_PIO_MASK_LED1)
#define BRD_TOGGLE_LED1   pio_toggle(BRD_PIO_BASE_LED1,BRD_PIO_MASK_LED1)
//////////////////////////////////////////////////////////////////////////////

//______________________________________________________________________________
#define BRD_PIOA_OUTPUT_MASK  (BRD_PIO_MASK_LED0)
#define BRD_PIOB_OUTPUT_MASK  (0) // none
#define BRD_PIOC_OUTPUT_MASK  (BRD_PIO_MASK_LED1) // none
#define BRD_PIOD_OUTPUT_MASK  (BRD_PIO_MASK_MISO) // none
#define BRD_PIOE_OUTPUT_MASK  (0) // none
/*----------------------------------------------------------------------------*/




/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
// User buttons //////////////////////////////////////////////////////////////
#define BRD_PIO_BASE_SW0   PIOA
#define BRD_PIO_BASE_SW1   PIOB
#define BRD_PIO_ID_SW0   ID_PIOA
#define BRD_PIOID__SW1   ID_PIOB
#define BRD_PIO_MASK_SW0   (1<<9)
#define BRD_PIO_MASK_SW1   (1<<12)
#define BRD_GET_SW0       pio_get(BRD_PIO_BASE_SW0,PIO_INPUT,BRD_PIO_MASK_SW0)
#define BRD_GET_SW1       pio_get(BRD_PIO_BASE_SW1,PIO_INPUT,BRD_PIO_MASK_SW1)
//////////////////////////////////////////////////////////////////////////////

//______________________________________________________________________________
#define BRD_PIOA_INPUT_MASK    (BRD_PIO_MASK_SW0)
#define BRD_PIOB_INPUT_MASK    (BRD_PIO_MASK_CSS | BRD_PIO_MASK_SW1)
#define BRD_PIOC_INPUT_MASK    (0) // none
#define BRD_PIOD_INPUT_MASK    (BRD_PIO_MASK_SPCK | BRD_PIO_MASK_MOSI)
#define BRD_PIOE_INPUT_MASK    (0) // none
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
// ---- PRG mode definitions ----
//-------------------------------
// PRG mode outputs //////////////////////////////////////////////////////////
#define BRD_PIO_BASE_BUSY_CKOUT  BRD_PIO_BASE_LED0
#define BRD_PIO_BASE_MISO        PIOD
#define BRD_PIO_ID_BUSY_CKOUT    BRD_PIO_ID_LED0
#define BRD_PIO_ID_MISO          ID_PIOD
#define BRD_PIO_MASK_BUSY_CKOUT  BRD_PIO_MASK_LED0  //LED0
#define BRD_PIO_MASK_MISO        (1<<20) //PD20 - EXT1 (J401) pin17
#define BRD_SET_BUSY_CKOUT    pio_set(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_SET_MISO          pio_set(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_CLR_BUSY_CKOUT    pio_clear(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_CLR_MISO          pio_clear(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_TOGGLE_BUSY_CKOUT pio_toggle(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_TOGGLE_MISO       pio_toggle(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)

// PRG mode inputs ///////////////////////////////////////////////////////////
#define BRD_PIO_BASE_WKUP_STOP   BRD_PIO_BASE_SW0
#define BRD_PIO_BASE_SPCK        PIOD
#define BRD_PIO_BASE_MOSI        PIOD
#define BRD_PIO_BASE_CSS         PIOB
#define BRD_PIO_ID_WKUP_STOP  BRD_PIO_ID_SW0
#define BRD_PIO_ID_SPCK       ID_PIOD
#define BRD_PIO_ID_MOSI       ID_PIOD
#define BRD_PIO_ID_CSS        ID_PIOB
#define BRD_PIO_MASK_WKUP  BRD_PIO_MASK_SW0   //user switch
#define BRD_PIO_MASK_SPCK  (1<<22) //PD22 - EXT1 (J401) pin18
#define BRD_PIO_MASK_MOSI  (1<<21) //PD21 - EXT1 (J401) pin16
#define BRD_PIO_MASK_CSS   (1<<2)  //PB02 - EXT1 (J401) pin6
#define BRD_GET_WKUP_STOP pio_get(BRD_PIO_BASE_WKUP_STOP,PIO_INPUT,BRD_PIO_MASK_WKUP)
#define BRD_GET_SPCK      pio_get(BRD_PIO_BASE_SPCK,PIO_INPUT,BRD_PIO_MASK_SPCK)
#define BRD_GET_MOSI      pio_get(BRD_PIO_BASE_MOSI,PIO_INPUT,BRD_PIO_MASK_MOSI)
#define BRD_GET_CSS       pio_get(BRD_PIO_BASE_CSS,PIO_INPUT,BRD_PIO_MASK_CSS)
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// CANOPUS //////////////////////////////////////////////////
// ---- SPI0 -------------------------------------------------
//#define BRD_PERIPH_SPI0      PIO_PERIPH_xxx
#define HWSPI_MISO_PIO_PERIPH  PIO_PERIPH_B //MISO
#define HWSPI_MOSI_PIO_PERIPH  PIO_PERIPH_B //MOSI
#define HWSPI_SPCK_PIO_PERIPH  PIO_PERIPH_B //SPCK
#define HWSPI_CSS_PIO_PERIPH   PIO_PERIPH_D //CSS

//DACC
#define BRD_DAC0_PIO_BASE        PIOB
#define BRD_DAC0_PIO_PERIPH      PIO_PERIPH_X
#define BRD_DAC0_PIO_MASK        (1<<13)
#define BRD_DAC1_PIO_BASE        PIOD
#define BRD_DAC1_PIO_PERIPH      PIO_PERIPH_X
#define BRD_DAC1_PIO_MASK        (1<<0)
#define BRD_DAC_TRIG_PIO_BASE    PIOA
#define BRD_DAC_TRIG_PIO_PERIPH  PIO_PERIPH_C
#define BRD_DAC_TRIG_PIO_MASK    (1<<2)

//AFE
#define BRD_AFE0_ADTRG_PIO_BASE    PIOA
#define BRD_AFE0_ADTRG_PIO_PERIPH  PIO_PERIPH_B
#define BRD_AFE0_ADTRG_PIO_MASK    (1<<8)
#define BRD_AFE1_ADTRG_PIO_BASE    PIOD
#define BRD_AFE1_ADTRG_PIO_PERIPH  PIO_PERIPH_C
#define BRD_AFE1_ADTRG_PIO_MASK    (1<<9)
/////////////////////////////////////////////////////////////




#endif // _SAMV71_XPLAINED_H
