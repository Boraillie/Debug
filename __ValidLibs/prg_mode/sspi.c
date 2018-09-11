/*******************************************************************************
 * @weakgroup SSPI
 * @{
 * @file
 * @brief   SSPI (Software Serial Protocol Interface) Driver source file
 * @author  JCK
 * @version $Revision: 0.9$
 * @date    $Date: 30-Jan-2015$
 ******************************************************************************/


#warning TO CLARIFY: SSPI_IRQn vs ID_SSPI!!!


// ---- PRG mode specific includes ------------------------------------------
#include "sspi.h"

// ---- Peripherals (ASF drivers) includes ----------------------------------
#include "drivers/pmc/pmc.h"
#if (DEVICE_HAS_PIOV4==1)
  #include "v_drivers/v_pioV4.h"
#else
  #include "drivers/pio/pio.h"
#endif


// ---- Validation libraries includes ---------------------------------------
#include "v_it_management.h"
#include "v_drivers/v_spi.h"



SSPIMode_t  sspi_mode;  ///< SSPI operating mode


#ifdef SSPI_WRAPPER_SPI_IDX /* if SSPI is a wrapper to a real, hardware SPI */
/**
 * This function must be called before calling the functions of the SSPI module.
 * It configures PIO muxing for HW SPI
 */
void sspi_init()
{
  //disable_interrupt(SSPI_IRQn);
  disable_interrupt(ID_SSPI);

  // initialize SPI
  REG_PMC_WPMR = (REG_PMC_WPMR & ~PMC_WPMR_WPEN)| PMC_WPMR_WPKEY_PASSWD;//unprotect PMC
  pmc_enable_periph_clk(ID_SSPI);
  REG_PMC_WPMR = PMC_WPMR_WPKEY_PASSWD | PMC_WPMR_WPEN; // Protect PMC

  //sspi_init_pio_configure();

  //#warning NOT GENERIC: DEBUG PURPOSE ONLY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //FLEXCOM9->FLEXCOM_MR = FLEXCOM_MR_OPMODE_SPI;

  #if (DEVICE_HAS_FLEXCOM && SSPI_IS_FLEXCOM)
    SERIAL_COM_LINK_PERIPH->FLEXCOM_MR =FLEXCOM_MR_OPMODE_SPI ;
  #endif

  #if (DEVICE_HAS_PIOV4==1) //PIOV4: 65108, 92U03 and next products...
    v_pioV4_iocfg_periph(BRD_PIO_BASE_MISO, BRD_PIO_MASK_MISO, HWSPI_MISO_PIO_PERIPH);//MISO
    v_pioV4_iocfg_periph(BRD_PIO_BASE_MOSI, BRD_PIO_MASK_MOSI, HWSPI_MOSI_PIO_PERIPH);//MOSI
    v_pioV4_iocfg_periph(BRD_PIO_BASE_SPCK, BRD_PIO_MASK_SPCK, HWSPI_SPCK_PIO_PERIPH);//SPCK
    v_pioV4_iocfg_periph(BRD_PIO_BASE_CSS, BRD_PIO_MASK_CSS,  HWSPI_CSS_PIO_PERIPH);//CSS
     //#warning to rewrite: pioV4 to manage
  #else //PIOV3: 63K9, 65103, 65105, 65107, 92A03, 92A04, and older products
    //pio_set_peripheral(BRD_PIO_BASE_MISO, HWSPI_MISO_PIO_PERIPH, BRD_PIO_MASK_MISO);//MISO
    //pio_set_peripheral(BRD_PIO_BASE_MOSI, HWSPI_MOSI_PIO_PERIPH, BRD_PIO_MASK_MOSI);//MOSI
    //pio_set_peripheral(BRD_PIO_BASE_SPCK, HWSPI_SPCK_PIO_PERIPH, BRD_PIO_MASK_SPCK);//SPCK
    //pio_set_peripheral(BRD_PIO_BASE_CSS,  HWSPI_CSS_PIO_PERIPH, BRD_PIO_MASK_CSS);//CSS
    pio_set_peripheral(BRD_PIO_BASE_MISO, HWSPI_MISO_PIO_PERIPH, BRD_PIO_MASK_MISO);//MISO
    pio_set_peripheral(BRD_PIO_BASE_MOSI, HWSPI_MOSI_PIO_PERIPH, BRD_PIO_MASK_MOSI);//MOSI
    pio_set_peripheral(BRD_PIO_BASE_SPCK, HWSPI_SPCK_PIO_PERIPH, BRD_PIO_MASK_SPCK);//SPCK
    pio_set_peripheral(BRD_PIO_BASE_CSS,  HWSPI_CSS_PIO_PERIPH, BRD_PIO_MASK_CSS);//CSS
  #endif
}

/**
 * This function must be called before calling the functions of the SSPI module.
 * It configures the hardware SPI as follows : Slave/SPI-mode=0/BITS=8/RDRF IT enable
 */
