 /*-----------------------------------------------------------------------------
 *         ATMEL Microchip  Software Validation   -  ROUSSET  -
 *------------------------------------------------------------------------------
 * File Name           : ddr_initialization.h
 * Object              : HeaderFile
 * Creation            : JPP
 * Change 24-Jan-16 JPP : Adapt to Winbon 128 Mbits  
 * Change 15-Mar-17 JPP : Adapt to Winbon die datasheet
 * Reference document 
 *  Winbond 
 *  DDR2 128 Mbits (16 MBytes) W971216KG_P07
 *  DDR2 512 Mbits (64 MBytes) W975116KG_P04
 *  DDR2 1 Gbits  (128 MBytes) W971G16SG_P02
 * Atmel 
 *  SAMA5D2 series  Atmel-11267E-ATARM-SAMA5D2-Datasheet_25-Jul-16
 *  SAMA5D2 SIP     170302_SAMA5D2 Plus DDR2 System in Package
 *----------------------------------------------------------------------------*/

#ifndef _DDR_VALIDATION_H
#define _DDR_VALIDATION_H
   
//------------------------------------------------------------------------------
//         Constant  definition 
//------------------------------------------------------------------------------
// constant returned by init_internal_ddr 
#define  DDR_ALREADY_INIT                       -1
#define  DDR_SIP_INIT_DONE                      0
#define  DDR_SIP_NOT_IN_FAMILY                  1
#define  DDR_SIP_NOT_FOUND_FAMILY               2
//------------------------------------------------------------------------------
//         Structures definition 
//------------------------------------------------------------------------------
typedef struct 
{
    unsigned int n_row; 
    unsigned int n_col;  
    unsigned int n_bank;
    unsigned int ba0;
    unsigned int ba1;    
    unsigned int t_refresh; //Refresh Timer    
// -------- HDDRSDRC2_T0PR : (HDDRSDRC2 Offset: 0xc) Timing0 Register --------   
    unsigned int t_tras;   // TRAS: Active to Precharge Delay
    unsigned int t_trcd;   // TRCD: Row to Column Delay
    unsigned int t_twr;    // TWR:  Write Recovery Delay
    unsigned int t_trc;    // TRC:  Row Cycle Delay
    unsigned int t_trp;    // TRP:  Row Precharge Delay
    unsigned int t_trrd;   // TRRD  Active bankA to Active bankB
    unsigned int t_twtr;   // TWTR: Internal Write to Read Delay
    unsigned int t_tmrd;   // TMRD: Load Mode Register Command to Active    
// -------- HDDRSDRC2_T1PR : (HDDRSDRC2 Offset: 0x10) Timing1 Register --------      
    unsigned int t_trfc;   // TRFC:  Row Cycle Delay
    unsigned int t_txsnr;  // TXSNR: Exit Self Refresh Delay
    unsigned int t_txsrd;  // TXSRD: ExiT Self Refresh Delay to Read
    unsigned int t_txp;    // TXP:   Exit Power-down Delay to First Command    
// -------- HDDRSDRC2_T2PR : (HDDRSDRC2 Offset: 0x14) Timing2 Register --------     
    unsigned int t_txard;  // TXARD:  Exit Active Power Down Delay to Read Command in Mode
    unsigned int t_tards;  // TXARDS: Exit Active Power Down Delay to Read Command in Mode
    unsigned int t_trpa;   // TRPA:   Row Precharge All Delay
    unsigned int t_trtp;   // TRTP:   Read to Precharge
    unsigned int t_tfaw;   // TFAW:   Read to Precharge 
} DDR2, *pDDR2;


