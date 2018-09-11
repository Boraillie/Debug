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


// ---- Validation libraries
typedef struct {
  unsigned int sn0; 	//
  unsigned int sn1; 	//  
} SN_READ;


typedef struct  {
  char name[30];	//
  unsigned int conf; 		//
  unsigned int ram_size0;  //
  unsigned int ram_size1; 	//
  unsigned int pakage; 		//
  unsigned int chip_id; 	//
  unsigned int chip_exid;   //

} CHIP_ID_MEM;

typedef struct {
  char  Nul_0;
  char  Year[2];
  char  Lot[5];
  char  Waffer[2];
  char  Diex[3];
  char  Diey[3];
  char  Rev;
  char  Margin[2];
  char  Nul_1;
  unsigned short P1;
  unsigned short Ft;
  unsigned short DataRet;
  unsigned short FullProbe;
  unsigned short DataRetFail;
  unsigned short ADBI;
  unsigned int Calibration[4];
  unsigned short RC32_18;
  unsigned short RC32_33;
  unsigned int RevP2;
  unsigned int RevFT;
  unsigned int RevP1;
  unsigned char  code_1265_18;
  unsigned char  code_0094_18;
  unsigned short code_18[7]; 
  unsigned char  code_1265_33;
  unsigned char  code_0094_33;
  unsigned short code_33[7];  
  unsigned int FlashCalibration[4];
  unsigned char  lenFtName;
  unsigned char  FtName[15];

} UNIQUE_ID;
typedef struct {
  unsigned int   Unique_ID[4] ;
  unsigned int   unused0[8] ;
  unsigned short RC32_18;
  unsigned short RC32_33;
  unsigned int   unused1[3] ;
  unsigned char  code_1265_18;
  unsigned char  code_0094_18;
  unsigned short code_18[7]; 
  unsigned char  code_1265_33;
  unsigned char  code_0094_33;
  unsigned short code_33[7];  

} DATA_UNIQUE_ID;


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
