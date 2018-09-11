#ifndef _V_FLEXCOM_WRAPPER_H
#define _V_FLEXCOM_WRAPPER_H

/**
 * Flexcom wrapper for backward compatibility of USART
 * this file is intended to be included after the genuine header files
 */

typedef struct {
  __IO uint32_t FLEX_MR;         /**< \brief (Flexcom Offset: 0x000) FLEXCOM Mode Register */
  __I  uint32_t Reserved1[3];
  __I  uint32_t FLEX_RHR;        /**< \brief (Flexcom Offset: 0x010) FLEXCOM Receive Holding Register */
  __I  uint32_t Reserved2[3];
  __IO uint32_t FLEX_THR;        /**< \brief (Flexcom Offset: 0x020) FLEXCOM Transmit Holding Register */
  __I  uint32_t Reserved3[54];
  __I  uint32_t FLEX_VERSION;     /**< \brief (Flexcom Offset: 0x0FC) FLEXCOM Version Register */
  __I  uint32_t Reserved4[64];
} FlexcomShared;

#define FLEXCOM_MR              FLEX_MR
#define FLEXCOM_MR_OPMODE_USART FLEX_MR_OPMODE_USART
#define FLEXCOM_MR_OPMODE_SPI   FLEX_MR_OPMODE_SPI
#define FLEXCOM_MR_OPMODE_TWI   FLEX_MR_OPMODE_TWI

// FLEXCOM to USART wrapper ----------------------------------------------------
// !!! not mappable to the Usart software structure of the SAMG55 Flexcom
typedef struct {
  __O  uint32_t US_CR;       /**< \brief (Flexcom Offset: 0x200) USART Control Register */
  __IO uint32_t US_MR;       /**< \brief (Flexcom Offset: 0x204) USART Mode Register */
  __O  uint32_t US_IER;      /**< \brief (Flexcom Offset: 0x208) USART Interrupt Enable Register */
  __O  uint32_t US_IDR;      /**< \brief (Flexcom Offset: 0x20C) USART Interrupt Disable Register */
  __I  uint32_t US_IMR;      /**< \brief (Flexcom Offset: 0x210) USART Interrupt Mask Register */
  __I  uint32_t US_CSR;      /**< \brief (Flexcom Offset: 0x214) USART Channel Status Register */
  __I  uint32_t US_RHR;      /**< \brief (Flexcom Offset: 0x218) USART Receive Holding Register */
  __O  uint32_t US_THR;      /**< \brief (Flexcom Offset: 0x21C) USART Transmit Holding Register */
  __IO uint32_t US_BRGR;     /**< \brief (Flexcom Offset: 0x220) USART Baud Rate Generator Register */
  __IO uint32_t US_RTOR;     /**< \brief (Flexcom Offset: 0x224) USART Receiver Timeout Register */
  __IO uint32_t US_TTGR;     /**< \brief (Flexcom Offset: 0x228) USART Transmitter Timeguard Register */
  __I  uint32_t Reserved5[5];
  __IO uint32_t US_FIDI;     /**< \brief (Flexcom Offset: 0x240) USART FI DI Ratio Register */
  __I  uint32_t US_NER;      /**< \brief (Flexcom Offset: 0x244) USART Number of Errors Register */
  __I  uint32_t Reserved6[1];
  __IO uint32_t US_IF;       /**< \brief (Flexcom Offset: 0x24C) USART IrDA Filter Register */
  __IO uint32_t US_MAN;      /**< \brief (Flexcom Offset: 0x250) USART Manchester Configuration Register */
  __IO uint32_t US_LINMR;    /**< \brief (Flexcom Offset: 0x254) USART LIN Mode Register */
  __IO uint32_t US_LINIR;    /**< \brief (Flexcom Offset: 0x258) USART LIN Identifier Register */
  __I  uint32_t US_LINBRR;   /**< \brief (Flexcom Offset: 0x25C) USART LIN Baud Rate Register */
  __I  uint32_t Reserved7[12];
  __IO uint32_t US_CMPR;     /**< \brief (Flexcom Offset: 0x290) USART Comparison Register */
  __I  uint32_t Reserved8[3];
  __IO uint32_t US_FMR;      /**< \brief (Flexcom Offset: 0x2A0) USART FIFO Mode Register */
  __I  uint32_t US_FESR;     /**< \brief (Flexcom Offset: 0x2A4) USART FIFO Level Register */
  __O  uint32_t US_FIER;     /**< \brief (Flexcom Offset: 0x2A8) USART FIFO Interrupt Enable Register */
  __O  uint32_t US_FIDR;     /**< \brief (Flexcom Offset: 0x2AC) USART FIFO Interrupt Disable Register */
  __I  uint32_t US_FIMR;     /**< \brief (Flexcom Offset: 0x2B0) USART FIFO Interrupt Mask Register */
  __I  uint32_t US_FLR;      /**< \brief (Flexcom Offset: 0x2B4) USART FIFO Event Status Register */
  __I  uint32_t Reserved9[11];
  __IO uint32_t US_WPMR;     /**< \brief (Flexcom Offset: 0x2E4) USART Write Protection Mode Register */
  __I  uint32_t US_WPSR;     /**< \brief (Flexcom Offset: 0x2E8) USART Write Protection Status Register */
  __I  uint32_t Reserved10[4];
  __I  uint32_t US_VERSION;  /**< \brief (Flexcom Offset: 0x2FC) USART Version Register */
  __I  uint32_t Reserved11[64];
} FlexcomUsart;

typedef FlexcomUsart Usart;

#if defined(FLEXCOM0) && !defined(USART0)
  #define USART0 ((Usart*)((uint8_t*)FLEXCOM0 + sizeof(FlexcomShared)))
  #define ID_USART0 ID_FLEXCOM0
#endif
#if defined(FLEXCOM1) && !defined(USART1)
  #define USART1 ((Usart*)((uint8_t*)FLEXCOM1 + sizeof(FlexcomShared)))
  #define ID_USART1 ID_FLEXCOM1
#endif
#if defined(FLEXCOM2) && !defined(USART2)
  #define USART2 ((Usart*)((uint8_t*)FLEXCOM2 + sizeof(FlexcomShared)))
  #define ID_USART2 ID_FLEXCOM2
#endif
#if defined(FLEXCOM3) && !defined(USART3)
  #define USART3 ((Usart*)((uint8_t*)FLEXCOM3 + sizeof(FlexcomShared)))
  #define ID_USART3 ID_FLEXCOM3
#endif
#if defined(FLEXCOM4) && !defined(USART4)
  #define USART4 ((Usart*)((uint8_t*)FLEXCOM4 + sizeof(FlexcomShared)))
  #define ID_USART4 ID_FLEXCOM4
#endif
#if defined(FLEXCOM5) && !defined(USART5)
  #define USART5 ((Usart*)((uint8_t*)FLEXCOM5 + sizeof(FlexcomShared)))
  #define ID_USART5 ID_FLEXCOM5
#endif
#if defined(FLEXCOM6) && !defined(USART6)
  #define USART6 ((Usart*)((uint8_t*)FLEXCOM6 + sizeof(FlexcomShared)))
  #define ID_USART6 ID_FLEXCOM6
#endif
#if defined(FLEXCOM7) && !defined(USART7)
  #define USART7 ((Usart*)((uint8_t*)FLEXCOM7 + sizeof(FlexcomShared)))
  #define ID_USART7 ID_FLEXCOM7
#endif
#if defined(FLEXCOM8) && !defined(USART8)
  #define USART8 ((Usart*)((uint8_t*)FLEXCOM8 + sizeof(FlexcomShared)))
  #define ID_USART8 ID_FLEXCOM8
#endif
#if defined(FLEXCOM9) && !defined(USART9)
  #define USART9 ((Usart*)((uint8_t*)FLEXCOM9 + sizeof(FlexcomShared)))
  #define ID_USART9 ID_FLEXCOM9
#endif
#if defined(FLEXCOM10) && !defined(USART10)
  #define USART10 ((Usart*)((uint8_t*)FLEXCOM10 + sizeof(FlexcomShared)))
  #define ID_USART10 ID_FLEXCOM10
#endif
#if defined(FLEXCOM11) && !defined(USART11)
  #define USART11 ((Usart*)((uint8_t*)FLEXCOM11 + sizeof(FlexcomShared)))
  #define ID_USART11 ID_FLEXCOM11
#endif
#if defined(FLEXCOM12) && !defined(USART12)
  #define USART12 ((Usart*)((uint8_t*)FLEXCOM12 + sizeof(FlexcomShared)))
  #define ID_USART12 ID_FLEXCOM12
