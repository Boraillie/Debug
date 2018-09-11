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



/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include "menu.h"
#include "tools.h"
#include "ddr_initialization.h"

extern char message[80];
/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/



// -----------------------------------------------------------------------------
//  Function Name       : internal_RC12MHz_reference
//  Object              : Software entry point
// -----------------------------------------------------------------------------
unsigned int internal_RC12MHz_reference(void)
{
   int read_tempo;

   // ------------ Select internal 12 MHz RC

   read_tempo = REG_CKGR_MOR;
   read_tempo &= ~CKGR_MOR_MOSCSEL;
   read_tempo |= CKGR_MOR_KEY_PASSWD;
   REG_CKGR_MOR = read_tempo;
   while( !(REG_PMC_SR & PMC_SR_MOSCSELS) );
       
   while (( PMC -> CKGR_MCFR & CKGR_MCFR_MAINFRDY ) != CKGR_MCFR_MAINFRDY) {}
   return(( PMC->CKGR_MCFR & CKGR_MCFR_MAINF_Msk)*2048);
}


// -----------------------------------------------------------------------------
//  Function Name       : external_12MHz_reference
//  Object              : Software entry point
// -----------------------------------------------------------------------------
unsigned int external_12MHz_reference(void)
{
   int read_tempo;

   // ------------ Enable external 12 MHz Osc
     
   read_tempo = REG_CKGR_MOR;
   read_tempo |= (CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCXTEN);
   REG_CKGR_MOR = read_tempo;
   while( !(REG_PMC_SR & PMC_SR_MOSCXTS) );

   // ------------ Select external 12 MHz Osc

   read_tempo = REG_CKGR_MOR;
   read_tempo |= (CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCSEL);
   REG_CKGR_MOR = read_tempo;
   while( !(REG_PMC_SR & PMC_SR_MOSCSELS) );
       
   while (( PMC -> CKGR_MCFR & CKGR_MCFR_MAINFRDY ) != CKGR_MCFR_MAINFRDY) {}
   return(( PMC->CKGR_MCFR & CKGR_MCFR_MAINF_Msk)*2048);
}
   void osc_infos(void)
{
    
//   Valid_DebugTrace( "\n\r");
//   Valid_DebugTrace( "Oscillator infos: \n\r");
   Valid_DebugTrace( "------------------------------------------------\n\r");
      
   //switch slow clock to internal rc 32k
   REG_SCKC_CR = SCKC_CR_OSCSEL_RC;    // select internal RC 32 KHz
   while( REG_PMC_SR & PMC_SR_OSCSELS);// bug : the status doesn't change
   Valid_DebugTrace( " 32K RC  ->");
   sprintf (message," XTAL 12MHz:%d Hz | RC 12MHz:%d Hz \n\r", external_12MHz_reference(),internal_RC12MHz_reference());     Valid_DebugTrace(message);    
      
   //switch 
   REG_SCKC_CR = SCKC_CR_OSCSEL_XTAL;  // select external 32 KHz Osc   
   //   while( !(REG_PMC_SR & PMC_SR_OSCSELS) );// bug : the status doesn't change
   while( (REG_SCKC_CR & SCKC_CR_OSCSEL_XTAL) == 0 ); 
//   Valid_DebugTrace( "\n\r");
   Valid_DebugTrace( " 32K EXT ->");
   sprintf (message," XTAL 12MHz:%d Hz | RC 12MHz:%d Hz \n\r", external_12MHz_reference(), internal_RC12MHz_reference());     Valid_DebugTrace(message);

}


// -----------------------------------------------------------------------------
//  Function Name       : display_FUSE_bits
//  Object              : read FuseBox data
// -----------------------------------------------------------------------------
void display_FUSE_bits (void)
{
 unsigned int  read_val, ii_count;

   if ((REG_SFC_MR & SFC_MR_MSK)){
     Valid_DebugTrace( "   Fuse read locked ! ! ! ! ! ! !\n\r");
     }
   else{
     Valid_DebugTrace( "\n\r");
     Valid_DebugTrace( "Fuses values: \n\r");
     Valid_DebugTrace( "------------------------------------------");
     for (ii_count = 0; ii_count < 24; ii_count++){
       Valid_DebugTrace( "\n\r");
       read_val = SFC->SFC_DR[ii_count];
       sprintf (message,"SFC_DR%02d = %.8x", ii_count,read_val);
       Valid_DebugTrace(message);
       }
     Valid_DebugTrace( "\n\r");
     Valid_DebugTrace( "------------------------------------------");
     Valid_DebugTrace( "\n\r");
     }
} 

