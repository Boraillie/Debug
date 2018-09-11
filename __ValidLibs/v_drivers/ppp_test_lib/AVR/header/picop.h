
#ifndef _PICOP_H
#define _PICOP_H



#include <stdint.h>

/* CMSIS TYPEDEFS */
#ifndef __IO
  #ifdef __cplusplus
    #define   __I     volatile             /**< Defines "Read-Only" permissions  */
  #else
    #define   __I     volatile const       /**< Defines "Read-Only" permissions  */
  #endif
  #define     __O     volatile             /**< Defines "Write-Only" permissions */
  #define     __IO    volatile             /**< Defines "Read-Write" permissions */
#endif


//typedef volatile const uint32_t RoReg;   /**< Read only 32-bit register (volatile const unsigned int) */
typedef volatile const uint16_t RoReg16; /**< Read only 16-bit register (volatile const unsigned int) */
typedef volatile const uint8_t  RoReg8;  /**< Read only  8-bit register (volatile const unsigned int) */
//typedef volatile       uint32_t WoReg;   /**< Write only 32-bit register (volatile unsigned int) */
typedef volatile       uint16_t WoReg16; /**< Write only 16-bit register (volatile unsigned int) */
typedef volatile       uint32_t WoReg8;  /**< Write only  8-bit register (volatile unsigned int) */
//typedef volatile       uint32_t RwReg;   /**< Read-Write 32-bit register (volatile unsigned int) */
typedef volatile       uint16_t RwReg16; /**< Read-Write 16-bit register (volatile unsigned int) */
typedef volatile       uint8_t  RwReg8;  /**< Read-Write  8-bit register (volatile unsigned int) */

/* IMPORTED MODULES HEADER FILES */
#include "ptc.h"

/* RAM ADDRESS MAP */
#define MAILBOX_ADDR                    (0xC000U)
#define RAM_ADDR                        (0x8000U)

/* PERIPHERAL ADDRESS MAP */
#define HF_IO_ADDR                      (0x001CU)
#define HF_ADDR                         (0x0220U)
#define PTC_ADDR                        (0x0300U)

#define TIMER_ADDR                      (0x0380U)
#define MAILINT_ADDR                    (0x03A0U)
#define PTCTEST_ADDR                    (0x03A4U)
#define GCLK_ADDR                       (0x03C0U)
#define PORT_ADDR                       (0x03E0U)

/* ADDRESS DEFINES */
#define HF_IO              ((Hf_io      *)(HF_IO_ADDR))
#define HF                 ((Hf         *)(HF_ADDR))
#define PTC                ((Ptc        *)(PTC_ADDR))
#define PORT               ((Port       *)(PORT_ADDR))
#define TIMER              ((Timer      *)(TIMER_ADDR))
#define GCLK               ((Gclk       *)(GCLK_ADDR))
#define MAILINT            ((Mailint    *)(MAILINT_ADDR))
#define PTCTEST            ((Ptctest    *)(PTCTEST_ADDR))


/* HF IO STRUCTS */
typedef union {
  struct {
    volatile uint8_t BYTE0 : 8;
    volatile uint8_t BYTE1 : 8;
    volatile uint8_t BYTE2 : 8;
    volatile uint8_t BYTE3 : 8;
  } bit;
  volatile uint32_t reg;
} HF_IO_DATA_Type;


typedef struct {
  __IO HF_IO_DATA_Type DATA;
} Hf_io;

/* HF STRUCTS */
typedef union {
  struct {
    volatile uint8_t BYTE0 : 8;
    volatile uint8_t BYTE1 : 8;
    volatile uint8_t BYTE2 : 8;
    volatile uint8_t BYTE3 : 8;
  } bit;
  volatile uint32_t reg;
} HF_DATA_Type;

typedef union {
  struct {
    volatile uint16_t IRQENCLR : 4;
  volatile uint16_t : 4;
    volatile uint16_t IRQENSET : 4;
  volatile uint16_t : 4;
  } bit;
  volatile uint16_t reg;
} HF_CTRL_Type;

typedef union {
  struct {
    volatile uint8_t CLR0 : 8;
    volatile uint8_t SET0 : 8;
    volatile uint8_t CLR1 : 8;
    volatile uint8_t SET1 : 8;
  } bit;
  volatile uint32_t reg;
} HF_SETCLR_Type;

