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
#ifndef _VALID_PATCH_SAM4S_H
#define _VALID_PATCH_SAM4S_H




//------------------------------------------------------------------------------
// ---- Bug reference: PMC missing definitions
//------------------------------------------------------------------------------
#define PMC_WPMR_WPKEY_PASSWD PMC_WPMR_WPKEY(0x504D43)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: 
//        Support iSOC IT handler naming changes (IrqHandler/ Handler)
//------------------------------------------------------------------------------
#define HANDLER_SUFFIX _IrqHandler

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: definitions missing for SAM4S4xx devices
//------------------------------------------------------------------------------
#if (SAM4S4==1 || SAM4S2==1)

  // PDC base addresses defnitions
  #define PDC_HSMCI  ((Pdc    *)0x40000100U) /**< \brief (PDC_HSMCI ) Base Address */
  #define PDC_SSC    ((Pdc    *)0x40004100U) /**< \brief (PDC_SSC   ) Base Address */
  #define PDC_SPI    ((Pdc    *)0x40008100U) /**< \brief (PDC_SPI   ) Base Address */
  #define PDC_TWI0   ((Pdc    *)0x40018100U) /**< \brief (PDC_TWI0  ) Base Address */
  #define PDC_TWI1   ((Pdc    *)0x4001C100U) /**< \brief (PDC_TWI1  ) Base Address */
  #define PDC_PWM    ((Pdc    *)0x40020100U) /**< \brief (PDC_PWM   ) Base Address */
  #define PDC_USART0 ((Pdc    *)0x40024100U) /**< \brief (PDC_USART0) Base Address */
  #define PDC_USART1 ((Pdc    *)0x40028100U) /**< \brief (PDC_USART1) Base Address */
  #define PDC_ADC    ((Pdc    *)0x40038100U) /**< \brief (PDC_ADC   ) Base Address */
  #define PDC_DACC   ((Pdc    *)0x4003C100U) /**< \brief (PDC_DACC  ) Base Address */
  #define PDC_UART0  ((Pdc    *)0x400E0700U) /**< \brief (PDC_UART0 ) Base Address */
  #define PDC_UART1  ((Pdc    *)0x400E0900U) /**< \brief (PDC_UART1 ) Base Address */
  #define PDC_PIOA   ((Pdc    *)0x400E0F68U) /**< \brief (PDC_PIOA  ) Base Address */

  // ****************************************
  //   MISCELLANEOUS DEFINITIONS FOR SAM4S8B
  #define CHIP_JTAGID (0x05B3203FUL)
  #define CHIPID_EXID (0x0UL)
  #if defined __SAM4S2A__
    #error VDE compilation error: Device not supported
  #elif defined __SAM4S2B__
    #error VDE compilation error: Device not supported
  #elif defined __SAM4S2C__
    #define CHIPID_CIDR (0x28AB07E0UL)
  #elif defined __SAM4S4A__
    #error VDE compilation error: Device not supported
  #elif defined __SAM4S4B__
    #error VDE compilation error: Device not supported
  #elif defined __SAM4S4C__
    #define CHIPID_CIDR (0x28AB09E0UL)
  #endif

// ***************************************
//   ELECTRICAL DEFINITIONS FOR SAM4Sxx 

  /* Device characteristics */
  #define CHIP_FREQ_SLCK_RC_MIN           (20000UL)
  #define CHIP_FREQ_SLCK_RC               (32000UL)
  #define CHIP_FREQ_SLCK_RC_MAX           (44000UL)
  #define CHIP_FREQ_MAINCK_RC_4MHZ        (4000000UL)
  #define CHIP_FREQ_MAINCK_RC_8MHZ        (8000000UL)
  #define CHIP_FREQ_MAINCK_RC_12MHZ       (12000000UL)
  #define CHIP_FREQ_CPU_MAX               (120000000UL)
  #define CHIP_FREQ_XTAL_32K              (32768UL)
  #define CHIP_FREQ_XTAL_12M              (12000000UL)

  /* Embedded Flash Write Wait State */
  #define CHIP_FLASH_WRITE_WAIT_STATE     (6U)

  /* Embedded Flash Read Wait State (VDDCORE set at 1.20V) */
  #define CHIP_FREQ_FWS_0                 (20000000UL) 
  #define CHIP_FREQ_FWS_1                 (40000000UL) 
  #define CHIP_FREQ_FWS_2                 (60000000UL) 
  #define CHIP_FREQ_FWS_3                 (80000000UL) 
  #define CHIP_FREQ_FWS_4                 (100000000UL)
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference:                    
//------------------------------------------------------------------------------
#undef  CKGR_PLLAR_MULA_Msk
#define CKGR_PLLAR_MULA_Msk (0x3fu << CKGR_PLLAR_MULA_Pos)
//#warning Validation patch : CKGR_PLLAR_MULA_Msk redefined
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: definitions missing in iSOC header last release
//------------------------------------------------------------------------------
#define PMC_FSMR_LPM (0x1<<20) // used in current version of pmc.c (ASF)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: Supply monitor threshold values definitions
//------------------------------------------------------------------------------
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
// ---- Bug reference: iFLASH bad definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: iSOC naming update
//------------------------------------------------------------------------------
// => definition updated in iSOC header last release
/*
#ifndef CKGR_MOR_MOSCRCF_4_MHz
  #define CKGR_MOR_MOSCRCF_4_MHz CKGR_MOR_MOSCRCF_4MHz
#endif
#ifndef CKGR_MOR_MOSCRCF_8_MHz
  #define CKGR_MOR_MOSCRCF_8_MHz CKGR_MOR_MOSCRCF_8MHz
#endif
#ifndef CKGR_MOR_MOSCRCF_12_MHz
  #define CKGR_MOR_MOSCRCF_12_MHz CKGR_MOR_MOSCRCF_12MHz
#endif

#define PMC_MCKR_PRES_CLK_1  PMC_MCKR_PRES_CLK
#define CKGR_PLLAR_ONE       CKGR_PLLAR_STUCKTO1
*/
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAM4Sxx.h"
//------------------------------------------------------------------------------

#endif//_VALID_PATCH_SAM4S_H
