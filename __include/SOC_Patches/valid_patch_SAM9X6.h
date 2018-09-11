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
#ifndef _VALID_PATCH_SAM9X6
#define _VALID_PATCH_SAM9X6




//------------------------------------------------------------------------------
// --- To review: section was added here while porting PRGtest from M7 products
//------------------------------------------------------------------------------

#if defined ( __ICCARM__ )
  #define __ASM            __asm    /*!< asm keyword for IAR Compiler          */
  #define __INLINE         inline   /*!< inline keyword for IAR Compiler. Only available in High optimization mode! */
  #define __STATIC_INLINE  static inline
#endif

#ifdef __SRAM_BOOT__
  #define  IRAM_ADDR     0x00000000  // JCK 19may17 for SRAM_BOOT
  #warning !! SRAM_BOOT !!
#else
  #define IRAM_ADDR     0x00300000
#endif

#define IRAM_MIN_SIZE 0x00010000  //128KBmin up to 256KB depending on config

#define __ICACHE_PRESENT   1

#define HANDLER_SUFFIX _Handler

//#define  REG_MATRIX_CCFG_SYSIO      (*(__IO uint32_t*)0x40088114U)
////////------------------------------------------------------------------------------
//////
//////
//////
//////
//////
//////
//////
//////
////////------------------------------------------------------------------------------
//////// ---- Bug reference: PTC definitions
////////------------------------------------------------------------------------------
//////#define ID_PTC (58)
////////------------------------------------------------------------------------------
//////
//////
//////
//////
////////------------------------------------------------------------------------------
//////// ---- Bug reference: missing definitions
////////------------------------------------------------------------------------------
//////#define REG_BSCR  (*(__O  uint32_t*)0xF8048054U)
////////------------------------------------------------------------------------------
//////
//////

//#warning 'MNn Reason for this definition is unknown for the moment'
//------------------------------------------------------------------------------
// ---- Bug reference: added for utils.c clock settings compliance
//------------------------------------------------------------------------------
#define CKGR_MOR_MOSCRCF_12_MHz (0x8C05C12) // Dummy value
//------------------------------------------------------------------------------