#endif
/* -------- FLEX_US_CR : (FLEXCOM Offset: 0x200) USART Control Register -------- */
#define US_CR_RSTRX FLEX_US_CR_RSTRX
#define US_CR_RSTTX FLEX_US_CR_RSTTX
#define US_CR_RXEN FLEX_US_CR_RXEN
#define US_CR_RXDIS FLEX_US_CR_RXDIS
#define US_CR_TXEN FLEX_US_CR_TXEN
#define US_CR_TXDIS FLEX_US_CR_TXDIS
#define US_CR_RSTSTA FLEX_US_CR_RSTSTA
#define US_CR_STTBRK FLEX_US_CR_STTBRK
#define US_CR_STPBRK FLEX_US_CR_STPBRK
#define US_CR_STTTO FLEX_US_CR_STTTO
#define US_CR_SENDA FLEX_US_CR_SENDA
#define US_CR_RSTIT FLEX_US_CR_RSTIT
#define US_CR_RSTNACK FLEX_US_CR_RSTNACK
#define US_CR_RETTO FLEX_US_CR_RETTO
#define US_CR_RTSEN FLEX_US_CR_RTSEN
#define US_CR_RTSDIS FLEX_US_CR_RTSDIS
#define US_CR_LINABT FLEX_US_CR_LINABT
#define US_CR_LINWKUP FLEX_US_CR_LINWKUP
#define US_CR_TXFCLR FLEX_US_CR_TXFCLR
#define US_CR_RXFCLR FLEX_US_CR_RXFCLR
#define US_CR_TXFLCLR FLEX_US_CR_TXFLCLR
#define US_CR_REQCLR FLEX_US_CR_REQCLR
#define US_CR_FIFOEN FLEX_US_CR_FIFOEN
#define US_CR_FIFODIS FLEX_US_CR_FIFODIS
/* -------- FLEX_US_MR : (FLEXCOM Offset: 0x204) USART Mode Register -------- */
#define US_MR_USART_MODE_Pos FLEX_US_MR_USART_MODE_Pos
#define US_MR_USART_MODE_Msk FLEX_US_MR_USART_MODE_Msk
#define US_MR_USART_MODE(value) FLEX_US_MR_USART_MODE(value) 
#define   US_MR_USART_MODE_NORMAL FLEX_US_MR_USART_MODE_NORMAL /**< \brief (FLEX_US_MR) Normal mode */
#define   US_MR_USART_MODE_RS485 FLEX_US_MR_USART_MODE_RS485 /**< \brief (FLEX_US_MR) RS485 */
#define   US_MR_USART_MODE_HW_HANDSHAKING FLEX_US_MR_USART_MODE_HW_HANDSHAKING /**< \brief (FLEX_US_MR) Hardware Handshaking */
#define   US_MR_USART_MODE_IS07816_T_0 FLEX_US_MR_USART_MODE_IS07816_T_0 /**< \brief (FLEX_US_MR) IS07816 Protocol: T = 0 */
#define   US_MR_USART_MODE_IS07816_T_1 FLEX_US_MR_USART_MODE_IS07816_T_1 /**< \brief (FLEX_US_MR) IS07816 Protocol: T = 1 */
#define   US_MR_USART_MODE_IRDA FLEX_US_MR_USART_MODE_IRDA /**< \brief (FLEX_US_MR) IrDA */
#define   US_MR_USART_MODE_LIN_MASTER FLEX_US_MR_USART_MODE_LIN_MASTER /**< \brief (FLEX_US_MR) LIN master */
#define   US_MR_USART_MODE_LIN_SLAVE FLEX_US_MR_USART_MODE_LIN_SLAVE /**< \brief (FLEX_US_MR) LIN Slave */
#define US_MR_USCLKS_Pos FLEX_US_MR_USCLKS_Pos
#define US_MR_USCLKS_Msk FLEX_US_MR_USCLKS_Msk
#define US_MR_USCLKS(value) FLEX_US_MR_USCLKS(value) 
#define   US_MR_USCLKS_MCK FLEX_US_MR_USCLKS_MCK /**< \brief (FLEX_US_MR) Peripheral clock is selected */
#define   US_MR_USCLKS_DIV FLEX_US_MR_USCLKS_DIV /**< \brief (FLEX_US_MR) Peripheral clock divided (DIV = 8) is selected */
#define   US_MR_USCLKS_PMC_PCK FLEX_US_MR_USCLKS_PMC_PCK /**< \brief (FLEX_US_MR) PMC programmable clock is selected. If the SCK pin is driven (CLKO = 1), the CD field must be greater than 1. */
#define   US_MR_USCLKS_SCK FLEX_US_MR_USCLKS_SCK /**< \brief (FLEX_US_MR) External pin SCK is selected */
#define US_MR_CHRL_Pos FLEX_US_MR_CHRL_Pos
#define US_MR_CHRL_Msk FLEX_US_MR_CHRL_Msk
#define US_MR_CHRL(value) FLEX_US_MR_CHRL(value) 
#define   US_MR_CHRL_5_BIT FLEX_US_MR_CHRL_5_BIT /**< \brief (FLEX_US_MR) Character length is 5 bits */
#define   US_MR_CHRL_6_BIT FLEX_US_MR_CHRL_6_BIT /**< \brief (FLEX_US_MR) Character length is 6 bits */
#define   US_MR_CHRL_7_BIT FLEX_US_MR_CHRL_7_BIT /**< \brief (FLEX_US_MR) Character length is 7 bits */
#define   US_MR_CHRL_8_BIT FLEX_US_MR_CHRL_8_BIT /**< \brief (FLEX_US_MR) Character length is 8 bits */
#define US_MR_SYNC FLEX_US_MR_SYNC
#define US_MR_PAR_Pos FLEX_US_MR_PAR_Pos
#define US_MR_PAR_Msk FLEX_US_MR_PAR_Msk
#define US_MR_PAR(value) FLEX_US_MR_PAR(value) 
#define   US_MR_PAR_EVEN FLEX_US_MR_PAR_EVEN /**< \brief (FLEX_US_MR) Even parity */
#define   US_MR_PAR_ODD FLEX_US_MR_PAR_ODD /**< \brief (FLEX_US_MR) Odd parity */
#define   US_MR_PAR_SPACE FLEX_US_MR_PAR_SPACE /**< \brief (FLEX_US_MR) Parity forced to 0 (Space) */
#define   US_MR_PAR_MARK FLEX_US_MR_PAR_MARK /**< \brief (FLEX_US_MR) Parity forced to 1 (Mark) */
#define   US_MR_PAR_NO FLEX_US_MR_PAR_NO /**< \brief (FLEX_US_MR) No parity */
#define   US_MR_PAR_MULTIDROP FLEX_US_MR_PAR_MULTIDROP /**< \brief (FLEX_US_MR) Multidrop mode */
#define US_MR_NBSTOP_Pos FLEX_US_MR_NBSTOP_Pos
#define US_MR_NBSTOP_Msk FLEX_US_MR_NBSTOP_Msk
#define US_MR_NBSTOP(value) FLEX_US_MR_NBSTOP(value) 
#define   US_MR_NBSTOP_1_BIT FLEX_US_MR_NBSTOP_1_BIT /**< \brief (FLEX_US_MR) 1 stop bit */
#define   US_MR_NBSTOP_1_5_BIT FLEX_US_MR_NBSTOP_1_5_BIT /**< \brief (FLEX_US_MR) 1.5 stop bit (SYNC = 0) or reserved (SYNC = 1) */
#define   US_MR_NBSTOP_2_BIT FLEX_US_MR_NBSTOP_2_BIT /**< \brief (FLEX_US_MR) 2 stop bits */
#define US_MR_CHMODE_Pos FLEX_US_MR_CHMODE_Pos
#define US_MR_CHMODE_Msk FLEX_US_MR_CHMODE_Msk
#define US_MR_CHMODE(value) FLEX_US_MR_CHMODE(value) 
#define   US_MR_CHMODE_NORMAL FLEX_US_MR_CHMODE_NORMAL /**< \brief (FLEX_US_MR) Normal mode */
#define   US_MR_CHMODE_AUTOMATIC FLEX_US_MR_CHMODE_AUTOMATIC /**< \brief (FLEX_US_MR) Automatic Echo. Receiver input is connected to the TXD pin. */
#define   US_MR_CHMODE_LOCAL_LOOPBACK FLEX_US_MR_CHMODE_LOCAL_LOOPBACK /**< \brief (FLEX_US_MR) Local Loopback. Transmitter output is connected to the Receiver Input. */
#define   US_MR_CHMODE_REMOTE_LOOPBACK FLEX_US_MR_CHMODE_REMOTE_LOOPBACK /**< \brief (FLEX_US_MR) Remote Loopback. RXD pin is internally connected to the TXD pin. */
#define US_MR_MSBF FLEX_US_MR_MSBF
#define US_MR_MODE9 FLEX_US_MR_MODE9
#define US_MR_CLKO FLEX_US_MR_CLKO
#define US_MR_OVER FLEX_US_MR_OVER
#define US_MR_INACK FLEX_US_MR_INACK
#define US_MR_DSNACK FLEX_US_MR_DSNACK
#define US_MR_VAR_SYNC FLEX_US_MR_VAR_SYNC
#define US_MR_INVDATA FLEX_US_MR_INVDATA
#define US_MR_MAX_ITERATION_Pos FLEX_US_MR_MAX_ITERATION_Pos
#define US_MR_MAX_ITERATION_Msk FLEX_US_MR_MAX_ITERATION_Msk
#define US_MR_MAX_ITERATION(value) FLEX_US_MR_MAX_ITERATION(value) 
#define US_MR_FILTER FLEX_US_MR_FILTER
#define US_MR_MAN FLEX_US_MR_MAN
#define US_MR_MODSYNC FLEX_US_MR_MODSYNC
#define US_MR_ONEBIT FLEX_US_MR_ONEBIT
/* -------- FLEX_US_IER : (FLEXCOM Offset: 0x208) USART Interrupt Enable Register -------- */
#define US_IER_RXRDY FLEX_US_IER_RXRDY
#define US_IER_TXRDY FLEX_US_IER_TXRDY
#define US_IER_RXBRK FLEX_US_IER_RXBRK
#define US_IER_OVRE FLEX_US_IER_OVRE
#define US_IER_FRAME FLEX_US_IER_FRAME
#define US_IER_PARE FLEX_US_IER_PARE
#define US_IER_TIMEOUT FLEX_US_IER_TIMEOUT
#define US_IER_TXEMPTY FLEX_US_IER_TXEMPTY
#define US_IER_ITER FLEX_US_IER_ITER
#define US_IER_NACK FLEX_US_IER_NACK
#define US_IER_CTSIC FLEX_US_IER_CTSIC
#define US_IER_CMP FLEX_US_IER_CMP
#define US_IER_MANE FLEX_US_IER_MANE
#define US_IER_LINBK FLEX_US_IER_LINBK
#define US_IER_LINID FLEX_US_IER_LINID
#define US_IER_LINTC FLEX_US_IER_LINTC
#define US_IER_LINBE FLEX_US_IER_LINBE
#define US_IER_LINISFE FLEX_US_IER_LINISFE
#define US_IER_LINIPE FLEX_US_IER_LINIPE
#define US_IER_LINCE FLEX_US_IER_LINCE
#define US_IER_LINSNRE FLEX_US_IER_LINSNRE
#define US_IER_LINSTE FLEX_US_IER_LINSTE
#define US_IER_LINHTE FLEX_US_IER_LINHTE
/* -------- FLEX_US_IDR : (FLEXCOM Offset: 0x20C) USART Interrupt Disable Register -------- */
#define US_IDR_RXRDY FLEX_US_IDR_RXRDY
#define US_IDR_TXRDY FLEX_US_IDR_TXRDY
#define US_IDR_RXBRK FLEX_US_IDR_RXBRK
#define US_IDR_OVRE FLEX_US_IDR_OVRE
#define US_IDR_FRAME FLEX_US_IDR_FRAME
#define US_IDR_PARE FLEX_US_IDR_PARE
#define US_IDR_TIMEOUT FLEX_US_IDR_TIMEOUT
#define US_IDR_TXEMPTY FLEX_US_IDR_TXEMPTY
#define US_IDR_ITER FLEX_US_IDR_ITER
#define US_IDR_NACK FLEX_US_IDR_NACK
#define US_IDR_CTSIC FLEX_US_IDR_CTSIC
#define US_IDR_CMP FLEX_US_IDR_CMP
#define US_IDR_MANE FLEX_US_IDR_MANE
#define US_IDR_LINBK FLEX_US_IDR_LINBK
#define US_IDR_LINID FLEX_US_IDR_LINID
#define US_IDR_LINTC FLEX_US_IDR_LINTC
#define US_IDR_LINBE FLEX_US_IDR_LINBE
#define US_IDR_LINISFE FLEX_US_IDR_LINISFE
#define US_IDR_LINIPE FLEX_US_IDR_LINIPE
#define US_IDR_LINCE FLEX_US_IDR_LINCE
#define US_IDR_LINSNRE FLEX_US_IDR_LINSNRE
#define US_IDR_LINSTE FLEX_US_IDR_LINSTE
#define US_IDR_LINHTE FLEX_US_IDR_LINHTE
/* -------- FLEX_US_IMR : (FLEXCOM Offset: 0x210) USART Interrupt Mask Register -------- */
#define US_IMR_RXRDY FLEX_US_IMR_RXRDY
#define US_IMR_TXRDY FLEX_US_IMR_TXRDY
#define US_IMR_RXBRK FLEX_US_IMR_RXBRK
#define US_IMR_OVRE FLEX_US_IMR_OVRE
#define US_IMR_FRAME FLEX_US_IMR_FRAME
#define US_IMR_PARE FLEX_US_IMR_PARE
#define US_IMR_TIMEOUT FLEX_US_IMR_TIMEOUT
#define US_IMR_TXEMPTY FLEX_US_IMR_TXEMPTY
#define US_IMR_ITER FLEX_US_IMR_ITER
#define US_IMR_NACK FLEX_US_IMR_NACK
#define US_IMR_CTSIC FLEX_US_IMR_CTSIC
#define US_IMR_CMP FLEX_US_IMR_CMP
#define US_IMR_MANE FLEX_US_IMR_MANE
#define US_IMR_LINBK FLEX_US_IMR_LINBK
#define US_IMR_LINID FLEX_US_IMR_LINID
#define US_IMR_LINTC FLEX_US_IMR_LINTC
#define US_IMR_LINBE FLEX_US_IMR_LINBE
#define US_IMR_LINISFE FLEX_US_IMR_LINISFE
#define US_IMR_LINIPE FLEX_US_IMR_LINIPE
#define US_IMR_LINCE FLEX_US_IMR_LINCE
#define US_IMR_LINSNRE FLEX_US_IMR_LINSNRE
#define US_IMR_LINSTE FLEX_US_IMR_LINSTE
#define US_IMR_LINHTE FLEX_US_IMR_LINHTE
/* -------- FLEX_US_CSR : (FLEXCOM Offset: 0x214) USART Channel Status Register -------- */
#define US_CSR_RXRDY FLEX_US_CSR_RXRDY
#define US_CSR_TXRDY FLEX_US_CSR_TXRDY
#define US_CSR_RXBRK FLEX_US_CSR_RXBRK
#define US_CSR_OVRE FLEX_US_CSR_OVRE
#define US_CSR_FRAME FLEX_US_CSR_FRAME
#define US_CSR_PARE FLEX_US_CSR_PARE
#define US_CSR_TIMEOUT FLEX_US_CSR_TIMEOUT
#define US_CSR_TXEMPTY FLEX_US_CSR_TXEMPTY
#define US_CSR_ITER FLEX_US_CSR_ITER
#define US_CSR_NACK FLEX_US_CSR_NACK
#define US_CSR_CTSIC FLEX_US_CSR_CTSIC
#define US_CSR_CMP FLEX_US_CSR_CMP
#define US_CSR_CTS FLEX_US_CSR_CTS
#define US_CSR_MANE FLEX_US_CSR_MANE
#define US_CSR_LINBK FLEX_US_CSR_LINBK
#define US_CSR_LINID FLEX_US_CSR_LINID
#define US_CSR_LINTC FLEX_US_CSR_LINTC
#define US_CSR_LINBLS FLEX_US_CSR_LINBLS
#define US_CSR_LINBE FLEX_US_CSR_LINBE
#define US_CSR_LINISFE FLEX_US_CSR_LINISFE
#define US_CSR_LINIPE FLEX_US_CSR_LINIPE
#define US_CSR_LINCE FLEX_US_CSR_LINCE
#define US_CSR_LINSNRE FLEX_US_CSR_LINSNRE
#define US_CSR_LINSTE FLEX_US_CSR_LINSTE
#define US_CSR_LINHTE FLEX_US_CSR_LINHTE
/* -------- FLEX_US_RHR : (FLEXCOM Offset: 0x218) USART Receive Holding Register -------- */
#define US_RHR_RXCHR_Pos FLEX_US_RHR_RXCHR_Pos
#define US_RHR_RXCHR_Msk FLEX_US_RHR_RXCHR_Msk
#define US_RHR_RXSYNH FLEX_US_RHR_RXSYNH
#define US_RHR_RXCHR0_Pos FLEX_US_RHR_RXCHR0_Pos
#define US_RHR_RXCHR0_Msk FLEX_US_RHR_RXCHR0_Msk
#define US_RHR_RXCHR1_Pos FLEX_US_RHR_RXCHR1_Pos
#define US_RHR_RXCHR1_Msk FLEX_US_RHR_RXCHR1_Msk
#define US_RHR_RXCHR2_Pos FLEX_US_RHR_RXCHR2_Pos
#define US_RHR_RXCHR2_Msk FLEX_US_RHR_RXCHR2_Msk
#define US_RHR_RXCHR3_Pos FLEX_US_RHR_RXCHR3_Pos
#define US_RHR_RXCHR3_Msk FLEX_US_RHR_RXCHR3_Msk
/* -------- FLEX_US_THR : (FLEXCOM Offset: 0x21C) USART Transmit Holding Register -------- */
#define US_THR_TXCHR_Pos FLEX_US_THR_TXCHR_Pos
#define US_THR_TXCHR_Msk FLEX_US_THR_TXCHR_Msk
#define US_THR_TXCHR(value) FLEX_US_THR_TXCHR(value) 
#define US_THR_TXSYNH FLEX_US_THR_TXSYNH
#define US_THR_TXCHR0_Pos FLEX_US_THR_TXCHR0_Pos
#define US_THR_TXCHR0_Msk FLEX_US_THR_TXCHR0_Msk
#define US_THR_TXCHR0(value) FLEX_US_THR_TXCHR0(value) 
#define US_THR_TXCHR1_Pos FLEX_US_THR_TXCHR1_Pos
#define US_THR_TXCHR1_Msk FLEX_US_THR_TXCHR1_Msk
#define US_THR_TXCHR1(value) FLEX_US_THR_TXCHR1(value) 
#define US_THR_TXCHR2_Pos FLEX_US_THR_TXCHR2_Pos
#define US_THR_TXCHR2_Msk FLEX_US_THR_TXCHR2_Msk
#define US_THR_TXCHR2(value) FLEX_US_THR_TXCHR2(value) 
#define US_THR_TXCHR3_Pos FLEX_US_THR_TXCHR3_Pos
#define US_THR_TXCHR3_Msk FLEX_US_THR_TXCHR3_Msk
#define US_THR_TXCHR3(value) FLEX_US_THR_TXCHR3(value) 
/* -------- FLEX_US_BRGR : (FLEXCOM Offset: 0x220) USART Baud Rate Generator Register -------- */
#define US_BRGR_CD_Pos FLEX_US_BRGR_CD_Pos
#define US_BRGR_CD_Msk FLEX_US_BRGR_CD_Msk
#define US_BRGR_CD(value) FLEX_US_BRGR_CD(value) 
#define US_BRGR_FP_Pos FLEX_US_BRGR_FP_Pos
#define US_BRGR_FP_Msk FLEX_US_BRGR_FP_Msk
#define US_BRGR_FP(value) FLEX_US_BRGR_FP(value) 
/* -------- FLEX_US_RTOR : (FLEXCOM Offset: 0x224) USART Receiver Timeout Register -------- */
#define US_RTOR_TO_Pos FLEX_US_RTOR_TO_Pos
#define US_RTOR_TO_Msk FLEX_US_RTOR_TO_Msk
#define US_RTOR_TO(value) FLEX_US_RTOR_TO(value) 
/* -------- FLEX_US_TTGR : (FLEXCOM Offset: 0x228) USART Transmitter Timeguard Register -------- */
#define US_TTGR_TG_Pos FLEX_US_TTGR_TG_Pos
#define US_TTGR_TG_Msk FLEX_US_TTGR_TG_Msk
#define US_TTGR_TG(value) FLEX_US_TTGR_TG(value) 
/* -------- FLEX_US_FIDI : (FLEXCOM Offset: 0x240) USART FI DI Ratio Register -------- */
#define US_FIDI_FI_DI_RATIO_Pos FLEX_US_FIDI_FI_DI_RATIO_Pos
#define US_FIDI_FI_DI_RATIO_Msk FLEX_US_FIDI_FI_DI_RATIO_Msk
#define US_FIDI_FI_DI_RATIO(value) FLEX_US_FIDI_FI_DI_RATIO(value) 
/* -------- FLEX_US_NER : (FLEXCOM Offset: 0x244) USART Number of Errors Register -------- */
#define US_NER_NB_ERRORS_Pos FLEX_US_NER_NB_ERRORS_Pos
#define US_NER_NB_ERRORS_Msk FLEX_US_NER_NB_ERRORS_Msk
/* -------- FLEX_US_IF : (FLEXCOM Offset: 0x24C) USART IrDA Filter Register -------- */
#define US_IF_IRDA_FILTER_Pos FLEX_US_IF_IRDA_FILTER_Pos
#define US_IF_IRDA_FILTER_Msk FLEX_US_IF_IRDA_FILTER_Msk
#define US_IF_IRDA_FILTER(value) FLEX_US_IF_IRDA_FILTER(value) 
/* -------- FLEX_US_MAN : (FLEXCOM Offset: 0x250) USART Manchester Configuration Register -------- */
#define US_MAN_TX_PL_Pos FLEX_US_MAN_TX_PL_Pos
#define US_MAN_TX_PL_Msk FLEX_US_MAN_TX_PL_Msk
#define US_MAN_TX_PL(value) FLEX_US_MAN_TX_PL(value) 
#define US_MAN_TX_PP_Pos FLEX_US_MAN_TX_PP_Pos
#define US_MAN_TX_PP_Msk FLEX_US_MAN_TX_PP_Msk
#define US_MAN_TX_PP(value) FLEX_US_MAN_TX_PP(value) 
#define   US_MAN_TX_PP_ALL_ONE FLEX_US_MAN_TX_PP_ALL_ONE /**< \brief (FLEX_US_MAN) The preamble is composed of '1's */
#define   US_MAN_TX_PP_ALL_ZERO FLEX_US_MAN_TX_PP_ALL_ZERO /**< \brief (FLEX_US_MAN) The preamble is composed of '0's */
#define   US_MAN_TX_PP_ZERO_ONE FLEX_US_MAN_TX_PP_ZERO_ONE /**< \brief (FLEX_US_MAN) The preamble is composed of '01's */
#define   US_MAN_TX_PP_ONE_ZERO FLEX_US_MAN_TX_PP_ONE_ZERO /**< \brief (FLEX_US_MAN) The preamble is composed of '10's */
#define US_MAN_TX_MPOL FLEX_US_MAN_TX_MPOL
#define US_MAN_RX_PL_Pos FLEX_US_MAN_RX_PL_Pos
#define US_MAN_RX_PL_Msk FLEX_US_MAN_RX_PL_Msk
#define US_MAN_RX_PL(value) FLEX_US_MAN_RX_PL(value) 
#define US_MAN_RX_PP_Pos FLEX_US_MAN_RX_PP_Pos
#define US_MAN_RX_PP_Msk FLEX_US_MAN_RX_PP_Msk
#define US_MAN_RX_PP(value) FLEX_US_MAN_RX_PP(value) 
#define   US_MAN_RX_PP_ALL_ONE FLEX_US_MAN_RX_PP_ALL_ONE /**< \brief (FLEX_US_MAN) The preamble is composed of '1's */
#define   US_MAN_RX_PP_ALL_ZERO FLEX_US_MAN_RX_PP_ALL_ZERO /**< \brief (FLEX_US_MAN) The preamble is composed of '0's */
#define   US_MAN_RX_PP_ZERO_ONE FLEX_US_MAN_RX_PP_ZERO_ONE /**< \brief (FLEX_US_MAN) The preamble is composed of '01's */
#define   US_MAN_RX_PP_ONE_ZERO FLEX_US_MAN_RX_PP_ONE_ZERO /**< \brief (FLEX_US_MAN) The preamble is composed of '10's */
#define US_MAN_RX_MPOL FLEX_US_MAN_RX_MPOL
#define US_MAN_ONE FLEX_US_MAN_ONE
#define US_MAN_DRIFT FLEX_US_MAN_DRIFT
#define US_MAN_RXIDLEV FLEX_US_MAN_RXIDLEV
/* -------- FLEX_US_LINMR : (FLEXCOM Offset: 0x254) USART LIN Mode Register -------- */
#define US_LINMR_NACT_Pos FLEX_US_LINMR_NACT_Pos
#define US_LINMR_NACT_Msk FLEX_US_LINMR_NACT_Msk
#define US_LINMR_NACT(value) FLEX_US_LINMR_NACT(value) 
#define   US_LINMR_NACT_PUBLISH FLEX_US_LINMR_NACT_PUBLISH /**< \brief (FLEX_US_LINMR) The USART transmits the response. */
#define   US_LINMR_NACT_SUBSCRIBE FLEX_US_LINMR_NACT_SUBSCRIBE /**< \brief (FLEX_US_LINMR) The USART receives the response. */
#define   US_LINMR_NACT_IGNORE FLEX_US_LINMR_NACT_IGNORE /**< \brief (FLEX_US_LINMR) The USART does not transmit and does not receive the response. */
#define US_LINMR_PARDIS FLEX_US_LINMR_PARDIS
#define US_LINMR_CHKDIS FLEX_US_LINMR_CHKDIS
#define US_LINMR_CHKTYP FLEX_US_LINMR_CHKTYP
#define US_LINMR_DLM FLEX_US_LINMR_DLM
#define US_LINMR_FSDIS FLEX_US_LINMR_FSDIS
#define US_LINMR_WKUPTYP FLEX_US_LINMR_WKUPTYP
#define US_LINMR_DLC_Pos FLEX_US_LINMR_DLC_Pos
#define US_LINMR_DLC_Msk FLEX_US_LINMR_DLC_Msk
#define US_LINMR_DLC(value) FLEX_US_LINMR_DLC(value) 
#define US_LINMR_PDCM FLEX_US_LINMR_PDCM
#define US_LINMR_SYNCDIS FLEX_US_LINMR_SYNCDIS
/* -------- FLEX_US_LINIR : (FLEXCOM Offset: 0x258) USART LIN Identifier Register -------- */
#define US_LINIR_IDCHR_Pos FLEX_US_LINIR_IDCHR_Pos
#define US_LINIR_IDCHR_Msk FLEX_US_LINIR_IDCHR_Msk
#define US_LINIR_IDCHR(value) FLEX_US_LINIR_IDCHR(value) 
/* -------- FLEX_US_LINBRR : (FLEXCOM Offset: 0x25C) USART LIN Baud Rate Register -------- */
#define US_LINBRR_LINCD_Pos FLEX_US_LINBRR_LINCD_Pos
#define US_LINBRR_LINCD_Msk FLEX_US_LINBRR_LINCD_Msk
#define US_LINBRR_LINFP_Pos FLEX_US_LINBRR_LINFP_Pos
#define US_LINBRR_LINFP_Msk FLEX_US_LINBRR_LINFP_Msk
/* -------- FLEX_US_CMPR : (FLEXCOM Offset: 0x290) USART Comparison Register -------- */
#define US_CMPR_VAL1_Pos FLEX_US_CMPR_VAL1_Pos
#define US_CMPR_VAL1_Msk FLEX_US_CMPR_VAL1_Msk
#define US_CMPR_VAL1(value) FLEX_US_CMPR_VAL1(value) 
#define US_CMPR_CMPMODE FLEX_US_CMPR_CMPMODE
#define   US_CMPR_CMPMODE_FLAG_ONLY FLEX_US_CMPR_CMPMODE_FLAG_ONLY /**< \brief (FLEX_US_CMPR) Any character is received and comparison function drives CMP flag. */
#define   US_CMPR_CMPMODE_START_CONDITION FLEX_US_CMPR_CMPMODE_START_CONDITION /**< \brief (FLEX_US_CMPR) Comparison condition must be met to start reception. */
#define US_CMPR_CMPPAR FLEX_US_CMPR_CMPPAR
#define US_CMPR_VAL2_Pos FLEX_US_CMPR_VAL2_Pos
#define US_CMPR_VAL2_Msk FLEX_US_CMPR_VAL2_Msk
#define US_CMPR_VAL2(value) FLEX_US_CMPR_VAL2(value) 
/* -------- FLEX_US_FMR : (FLEXCOM Offset: 0x2A0) USART FIFO Mode Register -------- */
#define US_FMR_TXRDYM_Pos FLEX_US_FMR_TXRDYM_Pos
#define US_FMR_TXRDYM_Msk FLEX_US_FMR_TXRDYM_Msk
#define US_FMR_TXRDYM(value) FLEX_US_FMR_TXRDYM(value) 
#define   US_FMR_TXRDYM_ONE_DATA FLEX_US_FMR_TXRDYM_ONE_DATA /**< \brief (FLEX_US_FMR) TXRDY will be at level '1' when at least one data can be written in the transmit FIFO */
#define   US_FMR_TXRDYM_TWO_DATA FLEX_US_FMR_TXRDYM_TWO_DATA /**< \brief (FLEX_US_FMR) TXRDY will be at level '1' when at least two data can be written in the transmit FIFO */
#define   US_FMR_TXRDYM_FOUR_DATA FLEX_US_FMR_TXRDYM_FOUR_DATA /**< \brief (FLEX_US_FMR) TXRDY will be at level '1' when at least four data can be written in the transmit FIFO */
#define US_FMR_RXRDYM_Pos FLEX_US_FMR_RXRDYM_Pos
#define US_FMR_RXRDYM_Msk FLEX_US_FMR_RXRDYM_Msk
#define US_FMR_RXRDYM(value) FLEX_US_FMR_RXRDYM(value) 
#define   US_FMR_RXRDYM_ONE_DATA FLEX_US_FMR_RXRDYM_ONE_DATA /**< \brief (FLEX_US_FMR) RXRDY will be at level '1' when at least one unread data is in the receive FIFO */
#define   US_FMR_RXRDYM_TWO_DATA FLEX_US_FMR_RXRDYM_TWO_DATA /**< \brief (FLEX_US_FMR) RXRDY will be at level '1' when at least two unread data are in the receive FIFO */
#define   US_FMR_RXRDYM_FOUR_DATA FLEX_US_FMR_RXRDYM_FOUR_DATA /**< \brief (FLEX_US_FMR) RXRDY will be at level '1' when at least four unread data are in the receive FIFO */
#define US_FMR_FRTSC FLEX_US_FMR_FRTSC
#define US_FMR_TXFTHRES_Pos FLEX_US_FMR_TXFTHRES_Pos
#define US_FMR_TXFTHRES_Msk FLEX_US_FMR_TXFTHRES_Msk
#define US_FMR_TXFTHRES(value) FLEX_US_FMR_TXFTHRES(value) 
#define US_FMR_RXFTHRES_Pos FLEX_US_FMR_RXFTHRES_Pos
#define US_FMR_RXFTHRES_Msk FLEX_US_FMR_RXFTHRES_Msk
#define US_FMR_RXFTHRES(value) FLEX_US_FMR_RXFTHRES(value) 
#define US_FMR_RXFTHRES2_Pos FLEX_US_FMR_RXFTHRES2_Pos
#define US_FMR_RXFTHRES2_Msk FLEX_US_FMR_RXFTHRES2_Msk
#define US_FMR_RXFTHRES2(value) FLEX_US_FMR_RXFTHRES2(value) 
/* -------- FLEX_US_FESR : (FLEXCOM Offset: 0x2A4) USART FIFO Level Register -------- */
#define US_FESR_TXFEF FLEX_US_FESR_TXFEF
#define US_FESR_TXFFF FLEX_US_FESR_TXFFF
#define US_FESR_TXFTHF FLEX_US_FESR_TXFTHF
#define US_FESR_RXFEF FLEX_US_FESR_RXFEF
#define US_FESR_RXFFF FLEX_US_FESR_RXFFF
#define US_FESR_RXFTHF FLEX_US_FESR_RXFTHF
#define US_FESR_TXFPTEF FLEX_US_FESR_TXFPTEF
#define US_FESR_RXFPTEF FLEX_US_FESR_RXFPTEF
#define US_FESR_TXFLOCK FLEX_US_FESR_TXFLOCK
#define US_FESR_RXFTHF2 FLEX_US_FESR_RXFTHF2
/* -------- FLEX_US_FIER : (FLEXCOM Offset: 0x2A8) USART FIFO Interrupt Enable Register -------- */
#define US_FIER_TXFEF FLEX_US_FIER_TXFEF
#define US_FIER_TXFFF FLEX_US_FIER_TXFFF
#define US_FIER_TXFTHF FLEX_US_FIER_TXFTHF
#define US_FIER_RXFEF FLEX_US_FIER_RXFEF
#define US_FIER_RXFFF FLEX_US_FIER_RXFFF
#define US_FIER_RXFTHF FLEX_US_FIER_RXFTHF
#define US_FIER_TXFPTEF FLEX_US_FIER_TXFPTEF
#define US_FIER_RXFPTEF FLEX_US_FIER_RXFPTEF
#define US_FIER_RXFTHF2 FLEX_US_FIER_RXFTHF2
/* -------- FLEX_US_FIDR : (FLEXCOM Offset: 0x2AC) USART FIFO Interrupt Disable Register -------- */
#define US_FIDR_TXFEF FLEX_US_FIDR_TXFEF
#define US_FIDR_TXFFF FLEX_US_FIDR_TXFFF
#define US_FIDR_TXFTHF FLEX_US_FIDR_TXFTHF
#define US_FIDR_RXFEF FLEX_US_FIDR_RXFEF
#define US_FIDR_RXFFF FLEX_US_FIDR_RXFFF
#define US_FIDR_RXFTHF FLEX_US_FIDR_RXFTHF
#define US_FIDR_TXFPTEF FLEX_US_FIDR_TXFPTEF
#define US_FIDR_RXFPTEF FLEX_US_FIDR_RXFPTEF
#define US_FIDR_RXFTHF2 FLEX_US_FIDR_RXFTHF2
/* -------- FLEX_US_FIMR : (FLEXCOM Offset: 0x2B0) USART FIFO Interrupt Mask Register -------- */
#define US_FIMR_TXFEF FLEX_US_FIMR_TXFEF
#define US_FIMR_TXFFF FLEX_US_FIMR_TXFFF
#define US_FIMR_TXFTHF FLEX_US_FIMR_TXFTHF
#define US_FIMR_RXFEF FLEX_US_FIMR_RXFEF
#define US_FIMR_RXFFF FLEX_US_FIMR_RXFFF
#define US_FIMR_RXFTHF FLEX_US_FIMR_RXFTHF
#define US_FIMR_TXFPTEF FLEX_US_FIMR_TXFPTEF
#define US_FIMR_RXFPTEF FLEX_US_FIMR_RXFPTEF
#define US_FIMR_RXFTHF2 FLEX_US_FIMR_RXFTHF2
/* -------- FLEX_US_FLR : (FLEXCOM Offset: 0x2B4) USART FIFO Event Status Register -------- */
#define US_FLR_TXFL_Pos FLEX_US_FLR_TXFL_Pos
#define US_FLR_TXFL_Msk FLEX_US_FLR_TXFL_Msk
#define US_FLR_RXFL_Pos FLEX_US_FLR_RXFL_Pos
#define US_FLR_RXFL_Msk FLEX_US_FLR_RXFL_Msk
/* -------- FLEX_US_WPMR : (FLEXCOM Offset: 0x2E4) USART Write Protection Mode Register -------- */
#define US_WPMR_WPEN FLEX_US_WPMR_WPEN
#define US_WPMR_WPKEY_Pos FLEX_US_WPMR_WPKEY_Pos
#define US_WPMR_WPKEY_Msk FLEX_US_WPMR_WPKEY_Msk
#define US_WPMR_WPKEY(value) FLEX_US_WPMR_WPKEY(value) 
#define   US_WPMR_WPKEY_PASSWD FLEX_US_WPMR_WPKEY_PASSWD /**< \brief (FLEX_US_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. */
/* -------- FLEX_US_WPSR : (FLEXCOM Offset: 0x2E8) USART Write Protection Status Register -------- */
#define US_WPSR_WPVS FLEX_US_WPSR_WPVS
#define US_WPSR_WPVSRC_Pos FLEX_US_WPSR_WPVSRC_Pos
#define US_WPSR_WPVSRC_Msk FLEX_US_WPSR_WPVSRC_Msk
/* -------- FLEX_US_VERSION : (FLEXCOM Offset: 0x2FC) USART Version Register -------- */
#define US_VERSION_VERSION_Pos FLEX_US_VERSION_VERSION_Pos
#define US_VERSION_VERSION_Msk FLEX_US_VERSION_VERSION_Msk
#define US_VERSION_MFN_Pos FLEX_US_VERSION_MFN_Pos
#define US_VERSION_MFN_Msk FLEX_US_VERSION_MFN_Msk

