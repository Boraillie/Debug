/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : prg_tests_list.h
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
*  65103 CANOPUS    |   ok   |  ok   |
*  65100 SIRIUS     |        |       |
*  92U01 SAMA5D2    |        |       |
*                   ииииииииииииииииии
*----------------------------------------------------------------------------
*/
#ifndef _PRG_TESTS_LIST_H
#define _PRG_TESTS_LIST_H



// -- Tests list depending on product ---------------------------------------
#if (CANOPUS==1)
  #include "products_settings/prg_tests_list_65103.h"
#elif (CAPELLA==1)
  #include "products_settings/prg_tests_list_65108.h"
#elif (SAMA5D2==1)
  #include "products_settings/prg_tests_list_92U03.h"
#elif (SAM9X6==1)
  #include "products_settings/prg_tests_list_SAM9X6.h"
//---- Not implemented ---------------------------------------------------------
#else
  #error PRG for test library does not support the specified device.
#endif


/*
// -- Test identifiers --------------------------------------------------------
#define PRG_ID00_TEST   prg_reserved_test
#define PRG_ID01_TEST   prg_low_power_idd_test
#define PRG_ID02_TEST   prg_dynamic_idd_test
#define PRG_ID03_TEST   prg_rc_measure_test
#define PRG_ID04_TEST   prg_DAC12_test
#define PRG_ID05_TEST   prg_AFE_test
//#define PRG_ID06_TEST   prg_user06_test
//...
//#define PRG_ID30_TEST   prg_user30_test
#define PRG_ID31_TEST   prg_non_reg_test
// ----------------------------------------------------------------------------
*/

/*
// -- Prototypes --------------------------------------------------------------
extern _PRG_TEST_FUNC_DECLARE(prg_reserved_test);
extern _PRG_TEST_FUNC_DECLARE(prg_low_power_idd_test);
extern _PRG_TEST_FUNC_DECLARE(prg_dynamic_idd_test);
extern _PRG_TEST_FUNC_DECLARE(prg_rc_measure_test);
extern _PRG_TEST_FUNC_DECLARE(prg_DAC12_test);
//extern _PRG_TEST_FUNC_DECLARE(prg_AFE_test);
extern _PRG_TEST_RAMFUNC_DECLARE(prg_AFE_test);
//...
extern _PRG_TEST_FUNC_DECLARE(prg_non_reg_test);
// ----------------------------------------------------------------------------
*/


// -- Test identifiers definitions --------------------------------------------
//#define PRG_TEST_ID_RESERVED_TEST (0x00)
// ----------------------------------------------------------------------------

// -- Misc definitions --------------------------------------------------------
// ----------------------------------------------------------------------------


#endif //_PRG_TESTS_LIST_H