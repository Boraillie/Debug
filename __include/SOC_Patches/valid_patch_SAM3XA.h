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
#ifndef _VALID_PATCH_SAM3XA_H
#define _VALID_PATCH_SAM3XA_H


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
typedef volatile const uint32_t RoReg; /**< Read only 32-bit register (volatile const unsigned int) */
typedef volatile       uint32_t WoReg; /**< Write only 32-bit register (volatile unsigned int) */
typedef volatile       uint32_t RwReg; /**< Read-Write 32-bit register (volatile unsigned int) */
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: 
//        number of lock bits
//------------------------------------------------------------------------------
#if (IFLASH0_NB_OF_LOCK_BITS==32)
  #undef IFLASH0_NB_OF_LOCK_BITS
  #undef IFLASH1_NB_OF_LOCK_BITS
  #define IFLASH0_NB_OF_LOCK_BITS  (16u)
  #define IFLASH1_NB_OF_LOCK_BITS  (16u)
#elif (IFLASH0_NB_OF_LOCK_BITS==16)
  #undef IFLASH0_NB_OF_LOCK_BITS
  #undef IFLASH1_NB_OF_LOCK_BITS
  #define IFLASH0_NB_OF_LOCK_BITS  (8u)
  #define IFLASH1_NB_OF_LOCK_BITS  (8u)
  #warning For 2x128KB devices (SAM3x4xxx)
#endif
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: 
//        CHIP ID value (doc11057 28-May-2012)
//------------------------------------------------------------------------------
#undef  CHIP_CIDR
#define CHIP_CIDR         (0x285E0A60UL)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: 
//        Support iSOC IT handler naming changes (IrqHandler/ Handler)
//------------------------------------------------------------------------------
#define HANDLER_SUFFIX _Handler
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
//#define CHIP_FREQ_XTAL_32K (32768)
#define SUPC_MR_ONREG SUPC_MR_VDDIORDY_VDDIO_PRESENT //same bit?

#define   SUPC_SMMR_SMTH_1_9V (0x0u << SUPC_SMMR_SMTH_Pos)
#define   SUPC_SMMR_SMTH_2_0V (0x1u << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_2_1V (0x2u << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_2_2V (0x3u << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_2_3V (0x4u << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_2_4V (0x5u << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_2_5V (0x6u << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_2_6V (0x7u << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_2_7V (0x8u << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_2_8V (0x9u << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_2_9V (0xAu << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_3_0V (0xBu << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_3_1V (0xCu << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_3_2V (0xDu << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_3_3V (0xEu << SUPC_SMMR_SMTH_Pos) 
#define   SUPC_SMMR_SMTH_3_4V (0xFu << SUPC_SMMR_SMTH_Pos) 
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- SOC naming changes
//------------------------------------------------------------------------------
#define PMC_SCER_UOTGCK PMC_SCER_UOTGCLK
#define PMC_SCDR_UOTGCK PMC_SCDR_UOTGCLK

#define SUPC_MR_KEY(passwd)  ((SUPC_MR_KEY_Msk & ((passwd) << SUPC_MR_KEY_Pos)))
#define SUPC_CR_KEY(passwd)  ((SUPC_CR_KEY_Msk & ((passwd) << SUPC_CR_KEY_Pos)))

#define RSTC_MR_KEY(passwd)  ((RSTC_MR_KEY_Msk & ((passwd) << RSTC_MR_KEY_Pos)))
#define RSTC_CR_KEY(passwd)  ((RSTC_CR_KEY_Msk & ((passwd) << RSTC_CR_KEY_Pos)))

#define WDT_CR_KEY(passwd)  ((WDT_CR_KEY_Msk & ((passwd) << WDT_CR_KEY_Pos)))
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: to support VDE v_debug.h generic naming
// ---- Applicable only for VDE
//------------------------------------------------------------------------------
void UART0_Handler       ( void );
#undef  UART
#define UART0 ((Uart   *)0x400E0800U)
//#undef  ID_UART
#define ID_UART0  ( 8)
#define PDC_UART0 PDC_UART
//---------------------------------------------
#define BRD_BASE_PIO_UART0  BRD_BASE_PIO_UART
#define BRD_ID_PIO_UART0    BRD_ID_PIO_UART
#define BRD_UART0_RXD	    BRD_UART_RXD
#define BRD_UART0_TXD	    BRD_UART_TXD
#define BRD_PERIPH_UART0    BRD_PERIPH_UART
//---------------------------------------------
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- SOC naming compatibility
//------------------------------------------------------------------------------
#ifndef IRAM_ADDR
  #ifdef IRAM0_ADDR
    #define IRAM_ADDR IRAM0_ADDR
  #endif
#endif

#ifndef IFLASH_ADDR
  #ifdef IFLASH0_ADDR
    #define IFLASH_ADDR IFLASH0_ADDR
  #endif
#endif

#ifndef IFLASH_PAGE_SIZE
  #ifdef IFLASH0_PAGE_SIZE
    #define IFLASH_PAGE_SIZE IFLASH0_PAGE_SIZE
  #endif
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: EFC missing definitions
//------------------------------------------------------------------------------
/*
#ifndef EEFC_FCR_FKEY
  #define EEFC_FCR_FKEY(value) ((EEFC_FCR_FKEY_Msk & ((value) << EEFC_FCR_FKEY_Pos)))
#endif

#ifndef EEFC_FCR_FCMD
  #define EEFC_FCR_FCMD(value) ((EEFC_FCR_FCMD_Msk & ((value) << EEFC_FCR_FCMD_Pos)))
#endif
*/
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: iSOC naming update
//------------------------------------------------------------------------------
/*
//#define PMC_MCKR_PRES_CLK_1 PMC_MCKR_PRES_CLK
//#define IFLASH_PAGE_SIZE         IFLASH0_PAGE_SIZE
#define IFLASH_LOCK_REGION_SIZE  IFLASH0_LOCK_REGION_SIZE
#define IFLASH_NB_OF_PAGES       IFLASH0_NB_OF_PAGES
//#define IFLASH_NB_OF_LOCK_BITS   IFLASH0_NB_OF_LOCK_BITS
*/
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: missing Flash informations / naming changes
//------------------------------------------------------------------------------
/*
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
*/
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAM3XAxx.h"//ERr
//------------------------------------------------------------------------------

#endif//_VALID_PATCH_SAM3XA_H
