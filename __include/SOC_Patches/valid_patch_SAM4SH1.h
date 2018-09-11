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
* Creation            : 10/Jan/2013
*----------------------------------------------------------------------------
*/
#ifndef _VALID_PATCH_SAM4SH1_H
#define _VALID_PATCH_SAM4SH1_H


//------------------------------------------------------------------------------
// ---- Bug reference: 
//        Support iSOC IT handler naming changes (IrqHandler/ Handler)
//------------------------------------------------------------------------------
#define HANDLER_SUFFIX _IrqHandler

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: Bas definition for RC values (SAM4SH1)
//------------------------------------------------------------------------------
#undef    CKGR_MOR_MOSCRCF_4_MHz
#undef    CKGR_MOR_MOSCRCF_8_MHz
#undef    CKGR_MOR_MOSCRCF_12_MHz
#define   CKGR_MOR_MOSCRCF_8_MHz   (0x0u << 4)  // (CKGR_MOR) 
#define   CKGR_MOR_MOSCRCF_16_MHz  (0x1u << 4)  // (CKGR_MOR) 
#define   CKGR_MOR_MOSCRCF_24_MHz  (0x2u << 4)  // (CKGR_MOR) 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: TWI0 and TWI2 addresses swapped (SAM4SH1)
//------------------------------------------------------------------------------
#undef  TWI0
#undef  TWI2
#define TWI0   ((Twihs *)0x40018000U) // (TWI0       ) Base Address */
#define TWI2   ((Twi   *)0x40040000U) // (TWI0       ) Base Address */
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: Matrix register missing definitions (SAM4SH1)
//------------------------------------------------------------------------------
#define   REG_MATRIX_WPMR (*(RwReg*)0x400E03E4U)
#define   REG_MATRIX_WPSR (*(RwReg*)0x400E03E8U)
/* -------- MATRIX_WPMR : (MATRIX Offset: 0x1E4) Write Protect Mode Register -------- */
#define MATRIX_WPMR_WPEN (0x1u << 0) /**< \brief (MATRIX_WPMR) Write Protect ENable */
#define MATRIX_WPMR_WPKEY_Pos 8
#define MATRIX_WPMR_WPKEY_Msk (0xffffffu << MATRIX_WPMR_WPKEY_Pos) /**< \brief (MATRIX_WPMR) Write Protect KEY (Write-only) */
#define MATRIX_WPMR_WPKEY(value) ((MATRIX_WPMR_WPKEY_Msk & ((value) << MATRIX_WPMR_WPKEY_Pos)))
/* -------- MATRIX_WPSR : (MATRIX Offset: 0x1E8) Write Protect Status Register -------- */
#define MATRIX_WPSR_WPVS (0x1u << 0) /**< \brief (MATRIX_WPSR) Write Protect Violation Status */
#define MATRIX_WPSR_WPVSRC_Pos 8
#define MATRIX_WPSR_WPVSRC_Msk (0xffffu << MATRIX_WPSR_WPVSRC_Pos) /**< \brief (MATRIX_WPSR) Write Protect Violation Source */
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: missing Flash informations
//------------------------------------------------------------------------------
#define PMC_FSMR_LPM (0x1<<20) // used in current version of pmc.c (ASF)
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
  #ifdef IFLASH1_NB_OF_LOCK_BITS
    #define IFLASH_NB_OF_LOCK_BITS (IFLASH0_NB_OF_LOCK_BITS+IFLASH1_NB_OF_LOCK_BITS)
  #else
    #ifdef IFLASH0_NB_OF_LOCK_BITS
      #define IFLASH_NB_OF_LOCK_BITS (IFLASH0_NB_OF_LOCK_BITS)
    #else
      #error IFLASH: No lock bits number definition available
    #endif
  #endif
#else
  #ifndef IFLASH0_NB_OF_LOCK_BITS
    #define IFLASH0_NB_OF_LOCK_BITS IFLASH_NB_OF_LOCK_BITS
  #endif
#endif
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: Supply monitor threshold values definitions (SAM4SH1)
//------------------------------------------------------------------------------
#define   SUPC_SMMR_SMTH_1_60V (0x0u << 0)
#define   SUPC_SMMR_SMTH_1_72V (0x1u << 0)
#define   SUPC_SMMR_SMTH_1_84V (0x2u << 0)
#define   SUPC_SMMR_SMTH_1_96V (0x3u << 0)
#define   SUPC_SMMR_SMTH_2_08V (0x4u << 0)

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAM4SH1.h"

#endif//_VALID_PATCH_SAM4SH1_H