// ------------------------------------ DDR2 Winbonb 128 Mbits W971216KG 800 MHz
// Organisation Table 33-5. org 9 colum / 12 row BA0 = A22, BA1 = A23 4 Banks 
#define DDR2_Winbon_128Mb_133MHZ     { MPDDRC_CR_NR_12_ROW_BITS, \
                                       MPDDRC_CR_NC_DDR9_MDDR8_COL_BITS, \
                                       MPDDRC_CR_NB_4_BANKS,     \
                                       (unsigned long)(1 << 22), \
                                       (unsigned long)(1 << 23), \
                                       2079,                     \
                                       MPDDRC_TPR0_TRAS(6),      \
                                       MPDDRC_TPR0_TRCD(2),      \
                                       MPDDRC_TPR0_TWR(2),       \
                                       MPDDRC_TPR0_TRC(8),       \
                                       MPDDRC_TPR0_TRP(2),       \
                                       MPDDRC_TPR0_TRRD(1),      \
                                       MPDDRC_TPR0_TWTR(1),      \
                                       MPDDRC_TPR0_TMRD(2),      \
                                       MPDDRC_TPR1_TRFC(10),     \
                                       MPDDRC_TPR1_TXSNR(12),    \
                                       MPDDRC_TPR1_TXSRD(200),   \
                                       MPDDRC_TPR1_TXP(2),       \
                                       MPDDRC_TPR2_TXARD(2),     \
                                       MPDDRC_TPR2_TXARDS(8),    \
                                       MPDDRC_TPR2_TRPA(3),      \
                                       MPDDRC_TPR2_TRTP(1),      \
                                       MPDDRC_TPR2_TFAW(5)       \
                                     }

#define DDR2_Winbon_128Mb_166MHZ     { MPDDRC_CR_NR_12_ROW_BITS, \
                                       MPDDRC_CR_NC_DDR9_MDDR8_COL_BITS, \
                                       MPDDRC_CR_NB_4_BANKS,     \
                                       (unsigned long)(1 << 22), \
                                       (unsigned long)(1 << 23), \
                                       2594,                     \
                                       MPDDRC_TPR0_TRAS(8),      \
                                       MPDDRC_TPR0_TRCD(3),      \
                                       MPDDRC_TPR0_TWR(3),       \
                                       MPDDRC_TPR0_TRC(10),      \
                                       MPDDRC_TPR0_TRP(3),       \
                                       MPDDRC_TPR0_TRRD(2),      \
                                       MPDDRC_TPR0_TWTR(2),      \
                                       MPDDRC_TPR0_TMRD(2),      \
                                       MPDDRC_TPR1_TRFC(13),     \
                                       MPDDRC_TPR1_TXSNR(15),    \
                                       MPDDRC_TPR1_TXSRD(200),   \
                                       MPDDRC_TPR1_TXP(2),       \
                                       MPDDRC_TPR2_TXARD(2),     \
                                       MPDDRC_TPR2_TXARDS(8),    \
                                       MPDDRC_TPR2_TRPA(4),      \
                                       MPDDRC_TPR2_TRTP(2),      \
                                       MPDDRC_TPR2_TFAW(6)       \
                                     }

#define DDR2_Winbon_128Mb_200MHZ     { MPDDRC_CR_NR_12_ROW_BITS, \
                                       MPDDRC_CR_NC_DDR9_MDDR8_COL_BITS, \
                                       MPDDRC_CR_NB_4_BANKS,     \
                                       (unsigned long)(1 << 22), \
                                       (unsigned long)(1 << 23), \
                                       3126,                     \
                                       MPDDRC_TPR0_TRAS(10),     \
                                       MPDDRC_TPR0_TRCD(4),      \
                                       MPDDRC_TPR0_TWR(4),       \
                                       MPDDRC_TPR0_TRC(13),      \
                                       MPDDRC_TPR0_TRP(4),       \
                                       MPDDRC_TPR0_TRRD(2),      \
                                       MPDDRC_TPR0_TWTR(2),      \
                                       MPDDRC_TPR0_TMRD(2),      \
                                       MPDDRC_TPR1_TRFC(16),     \
                                       MPDDRC_TPR1_TXSNR(18),    \
                                       MPDDRC_TPR1_TXSRD(200),   \
                                       MPDDRC_TPR1_TXP(2),       \
                                       MPDDRC_TPR2_TXARD(2),     \
                                       MPDDRC_TPR2_TXARDS(8),    \
                                       MPDDRC_TPR2_TRPA(5),      \
                                       MPDDRC_TPR2_TRTP(2),      \
                                       MPDDRC_TPR2_TFAW(8)       \
                                     }

