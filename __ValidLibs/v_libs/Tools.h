/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */


#ifndef _TOOLS_H
#define _TOOLS_H

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/


extern char message[80];
/*----------------------------------------------------------------------------
 *       prototype Exported functions
 *----------------------------------------------------------------------------*/
extern void print_mckr (void);
extern unsigned int calcul (unsigned int trace);
extern void print_chip_id_info(unsigned int decode);
extern unsigned int internal_RC12MHz_reference(void);
extern unsigned int external_12MHz_reference(void);
extern void display_FUSE_bits (void);
extern uint32_t BOARD_RamValidation_Check(uint32_t baseAddr, uint32_t size,uint32_t trace);
extern void BOARD_RamValidation_write(uint32_t baseAddr, uint32_t size);
extern unsigned int BOARD_RamValidation_size(uint32_t *size_read,  uint32_t baseAddr, uint32_t size);
extern uint32_t BOARD_RamValidation_inc(uint32_t baseAddr, uint32_t size,uint32_t trace);
extern void write_signature (uint32_t baseAddr);
extern unsigned int  read_signature (uint32_t baseAddr);
#endif