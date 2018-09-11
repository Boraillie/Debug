
#ifndef _PPP_TEST_LIB_H
#define _PPP_TEST_LIB_H


#include "PPP.h"
#include "AVR/ppp_common_avr_a5.h"

#define PPP_CODEMEM_SIZE 16384
#define PPP_MAILBOX_SIZE 4096
#define PPP_MAILBOX_ADDRESS (PTCMEM_ADDR+PPP_CODEMEM_SIZE)


// Global variables: ppp_code.c
extern unsigned char ppp_code[];
extern unsigned int ppp_code_len;

// Global variables: ppp_test_lib.c
extern volatile unsigned char *mb_cmd;
extern volatile unsigned short int *mb_addr;
extern volatile unsigned int *mb_data;
extern volatile unsigned short int *mb_buf;
extern volatile unsigned short int *mb_buf_adr;
extern volatile unsigned short int *mb_buf_size;


#define ppp_write(addr, data) ppp_write_func((unsigned /*short*/ int)&addr, data, sizeof(addr))
#define ppp_read(addr) ppp_read_func((unsigned /*short*/ int)&addr, sizeof(addr))

#ifndef _FORCE_INLINE_DIRECTIVE_
  #ifdef __ICCARM__
    #define _FORCE_INLINE_DIRECTIVE_ _Pragma("inline=forced")
  #else
    #define _FORCE_INLINE_DIRECTIVE_
  #endif
#endif


/**********************************/
/* ppp_loadcode                   */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_loadcode ()
{
  unsigned short int *ppp_memcode, *code_src;
  unsigned short int i;

  ppp_memcode = (unsigned short int *) PTCMEM_ADDR;
  code_src = (unsigned short int *) ppp_code;
  i = 0;

  while (i < (ppp_code_len>>1)) {
    *ppp_memcode++ = *code_src++;
    i++;
  }
}


/**********************************/
/* ppp_init                       */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_init ()
{
  // Init Mailbox pointers
  mb_cmd = (unsigned char *) (PPP_MAILBOX_ADDRESS + MB_CMD);
  mb_addr = (unsigned short int *) (PPP_MAILBOX_ADDRESS + MB_ADDR);
  mb_data = (unsigned int *) (PPP_MAILBOX_ADDRESS + MB_DATA);
  mb_buf = (unsigned short int *) (PPP_MAILBOX_ADDRESS + MB_BUF);
  mb_buf_adr = (unsigned short int *) (PPP_MAILBOX_ADDRESS + MB_BUF_ADR);
  mb_buf_size = (unsigned short int *) (PPP_MAILBOX_ADDRESS + MB_BUF_SIZE);

  // Start AVR
  PPP->PPP_CMD = 0x5;

  // Enable all 4 HF interrupts from AVR to A5
  PPP->PPP_HFCTRL = 0xF << 12;  
}


/**********************************/
/* ppp_send_cmd                   */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_send_cmd (void)
{
  // Send a HF to AVR
  PPP->PPP_HFCS23 = 0x1 << (24 + HF_CMD_TO_AVR);
  // Wait for acknowledge
  while (!((PPP->PPP_HF >> (28 + HF_ACK_TO_A5)) & 0x1));
  // Clear acknowledge
  PPP->PPP_HFCS23 = 0x1 << (20 + HF_ACK_TO_A5);
}


/**********************************/
/* ppp_write_func                 */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_write_func (unsigned /*short*/ int addr, unsigned int data, unsigned char size)
{

  switch(size) {
    case(1) : *mb_cmd = (unsigned char) CMD_WRITE8; break;
    case(2) : *mb_cmd = (unsigned char) CMD_WRITE16; break;
    case(4) : *mb_cmd = (unsigned char) CMD_WRITE32; break;
  }

  *mb_addr = addr;
  *mb_data = data;

  ppp_send_cmd();
}


/**********************************/
/* ppp_read_func                  */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline unsigned int ppp_read_func (unsigned /*short*/ int addr, unsigned char size)
{

  switch(size) {
    case(1) : *mb_cmd = (unsigned char) CMD_READ8; break;
    case(2) : *mb_cmd = (unsigned char) CMD_READ16; break;
    case(4) : *mb_cmd = (unsigned char) CMD_READ32; break;
  }

  *mb_addr = addr;

  ppp_send_cmd();

  return(*mb_data);
}


/**********************************/
/* ppp_get_eoc                    */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_get_eoc (void)
{
  // Wait for EOC interrupt
  while (!((PPP->PPP_HF >> (28 + HF_EOC_TO_A5)) & 0x1));
  // Clear EOC interrupt
  PPP->PPP_HFCS23 = 0x1 << (20 + HF_EOC_TO_A5);
}


/**********************************/
/* ppp_get_firm_version           */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline unsigned int ppp_get_firm_version (void)
{
  *mb_cmd = (unsigned char) CMD_FIRM_VERSION;
  ppp_send_cmd();
  return(*mb_data);
}


/**********************************/
/* ppp_set_buffer_size            */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_set_buffer_size (unsigned short int size)
{
  *mb_cmd = (unsigned char) CMD_SET_BUFFER_SIZE;
  *mb_data = (unsigned int) size;
  ppp_send_cmd();
}

/**********************************/
/* ppp_clear_buffer_ready         */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_clear_buffer_ready (void)
{
  *mb_cmd = (unsigned char) CMD_CLR_BUF_RDY;
  ppp_send_cmd();
}

/**********************************/
/* ppp_get_buffer_ready           */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_get_buffer_ready (void)
{
  // Wait for BUFHALF interrupt
  while (!((PPP->PPP_HF >> (28 + HF_BUFHALF_TO_A5)) & 0x1));
  // Clear BUFHALF interrupt
  PPP->PPP_HFCS23 = 0x1 << (20 + HF_BUFHALF_TO_A5);
}

/**********************************/
/* ppp_buf_overrun                */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline unsigned int ppp_buf_overrun (void)
{
  return ((PPP->PPP_HF >> (28 + HF_BUFOVERRUN_TO_A5)) & 0x1);
}

/**********************************/
/* ppp_clear_overrun              */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_clear_overrun (void)
{
  PPP->PPP_HFCS23 = 0x1 << (20 + HF_BUFOVERRUN_TO_A5);
}


/**********************************/
/* ppp_clear_buffer               */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_clear_buffer (void)
{
  *mb_cmd = (unsigned char) CMD_CLEAR_BUFFER;
  ppp_send_cmd();
}

/**********************************/
/* ppp_deepsleep                  */
/**********************************/
_FORCE_INLINE_DIRECTIVE_
__inline void ppp_deepsleep (void)
{
  *mb_cmd = (unsigned char) CMD_DEEPSLEEP;
  ppp_send_cmd();

  // Send a HF to AVR
  //PPP->PPP_HFCS23 = 0x1 << (24 + HF_CMD_TO_AVR);
  // Don't wait for acknowledge
}


#endif //_PPP_TEST_LIB_H
