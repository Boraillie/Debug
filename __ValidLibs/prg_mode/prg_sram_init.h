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
#ifndef _PRG_SETTINGS_H
#define _PRG_SETTINGS_H

/*
// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"

#include "v_clocks_management.h"
*/

#if (CANOPUS==1)
  #include "products_settings/prg_sram_init_65103.h"
#elif (CAPELLA==1)
  #include "products_settings/prg_sram_init_65108.h"
#elif (SAMA5D2==1)
  #include "products_settings/prg_sram_init_92U03.h"
#elif (SAM9X6==1)
  #include "products_settings/prg_sram_init_SAM9X6.h"
//---- Not implemented ---------------------------------------------------------
#else
  #error PRG for test library does not support the specified device.
#endif


#endif //_PRG_SETTINGS_H

