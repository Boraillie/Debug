/*******************************************************************************
 * @defgroup SSPI Software Serial Protocol Interface
 * @{
 * @file
 * @brief   SSPI (Software Serial Protocol Interface) Driver header file
 * @author  JCK
 * @version $Revision: 0.9$
 * @date    $Date: 30-Jan-2015$
 * @par     Conditional compilation
 *  Before including this file sspi.h, or compiling sspi.c, one can define the
 *  \c SSPI_WRAPPER_SPI_IDX symbolic name in order to configure the SSPI as a
 *  software wrapper of a real SPI block, which will be configured as
 *  Slave/SPI-mode=0/BITS=8. Depending on the product, \c SSPI_WRAPPER_SPI_IDX
 *  can be defined as \a \<void\> or \c 0 or \c 1...
 * @par SSPI operations
 *  - If \c SSPI_WRAPPER_SPI_IDX was defined, the SSPI behaves like a true SPI.
 *  - If \c SSPI_WRAPPER_SPI_IDX was not defined, the SSPI operating conditions
 *    can be fine tuned with respect to a true SPI, in order to achieve
 *    acceptable performance
 *    - call sspi_disable() when you are not expecting SSPI communication.
 *    - call sspi_set_mode(SSPI_MODE_RECEIVE) when you are expecting to receive
 *      a byte (it saves the CPU cycles required for data transmission).
 *    - call sspi_set_mode(SSPI_MODE_TRANSMIT) when you are expecting to
 *      transmit a byte (it saves the CPU cycles required for data reception).
 *    .
 * @par Example
 *  @code
 *  uint8_t rx_byte, tx_byte;
 *
 *  sspi_reset();
 *  sspi_enable();
 *
 *  // busy wait for RDRF flag and read a byte from SSPI_RDR
    sspi_set_mode(SSPI_MODE_RECEIVE);
 *  while (!sspi_is_rdr_full())
 *      ;
 *  read_byte = sspi_read_rdr();
 *
 *  // busy wait for TDRE flag and write a byte in SSPI_TDR
    sspi_set_mode(SSPI_MODE_TRANSMIT);
 *  while (!sspi_is_tdr_empty())
 *      ;
 *  sspi_write_tdr(tx_byte);
 *
 *  sspi_disable();
 *  @endcode
 ******************************************************************************/

#ifndef SSPI_H_
#define SSPI_H_


// ---- PRG mode specific includes ------------------------------------------
#include "prg_settings.h"



// Common definitions (HW or emulated SPI) ////////////////////////////////////
/// SSPI modes enum
typedef enum SSPIModesEnum
  {
    SSPI_MODE_DISABLED = 0x0,                                 ///< SSPI disabled : sspi_nss_handler() returns immediately
    SSPI_MODE_RECEIVE  = 0x1,                                 ///< SSPI receive  channel enabled
    SSPI_MODE_TRANSMIT = 0x2,                                 ///< SSPI transmit channel enabled
    SSPI_MODE_BIDIR    = SSPI_MODE_RECEIVE|SSPI_MODE_TRANSMIT ///< SSPI full duplex
  } SSPIMode_t;
///////////////////////////////////////////////////////////////////////////////


// Common global variables (HW or emulated SPI) ///////////////////////////////
extern SSPIMode_t sspi_mode;


// Common functions (HW or emulated SPI) //////////////////////////////////////
extern void sspi_init();
extern void sspi_reset();
#pragma inline=forced
__INLINE SSPIMode_t sspi_get_mode(void) { return (sspi_mode); }



//extern void sspi_init_pio_configure(); ///< @brief SSPI PIO configuration (muxing, IT...)