/*----------------------------------------------------------------------------*/
//* Function Name       : print_mckr
//* Object              : Print MCK setting and clock value
//* input               : baseAddr Basse addres to write
//*                     : Size in byte ( 8 bits) 
//*                     : trace if true (0) print trace
// output               : true or false ( error)
//*---------------------------------------------------------------------------*/
//#define PMC_MCKR_PLLADIV2 (0x1u << 12) /**< \brief (PMC_MCKR) PLLA Divisor by 2 */
void print_mckr (void)
{
  
  unsigned int pres,ref;
  
  ref = (PMC -> PMC_MCKR &  0x0F0 )>>4 ;    
  if (ref == 0) pres = 1;
  if (ref == 1) pres = 2;
  if (ref == 2) pres = 4;
  if (ref == 3) pres = 8;
  if (ref == 4) pres = 16;
  if (ref == 5) pres = 32;
  if (ref == 6) pres = 64;
  sprintf (message,"PRES:  %d ",pres);
  Valid_DebugTrace(message);    

  ref = (PMC -> PMC_MCKR & 0x0300 )>>8 ;    
  if (ref == 0) pres = 1;
  if (ref == 1) pres = 2;
  if (ref == 2) pres = 4;
  if (ref == 3) pres = 3;
   sprintf (message,"MDIV:  %d ",pres);
  Valid_DebugTrace(message); 
  
  ref = (PMC -> PMC_MCKR & PMC_MCKR_PRES_Msk & 0x0300 )>>8 ;    
  if ((PMC -> PMC_MCKR & PMC_MCKR_PLLADIV2)  == PMC_MCKR_PLLADIV2)  Valid_DebugTrace("PLLA/2 "); 
  
  if ((PMC -> PMC_MCKR & PMC_MCKR_H32MXDIV)  == PMC_MCKR_H32MXDIV_H32MXDIV2) Valid_DebugTrace(" H32=H64/2 "); 
  Valid_DebugTrace("\n\r"); 
}

/*----------------------------------------------------------------------------*/
//* Function Name       : BOARD_RamValidation_Check
//* Object              : Write the address at value with MASK
//* input               : baseAddr Basse addres to write
//*                     : Size in byte ( 8 bits) 
//*                     : trace if true (0) print trace
// output               : true or false ( error)
//*---------------------------------------------------------------------------*/

unsigned int calcul (unsigned int trace)
{
  
  unsigned int mck,pres,ref;

 
  mck = (PMC -> CKGR_PLLAR >>  18 ) & 0x1FF; 
  mck ++ ;
  mck=mck*12;

  pres = (PMC -> CKGR_PLLAR ) & 0xF; ;

  if ( pres !=0) mck = mck/pres;

  if (trace == 0) {
  sprintf (message,"PLL %d MHz ",mck);
  Valid_DebugTrace(message);
  }
  pres = PMC -> PMC_MCKR;
  if ( (PMC -> PMC_MCKR & PMC_MCKR_PLLADIV2) == PMC_MCKR_PLLADIV2)     
      pres = 2 ;
  else 
      pres = 1 ;

  ref = (PMC -> PMC_MCKR & PMC_MCKR_PRES_Msk & 0x0F0 )>>4 ;    
  if (ref == 1) pres =pres*2;
  if (ref == 2) pres =pres*4;
  if (ref == 3) pres =pres*8;
  mck = mck/pres;

  if (trace == 0) {
  sprintf (message," PCK %d MHz ",mck); Valid_DebugTrace(message);
    }
  
  ref = PMC -> PMC_MCKR & (0x0300) ;
  ref = ref >> 8   ;
   
  if (ref == 0) pres =1;
  if (ref == 1) pres =2;
  if (ref == 2) pres =4;
  if (ref == 3) pres =3;
  mck = mck/pres;  
    if (trace == 0) {

    sprintf (message," MCK %d MHz ",mck); Valid_DebugTrace(message);
    }
    return (mck* (1000000)) ;
}
/*----------------------------------------------------------------------------*/
//* Function Name       : BOARD_RamValidation_Check
//* Object              : Write the address at value with MASK
//* input               : baseAddr Basse addres to write
//*                     : Size in byte ( 8 bits) 
//*                     : trace if true (0) print trace
// output               : true or false ( error)
//*---------------------------------------------------------------------------*/
uint32_t BOARD_RamValidation_Check(uint32_t baseAddr, uint32_t size,uint32_t trace)
{
    uint32_t i,error;
    uint32_t *ptr = (uint32_t *) baseAddr;

   error =0;
    for (i = 0; i <  (size >> 2); ++i) {
        if (i & 1) {
            if (ptr[i] != (0x55000000 + (i<<2))) {
              error++;
              if (trace ) {
                sprintf (message,"--FAIL At 0x%08X  read 0x%08X write 0x%08X \n\r",&ptr[i],ptr[i], (0x55000000 +(i<<2)));
                Valid_DebugTrace(message);                
              } else {              
                return error;
              }
            }
        }
        else {
            if (ptr[i] != (0xAA000000+ (i<<2))) {
              error++;
               if (trace ) {
                sprintf (message,"--FAIL At 0x%08X  read 0x%08X write 0x%08X \n\r",&ptr[i],ptr[i], (0xAA000000 + (i<<2)));
                Valid_DebugTrace(message);                
              } else {              
                return error;
              }
            }
        }
    }
    return error;
}
/*----------------------------------------------------------------------------*/
//* Function Name       : BOARD_RamValidation_write
//* Object              : Write the address at value with MASK
//* input               : baseAddr Basse addres to write
//*                     : Size in byte ( 8 bits) 
// output               : None
//*---------------------------------------------------------------------------*/
void BOARD_RamValidation_write(uint32_t baseAddr, uint32_t size)
{
    uint32_t i;
    uint32_t *ptr = (uint32_t *) baseAddr;

    for (i = 0; i < (size >> 2); ++i) {      
        if (i & 1) {
            ptr[i] = 0x55000000 + (i<<2) ;
        }
        else {
            ptr[i] = 0xAA000000+ (i<<2) ;
        }
    }
  
}

