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
#ifndef _VALID_PATCH_LIMES_H
#define _VALID_PATCH_LIMES_H



//------------------------------------------------------------------------------
// ---- Bug reference: 
//        Support iSOC IT handler naming changes (IrqHandler/ Handler)
//------------------------------------------------------------------------------
#define HANDLER_SUFFIX _Handler

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference:                    
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: definitions missing in iSOCK headers
//------------------------------------------------------------------------------

// --- MISCELLANEOUS DEFINITIONS ---
//#define CHIP_JTAGID (0x05B3203FUL) // DS???
#define CHIPID_EXID (0x0UL)
#define CHIPID_CIDR (0xA50A09E0UL)

// --- ELECTRICAL DEFINITIONS ---
#define CHIP_FREQ_SLCK_RC_MIN           (20000UL)
#define CHIP_FREQ_SLCK_RC               (32000UL)
#define CHIP_FREQ_SLCK_RC_MAX           (44000UL)
#define CHIP_FREQ_MAINCK_RC_4MHZ        (4000000UL)
#define CHIP_FREQ_MAINCK_RC_8MHZ        (8000000UL)
#define CHIP_FREQ_MAINCK_RC_12MHZ       (12000000UL)
#define CHIP_FREQ_CPU_MAX               (48000000UL)
#define CHIP_FREQ_XTAL_32K              (32768UL)
#define CHIP_FREQ_XTAL_12M              (12000000UL)

  /* Embedded Flash Write Wait State */
  //#define CHIP_FLASH_WRITE_WAIT_STATE     (6U)

  /* Embedded Flash Read Wait State (VDDCORE set at 1.20V) */
  //#define CHIP_FREQ_FWS_0                 (20000000UL) 
  //#define CHIP_FREQ_FWS_1                 (40000000UL) 
  //#define CHIP_FREQ_FWS_2                 (60000000UL) 
  //#define CHIP_FREQ_FWS_3                 (80000000UL) 
  //#define CHIP_FREQ_FWS_4                 (100000000UL)
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: Supply monitor threshold values definitions
//------------------------------------------------------------------------------
//2013-may-17 preliminary DS
#define SUPC_SMMR_SMTH_1_60V (0x0000)
#define SUPC_SMMR_SMTH_1_72V (0x0001)
#define SUPC_SMMR_SMTH_1_84V (0x0010)
#define SUPC_SMMR_SMTH_1_96V (0x0011)
#define SUPC_SMMR_SMTH_2_08V (0x0100)
#define SUPC_SMMR_SMTH_2_20V (0x0101)
#define SUPC_SMMR_SMTH_2_32V (0x0110)
#define SUPC_SMMR_SMTH_2_44V (0x0111)
#define SUPC_SMMR_SMTH_2_56V (0x1000)
#define SUPC_SMMR_SMTH_2_68V (0x1001)
#define SUPC_SMMR_SMTH_2_80V (0x1010)
#define SUPC_SMMR_SMTH_2_92V (0x1011)
#define SUPC_SMMR_SMTH_3_04V (0x1100)
#define SUPC_SMMR_SMTH_3_16V (0x1101)
#define SUPC_SMMR_SMTH_3_28V (0x1110)
#define SUPC_SMMR_SMTH_3_40V (0x1111)
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
// ---- Bug reference: iFLASH bad definitions
//------------------------------------------------------------------------------
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
#define SUPC_MR_KEY(value) ((SUPC_MR_KEY_Msk & ((value) << SUPC_MR_KEY_Pos)))
#define SUPC_CR_KEY(value) ((SUPC_CR_KEY_Msk & ((value) << SUPC_CR_KEY_Pos)))
#define WDT_CR_KEY(value) ((WDT_CR_KEY_Msk & ((value) << WDT_CR_KEY_Pos)))
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_LIMES.h"
//------------------------------------------------------------------------------

#endif //_VALID_PATCH_LIMES_H
