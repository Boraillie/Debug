/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : prg_sram_init_xxxxx.h
* Object              : product relative PRG definitions
*
* Creation            : ERr / 2017
*----------------------------------------------------------------------------
*/
//#ifndef _PRG_SRAM_INIT_65108_H
//#define _PRG_SRAM_INIT_65108_H

FILE TO DELETE!!!!!!!!!!!!!!!!!!!


// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"

#include "v_clocks_management.h"
#include "prg_sram_init_65108.h"
#include "prg_mode\prg_memory_map.h"


// -- Clocks settings ---------------------------------------------------------
#pragma location = ".prg_sram_init" //used by prg mode linker
const Clk_Setting CkSettingsInit[PRG_MAX_CLK_SETS]=
{
  {INIT_CKSET00_TAG,INIT_CKSET00_MAIN_CK,INIT_CKSET00_MASTER_CK,INIT_CKSET00_PLL,INIT_CKSET00_SLOW_CK,INIT_CKSET00_EFC,INIT_CKSET_RESERVED_PATTERN,INIT_CKSET_RESERVED_PATTERN},
  {INIT_CKSET01_TAG,INIT_CKSET01_MAIN_CK,INIT_CKSET01_MASTER_CK,INIT_CKSET01_PLL,INIT_CKSET01_SLOW_CK,INIT_CKSET01_EFC,INIT_CKSET_RESERVED_PATTERN,INIT_CKSET_RESERVED_PATTERN},
  {INIT_CKSET02_TAG,INIT_CKSET02_MAIN_CK,INIT_CKSET02_MASTER_CK,INIT_CKSET02_PLL,INIT_CKSET02_SLOW_CK,INIT_CKSET02_EFC,INIT_CKSET_RESERVED_PATTERN,INIT_CKSET_RESERVED_PATTERN},
  {INIT_CKSET03_TAG,INIT_CKSET03_MAIN_CK,INIT_CKSET03_MASTER_CK,INIT_CKSET03_PLL,INIT_CKSET03_SLOW_CK,INIT_CKSET03_EFC,INIT_CKSET_RESERVED_PATTERN,INIT_CKSET_RESERVED_PATTERN},
  {INIT_CKSET04_TAG,INIT_CKSET04_MAIN_CK,INIT_CKSET04_MASTER_CK,INIT_CKSET04_PLL,INIT_CKSET04_SLOW_CK,INIT_CKSET04_EFC,INIT_CKSET_RESERVED_PATTERN,INIT_CKSET_RESERVED_PATTERN},
  {INIT_CKSET05_TAG,INIT_CKSET05_MAIN_CK,INIT_CKSET05_MASTER_CK,INIT_CKSET05_PLL,INIT_CKSET05_SLOW_CK,INIT_CKSET05_EFC,INIT_CKSET_RESERVED_PATTERN,INIT_CKSET_RESERVED_PATTERN},
  {INIT_CKSET06_TAG,INIT_CKSET06_MAIN_CK,INIT_CKSET06_MASTER_CK,INIT_CKSET06_PLL,INIT_CKSET06_SLOW_CK,INIT_CKSET06_EFC,INIT_CKSET_RESERVED_PATTERN,INIT_CKSET_RESERVED_PATTERN},
  {INIT_CKSET07_TAG,INIT_CKSET07_MAIN_CK,INIT_CKSET07_MASTER_CK,INIT_CKSET07_PLL,INIT_CKSET07_SLOW_CK,INIT_CKSET07_EFC,INIT_CKSET_RESERVED_PATTERN,INIT_CKSET_RESERVED_PATTERN},
  {INIT_CKSET08_TAG,INIT_CKSET08_MAIN_CK,INIT_CKSET08_MASTER_CK,INIT_CKSET08_PLL,INIT_CKSET08_SLOW_CK,INIT_CKSET08_EFC,INIT_CKSET_RESERVED_PATTERN,INIT_CKSET_RESERVED_PATTERN},
  {INIT_CKSET09_TAG,INIT_CKSET09_MAIN_CK,INIT_CKSET09_MASTER_CK,INIT_CKSET09_PLL,INIT_CKSET09_SLOW_CK,INIT_CKSET09_EFC,INIT_CKSET_RESERVED_PATTERN,INIT_CKSET_RESERVED_PATTERN}
};



