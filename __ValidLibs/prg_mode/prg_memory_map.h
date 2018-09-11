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
#ifndef _PRG_MEMORY_MAP_H
#define _PRG_MEMORY_MAP_H



// -- Memory mapping ----------------------------------------------------------
#define PRG_INFO_OFFSET     (0x0)
#define PRG_INFO_MAX_WORD32 (0x40)
#define PRG_INFO_MAX_SIZE   (4*PRG_INFO_MAX_WORD32)
//-------------------------------------------------
//
// ----------------------------------------------------------------------------
#define PRG_MAX_TESTS        (16)// Test number: Ox0 to 0xF
#define TEST_MAX_PARAM32     (8) // Parameters: 1 to 7 (0 reserved for TEST_ID)
#define TEST_MAX_RESULTS32   (32)// Results:    1 to 31 (0 reserved for TEST_ID)
#define PRG_MAX_CLK_SETS     (10)
#define CLK_SET_MAX_PARAM32  (8)
//#define CLK_SET_USED_PARAM32 (5) //moved to prg_monitor.h
//#define PRG_CLK_SETS_SIZE32 (8)
//------------------------------------
//
//_____________________________________________________________________________
#define PRG_CLK_SETS_OFFSET  (PRG_INFO_OFFSET + PRG_INFO_MAX_SIZE)
#define PRG_CLK_SETS_SIZE    (PRG_MAX_CLK_SETS * CLK_SET_MAX_PARAM32 * 4)
#define PRG_TESTS_OFFSET     (PRG_CLK_SETS_OFFSET + PRG_CLK_SETS_SIZE)
#define PRG_TESTS_MAX_SIZE   (PRG_MAX_TESTS * TEST_MAX_PARAM32 * 4)
#define PRG_RESULTS_OFFSET   (PRG_TESTS_OFFSET + PRG_TESTS_MAX_SIZE)
#define PRG_RESULTS_MAX_SIZE (PRG_MAX_TESTS * TEST_MAX_RESULTS32 * 4)
//_____________________________________________________________________________
#define PRG_INFO_BASE_ADDR     (IRAM_ADDR + SRAM_BASE_SIZE + PRG_INFO_OFFSET)
#define PRG_CLK_SETS_BASE_ADDR (IRAM_ADDR + SRAM_BASE_SIZE + PRG_CLK_SETS_OFFSET)
#define PRG_TESTS_BASE_ADDR    (IRAM_ADDR + SRAM_BASE_SIZE + PRG_TESTS_OFFSET)
#define PRG_RESULTS_BASE_ADDR  (IRAM_ADDR + SRAM_BASE_SIZE + PRG_RESULTS_OFFSET)
// ----------------------------------------------------------------------------


// -- ISRAM Common data buffer ------------------------------------------------
// ---- This buffer starts in internal SRAM after the test results area.
// ---- Its end address is the end address of physical ISRAM.
// ---- It can be used as a buffer or large result area by any test.
// ----> each test is able to overwrite information stored by the previous ones!
#define PRG_SHARED_BUFFER_ADDR ((uint32_t*)(PRG_RESULTS_BASE_ADDR+PRG_RESULTS_MAX_SIZE))
#define PRG_SHARED_BUFFER_SIZE ((uint32_t)((IRAM_ADDR+IRAM_MIN_SIZE-((uint32_t)PRG_SHARED_BUFFER_ADDR))))
// ----------------------------------------------------------------------------



// -- Misc definitions --------------------------------------------------------
#define PRG_RESERVED_PATTERN  (0xCAFEFADE)
//#define PRG_RESERVED_PATTERN  (0x5C0B1D00)
// ----------------------------------------------------------------------------


// -- PRG information access macro --------------------------------------------
#define PRG_INFO_PT32(idx) (volatile uint32_t*)(PRG_INFO_BASE_ADDR +(4*(idx)))
#define PRG_INFO_PT8(idx)  (volatile uint8_t*)(PRG_INFO_BASE_ADDR +(4*(idx)))
#define PRG_INFO(idx)      (*(PRG_INFO_PT32(idx)))
// ----------------------------------------------------------------------------

// -- Clock settings access macro ---------------------------------------------
#define CLK_SET_PARAMETERS_PT32(idx) (volatile uint32_t*)(PRG_CLK_SETS_BASE_ADDR  \
                                            +(CLK_SET_MAX_PARAM32*4*(idx)))
#define CLK_SET_PARAMETERS_PT8(idx) (volatile uint8_t*)(PRG_CLK_SETS_BASE_ADDR  \
                                            +(CLK_SET_MAX_PARAM32*4*(idx)))
#define CLK_SET_PARAMETER(idx,param_num) (*((CLK_SET_PARAMETERS_PT32(idx))+(param_num)))
// ----------------------------------------------------------------------------

// -- Test parameters access macro --------------------------------------------
#define TEST_PARAMETERS_PT32(idx) (volatile uint32_t*)(PRG_TESTS_BASE_ADDR  \
                                            +(TEST_MAX_PARAM32*4*(idx)))
#define TEST_PARAMETERS_PT8(idx) (volatile uint8_t*)(PRG_TESTS_BASE_ADDR  \
                                            +(TEST_MAX_PARAM32*4*(idx)))
#define TEST_PARAMETER(idx,param_num) (*((TEST_PARAMETERS_PT32(idx))+(param_num)))

#define TEST_IDENTIFER(idx)  ((uint8_t)((TEST_PARAMETER(idx,0))>>16))
#define TEST_NB_PARAM(idx)   ((uint8_t)((TEST_PARAMETER(idx,0))>>8))
// ----------------------------------------------------------------------------

// -- Test result access macro ------------------------------------------------
#define TEST_RESULTS_PT32(idx) (volatile uint32_t*)(PRG_RESULTS_BASE_ADDR  \
                                            +(TEST_MAX_RESULTS32*4*(idx)))
#define TEST_RESULTS_PT8(idx) (volatile uint8_t*)(PRG_RESULTS_BASE_ADDR  \
                                            +(TEST_MAX_RESULTS32*4*(idx)))
#define TEST_RESULT(idx,res_num) (*((TEST_RESULTS_PT32(idx))+(res_num)))
#define TEST_NB_RESULTS(idx) ((uint8_t)((TEST_RESULT(idx,0))>>0))
// ----------------------------------------------------------------------------


typedef struct {
  uint32_t TEST_DESCIPTOR;
  uint32_t TEST_PARAMS[TEST_MAX_PARAM32-1];
} TestParamSet;


#endif //_PRG_MEMORY_MAP_H