// ------------------------------------ DDR2 Winbonb 512 Mbits W975116KG 800 MHz
// Organisation Table 33-7. org 9 colum / 12 row BA0 = A22, BA1 = A23 4 Banks 
#define DDR2_Winbon_512Mb_133MHZ     { MPDDRC_CR_NR_13_ROW_BITS, \
                                       MPDDRC_CR_NC_DDR10_MDDR9_COL_BITS, \
                                       MPDDRC_CR_NB_4_BANKS,     \
                                       (unsigned long)(1 << 24), \
                                       (unsigned long)(1 << 25), \
                                       1040,                     \
                                       MPDDRC_TPR0_TRAS(6),      \
                                       MPDDRC_TPR0_TRCD(2),      \
                                       MPDDRC_TPR0_TWR(2),       \
                                       MPDDRC_TPR0_TRC(8),       \
                                       MPDDRC_TPR0_TRP(2),       \
                                       MPDDRC_TPR0_TRRD(2),      \
                                       MPDDRC_TPR0_TWTR(1),      \
                                       MPDDRC_TPR0_TMRD(2),      \
                                       MPDDRC_TPR1_TRFC(14),     \
                                       MPDDRC_TPR1_TXSNR(16),    \
                                       MPDDRC_TPR1_TXSRD(200),   \
                                       MPDDRC_TPR1_TXP(2),       \
                                       MPDDRC_TPR2_TXARD(2),     \
                                       MPDDRC_TPR2_TXARDS(8),    \
                                       MPDDRC_TPR2_TRPA(3),      \
                                       MPDDRC_TPR2_TRTP(1),      \
                                       MPDDRC_TPR2_TFAW(6)       \
                                     }
#define DDR2_Winbon_512Mb_166MHZ     { MPDDRC_CR_NR_13_ROW_BITS, \
                                       MPDDRC_CR_NC_DDR10_MDDR9_COL_BITS, \
                                       MPDDRC_CR_NB_4_BANKS,     \
                                       (unsigned long)(1 << 24), \
                                       (unsigned long)(1 << 25), \
                                       1297,                     \
                                       MPDDRC_TPR0_TRAS(8),      \
                                       MPDDRC_TPR0_TRCD(3),      \
                                       MPDDRC_TPR0_TWR(3),       \
                                       MPDDRC_TPR0_TRC(10),      \
                                       MPDDRC_TPR0_TRP(3),       \
                                       MPDDRC_TPR0_TRRD(2),      \
                                       MPDDRC_TPR0_TWTR(2),      \
                                       MPDDRC_TPR0_TMRD(2),      \
                                       MPDDRC_TPR1_TRFC(18),     \
                                       MPDDRC_TPR1_TXSNR(20),    \
                                       MPDDRC_TPR1_TXSRD(200),   \
                                       MPDDRC_TPR1_TXP(2),       \
                                       MPDDRC_TPR2_TXARD(2),     \
                                       MPDDRC_TPR2_TXARDS(8),    \
                                       MPDDRC_TPR2_TRPA(4),      \
                                       MPDDRC_TPR2_TRTP(2),      \
                                       MPDDRC_TPR2_TFAW(8)       \
                                     }
