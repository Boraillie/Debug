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
* Object              : iSOCK Patch file
*
*----------------------------------------------------------------------------
*/
#ifndef _VALID_PATCH_CAPELLA_H
#define _VALID_PATCH_CAPELLA_H

//------------------------------------------------------------------------------
// ---- Bug reference:  missing can
//------------------------------------------------------------------------------
#define ID_MCAN0_INT0      (36)
#define ID_MCAN0_INT1      (37)
#define ID_MCAN1_INT0      (38)
#define ID_MCAN1_INT1      (39)
#define ID_MCAN2_INT0      (40)
#define ID_MCAN2_INT1      (41)
#define ID_MCAN3_INT0      (42)
#define ID_MCAN3_INT1      (43)

void MCAN0_INT0_Handler(void);
void MCAN0_INT1_Handler(void);
void MCAN1_INT0_Handler(void);
void MCAN1_INT1_Handler(void);
void MCAN2_INT0_Handler(void);
void MCAN2_INT1_Handler(void);
void MCAN3_INT0_Handler(void);
void MCAN4_INT1_Handler(void);

//addresses already declared in product.h file
/*
#define MCAN0    ((Mcan     *)0x40058000U) //
#define MCAN1    ((Mcan     *)0x4005C000U) //
#define MCAN2    ((Mcan     *)0x40060000U) //
#define MCAN3    ((Mcan     *)0x40064000U) //
*/

//------------------------------------------------------------------------------
// ---- Bug reference:  missing product general definitions
//------------------------------------------------------------------------------
//#define IRAM_ADDR     0x20000000
#define IRAM_ADDR     0x1FFE0000 //128KB ITCM area + 256KB DTCM area @0x20000000
#define IRAM_MIN_SIZE 0x00060000 //384KB
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: missing peripherals handler prototypres
//------------------------------------------------------------------------------
void PTC_Handler      ( void );
void I2SC0_Handler      ( void );
void I2SC1_Handler      ( void );
void QSPIS_Handler      ( void );
void GMAC_Q1_Handler    ( void );
void GMAC_Q2_Handler    ( void );
void GMAC_Q3_Handler    ( void );
void GMAC_Q4_Handler    ( void );
void GMAC_Q5_Handler    ( void );
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#define  REG_MATRIX_CCFG_SYSIO      (*(__IO uint32_t*)0x40088114U)
#define  MATRIX_CCFG_SYSIO_SYSIO4   (0x1u << 4)
#define  MATRIX_CCFG_SYSIO_SYSIO5   (0x1u << 5)
#define  MATRIX_CCFG_SYSIO_SYSIO6   (0x1u << 6)
#define  MATRIX_CCFG_SYSIO_SYSIO7   (0x1u << 7)
#define  MATRIX_CCFG_SYSIO_SYSIO12  (0x1u << 12)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
//missing handler 
extern void CAN0_Handler       ( void );
extern void CAN1_Handler       ( void );
extern void MLB_Handler       ( void );
extern void FPU_Handler       ( void );

//------------------------------------------------------------------------------
// ---- Bug reference: 
//        Support iSOC IT handler naming changes (IrqHandler/ Handler)
//------------------------------------------------------------------------------
#define HANDLER_SUFFIX _Handler
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
typedef volatile const uint32_t RoReg; /**< Read only 32-bit register (volatile const unsigned int) */
typedef volatile       uint32_t WoReg; /**< Write only 32-bit register (volatile unsigned int) */
typedef volatile       uint32_t RwReg; /**< Read-Write 32-bit register (volatile unsigned int) */
//------------------------------------------------------------------------------
#define RSTC_CR_PERRST (0x1u << 2) /**< \brief (RSTC_CR) Peripheral Reset */



//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions : PMC
//------------------------------------------------------------------------------
#define PMC_MCKR_H32MXDIV_H32MXDIV2 (0x1u << 24)



//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions : Memory mapping
//------------------------------------------------------------------------------
#define IRAM0_ADDR      (0x20000000u) /**< Internal RAM 0 base address */


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#define WDT_MR_WDRPROC (0x1u << 14) /**< \brief (WDT_MR) Watchdog Reset Processor */
#define  CCFG_SYSIO (*(__IO uint32_t*)0x40088114U)    
//------------------------------------------------------------------------------


