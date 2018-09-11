#ifndef _PPP_COMMON_AVR_A5_H
#define _PPP_COMMON_AVR_A5_H


// header files
#include "header/picop.h"

// Mailbox register mapping
#define MB_CMD 0
#define MB_ADDR 2
#define MB_DATA 4
#define MB_BUF_ADR 8
#define MB_BUF_SIZE 10
#define MB_BUF 32

// Commands coding
#define CMD_WRITE8 0
#define CMD_WRITE16 1
#define CMD_WRITE32 2
#define CMD_READ8 4
#define CMD_READ16 5
#define CMD_READ32 6
#define CMD_FIRM_VERSION 8
#define CMD_SET_BUFFER_SIZE 12
#define CMD_CLR_BUF_RDY 13
#define CMD_CLEAR_BUFFER 14
#define CMD_DEEPSLEEP 16

// HF bits assignment
#define HF_CMD_TO_AVR 0
#define HF_ACK_TO_A5 0
#define HF_EOC_TO_A5 1
#define HF_BUFOVERRUN_TO_A5 2
#define HF_BUFHALF_TO_A5 3


#endif //_PPP_COMMON_AVR_A5_H