#ifdef SSPI_WRAPPER_SPI_IDX /* if SSPI is a wrapper to a real, hardware SPI */
//ERr: following definition moved to serial_com_link.h
//#define SSPI_WRAPPER  MERGE(SPI,SSPI_WRAPPER_SPI_IDX,,)

  #define SSPI_WRAPPER  MERGE(SP,I,SSPI_WRAPPER_SPI_IDX,)
  #define USED_SPI_IS_FLEXCOM  MERGE(SP,I,SSPI_WRAPPER_SPI_IDX,_IS_FLEXCOM)
  //#define USED_SPI_IS_FLEXCOM  MERGE(SSPI_WRAPPER,_IS_FLEXCOM,,)
  #if (USED_SPI_IS_FLEXCOM == 1)
    //#define SERIAL_COM_LINK_PERIPH  MERGE(FLEXCOM,SSPI_WRAPPER_SPI_IDX,_SPI,)
    #define SERIAL_COM_LINK_PERIPH  MERGE(FLEXCOM,SSPI_WRAPPER_SPI_IDX,,)
    #define _REG_SSPI  MERGE(REG,_FLEXCOM,,)
    #define _FLEXCOM_MODE  MERGE(_S,P,I,)
    #define SSPI_IRQn MERGE(FLEX,COM,SSPI_WRAPPER_SPI_IDX,_IRQn) // tricky : (...)
    #define COM_LINK_HANDLER MERGE(FLEX,COM,SSPI_WRAPPER_SPI_IDX,HANDLER_SUFFIX) // tricky : (...)
    #define ID_SSPI   MERGE(ID_FLEXCOM,SSPI_WRAPPER_SPI_IDX,,)
  #else
    #define SERIAL_COM_LINK_PERIPH  MERGE(SP,I,SSPI_WRAPPER_SPI_IDX,)
    #define _REG_SSPI  MERGE(REG,_SPI,,)
    #define _FLEXCOM_MODE
    #define SSPI_IRQn MERGE(SP,I,SSPI_WRAPPER_SPI_IDX,_IRQn) // tricky : MERGE(SPI,SSPI_WRAPPER_SPI_IDX,_IRQn,) not suitable since SPI appears during macro expansion and is itself expanded to something like (*(unsigned int)SPI_base_address)
    #define COM_LINK_HANDLER MERGE(SP,I,SSPI_WRAPPER_SPI_IDX,HANDLER_SUFFIX) // tricky : (...)
    #define ID_SSPI   MERGE(ID_SPI,SSPI_WRAPPER_SPI_IDX,,)
  #endif

#define REG_SSPI_CR   MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_CR) ///< @brief SSPI Configuration Register
#warning TO CHECK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //#define REG_SSPI_CR   MERGE(REG_SSPI,SSPI_WRAPPER_SPI_IDX,_CR,) ///< @brief SSPI Configuration Register
  #define REG_SSPI_MR   MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_MR  ) ///< @brief SSPI Mode Register
  #define REG_SSPI_RDR  MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_RDR ) ///< @brief SSPI Receive Data Register
  #define REG_SSPI_TDR  MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_TDR ) ///< @brief SSPI Transmit Data Register
  #define REG_SSPI_SR   MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_SR  ) ///< @brief SSPI Status Register
  #define REG_SSPI_IER  MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_IER ) ///< @brief SSPI Interrupt Enable Register
  #define REG_SSPI_IDR  MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_IDR ) ///< @brief SSPI Interrupt Disable Register
  #define REG_SSPI_IMR  MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_IMR ) ///< @brief SSPI Interrupt Mask Register
  #define REG_SSPI_CSR  MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_CSR ) ///< @brief SSPI Chip Select Register bank (base of 4 registers)
  #define REG_SSPI_WPMR MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_WPMR) ///< @brief SSPI Write Protection Control Register
  #define REG_SSPI_WPSR MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_WPSR) ///< @brief SSPI Write Protection Status Register
  #define REG_SSPI_RPR  MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_RPR ) ///< @brief SSPI Receive Pointer Register
  #define REG_SSPI_RCR  MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_RCR ) ///< @brief SSPI Receive Counter Register
  #define REG_SSPI_TPR  MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_TPR ) ///< @brief SSPI Transmit Pointer Register
  #define REG_SSPI_TCR  MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_TCR ) ///< @brief SSPI Transmit Counter Register
  #define REG_SSPI_RNPR MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_RNPR) ///< @brief SSPI Receive Next Pointer Register
  #define REG_SSPI_RNCR MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_RNCR) ///< @brief SSPI Receive Next Counter Register
  #define REG_SSPI_TNPR MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_TNPR) ///< @brief SSPI Transmit Next Pointer Register
  #define REG_SSPI_TNCR MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_TNCR) ///< @brief SSPI Transmit Next Counter Register
  #define REG_SSPI_PTCR MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_PTCR) ///< @brief SSPI Transfer Control Register
  #define REG_SSPI_PTSR MERGE(_REG_SSPI,SSPI_WRAPPER_SPI_IDX,_FLEXCOM_MODE,_PTSR) ///< @brief SSPI Transfer Status Register
