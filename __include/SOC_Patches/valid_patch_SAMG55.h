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
#ifndef _VALID_PATCH_SAMG55_H
#define _VALID_PATCH_SAMG55_H
//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//-----------------------------------------------------------------------------
//FLEXCOMX handler 
extern void FLEXCOM0_Handler      ( void );
extern void FLEXCOM1_Handler      ( void );
extern void FLEXCOM2_Handler      ( void );
extern void FLEXCOM3_Handler      ( void );
extern  void FLEXCOM4_Handler      ( void );
extern void FLEXCOM5_Handler      ( void );
extern void FLEXCOM6_Handler      ( void );
extern void FLEXCOM7_Handler      ( void );
#define ID_FLEXCOM0 ID_USART0
#define ID_FLEXCOM1 ID_USART1
#define ID_FLEXCOM2 ID_USART2
#define ID_FLEXCOM3 ID_USART3
#define ID_FLEXCOM4 ID_USART4
#define ID_FLEXCOM5 ID_USART5
#define ID_FLEXCOM6 ID_USART6
#define ID_FLEXCOM7 ID_USART7
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

//------------------------------------------------------------------------------






//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#define SUPC_MR_ONREG (0x1u << 14) /**< \brief (SUPC_MR) Voltage Regulator enable */

//#define PMC_WPMR_WPKEY(value) ((PMC_WPMR_WPKEY_Msk & ((value) << PMC_WPMR_WPKEY_Pos)))
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#define RSTC_CR_KEY(value) ((RSTC_CR_KEY_Msk & ((value) << RSTC_CR_KEY_Pos)))
#define RSTC_MR_KEY(value) ((RSTC_MR_KEY_Msk & ((value) << RSTC_MR_KEY_Pos)))

#define SUPC_CR_KEY(value) ((SUPC_CR_KEY_Msk & ((value) << SUPC_CR_KEY_Pos)))
#define SUPC_MR_KEY(value) ((SUPC_MR_KEY_Msk & ((value) << SUPC_MR_KEY_Pos)))

#define WDT_CR_KEY(value) ((WDT_CR_KEY_Msk & ((value) << WDT_CR_KEY_Pos)))

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
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAMG55.h"


#endif //_VALID_PATCH_SAMG55_H
