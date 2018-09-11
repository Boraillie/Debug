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
* Object              : Patch Definition File.
*
* Creation            : 
*----------------------------------------------------------------------------
*/
#ifndef _VALID_PATCH_ISLERO_H
#define _VALID_PATCH_ISLERO_H


//------------------------------------------------------------------------------
// ---- Bug reference: 
//        Support iSOC IT handler naming changes (IrqHandler/ Handler)
//------------------------------------------------------------------------------
#define HANDLER_SUFFIX _IrqHandler

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: missing definitions
//------------------------------------------------------------------------------
#define CHIP_FREQ_XTAL_32K (32768)
#define CHIP_FREQ_SLCK_RC  (32000)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: iSOC errors
//------------------------------------------------------------------------------
#undef REG_AESB_CR
#undef REG_AESB_MR
#undef REG_AESB_IER
#undef REG_AESB_IDR
#undef REG_AESB_IMR
#undef REG_AESB_ISR
#undef REG_AESB_KEYWR
#undef REG_AESB_IDATAR
#undef REG_AESB_ODATAR
#undef REG_AESB_IVR
#undef AESB

#define REG_AESB_CR     (*(__O  uint32_t*)0xF0020000U)
#define REG_AESB_MR     (*(__IO uint32_t*)0xF0020004U)
#define REG_AESB_IER    (*(__O  uint32_t*)0xF0020010U)
#define REG_AESB_IDR    (*(__O  uint32_t*)0xF0020014U)
#define REG_AESB_IMR    (*(__I  uint32_t*)0xF0020018U)
#define REG_AESB_ISR    (*(__I  uint32_t*)0xF002001CU)
#define REG_AESB_KEYWR  (*(__O  uint32_t*)0xF0020020U)
#define REG_AESB_IDATAR (*(__O  uint32_t*)0xF0020040U)
#define REG_AESB_ODATAR (*(__I  uint32_t*)0xF0020050U)
#define REG_AESB_IVR    (*(__O  uint32_t*)0xF0020060U)
#define AESB    ((Aesb    *)0xF0020000U)
//------------------------------------------------------------------------------





#define CHIP_JTAGID (0x8A5B076xUL)
//#define CHIPID_CIDR (0xXXXXXXUL)
//#define CHIPID_EXID (0xXXXXXXUL)
//------------------------------------------------------------------------------
// ---- Bug reference: missing definition (DS issue)
//------------------------------------------------------------------------------
#define   MATRIX_WPMR_WPKEY_PASSWD (0x4D4154u << 8) /**< \brief (MATRIX_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. */


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// ---- compatibility with SAM3xx & SAM4xx iSOC defines
//------------------------------------------------------------------------------
// ---- PMC ----------------------------------------------
#define PMC_MCKR_PRES_CLK_1    PMC_MCKR_PRES_CLOCK
#define PMC_MCKR_PRES_CLK_2    PMC_MCKR_PRES_CLOCK_DIV2
#define PMC_MCKR_PRES_CLK_4    PMC_MCKR_PRES_CLOCK_DIV4
#define PMC_MCKR_PRES_CLK_8    PMC_MCKR_PRES_CLOCK_DIV8
#define PMC_MCKR_PRES_CLK_16   PMC_MCKR_PRES_CLOCK_DIV16
#define PMC_MCKR_PRES_CLK_32   PMC_MCKR_PRES_CLOCK_DIV32
#define PMC_MCKR_PRES_CLK_64   PMC_MCKR_PRES_CLOCK_DIV64


#define PMC_PCK_CSS_MCK        PMC_PCK_CSS_MCK_CLK


/* -------- PMC_MOR : Islero has one RC frequency 12MHz -------- */
#define CKGR_MOR_MOSCRCF_12_MHz 0
#define CKGR_MOR_MOSCRCF_Pos 4



