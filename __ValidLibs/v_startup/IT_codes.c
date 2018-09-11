/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) %copyright_year%, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

#include "project.h"
#include "device.h"
#include "board.h"


////////////////////////////////////////////////////////////////////////////////
//#warning DEBUG PURPOSE!!!!! 
// These are volatile to try and prevent the compiler/linker optimising them
//away as the variables never actually get used.  If the debugger won't show the
//values of the variables, make them global my moving their declaration outside
//of this function.
volatile uint32_t r0;
volatile uint32_t r1;
volatile uint32_t r2;
volatile uint32_t r3;
volatile uint32_t r12;
volatile uint32_t lr; // Link register. 
volatile uint32_t pc; // Program counter.
volatile uint32_t psr;// Program status register.
void HardFault_Handler(void)  ;//__attribute__( ( naked ) );
void prvGetRegistersFromStack( uint32_t *pulFaultStackAddress );
void prvGetRegistersFromStack( uint32_t *pulFaultStackAddress )
{


    r0 = pulFaultStackAddress[ 0 ];
    r1 = pulFaultStackAddress[ 1 ];
    r2 = pulFaultStackAddress[ 2 ];
    r3 = pulFaultStackAddress[ 3 ];

    r12 = pulFaultStackAddress[ 4 ];
    lr = pulFaultStackAddress[ 5 ];
    pc = pulFaultStackAddress[ 6 ];
    psr = pulFaultStackAddress[ 7 ];

    // When the following line is hit, the variables contain the register values. 
    for( ;; );
}
void HardFault_Handler(void)
{
     // test bit 2 of the EXC_RETURN placed in LR to determine which stack was in use before entering the handler
     asm(" TST LR, #4 ");
     // move the appropriate stack pointer value into R0
     asm(" ITE EQ");
     asm(" MRSEQ R0, MSP");
     asm(" MRSNE R0, PSP");
     //asm(" MRSEQ R0, PSP");//test
    //get stacked PC
     asm("LDR R1, [R0, #24]");
     // call prvGetRegistersFromStack() with R0 set as the stack pointer at the time of exception entry
     //prvGetRegistersFromStack(0);
     asm("B.N prvGetRegistersFromStack");
//     asm("LDR R2, HANDLER2_ADDRESS_CONST");
//     asm("BX R2");
//     asm("IMPORT prvGetRegistersFromStack");
//     asm("ALIGN 4");
//     asm("HANDLER2_ADDRESS_CONST DCD prvGetRegistersFromStack");
}
//#warning DEBUG PURPOSE!!!!!
////////////////////////////////////////////////////////////////////////////////

void NMI_Handler(void){
  while (1);
  }

/*
void HardFault_Handler(void){
  while (1);
  }
*/

void MemManage_Handler(void){
  while (1);
  }

void BusFault_Handler(void){
  while (1);
  }

void UsageFault_Handler(void){
  while (1);
  }

void SVC_Handler(void){
  while (1);
  }

void DebugMon_Handler(void){
  while (1);
  }

void PendSV_Handler(void){
  while (1);
  }

void SysTick_Handler(void){
  while (1);
  }