//#warning "JCK 01apr15 : map Usart to Flexcom-Usart for backward compatibility"

// FLEXCOM to SPI wrapper ------------------------------------------------------
// !!! not mappable to the Qspi software structure of the SAMA5D2 stand alone QSPIs
// (mappable only from _CR to _IMR)
typedef struct {
  __O  uint32_t SPI_CR;      /**< \brief (Flexcom Offset: 0x400) SPI Control Register */
  __IO uint32_t SPI_MR;      /**< \brief (Flexcom Offset: 0x404) SPI Mode Register */
  __I  uint32_t SPI_RDR;     /**< \brief (Flexcom Offset: 0x408) SPI Receive Data Register */
  __O  uint32_t SPI_TDR;     /**< \brief (Flexcom Offset: 0x40C) SPI Transmit Data Register */
  __I  uint32_t SPI_SR;      /**< \brief (Flexcom Offset: 0x410) SPI Status Register */
  __O  uint32_t SPI_IER;     /**< \brief (Flexcom Offset: 0x414) SPI Interrupt Enable Register */
  __O  uint32_t SPI_IDR;     /**< \brief (Flexcom Offset: 0x418) SPI Interrupt Disable Register */
  __I  uint32_t SPI_IMR;     /**< \brief (Flexcom Offset: 0x41C) SPI Interrupt Mask Register */
  __I  uint32_t Reserved12[4];
  __IO uint32_t SPI_CSR[2];  /**< \brief (Flexcom Offset: 0x430) SPI Chip Select Register */
  __I  uint32_t Reserved13[2];
  __IO uint32_t SPI_FMR;     /**< \brief (Flexcom Offset: 0x440) SPI FIFO Mode Register */
  __I  uint32_t SPI_FLR;     /**< \brief (Flexcom Offset: 0x444) SPI FIFO Level Register */
  __IO uint32_t SPI_CMPR;    /**< \brief (Flexcom Offset: 0x448) SPI Comparison Register */
  __I  uint32_t Reserved14[38];
  __IO uint32_t SPI_WPMR;    /**< \brief (Flexcom Offset: 0x4E4) SPI Write Protection Mode Register */
  __I  uint32_t SPI_WPSR;    /**< \brief (Flexcom Offset: 0x4E8) SPI Write Protection Status Register */
  __I  uint32_t Reserved15[4];
  __I  uint32_t SPI_VERSION; /**< \brief (Flexcom Offset: 0x4FC) SPI Version Register */
  __I  uint32_t Reserved16[64];
} FlexcomSpi;


