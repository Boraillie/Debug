/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : prg_tests_list.c
* Object              : 
*
* Creation            : ERr / Jan 2015
*----------------------------------------------------------------------------
*/
/*---------------------------------------------------------------------------
*----------------------------------------------------------------------------
* Product compliance (tested):
*                   __________________
*                   | Build  |  Exec |
*  63917 SAMG51     |        |       |
*  63918 SAMG53/G54 |        |       |
*  65105 SAMG55     |        |       |
*  65103 CANOPUS    |        |       |
*  65100 SIRIUS     |        |       |
*  92U01 SAMA5D2    |        |       |
*                   ииииииииииииииииии
*----------------------------------------------------------------------------
*/



// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"

// ---- Libraries -----------------------------------------------------------
#include "prg_mode\prg_memory_map.h"
#include "prg_mode\prg_test_tools.h"
#include "prg_mode\prg_monitor.h"
#include "prg_test_tools.h"

//---------------------------------------------------------------------------
#include "prg_mode\prg_tests_list.h"


// -- Test functions prototype definition -------------------------------------
#include "prg_test_tools.h"
// -- Prototypes --------------------------------------------------------------
// The following list covers all test that were developed or specified for 
// all products supporting PRG mode.
// Depending on the product, each test can be implemented or not.
// For each product, a dedicated header file exists: prg_tests_list_xxxxx.h
// ----------------------------------------------------------------------------
extern _PRG_TEST_FUNC_DECLARE(prg_reserved_test);
extern _PRG_TEST_FUNC_DECLARE(prg_low_power_idd_test);
extern _PRG_TEST_FUNC_DECLARE(prg_dynamic_idd_test);
extern _PRG_TEST_FUNC_DECLARE(prg_rc_measure_test);
extern _PRG_TEST_FUNC_DECLARE(prg_DAC12_test);
//extern _PRG_TEST_FUNC_DECLARE(prg_AFE_test);
extern _PRG_TEST_RAMFUNC_DECLARE(prg_AFE_test);
extern _PRG_TEST_RAMFUNC_DECLARE(prg_flash_at_speed_test);
extern _PRG_TEST_FUNC_DECLARE(prg_chipid_test);
extern _PRG_TEST_FUNC_DECLARE(prg_dc_test);
//...
extern _PRG_TEST_FUNC_DECLARE(prg_non_reg_test);
// ----------------------------------------------------------------------------



_PRG_TEST_FUNC_DECLARE(prg_default_test);
#ifndef PRG_ID00_TEST
  #define PRG_ID00_TEST prg_default_test
#endif
#ifndef PRG_ID01_TEST
  #define PRG_ID01_TEST prg_default_test
#endif
#ifndef PRG_ID02_TEST
  #define PRG_ID02_TEST prg_default_test
#endif
#ifndef PRG_ID03_TEST
  #define PRG_ID03_TEST prg_default_test
#endif
#ifndef PRG_ID04_TEST
  #define PRG_ID04_TEST prg_default_test
#endif
#ifndef PRG_ID05_TEST
  #define PRG_ID05_TEST prg_default_test
#endif
#ifndef PRG_ID06_TEST
  #define PRG_ID06_TEST prg_default_test
#endif
#ifndef PRG_ID07_TEST
  #define PRG_ID07_TEST prg_default_test
#endif
#ifndef PRG_ID08_TEST
  #define PRG_ID08_TEST prg_default_test
#endif
#ifndef PRG_ID09_TEST
  #define PRG_ID09_TEST prg_default_test
#endif
#ifndef PRG_ID10_TEST
  #define PRG_ID10_TEST prg_default_test
#endif
#ifndef PRG_ID11_TEST
  #define PRG_ID11_TEST prg_default_test
#endif
#ifndef PRG_ID12_TEST
  #define PRG_ID12_TEST prg_default_test
#endif
#ifndef PRG_ID13_TEST
  #define PRG_ID13_TEST prg_default_test
#endif
#ifndef PRG_ID14_TEST
  #define PRG_ID14_TEST prg_default_test
#endif
#ifndef PRG_ID15_TEST
  #define PRG_ID15_TEST prg_default_test
#endif
#ifndef PRG_ID16_TEST
  #define PRG_ID16_TEST prg_default_test
#endif
#ifndef PRG_ID17_TEST
  #define PRG_ID17_TEST prg_default_test
#endif
#ifndef PRG_ID18_TEST
  #define PRG_ID18_TEST prg_default_test