/*
    #define REG_SSPI_CR   MERGE(REG_,SERIAL_COM_LINK_PERIPH,_CR  ,) ///< @brief SSPI Configuration Register
    #define REG_SSPI_MR   MERGE(REG_,SERIAL_COM_LINK_PERIPH,_MR  ,) ///< @brief SSPI Mode Register
    #define REG_SSPI_RDR  MERGE(REG_,SERIAL_COM_LINK_PERIPH,_RDR ,) ///< @brief SSPI Receive Data Register
    #define REG_SSPI_TDR  MERGE(REG_,SERIAL_COM_LINK_PERIPH,_TDR ,) ///< @brief SSPI Transmit Data Register
    #define REG_SSPI_SR   MERGE(REG_,SERIAL_COM_LINK_PERIPH,_SR  ,) ///< @brief SSPI Status Register
    #define REG_SSPI_IER  MERGE(REG_,SERIAL_COM_LINK_PERIPH,_IER ,) ///< @brief SSPI Interrupt Enable Register
    #define REG_SSPI_IDR  MERGE(REG_,SERIAL_COM_LINK_PERIPH,_IDR ,) ///< @brief SSPI Interrupt Disable Register
    #define REG_SSPI_IMR  MERGE(REG_,SERIAL_COM_LINK_PERIPH,_IMR ,) ///< @brief SSPI Interrupt Mask Register
    #define REG_SSPI_CSR  MERGE(REG_,SERIAL_COM_LINK_PERIPH,_CSR ,) ///< @brief SSPI Chip Select Register bank (base of 4 registers)
    #define REG_SSPI_WPMR MERGE(REG_,SERIAL_COM_LINK_PERIPH,_WPMR,) ///< @brief SSPI Write Protection Control Register
    #define REG_SSPI_WPSR MERGE(REG_,SERIAL_COM_LINK_PERIPH,_WPSR,) ///< @brief SSPI Write Protection Status Register
    #define REG_SSPI_RPR  MERGE(REG_,SERIAL_COM_LINK_PERIPH,_RPR ,) ///< @brief SSPI Receive Pointer Register
    #define REG_SSPI_RCR  MERGE(REG_,SERIAL_COM_LINK_PERIPH,_RCR ,) ///< @brief SSPI Receive Counter Register
    #define REG_SSPI_TPR  MERGE(REG_,SERIAL_COM_LINK_PERIPH,_TPR ,) ///< @brief SSPI Transmit Pointer Register
    #define REG_SSPI_TCR  MERGE(REG_,SERIAL_COM_LINK_PERIPH,_TCR ,) ///< @brief SSPI Transmit Counter Register
    #define REG_SSPI_RNPR MERGE(REG_,SERIAL_COM_LINK_PERIPH,_RNPR,) ///< @brief SSPI Receive Next Pointer Register
    #define REG_SSPI_RNCR MERGE(REG_,SERIAL_COM_LINK_PERIPH,_RNCR,) ///< @brief SSPI Receive Next Counter Register
    #define REG_SSPI_TNPR MERGE(REG_,SERIAL_COM_LINK_PERIPH,_TNPR,) ///< @brief SSPI Transmit Next Pointer Register
    #define REG_SSPI_TNCR MERGE(REG_,SERIAL_COM_LINK_PERIPH,_TNCR,) ///< @brief SSPI Transmit Next Counter Register
    #define REG_SSPI_PTCR MERGE(REG_,SERIAL_COM_LINK_PERIPH,_PTCR,) ///< @brief SSPI Transfer Control Register
    #define REG_SSPI_PTSR MERGE(REG_,SERIAL_COM_LINK_PERIPH,_PTSR,) ///< @brief SSPI Transfer Status Register
*/
//ERr: following definitions moved to serial_com_link.h
//#define SSPI_IRQn MERGE(SP,I,SSPI_WRAPPER_SPI_IDX,_IRQn) // tricky : MERGE(SPI,SSPI_WRAPPER_SPI_IDX,_IRQn,) not suitable since SPI appears during macro expansion and is itself expanded to something like (*(unsigned int)SPI_base_address)
//#define ID_SSPI   MERGE(ID_SPI,SSPI_WRAPPER_SPI_IDX,,)
/*
    #define SSPI_WRAPPER  MERGE(SPI,SSPI_WRAPPER_SPI_IDX,,)
    #define REG_SSPI_CR   MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_CR  ,) ///< @brief SSPI Configuration Register
    #define REG_SSPI_MR   MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_MR  ,) ///< @brief SSPI Mode Register
    #define REG_SSPI_RDR  MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_RDR ,) ///< @brief SSPI Receive Data Register
    #define REG_SSPI_TDR  MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_TDR ,) ///< @brief SSPI Transmit Data Register
    #define REG_SSPI_SR   MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_SR  ,) ///< @brief SSPI Status Register
    #define REG_SSPI_IER  MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_IER ,) ///< @brief SSPI Interrupt Enable Register
    #define REG_SSPI_IDR  MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_IDR ,) ///< @brief SSPI Interrupt Disable Register
    #define REG_SSPI_IMR  MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_IMR ,) ///< @brief SSPI Interrupt Mask Register
    #define REG_SSPI_CSR  MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_CSR ,) ///< @brief SSPI Chip Select Register bank (base of 4 registers)
    #define REG_SSPI_WPMR MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_WPMR,) ///< @brief SSPI Write Protection Control Register
    #define REG_SSPI_WPSR MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_WPSR,) ///< @brief SSPI Write Protection Status Register
    #define REG_SSPI_RPR  MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_RPR ,) ///< @brief SSPI Receive Pointer Register
    #define REG_SSPI_RCR  MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_RCR ,) ///< @brief SSPI Receive Counter Register
    #define REG_SSPI_TPR  MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_TPR ,) ///< @brief SSPI Transmit Pointer Register
    #define REG_SSPI_TCR  MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_TCR ,) ///< @brief SSPI Transmit Counter Register
    #define REG_SSPI_RNPR MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_RNPR,) ///< @brief SSPI Receive Next Pointer Register
    #define REG_SSPI_RNCR MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_RNCR,) ///< @brief SSPI Receive Next Counter Register
    #define REG_SSPI_TNPR MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_TNPR,) ///< @brief SSPI Transmit Next Pointer Register
    #define REG_SSPI_TNCR MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_TNCR,) ///< @brief SSPI Transmit Next Counter Register
    #define REG_SSPI_PTCR MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_PTCR,) ///< @brief SSPI Transfer Control Register
    #define REG_SSPI_PTSR MERGE(REG_SPI,SSPI_WRAPPER_SPI_IDX,_PTSR,) ///< @brief SSPI Transfer Status Register
    #define SSPI_IRQn MERGE(SP,I,SSPI_WRAPPER_SPI_IDX,_IRQn) // tricky : MERGE(SPI,SSPI_WRAPPER_SPI_IDX,_IRQn,) not suitable since SPI appears during macro expansion and is itself expanded to something like (*(unsigned int)SPI_base_address)
    #define ID_SSPI   MERGE(ID_SPI,SSPI_WRAPPER_SPI_IDX,,)
*/
  #ifndef HWSPI_MISO_PIO_PERIPH // => same periph for 4 wires
    #define HWSPI_MISO_PIO_PERIPH  MERGE(BRD_PERIPH_SPI,SSPI_WRAPPER_SPI_IDX,,) //MISO
    #define HWSPI_MOSI_PIO_PERIPH  MERGE(BRD_PERIPH_SPI,SSPI_WRAPPER_SPI_IDX,,) //MOSI
    #define HWSPI_SPCK_PIO_PERIPH  MERGE(BRD_PERIPH_SPI,SSPI_WRAPPER_SPI_IDX,,) //SPCK
    #define HWSPI_CSS_PIO_PERIPH   MERGE(BRD_PERIPH_SPI,SSPI_WRAPPER_SPI_IDX,,) //CSS
  #endif

    void sspi_set_mode(SSPIMode_t sm);