/** \brief Uart hardware registers */
typedef struct {
  __O  uint32_t UART_CR;       /**< \brief (Uart Offset: 0x0000) Control Register */
  __IO uint32_t UART_MR;       /**< \brief (Uart Offset: 0x0004) Mode Register */
  __O  uint32_t UART_IER;      /**< \brief (Uart Offset: 0x0008) Interrupt Enable Register */
  __O  uint32_t UART_IDR;      /**< \brief (Uart Offset: 0x000C) Interrupt Disable Register */
  __I  uint32_t UART_IMR;      /**< \brief (Uart Offset: 0x0010) Interrupt Mask Register */
  __I  uint32_t UART_SR;       /**< \brief (Uart Offset: 0x0014) Status Register */
  __I  uint32_t UART_RHR;      /**< \brief (Uart Offset: 0x0018) Receive Holding Register */
  __O  uint32_t UART_THR;      /**< \brief (Uart Offset: 0x001C) Transmit Holding Register */
  __IO uint32_t UART_BRGR;     /**< \brief (Uart Offset: 0x0020) Baud Rate Generator Register */
  __IO uint32_t UART_CMPR;     /**< \brief (Uart Offset: 0x0024) Comparison Register */
  __I  uint32_t Reserved1[47];
  __IO uint32_t UART_WPMR;     /**< \brief (Uart Offset: 0x00E4) Write Protection Mode Register */
} Uart;

#define UART0  ((Uart   *)0x40010000) /**< \brief (UART0/FLEXCOM0) Base Address */                             
#define CHIP_ID_REGISTER   REG_CHIPID_CIDR
#define CHIP_EXID_REGISTER REG_CHIPID_EXID


//------------------------------------------------------------------------------
// ---- Bug reference: iSock modified PIO definitions for backward compatibility
//------------------------------------------------------------------------------
#undef PIOA
#ifndef PIO
 #define PIO ((Pio*)0x40008000U) /**< \brief (PIOA    ) Base Address */
#else
 #error PIO was already defined (iSock changed?)
#endif

/*
#undef ID_PIOA
#ifndef ID_PIO
 #define ID_PIO (18)
#else
 #error ID_PIO was already defined (iSock changed?)
#endif
*/
#define PIOA (PIO->PIO_IO_GROUP    )
#define PIOB (PIO->PIO_IO_GROUP + 1)
#define PIOC (PIO->PIO_IO_GROUP + 2)
#define PIOD (PIO->PIO_IO_GROUP + 3)
#define PIOE (PIO->PIO_IO_GROUP + 4)
/*
#ifndef ID_PIO
 #define ID_PIO (ID_PIOA)
#else
 #error ID_PIO was already defined (iSock changed?)
#endif
*/


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#define SUPC_MR_ONREG (0x1u << 14) /**< \brief (SUPC_MR) Voltage Regulator enable */

//#define PMC_WPMR_WPKEY(value) ((PMC_WPMR_WPKEY_Msk & ((value) << PMC_WPMR_WPKEY_Pos)))
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: Supply monitor threshold values definitions
// TODO : Values cpoied from canopus
//------------------------------------------------------------------------------
#define   SUPC_SMMR_SMTH_1_60V (0x0u << 0)
#define   SUPC_SMMR_SMTH_1_72V (0x1u << 0)
#define   SUPC_SMMR_SMTH_1_84V (0x2u << 0)
#define   SUPC_SMMR_SMTH_1_96V (0x3u << 0)
#define   SUPC_SMMR_SMTH_2_08V (0x4u << 0)
#define   SUPC_SMMR_SMTH_2_20V (0x5u << 0)
#define   SUPC_SMMR_SMTH_2_32V (0x6u << 0)
#define   SUPC_SMMR_SMTH_2_44V (0x7u << 0)
#define   SUPC_SMMR_SMTH_2_56V (0x8u << 0)
#define   SUPC_SMMR_SMTH_2_68V (0x9u << 0)
#define   SUPC_SMMR_SMTH_2_80V (0xAu << 0)
#define   SUPC_SMMR_SMTH_2_92V (0xBu << 0)
#define   SUPC_SMMR_SMTH_3_04V (0xCu << 0)
#define   SUPC_SMMR_SMTH_3_16V (0xDu << 0)
#define   SUPC_SMMR_SMTH_3_28V (0xEu << 0)
#define   SUPC_SMMR_SMTH_3_40V (0xFu << 0)

//------------------------------------------------------------------------------
// ---- Bug reference: missing Flash informations / naming changes
//------------------------------------------------------------------------------


