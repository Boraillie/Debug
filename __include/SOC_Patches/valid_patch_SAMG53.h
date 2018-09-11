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
* Creation            : 07/Aug/2013
*----------------------------------------------------------------------------
*/
#ifndef _VALID_PATCH_SAMG53_H
#define _VALID_PATCH_SAMG53_H


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



//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#define CHIP_FREQ_XTAL_32K (32768)
#define CHIP_FREQ_SLCK_RC  (32000)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: iSock Bad definitions
//------------------------------------------------------------------------------
#undef IFLASH_NB_OF_PAGES
#undef IFLASH_NB_OF_LOCK_BITS
#define IFLASH_NB_OF_PAGES      (1024u)
#define IFLASH_NB_OF_LOCK_BITS  (64u)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: Supply monitor threshold values definitions
//------------------------------------------------------------------------------
#define   SUPC_SMMR_SMTH_1_60V (0x0u << 0)
#define   SUPC_SMMR_SMTH_1_72V (0x1u << 0)
#define   SUPC_SMMR_SMTH_1_84V (0x2u << 0)
#define   SUPC_SMMR_SMTH_1_96V (0x3u << 0)
//not up-to-date ////////////////////////////////////////////////////////////////////////////////////////////
#define   SUPC_SMMR_SMTH_2_08V (0x4u << 0) // to check on SAMG51?

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: Matrix register missing definitions (SAM4SH1) // SAMG53?
//------------------------------------------------------------------------------
// --- MISCELLANEOUS DEFINITIONS ---
#define CHIP_JTAGID (0x05B3C03FUL)
#define CHIP_EXID (0x0UL)
#define CHIP_CIDR (0x247E0AE0UL)


#define   REG_MATRIX_WPMR (*(RwReg*)0x400E03E4U)
#define   REG_MATRIX_WPSR (*(RwReg*)0x400E03E8U)
/* -- MATRIX_WPMR : (MATRIX Offset: 0x1E4) Write Protect Mode Register -- */
#define MATRIX_WPMR_WPEN (0x1u << 0)
#define MATRIX_WPMR_WPKEY_Pos 8
#define MATRIX_WPMR_WPKEY_Msk (0xffffffu << MATRIX_WPMR_WPKEY_Pos)
#define MATRIX_WPMR_WPKEY(value) ((MATRIX_WPMR_WPKEY_Msk & ((value) << MATRIX_WPMR_WPKEY_Pos)))
/* -- MATRIX_WPSR : (MATRIX Offset: 0x1E8) Write Protect Status Register -- */
#define MATRIX_WPSR_WPVS (0x1u << 0)
#define MATRIX_WPSR_WPVSRC_Pos 8
#define MATRIX_WPSR_WPVSRC_Msk (0xffffu << MATRIX_WPSR_WPVSRC_Pos)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
//#define PMC_WPMR_WPKEY(value) ((PMC_WPMR_WPKEY_Msk & ((value) << PMC_WPMR_WPKEY_Pos)))
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: Bad definition for RC values
//------------------------------------------------------------------------------
// ok
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: TWI0 and TWI2 addresses swapped
//------------------------------------------------------------------------------
// ok
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


//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAMG53.h"


#endif //_VALID_PATCH_SAMG53_H
