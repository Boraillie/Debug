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
//  Creation            : JPP / Apr 2015
//	SAM5D27 
// -----------------------------------------------------------------------------

// ---- Project include files

#include "project.h"
#include "device.h"
#include "board.h"
#include "v_chipid.h"

#include "v_utils.h"
#define   IRAM_ADDR   0x02000000
// ---- General purpose include files


#define CHIP_ID_CONF_ALL          (0x00)
#define CHIP_ID_CONF_NO_AESB      (0x01)
#define CHIP_ID_CONF_NO_CAN0      (0x02)
#define CHIP_ID_CONF_NO_CAN1      (0x04)
#define CHIP_ID_CONF_NO_HSIC      (0x08)
#define CHIP_ID_CONF_NO_SHIELD    (0x10)


#include <string.h>
#include "v_debug.h"

extern unsigned int page_status[512];
extern unsigned int trace[10];
// ---- Project files (local)
static SN_READ sn;
#define data sheet0x8a5c08c0
const CHIP_ID_MEM samA5D2[]={
#define CONF_FUSE_SAMA5D21   ( CHIP_ID_CONF_NO_SHIELD | CHIP_ID_CONF_NO_HSIC | CHIP_ID_CONF_NO_AESB | CHIP_ID_CONF_NO_CAN0 | CHIP_ID_CONF_NO_CAN1 )
#define CONF_FUSE_SAMA5D22   ( CHIP_ID_CONF_NO_SHIELD | CHIP_ID_CONF_NO_HSIC)
#define CONF_FUSE_SAMA5D23   ( CHIP_ID_CONF_NO_HSIC)
#define CONF_FUSE_SAMA5D24   ( CHIP_ID_CONF_NO_SHIELD |  CHIP_ID_CONF_NO_CAN0 | CHIP_ID_CONF_NO_CAN1 )
#define CONF_FUSE_SAMA5D26   ( CHIP_ID_CONF_NO_SHIELD | CHIP_ID_CONF_NO_HSIC | CHIP_ID_CONF_NO_AESB |  CHIP_ID_CONF_NO_CAN0 | CHIP_ID_CONF_NO_CAN1  )
#define CONF_FUSE_SAMA5D27   ( CHIP_ID_CONF_NO_SHIELD )
#define CONF_FUSE_SAMA5D28   ( CHIP_ID_CONF_ALL )
  
//      name[20];	Confif;         ram_size0;  ram_size1; pakage; chip_id; 	chip_exid;   //  
	"UNKNOW"         , 0                    ,    0  ,  0    , 0     , 0         , 0 ,
	"SAMA5D27 Blind"    , CHIP_ID_CONF_ALL,  128	,128	, 298 	,0x8A5C08C0  , 0 ,
	"SAMA5D21-CU 85 C" , CONF_FUSE_SAMA5D21 ,  128	,128	, 196 	,0x8A5C08C0 , 0x5a ,
	"SAMA5D22-CU 85 C" , CONF_FUSE_SAMA5D22,  128	,128	, 196 	,0x8A5C08C0 , 0x59 ,
	"SAMA5D22-CN 105 C" ,CONF_FUSE_SAMA5D22,  128	,128	, 196 	,0x8A5C08C0 , 0x69 ,
	"SAMA5D23-CU 85 C",  CONF_FUSE_SAMA5D23 ,  128	,128	, 196 	,0x8A5C08C0 , 0x58 ,
	"SAMA5D24-Cx 70 C" , CONF_FUSE_SAMA5D24 ,  128	,128	, 256 	,0x8A5C08C0 , 0x04 ,
	"SAMA5D24-CU 85 C" , CONF_FUSE_SAMA5D24,  128	,128	, 256 	,0x8A5C08C0 , 0x14 ,
 	"SAMA5D26-CU 85 C" , CONF_FUSE_SAMA5D26,  128	,128	, 289 	,0x8A5C08C0 , 0x12 ,                      
	"SAMA5D27-CN 85 C" , CONF_FUSE_SAMA5D27 ,  128	,128	, 289 	,0x8A5C08C0 , 0x11 , // must be CU
	"SAMA5D27-CN 105 C" ,CONF_FUSE_SAMA5D27,  128	,128	, 289 	,0x8A5C08C0 , 0x21 ,
	"SAMA5D28-CN 85 C" , CONF_FUSE_SAMA5D28 ,  128	,128	, 289 	,0x8A5C08C0 , 0x10 ,  // must be CU
	"SAMA5D28-CN 105 C" ,CONF_FUSE_SAMA5D28,  128	,128	, 289 	,0x8A5C08C0 , 0x20 ,              

	"SAMA5D21-CU 85 MRLB" ,CONF_FUSE_SAMA5D21 ,  128	,128	, 196 	,0x8A5C08C1 , 0x5a ,
	"SAMA5D22-CU 85 MRLB" , CONF_FUSE_SAMA5D22,  128	,128	, 196 	,0x8A5C08C1 , 0x59 ,
	"SAMA5D22-CN 105 MRLB" ,CONF_FUSE_SAMA5D22,  128	,128	, 196 	,0x8A5C08C1 , 0x69 ,
	"SAMA5D23-CU 85 MRLB", CONF_FUSE_SAMA5D23 ,  128	,128	, 196 	,0x8A5C08C1 , 0x58 ,
	"SAMA5D24-Cx 70 MRLB" ,CONF_FUSE_SAMA5D24 ,  128	,128	, 256 	,0x8A5C08C1 , 0x04 ,
	"SAMA5D24-CU 85 MRLB" , CONF_FUSE_SAMA5D24,  128	,128	, 256 	,0x8A5C08C1 , 0x14 ,
 	"SAMA5D26-CU 85 MRLB" , CONF_FUSE_SAMA5D26,  128	,128	, 289 	,0x8A5C08C1 , 0x12 ,                      
 	"SAMA5D26-CN 105 MRLB" , CONF_FUSE_SAMA5D26,  128	,128	, 289 	,0x8A5C08C1 , 0x22 ,                      
	"SAMA5D27-CU 85 MRLB" , CONF_FUSE_SAMA5D27 ,  128	,128	, 289 	,0x8A5C08C1 , 0x11 ,
	"SAMA5D27-CN 105 MRLB" , CONF_FUSE_SAMA5D27,  128	,128	, 289 	,0x8A5C08C1 , 0x21 ,
	"SAMA5D28-CU 85 MRLB" , CONF_FUSE_SAMA5D28 ,  128	,128	, 289 	,0x8A5C08C1 , 0x10 ,
	"SAMA5D28-CN 105 MRLB" , CONF_FUSE_SAMA5D28,  128	,128	, 289 	,0x8A5C08C1 , 0x20 ,              

	"SAMA5D225-D1M MRLC SIP 128M" , CONF_FUSE_SAMA5D22 ,  128	,128	, 196 	,0x8A5C08C2 , 0x53 ,
	"SAMA5D23-D1M MRLB SIP 128M" , CONF_FUSE_SAMA5D23,    128	,128	, 196 	,0x8A5C08C2 , 0x43 ,             

	"SAMA5D27-D5M MRLC SIP 512M" , CONF_FUSE_SAMA5D27 ,   128	,128	, 289 	,0x8A5C08C2 , 0x32 ,
	"SAMA5D27-D1G MRLC SIP  1Gb" , CONF_FUSE_SAMA5D27,    128	,128	, 289 	,0x8A5C08C2 , 0x33 ,
	"SAMA5D27-D1G MRLC SIP  1Gb" , CONF_FUSE_SAMA5D27,    128	,128	, 289 	,0x8A5C08C2 , 0x30 ,
	"SAMA5D28-D1G MRLB SIP  1Gb" , CONF_FUSE_SAMA5D28 ,   128	,128	, 289 	,0x8A5C08C2 , 0x13 ,
	"TESTER -D1G MRLB SIP  1Gb" , CONF_FUSE_SAMA5D28 ,    128	,128	, 289 	,0x8A5C08C2 , 0x00 ,        
};


