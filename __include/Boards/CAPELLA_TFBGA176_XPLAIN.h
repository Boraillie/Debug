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
#ifndef _CAPELLA_XPLAIN_H
#define _CAPELLA_XPLAIN_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : CAPELLA
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO CAPELLA done |
____________________________________________
| USART1    EDBG |  PC25=RXD1 / PC26=TXD1  |   
| Gr LED (D1)    |  PC17 (1 => LED on)    |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


#define BRD_HAS_SDRAM    (1) //any external SDRAM (SD, DDR...)
#define BRD_HAS_ETHERNET (1) //

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
#define BRD_LED_PIO_LETTER    C
#define BRD_LED1_PIO_LETTER   BRD_LED_PIO_LETTER
#define BRD_LED2_PIO_LETTER   BRD_LED_PIO_LETTER

#define BRD_LED1_MASK      (1<<17)  // PB23 LED1
#define BRD_LED2_MASK      (1<<17)  // PB24 LED2

#define BRD_PIOA_OUTPUT_MASK  (0) // none
#define BRD_PIOB_OUTPUT_MASK  (0)
#define BRD_PIOC_OUTPUT_MASK  (BRD_LED1_MASK|BRD_LED2_MASK)
#define BRD_PIOD_OUTPUT_MASK  (0) // none
#define BRD_PIOE_OUTPUT_MASK  (0) // none

#define BRD_LED1_POLARITY (1) // (0 => LED On)
#define BRD_LED2_POLARITY (1) // (0 => LED On)
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
#define BRD_BP_PIO_LETTER    C   
#define BRD_BP3_PIO_LETTER   BRD_BP_PIO_LETTER
#define BRD_BP4_PIO_LETTER   BRD_BP_PIO_LETTER


#define BRD_BP3_MASK         (0x1u<<14)  // SW1
#define BRD_BP4_MASK         (0x1u<<14)  // SW1


#define BRD_PIOA_INPUT_MASK    	(0) // none
#define BRD_PIOB_INPUT_MASK    	(0)
#define BRD_PIOC_INPUT_MASK    	(BRD_BP3_MASK|BRD_BP4_MASK) // none
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
#define BRD_MAIN_XTAL_FREQ    		(12000000)   //
//#define BRD_MAIN_OSC_FREQ    		 (3000000)   //
/*----------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_USART7 (27) // UART0 on J15
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
#define BRD_PIO_BASE_WKUP_STOP  BRD_BP3_BASE_PIO
#define BRD_PIO_BASE_SPCK       PIOD
#define BRD_PIO_BASE_MOSI       PIOD
#define BRD_PIO_BASE_CSS        PIOB
#define BRD_PIO_ID_WKUP_STOP    BRD_BP3_ID_PIO
#define BRD_PIO_ID_SPCK         ID_PIOD
#define BRD_PIO_ID_MOSI         ID_PIOD
#define BRD_PIO_ID_CSS          ID_PIOB
#define BRD_PIO_MASK_WKUP_STOP  BRD_BP3_MASK   //BP3 user switch???
#define BRD_PIO_MASK_SPCK  (1<<22) //PD22???
#define BRD_PIO_MASK_MOSI  (1<<21) //PD21???
#define BRD_PIO_MASK_CSS   (1<<2)  //PB02???
#define BRD_GET_WKUP_STOP v_pioV4_get(BRD_PIO_BASE_WKUP_STOP,BRD_PIO_MASK_WKUP_STOP)
#define BRD_GET_SPCK      v_pioV4_get(BRD_PIO_BASE_SPCK,PIO_INPUT,BRD_SPCK_MASK)
#define BRD_GET_MOSI      v_pioV4_get(BRD_PIO_BASE_MOSI,PIO_INPUT,BRD_MOSI_MASK)
#define BRD_GET_CSS       v_pioV4_get(BRD_PIO_BASE_CSS,PIO_INPUT,BRD_CSS_MASK)
//------------------------------------------------------------------------------






/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// CAPELLA //////////////////////////////////////////////////

//USART7
#define BRD_BASE_PIO_USART7  PIOC
#define BRD_ID_PIO_USART0    ID_PIOC
#define BRD_USART7_RXD	     PIO_PC25C_FLEXCOM7_IO1  
#define BRD_USART7_TXD	     PIO_PC26C_FLEXCOM7_IO0 
#define BRD_PERIPH_USART7    PIO_PERIPH_C

///////////////////////////////////////////////////////////////////////////////
// SDRAM Definitions    ///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//\TODO  Remove settings from here
//SDRAM config : AS4C16M16SA-6BIN 166 MHz
//tCK3 Clock Cycle time (min.) 6/7 ns
//tAC3 Access time from CLK (max.) 5/5.4 ns
//tRAS Row Active time (min.) 42/42 ns
//tRC Row Cycle time (min.) 60/63 ns

#define SDRAM_CFG SDRAMC_CR_NC_COL8      /* 8 column bits */\
		| SDRAMC_CR_NR_ROW12      /* 12 row bits (4K)*/\
		| SDRAMC_CR_CAS_LATENCY3\ /* CAS Latency */\
		| SDRAMC_CR_NB_BANK4\     /* banks*/\
		| SDRAMC_CR_DBW\          /* 16 bits*/\
		| SDRAMC_CR_TWR(5)\       /* Write Recovery Delay*/\
		| SDRAMC_CR_TRC_TRFC(13)\ /* 63ns   min*/\
		| SDRAMC_CR_TRP(5)\       /* Command period (PRE to ACT) 21 ns min*/\
		| SDRAMC_CR_TRCD(5)\    /* Active Command to read/Write Command delay time 21ns min*/\
		| SDRAMC_CR_TRAS(9)\      /* Command period (ACT to PRE)  42ns min*/\
		| SDRAMC_CR_TXSR(15U)   /* Exit self-refresh to active time  70ns Min*/
