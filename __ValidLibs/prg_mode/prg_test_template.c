/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : prg_test_template.c
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
*  65103 CANOPUS    |  OK    |  OK   |
*  65100 SIRIUS     |        |       |
*  92U01 SAMA5D2    |        |       |
*                   ииииииииииииииииии
*----------------------------------------------------------------------------
*/
// ---- Test implementation ----------------------------------------------------
#warning This is a template test: you can rename this file and insert your code.
// - Select the appropriate function name in prg_tests_list_xxxxx.h (product dependant)
// - Rename this file and update the _PRG_TEST_FUNC_DECLARE(...) call below
// - Add the file to the compilation list (makefile, IAR project...)
// - Insert your code
// - 
// - If the function name does not exist in the product prg_tests_list header,
//   it may be added to the supported tests list:
//         => update prg_tests_list_xxxxx.h
//         => update prg_tests_list.c
//         => contact VDE admin to propagate updates in the trunk
// -----------------------------------------------------------------------------


// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"

// ---- PRG mode specific includes -------------------------------------------
#include "prg_mode\prg_monitor.h"
#include "prg_mode\prg_memory_map.h"
#include "prg_test_tools.h"
//#include "prg_test_template.h"




// ---- Local definitions: visibility is this file only ----------------------
#define CURRENT_TEST_NB_PARAMS  (TEST_MAX_PARAM32)   //to set according to test behavior
//CURRENT_TEST_NB_PARAM always>0 because param0=in_test_descriptor is included

#define CURRENT_TEST_NB_RESULTS (TEST_MAX_RESULTS32) //to set according to test behavior
#define CURRENT_TEST_IDENTIFIER (0x1F) //to set according to prg_test_list.h
//---------------------------------------------------------------------------

// ---- Global variables ----------------------------------------------------
extern unsigned int  MCK_clock_speed; //main.c
//---------------------------------------------------------------------------


// ---- Peripherals (ASF drivers) includes ----------------------------------
//#include "drivers/pio/pio.h"

// ---- Global variables ----------------------------------------------------
//---------------------------------------------------------------------------

// ---- Test main function ---------------------------------------------------
//----------------------------------------------------------------------------
//uint32_t prg_non_reg_test(unsigned char current_test_idx, unsigned char clk_set_idx)
//_PRG_TEST_FUNC_DECLARE(prg_test_template)
_PRG_TEST_FUNC_DECLARE(_replace_this_with_test_function_name_)
{
 uint32_t  i,j;
 uint32_t  in_test_descriptor; //=test_param0
 uint32_t  test_parameter1,test_parameter2;
 uint32_t* large_results_array;
 uint32_t  large_results_max_size32;
 
  // Write in RESULT0 the actual test number of parameters and results
  SET_CURRENT_TEST_NB_RESULTS(CURRENT_TEST_NB_RESULTS); //field in RESULT0
  SET_CURRENT_TEST_NB_PARAMS(CURRENT_TEST_NB_PARAMS);   //field in RESULT0
  
  // Retrieve test parameters
  in_test_descriptor = CURRENT_TEST_PARAMETER(0);
  test_parameter1 = CURRENT_TEST_PARAMETER(1);
  test_parameter2 = CURRENT_TEST_PARAMETER(2);

  // Shared buffer init
  large_results_array = PRG_SHARED_BUFFER_ADDR;
  large_results_max_size32 = PRG_SHARED_BUFFER_SIZE/4;

  // RAZ on current test results area
  RESET_CURRENT_TEST_RESULTS(0x00000000);
//#warning debug code
//  RESET_CURRENT_TEST_RESULTS(0xCAFEDEDE);
//#warning debug code
  
  
  //////////////////////////////////////////////////////////////////////////////
  // Test body /////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  
  if(test_parameter1==0){ /////////////////////////////// non reg mode 0//
    // Copy all parameters and selected clock settings in shared buffer
    for(i=0;i<CURRENT_TEST_NB_PARAMS;++i) // parameters
      {large_results_array[i]=CURRENT_TEST_PARAMETER(i);}
    for(j=0;j++<=CLK_SET_USED_PARAM32;++i) // clock setting fields
      {large_results_array[i]=CLK_SET_PARAMETER(clk_set_idx,j);}
      //{large_results_array[i]=CURRENT_CLOCK_SETTING(j);}
    } //////////////////////////////////////////// end of tenon reg mode 0 //
  
  else{ //////////////////////////////////////////////// non reg mode 1 //
    // Shared buffer fill (repeat n times depending on test parameters)
    for(j=0;j<test_parameter1;++j){
      for(i=0;i<test_parameter2;++i){
        large_results_array[i]=(i<<24)|((i+1)<<16)|((i+2)<<8)|(i+3);
        }
      }
    } /////////////////////////////////////////// end of non reg mode 1 //

  
  //////////////////////////////////////////////// common non reg //
  // Fill results area with 32 bits words (incremental pattern)
    for(i=2;i<TEST_MAX_RESULTS32;++i) //result
      {CURRENT_TEST_RESULT(i)=(i<<24)|(i<<16)|(i<<8)|(i);}
  /////////////////////////////////////////// //// end of common non reg //


  //////////////////////////////////////////////////////////////////////////////
  // EOF Test body /////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////

  return(CURRENT_TEST_RESULT(0));
}
//----------------------------------------------------------------------------