#pragma inline=forced
    __INLINE void sspi_enable () { REG_SSPI_CR = SPI_CR_SPIEN ; }
#pragma inline=forced
    __INLINE void sspi_disable() { REG_SSPI_CR = SPI_CR_SPIDIS; }
    //extern   void sspi_reset  ();
#pragma inline=forced
    __INLINE void sspi_register_rdrf_handler( void (*func_ptr)()) { }
#pragma inline=forced
    __INLINE void sspi_register_tdre_handler( void (*func_ptr)()) { }

#else /* if SSPI is not the hardware SPI */
// ----------------------------------------------------------------------------
    /// SSPI class
    typedef struct
    {
        uint32_t SPI_RDR; ///< SSPI Receive  Data Register. @warning please do not read it directly, use sspi_get_rdr() instead
        uint32_t SPI_TDR; ///< SSPI Transmit Data Register. @warning please do not set  it directly, use sspi_set_tdr() instead
        uint32_t SPI_SR;  ///< SSPI Status        Register. @warning please do not read it directly, use sspi_get_sr() instead
    } SSPI_t;

    // global variables declaration (should be SSPI class member attributes, but global here for performance purpose)
    extern volatile SSPI_t     SSPI;
    //extern          SSPIMode_t sspi_mode;

    extern void sspi_register_rdrf_handler( void (*func_ptr)());
    extern void sspi_register_tdre_handler( void (*func_ptr)());
    extern void sspi_nss_handler ();
 #ifdef SSPI_IRQ_ON_SPCK
    extern void sspi_spck_handler();
 #endif

    /*
     * Sets #sspi_mode to \a sm.
     * @param[in] sm the SSPI mode. Allowed values are<tt>
     *               - SSPI_MODE_DISABLED
     *               - SSPI_MODE_RECEIVE
     *               - SSPI_MODE_TRANSMIT
     *               - SSPI_MODE_BIDIR
     *               .</tt>
     */