// -----------------------------------------------------------------------------
//  Function Name       : main
//  Object              : Software entry point
// -----------------------------------------------------------------------------
void Chip_ID_print(CHIP_ID_MEM *chip)
{

  char * csn;
  char  msg[80];
   // Device 
   Valid_DebugTrace(" =======================================================================\n\r");
   sprintf (msg,"Device : %s PIN nb %d, ",chip->name ,chip->pakage );        Valid_DebugTrace(msg);
   sprintf (msg,"SRAM0 %d Kbyte ",chip->ram_size0 );Valid_DebugTrace(msg);
   sprintf (msg,"SRAM1 %d Kbyte ",chip->ram_size1);                           Valid_DebugTrace(msg);
   Valid_DebugTrace("\n\r");
   // Chip ID   
   Valid_DebugTrace(" =======================================================================\n\r");   
   sprintf (msg,"ID:0x%.8X  exteded ID:0x%.8X ",REG_CHIPID_CIDR , REG_CHIPID_EXID );Valid_DebugTrace(msg);
   Valid_DebugTrace("\n\r");
   Valid_DebugTrace(" =======================================================================\n\r");
   //Serial number print       
   Valid_DebugTrace( "'------------------------------------------------ Serial number\n\r");
   sprintf (msg," SN0 : 0x%08X |",REG_SFR_SN0 );     Valid_DebugTrace(msg);   
   sprintf (msg," SN1 : 0x%08X \n\r",REG_SFR_SN1 );    Valid_DebugTrace(msg);   
 
   sn.sn0  = REG_SFR_SN0;
   sn.sn1  = REG_SFR_SN1;     
   csn = (char *) &sn;
   sprintf (msg,"Serial num: X:%d-Y:%d-Waffer:%d-", csn[5], csn[6] ,csn[7] );
   Valid_DebugTrace(msg);
   csn[5]=0;
   sprintf (msg,"Lot:%s-\n\r",csn  );    Valid_DebugTrace(msg);
}

