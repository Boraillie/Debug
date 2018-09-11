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
#ifndef _SAMA5D2_BIB_H
#define _SAMA5D2_BIB_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAMA5D2
*
*
*----------------------------------------------------------------------------
-------------------------------------------------
|    Board             |        PIO             |
_________________________________________________
=================================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
#define BRD_PIOA_HAS_IO (0) // IO group 0
#define BRD_PIOB_HAS_IO (0) // IO group 1
#define BRD_PIOC_HAS_IO (0) // IO group 2
#define BRD_PIOD_HAS_IO (1) // IO group 3
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Outputs Definition (user LEDS)                                    */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_OUTPUT  PIOD //PIO->PIO_IO_GROUP[3] <=> PIOD

#define BRD_DS_MASK      (1<<21) // PD21

#define BRD_DS_POLARITY  (0)    // (0 => LED On)

#define BRD_PIOA_OUTPUT_MASK  (0) // none
#define BRD_PIOB_OUTPUT_MASK  (0) // none
#define BRD_PIOC_OUTPUT_MASK  (0) // none
#define BRD_PIOD_OUTPUT_MASK  (BRD_DS_MASK)

#define BRD_TURN_ON_DS   v_pioV4_clear(BRD_BASE_PIO_OUTPUT,BRD_DS_MASK)
#define BRD_TURN_OFF_DS  v_pioV4_set(BRD_BASE_PIO_OUTPUT,BRD_DS_MASK)
#define BRD_TOGGLE_DS    v_pioV4_toggle(BRD_BASE_PIO_OUTPUT,BRD_DS_MASK)

#define BRD_PIO_HAS_OUTPUTS ( BRD_PIOA_OUTPUT_MASK |BRD_PIOB_OUTPUT_MASK \
                            | BRD_PIOC_OUTPUT_MASK |BRD_PIOD_OUTPUT_MASK )
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition (user buttons)                                  */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_INPUT   PIOD //PIO->PIO_IO_GROUP[3] <=> PIOD
#define BRD_S5_BASE_PIO      BRD_BASE_PIO_INPUT
#define BRD_S6_BASE_PIO      BRD_BASE_PIO_INPUT
#define BRD_ID_PIO_INPUT     ID_PIOD
#define BRD_S5_ID_PIO        BRD_ID_PIO_INPUT
#define BRD_S6_ID_PIO        BRD_ID_PIO_INPUT

#define BRD_S5_MASK       (1<<23)  //PD23
#define BRD_S6_MASK       (1<<24)  //PD24

#define BRD_PIOA_INPUT_MASK    (0) // none
#define BRD_PIOB_INPUT_MASK    (0) // none
#define BRD_PIOC_INPUT_MASK    (0) // none
#define BRD_PIOD_INPUT_MASK    (BRD_S5_MASK | BRD_S6_MASK)

#define BRD_GET_S5 v_pioV4_get(BRD_S5_BASE_PIO,BRD_S5_MASK)
#define BRD_GET_S6 v_pioV4_get(BRD_S6_BASE_PIO,BRD_S6_MASK)

#define BRD_PIO_HAS_INPUTS ( BRD_PIOA_INPUT_MASK |BRD_PIOB_INPUT_MASK \
                           | BRD_PIOC_INPUT_MASK |BRD_PIOD_INPUT_MASK )
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     		(0)   //none
#define BRD_MAIN_OSC     		(0)   //default=DNP
#define BRD_SLOW_XTAL    		(0)   //default=DNP  
#define BRD_MAIN_XTAL    		(0)   //default=DNP
#define BRD_MAIN_OSC_FREQ     		(3000000)    //default=DNP
#define BRD_SLOW_XTAL_FREQ    		(32768)      //default=DNP  
#define BRD_MAIN_XTAL_FREQ    		(12000000)   //default=DNP
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board available serial links                                      */
/*----------------------------------------------------------------------------*/
#define BRD_UART0   (0x10) // UART0 on J3 connector (extension board mandatory)
// UART0 = (0x10)
// UART1 = (0x11)
// ...
#define BRD_USART3  (0x23)  // USART3 (J13) - BIB prototypes only
// USART1 = (0x21)
// USART2 = (0x22)
// ...



/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// SAMA5D2 ////////////////////////////////////////////////////
#if (SAMA5D2==1)
// ---- UART1 on J3 (site1) -------------------------------
  #define BRD_BASE_PIO_UART1  PIOD
  #define BRD_ID_PIO_UART1    ID_PIOD
  #define BRD_UART1_RXD	      PIO_PD2A_URXD1
  #define BRD_UART1_TXD	      PIO_PD3A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
#else
  #error board.h file does not support the specified device.
#endif
/////////////////////////////////////////////////////////////


#endif // _SAMA5D2_BIB_H