typedef union {
  struct {
    volatile uint8_t CLR0 : 8;
    volatile uint8_t SET0 : 8;
    volatile uint8_t CLR1 : 8;
    volatile uint8_t SET1 : 8;
  } bit;
  volatile uint32_t reg;
} HF_SETCLR1_Type;

typedef struct {
  __IO HF_DATA_Type DATA;
  __IO HF_CTRL_Type CTRL;
  RoReg16 Reserved;
  __O HF_SETCLR_Type SETCLR0;
  __O HF_SETCLR1_Type SETCLR1;
} Hf;

/* TIMER STRUCTS */
typedef union {
  struct {
    volatile uint8_t EN1 : 1;
    volatile uint8_t EN2 : 1;
    volatile uint8_t : 6;
  } bit;
  volatile uint8_t reg;
} TIMER_CTRL_Type;

typedef union {
  struct {
    volatile uint16_t COUNT : 16;
  } bit;
  volatile uint16_t reg;
} TIMER_COUNT1_Type;

typedef union {
  struct {
    volatile uint16_t COUNT : 16;
  } bit;
  volatile uint16_t reg;
} TIMER_COUNT2_Type;

typedef union {
  struct {
    volatile uint8_t INTFLAG : 1;
  volatile uint8_t : 7;
  } bit;
  volatile uint8_t reg;
} TIMER_INTFLAG_Type;


typedef union {
  struct {
    volatile uint8_t STARTED1 : 1;
    volatile uint8_t STARTED2 : 1;
  volatile uint8_t : 6;
  } bit;
  volatile uint8_t reg;
} TIMER_SYNC_Type;


typedef struct {
  __IO TIMER_CTRL_Type CTRL;
  RoReg8 Reserved0;
  RoReg16 Reserved1;
  __IO TIMER_COUNT1_Type COUNT1;
  RoReg16 Reserved2;
  __IO TIMER_COUNT2_Type COUNT2;
  RoReg16 Reserved3;
  __IO TIMER_INTFLAG_Type INTFLAG;
  RoReg8 Reserved4;
  RoReg16 Reserved5;
  __IO TIMER_SYNC_Type SYNC;
} Timer;

typedef union {
  struct {
    volatile uint8_t INTCLR : 1;
    volatile uint8_t : 7;
  } bit;
  volatile uint8_t reg;
} MAILINT_INTCLR_Type;

typedef struct {
  __O MAILINT_INTCLR_Type INTCLR;
} Mailint;

typedef union {
  struct {
    volatile uint8_t CTRL : 8;
  } bit;
  volatile uint8_t reg;
} PTCTEST_CTRL_Type;

typedef struct {
  __IO PTCTEST_CTRL_Type CTRL;
} Ptctest;

/* PORT STRUCTS */
typedef union {
  struct {
    volatile uint8_t OE : 8;
  } bit;
  volatile uint8_t reg;
} PORT_OE_Type;

typedef union {
  struct {
    volatile uint8_t OV : 8;
  } bit;
  volatile uint8_t reg;
} PORT_OV_Type;

typedef union {
  struct {
    volatile uint8_t IN : 8;
  } bit;
  volatile uint8_t reg;
} PORT_IN_Type;


typedef struct {
  __IO PORT_OE_Type OE;
  __IO PORT_OV_Type OV;
  RoReg16 Reserved0;
  __I PORT_IN_Type IN;
} Port;


/* GCLK STRUCTS */
typedef union {
  struct {
    volatile uint8_t DIV : 8;
  } bit;
  volatile uint8_t reg;
} GCLK_DIV_Type;

typedef union {
  struct { 
    volatile uint8_t DIVEN:1;
    volatile uint8_t DIVSEL:1;
    volatile uint8_t IDC:1;
    volatile uint8_t : 5;
  } bit;
  volatile uint8_t reg;
} GCLK_CTRL_Type;


typedef union {
  struct {
    volatile uint8_t CTRLBUSY:1;
    volatile uint8_t DIVBUSY:1;
  volatile uint8_t : 6;
  } bit;
  volatile uint8_t reg;
} GCLK_SYNCBUSY_Type;

typedef struct {
  __IO GCLK_CTRL_Type CTRL;
  __IO GCLK_DIV_Type DIV;
__I GCLK_SYNCBUSY_Type SYNCBUSY;
} Gclk;



#endif //_PICOP_H