#define DDR2_Winbon_512Mb_200MHZ     { MPDDRC_CR_NR_13_ROW_BITS, \
                                       MPDDRC_CR_NC_DDR10_MDDR9_COL_BITS, \
                                       MPDDRC_CR_NB_4_BANKS,     \
                                       (unsigned long)(1 << 24), \
                                       (unsigned long)(1 << 25), \
                                       1563,                     \
                                       MPDDRC_TPR0_TRAS(10),     \
                                       MPDDRC_TPR0_TRCD(4),      \
                                       MPDDRC_TPR0_TWR(4),       \
                                       MPDDRC_TPR0_TRC(13),      \
                                       MPDDRC_TPR0_TRP(4),       \
                                       MPDDRC_TPR0_TRRD(3),      \
                                       MPDDRC_TPR0_TWTR(2),      \
                                       MPDDRC_TPR0_TMRD(2),      \
                                       MPDDRC_TPR1_TRFC(22),     \
                                       MPDDRC_TPR1_TXSNR(24),    \
                                       MPDDRC_TPR1_TXSRD(200),   \
                                       MPDDRC_TPR1_TXP(2),       \
                                       MPDDRC_TPR2_TXARD(2),     \
                                       MPDDRC_TPR2_TXARDS(8),    \
                                       MPDDRC_TPR2_TRPA(5),      \
                                       MPDDRC_TPR2_TRTP(2),      \
                                       MPDDRC_TPR2_TFAW(10)      \
                                     }

// ------------------------------------ DDR2 Winbonb 1 Gbits W971GG6SB 800 MHz
// Organisation Table 33-11. org 9 colum / 13 row BA0 = A24, BA1 = A25 8 Banks 
#define DDR2_Winbon_1Gbit_133MHZ     { MPDDRC_CR_NR_13_ROW_BITS, \
                                       MPDDRC_CR_NC_DDR10_MDDR9_COL_BITS, \
                                       MPDDRC_CR_NB_8_BANKS,     \
                                       (unsigned long)(1 << 24), \
                                       (unsigned long)(1 << 25), \
                                       1040,                     \
                                       MPDDRC_TPR0_TRAS(6),      \
                                       MPDDRC_TPR0_TRCD(2),      \
                                       MPDDRC_TPR0_TWR(2),       \
                                       MPDDRC_TPR0_TRC(7),       \
                                       MPDDRC_TPR0_TRP(2),       \
                                       MPDDRC_TPR0_TRRD(2),      \
                                       MPDDRC_TPR0_TWTR(1),      \
                                       MPDDRC_TPR0_TMRD(2),      \
                                       MPDDRC_TPR1_TRFC(17),     \
                                       MPDDRC_TPR1_TXSNR(19),    \
                                       MPDDRC_TPR1_TXSRD(200),   \
                                       MPDDRC_TPR1_TXP(2),       \
                                       MPDDRC_TPR2_TXARD(2),     \
                                       MPDDRC_TPR2_TXARDS(8),    \
                                       MPDDRC_TPR2_TRPA(3),      \
                                       MPDDRC_TPR2_TRTP(1),      \
                                       MPDDRC_TPR2_TFAW(6)       \
                                     }
#define DDR2_Winbon_1Gbit_166MHZ     { MPDDRC_CR_NR_13_ROW_BITS, \
                                       MPDDRC_CR_NC_DDR10_MDDR9_COL_BITS, \
                                       MPDDRC_CR_NB_8_BANKS,     \
                                       (unsigned long)(1 << 24), \
                                       (unsigned long)(1 << 25), \
                                       1297,                     \
                                       MPDDRC_TPR0_TRAS(7),      \
                                       MPDDRC_TPR0_TRCD(3),      \
                                       MPDDRC_TPR0_TWR(3),       \
                                       MPDDRC_TPR0_TRC(9),       \
                                       MPDDRC_TPR0_TRP(3),       \
                                       MPDDRC_TPR0_TRRD(2),      \
                                       MPDDRC_TPR0_TWTR(2),      \
                                       MPDDRC_TPR0_TMRD(2),      \
                                       MPDDRC_TPR1_TRFC(22),     \
                                       MPDDRC_TPR1_TXSNR(23),    \
                                       MPDDRC_TPR1_TXSRD(200),   \
                                       MPDDRC_TPR1_TXP(2),       \
                                       MPDDRC_TPR2_TXARD(2),     \
                                       MPDDRC_TPR2_TXARDS(8),    \
                                       MPDDRC_TPR2_TRPA(4),      \
                                       MPDDRC_TPR2_TRTP(2),      \
                                       MPDDRC_TPR2_TFAW(8)       \
                                     }

