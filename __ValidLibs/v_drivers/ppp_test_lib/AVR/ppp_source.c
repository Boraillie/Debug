#define __SAML21E18A__

#include "ppp_common_avr_a5.h"

#define PPP_FIRM_VERSION 6

#define PICOP_CTRL_CTTSEN_Pos 0
#define PICOP_CTRL_IL1EN_Pos 2
#define PICOP_CTRL_IL2EN_Pos 3
#define PICOP_CTRL_IL3EN_Pos 4
#define PICOP_CTRL_IL4EN_Pos 5
#define PICOP_CTRL_I_Pos 7
#define PICOP_CTRL_SLEEPMODE_Pos 8
#define PICOP_CTRL_DEEPSLEEPMODE_Pos 9


void initcode() __attribute__((section (".initcode"), naked));
void ISR_HF(unsigned int avec) __attribute__((section (".isr1"), OS_task));
void ISR_PTC(unsigned int avec) __attribute__((section (".isr2"), OS_task));
void ISR_TIMER(unsigned int avec) __attribute__((section (".isr3"), OS_task));
void ISR_MAILBOX(unsigned int avec) __attribute__((section (".isr4"), OS_task));

volatile uint8_t *cmd;
volatile uint16_t *addr;
volatile uint32_t *data;

volatile uint16_t *buf_addr;
volatile uint16_t *buf_size;

volatile uint16_t *adc_buf_read_p;
volatile uint16_t *adc_buf_write_p;

volatile uint16_t adc_buffer_size;

volatile uint8_t deepsleep_req;


int picop(){

  cmd = (uint8_t *) (MAILBOX_ADDR + MB_CMD);
  addr = (uint16_t *) (MAILBOX_ADDR + MB_ADDR);
  data = (uint32_t *) (MAILBOX_ADDR + MB_DATA);
  buf_addr = (uint16_t *) (MAILBOX_ADDR + MB_BUF_ADR);
  buf_size = (uint16_t *) (MAILBOX_ADDR + MB_BUF_SIZE);
  adc_buf_read_p = (uint16_t *) (MAILBOX_ADDR + MB_BUF);
  adc_buf_write_p = adc_buf_read_p;

  //Enable HF + PTC interrupt
  AVR16_WriteCTRL16(
    (1 << PICOP_CTRL_CTTSEN_Pos) |
    (1 << PICOP_CTRL_IL2EN_Pos) |
    (1 << PICOP_CTRL_IL1EN_Pos) |
    (1 << PICOP_CTRL_I_Pos)
  );

  // Enable HF interrupt from A5
  HF->CTRL.bit.IRQENSET = 1 << HF_CMD_TO_AVR;

  // Default buffer size = 0 => no buffering
  adc_buffer_size = 0;

  // Transmit Buffer reset
  *buf_size = 0;

  deepsleep_req = 0;
  while(1) {
    if (deepsleep_req) {
      // Clear MAILBOX interrupt
      MAILINT->INTCLR.reg = 1;
      // Clear Deep Sleep Request
      deepsleep_req = 0;
      // Enter Deep Sleep Mode
      AVR16_WriteCTRL16(
        (1 << PICOP_CTRL_CTTSEN_Pos) |
        (1 << PICOP_CTRL_IL2EN_Pos) |
        (1 << PICOP_CTRL_IL1EN_Pos) |
        (1 << PICOP_CTRL_I_Pos) |
        (1 << PICOP_CTRL_DEEPSLEEPMODE_Pos)
      );
    }
  }

}