#define CKGR_MOR_MOSCRCEN (0x1u << 3) /**< \brief (CKGR_MOR) Main On-Chip RC Oscillator Enable */
/* -------- WDT_MR : (WDT Offset: 0x04) Mode Register -------- */
#define WDT_MR_WDV_Pos 0
#define WDT_MR_WDV_Msk (0xfffu << WDT_MR_WDV_Pos) /**< \brief (WDT_MR) Watchdog Counter Value */
#define WDT_MR_WDV(value) ((WDT_MR_WDV_Msk & ((value) << WDT_MR_WDV_Pos)))
#define WDT_MR_WDFIEN (0x1u << 12) /**< \brief (WDT_MR) Watchdog Fault Interrupt Enable */
#define WDT_MR_WDRSTEN (0x1u << 13) /**< \brief (WDT_MR) Watchdog Reset Enable */
#define WDT_MR_WDRPROC (0x1u << 14) /**< \brief (WDT_MR) Watchdog Reset Processor */
#define WDT_MR_WDDIS (0x1u << 15) /**< \brief (WDT_MR) Watchdog Disable */
#define WDT_MR_WDD_Pos 16
#define WDT_MR_WDD_Msk (0xfffu << WDT_MR_WDD_Pos) /**< \brief (WDT_MR) Watchdog Delta Value */
#define WDT_MR_WDD(value) ((WDT_MR_WDD_Msk & ((value) << WDT_MR_WDD_Pos)))
#define WDT_MR_WDDBGHLT (0x1u << 28) /**< \brief (WDT_MR) Watchdog Debug Halt */
#define WDT_MR_WDIDLEHLT (0x1u << 29) /**< \brief (WDT_MR) Watchdog Idle Halt */
/* -------- WDT_CR : (WDT Offset: 0x00) Control Register -------- */
#define WDT_CR_WDRSTT (0x1u << 0) /**< \brief (WDT_CR) Watchdog Restart */
#define WDT_CR_KEY_Pos 24
#define WDT_CR_KEY_Msk (0xffu << WDT_CR_KEY_Pos) /**< \brief (WDT_CR) Password */
#define WDT_CR_KEY(value) ((WDT_CR_KEY_Msk & ((value) << WDT_CR_KEY_Pos)))

/* -------- SCKC_CR : (SCKC Offset: 0x0) Slow Clock Configuration Register -------- */
#define SCKC_CR_RCEN (0x1u << 0) /**< \brief (SCKC_CR) Internal 32 kHz RC Oscillator */
#define SCKC_CR_OSC32EN (0x1u << 1) /**< \brief (SCKC_CR) 32,768 Hz Oscillator */
#define SCKC_CR_OSC32BYP (0x1u << 2) /**< \brief (SCKC_CR) 32,768Hz Oscillator Bypass */
#define SCKC_CR_OSCSEL (0x1u << 3) /**< \brief (SCKC_CR) Slow Clock Selector */
#define   SCKC_CR_OSCSEL_RC (0x0u << 3) /**< \brief (SCKC_CR) Slow clock is internal 32 kHz RC oscillator. */
#define   SCKC_CR_OSCSEL_XTAL (0x1u << 3) /**< \brief (SCKC_CR) Slow clock is 32,768 Hz oscillator. */

#define CKGR_MOR_KEY(value) ((CKGR_MOR_KEY_Msk & ((value) << CKGR_MOR_KEY_Pos)))
/* -------- CKGR_PLLAR : (PMC Offset: 0x0028) PLLA Register -------- */
#define CKGR_PLLAR_DIVA_Pos 0
#define CKGR_PLLAR_DIVA_Msk (0xffu << CKGR_PLLAR_DIVA_Pos) /**< \brief (CKGR_PLLAR) Divider A */
#define CKGR_PLLAR_DIVA(value) ((CKGR_PLLAR_DIVA_Msk & ((value) << CKGR_PLLAR_DIVA_Pos)))


#define PIO_WPMR_WPKEY(value) ((PIO_WPMR_WPKEY_Msk & ((value) << PIO_WPMR_WPKEY_Pos)))
#define PMC_WPMR_WPKEY(value) ((PMC_WPMR_WPKEY_Msk & ((value) << PMC_WPMR_WPKEY_Pos)))


//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_ISLEROxx.h" //ERr
//#include "Devices/_features/FEATURES_SAMA5Dxx.h"
//------------------------------------------------------------------------------

#endif//_VALID_PATCH_ISLERO_H