///////////////////////////////////////////////////////////////////////////////
// SoftPack definitions ///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define BOARD_NAME "samu70-xplained"
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
#define CONFIG_HAVE_SDRAM_W981216BH    (1) // SDRAM 32MB
#define BOARD_DDRAM_TYPE         W981216BH
#define BOARD_DDR_MEMORY_SIZE    (32*1024*1024)
/* D0-D15, A2-A11, SDA10, A13, SDCK, SDCKE, SDWE, SDCS0, CAS, RAS, BA0/1, NBS0/1 */
#define BOARD_DDRAM_PINS PINS_EBI_SDRAM_IOS1 


//#define CONFIG_HAVE_SDRAM_AS4C16M16SA  (1)// SDRAM 32MB
//CONFIG_HAVE_SDRAM_AS4C16M16SA // SDRAM 32MB
//CONFIG_HAVE_SDRAM_IS42S16100E // SDRAM 2MB
//CONFIG_HAVE_SDRAM_W981216BH   // SDRAM 2MB

//#define BOARD_ETH0_PHY_RESET   { PIO_GROUP_C, PIO_PC24, PIO_OUTPUT_1, PIO_PULLUP }

// =================== ETH0 definitions ===================
#define BOARD_ETH0_PHY_TYPE    ETH_PHY_TYPE_RMII
#define BOARD_ETH0_MAC_ADDR    {0x3a, 0x1f, 0x34, 0x08, 0x27, 0x27}
#define BOARD_ETH0_PINS        PINS_GMAC_RMII_IOS1
//#define BOARD_ETH0_PINS        PINS_GMAC_MII_VB
#define BOARD_ETH0_TYPE        ETH_TYPE_GMAC
#define BOARD_ETH0_ADDR        GMAC0
#define BOARD_ETH0_PHY_ADDR    0
#define BOARD_ETH0_PHY_IF      PHY_IF_GMAC
#define BOARD_ETH0_PHY_RETRIES PHY_DEFAULT_RETRIES

#if (MAC_PHY_ACCESS_MODE == MII_MODE)
  #error MAC-PHY interface undefined or unsupported on this HW: check project.h!
#endif
///////////////////////////////////////////////////////////////////////////////






#endif // _CAPELLA_XPLAIN_H