#define DDR2_Winbon_1Gbit_200MHZ     { MPDDRC_CR_NR_13_ROW_BITS, \
                                       MPDDRC_CR_NC_DDR10_MDDR9_COL_BITS, \
                                       MPDDRC_CR_NB_8_BANKS,     \
                                       (unsigned long)(1 << 24), \
                                       (unsigned long)(1 << 25), \
                                       1563,                     \
                                       MPDDRC_TPR0_TRAS(9),      \
                                       MPDDRC_TPR0_TRCD(3),      \
                                       MPDDRC_TPR0_TWR(4),       \
                                       MPDDRC_TPR0_TRC(11),       \
                                       MPDDRC_TPR0_TRP(3),       \
                                       MPDDRC_TPR0_TRRD(3),      \
                                       MPDDRC_TPR0_TWTR(2),      \
                                       MPDDRC_TPR0_TMRD(2),      \
                                       MPDDRC_TPR1_TRFC(26),     \
                                       MPDDRC_TPR1_TXSNR(28),    \
                                       MPDDRC_TPR1_TXSRD(200),   \
                                       MPDDRC_TPR1_TXP(2),       \
                                       MPDDRC_TPR2_TXARD(2),     \
                                       MPDDRC_TPR2_TXARDS(8),    \
                                       MPDDRC_TPR2_TRPA(5),      \
                                       MPDDRC_TPR2_TRTP(2),      \
                                       MPDDRC_TPR2_TFAW(10)       \
                                     }
// Organisation Table 33-7. org 9 colum / 12 row BA0 = A22, BA1 = A23 4 Banks 
#define DDR2_Winbon_512Mb_133MHZ     { MPDDRC_CR_NR_13_ROW_BITS, \
                                       MPDDRC_CR_NC_DDR10_MDDR9_COL_BITS, \
                                       MPDDRC_CR_NB_4_BANKS,     \
                                       (unsigned long)(1 << 24), \
                                       (unsigned long)(1 << 25), \
                                       1040,                     \
                                       MPDDRC_TPR0_TRAS(6),      \
                                       MPDDRC_TPR0_TRCD(2),      \
                                       MPDDRC_TPR0_TWR(2),       \
                                       MPDDRC_TPR0_TRC(8),       \
                                       MPDDRC_TPR0_TRP(2),       \
                                       MPDDRC_TPR0_TRRD(2),      \
                                       MPDDRC_TPR0_TWTR(1),      \
                                       MPDDRC_TPR0_TMRD(2),      \
                                       MPDDRC_TPR1_TRFC(14),     \
                                       MPDDRC_TPR1_TXSNR(16),    \
                                       MPDDRC_TPR1_TXSRD(200),   \
                                       MPDDRC_TPR1_TXP(2),       \
                                       MPDDRC_TPR2_TXARD(2),     \
                                       MPDDRC_TPR2_TXARDS(8),    \
                                       MPDDRC_TPR2_TRPA(3),      \
                                       MPDDRC_TPR2_TRTP(1),      \
                                       MPDDRC_TPR2_TFAW(6)       \
                                     }

/*********************** External Prototype Functions *************************/
extern void Init_DDR2_16   (const DDR2 *ddr2);


uint32_t BOARD_RamValidation_inc(uint32_t baseAddr, uint32_t size,uint32_t trace);
unsigned int internal_ddr_size(unsigned int family,unsigned int byte_read);
unsigned int init_internal_ddr(unsigned int family);
unsigned int speed_ddr  (void);

#endif /* _DDR_VALIDATION_H */
