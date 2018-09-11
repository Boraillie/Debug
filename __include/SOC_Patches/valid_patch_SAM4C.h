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
* Object              : ATSAM Definition File.
*
* Creation            : 08/Oct/2011
*----------------------------------------------------------------------------
*/
#ifndef _VALID_PATCH_SAM4C_H
#define _VALID_PATCH_SAM4C_H



//------------------------------------------------------------------------------
// ---- Bug reference: 
//        Support iSOC IT handler naming changes (IrqHandler/ Handler)
//------------------------------------------------------------------------------
#define HANDLER_SUFFIX _IrqHandler

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: iSOCK naming changes (...)
//------------------------------------------------------------------------------
// ----------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: unused definition
//------------------------------------------------------------------------------
#undef IRAM_SIZE // use IRAMx_SIZE instead
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: EFC missing definitions
//------------------------------------------------------------------------------
#ifndef EEFC_FCR_FKEY
  #define EEFC_FCR_FKEY(value) ((EEFC_FCR_FKEY_Msk & ((value) << EEFC_FCR_FKEY_Pos)))
#endif

#ifndef EEFC_FCR_FCMD
  #define EEFC_FCR_FCMD(value) ((EEFC_FCR_FCMD_Msk & ((value) << EEFC_FCR_FCMD_Pos)))
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: definitions missing in iSOC header last release
//------------------------------------------------------------------------------
/* Device characteristics */
#define CHIP_FREQ_SLCK_RC_MIN           (21000UL)
#define CHIP_FREQ_SLCK_RC               (32000UL)
#define CHIP_FREQ_SLCK_RC_MAX           (44000UL)
#define CHIP_FREQ_MAINCK_RC_4MHZ        (4000000UL)
#define CHIP_FREQ_MAINCK_RC_8MHZ        (8000000UL)
#define CHIP_FREQ_MAINCK_RC_12MHZ       (12000000UL)
#define CHIP_FREQ_CPU_MAX               (100000000UL)
#define CHIP_FREQ_XTAL_32K              (32768UL)
#define CHIP_FREQ_XTAL_MIN              (3000000UL)
#define CHIP_FREQ_XTAL                  (16000000UL)
#define CHIP_FREQ_XTAL_MAX              (20000000UL)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: Supply monitor threshold values definitions
//------------------------------------------------------------------------------
//#warning waiting for electrical part to be added to be updated in datasheet
#undef   SUPC_SMMR_SMTH_1_9V
#undef   SUPC_SMMR_SMTH_2_0V
#undef   SUPC_SMMR_SMTH_2_1V
#undef   SUPC_SMMR_SMTH_2_2V
#undef   SUPC_SMMR_SMTH_2_3V
#undef   SUPC_SMMR_SMTH_2_4V
#undef   SUPC_SMMR_SMTH_2_5V
#undef   SUPC_SMMR_SMTH_2_6V
#undef   SUPC_SMMR_SMTH_2_7V
#undef   SUPC_SMMR_SMTH_2_8V
#undef   SUPC_SMMR_SMTH_2_9V
#undef   SUPC_SMMR_SMTH_3_0V
#undef   SUPC_SMMR_SMTH_3_1V
#undef   SUPC_SMMR_SMTH_3_2V
#undef   SUPC_SMMR_SMTH_3_3V
#undef   SUPC_SMMR_SMTH_3_4V
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
// ---- Bug reference: iSOC naming update
//------------------------------------------------------------------------------
// => definition updated in iSOC header last release
#define ID_SRAM1_2   (42)
//-----------------------------------------------------------------------------
// sam4c patch
#if (SAM4C32 == 1)
	#define PMC_MCKR_CSS_PLLB_CLK   (0x3u << 0) /**< \brief (PMC_MCKR) PLLBClock is selected */
        #define CKGR_MOR_KEY(value)     ((CKGR_MOR_KEY_Msk & ((value) << CKGR_MOR_KEY_Pos)))
        #define PMC_SCER_CPKEY(value)   ((PMC_SCER_CPKEY_Msk & ((value) << PMC_SCER_CPKEY_Pos)))
        #define RSTC_CR_KEY(value)      ((RSTC_CR_KEY_Msk & ((value) << RSTC_CR_KEY_Pos)))
        #define RSTC_MR_KEY(value)      ((RSTC_MR_KEY_Msk & ((value) << RSTC_MR_KEY_Pos)))
        #define CKGR_PLLAR_DIVA(value)  ((CKGR_PLLAR_PLLAEN_Msk & ((value) << CKGR_PLLAR_PLLAEN_Pos)))
        #define SUPC_MR_KEY(value)      ((SUPC_MR_KEY_Msk & ((value) << SUPC_MR_KEY_Pos)))
        #define SUPC_CR_KEY(value)      ((SUPC_CR_KEY_Msk & ((value) << SUPC_CR_KEY_Pos)))
        #define WDT_CR_KEY(value)       ((WDT_CR_KEY_Msk & ((value) << WDT_CR_KEY_Pos)))
#endif



//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAM4Cxx.h"
//------------------------------------------------------------------------------

#endif//_VALID_PATCH_SAM4C_H
