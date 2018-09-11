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
#ifndef _SAMA5D2_VB_BGA289_H
#define _SAMA5D2_VB_BGA289_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAMA5D2
*
*
*----------------------------------------------------------------------------
-------------------------------------------------
|    Board             |        PIO             |
+----------------------+------------------------+
| UART0     (J88/J87)  |  PB26=URXD0/PB27=UTXD0 |   
| USART3    (J93/J91)  |  PA13=RXD3 / PA15=TXD3 |
|           (J92/J94)  |  PA17=RTS3 / PA16=CTS3 |
|				                |
| Green LED     (D1)   |  PD21 (1 => LED off)   |
| Green LED 	(D2)   |  PD22 (1 => LED off)   |
| Power LED red	(D3)   |  5V (from MPM)         |
|                                               |
| Left click 	(BP3)  |  PD23  (push => 0)     |
| Right click 	(BP4)  |  PD24  (push => 0)     |
=================================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (1)
#define BRD_PIOC_HAS_IO (0)
#define BRD_PIOD_HAS_IO (1)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_LED_PIO_LETTER    D
#define BRD_LED1_PIO_LETTER   BRD_LED_PIO_LETTER
#define BRD_LED2_PIO_LETTER   BRD_LED_PIO_LETTER

#define BRD_LED1_MASK      (1<<21)  // PD21 LED1
#define BRD_LED2_MASK      (1<<22)  // PD22 LED2

#define BRD_LED1_POLARITY (0) // (0 => LED On)
#define BRD_LED2_POLARITY (0) // (0 => LED On)
//-------------------------------------------------------------

//#define BRD_BASE_PIO_D1  PIOD
//#define BRD_BASE_PIO_D2  PIOD
//#define BRD_ID_PIO_D1    ID_PIOD
//#define BRD_ID_PIO_D2    ID_PIOD
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
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BP_PIO_LETTER    D
#define BRD_BP3_PIO_LETTER   BRD_BP_PIO_LETTER
#define BRD_BP4_PIO_LETTER   BRD_BP_PIO_LETTER

#define BRD_BP3_MASK         (0x1u<<23)  // PD23  LEFT CLICK 
#define BRD_BP4_MASK         (0x1u<<24)  // PD24  RIGHT CLICK

//-------------------------------------------------------------

/*
#define BRD_BASE_PIO_BP3   		PIOD
#define BRD_BASE_PIO_BP4   		PIOD
#define BRD_ID_PIO_BP3     		ID_PIOD
#define BRD_ID_PIO_BP4    	 	ID_PIOD
#define BRD_BP3_MASK       		(0x1u<<23)  // PD23  LEFT CLICK 
#define BRD_BP4_MASK       		(0x1u<<24)  // PD24  RIGHT CLICK
*/

#define BRD_BP3_BASE_PIO     MERGE(PI,O,BRD_BP3_PIO_LETTER, )
#define BRD_BP4_BASE_PIO     MERGE(PI,O,BRD_BP4_PIO_LETTER, )
#define BRD_BP3_ID_PIO       MERGE(ID_,PI,O,BRD_BP3_PIO_LETTER)
#define BRD_BP4_ID_PIO       MERGE(ID_,PI,O,BRD_BP4_PIO_LETTER)
#ifdef BRD_BP_PIO_LETTER
  #define BRD_BP_BASE_PIO     MERGE(PI,O,BRD_BP_PIO_LETTER, )
  #define BRD_BP_ID_PIO       MERGE(ID_,PI,O,BRD_BP_PIO_LETTER)
#endif

#define BRD_GET_BP3    v_pioV4_get(BRD_BP3_BASE_PIO,BRD_BP3_MASK)
#define BRD_GET_BP4    v_pioV4_get(BRD_BP4_BASE_PIO,BRD_BP4_MASK)

#define BRD_BP_IT_HANDLER    MERGE(PI,O,BRD_BP_PIO_LETTER,HANDLER_SUFFIX)
#define BRD_BP3_IT_HANDLER   MERGE(PI,O,BRD_BP3_PIO_LETTER,HANDLER_SUFFIX)
#define BRD_BP4_IT_HANDLER   MERGE(PI,O,BRD_BP4_PIO_LETTER,HANDLER_SUFFIX)

#define BRD_PIO_HAS_INPUTS ( BRD_PIOA_INPUT_MASK |BRD_PIOB_INPUT_MASK \
                           | BRD_PIOC_INPUT_MASK |BRD_PIOD_INPUT_MASK )
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC           (0)
#define BRD_MAIN_OSC           (0)
#define BRD_SLOW_XTAL          (1)      // Y1(R3  & R7 )
#define BRD_MAIN_XTAL          (1)      // Y2(R12 & R15)
#define BRD_SLOW_XTAL_FREQ     (32768)  // Y1(R3  & R7 )
#define BRD_MAIN_XTAL_FREQ  (12000000)  // Y2(R12 & R15)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board available serial links                                      */
/*----------------------------------------------------------------------------*/
#define BRD_UART0   (0x10)  // UART0 (J87/J88)
// UART0 = (0x10)
// UART1 = (0x11)
// ...
#define BRD_USART3  (0x23)  // USART3 (J91/J92/J93/J94)
// USART1 = (0x21)
// USART2 = (0x22)
// ...


//#warning BRD files: PRG mode PIO definition to update for 92U03!!!
//------------------------------------------------------------------------------
// ---- PRG mode definitions ----
//-------------------------------

