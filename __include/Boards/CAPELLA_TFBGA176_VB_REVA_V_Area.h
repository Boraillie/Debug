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
#ifndef _CAPELLA_VB_V_H
#define _CAPELLA_VB_V_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : CANOPUS
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO CAPELLA done |
____________________________________________
| UART1 (J15)    |  PB3=URXD1 / PB2=UTXD1  |
| USART5 (J16)   |  PA11=RXD5 / PA10=TXD5  |
|                |  PA14=RTS5 / PA13=CTS5  |
| Gr LED (D2)    |  PB23 (1 => LED off)    |
| Gr LED (D3)    |  PB24 (1 => LED off)    |
| Power LED (D4) |  VDDMAIN                |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


//#define BRD_HAS_SDRAM    (1) //any external SDRAM (SD, DDR...)
//#define BRD_HAS_ETHERNET (1) //


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

#define BRD_LED1_MASK      (1<<23)  // PB23 LED1
#define BRD_LED2_MASK      (1<<24)  // PB24 LED2

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
//#define BRD_BP_PIO_LETTER    C   //ERr last update //was C updated MNn 12/10/16
#define BRD_BP1_PIO_LETTER   B//BRD_BP_PIO_LETTER
#define BRD_BP3_PIO_LETTER   C//BRD_BP_PIO_LETTER
#define BRD_BP4_PIO_LETTER   C//BRD_BP_PIO_LETTER

#define BRD_BP1_MASK         (0x1u<<4) //ERr last update
#define BRD_BP3_MASK         (0x1u<<6) //ERr last update //"LEFT CLICK" was 0x1u<<6) updated MNn 12/10/16
#define BRD_BP4_MASK         (0x1u<<7) //ERr last update //"RIGHT CLICK" was (0x1u<<7) updated MNn 12/10/16

#define BRD_PIOA_INPUT_MASK    	(0) // none
#define BRD_PIOB_INPUT_MASK    	(BRD_BP1_MASK)
#define BRD_PIOC_INPUT_MASK    	(BRD_BP3_MASK|BRD_BP4_MASK)
#define BRD_PIOD_INPUT_MASK    	(0)
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


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks done for CAPELLA                                                     */
/*----------------------------------------------------------------------------*/
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
#define BRD_USART0 (20) // UART0 on J15
//#define BRD_USART5 (25) // USART1 on J16
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// ---- PRG mode definitions ----
//-------------------------------
// SPI link: FLEXCOM9 connected on EXT3 connector J19
// PRG mode outputs //////////////////////////////////////////////////////////
#define BRD_PIO_BASE_BUSY_CKOUT  BRD_LED1_BASE_PIO
#define BRD_PIO_BASE_MISO        PIOC
#define BRD_PIO_ID_BUSY_CKOUT    BRD_LED1_ID_PIO
#define BRD_PIO_ID_MISO          ID_PIOC
#define BRD_PIO_MASK_BUSY_CKOUT  BRD_LED1_MASK  //LED1???
#define BRD_PIO_MASK_MISO        (1<<20) //
//----------------------------------------------------
#define BRD_SET_BUSY_CKOUT    v_pioV4_set(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_SET_MISO          v_pioV4_set(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_CLR_BUSY_CKOUT    v_pioV4_clear(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_CLR_MISO          v_pioV4_clear(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)
#define BRD_TOGGLE_BUSY_CKOUT v_pioV4_toggle(BRD_PIO_BASE_BUSY_CKOUT,BRD_PIO_MASK_BUSY_CKOUT)
#define BRD_TOGGLE_MISO       v_pioV4_toggle(BRD_PIO_BASE_MISO,BRD_PIO_MASK_MISO)

// PRG mode inputs ///////////////////////////////////////////////////////////
#define BRD_PIO_BASE_WKUP_STOP   BRD_BP1_BASE_PIO
#define BRD_PIO_BASE_SPCK        PIOC
#define BRD_PIO_BASE_MOSI        PIOC
#define BRD_PIO_BASE_CSS         PIOC
#define BRD_PIO_ID_WKUP_STOP  BRD_BP1_ID_PIO
#define BRD_PIO_ID_SPCK       ID_PIOC
#define BRD_PIO_ID_MOSI       ID_PIOC
#define BRD_PIO_ID_CSS        ID_PIOC
#define BRD_PIO_MASK_WKUP_STOP  BRD_BP1_MASK   //BP3 user switch???
#define BRD_PIO_MASK_SPCK  (1<<21) //
#define BRD_PIO_MASK_MOSI  (1<<19) //
#define BRD_PIO_MASK_CSS   (1<<22) //
#define BRD_GET_WKUP_STOP v_pioV4_get(BRD_PIO_BASE_WKUP_STOP,BRD_PIO_MASK_WKUP_STOP)
#define BRD_GET_SPCK      v_pioV4_get(BRD_PIO_BASE_SPCK,BRD_PIO_MASK_SPCK)
#define BRD_GET_MOSI      v_pioV4_get(BRD_PIO_BASE_MOSI,BRD_PIO_MASK_MOSI)
#define BRD_GET_CSS       v_pioV4_get(BRD_PIO_BASE_CSS,BRD_PIO_MASK_CSS)
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