#if (SPI_IS_FLEXCOM==1)
  typedef FlexcomSpi Spi;
  /* -------- FLEX_SPI_xx : (FLEXCOM Offset: 0x400) SPI Control Register -------- */
  #define SPI_CR_SPIEN       FLEX_SPI_CR_SPIEN
  #define SPI_CR_SPIDIS      FLEX_SPI_CR_SPIDIS
  #define SPI_CR_SWRST       FLEX_SPI_CR_SWRST
  #define SPI_CR_LASTXFER    FLEX_SPI_CR_LASTXFER

  #define SPI_MR_MSTR        FLEX_SPI_MR_MSTR
  #define SPI_MR_PS          FLEX_SPI_MR_PS
  #define SPI_MR_PCSDEC      FLEX_SPI_MR_PCSDEC
  #define SPI_MR_MODFDIS     FLEX_SPI_MR_MODFDIS
  #define SPI_MR_LLB         FLEX_SPI_MR_LLB
  #define SPI_MR_WDRBT       FLEX_SPI_MR_WDRBT
  #define SPI_MR_PCS         FLEX_SPI_MR_PCS
  #define SPI_MR_DLYBCS      FLEX_SPI_MR_DLYBCS

  #define SPI_SR_RDRF         FLEX_SPI_SR_RDRF
  #define SPI_SR_OVRES        FLEX_SPI_SR_OVRES
  #define SPI_SR_TDRE         FLEX_SPI_SR_TDRE
  #define SPI_SR_TXEMPTY      FLEX_SPI_SR_TXEMPTY
  #define SPI_SR_UNDES        FLEX_SPI_SR_UNDES
  #define SPI_SR_NSSR         FLEX_SPI_SR_NSSR

  #define SPI_WPMR_WPKEY      FLEX_SPI_WPMR_WPKEY
  #define SPI_WPMR_WPKEY_Pos    FLEX_SPI_WPMR_WPKEY_Pos
  #define SPI_WPMR_WPKEY_Msk    FLEX_SPI_WPMR_WPKEY_Msk
  #define SPI_WPMR_WPKEY        FLEX_SPI_WPMR_WPKEY
  #define SPI_WPMR_WPKEY_PASSWD FLEX_SPI_WPMR_WPKEY_PASSWD 

  #define SPI_CSR_NCPHA       FLEX_SPI_CSR_NCPHA
  #define SPI_CSR_BITS_8_BIT  FLEX_SPI_CSR_BITS_8_BIT
  #define SPI_CSR_CPOL        FLEX_SPI_CSR_CPOL
  #define SPI_CSR_CSAAT       FLEX_SPI_CSR_CSAAT
  #define SPI_CSR_SCBR        FLEX_SPI_CSR_SCBR
  #define SPI_CSR_DLYBS       FLEX_SPI_CSR_DLYBS
  #define SPI_CSR_DLYBCT      FLEX_SPI_CSR_DLYBCT

  #define SPI_IER_TDRE        FLEX_SPI_IER_TDRE
  #define SPI_IER_RDRF        FLEX_SPI_IER_RDRF

  #define SPI_RDR_RD_Msk    FLEX_SPI_RDR_RD_Msk
  #define SPI_RDR_RD_Pos    FLEX_SPI_RDR_RD_Pos
  #define SPI_RDR_PCS_Msk   FLEX_SPI_RDR_PCS_Msk
  #define SPI_RDR_PCS_Pos   FLEX_SPI_RDR_PCS_Pos

  #define SPI_TDR_PCS       FLEX_SPI_TDR_PCS
  #define SPI_TDR_TD        FLEX_SPI_TDR_TD
  #define SPI_TDR_LASTXFER  FLEX_SPI_TDR_LASTXFER
