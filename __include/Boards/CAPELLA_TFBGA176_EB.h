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
#ifndef _CAPELLA_TFBGA176_EB_H
#define _CAPELLA_TFBGA176_EB_H

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

============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"



/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (0)
#define BRD_PIOB_HAS_IO (1)
#define BRD_PIOC_HAS_IO (1)
#define BRD_PIOD_HAS_IO (0)
#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* -------- Leds Definition   for pioV4 from sama5d2 done for CAPELLA         */
/*----------------------------------------------------------------------------*/
#define BRD_LED_PIO_LETTER    B
#define BRD_LED1_PIO_LETTER   BRD_LED_PIO_LETTER
#define BRD_LED2_PIO_LETTER   BRD_LED_PIO_LETTER

#define BRD_LED1_MASK      (1<<24)  // PB23 LED1
#define BRD_LED2_MASK      (1<<23)  // PB24 LED2

#define BRD_PIOA_OUTPUT_MASK  (0) // none
#define BRD_PIOB_OUTPUT_MASK  (BRD_LED1_MASK|BRD_LED2_MASK)
#define BRD_PIOC_OUTPUT_MASK  (0) // none
#define BRD_PIOD_OUTPUT_MASK  (0) // none
#define BRD_PIOE_OUTPUT_MASK  (0) // none

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
#define BRD_BP_PIO_LETTER    B   // was C updated MNn 12/10/16
#define BRD_BP3_PIO_LETTER   BRD_BP_PIO_LETTER
#define BRD_BP4_PIO_LETTER   BRD_BP_PIO_LETTER

#define BRD_BP3_MASK         (0x1u<<25)  // "LEFT CLICK" was 0x1u<<6) updated MNn 12/10/16
#define BRD_BP4_MASK         (0x1u<<26)  // "RIGHT CLICK" was (0x1u<<7) updated MNn 12/10/16

#define BRD_PIOA_INPUT_MASK    	(0) // none
#define BRD_PIOB_INPUT_MASK    	(BRD_BP3_MASK|BRD_BP4_MASK) // none
#define BRD_PIOC_INPUT_MASK    	(0) // none
#define BRD_PIOD_INPUT_MASK    	(0)
//-------------------------------------------------------------

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
/* -------- Board Clocks done for CAPELLA                                                     */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // none
#define BRD_SLOW_XTAL    		(1)   // capella Y2(R21, R22) canopus Y3(R48 & R51)
#define BRD_MAIN_XTAL    		(1)   // capella Y1(R20, R23) canopus Y4((R9 & R50)
#define BRD_SLOW_XTAL_FREQ    		(32768)      //
#define BRD_MAIN_XTAL_FREQ    		(24000000)   //
//#define BRD_MAIN_OSC_FREQ    		 (3000000)   //
/*----------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_USART0 (20) // UART0 on J15
//#define BRD_USART5 (25) // USART1 on J16
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// ---- PRG mode definitions ----
//-------------------------------
// PRG mode outputs //////////////////////////////////////////////////////////
#define BRD_PIO_BASE_BUSY_CKOUT  BRD_LED1_BASE_PIO
#define BRD_PIO_BASE_MISO        PIOD
#define BRD_PIO_ID_BUSY_CKOUT    BRD_LED1_ID_PIO
#define BRD_PIO_ID_MISO          ID_PIOD
#define BRD_PIO_MASK_BUSY_CKOUT  BRD_LED1_MASK  //LED1???
#define BRD_PIO_MASK_MISO        (1<<20) //PD20???
//----------------------------------------------------
#define BRD_SET_BUSY_CKOUT    v_pioV4_set(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_SET_MISO          v_pioV4_set(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_CLR_BUSY_CKOUT    v_pioV4_clear(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_CLR_MISO          v_pioV4_clear(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_TOGGLE_BUSY_CKOUT v_pioV4_toggle(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_TOGGLE_MISO       v_pioV4_toggle(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)

// PRG mode inputs ///////////////////////////////////////////////////////////
#define BRD_PIO_BASE_WKUP_STOP   BRD_BP3_BASE_PIO
#define BRD_PIO_BASE_SPCK        PIOD
#define BRD_PIO_BASE_MOSI        PIOD
#define BRD_PIO_BASE_CSS         PIOB
#define BRD_PIO_ID_WKUP_STOP  BRD_BP3_ID_PIO
#define BRD_PIO_ID_SPCK       ID_PIOD
#define BRD_PIO_ID_MOSI       ID_PIOD
#define BRD_PIO_ID_CSS        ID_PIOB
#define BRD_PIO_MASK_WKUP  BRD_BP3_MASK   //BP3 user switch???
#define BRD_PIO_MASK_SPCK  (1<<22) //PD22???
#define BRD_PIO_MASK_MOSI  (1<<21) //PD21???
#define BRD_PIO_MASK_CSS   (1<<2)  //PB02???
#define BRD_GET_WKUP_STOP pio_get(BRD_PIO_BASE_WKUP_STOP,PIO_INPUT,BRD_WKUP_STOP_MASK)
#define BRD_GET_SPCK      pio_get(BRD_PIO_BASE_SPCK,PIO_INPUT,BRD_SPCK_MASK)
#define BRD_GET_MOSI      pio_get(BRD_PIO_BASE_MOSI,PIO_INPUT,BRD_MOSI_MASK)
#define BRD_GET_CSS       pio_get(BRD_PIO_BASE_CSS,PIO_INPUT,BRD_CSS_MASK)
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






#endif /* _CAPELLA_XPLAIN_H */
