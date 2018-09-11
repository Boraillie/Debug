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
#ifndef _CAPELLA_TESTPROD_H
#define _CAPELLA_TESTPROD_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : CAPELLA
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO CAPELLA done |
____________________________________________
| UART1 (J15)    |  PB3=URXD1 / PB2=UTXD1  |
| USART5 (J16)   |  PA11=RXD5 / PA10=TXD5  |
| 		 |  PA14=RTS5 / PA13=CTS5  |
| Gr LED (D2)    |  PB23 (1 => LED off)    |
| Gr LED (D3)    |  PB24 (1 => LED off)    |
| Power LED (D4) |  VDDMAIN                |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"



/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (1)
#define BRD_PIOC_HAS_IO (0)
#define BRD_PIOD_HAS_IO (0)
#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition   for pioV4 from sama5d2 done for CAPELLA         */
/*----------------------------------------------------------------------------*/
#define BRD_LED_PIO_LETTER    B
#define BRD_LED1_PIO_LETTER   BRD_LED_PIO_LETTER
#define BRD_LED2_PIO_LETTER   BRD_LED_PIO_LETTER

#define BRD_LED1_MASK      (1<<23)  // PB23 LED1
#define BRD_LED2_MASK      (1<<24)  // PB24 LED2

#define BRD_LED1_POLARITY (0) // (0 => LED On)
#define BRD_LED2_POLARITY (0) // (0 => LED On)
//-------------------------------------------------------------

#define BRD_LED1_BASE_PIO     MERGE(PI,O,BRD_LED1_PIO_LETTER, )
#define BRD_LED2_BASE_PIO     MERGE(PI,O,BRD_LED2_PIO_LETTER, )
#define BRD_LED1_ID_PIO       MERGE(ID_,PI,O,BRD_LED1_PIO_LETTER)
#define BRD_LED2_ID_PIO       MERGE(ID_,PI,O,BRD_LED2_PIO_LETTER)
#ifdef BRD_LED_PIO_LETTER
  #define BRD_LED_BASE_PIO     MERGE(PI,O,BRD_LED_PIO_LETTER, )
  #define BRD_LED_ID_PIO       MERGE(ID_,PI,O,BRD_LED_PIO_LETTER)
#endif

#define BRD_TURN_ON_LED1   v_pioV4_clear (BRD_LED1_BASE_PIO,BRD_LED1_MASK)
#define BRD_TURN_OFF_LED1  v_pioV4_set   (BRD_LED1_BASE_PIO,BRD_LED1_MASK)
#define BRD_TOGGLE_LED1    v_pioV4_toggle(BRD_LED1_BASE_PIO,BRD_LED1_MASK)
#define BRD_TURN_ON_LED2   v_pioV4_clear (BRD_LED2_BASE_PIO,BRD_LED2_MASK)
#define BRD_TURN_OFF_LED2  v_pioV4_set   (BRD_LED2_BASE_PIO,BRD_LED2_MASK)
#define BRD_TOGGLE_LED2    v_pioV4_toggle(BRD_LED2_BASE_PIO,BRD_LED2_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition for pioV4 from sama5d2 done for CAPELLA         */
/*----------------------------------------------------------------------------*/
//#define BRD_BP_PIO_LETTER    C   //ERr last update //was C updated MNn 12/10/16
#define BRD_BP1_PIO_LETTER   B//BRD_BP_PIO_LETTER
#define BRD_BP3_PIO_LETTER   C//BRD_BP_PIO_LETTER
#define BRD_BP4_PIO_LETTER   C//BRD_BP_PIO_LETTER

#define BRD_BP1_MASK         (0x1u<<4) //ERr last update
#define BRD_BP3_MASK         (0x1u<<6) //ERr last update //"LEFT CLICK" was 0x1u<<6) updated MNn 12/10/16
#define BRD_BP4_MASK         (0x1u<<7) //ERr last update //"RIGHT CLICK" was (0x1u<<7) updated MNn 12/10/16
//-------------------------------------------------------------

