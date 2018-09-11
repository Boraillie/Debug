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
#ifndef _CAPELLA_BIB_TFBGA100_H
#define _CAPELLA_BIB_TFBGA100_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : CAPELLA
*
*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO              |
____________________________________________
| UART1 (J15)    |  PB3=URXD1 / PB2=UTXD1  |   
| USART5 (J16)   |  PA11=RXD5 / PA10=TXD5  |   
| 		 |  PA14=RTS5 / PA13=CTS5  |   
| 		 |                         |   
| Gr LED (D2)    |  PB23 (1 => LED off)    |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
/*#define BRD_PIOA_HAS_IO (1)
#define BRD_PIOB_HAS_IO (0)
#define BRD_PIOC_HAS_IO (0)
#define BRD_PIOD_HAS_IO (0)
#define BRD_PIOE_HAS_IO (1)*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (0)
#define BRD_PIOB_HAS_IO (1)
#define BRD_PIOC_HAS_IO (0)
#define BRD_PIOD_HAS_IO (0)
#define BRD_PIOE_HAS_IO (0)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
/*#define BRD_BASE_PIO_OUTPUT  PIOE
#define BRD_ID_PIO_OUTPUT    ID_PIOE

#define BRD_DS_MASK      (1<<4)  	// PE4 DS

#define BRD_DS_POLARITY  (0) // (0 => LED On)

#define BRD_PIOA_OUTPUT_MASK  (0)
#define BRD_PIOB_OUTPUT_MASK  (0) 
#define BRD_PIOC_OUTPUT_MASK  (0) // none
#define BRD_PIOD_OUTPUT_MASK  (0) // none
#define BRD_PIOE_OUTPUT_MASK  (BRD_DS_MASK)

#define BRD_TURN_ON_DS   pio_clear(BRD_BASE_PIO_OUTPUT,BRD_DS_MASK)
#define BRD_TURN_OFF_DS  pio_set(BRD_BASE_PIO_OUTPUT,BRD_DS_MASK)
#define BRD_TOGGLE_DS    pio_toggle(BRD_BASE_PIO_OUTPUT,BRD_DS_MASK)*/

#define BRD_LED_PIO_LETTER    B
#define BRD_LED1_PIO_LETTER   BRD_LED_PIO_LETTER
//#define BRD_LED2_PIO_LETTER   BRD_LED_PIO_LETTER

#define BRD_LED1_MASK      (1<<23)  // PB23 LED1
//#define BRD_LED2_MASK      (1<<24)  // PB24 LED2

#define BRD_PIOA_OUTPUT_MASK  (0) // none
#define BRD_PIOB_OUTPUT_MASK  (BRD_LED1_MASK|BRD_LED2_MASK)
#define BRD_PIOC_OUTPUT_MASK  (0) // none
#define BRD_PIOD_OUTPUT_MASK  (0) // none
#define BRD_PIOE_OUTPUT_MASK  (0) // none

#define BRD_LED1_POLARITY (0) // (0 => LED On)
//#define BRD_LED2_POLARITY (0) // (0 => LED On)

#define BRD_LED1_BASE_PIO     MERGE(PI,O,BRD_LED1_PIO_LETTER, )
/*#define BRD_LED2_BASE_PIO     MERGE(PI,O,BRD_LED2_PIO_LETTER, )*/
#define BRD_LED1_ID_PIO       MERGE(ID_,PI,O,BRD_LED1_PIO_LETTER)
/*#define BRD_LED2_ID_PIO       MERGE(ID_,PI,O,BRD_LED2_PIO_LETTER)*/
#ifdef BRD_LED_PIO_LETTER
  #define BRD_LED_BASE_PIO     MERGE(PI,O,BRD_LED_PIO_LETTER, )
  #define BRD_LED_ID_PIO       MERGE(ID_,PI,O,BRD_LED_PIO_LETTER)
#endif

