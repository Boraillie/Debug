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
#ifndef _SAM9X6_TYPHOON_FPGA_H
#define _SAM9X6_TYPHOON_FPGA_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAM9X6
*
*
*----------------------------------------------------------------------------
-------------------------------------------------
|    Board             |        PIO             |
+----------------------+------------------------+
| UART0     (J88/J87)  |  PA1=URXD0/PA0=UTXD0 |     done sam9x5 
| USART3    (J93/J91)  |  PA13=RXD3 / PA15=TXD3 |   NA
|           (J92/J94)  |  PA17=RTS3 / PA16=CTS3 |   NA
|				                |
| Yellow LED    (D1)   |  PC19 (1 => LED off)   |   done sam9x5
| Green LED 	(D2)   |  PC20 (1 => LED off)   |   done sam9x5 
| Power LED red	(D3)   |  5V (from MPM)         |
|                                               |
| Left click 	(BP3)  |  PC2  (push => 0)     |   done sam9x5 
| Right click 	(BP4)  |  PC3  (push => 0)     |   done sam9x5 
=================================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"

/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (1)
#define BRD_PIOC_HAS_IO (1)
#define BRD_PIOD_HAS_IO (1)
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/

#define BRD_BASE_PIO_OUTPUT  PIOB
#define BRD_ID_PIO_OUTPUT    ID_PIOB

#define BRD_D11_MASK      (1u<<11)  	/* PB11 D11 */
#define BRD_D12_MASK      (1u<<12)	/* PB12 D12 */

#define BRD_D11_POLARITY 0 // (0 => LED On)
#define BRD_D12_POLARITY 0 // (0 => LED On)

#define BRD_PIOA_OUTPUT_MASK  (0)
#define BRD_PIOB_OUTPUT_MASK  (BRD_D11_MASK|BRD_D12_MASK) 
#define BRD_PIOC_OUTPUT_MASK  (0) // none
#define BRD_PIOD_OUTPUT_MASK  (0) // D2 D3
#define BRD_PIOE_OUTPUT_MASK  (0) // none

#define BRD_TURN_ON_D11   pio_clear(BRD_BASE_PIO_OUTPUT,BRD_D11_MASK)
#define BRD_TURN_OFF_D11  pio_set(BRD_BASE_PIO_OUTPUT,BRD_D11_MASK)
#define BRD_TOGGLE_D11    pio_toggle(BRD_BASE_PIO_OUTPUT,BRD_D11_MASK)
#define BRD_TURN_ON_D12   pio_clear(BRD_BASE_PIO_OUTPUT,BRD_D12_MASK)
#define BRD_TURN_OFF_D12  pio_set(BRD_BASE_PIO_OUTPUT,BRD_D12_MASK)
#define BRD_TOGGLE_D12    pio_toggle(BRD_BASE_PIO_OUTPUT,BRD_D12_MASK)


/*
#define BRD_LED_PIO_LETTER    B   //done sam9x5 
#define BRD_LED1_PIO_LETTER   BRD_LED_PIO_LETTER
#define BRD_LED2_PIO_LETTER   BRD_LED_PIO_LETTER

#define BRD_LED1_MASK      (1<<11)  // PC19 LED1 done sam9x5 
#define BRD_LED2_MASK      (1<<12)  // PC20 LED2 done sam9x5 

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

#define BRD_TURN_ON_LED1   pio_clear (BRD_LED1_BASE_PIO,BRD_LED1_MASK)
#define BRD_TURN_OFF_LED1  pio_set   (BRD_LED1_BASE_PIO,BRD_LED1_MASK)
#define BRD_TOGGLE_LED1    pio_toggle(BRD_LED1_BASE_PIO,BRD_LED1_MASK)
#define BRD_TURN_ON_LED2   pio_clear (BRD_LED2_BASE_PIO,BRD_LED2_MASK)
#define BRD_TURN_OFF_LED2  pio_set   (BRD_LED2_BASE_PIO,BRD_LED2_MASK)
#define BRD_TOGGLE_LED2    pio_toggle(BRD_LED2_BASE_PIO,BRD_LED2_MASK)
*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/

#define BRD_BP_PIO_LETTER    B
#define BRD_BP3_PIO_LETTER   BRD_BP_PIO_LETTER
#define BRD_BP4_PIO_LETTER   BRD_BP_PIO_LETTER

#define BRD_BP_BASE_PIO   PIOB
#define BRD_ID_PIO_BP3     ID_PIOB
#define BRD_ID_PIO_BP4     ID_PIOB
#define BRD_BP3_MASK       (0x1u<<18)	// PB18  SW13 on FPGA
#define BRD_BP4_MASK       (0x1u<<25)	// PB25  SW14 on FPGA

#define BRD_PIOA_INPUT_MASK    (0) // none
#define BRD_PIOB_INPUT_MASK    (BRD_BP3_MASK|BRD_BP4_MASK) // none
#define BRD_PIOC_INPUT_MASK    (0)
#define BRD_PIOD_INPUT_MASK    (0)
#define BRD_PIOE_INPUT_MASK    (0) // none

#define BRD_GET_BP3  pio_get(BRD_BASE_PIO_BP3,PIO_INPUT,BRD_BP3_MASK)
#define BRD_GET_BP4  pio_get(BRD_BASE_PIO_BP4,PIO_INPUT,BRD_BP4_MASK)

#define BRD_BP_IT_HANDLER    MERGE(PI,O,BRD_BP_PIO_LETTER,HANDLER_SUFFIX)
#define BRD_BP3_IT_HANDLER   MERGE(PI,O,BRD_BP3_PIO_LETTER,HANDLER_SUFFIX)
#define BRD_BP4_IT_HANDLER   MERGE(PI,O,BRD_BP4_PIO_LETTER,HANDLER_SUFFIX)


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC           (0)
#define BRD_MAIN_OSC           (0)
#define BRD_SLOW_XTAL          (1)      // Y1(R3  & R7 )
#define BRD_MAIN_XTAL          (1)      // Y2(R12 & R15)
#define BRD_SLOW_XTAL_FREQ     (32768)  // Y1(R3  & R7 )
#define BRD_MAIN_XTAL_FREQ  (15000000)  // Y2(R12 & R15) typhoon board clocks are fixed at 15MHz
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board available serial links                                      */
/*----------------------------------------------------------------------------*/
#define BRD_UART0   (0x10)  // UART0 (J87/J88)

