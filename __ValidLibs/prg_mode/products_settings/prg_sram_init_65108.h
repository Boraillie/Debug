/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : prg_settings_xxxxx.h
* Object              : product relative PRG definitions
*
* Creation            : ERr / 2015
*----------------------------------------------------------------------------
*/
#ifndef _PRG_SRAM_INIT_65108_H
#define _PRG_SRAM_INIT_65108_H


// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"

#include "v_clocks_management.h"

#define INIT_PARAM_RESERVED_PATTERN  0xAAAAAAAA
#define INIT_RESULT_RESERVED_PATTERN 0xBBBBBBBB
#define INIT_CKSET_RESERVED_PATTERN  0xCCCCCCCC


// -- Clocks settings ---------------------------------------------------------
//Reserve clock set 0 for PRG monitor default setting
//Master clock is configured on fastest RC available (no PLL)
#define INIT_CKSET00_TAG (TAG_TAG(0xC10C)|TAG_IDX(0x0))
#define INIT_CKSET00_MAIN_CK ( MAIN_CK_RC_FREQ_MHZ_DIV2(6)  \
                              & ~MAIN_CK_USE_XTAL           \
                              & ~MAIN_CK_USE_EXTCLK         \
                              | EXT_FREQ_HZ_DIV8(0)         )
#define INIT_CKSET00_MASTER_CK ( MASTER_CK_USE_MAIN           \
                                & ~MASTER_CK_USE_SLOW          \
                                & ~MASTER_CK_USE_PLLA          \
                                & ~MASTER_CK_USE_PLLB          \
                                & ~MASTER_CK_USE_PLLU          \
                                |  MASTER_CK_PROC_PRESCALER(1) \
                                |  MASTER_CK_BUS_MDIV(1)       )
#define INIT_CKSET00_PLL ( PLL_PRE_DIV(1) \
                          | PLL_MUL(20)    \
                          | PLL_POST_DIV2  )
#define INIT_CKSET00_SLOW_CK ( SLOW_CK_USE_RC      \
                              & ~SLOW_CK_USE_XTAL   \
                              & ~SLOW_CK_USE_EXTCLK \
                              | SLOW_CK_EXT_FREQ(0) )
#define INIT_CKSET00_EFC ( EFC_EFC0_WS(0x0) \
                          | EFC_EFC1_WS(0x0) )

// ----------------------------------------------------------------------------
//Master clock configured at 150MHz with processor at 300MHz
#define INIT_CKSET01_TAG (TAG_TAG(0xC10C)|TAG_IDX(0x1))
#define INIT_CKSET01_MAIN_CK ( MAIN_CK_RC_FREQ_MHZ_DIV2(6)  \
                              & ~MAIN_CK_USE_XTAL           \
                              & ~MAIN_CK_USE_EXTCLK         \
                              | EXT_FREQ_HZ_DIV8(0)         )
#define INIT_CKSET01_MASTER_CK (0 & ~MASTER_CK_USE_MAIN          \
                                & ~MASTER_CK_USE_SLOW          \
                                |  MASTER_CK_USE_PLLA          \
                                & ~MASTER_CK_USE_PLLB          \
                                & ~MASTER_CK_USE_PLLU          \
                                |  MASTER_CK_PROC_PRESCALER(1) \
                                |  MASTER_CK_BUS_MDIV(2)       )
#define INIT_CKSET01_PLL    (  PLL_PRE_DIV(1) \
                          |  PLL_MUL(25)    \
                          & ~PLL_POST_DIV2  )
#define INIT_CKSET01_SLOW_CK (  SLOW_CK_USE_RC      \
                            & ~SLOW_CK_USE_XTAL   \
                            & ~SLOW_CK_USE_EXTCLK \
                            | SLOW_CK_EXT_FREQ(0) )
#define INIT_CKSET01_EFC ( EFC_EFC0_WS(0x8) \
                       | EFC_EFC1_WS(0x8) )

// ----------------------------------------------------------------------------
//Master clock configured on bypassed oscillator (external clock) / no PLL
#define INIT_CKSET02_TAG (TAG_TAG(0xC10C)|TAG_IDX(0x2))
#define INIT_CKSET02_MAIN_CK ( MAIN_CK_RC_FREQ_MHZ_DIV2(0) \
                              & ~MAIN_CK_USE_XTAL          \
                              |  MAIN_CK_USE_EXTCLK        \
                              |  EXT_FREQ_HZ_DIV8(1250000) )
#define INIT_CKSET02_MASTER_CK (0 | MASTER_CK_USE_MAIN           \
                                  & ~MASTER_CK_USE_SLOW          \
                                  & ~MASTER_CK_USE_PLLA          \
                                  & ~MASTER_CK_USE_PLLB          \
                                  & ~MASTER_CK_USE_PLLU          \
                                  |  MASTER_CK_PROC_PRESCALER(1) \
                                  |  MASTER_CK_BUS_MDIV(1)       )
#define INIT_CKSET02_PLL  (  PLL_PRE_DIV(1) \
                          |  PLL_MUL(25)    \
                          & ~PLL_POST_DIV2  )
#define INIT_CKSET02_SLOW_CK (  SLOW_CK_USE_RC    \
                            & ~SLOW_CK_USE_XTAL   \
                            & ~SLOW_CK_USE_EXTCLK \
                            | SLOW_CK_EXT_FREQ(0) )
#define INIT_CKSET02_EFC ( EFC_EFC0_WS(0x0) \
                       | EFC_EFC1_WS(0x0) )

// ----------------------------------------------------------------------------
#define INIT_CKSET03_TAG        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET03_MAIN_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET03_MASTER_CK  INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET03_PLL        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET03_SLOW_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET03_EFC        INIT_CKSET_RESERVED_PATTERN

// ----------------------------------------------------------------------------
#define INIT_CKSET04_TAG        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET04_MAIN_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET04_MASTER_CK  INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET04_PLL        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET04_SLOW_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET04_EFC        INIT_CKSET_RESERVED_PATTERN

// ----------------------------------------------------------------------------
#define INIT_CKSET05_TAG        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET05_MAIN_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET05_MASTER_CK  INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET05_PLL        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET05_SLOW_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET05_EFC        INIT_CKSET_RESERVED_PATTERN

// ----------------------------------------------------------------------------
#define INIT_CKSET06_TAG        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET06_MAIN_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET06_MASTER_CK  INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET06_PLL        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET06_SLOW_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET06_EFC        INIT_CKSET_RESERVED_PATTERN

// ----------------------------------------------------------------------------
#define INIT_CKSET07_TAG        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET07_MAIN_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET07_MASTER_CK  INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET07_PLL        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET07_SLOW_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET07_EFC        INIT_CKSET_RESERVED_PATTERN

// ----------------------------------------------------------------------------
#define INIT_CKSET08_TAG        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET08_MAIN_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET08_MASTER_CK  INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET08_PLL        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET08_SLOW_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET08_EFC        INIT_CKSET_RESERVED_PATTERN

// ----------------------------------------------------------------------------
#define INIT_CKSET09_TAG        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET09_MAIN_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET09_MASTER_CK  INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET09_PLL        INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET09_SLOW_CK    INIT_CKSET_RESERVED_PATTERN
#define INIT_CKSET09_EFC        INIT_CKSET_RESERVED_PATTERN



#endif //_PRG_SRAM_INIT_65108_H