#define IFLASH0_NB_OF_LOCK_BITS 128//todo : value to check 

//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_CAPELLA.h"
/*
 __I  uint32_t REG_SCKC_CR; 
#warning  " MNn :   dummy definition of REG_SCKC_CR for compatibility value unknown"
  #define REG_SCKC_CR    
#warning  " MNn :   dummy definition of SCKC_CR_OSCSEL_RC for compatibility value unknown"
#define SCKC_CR_OSCSEL_RC (0x1u << 0) 
#define SCKC_CR_OSCSEL_XTAL (0x1u << 10)
*/


//Pio.h updated for compatibility seems only exists on SAMA5D2 not CAPELLA
#define   PIO_CFGR_DRVSTR_ME PIO_CFGR_DRVSTR_LO /**< \brief (PIO_CFGR) Medium drive */

/*MNn adding sysc stuff*/
typedef struct {
  __IO uint32_t SYSC_WPMR;     /**< \brief (Supc Offset: 0x04) Supply Controller Supply Monitor Mode Register */
} Sysc;

#define   SYSC_WPMR_KEY_PASSWD (0x525443u << 8) /**< \brief (SUPC_CR) Writing any other value in this field aborts the write operation. */
/* -------- SYSC_WPMR : (SYSC_WPMR Offset: 0x00) Supply Controller Supply Monitor Mode Register -------- */

 #define SYSC_WPMR_WPEN_Pos 0
 #define SYSC_WPMR_WPEN_Msk (0x1 << SYSC_WPMR_WPEN_Pos) /**< \brief (SUPC_SMMR) Supply Monitor Threshold */
 //#define SYSC_WPMR_WPEN(value) ((SYSC_WPMR_WPEN_Msk & ((value) << SYSC_WPMR_WPEN_Pos)))

#define PMC_MCKR_PLLADIV2 (0x1u << 12) /**< \brief (PMC_MCKR) PLLA Divisor by 2 */


/* -------- SUPC_MR : (SUPC Offset: 0x08) Supply Controller Mode Register -------- */

#define SUPC_MR_CORSMRSTEN (0x1u << 12) /**< \brief (SUPC_MR) VDDCORE Supply Monitor Reset Enable */
#define   SUPC_MR_CORSMRSTEN_NOT_ENABLE (0x0u << 12) /**< \brief (SUPC_MR) The core reset signal vddcore_nreset is not affected when a VDDCORE supply monitor detection occurs. */
#define   SUPC_MR_CORSMRSTEN_ENABLE (0x1u << 12) /**< \brief (SUPC_MR) The core reset signal, vddcore_nreset is asserted when a VDDCORE supply monitor detection occurs. */
#define SUPC_MR_CORSMDIS (0x1u << 13) /**< \brief (SUPC_MR) VDDCORE Supply Monitor Disable */
#define   SUPC_MR_CORSMDIS_ENABLE (0x0u << 13) /**< \brief (SUPC_MR) The VDDCORE supply monitor is enabled */
#define   SUPC_MR_CORSMDIS_DISABLE (0x1u << 13) /**< \brief (SUPC_MR) The VDDCORE supply monitor is disabled */
#define SUPC_MR_SXTALSTUP (0x1u << 17) /**< \brief (SUPC_MR) Slow Startup 32.768 kHz Crystal Oscillator : Exclusive to FXTALSTUP bit */
#define   SUPC_MR_SXTALSTUP_13200_RC_PERIODS (0x0u << 17) /**< \brief (SUPC_MR) Oscillator startup time is 13200 slow RC periods. */
#define   SUPC_MR_SXTALSTUP_152800_RC_PERIODS (0x1u << 17) /**< \brief (SUPC_MR) Oscillator startup time is 152800 slow RC periods. */
#define SUPC_MR_FXTALSTUP (0x1u << 22) /**< \brief (SUPC_MR) Fast Startup 32.768 kHz Crystal Oscillator : Exclusive to SXTALSTUP bit */
#define   SUPC_MR_FXTALSTUP_52800_RC_PERIODS (0x0u << 22) /**< \brief (SUPC_MR) Oscillator startup time is 52800 slow RC periods. */
#define   SUPC_MR_FXTALSTUP_13200_RC_PERIODS (0x1u << 22) /**< \brief (SUPC_MR) Oscillator startup time is 13200 slow RC periods. */