#endif

#if defined(FLEXCOM0) && !defined(SPI0)
  #define SPI0 ((Spi*)((uint8_t*)FLEXCOM0 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI0 ID_FLEXCOM0
#endif
#if defined(FLEXCOM1) && !defined(SPI1)
  #define SPI1 ((Spi*)((uint8_t*)FLEXCOM1 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI1 ID_FLEXCOM1
#endif
#if defined(FLEXCOM2) && !defined(SPI2)
  #define SPI2 ((Spi*)((uint8_t*)FLEXCOM2 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI2 ID_FLEXCOM2
#endif
#if defined(FLEXCOM3) && !defined(SPI3)
  #define SPI3 ((Spi*)((uint8_t*)FLEXCOM3 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI3 ID_FLEXCOM3
#endif
#if defined(FLEXCOM4) && !defined(SPI4)
  #define SPI4 ((Spi*)((uint8_t*)FLEXCOM4 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI4 ID_FLEXCOM4
#endif
#if defined(FLEXCOM5) && !defined(SPI5)
  #define SPI5 ((Spi*)((uint8_t*)FLEXCOM5 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI5 ID_FLEXCOM5
#endif
#if defined(FLEXCOM6) && !defined(SPI6)
  #define SPI6 ((Spi*)((uint8_t*)FLEXCOM6 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI6 ID_FLEXCOM6
#endif  
#if defined(FLEXCOM7) && !defined(SPI7)
  #define SPI7 ((Spi*)((uint8_t*)FLEXCOM7 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI7 ID_FLEXCOM7
#endif
#if defined(FLEXCOM8) && !defined(SPI8)
  #define SPI8 ((Spi*)((uint8_t*)FLEXCOM8 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI8 ID_FLEXCOM8
#endif  
#if defined(FLEXCOM9) && !defined(SPI9)
  #define SPI9 ((Spi*)((uint8_t*)FLEXCOM9 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI9 ID_FLEXCOM9
#endif
#if defined(FLEXCOM10) && !defined(SPI10)
  #define SPI10 ((Spi*)((uint8_t*)FLEXCOM10 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI10 ID_FLEXCOM10
#endif
#if defined(FLEXCOM11) && !defined(USART11)
  #define SPI11 ((Spi*)((uint8_t*)FLEXCOM11 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI11 ID_FLEXCOM11
#endif
#if defined(FLEXCOM12) && !defined(USART12)
  #define SPI12 ((Spi*)((uint8_t*)FLEXCOM12 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)))
  #define ID_SPI12 ID_FLEXCOM12
#endif

typedef struct {
  
 ////// MNn adding the following which seemed to be omitted
  __O  uint32_t TWI_CR;      /**< \brief (Flexcom Offset: 0x600) TWI Control Register */
  __IO uint32_t TWI_MMR;     /**< \brief (Flexcom Offset: 0x604) TWI Master Mode Register */
  __IO uint32_t TWI_SMR;     /**< \brief (Flexcom Offset: 0x608) TWI Slave Mode Register */
  __IO uint32_t TWI_IADR;    /**< \brief (Flexcom Offset: 0x60C) TWI Internal Address Register */
  __IO uint32_t TWI_CWGR;    /**< \brief (Flexcom Offset: 0x610) TWI Clock Waveform Generator Register */
  __I  uint32_t Reserved16[3];
////// finish
 
  __I  uint32_t TWI_SR;      /**< \brief (Flexcom Offset: 0x620) TWI Status Register */
  __O  uint32_t TWI_IER;     /**< \brief (Flexcom Offset: 0x624) TWI Interrupt Enable Register */
  __O  uint32_t TWI_IDR;     /**< \brief (Flexcom Offset: 0x628) TWI Interrupt Disable Register */
  __I  uint32_t TWI_IMR;     /**< \brief (Flexcom Offset: 0x62C) TWI Interrupt Mask Register */
  __I  uint32_t TWI_RHR;     /**< \brief (Flexcom Offset: 0x630) TWI Receive Holding Register */
  __O  uint32_t TWI_THR;     /**< \brief (Flexcom Offset: 0x634) TWI Transmit Holding Register */
  __IO uint32_t TWI_SMBTR;   /**< \brief (Flexcom Offset: 0x638) TWI SMBus Timing Register */
  __I  uint32_t Reserved18[1];
  __IO uint32_t TWI_ACR;     /**< \brief (Flexcom Offset: 0x640) TWI Alternative Command Register */
  __IO uint32_t TWI_FILTR;   /**< \brief (Flexcom Offset: 0x644) TWI Filter Register */
  __I  uint32_t Reserved19[1];
  __IO uint32_t TWI_SWMR;    /**< \brief (Flexcom Offset: 0x64C) TWI SleepWalking Matching Register */
  __IO uint32_t TWI_FMR;     /**< \brief (Flexcom Offset: 0x650) TWI FIFO Mode Register */
  __I  uint32_t TWI_FLR;     /**< \brief (Flexcom Offset: 0x654) TWI FIFO Level Register */
  __I  uint32_t Reserved20[2];
  __I  uint32_t TWI_FSR;     /**< \brief (Flexcom Offset: 0x660) TWI FIFO Status Register */
  __O  uint32_t TWI_FIER;    /**< \brief (Flexcom Offset: 0x664) TWI FIFO Interrupt Enable Register */
  __O  uint32_t TWI_FIDR;    /**< \brief (Flexcom Offset: 0x668) TWI FIFO Interrupt Disable Register */
  __I  uint32_t TWI_FIMR;    /**< \brief (Flexcom Offset: 0x66C) TWI FIFO Interrupt Mask Register */
  __I  uint32_t Reserved21[24];
  __I  uint32_t TWI_DR;      /**< \brief (Flexcom Offset: 0x6D0) TWI Debug Register */
  __I  uint32_t Reserved22[4];
  __IO uint32_t TWI_WPMR;    /**< \brief (Flexcom Offset: 0x6E4) TWI Protection Mode Register */
  __I  uint32_t TWI_WPSR;    /**< \brief (Flexcom Offset: 0x6E8) TWI Protection Status Register */
  __I  uint32_t Reserved23[4];
  __I  uint32_t TWI_VER;     /**< \brief (Flexcom Offset: 0x6FC) TWI Version Register */
} FlexcomTwi;