#endif
#ifndef PRG_ID19_TEST
  #define PRG_ID19_TEST prg_default_test
#endif
#ifndef PRG_ID20_TEST
  #define PRG_ID20_TEST prg_default_test
#endif
#ifndef PRG_ID21_TEST
  #define PRG_ID21_TEST prg_default_test
#endif
#ifndef PRG_ID22_TEST
  #define PRG_ID22_TEST prg_default_test
#endif
#ifndef PRG_ID23_TEST
  #define PRG_ID23_TEST prg_default_test
#endif
#ifndef PRG_ID24_TEST
  #define PRG_ID24_TEST prg_default_test
#endif
#ifndef PRG_ID25_TEST
  #define PRG_ID25_TEST prg_default_test
#endif
#ifndef PRG_ID26_TEST
  #define PRG_ID26_TEST prg_default_test
#endif
#ifndef PRG_ID27_TEST
  #define PRG_ID27_TEST prg_default_test
#endif
#ifndef PRG_ID28_TEST
  #define PRG_ID28_TEST prg_default_test
#endif
#ifndef PRG_ID29_TEST
  #define PRG_ID29_TEST prg_default_test
#endif
#ifndef PRG_ID30_TEST
  #define PRG_ID30_TEST prg_default_test
#endif
#ifndef PRG_ID31_TEST
  #define PRG_ID31_TEST prg_default_test
#endif
//---------------------------------------------------------------------------


// ---- Global variables ----------------------------------------------------
extern unsigned char restore_clocks_after_test; //prg_monitor.c
//----------------------------------------------------------------------------
// 32 tests available - can be extended up to 256
const prg_test_func _prg_test_table_[PRG_MAX_TEST_IDENTIFIERS] =
{
  PRG_ID00_TEST,
  PRG_ID01_TEST,
  PRG_ID02_TEST,
  PRG_ID03_TEST,
  PRG_ID04_TEST,
  PRG_ID05_TEST,
  PRG_ID06_TEST,
  PRG_ID07_TEST,
  PRG_ID08_TEST,
  PRG_ID09_TEST,
  PRG_ID10_TEST,
  PRG_ID11_TEST,
  PRG_ID12_TEST,
  PRG_ID13_TEST,
  PRG_ID14_TEST,
  PRG_ID15_TEST,
  PRG_ID16_TEST,
  PRG_ID17_TEST,
  PRG_ID18_TEST,
  PRG_ID19_TEST,
  PRG_ID20_TEST,
  PRG_ID21_TEST,
  PRG_ID22_TEST,
  PRG_ID23_TEST,
  PRG_ID24_TEST,
  PRG_ID25_TEST,
  PRG_ID26_TEST,
  PRG_ID27_TEST,
  PRG_ID28_TEST,
  PRG_ID20_TEST,
  PRG_ID30_TEST,
  PRG_ID31_TEST
};


//-- The following test were already affected an identifer but may not be --//
//-- implemented in the current workspace                                 --//
//--------------------------------------------------------------------------//
//#pragma weak  prg_reserved_test      = prg_default_test                   //
#pragma weak  prg_low_power_idd_test  = prg_default_test                    //
#pragma weak  prg_dynamic_idd_test    = prg_default_test                    //
#pragma weak  prg_rc_measure_test     = prg_default_test                    //
#pragma weak  prg_DAC12_test          = prg_default_test                    //
#pragma weak  prg_AFE_test            = prg_default_test                    //
#pragma weak  prg_flash_at_speed_test = prg_default_test                    //
#pragma weak  prg_chipid_test         = prg_default_test                    //
#pragma weak  prg_dc_test             = prg_default_test                    //
// -------------------------------------------------------------------------//
#pragma weak  prg_non_reg_test       = prg_default_test                     //
//--------------------------------------------------------------------------//


//----------------------------------------------------------------------------
// default function: will be executed for any non affected test identifier
#pragma location = ".prg_monitor"
_PRG_TEST_FUNC_DECLARE(prg_default_test)
{
#warning To add: send diagnosis character : Unknown test identifier
  while(1);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// reserved function: used to change prg monitor main loop clock settings
#pragma location = ".prg_monitor"
_PRG_TEST_FUNC_DECLARE(prg_reserved_test)
{
  //test used to apply clock settings to monitor itself
  restore_clocks_after_test=0;
  return(0);
}
//----------------------------------------------------------------------------