#pragma inline=forced
    __INLINE void sspi_set_mode(SSPIMode_t sm) { sspi_mode = sm; }
#pragma inline=forced
    __INLINE void sspi_enable () { sspi_set_mode(SSPI_MODE_BIDIR   ); } ///< sspi_set_mode(SSPI_MODE_BIDIR)
#pragma inline=forced
    __INLINE void sspi_disable() { sspi_set_mode(SSPI_MODE_DISABLED); } ///< sspi_set_mode(SSPI_MODE_DISABLED)

    #define REG_SSPI_RDR (SSPI.SPI_RDR)
    #define REG_SSPI_TDR (SSPI.SPI_TDR)
    #define REG_SSPI_SR  (SSPI.SPI_SR )
#endif
// ----------------------------------------------------------------------------




// ----------------------------------------------------------------------------
// -- SSPI generic basic routines ---------------------------------------------
// ----------------------------------------------------------------------------    
/**
 * @brief  Clears \c REG_SSPI_SR_RDRF flag and returns \c REG_SSPI_RDR
 * @return \c REG_SSPI_RDR (the byte received on MOSI)
 * @note   Consider busy waiting for sspi_is_rdr_full() before calling this function.
 *         The returned byte is indeed unreliable until REG_SSPI_SR_RDRF is asserted.
 */
