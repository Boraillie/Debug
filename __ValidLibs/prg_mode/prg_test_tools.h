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
* Object              : 
*
* Creation            : 
*----------------------------------------------------------------------------
*/

#ifndef _PRG_TEST_TOOLS_H
#define _PRG_TEST_TOOLS_H


// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"

// ---- Specific includes ---------------------------------------------------
#include "prg_mode\prg_memory_map.h"




// -- Test functions prototype definition -------------------------------------
typedef uint32_t( *prg_test_func )( unsigned char, unsigned char );
#define _PRG_TEST_FUNC_DECLARE(function_name) uint32_t function_name(unsigned char current_test_idx, unsigned char clk_set_idx)
#define _PRG_TEST_RAMFUNC_DECLARE(function_name) __ramfunc uint32_t function_name(unsigned char current_test_idx, unsigned char clk_set_idx)
// ----------------------------------------------------------------------------

// -- Current clock setting access --------------------------------------------
// -- (to be used in test function only ---------------------------------------
#define CURRENT_CLOCK_SETTING(param_number) (CLK_SET_PARAMETERS(clk_set_idx,(param_number)))
#define CURRENT_CLOCK_SETTING_PT32          (CLK_SET_PARAMETERS_PT32(clk_set_idx))
#define CURRENT_CLOCK_SETTING_PT8           (CLK_SET_PARAMETERS_PT8(clk_set_idx))
// ----------------------------------------------------------------------------

// -- Current test parameters access ------------------------------------------
// -- (to be used in test function only ---------------------------------------
#define CURRENT_TEST_PARAMETER(param_number) (TEST_PARAMETER(current_test_idx,(param_number)))
#define CURRENT_TEST_PARAMETERS_PT32         (TEST_PARAMETERS_PT32(current_test_idx))
#define CURRENT_TEST_PARAMETERS_PT8          (TEST_PARAMETERS_PT8(current_test_idx))
// ----------------------------------------------------------------------------

// -- Current test results access ---------------------------------------------
// -- (to be used in test function only ---------------------------------------
#define CURRENT_TEST_RESULT(res_number) (TEST_RESULT(current_test_idx,(res_number)))
#define CURRENT_TEST_RESULTS_PT32       (TEST_RESULTS_PT32(current_test_idx))
#define CURRENT_TEST_RESULTS_PT8        (TEST_RESULTS_PT8(current_test_idx))

#define SET_CURRENT_TEST_NB_PARAMS(nb_arg) CURRENT_TEST_RESULT(0)=(CURRENT_TEST_RESULT(0)&(0xFFFF00FF))|((nb_arg)<<8)
#define SET_CURRENT_TEST_NB_RESULTS(nb_res) CURRENT_TEST_RESULT(0)=(CURRENT_TEST_RESULT(0)&(0xFFFFFF00))|(nb_res)
#define RESET_CURRENT_TEST_RESULTS(pattern32) reset_test_results(current_test_idx,pattern32)
// ----------------------------------------------------------------------------


// -- Prototypes --------------------------------------------------------------
//extern void set_test_nb_results(unsigned char test_idx, uint8_t nb_results);
extern void reset_test_results(unsigned char test_idx, uint32_t pattern32);
// ----------------------------------------------------------------------------


#endif //_PRG_TEST_TOOLS_H