#define BRD_BP1_BASE_PIO     MERGE(PI,O,BRD_BP1_PIO_LETTER, )
#define BRD_BP3_BASE_PIO     MERGE(PI,O,BRD_BP3_PIO_LETTER, )
#define BRD_BP4_BASE_PIO     MERGE(PI,O,BRD_BP4_PIO_LETTER, )
#define BRD_BP1_ID_PIO       MERGE(ID_,PI,O,BRD_BP1_PIO_LETTER)
#define BRD_BP3_ID_PIO       MERGE(ID_,PI,O,BRD_BP3_PIO_LETTER)
#define BRD_BP4_ID_PIO       MERGE(ID_,PI,O,BRD_BP4_PIO_LETTER)
#ifdef BRD_BP_PIO_LETTER
  #define BRD_BP_BASE_PIO     MERGE(PI,O,BRD_BP_PIO_LETTER, )
  #define BRD_BP_ID_PIO       MERGE(ID_,PI,O,BRD_BP_PIO_LETTER)
#endif

#define BRD_GET_BP1    v_pioV4_get(BRD_BP1_BASE_PIO,BRD_BP1_MASK)
#define BRD_GET_BP3    v_pioV4_get(BRD_BP3_BASE_PIO,BRD_BP3_MASK)
#define BRD_GET_BP4    v_pioV4_get(BRD_BP4_BASE_PIO,BRD_BP4_MASK)

#define BRD_BP_IT_HANDLER    MERGE(PI,O,BRD_BP_PIO_LETTER,HANDLER_SUFFIX)
#define BRD_BP1_IT_HANDLER   MERGE(PI,O,BRD_BP1_PIO_LETTER,HANDLER_SUFFIX)
#define BRD_BP3_IT_HANDLER   MERGE(PI,O,BRD_BP3_PIO_LETTER,HANDLER_SUFFIX)
#define BRD_BP4_IT_HANDLER   MERGE(PI,O,BRD_BP4_PIO_LETTER,HANDLER_SUFFIX)

#define BRD_PIO_HAS_INPUTS ( BRD_PIOA_INPUT_MASK |BRD_PIOB_INPUT_MASK \
                           | BRD_PIOC_INPUT_MASK |BRD_PIOD_INPUT_MASK )
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------
// ---- PRG mode definitions ----
//-------------------------------
// SPI link: FLEXCOM1
// PRG mode outputs //////////////////////////////////////////////////////////
#define BRD_PIO_BASE_BUSY_CKOUT  PIOA
#define BRD_PIO_BASE_MISO        PIOB
#define BRD_PIO_ID_BUSY_CKOUT    ID_PIOA
#define BRD_PIO_ID_MISO          ID_PIOB
#define BRD_PIO_MASK_BUSY_CKOUT  (1<<5) // PA5 = PCK1
#define BRD_PIO_MASK_MISO        (1<<3) // PB3 = FLEXCOM1_IO1
//----------------------------------------------------
//cjn 07feb17: add missing PIO configuration for BUSY_CKOUT
//#define BRD_CFG_BUSY_CKOUT    v_pioV4_iocfg_output_default(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_SET_BUSY_CKOUT    v_pioV4_set(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_SET_MISO          v_pioV4_set(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_CLR_BUSY_CKOUT    v_pioV4_clear(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_CLR_MISO          v_pioV4_clear(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_TOGGLE_BUSY_CKOUT v_pioV4_toggle(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_TOGGLE_MISO       v_pioV4_toggle(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)

// PRG mode inputs ///////////////////////////////////////////////////////////
#define BRD_PIO_BASE_WKUP_STOP   PIOA
#define BRD_PIO_BASE_SPCK        PIOA
#define BRD_PIO_BASE_MOSI        PIOB
#define BRD_PIO_BASE_CSS         PIOB
#define BRD_PIO_ID_WKUP_STOP  ID_PIOA
#define BRD_PIO_ID_SPCK       ID_PIOA
#define BRD_PIO_ID_MOSI       ID_PIOB
#define BRD_PIO_ID_CSS        ID_PIOB