// -----------------------------------------------------------------------------
//  Function Name       : Chip_ID
//  Object              : samA5D2
// -----------------------------------------------------------------------------
int Chip_ID(CHIP_ID_MEM *chip)
{
unsigned int id;
unsigned int chip_id,chip_idext;
   // Send Chip IP on debug  *chip_id   = ;
   chip_id = REG_CHIPID_CIDR;
   chip_idext = REG_CHIPID_EXID;
   // Init structure
   memcpy (  chip, (void *)&samA5D2[0], sizeof (samA5D2[0]));

   for ( id = 1 ; id < ( sizeof (samA5D2) / sizeof (CHIP_ID)) ; id ++)
   {
     if ( chip_id == samA5D2[id].chip_id) {
       
       if ( chip_idext == samA5D2[id].chip_exid){
       
       memcpy (  chip, (void *)&samA5D2[id], sizeof (samA5D2[0]));
       return 1;
       }
      
     }
   }
    return 0;
}
/*
void print_chip_id_info(unsigned int decode)
{
      char  msg[80];
      chip_id_s chip_id;
      
      chip_id =*((chip_id_s *)&CHIP_ID_REGISTER);
    //  Valid_DebugTrace( "\n\r");
//      Valid_DebugTrace( "Device infos : \n\r");
      Valid_DebugTrace( "'------------------------------------------------\n\r");
      
      sprintf (msg," Device chipID :                  0x%X\n\r",CHIP_ID_REGISTER);           Valid_DebugTrace(msg);      
      if (chip_id.EXT)
      {  sprintf (msg," Device ext chipID:               0x%X \n\r",CHIP_EXID_REGISTER);  Valid_DebugTrace(msg);}
      else 
            Valid_DebugTrace(" Device has no chip id extension\r\n");
      if ( decode)
      {            
            sprintf (msg," Package :                        %d_%d \n\r",DEVICE_PACKAGE/1000,DEVICE_PACKAGE%1000);           Valid_DebugTrace(msg);
            sprintf (msg," VERSION:                         %d \n\r",chip_id.VERSION );   Valid_DebugTrace(msg);
            sprintf (msg," Embedded Processor:              %d \n\r",chip_id.EPROC );     Valid_DebugTrace(msg);
            sprintf (msg," NVM Size :                       %d \n\r",chip_id.NVPSIZ );    Valid_DebugTrace(msg);
            sprintf (msg," 2nd NVM Size:                    %d \n\r",chip_id.NVPSIZ2);    Valid_DebugTrace(msg);
            sprintf (msg," ISRAM Size :                     %d \n\r",chip_id.SRAMSIZ);    Valid_DebugTrace(msg);
            sprintf (msg," Architecture type:               %d \r\n",chip_id.ARCH );      Valid_DebugTrace(msg);
            sprintf (msg," NVM Type :                       %d \n\r",chip_id.NVPTYP );    Valid_DebugTrace(msg);
      }
                                    
}
*/
#pragma segment="CSTACK"
unsigned int check_RAM_size (unsigned int ram_size ,unsigned *ptram_start, unsigned *ptram_end )
{
   unsigned int error,ii,size;
  
   // Write RAM rase Flash buffer
   error =0;
   size = (unsigned int)ptram_end  -(unsigned int ) ptram_start ;
  for (ii=0; ii < size /4 ; ii++)
    ptram_start[ii] = ii ;
  // Check TAG
  for (ii=0; ii < size /4 ; ii++)  {
   if ( ptram_start[ii] != ii ) error++ ;
  }

  return error;
}


