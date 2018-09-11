// -----------------------------------------------------------------------------
//          ATMEL Microcontroller Software Support  -  ROUSSET  -
// -----------------------------------------------------------------------------
//  The software is delivered "AS IS" without warranty or condition of any
//  kind, either express, implied or statutory. This includes without
//  limitation any warranty or condition with respect to merchantability or
//  fitness for any particular purpose, or against the infringements of
//  intellectual property rights of others.
// -----------------------------------------------------------------------------
//  File Name           : Chip_ID.c
//  Object              : Read en decode the chip ID
//  Creation            : JPP / Oct 2012
//	SAMAD27 	2*1024 	160 100 0X29A70EE0
// -----------------------------------------------------------------------------

// ---- Project include files

// ---- General purpose include files

#include "project.h"
#include "device.h"
#include "board.h"
#include "v_chipid.h"
#include "v_utils.h"





#define  PASS_P1           (0x2A2A)
#define  PASS_FT           (0x25A2)
#define  PASS_DATA_RET     (0xD5D5)
#define  PASS_FULL_PROBE   (0x2525)
#define  FAIL_DATA_RET     (0x1111)
#define  PASS_ADBI         (0x5D23)
#define  PASS_ADBI_1       (0x5D28)
#define  PASS_NUL          (0x0000)


extern int Chip_ID(CHIP_ID_MEM *chip);
extern void Chip_ID_print(CHIP_ID_MEM *chip);
extern unsigned int check_RAM_size (unsigned int ram_size ,unsigned *ptram_start, unsigned *ptram_end );
extern void print_chip_id_info(unsigned int decode);
extern uint32_t v_memory_test(uint32_t baseAddr, uint32_t size);