void sspi_reset()
{
    REG_SSPI_CR = SPI_CR_SPIDIS; // disable SPI
    REG_SSPI_CR = SPI_CR_SWRST;  // 2 resets
    REG_SSPI_CR = SPI_CR_SWRST;
    /* nothing to do in Mode Register : default is Slave, Fixed peripheral 0, no
     * Mode fault detection
     */
    REG_SSPI_WPMR = SPI_WPMR_WPKEY(SPI_KEY_VAL); // clear the WPEN bit to enable SPI_CSRx changes
    //REG_SSPI_WPMR = SPI_WPMR_WPKEY_PASSWD; // clear the WPEN bit to enable SPI_CSRx changes
    REG_SSPI_CSR  = SPI_CSR_NCPHA | SPI_CSR_BITS_8_BIT; // SPI-mode=0 (capture on SPCK rising edge, shift on SPCK falling edge), BITS=8

    SPI_EnableIt(SSPI_WRAPPER, SPI_IER_RDRF);
    //NVIC_SetPriority(SSPI_IRQn, 3); // SPI interrupts (level 3) preempt the UART ones (level 4)
    //enable_interrupt(SSPI_IRQn);
    enable_interrupt(ID_SSPI);

    REG_SSPI_CR = SPI_CR_SPIEN; // enable SPI
}


void sspi_set_mode(SSPIMode_t sm)
{
  if(sm==sspi_mode){return;}
  else{
    //disable_interrupt(SSPI_IRQn);
    disable_interrupt(ID_SSPI);

    SPI_DisableIt(SSPI_WRAPPER, SPI_IER_TDRE);
    SPI_DisableIt(SSPI_WRAPPER, SPI_IER_RDRF);
    sspi_mode = sm;
    if(sm & SSPI_MODE_RECEIVE){SPI_EnableIt(SSPI_WRAPPER, SPI_IER_RDRF);}
    if(sm & SSPI_MODE_TRANSMIT){SPI_EnableIt(SSPI_WRAPPER, SPI_IER_TDRE);}
    //NVIC_ClearPendingIRQ(SSPI_IRQn);
    
    clear_pending_interrupt(SSPI_IRQn);
    //clear_pending_interrupt(ID_SSPI);

    if (sm != SSPI_MODE_DISABLED)
      enable_interrupt(SSPI_IRQn);
      //enable_interrupt(ID_SSPI);
    }
}



#else /* if SSPI is actually a software emulation */
// global variables definition
volatile SSPI_t          SSPI;                  ///< The SSPI instance
         void           (*sspi_rdrf_handler)(); ///< registered call-back function on RDRF event
         void           (*sspi_tdre_handler)(); ///< registered call-back function on TDRE event
static volatile uint32_t sspi_shift_reg; ///< SSPI internal shift register
#ifdef SSPI_IRQ_ON_SPCK
static volatile int bit;
#endif

void sspi_init()
{
#error to write
}

/**
 * This function must be called before enabling the interrupt, which will
 * trigger a call to sspi_NSS_handler().\n
 * It sets the following :<tt>
 * - sspi_shift_reg = 0x0
 * - REG_SSPI_RDR   = 0x0
 * - REG_SSPI_TDR   = 0x0
 * - REG_SSPI_SR    = SPI_SR_TDRE
 * .</tt>
 */
void sspi_reset()
{
    sspi_shift_reg    = 0x0;
    REG_SSPI_RDR      = 0x0;
    REG_SSPI_TDR      = 0x0;
    REG_SSPI_SR       = SPI_SR_TDRE; // at reset, RDR and TDR are empty
    sspi_rdrf_handler = NULL;
    sspi_tdre_handler = NULL;
#ifdef SSPI_IRQ_ON_SPCK
    bit               = -1;
#endif
}

/**
 * Register @a func_ptr as call-back function on RDRF event
 * (emulates an Interrupt Service Routine)
 * @param[in] func_ptr pointer to a function with no argument returning void
 */
void sspi_register_rdrf_handler(void (*func_ptr)())
{
  sspi_rdrf_handler = func_ptr;
}

/**
 * Register @a func_ptr as call-back function on TDRE event
 * (emulates an Interrupt Service Routine)
 * @param[in] func_ptr pointer to a function with no argument returning void
 */
void sspi_register_tdre_handler(void (*func_ptr)())
{
  sspi_tdre_handler = func_ptr;
}


/**
 * Handle the interrupt on falling edge of PIO dedicated to the NSS signal of
 * our software emulation of SPI protocol through PIOs, which is kind of
 * a virtual SPI peripheral called SSPI (i.e. Software SPI)
 * Parameters (global variables)
 */
