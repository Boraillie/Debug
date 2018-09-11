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
#ifndef _VALID_PATCH_CANOPUS_H
#define _VALID_PATCH_CANOPUS_H


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions in last generated headers for MRLB
//------------------------------------------------------------------------------
// Device characteristics
#ifndef CHIP_FREQ_SLCK_RC_MIN
  #define CHIP_FREQ_SLCK_RC_MIN (20000UL)
#endif
#ifndef CHIP_FREQ_SLCK_RC
  #define CHIP_FREQ_SLCK_RC (32000UL)
#endif
#ifndef CHIP_FREQ_SLCK_RC_MAX
  #define CHIP_FREQ_SLCK_RC_MAX (44000UL)
#endif
#ifndef CHIP_FREQ_MAINCK_RC_4MHZ
  #define CHIP_FREQ_MAINCK_RC_4MHZ (4000000UL)
#endif
#ifndef CHIP_FREQ_MAINCK_RC_8MHZ
  #define CHIP_FREQ_MAINCK_RC_8MHZ (8000000UL)
#endif
#ifndef CHIP_FREQ_MAINCK_RC_12MHZ
  #define CHIP_FREQ_MAINCK_RC_12MHZ (12000000UL)
#endif
#ifndef CHIP_FREQ_CPU_MAX
  #define CHIP_FREQ_CPU_MAX (120000000UL)
#endif
#ifndef CHIP_FREQ_XTAL_32K
  #define CHIP_FREQ_XTAL_32K (32768UL)
#endif
#ifndef CHIP_FREQ_XTAL_12M
  #define CHIP_FREQ_XTAL_12M (12000000UL)
#endif

// Embedded Flash Read Wait State (VDDCORE set at 1.20V)
#ifndef CHIP_FREQ_FWS_0
  #define CHIP_FREQ_FWS_0 (20000000UL)  /**< \brief Maximum operating frequency when FWS is 0 */
#endif
#ifndef CHIP_FREQ_FWS_1
  #define CHIP_FREQ_FWS_1 (40000000UL)  /**< \brief Maximum operating frequency when FWS is 1 */
#endif
#ifndef CHIP_FREQ_FWS_2
  #define CHIP_FREQ_FWS_2 (60000000UL)  /**< \brief Maximum operating frequency when FWS is 2 */
#endif
#ifndef CHIP_FREQ_FWS_3
  #define CHIP_FREQ_FWS_3 (80000000UL)  /**< \brief Maximum operating frequency when FWS is 3 */
#endif
#ifndef CHIP_FREQ_FWS_4
  #define CHIP_FREQ_FWS_4 (100000000UL) /**< \brief Maximum operating frequency when FWS is 4 */
#endif
#ifndef CHIP_FREQ_FWS_5
  #define CHIP_FREQ_FWS_5 (123000000UL) /**< \brief Maximum operating frequency when FWS is 5 */
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: DACC missing definitions / wrong comments
//------------------------------------------------------------------------------
#ifndef REG_DACC_CDR0
  #define REG_DACC_CDR0   REG_DACC_CDR
#endif
#ifndef REG_DACC_CDR1
  #define REG_DACC_CDR1   (*(__O  uint32_t*)0x40040020U) /**< \brief (DACC) Conversion Data Register */
#endif
//#define   DACC_TRIGR_TRGSEL0_TRGSEL0 (0x0u << 4) /**< \brief (DACC_TRIGR) External */
//#define   DACC_TRIGR_TRGSEL0_TRGSEL1 (0x1u << 4) /**< \brief (DACC_TRIGR) TC0 output */
//#define   DACC_TRIGR_TRGSEL0_TRGSEL2 (0x2u << 4) /**< \brief (DACC_TRIGR) TC1 output */
//#define   DACC_TRIGR_TRGSEL0_TRGSEL3 (0x2u << 4) /**< \brief (DACC_TRIGR) TC2 output */
//#define   DACC_TRIGR_TRGSEL0_TRGSEL4 (0x4u << 4) /**< \brief (DACC_TRIGR) PWM0 event 0 */
//#define   DACC_TRIGR_TRGSEL0_TRGSEL5 (0x5u << 4) /**< \brief (DACC_TRIGR) PWM0 event 1 */
//#define   DACC_TRIGR_TRGSEL0_TRGSEL6 (0x6u << 4) /**< \brief (DACC_TRIGR) PWM1 event 0 */
#ifndef DACC_TRIGR_TRGSEL0_TRGSEL7
  #define   DACC_TRIGR_TRGSEL0_TRGSEL7 (0x7u << 4) /**< \brief (DACC_TRIGR) PWM1 event 1 */
