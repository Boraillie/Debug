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
* Modification        : Olivier DUMAS - 6 Oct 2014 - Add SAM4S XPLAINED Board 
*----------------------------------------------------------------------------
*/
#ifndef _SAM4S_XPLAINED_H
#define _SAM4S_XPLAINED_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAM4S16C-AU
*
*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO              |
____________________________________________
| Ye LED (LED1)  |  PC10 (1 => LED off)    |
| Ye LED (LED2)  |  PC17 (1 => LED off)    |
| RClick (BP2)   |  PA5  (push => 0)       |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (0)
#define BRD_PIOC_HAS_IO (1)
//#define BRD_PIOD_HAS_IO (0)
//#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_LED1  PIOC
#define BRD_BASE_PIO_LED2  PIOC
#define BRD_ID_PIO_LED1    ID_PIOC
#define BRD_ID_PIO_LED2    ID_PIOC
#define BRD_LED1_MASK      (1<<10)  /* PC10 LED1*/ 
#define BRD_LED2_MASK      (1<<17)  /* PC17 LED2*/

//#define BRD_LED1_POLARITY 1 // (0 => LED On)
//#define BRD_LED2_POLARITY 1 // (0 => LED On)

#define BRD_BASE_PIO_ALL_LED  PIOC /////////////////////////////////////////////
#define BRD_ID_PIO_ALL_LED    ID_PIOC///////////////////////////////////////////
#define BRD_ALL_LED_MASK      (BRD_LED1_MASK|BRD_LED2_MASK)/////////////

#define BRD_PIOA_LED_MASK  (0) // none
#define BRD_PIOB_LED_MASK  (0) // none
#define BRD_PIOC_LED_MASK  (BRD_LED1_MASK|BRD_LED2_MASK) // none
#define BRD_PIOD_LED_MASK  (0) // none
#define BRD_PIOE_LED_MASK  (0) // none

#define BRD_TURN_OFF_LED1  pio_set(BRD_BASE_PIO_LED1,BRD_LED1_MASK)
#define BRD_TURN_ON_LED1   pio_clear(BRD_BASE_PIO_LED1,BRD_LED1_MASK)
#define BRD_TOGGLE_LED1    pio_toggle(BRD_BASE_PIO_LED1,BRD_LED1_MASK)
#define BRD_TURN_OFF_LED2  pio_clear(BRD_BASE_PIO_LED2,BRD_LED2_MASK)
#define BRD_TURN_ON_LED2   pio_set(BRD_BASE_PIO_LED2,BRD_LED2_MASK)
#define BRD_TOGGLE_LED2    pio_toggle(BRD_BASE_PIO_LED2,BRD_LED2_MASK)

#define BRD_BASE_PIO_RDY_CKOUT  PIOA
#define BRD_ID_PIO_RDY_CKOUT    ID_PIOA
#define BRD_BASE_PIO_MISO       PIOA
#define BRD_ID_PIO_MISO         ID_PIOA

#define BRD_RDY_CKOUT_MASK     (1<<4)  //PA4
#define BRD_MISO_MASK          (1<<12) //PA12

#define BRD_PIOA_OUTPUT_MASK  (BRD_RDY_CKOUT_MASK)
#define BRD_PIOB_OUTPUT_MASK  (0) // none
#define BRD_PIOC_OUTPUT_MASK  (BRD_PIOC_LED_MASK)
#define BRD_PIOD_OUTPUT_MASK  (0) // none
#define BRD_PIOE_OUTPUT_MASK  (0) // none

#define BRD_SET_RDY_CKOUT    pio_set(BRD_BASE_PIO_RDY_CKOUT,BRD_RDY_CKOUT_MASK)
#define BRD_CLR_RDY_CKOUT    pio_clear(BRD_BASE_PIO_RDY_CKOUT,BRD_RDY_CKOUT_MASK)
#define BRD_TOGGLE_RDY_CKOUT pio_toggle(BRD_BASE_PIO_RDY_CKOUT,BRD_RDY_CKOUT_MASK)
#define BRD_SET_MISO         pio_set(BRD_BASE_PIO_MISO,BRD_MISO_MASK)
#define BRD_CLR_MISO         pio_clear(BRD_BASE_PIO_MISO,BRD_MISO_MASK)
#define BRD_TOGGLE_MISO      pio_toggle(BRD_BASE_PIO_MISO,BRD_MISO_MASK)

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_BP2   PIOA
#define BRD_ID_PIO_BP2     ID_PIOA
#define BRD_BP2_MASK       (1<<5)	// PA5  RIGHT CLICK 

#define BRD_BASE_PIO_ALL_INPUT  PIOA ///////////////////////////////////////////
#define BRD_ID_PIO_ALL_INPUT    ID_PIOA ////////////////////////////////////////
#define BRD_ALL_INPUT_MASK      BRD_BP2_MASK //////////////////