////////------------------------------------------------------------------------------
//////// ---- Bug reference: missing definitions
//////// removed because updated in latest iSock delivery
////////------------------------------------------------------------------------------
////////#define REG_SFR_SN0  (*(__I uint32_t*)0xF803004C) /**< \brief (SFR_SN0) Serial Number 0 Register */
////////#define REG_SFR_SN1  (*(__I uint32_t*)0xF8030050) /**< \brief (SFR_SN1) Serial Number 1 Register */
////////------------------------------------------------------------------------------
//////
//////
//////
////////------------------------------------------------------------------------------
//////// ---- Bug reference: missing definitions
////////------------------------------------------------------------------------------
//////#define PMC_MCKR_H32MXDIV_H32MXDIV2 (0x1u << 24)
////////------------------------------------------------------------------------------
//////
//////
//////
////////------------------------------------------------------------------------------
//////// ---- Bug reference: 
////////        Support iSOC IT handler naming changes (IrqHandler/ Handler)
////////------------------------------------------------------------------------------
////////#define HANDLER_SUFFIX _IrqHandler
//////#define HANDLER_SUFFIX _Handler
////////------------------------------------------------------------------------------
//////
//////
////////------------------------------------------------------------------------------
//////// ---- Bug reference: missing definitions
////////------------------------------------------------------------------------------
////////#define CHIP_FREQ_XTAL_32K (32768)
////////------------------------------------------------------------------------------
//////
////////------------------------------------------------------------------------------
//////// ---- Bug reference: iSOC errors
////////------------------------------------------------------------------------------
////////#undef REG_AESB_CR
//////
////////#define REG_AESB_CR     (*(__O  uint32_t*)0xF0020000U)
////////------------------------------------------------------------------------------
//////
//////
//////
//////#define CHIP_ID     (0x8A5C08C0UL)
////////#define CHIP_JTAGID (0x05B3F03FUL)
//////#define CHIP_SWID   (0x5BA00477UL)
//////
//////
//////
////////------------------------------------------------------------------------------
//////// ---- Bug reference: missing definition (DS issue)
//////// removed because updated in latest iSock delivery
////////------------------------------------------------------------------------------
////////#define   MATRIX_WPMR_WPKEY_PASSWD (0x4D4154u << 8) /**< \brief (MATRIX_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. */
////////#define PMC_SR_MOSCRCS (0x1u << 17) ///< @brief Main On-Chip RC Oscillator Status
////////#warning "JCK 27mar15 : define PMC_SR_MOSCRCS ; datasheet error"
//////
//////
//////
////////------------------------------------------------------------------------------
//////// ---- Bug reference: missing definitions
//////// removed because updated in latest iSock delivery
////////------------------------------------------------------------------------------
////////#define   PIO_CFGR_IFSCEN_DISABLED (0x0u << 13)
////////#define   PIO_CFGR_IFSCEN_ENABLED  (0x1u << 13)
////////------------------------------------------------------------------------------
//////
//////
////////------------------------------------------------------------------------------
////////------------------------------------------------------------------------------
//////// ---- compatibility with SAM3xx & SAM4xx iSOC defines
////////------------------------------------------------------------------------------
//////
//////
//////// ---- PMC ----------------------------------------------
//////#define PMC_MCKR_PRES_CLK_1    PMC_MCKR_PRES_CLOCK
//////#define PMC_MCKR_PRES_CLK_2    PMC_MCKR_PRES_CLOCK_DIV2
//////#define PMC_MCKR_PRES_CLK_4    PMC_MCKR_PRES_CLOCK_DIV4
//////#define PMC_MCKR_PRES_CLK_8    PMC_MCKR_PRES_CLOCK_DIV8
//////#define PMC_MCKR_PRES_CLK_16   PMC_MCKR_PRES_CLOCK_DIV16
//////#define PMC_MCKR_PRES_CLK_32   PMC_MCKR_PRES_CLOCK_DIV32
//////#define PMC_MCKR_PRES_CLK_64   PMC_MCKR_PRES_CLOCK_DIV64
////////commented out MNn due to problems encountered un v_pmc.c 
////////#define PMC_PCK_CSS_MCK        PMC_PCK_CSS_MCK_CLK
//////
///////*
//////#define PIOB     ((Pio *)((unsigned char *)PIOA +    sizeof(PioIo_group)) ) ///< \brief (PIOB    ) Base Address
//////#define PIOC     ((Pio *)((unsigned char *)PIOA + (2*sizeof(PioIo_group)))) ///< \brief (PIOC    ) Base Address
//////#define PIOD     ((Pio *)((unsigned char *)PIOA + (3*sizeof(PioIo_group)))) ///< \brief (PIOD    ) Base Address
//////#warning "JCK 31mar15 : artificial definition of PIOB,C,D for backward compatibility"
//////*/
//////
//////// commenting out code for pioV4 IP MNn
//////////#undef PIOA
//////////#ifndef PIO
////////// #define PIO ((Pio*)0xFC038000U) /**< \brief (PIOA    ) Base Address */
//////////#else
////////// #error PIO was already defined (iSock changed?)
//////////#endif
//////////
//////////#undef ID_PIOA
//////////#ifndef ID_PIO
////////// #define ID_PIO (18) /**< \brief Parallel I/O Controller (PIO) */
//////////#else
////////// #error ID_PIO was already defined (iSock changed?)
//////////#endif
//////////
//////////#define PIOA (PIO->PIO_IO_GROUP    )
//////////#define PIOB (PIO->PIO_IO_GROUP + 1)
//////////#define PIOC (PIO->PIO_IO_GROUP + 2)
//////////#define PIOD (PIO->PIO_IO_GROUP + 3)
//////
//////#define CHIP_ID_REGISTER   (CHIPID->CHIPID_CIDR)
//////#define CHIP_EXID_REGISTER (CHIPID->CHIPID_EXID)
//////
//////
////////------------------------------------------------------------------------------
//////// ---- Bug reference:
//////// Added USB relative definitions (imported from AYi)
////////------------------------------------------------------------------------------
///////* -------- CCFG_USBMR : (MATRIX Offset: 0x0120) USB Management Register -------- */
//////#define CCFG_USBMR_DEVICE (0x1u << 0) /**< \brief (CCFG_USBMR) USB device mode */
//////#define CCFG_USBMR_USBHTSSC (0x1u << 1) /**< \brief (CCFG_USBMR) USB Transceiver Suspend Software Control */
//////#define CCFG_USBMR_USBHTSC (0x1u << 2) /**< \brief (CCFG_USBMR) USB Host Transceiver Suspend Control */
///////* -------- CCFG_SYSIO : (MATRIX Offset: 0x0114) System I/O Configuration Register -------- */
//////#define CCFG_SYSIO_SYSIO4 (0x1u << 4) /**< \brief (CCFG_SYSIO) PB4 or TDI Assignment */
//////#define CCFG_SYSIO_SYSIO5 (0x1u << 5) /**< \brief (CCFG_SYSIO) PB5 or TDO/TRACESWO Assignment */
//////#define CCFG_SYSIO_SYSIO6 (0x1u << 6) /**< \brief (CCFG_SYSIO) PB6 or TMS/SWDIO Assignment */
//////#define CCFG_SYSIO_SYSIO7 (0x1u << 7) /**< \brief (CCFG_SYSIO) PB7 or TCK/SWCLK Assignment */
//////#define CCFG_SYSIO_SYSIO10 (0x1u << 10) /**< \brief (CCFG_SYSIO) PA21 or DM Assignment */
//////#define CCFG_SYSIO_SYSIO11 (0x1u << 11) /**< \brief (CCFG_SYSIO) PA22 or DP Assignment */
//////#define CCFG_SYSIO_SYSIO12 (0x1u << 12) /**< \brief (CCFG_SYSIO) PB12 or ERASE Assignment */
////////#define PMC_SCER_UDP            (0x1u << 7) /**< \brief (PMC_SCER) USB Device Port Clock Enable */
////////#define PMC_SCER_UHP            (0x1u << 6) /**< \brief (PMC_SCER) USB Host Port Clock Enable */
//////#define CCFG_USB                (*(__IO uint32_t*)0x400E0320U) /**< \brief (PMC) PLLB Register */
//////#define CCFG_USB_USBTRAN        (1<<0)   //USB Transceiver control management 0: USBHOST is selected  1: USBDEV is selected               
//////#define CCFG_USB_ONNHOST        (1<<1)  //0: ONN is LOW 1: ONN is HIGH
//////#define CCFG_USB_ONNSEL         (1<<2)  //0: ONN is controlled by the OHCI 1: ONN is controlled by the SFR register value SFR4[1]
//////#define CCFG_USB_FREQADJUST     (1<<4)
//////#define CCFG_USB_FREQADJUSTFLT  (1<<5)
//////#define CCFG_USB_ICMODE         (1<<8)                  
//////#define CCFG_USB_ICEOBR         (1<<9)                  
//////#undef  UHP 
//////#define UHP         ((Uhp      *)UHPHS_OHCI_ADDR) /**< \brief (UHP        ) Base Address */
////////------------------------------------------------------------------------------
//////
//////
//////#if 0
//////
///////* -------- PMC_MOR : Islero has one RC frequency 12MHz -------- */
//////#define CKGR_MOR_MOSCRCF_12_MHz 0
//////#define CKGR_MOR_MOSCRCF_Pos 4
//////
//////#define CKGR_MOR_MOSCRCEN (0x1u << 3) /**< \brief (CKGR_MOR) Main On-Chip RC Oscillator Enable */