/*----------------------------------------------------------------------------*/
//* Function Name       : BOARD_RamValidation_add
//* Object              : Write and check the address at value
//* input               : baseAddr Basse addres to write
//*                     : Size in byte ( 8 bits)
// output               : true or false ( error)
//*---------------------------------------------------------------------------*/
unsigned int BOARD_RamValidation_add(uint32_t baseAddr, uint32_t size)
{
    uint32_t i;
    uint32_t *ptr = (uint32_t *) baseAddr;
    for (i = 0; i < (size >> 2); ++i) {      
            ptr[i] = 0x00000000 + (i<<2) ;
     }
    for (i = 0; i < (size >> 2); ++i) {      
        if( ptr[i] != 0x00000000 + (i<<2)){
                   return false;  
        }
     }
  return true;  
}

/*----------------------------------------------------------------------------*/
//* Function Name       : BOARD_RamValidation_write_K
//* Object              : Write at each K byte
//* input               : baseAddr Basse addres to write
//*                     : Size in byte ( 8 bits)
// output               : true or false ( error)
//*---------------------------------------------------------------------------*/
void BOARD_RamValidation_write_K(uint32_t baseAddr, uint32_t size)
{
    uint32_t i,k;
    uint32_t *ptr = (uint32_t *) baseAddr;

    for (i = 0,k=0; i < (size >> 2); ++i) {      
        if ((i % 1024)== 0) {
            k++;
        }
            ptr[i] = 0x00000000 + (0xFFFF&(i<<2)) + (k<<16) ;

    }
  
}

/*----------------------------------------------------------------------------*/
//* Function Name       : write_signature
//* Object              : Write at 4 32 Bits signature
//* input               : baseAddr Basse addres to write
// output               : none
//*---------------------------------------------------------------------------*/
void write_signature (uint32_t baseAddr)
{
    uint32_t *ptr = (uint32_t *) baseAddr;
    ptr[0] = 0xCAFEDEDE; 
    ptr[1] = 0xA5A5A0A0; 
    ptr[2] = 0xCAFEDEDE; 
    ptr[3] = 0xAA005A5A; 
}
/*----------------------------------------------------------------------------*/
//* Function Name       : read_signature
//* Object              : Check if signature is done
//* input               : baseAddr Basse addres to write
// output               : true or false ( error)
//*---------------------------------------------------------------------------*/
unsigned int  read_signature (uint32_t baseAddr)
{
    uint32_t *ptr = (uint32_t *) baseAddr;
    if ( ( ptr[0] == 0xCAFEDEDE ) &
         ( ptr[1] == 0xA5A5A0A0 ) &
         ( ptr[2] == 0xCAFEDEDE ) & 
         ( ptr[3] == 0xAA005A5A ) )
    {
      return true;       
    } else {
      return false;   
    }
}

uint32_t BOARD_RamValidation_size(uint32_t *size_read,  uint32_t baseAddr, uint32_t size)
{

    uint32_t i;
    uint32_t *ptr = (uint32_t *) baseAddr;
    write_signature( baseAddr);
    *size_read = size ;

    for (i = 1024; i < (size >> 2); i+=1024 ) {      
         if (read_signature((uint32_t )&ptr[i]) ){
             *size_read = i*4;
             i = ((i*4)/1024)/1024;
              sprintf (message,"-- Modulo at %d Mbyte (%d Mbits) (%d Gbits)\n\r",i, (i*8), (i*8)/1024 );
              
              Valid_DebugTrace(message);
              return true;                  
               }
         if ((ptr[i]   ==  0 ) &
             (ptr[i+1] ==  0 ) &
             (ptr[i+2] ==  0 ) &
             (ptr[i+3] == 0 ) ){
             *size_read = i*4;            
             i = ((i*4)/1024)/1024;          
              sprintf (message,"-- zero at %d Mbyte (%d Mbits) (%d Gbits)\n\r",i, (i*8), (i*8)/1024 );
              Valid_DebugTrace(message);
              return false;                  
               }
    }
   return false;
}

/*----------------------------------------------------------------------------*/
//* Function Name       : BOARD_RamValidation_inc
//* Object              : Write and Check the address at value with MASK
//* input               : baseAddr Basse addres to write
//*                     : sise int byte 
//*                     : trace if true (0) print trace
// output               : true or false ( error)
//*---------------------------------------------------------------------------*/
uint32_t BOARD_RamValidation_inc(uint32_t baseAddr, uint32_t size,uint32_t trace)
{
    uint32_t error;
     // Write the address at value with MASK
     BOARD_RamValidation_write( baseAddr, size);
     // Check if Write the address at value with MASK
     error = BOARD_RamValidation_Check( baseAddr, size,trace);
     return error;
}