/*following added by MNn 10 nov '16*/
#if (TWI_IS_FLEXCOM==1)
  typedef FlexcomTwi Twi;
 /* -------- FLEX_TWI_xx : (FLEXCOM Offset: 0x600) TWI Control Register -------- */   
#define TWI_CR_START   FLEX_TWI_CR_START 
#define TWI_CR_STOP    FLEX_TWI_CR_STOP 
#define TWI_CR_MSEN    FLEX_TWI_CR_MSEN 
#define TWI_CR_MSDIS   FLEX_TWI_CR_MSDIS 
#define TWI_CR_SVEN    FLEX_TWI_CR_SVEN 
#define TWI_CR_SVDIS   FLEX_TWI_CR_SVDIS 
#define TWI_CR_QUICK   FLEX_TWI_CR_QUICK 
#define TWI_CR_SWRST   FLEX_TWI_CR_SWRST 
#define TWI_CR_HSEN    FLEX_TWI_CR_HSEN 
#define TWI_CR_HSDIS   FLEX_TWI_CR_HSDIS 
#define TWI_CR_SMBEN   FLEX_TWI_CR_SMBEN 
#define TWI_CR_SMBDIS  FLEX_TWI_CR_SMBDIS
#define TWI_CR_PECEN   FLEX_TWI_CR_PECEN 
#define TWI_CR_PECDIS  FLEX_TWI_CR_PECDIS
#define TWI_CR_PECRQ   FLEX_TWI_CR_PECRQ 
#define TWI_CR_CLEAR   FLEX_TWI_CR_CLEAR 
#define TWI_CR_ACMEN   FLEX_TWI_CR_ACMEN 
#define TWI_CR_ACMDIS  FLEX_TWI_CR_ACMDIS
#define TWI_CR_THRCLR  FLEX_TWI_CR_THRCLR
#define TWI_CR_LOCKCLR FLEX_TWI_CR_LOCKCLR
#define TWI_CR_FIFOEN  FLEX_TWI_CR_FIFOEN 
#define TWI_CR_FIFODIS FLEX_TWI_CR_FIFODIS
/* -------- FLEX_TWI_MMR : (FLEXCOM Offset: 0x604) TWI Master Mode Register -------- */
#define TWI_MMR_IADRSZ_Pos    FLEX_TWI_MMR_IADRSZ_Pos 
#define TWI_MMR_IADRSZ_Msk    FLEX_TWI_MMR_IADRSZ_Msk 
#define TWI_MMR_IADRSZ(value) FLEX_TWI_MMR_IADRSZ(value) 
#define TWI_MMR_IADRSZ_NONE   FLEX_TWI_MMR_IADRSZ_NONE  
#define TWI_MMR_IADRSZ_1_BYTE FLEX_TWI_MMR_IADRSZ_1_BYTE
#define TWI_MMR_IADRSZ_2_BYTE FLEX_TWI_MMR_IADRSZ_2_BYTE
#define TWI_MMR_IADRSZ_3_BYTE FLEX_TWI_MMR_IADRSZ_3_BYTE
#define TWI_MMR_MREAD         FLEX_TWI_MMR_MREAD 
#define TWI_MMR_DADR_Pos      FLEX_TWI_MMR_DADR_Pos 
#define TWI_MMR_DADR_Msk      FLEX_TWI_MMR_DADR_Msk 
#define TWI_MMR_DADR(value)   FLEX_TWI_MMR_DADR(value)
#define TWI_MMR_NOAP          FLEX_TWI_MMR_NOAP 
/* -------- FLEX_TWI_SMR : (FLEXCOM Offset: 0x608) TWI Slave Mode Register -------- */
#define TWI_SMR_NACKEN      FLEX_TWI_SMR_NACKEN 
#define TWI_SMR_SMDA        FLEX_TWI_SMR_SMDA 
#define TWI_SMR_SMHH        FLEX_TWI_SMR_SMHH 
#define TWI_SMR_SADAT       FLEX_TWI_SMR_SADAT 
#define TWI_SMR_SCLWSDIS    FLEX_TWI_SMR_SCLWSDIS
#define TWI_SMR_MASK_Pos    FLEX_TWI_SMR_MASK_Pos
#define TWI_SMR_MASK_Msk    FLEX_TWI_SMR_MASK_Msk
#define TWI_SMR_MASK(value) FLEX_TWI_SMR_MASK(value)
#define TWI_SMR_SADR_Pos    FLEX_TWI_SMR_SADR_Pos 
#define TWI_SMR_SADR_Msk    FLEX_TWI_SMR_SADR_Msk 
#define TWI_SMR_SADR(value) FLEX_TWI_SMR_SADR(value)
#define TWI_SMR_SADR1EN     FLEX_TWI_SMR_SADR1EN 
#define TWI_SMR_SADR2EN     FLEX_TWI_SMR_SADR2EN 
#define TWI_SMR_SADR3EN     FLEX_TWI_SMR_SADR3EN 
#define TWI_SMR_DATAMEN     FLEX_TWI_SMR_DATAMEN 
/* -------- FLEX_TWI_IADR : (FLEXCOM Offset: 0x60C) TWI Internal Address Register -------- */
#define TWI_IADR_IADR_Pos   FLEX_TWI_IADR_IADR_Pos 
#define TWI_IADR_IADR_Msk   FLEX_TWI_IADR_IADR_Msk 
#define TWI_IADR_IADR(value)FLEX_TWI_IADR_IADR(value)
/* -------- FLEX_TWI_CWGR : (FLEXCOM Offset: 0x610) TWI Clock Waveform Generator Register -------- */
#define TWI_CWGR_CLDIV_Pos           FLEX_TWI_CWGR_CLDIV_Pos 
#define TWI_CWGR_CLDIV_Msk           FLEX_TWI_CWGR_CLDIV_Msk 
#define TWI_CWGR_CLDIV(value)        FLEX_TWI_CWGR_CLDIV(value) 
#define TWI_CWGR_CHDIV_Pos           FLEX_TWI_CWGR_CHDIV_Pos
#define TWI_CWGR_CHDIV_Msk           FLEX_TWI_CWGR_CHDIV_Msk
#define TWI_CWGR_CHDIV(value)        FLEX_TWI_CWGR_CHDIV(value)
#define TWI_CWGR_CKDIV_Pos           FLEX_TWI_CWGR_CKDIV_Pos
#define TWI_CWGR_CKDIV_Msk           FLEX_TWI_CWGR_CKDIV_Msk 
#define TWI_CWGR_CKDIV(value)        FLEX_TWI_CWGR_CKDIV(value) 
#define TWI_CWGR_BRSRCCLK            FLEX_TWI_CWGR_BRSRCCLK 
#define TWI_CWGR_BRSRCCLK_PERIPH_CLK FLEX_TWI_CWGR_BRSRCCLK_PERIPH_CLK 
#define TWI_CWGR_BRSRCCLK_GCLK       FLEX_TWI_CWGR_BRSRCCLK_GCLK 
#define TWI_CWGR_HOLD_Pos            FLEX_TWI_CWGR_HOLD_Pos 
#define TWI_CWGR_HOLD_Msk            FLEX_TWI_CWGR_HOLD_Msk 
#define TWI_CWGR_HOLD(value)         FLEX_TWI_CWGR_HOLD(value) 
/* -------- FLEX_TWI_SR : (FLEXCOM Offset: 0x620) TWI Status Register -------- */
#define TWI_SR_TXCOMP  FLEX_TWI_SR_TXCOMP 
#define TWI_SR_RXRDY   FLEX_TWI_SR_RXRDY 
#define TWI_SR_TXRDY   FLEX_TWI_SR_TXRDY 
#define TWI_SR_SVREAD  FLEX_TWI_SR_SVREAD 
#define TWI_SR_SVACC   FLEX_TWI_SR_SVACC 
#define TWI_SR_GACC    FLEX_TWI_SR_GACC 
#define TWI_SR_OVRE    FLEX_TWI_SR_OVRE 
#define TWI_SR_UNRE    FLEX_TWI_SR_UNRE 
#define TWI_SR_NACK    FLEX_TWI_SR_NACK 
#define TWI_SR_ARBLST  FLEX_TWI_SR_ARBLST 
#define TWI_SR_SCLWS   FLEX_TWI_SR_SCLWS 
#define TWI_SR_EOSACC  FLEX_TWI_SR_EOSACC 
#define TWI_SR_MCACK   FLEX_TWI_SR_MCACK 
#define TWI_SR_TOUT    FLEX_TWI_SR_TOUT 
#define TWI_SR_PECERR  FLEX_TWI_SR_PECERR 
#define TWI_SR_SMBDAM  FLEX_TWI_SR_SMBDAM 
#define TWI_SR_SMBHHM  FLEX_TWI_SR_SMBHHM 
#define TWI_SR_LOCK    FLEX_TWI_SR_LOCK 
#define TWI_SR_SCL     FLEX_TWI_SR_SCL 
#define TWI_SR_SDA     FLEX_TWI_SR_SDA 
#define TWI_SR_SR      FLEX_TWI_SR_SR 
/* -------- FLEX_TWI_IER : (FLEXCOM Offset: 0x624) TWI Interrupt Enable Register -------- */
#define TWI_IER_TXCOMP   FLEX_TWI_IER_TXCOMP
#define TWI_IER_RXRDY    FLEX_TWI_IER_RXRDY 
#define TWI_IER_TXRDY    FLEX_TWI_IER_TXRDY 
#define TWI_IER_SVACC    FLEX_TWI_IER_SVACC 
#define TWI_IER_GACC     FLEX_TWI_IER_GACC 
#define TWI_IER_OVRE     FLEX_TWI_IER_OVRE 
#define TWI_IER_UNRE     FLEX_TWI_IER_UNRE 
#define TWI_IER_NACK     FLEX_TWI_IER_NACK 
#define TWI_IER_ARBLST   FLEX_TWI_IER_ARBLST
#define TWI_IER_SCL_WS   FLEX_TWI_IER_SCL_WS
#define TWI_IER_EOSACC   FLEX_TWI_IER_EOSACC
#define TWI_IER_ENDRX    FLEX_TWI_IER_ENDRX 
#define TWI_IER_ENDTX    FLEX_TWI_IER_ENDTX 
#define TWI_IER_RXBUFF   FLEX_TWI_IER_RXBUFF
#define TWI_IER_TXBUFE   FLEX_TWI_IER_TXBUFE
#define TWI_IER_MCACK    FLEX_TWI_IER_MCACK 
#define TWI_IER_TOUT     FLEX_TWI_IER_TOUT 
#define TWI_IER_PECERR   FLEX_TWI_IER_PECERR
#define TWI_IER_SMBDAM   FLEX_TWI_IER_SMBDAM
#define TWI_IER_SMBHHM   FLEX_TWI_IER_SMBHHM
/* -------- FLEX_TWI_IDR : (FLEXCOM Offset: 0x628) TWI Interrupt Disable Register -------- */
#define TWI_IDR_TXCOMP  FLEX_TWI_IDR_TXCOMP 
#define TWI_IDR_RXRDY   FLEX_TWI_IDR_RXRDY 
#define TWI_IDR_TXRDY   FLEX_TWI_IDR_TXRDY 
#define TWI_IDR_SVACC   FLEX_TWI_IDR_SVACC 
#define TWI_IDR_GACC    FLEX_TWI_IDR_GACC 
#define TWI_IDR_OVRE    FLEX_TWI_IDR_OVRE 
#define TWI_IDR_UNRE    FLEX_TWI_IDR_UNRE 
#define TWI_IDR_NACK    FLEX_TWI_IDR_NACK 
#define TWI_IDR_ARBLST  FLEX_TWI_IDR_ARBLST 
#define TWI_IDR_SCL_WS  FLEX_TWI_IDR_SCL_WS 
#define TWI_IDR_EOSACC  FLEX_TWI_IDR_EOSACC 
#define TWI_IDR_ENDRX   FLEX_TWI_IDR_ENDRX 
#define TWI_IDR_ENDTX   FLEX_TWI_IDR_ENDTX 
#define TWI_IDR_RXBUFF  FLEX_TWI_IDR_RXBUFF 
#define TWI_IDR_TXBUFE  FLEX_TWI_IDR_TXBUFE 
#define TWI_IDR_MCACK   FLEX_TWI_IDR_MCACK 
#define TWI_IDR_TOUT    FLEX_TWI_IDR_TOUT 
#define TWI_IDR_PECERR  FLEX_TWI_IDR_PECERR 
#define TWI_IDR_SMBDAM  FLEX_TWI_IDR_SMBDAM 
#define TWI_IDR_SMBHHM  FLEX_TWI_IDR_SMBHHM 
/* -------- FLEX_TWI_IMR : (FLEXCOM Offset: 0x62C) TWI Interrupt Mask Register -------- */
#define TWI_IMR_TXCOMP    FLEX_TWI_IMR_TXCOMP 
#define TWI_IMR_RXRDY     FLEX_TWI_IMR_RXRDY 
#define TWI_IMR_TXRDY     FLEX_TWI_IMR_TXRDY 
#define TWI_IMR_SVACC     FLEX_TWI_IMR_SVACC 
#define TWI_IMR_GACC      FLEX_TWI_IMR_GACC 
#define TWI_IMR_OVRE      FLEX_TWI_IMR_OVRE 
#define TWI_IMR_UNRE      FLEX_TWI_IMR_UNRE 
#define TWI_IMR_NACK      FLEX_TWI_IMR_NACK 
#define TWI_IMR_ARBLST    FLEX_TWI_IMR_ARBLST 
#define TWI_IMR_SCL_WS    FLEX_TWI_IMR_SCL_WS 
#define TWI_IMR_EOSACC    FLEX_TWI_IMR_EOSACC 
#define TWI_IMR_ENDRX     FLEX_TWI_IMR_ENDRX 
#define TWI_IMR_ENDTX     FLEX_TWI_IMR_ENDTX 
#define TWI_IMR_RXBUFF    FLEX_TWI_IMR_RXBUFF 
#define TWI_IMR_TXBUFE    FLEX_TWI_IMR_TXBUFE 
#define TWI_IMR_MCACK     FLEX_TWI_IMR_MCACK 
#define TWI_IMR_TOUT      FLEX_TWI_IMR_TOUT 
#define TWI_IMR_PECERR    FLEX_TWI_IMR_PECERR 
#define TWI_IMR_SMBDAM    FLEX_TWI_IMR_SMBDAM 
#define TWI_IMR_SMBHHM    FLEX_TWI_IMR_SMBHHM 
/* -------- FLEX_TWI_RHR : (FLEXCOM Offset: 0x630) TWI Receive Holding Register -------- */
#define TWI_RHR_RXDATA_Pos  FLEX_TWI_RHR_RXDATA_Pos 
#define TWI_RHR_RXDATA_Msk  FLEX_TWI_RHR_RXDATA_Msk 
#define TWI_RHR_RXDATA0_Pos FLEX_TWI_RHR_RXDATA0_Pos
#define TWI_RHR_RXDATA0_Msk FLEX_TWI_RHR_RXDATA0_Msk
#define TWI_RHR_RXDATA1_Pos FLEX_TWI_RHR_RXDATA1_Pos
#define TWI_RHR_RXDATA1_Msk FLEX_TWI_RHR_RXDATA1_Msk
#define TWI_RHR_RXDATA2_Pos FLEX_TWI_RHR_RXDATA2_Pos
#define TWI_RHR_RXDATA2_Msk FLEX_TWI_RHR_RXDATA2_Msk
#define TWI_RHR_RXDATA3_Pos FLEX_TWI_RHR_RXDATA3_Pos
#define TWI_RHR_RXDATA3_Msk FLEX_TWI_RHR_RXDATA3_Msk
/* -------- FLEX_TWI_THR : (FLEXCOM Offset: 0x634) TWI Transmit Holding Register -------- */
#define TWI_THR_TXDATA_Pos     FLEX_TWI_THR_TXDATA_Pos 
#define TWI_THR_TXDATA_Msk     FLEX_TWI_THR_TXDATA_Msk 
#define TWI_THR_TXDATA(value)  FLEX_TWI_THR_TXDATA(value) 
#define TWI_THR_TXDATA0_Pos    FLEX_TWI_THR_TXDATA0_Pos 
#define TWI_THR_TXDATA0_Msk    FLEX_TWI_THR_TXDATA0_Msk 
#define TWI_THR_TXDATA0(value) FLEX_TWI_THR_TXDATA0(value)
#define TWI_THR_TXDATA1_Pos    FLEX_TWI_THR_TXDATA1_Pos 
#define TWI_THR_TXDATA1_Msk    FLEX_TWI_THR_TXDATA1_Msk 
#define TWI_THR_TXDATA1(value) FLEX_TWI_THR_TXDATA1(value)
#define TWI_THR_TXDATA2_Pos    FLEX_TWI_THR_TXDATA2_Pos 
#define TWI_THR_TXDATA2_Msk    FLEX_TWI_THR_TXDATA2_Msk 
#define TWI_THR_TXDATA2(value) FLEX_TWI_THR_TXDATA2(value)
#define TWI_THR_TXDATA3_Pos    FLEX_TWI_THR_TXDATA3_Pos 
#define TWI_THR_TXDATA3_Msk    FLEX_TWI_THR_TXDATA3_Msk 
#define TWI_THR_TXDATA3(value) FLEX_TWI_THR_TXDATA3(value)
/* -------- FLEX_TWI_SMBTR : (FLEXCOM Offset: 0x638) TWI SMBus Timing Register -------- */
#define TWI_SMBTR_PRESC_Pos    FLEX_TWI_SMBTR_PRESC_Pos 
#define TWI_SMBTR_PRESC_Msk    FLEX_TWI_SMBTR_PRESC_Msk 
#define TWI_SMBTR_PRESC(value) FLEX_TWI_SMBTR_PRESC(value) 
#define TWI_SMBTR_TLOWS_Pos 8  FLEX_TWI_SMBTR_TLOWS_Pos 8
#define TWI_SMBTR_TLOWS_Msk    FLEX_TWI_SMBTR_TLOWS_Msk 
#define TWI_SMBTR_TLOWS(value) FLEX_TWI_SMBTR_TLOWS(value) 
#define TWI_SMBTR_TLOWM_Pos    FLEX_TWI_SMBTR_TLOWM_Pos 
#define TWI_SMBTR_TLOWM_Msk    FLEX_TWI_SMBTR_TLOWM_Msk 
#define TWI_SMBTR_TLOWM(value) FLEX_TWI_SMBTR_TLOWM(value) 
#define TWI_SMBTR_THMAX_Pos    FLEX_TWI_SMBTR_THMAX_Pos 
#define TWI_SMBTR_THMAX_Msk    FLEX_TWI_SMBTR_THMAX_Msk 
#define TWI_SMBTR_THMAX(value) FLEX_TWI_SMBTR_THMAX(value) 
/* -------- FLEX_TWI_ACR : (FLEXCOM Offset: 0x640) TWI Alternative Command Register -------- */
#define TWI_ACR_DATAL_Pos    FLEX_TWI_ACR_DATAL_Pos 
#define TWI_ACR_DATAL_Msk    FLEX_TWI_ACR_DATAL_Msk 
#define TWI_ACR_DATAL(value) FLEX_TWI_ACR_DATAL(value) 
#define TWI_ACR_DIR          FLEX_TWI_ACR_DIR 
#define TWI_ACR_PEC          FLEX_TWI_ACR_PEC 
#define TWI_ACR_NDATAL_Pos   FLEX_TWI_ACR_NDATAL_Pos 
#define TWI_ACR_NDATAL_Msk   FLEX_TWI_ACR_NDATAL_Msk 
#define TWI_ACR_NDATAL(value)FLEX_TWI_ACR_NDATAL(value)  
#define TWI_ACR_NDIR         FLEX_TWI_ACR_NDIR  
#define TWI_ACR_NPEC         FLEX_TWI_ACR_NPEC  
/* -------- FLEX_TWI_FILTR : (FLEXCOM Offset: 0x644) TWI Filter Register -------- */
#define TWI_FILTR_FILT        FLEX_TWI_FILTR_FILT 
#define TWI_FILTR_PADFEN      FLEX_TWI_FILTR_PADFEN 
#define TWI_FILTR_PADFCFG     FLEX_TWI_FILTR_PADFCFG 
#define TWI_FILTR_THRES_Pos   FLEX_TWI_FILTR_THRES_Pos 
#define TWI_FILTR_THRES_Msk   FLEX_TWI_FILTR_THRES_Msk 
#define TWI_FILTR_THRES(value)FLEX_TWI_FILTR_THRES(value)
/* -------- FLEX_TWI_SWMR : (FLEXCOM Offset: 0x64C) TWI SleepWalking Matching Register -------- */
#define TWI_SWMR_SADR1_Pos   FLEX_TWI_SWMR_SADR1_Pos 
#define TWI_SWMR_SADR1_Msk   FLEX_TWI_SWMR_SADR1_Msk 
#define TWI_SWMR_SADR1(value)FLEX_TWI_SWMR_SADR1(value) 
#define TWI_SWMR_SADR2_Pos   FLEX_TWI_SWMR_SADR2_Pos 
#define TWI_SWMR_SADR2_Msk   FLEX_TWI_SWMR_SADR2_Msk 
#define TWI_SWMR_SADR2(value)FLEX_TWI_SWMR_SADR2(value) 
#define TWI_SWMR_SADR3_Pos   FLEX_TWI_SWMR_SADR3_Pos 
#define TWI_SWMR_SADR3_Msk   FLEX_TWI_SWMR_SADR3_Msk 
#define TWI_SWMR_SADR3(value)FLEX_TWI_SWMR_SADR3(value) 
#define TWI_SWMR_DATAM_Pos   FLEX_TWI_SWMR_DATAM_Pos 
#define TWI_SWMR_DATAM_Msk   FLEX_TWI_SWMR_DATAM_Msk 
#define TWI_SWMR_DATAM(value)FLEX_TWI_SWMR_DATAM(value) 
/* -------- FLEX_TWI_FMR : (FLEXCOM Offset: 0x650) TWI FIFO Mode Register -------- */
#define TWI_FMR_TXRDYM_Pos        FLEX_TWI_FMR_TXRDYM_Pos 
#define TWI_FMR_TXRDYM_Msk        FLEX_TWI_FMR_TXRDYM_Msk 
#define TWI_FMR_TXRDYM(value)     FLEX_TWI_FMR_TXRDYM(value) 
#define TWI_FMR_TXRDYM_ONE_DATA   FLEX_TWI_FMR_TXRDYM_ONE_DATA 
#define TWI_FMR_TXRDYM_TWO_DATA   FLEX_TWI_FMR_TXRDYM_TWO_DATA 
#define TWI_FMR_TXRDYM_FOUR_DATA  FLEX_TWI_FMR_TXRDYM_FOUR_DATA
#define TWI_FMR_RXRDYM_Pos        FLEX_TWI_FMR_RXRDYM_Pos 
#define TWI_FMR_RXRDYM_Msk        FLEX_TWI_FMR_RXRDYM_Msk 
#define TWI_FMR_RXRDYM(value)     FLEX_TWI_FMR_RXRDYM(value) 
#define TWI_FMR_RXRDYM_ONE_DATA   FLEX_TWI_FMR_RXRDYM_ONE_DATA 
#define TWI_FMR_RXRDYM_TWO_DATA   FLEX_TWI_FMR_RXRDYM_TWO_DATA 
#define TWI_FMR_RXRDYM_FOUR_DATA  FLEX_TWI_FMR_RXRDYM_FOUR_DATA
#define TWI_FMR_TXFTHRES_Pos      FLEX_TWI_FMR_TXFTHRES_Pos 
#define TWI_FMR_TXFTHRES_Msk      FLEX_TWI_FMR_TXFTHRES_Msk 
#define TWI_FMR_TXFTHRES(value)   FLEX_TWI_FMR_TXFTHRES(value) 
#define TWI_FMR_RXFTHRES_Pos      FLEX_TWI_FMR_RXFTHRES_Pos 
#define TWI_FMR_RXFTHRES_Msk      FLEX_TWI_FMR_RXFTHRES_Msk 
#define TWI_FMR_RXFTHRES(value)   FLEX_TWI_FMR_RXFTHRES(value) 
/* -------- FLEX_TWI_FLR : (FLEXCOM Offset: 0x654) TWI FIFO Level Register -------- */
#define TWI_FLR_TXFL_Pos  FLEX_TWI_FLR_TXFL_Pos
#define TWI_FLR_TXFL_Msk  FLEX_TWI_FLR_TXFL_Msk
#define TWI_FLR_RXFL_Pos  FLEX_TWI_FLR_RXFL_Pos
#define TWI_FLR_RXFL_Msk  FLEX_TWI_FLR_RXFL_Msk
/* -------- FLEX_TWI_FSR : (FLEXCOM Offset: 0x660) TWI FIFO Status Register -------- */
#define TWI_FSR_TXFEF   FLEX_TWI_FSR_TXFEF 
#define TWI_FSR_TXFFF   FLEX_TWI_FSR_TXFFF 
#define TWI_FSR_TXFTHF  FLEX_TWI_FSR_TXFTHF
#define TWI_FSR_RXFEF   FLEX_TWI_FSR_RXFEF 
#define TWI_FSR_RXFFF   FLEX_TWI_FSR_RXFFF 
#define TWI_FSR_RXFTHF  FLEX_TWI_FSR_RXFTHF
#define TWI_FSR_TXFPTEF FLEX_TWI_FSR_TXFPTEF 
#define TWI_FSR_RXFPTEF FLEX_TWI_FSR_RXFPTEF 
/* -------- FLEX_TWI_FIER : (FLEXCOM Offset: 0x664) TWI FIFO Interrupt Enable Register -------- */
#define TWI_FIER_TXFEF   FLEX_TWI_FIER_TXFEF 
#define TWI_FIER_TXFFF   FLEX_TWI_FIER_TXFFF 
#define TWI_FIER_TXFTHF  FLEX_TWI_FIER_TXFTHF
#define TWI_FIER_RXFEF   FLEX_TWI_FIER_RXFEF 
#define TWI_FIER_RXFFF   FLEX_TWI_FIER_RXFFF 
#define TWI_FIER_RXFTHF  FLEX_TWI_FIER_RXFTHF
#define TWI_FIER_TXFPTEF FLEX_TWI_FIER_TXFPTEF
#define TWI_FIER_RXFPTEF FLEX_TWI_FIER_RXFPTEF
/* -------- FLEX_TWI_FIDR : (FLEXCOM Offset: 0x668) TWI FIFO Interrupt Disable Register -------- */
#define TWI_FIDR_TXFEF   FLEX_TWI_FIDR_TXFEF
#define TWI_FIDR_TXFFF   FLEX_TWI_FIDR_TXFFF
#define TWI_FIDR_TXFTHF  FLEX_TWI_FIDR_TXFTHF
#define TWI_FIDR_RXFEF   FLEX_TWI_FIDR_RXFEF 
#define TWI_FIDR_RXFFF   FLEX_TWI_FIDR_RXFFF 
#define TWI_FIDR_RXFTHF  FLEX_TWI_FIDR_RXFTHF
#define TWI_FIDR_TXFPTEF FLEX_TWI_FIDR_TXFPTEF
#define TWI_FIDR_RXFPTEF FLEX_TWI_FIDR_RXFPTEF
/* -------- FLEX_TWI_FIMR : (FLEXCOM Offset: 0x66C) TWI FIFO Interrupt Mask Register -------- */
#define TWI_FIMR_TXFEF   FLEX_TWI_FIMR_TXFEF 
#define TWI_FIMR_TXFFF   FLEX_TWI_FIMR_TXFFF 
#define TWI_FIMR_TXFTHF  FLEX_TWI_FIMR_TXFTHF
#define TWI_FIMR_RXFEF   FLEX_TWI_FIMR_RXFEF 
#define TWI_FIMR_RXFFF   FLEX_TWI_FIMR_RXFFF 
#define TWI_FIMR_RXFTHF  FLEX_TWI_FIMR_RXFTHF
#define TWI_FIMR_TXFPTEF FLEX_TWI_FIMR_TXFPTEF
#define TWI_FIMR_RXFPTEF FLEX_TWI_FIMR_RXFPTEF
/* -------- FLEX_TWI_DR : (FLEXCOM Offset: 0x6D0) TWI Debug Register -------- */
#define TWI_DR_SWEN    FLEX_TWI_DR_SWEN 
#define TWI_DR_CLKRQ   FLEX_TWI_DR_CLKRQ
#define TWI_DR_SWMATCH FLEX_TWI_DR_SWMATCH 
#define TWI_DR_TRP     FLEX_TWI_DR_TRP 
/* -------- FLEX_TWI_WPMR : (FLEXCOM Offset: 0x6E4) TWI Write Protection Mode Register -------- */
#define TWI_WPMR_WPEN         FLEX_TWI_WPMR_WPEN 
#define TWI_WPMR_WPITEN       FLEX_TWI_WPMR_WPITEN 
#define TWI_WPMR_WPCREN       FLEX_TWI_WPMR_WPCREN 
#define TWI_WPMR_WPKEY_Pos    FLEX_TWI_WPMR_WPKEY_Pos 
#define TWI_WPMR_WPKEY_Msk    FLEX_TWI_WPMR_WPKEY_Msk 
#define TWI_WPMR_WPKEY(value) FLEX_TWI_WPMR_WPKEY(value)
#define TWI_WPMR_WPKEY_PASSWD FLEX_TWI_WPMR_WPKEY_PASSWD
/* -------- FLEX_TWI_WPSR : (FLEXCOM Offset: 0x6E8) TWI Write Protection Status Register -------- */
#define TWI_WPSR_WPVS       FLEX_TWI_WPSR_WPVS 
#define TWI_WPSR_WPVSRC_Pos FLEX_TWI_WPSR_WPVSRC_Pos
#define TWI_WPSR_WPVSRC_Msk FLEX_TWI_WPSR_WPVSRC_Msk
/* -------- FLEX_TWI_VER : (FLEXCOM Offset: 0x6FC) TWI Version Register -------- */
#define TWI_VER_VERSION_Pos FLEX_TWI_VER_VERSION_Pos 
#define TWI_VER_VERSION_Msk FLEX_TWI_VER_VERSION_Msk
#define TWI_VER_MFN_Pos     FLEX_TWI_VER_MFN_Pos 
#define TWI_VER_MFN_Msk     FLEX_TWI_VER_MFN_Msk  
  #endif


  #if defined(FLEXCOM0) && !defined(TWI0)
  #define TWI0 ((Twi*)((uint8_t*)FLEXCOM0 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI0 ID_FLEXCOM0