// PMC Fast Start Mode Register  MNn
#define PMC_FSMR_ULPM (0x1u << 20) /**< \brief (PMC_FSMR) ULPM not defined in FSMR register. This needs to be corrected in next Isock files */ 

//WDT patch MNn creating the Value counter equation since it was not defined in wdt.h header file
//#define WDT_VR_COUNTER(value) ((WDT_VR_COUNTER_Msk & ((value) << WDT_VR_COUNTER_Pos)))
//#define WDT_WLR_RPTH(value) ((WDT_WLR_RPTH_Msk & ((value) << WDT_WLR_RPTH_Pos)))



///* -------- WDT_MR : (WDT Offset: 0x04) Mode Register -------- */
//#define WDT_MR_WDV_Pos 0
//#define WDT_MR_WDV_Msk (0xfffu << WDT_MR_WDV_Pos) /**< \brief (WDT_MR) Watchdog Counter Value */
//#define WDT_MR_WDV(value) ((WDT_MR_WDV_Msk & ((value) << WDT_MR_WDV_Pos)))
//#define WDT_MR_WDFIEN (0x1u << 12) /**< \brief (WDT_MR) Watchdog Fault Interrupt Enable */
//#define WDT_MR_WDRSTEN (0x1u << 13) /**< \brief (WDT_MR) Watchdog Reset Enable */
//#define WDT_MR_WDRPROC (0x1u << 14) /**< \brief (WDT_MR) Watchdog Reset Processor */
//#define WDT_MR_WDDIS (0x1u << 15) /**< \brief (WDT_MR) Watchdog Disable */
//#define WDT_MR_WDD_Pos 16
//#define WDT_MR_WDD_Msk (0xfffu << WDT_MR_WDD_Pos) /**< \brief (WDT_MR) Watchdog Delta Value */
//#define WDT_MR_WDD(value) ((WDT_MR_WDD_Msk & ((value) << WDT_MR_WDD_Pos)))
//#define WDT_MR_WDDBGHLT (0x1u << 28) /**< \brief (WDT_MR) Watchdog Debug Halt */
//#define WDT_MR_WDIDLEHLT (0x1u << 29) /**< \brief (WDT_MR) Watchdog Idle Halt */
///* -------- WDT_CR : (WDT Offset: 0x00) Control Register -------- */
//#define WDT_CR_WDRSTT (0x1u << 0) /**< \brief (WDT_CR) Watchdog Restart */
//#define WDT_CR_KEY_Pos 24
//#define WDT_CR_KEY_Msk (0xffu << WDT_CR_KEY_Pos) /**< \brief (WDT_CR) Password */
//#define WDT_CR_KEY(value) ((WDT_CR_KEY_Msk & ((value) << WDT_CR_KEY_Pos)))