void sspi_nss_handler()
{
#ifdef SSPI_IRQ_ON_SPCK
  bit = 8;

  if ((BRD_BASE_PIO_NSS->PIO_PDSR & BRD_NSS_MASK) == 0)
  {
    BRD_BASE_PIO_SPCK->PIO_IER = BRD_SPCK_MASK;
#else
  int bit=8;

  if (sspi_mode == SSPI_MODE_DISABLED)
    return;
#endif
    // -1 possibly copy REG_SSPI_TDR to the sspi_shift_reg
    if (sspi_mode & SSPI_MODE_TRANSMIT)
    {
      if (sspi_is_tdr_empty())
        REG_SSPI_SR |= SPI_SR_UNDES;
      else
      {
        sspi_shift_reg = REG_SSPI_TDR;
        REG_SSPI_SR   |= SPI_SR_TDRE;
        if (sspi_tdre_handler!=NULL){
          sspi_tdre_handler();
          }
      }
    }
#ifdef SSPI_IRQ_ON_SPCK
  }
  else
  {
    BRD_BASE_PIO_SPCK->PIO_IDR = BRD_SPCK_MASK;
    bit = -1;
  }
#else
  while (--bit >= 0)
  {
    // -2 busy wait for SPCK rising edge
    while (((BRD_BASE_PIO_SPCK->PIO_PDSR) & BRD_SPCK_MASK) == 0x0)
      ;

    // 3- shift left the sspi_shift_reg
    sspi_shift_reg <<= 1;

    // 4- possibly store MOSI state as LSB of sspi_shift_reg
    if (sspi_mode & SSPI_MODE_RECEIVE)
    {
      if (((BRD_BASE_PIO_MOSI->PIO_PDSR) & BRD_MOSI_MASK) == 0)
        sspi_shift_reg &= ~0x1ul;
      else
        sspi_shift_reg |= 0x1ul;
    }

    // 5- busy wait for SPCK falling edge
    while (((BRD_BASE_PIO_SPCK->PIO_PDSR) & BRD_SPCK_MASK) != 0x0)
      ;

    // 6- possibly send bit8 of sspi_shift_reg to MISO
    if (sspi_mode & SSPI_MODE_TRANSMIT)
    {
      if ((sspi_shift_reg & 0x100) == 0)
        BRD_BASE_PIO_SPCK->PIO_CODR = BRD_MISO_MASK;
      else
        BRD_BASE_PIO_SPCK->PIO_SODR = BRD_MISO_MASK;
    }
  }

  // 7- possibly update SR_TXEMPTY flag
  if (sspi_mode & SSPI_MODE_TRANSMIT)
    REG_SSPI_SR |= SPI_SR_TXEMPTY;

  // 8- possibly copy sspi_shift_reg to REG_SSPI_RDR
  if (sspi_mode & SSPI_MODE_RECEIVE)
  {
    REG_SSPI_RDR = sspi_shift_reg & 0xFF;
    REG_SSPI_SR |= sspi_is_rdr_full() ? SPI_SR_OVRES : SPI_SR_RDRF;

    if (sspi_rdrf_handler)
      sspi_rdrf_handler();
  }
#endif
}

#ifdef SSPI_IRQ_ON_SPCK
void sspi_spck_handler()
{
  if (bit <= 0) // should not occur
    return;

  const uint32_t pdsr = BRD_BASE_PIO_SPCK->PIO_PDSR;

  if ((pdsr & BRD_SPCK_MASK) != 0) // SPCK rising edge
  {
    --bit;

    // shift left the sspi_shift_reg
    sspi_shift_reg <<= 1;

    // possibly store MOSI state as LSB of sspi_shift_reg
    if (sspi_mode & SSPI_MODE_RECEIVE)
    {
      if (((BRD_BASE_PIO_MOSI->PIO_PDSR) & BRD_MOSI_MASK) == 0)
        sspi_shift_reg &= ~0x1ul;
      else
        sspi_shift_reg |= 0x1ul;

      // possibly copy sspi_shift_reg to REG_SSPI_RDR
      if (bit == 0)
      {
        REG_SSPI_RDR = sspi_shift_reg & 0xFF;
        REG_SSPI_SR |= sspi_is_rdr_full() ? SPI_SR_OVRES : SPI_SR_RDRF;

        if (sspi_rdrf_handler)
          sspi_rdrf_handler();
      }
    }
  }
  else
    // possibly send bit8 of sspi_shift_reg to MISO
    if (sspi_mode & SSPI_MODE_TRANSMIT)
    {
      if ((sspi_shift_reg & 0x100) == 0)
        BRD_BASE_PIO_SPCK->PIO_CODR = BRD_MISO_MASK;
      else
        BRD_BASE_PIO_SPCK->PIO_SODR = BRD_MISO_MASK;

      // possibly update SR_TXEMPTY flag
      if (bit == 0)
        REG_SSPI_SR |= SPI_SR_TXEMPTY;
    }
}
#endif /*SSPI_IRQ_ON_SPCK*/

#endif /*SSPI_WRAPPER_SPI_IDX*/
/// @}