#define BRD_TURN_ON_LED1   v_pioV4_clear (BRD_LED1_BASE_PIO,BRD_LED1_MASK)
#define BRD_TURN_OFF_LED1  v_pioV4_set   (BRD_LED1_BASE_PIO,BRD_LED1_MASK)
#define BRD_TOGGLE_LED1    v_pioV4_toggle(BRD_LED1_BASE_PIO,BRD_LED1_MASK)
/*#define BRD_TURN_ON_LED2   v_pioV4_clear (BRD_LED2_BASE_PIO,BRD_LED2_MASK)
#define BRD_TURN_OFF_LED2  v_pioV4_set   (BRD_LED2_BASE_PIO,BRD_LED2_MASK)
#define BRD_TOGGLE_LED2    v_pioV4_toggle(BRD_LED2_BASE_PIO,BRD_LED2_MASK)
*/

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition ( user bottons)                                 */
/*----------------------------------------------------------------------------*/
/*#define BRD_BASE_PIO_S5   PIOA
#define BRD_BASE_PIO_S6   PIOA

#define BRD_ID_PIO_S5     ID_PIOA
#define BRD_ID_PIO_S6     ID_PIOA

#define BRD_S5_MASK       (1<<2)   //PA2
#define BRD_S6_MASK       (1<<16)  //PA16


#define BRD_PIOA_INPUT_MASK    (BRD_S5_MASK | BRD_S6_MASK)
#define BRD_PIOB_INPUT_MASK    (0) // none
#define BRD_PIOC_INPUT_MASK    (0) // none
#define BRD_PIOD_INPUT_MASK    (0) // none
#define BRD_PIOE_INPUT_MASK    (0) // none

#define BRD_GET_S5 pio_get(BRD_BASE_PIO_S5,PIO_INPUT,BRD_S5_MASK)
#define BRD_GET_S6 pio_get(BRD_BASE_PIO_S6,PIO_INPUT,BRD_S6_MASK)*/

#define BRD_BP_PIO_LETTER    B
#define BRD_BP3_PIO_LETTER   BRD_BP_PIO_LETTER
#define BRD_BP4_PIO_LETTER   BRD_BP_PIO_LETTER

#define BRD_BP3_MASK         (0x1u<<25)  // PB25  LEFT CLICK 
#define BRD_BP4_MASK         (0x1u<<26)  // PB26  RIGHT CLICK

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
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
/*#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // default = DNP  / Y1
#define BRD_SLOW_XTAL    		(0)   // default = DNP  / Yx00
#define BRD_MAIN_XTAL    		(0)   // default = DNP  / Yx01
#define BRD_SLOW_XTAL_FREQ          (32768)   //
#define BRD_MAIN_XTAL_FREQ       (12000000)   //
#define BRD_MAIN_OSC_FREQ         (3000000)   //*/

#define BRD_SLOW_OSC     		(0)   // none
#define BRD_MAIN_OSC     		(0)   // none
#define BRD_SLOW_XTAL    		(1)   // capella Y2(R21, R22) canopus Y3(R48 & R51)
#define BRD_MAIN_XTAL    		(1)   // capella Y1(R20, R23) canopus Y4((R9 & R50)
#define BRD_SLOW_XTAL_FREQ    		(32768)      //
#define BRD_MAIN_XTAL_FREQ    		(12000000)   //
//#define BRD_MAIN_OSC_FREQ    		 (3000000)   //

/*----------------------------------------------------------------------------*/



//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
/*#define BRD_UART0 (10) // UART0 on J3 connector (extension board mandatory)*/
#define BRD_UART1 (11) // UART1 on J15
#define BRD_USART5 (25) // USART5 on J16
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/

// CANOPUS ////////////////////////////////////////////////////
/*#define BRD_BASE_PIO_UART0  	PIOA
#define BRD_ID_PIO_UART0    	ID_PIOA
#define BRD_UART0_RXD	     	PIO_PA9A_URXD0  
#define BRD_UART0_TXD	     	PIO_PA10A_UTXD0 
#define BRD_PERIPH_UART0    	PIO_PERIPH_A */
/////////////////////////////////////////////////////////////

// CAPELLA ////////////////////////////////////////////////////
// ---- UART1 on J15 -------------------------------
  #define BRD_BASE_PIO_UART1  PIOB
  #define BRD_ID_PIO_UART1    ID_PIOB
  #define BRD_UART1_RXD	      PIO_PB3C_FLEXCOM1_IO1
  #define BRD_UART1_TXD	      PIO_PB2C_FLEXCOM1_IO0
  #define BRD_PERIPH_UART1    PIO_PERIPH_C
// ---- USART5 on J16 ----------------------------------
  #define BRD_BASE_PIO_USART5  PIOA
  #define BRD_ID_PIO_USART5    ID_PIOA
  #define BRD_USART5_RXD       PIO_PA11A_FLEXCOM5_IO1
  #define BRD_USART5_TXD       PIO_PA10A_FLEXCOM5_IO0
  #define BRD_USART5_RTS       PIO_PA14A_FLEXCOM5_IO4
  #define BRD_USART5_CTS       PIO_PA13A_FLEXCOM5_IO3
  #define BRD_PERIPH_USART3    PIO_PERIPH_E
/////////////////////////////////////////////////////////////



/*#endif  _CANOPUS_BIB_LQ144_H */
#endif   _CAPELLA_BIB_TFBGA100_H