#define BRD_GET_BP2  pio_get(BRD_BASE_PIO_BP2,PIO_INPUT,BRD_BP2_MASK)

#define BRD_BASE_PIO_WKUP_STOP   PIOA
#define BRD_BASE_PIO_SPCK        PIOA
#define BRD_BASE_PIO_MOSI        PIOA
#define BRD_BASE_PIO_NSS         PIOA
#define BRD_BASE_PIO_NPCS        PIOA

#define BRD_ID_PIO_WKUP_STOP  ID_PIOA
#define BRD_ID_PIO_SPCK       ID_PIOA
#define BRD_ID_PIO_MOSI       ID_PIOA
#define BRD_ID_PIO_NSS        ID_PIOA
#define BRD_ID_PIO_NPCS       ID_PIOA

#define BRD_SPI_NPCS_INDEX    1         // for Master in hardware mode

#define BRD_BASE_PIO_NSS_IRQn PIOA_IRQn // for Slave in emulated mode

#define BRD_WKUP_STOP_MASK  (1<<9)   //PA9
#define BRD_SPCK_MASK       (1<<14)  //PA14
#define BRD_MOSI_MASK       (1<<13)  //PA13
#define BRD_NSS_MASK        (1<<11)  //PA11 (NPCS0/NSS) for Slave
#define BRD_NPCS_MASK       (1<<31)  //PA31 (NPCS1)     for Master

#define BRD_PIOA_INPUT_MASK    (BRD_BP2_MASK|BRD_WKUP_STOP_MASK)
#define BRD_PIOB_INPUT_MASK    (0) // none
#define BRD_PIOC_INPUT_MASK    (0) // none
#define BRD_PIOD_INPUT_MASK    (0) // none
#define BRD_PIOE_INPUT_MASK    (0) // none

#define BRD_GET_WKUP_STOP pio_get(BRD_BASE_PIO_WKUP_STOP,PIO_INPUT,BRD_WKUP_STOP_MASK)
#define BRD_GET_SPCK      pio_get(BRD_BASE_PIO_SPCK,PIO_INPUT,BRD_SPCK_MASK)
#define BRD_GET_MOSI      pio_get(BRD_BASE_PIO_MOSI,PIO_INPUT,BRD_MOSI_MASK)
#define BRD_GET_NSS       pio_get(BRD_BASE_PIO_NSS,PIO_INPUT,BRD_NSS_MASK)

/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0) // NONE bypass through J7 connector
#define BRD_MAIN_OSC     		(0) // NONE bypass through J6 connector
#define BRD_SLOW_XTAL    		(1) // Y3(R28 & R30)
#define BRD_MAIN_XTAL    		(1) //
#define BRD_SLOW_XTAL_FREQ          (32768) //

#ifdef SAM7
  #define BRD_MAIN_XTAL_FREQ   (18432000)  // Y4(JP29 & JP30)
#else
  #define BRD_MAIN_XTAL_FREQ   (12000000)  // Y2(JP31 & JP32) or Y1(R21 & R24)
#endif//sam7
/*----------------------------------------------------------------------------*/



//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// SAM3S ////////////////////////////////////////////////////
#if (SAM3S==1 || SAM3S8==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_A
  #define BRD_BASE_PIO_UART1  PIOB
  #define BRD_ID_PIO_UART1    ID_PIOB
  #define BRD_UART1_RXD	      PIO_PB2A_URXD1
  #define BRD_UART1_TXD	      PIO_PB3A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
// SAM4S ////////////////////////////////////////////////////
#elif (SAM4S==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_A
  #define BRD_BASE_PIO_UART1  PIOB
  #define BRD_ID_PIO_UART1    ID_PIOB
  #define BRD_UART1_RXD	      PIO_PB2A_URXD1
  #define BRD_UART1_TXD	      PIO_PB3A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
// SAM4N ////////////////////////////////////////////////////
#elif (SAM4N==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_A
  #define BRD_BASE_PIO_UART1  PIOB
  #define BRD_ID_PIO_UART1    ID_PIOB
  #define BRD_UART1_RXD	      PIO_PB2A_URXD1
  #define BRD_UART1_TXD	      PIO_PB3A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
// SIRIUS ////////////////////////////////////////////////////
#elif (SIRIUS==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_A
  #define BRD_BASE_PIO_UART1  PIOB
  #define BRD_ID_PIO_UART1    ID_PIOB
  #define BRD_UART1_RXD	      PIO_PB2A_URXD1
  #define BRD_UART1_TXD	      PIO_PB3A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////




#endif /* _SAM4S_XPLAINED_H */
