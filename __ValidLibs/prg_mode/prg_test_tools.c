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


#include "prg_test_tools.h"



//----------------------------------------------------------------------------
void reset_test_results(unsigned char test_idx, uint32_t pattern32)
{
 uint32_t i;

  // Fill results area with 32 bits words (keep result0=test descriptor)
  for(i=1;i<TEST_MAX_RESULTS32;++i){
    TEST_RESULT(test_idx,i)=pattern32;
    }
}
//----------------------------------------------------------------------------