#define BRD_PIO_MASK_WKUP_STOP  (1<<17) // PA17 = WKUP4
#define BRD_PIO_MASK_SPCK       (1<<16) // PA16 = FLEXCOM1_IO2 (SPCK)
#define BRD_PIO_MASK_MOSI       (1<<2 ) // PB2  = FLEXCOM1_IO0 (MOSI)
#define BRD_PIO_MASK_CSS        (1<<12) // PB12 = FLEXCOM1_IO3 (NSS )
#define BRD_GET_WKUP_STOP v_pioV4_get(BRD_PIO_BASE_WKUP_STOP,BRD_PIO_MASK_WKUP_STOP)
#define BRD_GET_SPCK      v_pioV4_get(BRD_PIO_BASE_SPCK,BRD_PIO_MASK_SPCK)
#define BRD_GET_MOSI      v_pioV4_get(BRD_PIO_BASE_MOSI,BRD_PIO_MASK_MOSI)
#define BRD_GET_CSS       v_pioV4_get(BRD_PIO_BASE_CSS,BRD_PIO_MASK_CSS)
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/* -- PIO I/Os summary                                                        */
/*----------------------------------------------------------------------------*/
#define BRD_PIOA_OUTPUT_MASK  (BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_PIOB_OUTPUT_MASK  (BRD_LED1_MASK|BRD_LED2_MASK)
#define BRD_PIOC_OUTPUT_MASK  (0) // none
#define BRD_PIOD_OUTPUT_MASK  (0) // none
#define BRD_PIOE_OUTPUT_MASK  (0) // none
//---------------------------------------------------------------
#define BRD_PIOA_INPUT_MASK   (BRD_PIO_MASK_WKUP_STOP)
#define BRD_PIOB_INPUT_MASK   (BRD_BP1_MASK)
#define BRD_PIOC_INPUT_MASK   (BRD_BP3_MASK|BRD_BP4_MASK)
#define BRD_PIOD_INPUT_MASK   (0)
#define BRD_PIOE_INPUT_MASK   (0)
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Board Clocks done for CAPELLA                                     */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)
#define BRD_MAIN_OSC     		(0)
#define BRD_SLOW_XTAL    		(0)
#define BRD_MAIN_XTAL    		(0)
#define BRD_SLOW_XTAL_FREQ    		(32768)      //
#define BRD_MAIN_XTAL_FREQ    		(12000000)   //
//#define BRD_MAIN_OSC_FREQ    		 (3000000)   //
/*----------------------------------------------------------------------------*/



//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_USART0 (20) // UART0 on J15
//#define BRD_USART5 (25) // USART1 on J16
//------------------------------------------------------------------------------

/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// CAPELLA //////////////////////////////////////////////////

//USART0
#define BRD_BASE_PIO_USART0  PIOB
#define BRD_ID_PIO_USART0    ID_PIOB
#define BRD_USART0_RXD	     PIO_PB10A_FLEXCOM0_IO1
#define BRD_USART0_TXD	     PIO_PB7A_FLEXCOM0_IO0
#define BRD_PERIPH_USART0    PIO_PERIPH_A

//SPI
// ---- SPI1 (FLEXCOM1) --------------------------------------
#define BRD_PERIPH_SPI1      PIO_PERIPH_C
//#define HWSPI_MISO_PIO_PERIPH  PIO_PERIPH_C //MISO
//#define HWSPI_MOSI_PIO_PERIPH  PIO_PERIPH_C //MOSI
//#define HWSPI_SPCK_PIO_PERIPH  PIO_PERIPH_C //SPCK
//#define HWSPI_CSS_PIO_PERIPH   PIO_PERIPH_C //CSS


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

//ADC
/*
#define BRD_AFE0_ADTRG_PIO_BASE    PIOA
#define BRD_AFE0_ADTRG_PIO_PERIPH  PIO_PERIPH_B
#define BRD_AFE0_ADTRG_PIO_MASK    (1<<8)
#define BRD_AFE1_ADTRG_PIO_BASE    PIOD
#define BRD_AFE1_ADTRG_PIO_PERIPH  PIO_PERIPH_C
#define BRD_AFE1_ADTRG_PIO_MASK    (1<<9)
*/
/////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// SoftPack definitions ///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define BOARD_NAME "capella-testprod"
#define BOARD_MAIN_CLOCK_EXT_OSC (EXT_CLOCK_FREQ)
#define BOARD_TIMER_TC      TC1
#define BOARD_TIMER_CHANNEL 0

#define BOARD_PMC_PLLA_MUL (PLLA_MUL)
#define BOARD_PMC_PLLA_DIV (PLLA_DIV)

//#define CONFIG_CHIP_SAMU70S20 1
//#define CONFIG_BOARD_SAMU70_VB_LQFP176 1
//#define CONFIG_SERIALD_USART 1
#define CONFIG_HAVE_SERIALD_USART 0
#define CONFIG_HAVE_LED 0



#endif /* CAPELLA_TESTPROD_H */