#endif
///////////////////////////////////////////////////////////////////////////////




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
// ---- Bug reference: 
//        iSOC naming changes
//------------------------------------------------------------------------------
#define ACC_WPMR_WPKEY_VALUE ACC_WPMR_WPKEY_PASSWD
#define ACC_WPSR_WPROTERR ACC_WPSR_WPVS
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#if (SAME70B == 1) // header last updates: definitions already present
#else
  typedef volatile const uint32_t RoReg; /**< Read only 32-bit register (volatile const unsigned int) */
  typedef volatile       uint32_t WoReg; /**< Write only 32-bit register (volatile unsigned int) */
  typedef volatile       uint32_t RwReg; /**< Read-Write 32-bit register (volatile unsigned int) */
#endif
//------------------------------------------------------------------------------
#define RSTC_CR_PERRST (0x1u << 2) /**< \brief (RSTC_CR) Peripheral Reset */


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
/*
#define AFEC_MR_SETTLING_Pos 20
#define AFEC_MR_SETTLING_Msk (0x3u << AFEC_MR_SETTLING_Pos)
#define   AFEC_MR_SETTLING_AST3 ( 0x0u << AFEC_MR_SETTLING_Pos)
#define   AFEC_MR_SETTLING_AST5  (0x1u << AFEC_MR_SETTLING_Pos)
#define   AFEC_MR_SETTLING_AST9  (0x2u << AFEC_MR_SETTLING_Pos)
#define   AFEC_MR_SETTLING_AST17 (0x3u << AFEC_MR_SETTLING_Pos)
#warning: Check inconsistency between headers and datasheet!!!
*/
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#define WDT_MR_WDRPROC (0x1u << 14) /**< \brief (WDT_MR) Watchdog Reset Processor */
#define  CCFG_SYSIO (*(__IO uint32_t*)0x40088114U)    
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: iSock Bad definitions
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: Supply monitor threshold values definitions
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




//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#ifndef SUPC_MR_ONREG
  #define SUPC_MR_ONREG (0x1u << 14) /**< \brief (SUPC_MR) Voltage Regulator enable */
#endif
//#define PMC_WPMR_WPKEY(value) ((PMC_WPMR_WPKEY_Msk & ((value) << PMC_WPMR_WPKEY_Pos)))
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#ifndef RSTC_CR_KEY
  #define RSTC_CR_KEY(value) ((RSTC_CR_KEY_Msk & ((value) << RSTC_CR_KEY_Pos)))
#endif
#ifndef RSTC_MR_KEY
  #define RSTC_MR_KEY(value) ((RSTC_MR_KEY_Msk & ((value) << RSTC_MR_KEY_Pos)))
#endif
#ifndef SUPC_CR_KEY
  #define SUPC_CR_KEY(value) ((SUPC_CR_KEY_Msk & ((value) << SUPC_CR_KEY_Pos)))
#endif
#ifndef SUPC_MR_KEY
  #define SUPC_MR_KEY(value) ((SUPC_MR_KEY_Msk & ((value) << SUPC_MR_KEY_Pos)))
#endif
#ifndef WDT_CR_KEY
  #define WDT_CR_KEY(value) ((WDT_CR_KEY_Msk & ((value) << WDT_CR_KEY_Pos)))
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: missing Flash informations / naming changes
//------------------------------------------------------------------------------
#ifndef IFLASH_PAGE_SIZE
  #ifdef IFLASH0_PAGE_SIZE
    #define IFLASH_PAGE_SIZE (IFLASH0_PAGE_SIZE)
    #ifdef IFLASH1_PAGE_SIZE
      #if(IFLASH1_PAGE_SIZE != IFLASH0_PAGE_SIZE)
        #warning Flash0 and Flash1 page sizes are not the same
      #endif
    #endif
  #else
    #error IFLASH: No page size definition available
  #endif
#endif

#ifndef IFLASH_NB_OF_LOCK_BITS
  #define IFLASH_NB_OF_LOCK_BITS  (IFLASH_NB_OF_PAGES/32)
  #define IFLASH0_NB_OF_LOCK_BITS (IFLASH_NB_OF_LOCK_BITS)
/*
  #ifdef IFLASH1_NB_OF_LOCK_BITS
    #define IFLASH_NB_OF_LOCK_BITS (IFLASH0_NB_OF_LOCK_BITS+IFLASH1_NB_OF_LOCK_BITS)
  #else
    #ifdef IFLASH0_NB_OF_LOCK_BITS
      #define IFLASH_NB_OF_LOCK_BITS (IFLASH0_NB_OF_LOCK_BITS)
    #else
      #error IFLASH: No lock bits number definition available
    #endif
  #endif
*/
#else
  #ifndef IFLASH0_NB_OF_LOCK_BITS
    #define IFLASH0_NB_OF_LOCK_BITS IFLASH_NB_OF_LOCK_BITS
  #endif
#endif
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_CANOPUS.h"


#endif //_VALID_PATCH_SAMG55_H