// WDT to DWDT definitions
//#define Wdt Dwdt
//////typedef FlexcomTwi Twi;
//////
//////horribley horrid
//////
//////
///////* -------- SCKC_CR : (SCKC Offset: 0x0) Slow Clock Configuration Register -------- */
//////#define SCKC_CR_RCEN (0x1u << 0) /**< \brief (SCKC_CR) Internal 32 kHz RC Oscillator */
//////#define SCKC_CR_OSC32EN (0x1u << 1) /**< \brief (SCKC_CR) 32,768 Hz Oscillator */
//////#define SCKC_CR_OSC32BYP (0x1u << 2) /**< \brief (SCKC_CR) 32,768Hz Oscillator Bypass */
//////#define SCKC_CR_OSCSEL (0x1u << 3) /**< \brief (SCKC_CR) Slow Clock Selector */
//////#define   SCKC_CR_OSCSEL_RC (0x0u << 3) /**< \brief (SCKC_CR) Slow clock is internal 32 kHz RC oscillator. */
//////#define   SCKC_CR_OSCSEL_XTAL (0x1u << 3) /**< \brief (SCKC_CR) Slow clock is 32,768 Hz oscillator. */
//////
//////#define CKGR_MOR_KEY(value) ((CKGR_MOR_KEY_Msk & ((value) << CKGR_MOR_KEY_Pos)))
///////* -------- CKGR_PLLAR : (PMC Offset: 0x0028) PLLA Register -------- */
//////#define CKGR_PLLAR_DIVA_Pos 0
//////#define CKGR_PLLAR_DIVA_Msk (0xffu << CKGR_PLLAR_DIVA_Pos) /**< \brief (CKGR_PLLAR) Divider A */
//////#define CKGR_PLLAR_DIVA(value) ((CKGR_PLLAR_DIVA_Msk & ((value) << CKGR_PLLAR_DIVA_Pos)))
//////
//////
//////#define PIO_WPMR_WPKEY(value) ((PIO_WPMR_WPKEY_Msk & ((value) << PIO_WPMR_WPKEY_Pos)))
//////#define PMC_WPMR_WPKEY(value) ((PMC_WPMR_WPKEY_Msk & ((value) << PMC_WPMR_WPKEY_Pos)))
//////
//////#endif /* end if 0 */

//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
//#include "Devices/_features/FEATURES_SAMA5D2x.h"
#include "Devices/_features/FEATURES_SAM9X6.h"
//------------------------------------------------------------------------------

#endif//_VALID_PATCH_SAM9X6