// ---- SPI9 (FLEXCOM9) --------------------------------------
#define BRD_PERIPH_SPI9      PIO_PERIPH_B
//#define HWSPI_MISO_PIO_PERIPH  PIO_PERIPH_B //MISO
//#define HWSPI_MOSI_PIO_PERIPH  PIO_PERIPH_B //MOSI
//#define HWSPI_SPCK_PIO_PERIPH  PIO_PERIPH_B //SPCK
//#define HWSPI_CSS_PIO_PERIPH   PIO_PERIPH_B //CSS


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
#define BOARD_NAME "capella-vb-tfbga176"
#define BOARD_MAIN_CLOCK_EXT_OSC 12000000
#define BOARD_TIMER_TC      TC1
#define BOARD_TIMER_CHANNEL 0

#define BOARD_PMC_PLLA_MUL (PLLA_MUL)
#define BOARD_PMC_PLLA_DIV (PLLA_DIV)

#define CONFIG_CHIP_SAMU70S20 1
#define CONFIG_BOARD_SAMU70_VB_LQFP176 1
//#define CONFIG_SERIALD_USART 1
#define CONFIG_HAVE_SERIALD_USART 1
#define CONFIG_HAVE_LED 1

// =================== SDRAM definitions ===================
#define CONFIG_HAVE_MPDDRC_SDRAM       (1) //mandatory to compile SoftPack
#define CONFIG_HAVE_SDRAM_AS4C16M16SA  (1)// SDRAM 32MB
//CONFIG_HAVE_SDRAM_AS4C16M16SA // SDRAM 32MB
//CONFIG_HAVE_SDRAM_IS42S16100E // SDRAM 2MB
//CONFIG_HAVE_SDRAM_W981216BH   // SDRAM 2MB

#define PINS_GMAC_MII_VB {\
	{ PIO_GROUP_A, 0x27F80000, PIO_PERIPH_E, PIO_DEFAULT },\
	{ PIO_GROUP_B, PIO_PB5F_GTXCK, PIO_PERIPH_F, PIO_DEFAULT },\
	{ PIO_GROUP_D, 0x0000000F, PIO_PERIPH_B, PIO_DEFAULT },\
	{ PIO_GROUP_C, 0xF0000000, PIO_PERIPH_B, PIO_DEFAULT },\
}
//#define BOARD_ETH0_PHY_RESET   { PIO_GROUP_C, PIO_PC24, PIO_OUTPUT_1, PIO_PULLUP }

// =================== ETH0 definitions ===================
#define BOARD_ETH0_MAC_ADDR    {0x3a, 0x1f, 0x34, 0x08, 0x27, 0x27}
//#define BOARD_ETH0_PINS        PINS_GMAC_RMII_IOS1
//#define BOARD_ETH0_PINS        PINS_GMAC_MII_VB
#define BOARD_ETH0_TYPE        ETH_TYPE_GMAC
#define BOARD_ETH0_ADDR        GMAC0
#define BOARD_ETH0_PHY_ADDR    0 
#define BOARD_ETH0_PHY_IF      PHY_IF_GMAC
#define BOARD_ETH0_PHY_RETRIES PHY_DEFAULT_RETRIES
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// Extension boards definitions ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifdef EXT_MII_RMII_SOD200_REVA
  #if (MAC_PHY_ACCESS_MODE==MII_MODE)
    #define BOARD_ETH0_PINS  PINS_GMAC_MII_VB    //softpack style defintion
    #define PHY_REFERENCE PHY_KSZ8081MNX
  #elif (MAC_PHY_ACCESS_MODE==RMII25MHZ_MODE || MAC_PHY_ACCESS_MODE==RMII50MHZ_MODE)
    #define BOARD_ETH0_PINS  PINS_GMAC_RMII_IOS1 //softpack style defintion
    #define PHY_REFERENCE PHY_KSZ8081RNB
  #else
    #error Undefined MAC-PHY communication mode: check project.h
  #endif
//softpack style defintion
#endif
///////////////////////////////////////////////////////////////////////////////


#endif /* _CAPELLA_VB_V_H */