#pragma inline=forced
__INLINE uint8_t sspi_read_rdr()
{
#ifndef SSPI_WRAPPER_SPI_IDX
    REG_SSPI_SR &= ~SPI_SR_RDRF; // read RDR => no more full => ready to reveive a new byte
#endif
    return REG_SSPI_RDR;
}

/**
 * @brief    Writes \a data to \c REG_SSPI_TDR and clears \c SSPI_SR_TDRE +
  *          \c SPI_SR_TXEMPTY flags.
 * param[in] data the byte to be transmited on MISO
 * @note     Consider busy waiting for sspi_is_tdr_empty() before calling this function.
 *           Pending byte in TDR will will be replaced without sending by \a data
 *           if REG_SSPI_SR_TDRE was not asserted as this function was called.
 */
#pragma inline=forced
__INLINE void sspi_write_tdr(uint8_t data)
{
    REG_SSPI_TDR = data;
#ifndef SSPI_WRAPPER_SPI_IDX
    REG_SSPI_SR &= ~SPI_SR_TDRE & ~SPI_SR_TXEMPTY; // fill TDR => no more empty => clear the TDR Empty flag and ready to transmit a new byte
#endif
}

/**
 * @brief  Clears \c REG_SSPI_SR_UNDES flag and returns \c REG_SSPI_SR
 * @return \c REG_SSPI_SR
 */
#pragma inline=forced
__INLINE uint32_t sspi_read_sr()
{
#ifndef SSPI_WRAPPER_SPI_IDX
    const uint32_t status = REG_SSPI_SR;
    REG_SSPI_SR &= ~(SPI_SR_UNDES|SPI_SR_OVRES); // clear the UNDerrun and OVeRrun Error Status flags
    return status;
#else
    return REG_SSPI_SR;
#endif
}

#pragma inline=forced
__INLINE uint32_t sspi_is_rdr_full () { return sspi_read_sr() & SPI_SR_RDRF ; } ///< @return \c REG_SSPI_SR \& SPI_SR_RDRF
#pragma inline=forced
__INLINE uint32_t sspi_is_rdr_ovres() { return sspi_read_sr() & SPI_SR_OVRES; } ///< @return \c REG_SSPI_SR \& SPI_SR_OVRES
#pragma inline=forced
__INLINE uint32_t sspi_is_tdr_empty() { return sspi_read_sr() & SPI_SR_TDRE ; } ///< @return \c REG_SSPI_SR \& SPI_SR_TDRE
#pragma inline=forced
__INLINE uint32_t sspi_is_tx_empty() { return sspi_read_sr() & SPI_SR_TXEMPTY ; } ///< @return \c REG_SSPI_SR \& SPI_SR_TXEMPTY
#pragma inline=forced
__INLINE uint32_t sspi_is_tdr_undes() { return sspi_read_sr() & SPI_SR_UNDES; } ///< @return \c REG_SSPI_SR \& SPI_SR_UNDES
#pragma inline=forced
__INLINE uint32_t sspi_has_nss_rised() { return sspi_read_sr() & SPI_SR_NSSR; } ///< @return \c REG_SSPI_SR \& SPI_SR_NSSR
// ----------------------------------------------------------------------------  



/// @}
#endif /*SSPI_H_*/