#endif
#if defined(FLEXCOM1) && !defined(TWI1)
  #define TWI1 ((Twi*)((uint8_t*)FLEXCOM1 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI1 ID_FLEXCOM1
#endif
#if defined(FLEXCOM2) && !defined(TWI2)
  #define TWI2 ((Twi*)((uint8_t*)FLEXCOM2 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI2 ID_FLEXCOM2
#endif
#if defined(FLEXCOM3) && !defined(TWI3)
  #define TWI3 ((Twi*)((uint8_t*)FLEXCOM3 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI3 ID_FLEXCOM3
#endif
#if defined(FLEXCOM4) && !defined(TWI4)
  #define TWI4 ((Twi*)((uint8_t*)FLEXCOM4 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI4 ID_FLEXCOM4
#endif
#if defined(FLEXCOM5) && !defined(TWI5)
  #define TWI5 ((Twi*)((uint8_t*)FLEXCOM5 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI5 ID_FLEXCOM5
#endif
#if defined(FLEXCOM6) && !defined(TWI6)
  #define TWI6 ((Twi*)((uint8_t*)FLEXCOM6 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI6 ID_FLEXCOM6
#endif  
#if defined(FLEXCOM7) && !defined(TWI7)
  #define TWI7 ((Twi*)((uint8_t*)FLEXCOM7 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI7 ID_FLEXCOM7
#endif
#if defined(FLEXCOM8) && !defined(TWI8)
  #define TWI8 ((Twi*)((uint8_t*)FLEXCOM8 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI8 ID_FLEXCOM8
#endif  
#if defined(FLEXCOM9) && !defined(TWI9)
  #define TWI9 ((Twi*)((uint8_t*)FLEXCOM9 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI9 ID_FLEXCOM9
#endif
#if defined(FLEXCOM10) && !defined(TWI10)
  #define TWI10 ((Twi*)((uint8_t*)FLEXCOM10 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI10 ID_FLEXCOM10
#endif
#if defined(FLEXCOM11) && !defined(TWI11)
  #define TWI11 ((Twi*)((uint8_t*)FLEXCOM11 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI11 ID_FLEXCOM11
#endif
#if defined(FLEXCOM12) && !defined(TWI12)
  #define TWI12 ((Twi*)((uint8_t*)FLEXCOM12 + sizeof(FlexcomShared)+sizeof(FlexcomUsart)+sizeof(FlexcomSpi)))
  #define ID_TWI12 ID_FLEXCOM12
#endif
   
                             
  #endif /*_V_FLEXCOM_WRAPPER_H*/