void ISR_HF (unsigned int avec) {
  // Clear interrupt
  HF->SETCLR1.bit.CLR1 = 1 << HF_CMD_TO_AVR;

  switch(*cmd) {
    case CMD_WRITE8 :
      AVR16_WriteMemory8( *addr, (uint8_t)*data );
      break;
    case CMD_WRITE16 :
      AVR16_WriteMemory16( *addr, (uint16_t)*data );
      break;
    case CMD_WRITE32 :
      AVR16_WriteMemory32( *addr, (uint32_t)*data );
      break;
    case CMD_READ8 :
      *data = (uint32_t)AVR16_ReadMemory8(*addr);
      break;
    case CMD_READ16 :
      *data = (uint32_t)AVR16_ReadMemory16(*addr);
      break;
    case CMD_READ32 :
      //*data = (uint32_t)AVR16_ReadMemory32(*addr);
      // AVR16_ReadMemory32 seems to have a bug
      *data = (uint32_t)AVR16_ReadMemory16(*addr) | ((uint32_t)AVR16_ReadMemory16(*addr + 2)<<16);
      break;
    case CMD_FIRM_VERSION :
      *data = (uint32_t)PPP_FIRM_VERSION;
      break;
    case CMD_SET_BUFFER_SIZE :
      adc_buffer_size = (uint16_t)(*data<<1);
      // Max buffer size = (4KB - (buffer base addr)) / 4
      if (adc_buffer_size > ((4096 - MB_BUF)>>2)) adc_buffer_size = ((4096 - MB_BUF)>>2);
      break;
    case CMD_CLR_BUF_RDY :
      adc_buf_read_p = (uint16_t *)(((*buf_size + *buf_addr)<<1) + MAILBOX_ADDR + MB_BUF);
      if ((uint16_t)adc_buf_read_p >= MAILBOX_ADDR + MB_BUF + (adc_buffer_size<<1)) {
        adc_buf_read_p = (uint16_t *) (MAILBOX_ADDR + MB_BUF);        
      }
      *buf_size = 0;
      break;
    case CMD_CLEAR_BUFFER :
      adc_buf_read_p = (uint16_t *) (MAILBOX_ADDR + MB_BUF);
      adc_buf_write_p = adc_buf_read_p;
      *buf_size = 0;
      break;
    case CMD_DEEPSLEEP :
      deepsleep_req = 1;
      break;
  }

  // Send Acknowledge on Interrupt to A5
  HF->SETCLR1.bit.SET1 = 0x10 << HF_ACK_TO_A5;

  asm volatile("reti");
}


void ISR_PTC (unsigned int avec) {

  uint16_t buffer_ready_bytes;

  if (adc_buffer_size == 0) {
    // Send HF Interrupt to A5
    HF->SETCLR1.bit.SET1 = (PTC->INTFLAG.bit.EOC || PTC->INTFLAG.bit.WCOMP)  << (4+HF_EOC_TO_A5);  
  } else {
    if (PTC->INTFLAG.bit.EOC) {
      *adc_buf_write_p++ = AVR16_ReadMemory16((uint16_t *)&(PTC->RES.reg));
      if ((uint16_t)adc_buf_write_p >= MAILBOX_ADDR + MB_BUF + (adc_buffer_size<<1)) {
        adc_buf_write_p = (uint16_t *) (MAILBOX_ADDR + MB_BUF);        
      }
      // Check buffer overrun
      if (adc_buf_write_p == adc_buf_read_p) {
        HF->SETCLR1.bit.SET1 = 1 << (4+HF_BUFOVERRUN_TO_A5);
      }
      if (!*buf_size) {
        // Check buffer half full
        if (adc_buf_write_p < adc_buf_read_p) {
          buffer_ready_bytes = (adc_buffer_size<<1) + (uint16_t)adc_buf_write_p - (uint16_t)adc_buf_read_p;
        } else {
          buffer_ready_bytes = (uint16_t)adc_buf_write_p - (uint16_t)adc_buf_read_p;
        }
        if (buffer_ready_bytes >= adc_buffer_size) {
          *buf_size = buffer_ready_bytes>>1;        
          *buf_addr = ((uint16_t)adc_buf_read_p - (MAILBOX_ADDR + MB_BUF))>>1;        
          HF->SETCLR1.bit.SET1 = 1 << (4+HF_BUFHALF_TO_A5);
        }
      }
    }
  }
  // Clear PTC interrupt flags
  PTC->INTFLAG.reg = PTC_INTFLAG_EOC | PTC_INTFLAG_WCOMP;
  asm volatile("reti");
}

void ISR_TIMER (unsigned int avec) {
  TIMER->INTFLAG.bit.INTFLAG = 0x1;
  asm volatile("reti");
}
void ISR_MAILBOX (unsigned int avec) {
  MAILINT->INTCLR.reg=0x1;
  asm volatile("reti");
}

//Low-level initialization code. Will be linked before "main" section and do no stack operations.
//Sets up stack pointer
void initcode(){
  asm volatile("ldi r16, 0xFF");
  asm volatile("ldi r17, 0xBF");
  asm volatile("out 0x3D, r16");
  asm volatile("out 0x3E, r17");
}