// PRG mode outputs //////////////////////////////////////////////////////////
#define BRD_PIO_BASE_BUSY_CKOUT  BRD_LED1_BASE_PIO
#define BRD_PIO_ID_BUSY_CKOUT    BRD_LED1_ID_PIO
#define BRD_PIO_MASK_BUSY_CKOUT  BRD_LED1_MASK  //LED1???

//----------------------------------------------------
#define BRD_SET_BUSY_CKOUT    v_pioV4_set(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_CLR_BUSY_CKOUT    v_pioV4_clear(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_TOGGLE_BUSY_CKOUT v_pioV4_toggle(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)

// SPI link:
#define BRD_PIO_BASE_MISO     PIOA
#define BRD_PIO_ID_MISO       ID_PIOA
#define BRD_PIO_MASK_MISO     (1<<24) //
#define BRD_SET_MISO          v_pioV4_set(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_CLR_MISO          v_pioV4_clear(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_TOGGLE_MISO       v_pioV4_toggle(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)

// PRG mode inputs ///////////////////////////////////////////////////////////
#define BRD_PIO_BASE_WKUP_STOP   BRD_BP3_BASE_PIO
#define BRD_PIO_ID_WKUP_STOP     BRD_BP3_ID_PIO
#define BRD_PIO_MASK_WKUP_STOP   BRD_BP3_MASK   //BP3 user switch???

#define BRD_PIO_BASE_SPCK        PIOA
#define BRD_PIO_BASE_MOSI        PIOA
#define BRD_PIO_BASE_CSS         PIOA
#define BRD_PIO_ID_SPCK       ID_PIOA
#define BRD_PIO_ID_MOSI       ID_PIOA
#define BRD_PIO_ID_CSS        ID_PIOA
#define BRD_PIO_MASK_SPCK  (1<<22) //
#define BRD_PIO_MASK_MOSI  (1<<23) //
#define BRD_PIO_MASK_CSS   (1<<25) //

//----------------------------------------------------
#define BRD_GET_WKUP_STOP v_pioV4_get(BRD_PIO_BASE_WKUP_STOP,BRD_PIO_MASK_WKUP_STOP)
#define BRD_GET_SPCK      v_pioV4_get(BRD_PIO_BASE_SPCK,BRD_PIO_MASK_SPCK)
#define BRD_GET_MOSI      v_pioV4_get(BRD_PIO_BASE_MOSI,BRD_PIO_MASK_MOSI)
#define BRD_GET_CSS       v_pioV4_get(BRD_PIO_BASE_CSS,BRD_PIO_MASK_CSS)
//------------------------------------------------------------------------------

#define BRD_PIOA_OUTPUT_MASK  (PIO_PA21B_PCK2)
#define BRD_PIOB_OUTPUT_MASK  (PIO_PB13C_PCK1)
#define BRD_PIOC_OUTPUT_MASK  (0) // none
#define BRD_PIOD_OUTPUT_MASK  (BRD_LED1_MASK|BRD_LED2_MASK|PIO_PD31E_PCK0)
#define BRD_PIOE_OUTPUT_MASK  (0) // none

#define BRD_PIOA_INPUT_MASK    	(0) // none
#define BRD_PIOB_INPUT_MASK    	(0) // none
#define BRD_PIOC_INPUT_MASK    	(0) // none
#define BRD_PIOD_INPUT_MASK    	(BRD_BP3_MASK|BRD_BP4_MASK)


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// SAMA5D2 ////////////////////////////////////////////////////
#if (SAMA5D2==1)
// ---- UART0 on J87/J88 -------------------------------
  #define BRD_BASE_PIO_UART0  PIOB
  #define BRD_ID_PIO_UART0    ID_PIOB
  #define BRD_UART0_RXD	      PIO_PB26C_URXD0
  #define BRD_UART0_TXD	      PIO_PB27C_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_C

// ---- USART3 -------------------------------
  #define BRD_BASE_PIO_USART3           PIOA
  #define BRD_ID_PIO_USART3             ID_PIOA
  #define BRD_USART3_RXD	        PIO_PA13E_FLEXCOM3_IO1
  #define BRD_USART3_TXD	        PIO_PA15E_FLEXCOM3_IO0
  #define BRD_PERIPH_USART3             PIO_PERIPH_E



// ---- USART3 on J91/J92/J93/J94 ----------------------------------
  #define BRD_BASE_PIO_USART3  PIOA
  #define BRD_ID_PIO_USART3    ID_PIOA
  #define BRD_USART3_RXD       PIO_PA13E_FLEXCOM3_IO1
  #define BRD_USART3_TXD       PIO_PA15E_FLEXCOM3_IO0
  #define BRD_USART3_RTS3      PIO_PA17E_FLEXCOM3_IO4
  #define BRD_USART3_CTS3      PIO_PA16E_FLEXCOM3_IO3
  #define BRD_PERIPH_USART3    PIO_PERIPH_E
// ---- SPI1 -------------------------------------------------------
  #define BRD_PERIPH_SPI1      PIO_PERIPH_D
/*
  #define HWSPI_MISO_PIO_PERIPH  PIO_PERIPH_D //MISO
  #define HWSPI_MOSI_PIO_PERIPH  PIO_PERIPH_D //MOSI
  #define HWSPI_SPCK_PIO_PERIPH  PIO_PERIPH_D //SPCK
  #define HWSPI_CSS_PIO_PERIPH   PIO_PERIPH_D //CSS
*/
/////////////////////////////////////////////////////////////
//#elif (SAMA5D2_yy==1)
#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////

#endif // _SAMA5D2_VB_BGA289_H
