// -----------------------------------------------------------------------------
//          ATMEL Microcontroller Software Support  -  ROUSSET  -
// -----------------------------------------------------------------------------
//  The software is delivered "AS IS" without warranty or condition of any
//  kind, either express, implied or statutory. This includes without
//  limitation any warranty or condition with respect to merchantability or
//  fitness for any particular purpose, or against the infringements of
//  intellectual property rights of others.
// -----------------------------------------------------------------------------
//  File Name           : xxxx.c
//  Object              : 
//  Creation            : 2017
//	SAM5D27 
// -----------------------------------------------------------------------------

// ---- Project include files


#include "v_memory_tools.h"




uint32_t v_memory_test(uint32_t baseAddr, uint32_t size)
{
	//Fill memory
	uint32_t index, error = 0;
	uint32_t *memory = (uint32_t *) baseAddr;
        
        //reset memory
        memset(memory, 0, size);
        
	for (index = 0; index < (size >> 2); ++index) {      
		if (index & 1) {
			memory[index] = 0x55000000 + (index<<2) ;
		}
		else {
			memory[index] = 0xAA000000+ (index<<2) ;
		}
	}
	//check previousely wrote data
        
        for (index = 0; index <  (size >> 2); ++index) {
                if (index & 1) {
                        if (memory[index] != (0x55000000 + (index<<2))) {
                                error++;
                                printf ("--FAIL At 0x%08X  read 0x%08X write 0x%08X \n\r",&memory[index],memory[index], (0x55000000 +(index<<2)));
                                return error;
                        }
                }
                else {
                        if (memory[index] != (0xAA000000+ (index<<2))) {
                                error++;
                                printf ("--FAIL At 0x%08X  read 0x%08X write 0x%08X \n\r",&memory[index],memory[index], (0xAA000000 + (index<<2)));
                                return error;
                        }
                }
        }
        
}