// ---------- definitions to remove
//  #define SUPC_MR_BODRSTEN (0x1u << 12) /**< \brief (SUPC_MR) Brownout Detector Reset Enable */
//  #define   SUPC_MR_BODRSTEN_NOT_ENABLE (0x0u << 12) /**< \brief (SUPC_MR) The core reset signal vddcore_nreset is not affected when a brownout detection occurs. */
//  #define   SUPC_MR_BODRSTEN_ENABLE (0x1u << 12) /**< \brief (SUPC_MR) The core reset signal, vddcore_nreset is asserted when a brownout detection occurs. */
//  #define SUPC_MR_BODDIS (0x1u << 13) /**< \brief (SUPC_MR) Brownout Detector Disable */
//  #define   SUPC_MR_BODDIS_ENABLE (0x0u << 13) /**< \brief (SUPC_MR) The core brownout detector is enabled. */
//  #define   SUPC_MR_BODDIS_DISABLE (0x1u << 13) /**< \brief (SUPC_MR) The core brownout detector is disabled. */
//  #define SUPC_MR_BKUPRETON (0x1u << 17) /**< \brief (SUPC_MR) SRAM On In Backup Mode */
//  #define SUPC_MR_PORDIS (0x1u << 23) /**< \brief (SUPC_MR) Power-on Reset VDDCORE Disable */
//  #define   SUPC_MR_PORDIS_ENABLE (0x0u << 23) /**< \brief (SUPC_MR) The core power-on reset is enabled. */
//  #define   SUPC_MR_PORDIS_DISABLE (0x1u << 23) /**< \brief (SUPC_MR) The core power-on reset is disabled. */


//------------------------------------------------------------------------------
// ---- Softpack compatibility section: may be moved to a separate file
//------------------------------------------------------------------------------
#define CONFIG_HAVE_ETH

#define GMAC_UR_MII_TYPE_Pos 0
#define GMAC_UR_MII_TYPE_Msk (0x1u << 0) /**< \brief (GMAC_UR) PHY 
Interface Mode */
#define   GMAC_UR_MII_TYPE_RMII (0x0u << 0) /**< \brief (GMAC_UR)RMII 
Mode */
#define   GMAC_UR_MII_TYPE_MII (0x1u << 0) /**< \brief (GMAC_UR) MII Mode */


#ifndef XDMAC0
  #define XDMAC0 XDMAC
#endif
//#ifndef ID_XDMAC0
//  #define ID_XDMAC0 ID_XDMAC
//#endif

#ifndef GMAC0
  #define GMAC0 GMAC
#endif
//#ifndef ID_GMAC0
//  #define ID_GMAC0 ID_GMAC
//#endif


