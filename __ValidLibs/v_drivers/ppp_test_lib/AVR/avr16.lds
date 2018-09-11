
/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
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

/*------------------------------------------------------------------------------
 *      Linker script for running in internal FLASH
 *----------------------------------------------------------------------------*/

/*ENTRY(entry) /* where the cpu starts running/*

/* Memory Spaces Definitions */
MEMORY
{
    lram :   ORIGIN = 0x8000, LENGTH = 16384
}

/* Symbol definitions */
AVR16_ICBASE = 0x0;
AVR16_VBASE = AVR16_ICBASE;
AVR16_RESET = AVR16_VBASE;
AVR16_NMI = AVR16_RESET + 4;
AVR16_IRQLVL4 = AVR16_NMI + 0x4;
AVR16_IRQLVL3 = AVR16_IRQLVL4 + 0x4;
AVR16_IRQLVL2 = AVR16_IRQLVL3 + 0x4;
AVR16_IRQLVL1 = AVR16_IRQLVL2 + 0x4;
AVR16_CONTEXT0 = AVR16_IRQLVL1 + 0xC;
AVR16_CONTEXT1 = AVR16_CONTEXT0 + 0x30;
AVR16_CONTEXT2 = AVR16_CONTEXT1 + 0x30;
AVR16_CONTEXT3 = AVR16_CONTEXT2 + 0x30;
AVR16_APPLICATION = AVR16_CONTEXT3 + 0x30;


/* Symbol definitions for call map */
AVR16_ReadMemory16 = 0x118C0;
AVR16_ReadMemory32 = 0x118B8;
AVR16_WriteMemory16 = 0x118B4;
AVR16_WriteMemory32 = 0x118AC;
AVR16_ReadFarMemory16 = 0x117C0;
AVR16_ReadFarMemory32 = 0x117B8;
AVR16_WriteFarMemory16 = 0x117A4;
AVR16_WriteFarMemory32 = 0x1179C;

AVR16_ReadMemory8 = 0x118C2;
AVR16_WriteMemory8 = 0x118B6;
AVR16_ReadFarMemory8 = 0x117C2;
AVR16_WriteFarMemory8 = 0x117A6;


/* MOVS2R.w R24, SR   (0b1001_0000_0110_0000 << 1) */
AVR16_ReadSR16 = 0x120C0;
/* MOVS2R.w R24, CTRL (0b1001_0000_0110_0001 << 1) */
AVR16_ReadCTRL16 = 0x120C2;
/* MOVS2R.w R24, CCR  (0b1001_0000_0110_0010 << 1) */
AVR16_ReadCCR16 = 0x120C4; 
/* MOVS2R.w R24, SP   (0b1001_0000_0110_0011 << 1) */
AVR16_ReadSP16 = 0x120C6;
/* MOVS2R.l R22, SR   (0b1001_0000_0101_1100 << 1) */
AVR16_ReadSR32 = 0x120B8; 
/* MOVS2R.l R22, CTRL (0b1001_0000_0101_1101 << 1) */
AVR16_ReadCTRL32 = 0x120BA;
/* MOVS2R.l R22, CCR  (0b1001_0000_0101_1110 << 1) */
AVR16_ReadCCR32 = 0x120BC;
/* MOVS2R.l R22, SP   (0b1001_0000_0101_1111 << 1) */
AVR16_ReadSP32 = 0x120BE;
/* MOVR2S.w SR, R24   (0b1001_0000_1110_0000 << 1) */
AVR16_WritePC16 = 0x121C0;
/* MOVR2S.w CTRL, R24 (0b1001_0000_1110_0001 << 1) */
AVR16_WriteCTRL16 = 0x121C2;
/* MOVR2S.w CCR, R24  (0b1001_0000_1110_0010 << 1) */
AVR16_WriteCCR16 = 0x121C4;
/* MOVR2S.w SP, R24   (0b1001_0000_1110_0011 << 1) */
AVR16_WriteSP16 = 0x121C6;
/* MOVR2S.l SR, R22   (0b1001_0000_1101_1100 << 1) */
AVR16_WritePC32 = 0x121B8;
/* MOVR2S.l CTRL, R22 (0b1001_0000_1101_1101 << 1) */
AVR16_WriteCTRL32 = 0x121BA;
/* MOVR2S.l CCR, R22  (0b1001_0000_1101_1110 << 1) */
AVR16_WriteCCR32 = 0x121BC;
/* MOVR2S.l SP, R22   (0b1001_0000_1101_1111 << 1) */
AVR16_WriteSP32 = 0x121BE;

 


SECTIONS
{
  
    .text :
    {

      /*IRQ VECTORS*/
      . = AVR16_RESET;
      SHORT(0xC06F)
      SHORT(0x0000)
      LONG(_picop_local_NMI)
      LONG(_picop_local_isr4)

      LONG(_picop_local_isr3)

      LONG(_picop_local_isr2)

      LONG(_picop_local_isr1)

      /*APPLICATION CODE*/
      . = AVR16_APPLICATION;
      KEEP(*(.initcode))
      *(.text)
      /*INTERRUPT SERVICE ROUTINES*/
      . = ALIGN(4);
      _picop_local_NMI = . ;
      *(.nmi)
      _picop_local_isr1 = . ;
      *(.isr1)
      _picop_local_isr2 = . ;
      *(.isr2)
      _picop_local_isr3 = . ;
      *(.isr3)
      _picop_local_isr4 = . ;
      *(.isr4)

    } >lram

    .data :
    {
      *(.data)
      *(.rodata)
    } >lram

}



