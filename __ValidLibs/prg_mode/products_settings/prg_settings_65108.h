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
#ifndef _PRG_SETTINGS_65108_H
#define _PRG_SETTINGS_65108_H


// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"

#include "v_clocks_management.h"


// ---- Processor cycles counter management ---------------------------------
extern uint32_t proc_cycles_count; // prg_monitor.c
#define INIT_CYCLE_COUNTER  (proc_cycles_count=(DWT->CYCCNT))
#define GET_CYCLE_COUNT     (proc_cycles_count=(DWT->CYCCNT)-proc_cycles_count)
#warning cycle counter management still to implement on A5!!!

// -- Clocks settings ---------------------------------------------------------
//Reserve clock set 0 for PRG monitor default setting
//Master clock is configured on fastest RC available (no PLL)
#define MONITOR_CKSET_TAG (TAG_TAG(0xC10C)|TAG_IDX(0x0))
#define MONITOR_CKSET_MAIN_CK ( MAIN_CK_RC_FREQ_MHZ_DIV2(6) \
                              & ~MAIN_CK_USE_XTAL           \
                              & ~MAIN_CK_USE_EXTCLK         \
                              | EXT_FREQ_HZ_DIV8(0)         )
#define MONITOR_CKSET_MASTER_CK ( MASTER_CK_USE_MAIN           \
                                & ~MASTER_CK_USE_SLOW          \
                                & ~MASTER_CK_USE_PLLA          \
                                & ~MASTER_CK_USE_PLLB          \
                                & ~MASTER_CK_USE_PLLU          \
                                |  MASTER_CK_PROC_PRESCALER(1) \
                                |  MASTER_CK_BUS_MDIV(1)       )
#define MONITOR_CKSET_PLL ( PLL_PRE_DIV(1) \
                          | PLL_MUL(20)    \
                          | PLL_POST_DIV2  )
#define MONITOR_CKSET_SLOW_CK ( SLOW_CK_USE_RC      \
                              & ~SLOW_CK_USE_XTAL   \
                              & ~SLOW_CK_USE_EXTCLK \
                              | SLOW_CK_EXT_FREQ(0) )
#define MONITOR_CKSET_EFC ( EFC_EFC0_WS(0x0) \
                          | EFC_EFC1_WS(0x0) )

/*
//#define PRG_MONITOR_MOR_VAL 0x0637ff28
#define PRG_MONITOR_MOR_VAL (0&(~(CKGR_MOR_MOSCXTEN)) & (~(CKGR_MOR_MOSCXTBY)) \
                              &(~(CKGR_MOR_WAITMODE)) | ( (CKGR_MOR_MOSCRCEN)) \
                              |( (CKGR_MOR_MOSCRCF_12_MHz))                    \
                              |( (CKGR_MOR_MOSCXTST(0xFF)))                    \
                              |( (CKGR_MOR_KEY_PASSWD))                        \
                              &(~(CKGR_MOR_MOSCSEL)) |  ( (CKGR_MOR_CFDEN))    \
                              |( (CKGR_MOR_XT32KFME))                          )
#define PRG_MONITOR_FLASH_WS (0)
*/
// ----------------------------------------------------------------------------
//Master clock configured at 150MHz with processor at 300MHz
#define FAST_CKSET_TAG (TAG_TAG(0xC10C)|TAG_IDX(0x1))
#define FAST_CKSET_MAIN_CK ( MAIN_CK_RC_FREQ_MHZ_DIV2(6) \
                              & ~MAIN_CK_USE_XTAL           \
                              & ~MAIN_CK_USE_EXTCLK         \
                              | EXT_FREQ_HZ_DIV8(0)         )
#define FAST_CKSET_MASTER_CK (0 & ~MASTER_CK_USE_MAIN          \
                                & ~MASTER_CK_USE_SLOW          \
                                |  MASTER_CK_USE_PLLA          \
                                & ~MASTER_CK_USE_PLLB          \
                                & ~MASTER_CK_USE_PLLU          \
                                |  MASTER_CK_PROC_PRESCALER(1) \
                                |  MASTER_CK_BUS_MDIV(2)       )
#define FAST_CKSET_PLL    (  PLL_PRE_DIV(1) \
                          |  PLL_MUL(25)    \
                          & ~PLL_POST_DIV2  )
#define FAST_CKSET_SLOW_CK (  SLOW_CK_USE_RC      \
                            & ~SLOW_CK_USE_XTAL   \
                            & ~SLOW_CK_USE_EXTCLK \
                            | SLOW_CK_EXT_FREQ(0) )
#define FAST_CKSET_EFC ( EFC_EFC0_WS(0x8) \
                       | EFC_EFC1_WS(0x8) )

/*
//#define PRG_FAST_MOR_VAL 0x0637ff28
#define PRG_FAST_MOR_VAL (0&(~(CKGR_MOR_MOSCXTEN)) & (~(CKGR_MOR_MOSCXTBY)) \
                              &(~(CKGR_MOR_WAITMODE)) | ( (CKGR_MOR_MOSCRCEN)) \
                              |( (CKGR_MOR_MOSCRCF_12_MHz))                    \
                              |( (CKGR_MOR_MOSCXTST(0xFF)))                    \
                              |( (CKGR_MOR_KEY_PASSWD))                        \
                              &(~(CKGR_MOR_MOSCSEL)) |  ( (CKGR_MOR_CFDEN))    \
                              |( (CKGR_MOR_XT32KFME))                          )
#define PRG_FAST_FLASH_WS (8)
*/
// ----------------------------------------------------------------------------


// Monitor serial link settings -----------------------------------------------
//#define SSPI_WRAPPER_SPI_IDX 0               // can be <void>, 0, 1... comment out for pure software SSPI
//#define SPI_MODE             SPI_MODE_SLAVE  // SPI_MODE_MASTER or SPI_MODE_SLAVE ; used when SSPI_WRAPPER_SPI_IDX is defined
//#define SPI_SPCK_FREQ        115200          // meaningful only when SPI_MODE==SPI_MODE_MASTER
// ----------------------------------------------------------------------------


#endif //_PRG_SETTINGS_65108_H

