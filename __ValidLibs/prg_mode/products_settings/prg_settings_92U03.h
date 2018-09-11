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
#ifndef _PRG_SETTINGS_92U03_H
#define _PRG_SETTINGS_92U03_H


// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"

#include "v_clocks_management.h"


// ---- Processor cycles counter management ---------------------------------
extern uint32_t proc_cycles_count; // prg_monitor.c
#define INIT_CYCLE_COUNTER (proc_cycles_count=(PMN_Read_Cycles()))//M7: (proc_cycles_count=(DWT->CYCCNT))
#define GET_CYCLE_COUNT  (proc_cycles_count=(PMN_Read_Cycles())-proc_cycles_count)//0 //M7: (proc_cycles_count=(DWT->CYCCNT)-proc_cycles_count)
#warning cycle counter management still to implement on A5!!!


// -- Clocks settings ---------------------------------------------------------
//Reserve clock set 0 for PRG monitor default setting
//Master clock is configured on fastest RC available (no PLL)
#define MONITOR_CKSET_TAG (TAG_TAG(0xC10Cu)|TAG_IDX(0x0u))
#define MONITOR_CKSET_MAIN_CK ( MAIN_CK_RC_FREQ_MHZ_DIV2(6u) \
                              & ~MAIN_CK_USE_XTAL           \
                              & ~MAIN_CK_USE_EXTCLK         \
                              | EXT_FREQ_HZ_DIV8(0)         )
#define MONITOR_CKSET_MASTER_CK ( MASTER_CK_USE_MAIN           \
                                & ~MASTER_CK_USE_SLOW          \
                                & ~MASTER_CK_USE_PLLA          \
                                & ~MASTER_CK_USE_PLLB          \
                                & ~MASTER_CK_USE_PLLU          \
                                |  MASTER_CK_PROC_PRESCALER(1u) \
                                |  MASTER_CK_BUS_MDIV(1u)       )
#define MONITOR_CKSET_PLL ( PLL_PRE_DIV(1u) \
                          | PLL_MUL(20u)    \
                          | PLL_POST_DIV2  )
#define MONITOR_CKSET_SLOW_CK ( SLOW_CK_USE_RC      \
                              & ~SLOW_CK_USE_XTAL   \
                              & ~SLOW_CK_USE_EXTCLK \
                              | SLOW_CK_EXT_FREQ(0u) )
// Used on MCUs only
#define MONITOR_CKSET_EFC (0xCCCCCCCCu)
// ----------------------------------------------------------------------------
//Master clock configured at 150MHz with processor at 450MHz (PLL @900MHz)
#define FAST_CKSET_TAG (TAG_TAG(0xC10Cu)|TAG_IDX(0x1u))
#define FAST_CKSET_MAIN_CK ( MAIN_CK_RC_FREQ_MHZ_DIV2(6u) \
                              & ~MAIN_CK_USE_XTAL           \
                              & ~MAIN_CK_USE_EXTCLK         \
                              | EXT_FREQ_HZ_DIV8(0u)         )
#define FAST_CKSET_MASTER_CK (0u & ~MASTER_CK_USE_MAIN          \
                                & ~MASTER_CK_USE_SLOW          \
                                |  MASTER_CK_USE_PLLA          \
                                & ~MASTER_CK_USE_PLLB          \
                                & ~MASTER_CK_USE_PLLU          \
                                |  MASTER_CK_PROC_PRESCALER(2u) \
                                |  MASTER_CK_BUS_MDIV(3u)       )
#define FAST_CKSET_PLL    (  PLL_PRE_DIV(1u) \
                          |  PLL_MUL(75u)    \
                          & ~PLL_POST_DIV2  )
#define FAST_CKSET_SLOW_CK (  SLOW_CK_USE_RC      \
                            & ~SLOW_CK_USE_XTAL   \
                            & ~SLOW_CK_USE_EXTCLK \
                            | SLOW_CK_EXT_FREQ(0u) )
// Used on MCUs only
#define FAST_CKSET_EFC (0xCCCCCCCCu)
// ----------------------------------------------------------------------------


// Monitor serial link settings -----------------------------------------------
//#define SSPI_WRAPPER_SPI_IDX 0               // can be <void>, 0, 1... comment out for pure software SSPI
//#define SPI_MODE             SPI_MODE_SLAVE  // SPI_MODE_MASTER or SPI_MODE_SLAVE ; used when SSPI_WRAPPER_SPI_IDX is defined
//#define SPI_SPCK_FREQ        115200          // meaningful only when SPI_MODE==SPI_MODE_MASTER
// ----------------------------------------------------------------------------


#endif //_PRG_SETTINGS_92U03_H

