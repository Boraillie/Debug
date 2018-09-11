#include "platform.h"

#include "ppp_test_lib.c"


//////////////////////////////
// main
//////////////////////////////
int main(void)
{
 
  unsigned int i, j; 

  unsigned short int buffer[512];

  unsigned short int buf_size, mb_buf_index, buf_index;

  unsigned int pmc_ratio_mode_plla0;
  unsigned int plla_settings;

  // Enable PTC peripheral clock
  AT91F_PTC_CfgPMC();

  // Upload PPP software
  rprint ("-I- Upload PPP software");
  ppp_loadcode();

  // Enable PTC interrupt
  //AT91F_AIC_EnableIt(AIC, ID_PTC);

  // Start AVR
  rprint ("-I- Start running AVR");
  ppp_init();


  // Program PTC GCLK
  ppp_write(GCLK->DIV.reg, 1);
  // Wait for GCLK DIV Busy release
  while(ppp_read(GCLK->SYNCBUSY.reg) & 0x02);

  ppp_write(GCLK->CTRL.reg, 5);
  // Wait for GCLK CTRL Busy release
  while(ppp_read(GCLK->SYNCBUSY.reg) & 0x01);

  // Enable Interrupt on EOC
  ppp_write(PTC->INTENSET.reg, PTC_INTENSET_EOC);

  // Debug read 32 bits function
  ppp_write(PTC->CTRLB.reg, 0x12345678);
  while(ppp_read(PTC->SYNCBUSY.reg) & PTC_SYNCBUSY_CTRLB);
  ppp_write(PTC->CTRLC.reg, 0xABCDEF12);
  while(ppp_read(PTC->SYNCBUSY.reg) & PTC_SYNCBUSY_CTRLC);
  rprintf ("-I- CTRLB = %x, CTRLC = %x", ppp_read(PTC->CTRLB.reg), ppp_read(PTC->CTRLC.reg));

  ppp_write(PTC->CTRLB.reg, 0x00000000);
  while(ppp_read(PTC->SYNCBUSY.reg) & PTC_SYNCBUSY_CTRLB);
  ppp_write(PTC->CTRLC.reg, 0x00000000);
  while(ppp_read(PTC->SYNCBUSY.reg) & PTC_SYNCBUSY_CTRLC);

  // Enable Y0
  ppp_write(PTC->YEN.reg, 1);

  // Enable PTC in free run mode
  ppp_write(PTC->CTRLA.reg, PTC_CTRLA_ENABLE|PTC_CTRLA_FREERUN);
  // Wait for Enable Busy release
  while(ppp_read(PTC->SYNCBUSY.reg) & PTC_SYNCBUSY_ENABLE);

  // Select Y0
  ppp_write(PTC->YSEL.reg, 1);
  // Wait for YSEL Busy release
  while(ppp_read(PTC->SYNCBUSY.reg) & PTC_SYNCBUSY_YSEL);

  // Check YEN and YSEL regs
  rprintf ("-I- YEN = %x, YSEL = %x", ppp_read(PTC->YEN.reg), ppp_read(PTC->YSEL.reg));

  // Start conversions
  ppp_write(PTC->SWTRIG.reg, PTC_SWTRIG_STCONV);

  // Use buffer
  ppp_set_buffer_size(8); // 16 bits words
  i = 0;
  buf_index = 0;
  ppp_clear_buffer();

  // Start conversions
  ppp_write(PTC->SWTRIG.reg, PTC_SWTRIG_STCONV);

  while (i < 1) {
    // Wait for BUFHALF
    ppp_get_buffer_ready();
    // Fill buffer
    j = 0;
    mb_buf_index = *mb_buf_adr;
    buf_size = *mb_buf_size;
    while (j++ < buf_size) {
      buffer[buf_index++] = mb_buf[mb_buf_index++];
    }
    i++;
    // Check no overrrun occured
    if (ppp_buf_overrun()) {
      rprint ("-E- ADC Overrun with buffer");
      outi(MSG_BASE, MSG_FAILED);
    }
    // Send clear buffer ready command
    ppp_clear_buffer_ready();
  }
  
  // Stop PTC in free run mode
  ppp_write(PTC->CTRLA.reg, 0);
  // Wait for Enable Busy release
  while(ppp_read(PTC->SYNCBUSY.reg) & PTC_SYNCBUSY_ENABLE);

  ppp_set_buffer_size(0); // Disable ADC FIFO

  // Set delay before acquisition
  ppp_write(PTC->CTRLB.reg, PTC_CTRLB_CCDS_DLY75);
  while(ppp_read(PTC->SYNCBUSY.reg) & PTC_SYNCBUSY_CTRLB);

  // Enable start conversion trigger event
  ppp_write(PTC->EVCTRL.reg, PTC_EVCTRL_STCONVEI);

  // Enable Interrupt on Window compare
  ppp_write(PTC->INTENSET.reg, PTC_INTENSET_WCOMP);

  // Disable Interrupt on EOC
  ppp_write(PTC->INTENCLR.reg, PTC_INTENCLR_EOC);

  // Set windows compare mode
  ppp_write(PTC->WINCTRL.reg, PTC_WINCTRL_WINCM_MODE4);

  // Set windows compare limits
  ppp_write(PTC->WINLT.reg, 384);
  ppp_write(PTC->WINHT.reg, 640);

  // Enable PTC and enable run in standby mode
  ppp_write(PTC->CTRLA.reg, PTC_CTRLA_ENABLE);

  // PTC event timer (TIMER2) configuration
  ppp_write(TIMER->COUNT2.reg, 32768); // Trig every second
  ppp_write(TIMER->CTRL.reg, 2);

  // Put AVR in deepsleep mode
  ppp_deepsleep();

  //enable PTC SleepWalking 
  PMC->PMC_SLPWKCR = PMC_SLPWKCR_PID(ID_PTC)|(0x1<<12)|PMC_SLPWKCR_SLPWKSR;

  // Get current clock settings
  plla_settings = PMC->CKGR_PLLAR | CKGR_PLLAR_MULA(__PLLAR_MULA);
  pmc_ratio_mode_plla0 = PMC -> PMC_MCKR & (~PMC_MCKR_CSS_Msk);

  // change first to slower clock
  PMC->PMC_MCKR = PMC_MCKR_CSS_MAIN_CLK | pmc_ratio_mode_plla0;
  // wait ready before changing ratio
  while( !(PMC->PMC_SR & PMC_SR_MCKRDY) );
  // Shut down PLLA
  PMC->CKGR_PLLAR &= ~CKGR_PLLAR_MULA_Msk;

  // Switch to RCOSC 12MHz
  PMC->CKGR_MOR = CKGR_MOR_KEY_PASSWD | (PMC->CKGR_MOR & ~CKGR_MOR_MOSCSEL);
  //disable xtal
  PMC->CKGR_MOR = CKGR_MOR_KEY_PASSWD | (PMC->CKGR_MOR & ~CKGR_MOR_MOSCXTEN);

  //Enter in Wait mode
  PMC->PMC_FSMR = PMC_FSMR_LPM;
  __sev();
  __wfe();
  __wfe();

  i = 10;
  while (i--);

  //enable xtal
  PMC->CKGR_MOR = CKGR_MOR_KEY_PASSWD | (PMC->CKGR_MOR | CKGR_MOR_MOSCXTEN);
  //Switch to XTAL as main clock
  PMC->CKGR_MOR = CKGR_MOR_KEY_PASSWD | (PMC->CKGR_MOR | CKGR_MOR_MOSCSEL);

  // restart PLLA
  PMC->CKGR_PLLAR = plla_settings;

  // wait PLLA lock
  while( !(PMC->PMC_SR & PMC_SR_LOCKA) );

  PMC->PMC_MCKR = PMC_MCKR_CSS_PLLA_CLK | pmc_ratio_mode_plla0;
  while( !(PMC->PMC_SR & PMC_SR_MCKRDY) );

  
  // Test pass
  outi(MSG_BASE, MSG_OK);


}