//#define FLEXCOM0   ((Flexcom  *)0x40010000U) /**< \brief (FLEXCOM0  ) Base Address */
#define FLEXUSART0 ((Usart    *)0x40010200U) /**< \brief (FLEXUSART0) Base Address */
#define FLEXSPI0   ((Spi      *)0x40010400U) /**< \brief (FLEXSPI0  ) Base Address */
#define FLEXTWI0   ((Twi      *)0x40010600U) /**< \brief (FLEXTWI0  ) Base Address */
//#define FLEXCOM1   ((Flexcom  *)0x40014000U) /**< \brief (FLEXCOM1  ) Base Address */
#define FLEXUSART1 ((Usart    *)0x40014200U) /**< \brief (FLEXUSART1) Base Address */
#define FLEXSPI1   ((Spi      *)0x40014400U) /**< \brief (FLEXSPI1  ) Base Address */
#define FLEXTWI1   ((Twi      *)0x40014600U) /**< \brief (FLEXTWI1  ) Base Address */
//#define FLEXCOM2   ((Flexcom  *)0x40018000U) /**< \brief (FLEXCOM2  ) Base Address */
#define FLEXUSART2 ((Usart    *)0x40018200U) /**< \brief (FLEXUSART2) Base Address */
#define FLEXSPI2   ((Spi      *)0x40018400U) /**< \brief (FLEXSPI2  ) Base Address */
#define FLEXTWI2   ((Twi      *)0x40018600U) /**< \brief (FLEXTWI2  ) Base Address */
//#define FLEXCOM3   ((Flexcom  *)0x4001C000U) /**< \brief (FLEXCOM3  ) Base Address */
#define FLEXUSART3 ((Usart    *)0x4001C200U) /**< \brief (FLEXUSART3) Base Address */
#define FLEXSPI3   ((Spi      *)0x4001C400U) /**< \brief (FLEXSPI3  ) Base Address */
#define FLEXTWI3   ((Twi      *)0x4001C600U) /**< \brief (FLEXTWI3  ) Base Address */
//#define FLEXCOM4   ((Flexcom  *)0x40020000U) /**< \brief (FLEXCOM4  ) Base Address */
#define FLEXUSART4 ((Usart    *)0x40020200U) /**< \brief (FLEXUSART4) Base Address */
#define FLEXSPI4   ((Spi      *)0x40020400U) /**< \brief (FLEXSPI4  ) Base Address */
#define FLEXTWI4   ((Twi      *)0x40020600U) /**< \brief (FLEXTWI4  ) Base Address */
//#define FLEXCOM5   ((Flexcom  *)0x40024000U) /**< \brief (FLEXCOM5  ) Base Address */
#define FLEXUSART5 ((Usart    *)0x40024200U) /**< \brief (FLEXUSART5) Base Address */
#define FLEXSPI5   ((Spi      *)0x40024400U) /**< \brief (FLEXSPI5  ) Base Address */
#define FLEXTWI5   ((Twi      *)0x40024600U) /**< \brief (FLEXTWI5  ) Base Address */
//#define FLEXCOM6   ((Flexcom  *)0x40028000U) /**< \brief (FLEXCOM6  ) Base Address */
#define FLEXUSART6 ((Usart    *)0x40028200U) /**< \brief (FLEXUSART6) Base Address */
#define FLEXSPI6   ((Spi      *)0x40028400U) /**< \brief (FLEXSPI6  ) Base Address */
#define FLEXTWI6   ((Twi      *)0x40028600U) /**< \brief (FLEXTWI6  ) Base Address */
//#define FLEXCOM7   ((Flexcom  *)0x4002C000U) /**< \brief (FLEXCOM7  ) Base Address */
#define FLEXUSART7 ((Usart    *)0x4002C200U) /**< \brief (FLEXUSART7) Base Address */
#define FLEXSPI7   ((Spi      *)0x4002C400U) /**< \brief (FLEXSPI7  ) Base Address */
#define FLEXTWI7   ((Twi      *)0x4002C600U) /**< \brief (FLEXTWI7  ) Base Address */
//#define FLEXCOM8   ((Flexcom  *)0x40030000U) /**< \brief (FLEXCOM8  ) Base Address */
#define FLEXUSART8 ((Usart    *)0x40030200U) /**< \brief (FLEXUSART8) Base Address */
#define FLEXSPI8   ((Spi      *)0x40030400U) /**< \brief (FLEXSPI8  ) Base Address */
#define FLEXTWI8   ((Twi      *)0x40030600U) /**< \brief (FLEXTWI8  ) Base Address */
//#define FLEXCOM9   ((Flexcom  *)0x40034000U) /**< \brief (FLEXCOM9  ) Base Address */
#define FLEXUSART9 ((Usart    *)0x40034200U) /**< \brief (FLEXUSART9) Base Address */
#define FLEXSPI9   ((Spi      *)0x40034400U) /**< \brief (FLEXSPI9  ) Base Address */
#define FLEXTWI9   ((Twi      *)0x40034600U) /**< \brief (FLEXTWI9  ) Base Address */

#include "../__ValidLibs/v_drivers/v_flexcom_wrapper.h"
//#include "Capella_chip.h"
//------------------------------------------------------------------------------

//USB Soft Debug
#define PMC_SCER_UDP            (0x1u << 7) /**< \brief (PMC_SCER) USB Device Port Clock Enable */
#define PMC_SCER_UHP            (0x1u << 6) /**< \brief (PMC_SCER) USB Host Port Clock Enable */
#define PMC_SCDR_UDP            (0x1u << 7) /**< \brief (PMC_SCER) USB Device Port Clock Disable */
#define PMC_SCDR_UHP            (0x1u << 6) /**< \brief (PMC_SCER) USB Host Port Clock Disable */
#define PMC_SCSR_UDP            (0x1u << 7) /**< \brief (PMC_SCER) USB Device Port Clock Status */
#define PMC_SCSR_UHP            (0x1u << 6) /**< \brief (PMC_SCER) USB Host Port Clock Status */















#endif //_VALID_PATCH_CAPELLA_H