#define BRD_DBGU  (0xDB)  // USART3 (J91/J92/J93/J94)

//#warning BRD files: PRG mode PIO definition to update for SAM9X6!!!
//------------------------------------------------------------------------------
// ---- PRG mode definitions ----
//-------------------------------

// PRG mode outputs //////////////////////////////////////////////////////////
#define BRD_PIO_BASE_BUSY_CKOUT  BRD_BASE_PIO_OUTPUT
#define BRD_PIO_ID_BUSY_CKOUT    BRD_ID_PIO_OUTPUT
#define BRD_PIO_MASK_BUSY_CKOUT  BRD_D11_MASK

//----------------------------------------------------

#define BRD_SET_BUSY_CKOUT    pio_set(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_CLR_BUSY_CKOUT    pio_clear(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_TOGGLE_BUSY_CKOUT pio_toggle(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)


// SPI link:
#define BRD_PIO_BASE_MISO     PIOA
#define BRD_PIO_ID_MISO       ID_PIOA
#define BRD_PIO_MASK_MISO     (1<<11) //done sam9x5

#define BRD_SET_MISO          pio_set(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_CLR_MISO          pio_clear(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_TOGGLE_MISO       pio_toggle(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)

// PRG mode inputs ///////////////////////////////////////////////////////////
#define BRD_PIO_BASE_WKUP_STOP   BRD_BP_BASE_PIO
#define BRD_PIO_ID_WKUP_STOP     BRD_BP3_ID_PIO
#define BRD_PIO_MASK_WKUP_STOP   BRD_BP3_MASK   //BP3 user switch???

#define BRD_PIO_BASE_SPCK        PIOA
#define BRD_PIO_BASE_MOSI        PIOA
#define BRD_PIO_BASE_CSS         PIOA
#define BRD_PIO_ID_SPCK       ID_PIOA
#define BRD_PIO_ID_MOSI       ID_PIOA
#define BRD_PIO_ID_CSS        ID_PIOA
#define BRD_PIO_MASK_SPCK  (1<<13) //done sam9x5 
#define BRD_PIO_MASK_MOSI  (1<<12) //done sam9x5 
#define BRD_PIO_MASK_CSS   (1<<14) //done sam9x5 

//----------------------------------------------------
// to be updated with pio3 code
#define BRD_GET_WKUP_STOP pio_get(BRD_PIO_BASE_WKUP_STOP,PIO_INPUT,BRD_PIO_MASK_WKUP_STOP)
#define BRD_GET_SPCK      pio_get(BRD_PIO_BASE_SPCK,PIO_INPUT,BRD_PIO_MASK_SPCK)
#define BRD_GET_MOSI      pio_get(BRD_PIO_BASE_MOSI,PIO_INPUT,BRD_PIO_MASK_MOSI)
#define BRD_GET_CSS       pio_get(BRD_PIO_BASE_CSS,PIO_INPUT,BRD_PIO_MASK_CSS)

//------------------------------------------------------------------------------

#define BRD_PIOA_OUTPUT_MASK  (0)
#define BRD_PIOC_OUTPUT_MASK  (PIO_PC15C_PCK0|PIO_PC31C_PCK1) //done sam9x5
#define BRD_PIOD_OUTPUT_MASK  (0)
#define BRD_PIOE_OUTPUT_MASK  (0) // none

/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// SAM9X6 ////////////////////////////////////////////////////
#if (SAM9X6 ==1)
// ---- DEBUG UNIT DBGU -------------------------------
  #define BRD_BASE_PIO_DBGU  PIOA
  #define BRD_ID_PIO_DBGU    ID_PIOA
// to be updated MNn
  #define BRD_DBGU_RXD	      PIO_PA9A_DRXD
  #define BRD_DBGU_TXD	      PIO_PA10A_DTXD
  #define BRD_PERIPH_DBGU     PIO_PERIPH_A
// ---- USART3 on J91/J92/J93/J94 ----------------------------------
// ---- SPI1 -------------------------------------------------------
  #define BRD_PERIPH_SPI1      PIO_PERIPH_D
// to be updated MNn
  #define HWSPI_MISO_PIO_PERIPH  PIO_PERIPH_D //MISO
  #define HWSPI_MOSI_PIO_PERIPH  PIO_PERIPH_D //MOSI
  #define HWSPI_SPCK_PIO_PERIPH  PIO_PERIPH_D //SPCK
  #define HWSPI_CSS_PIO_PERIPH   PIO_PERIPH_D //CSS

/////////////////////////////////////////////////////////////
//#elif (SAMA5D2_yy==1)
#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////

#endif // _SAM9X6_TYPHOON_FPGA_H
