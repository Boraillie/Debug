/*! \file *********************************************************************
 *
 * \brief Reset Controller (RSTC) driver for AT91SAM devices.
 *
 * - Compiler:           IAR EWARM and CodeSourcery GCC for ARM
 * - Supported devices:  All SAM devices can be used.
 * - AppNote:
 *
 ******************************************************************************/
// $asf_license$

#ifndef _SAM_RSTC_
#define _SAM_RSTC_

#include  "compiler.h"

//! \name RSTC reset modes
//! @{
//! RSTC reset modes bits
typedef enum rstc_reset_mode {
	RSTC_PROCRST = RSTC_CR_PROCRST, //!< Processor Reset
	RSTC_PERRST = RSTC_CR_PERRST, //!< Peripheral Reset
#if NRST_IS_INPUT_ONLY==0
	RSTC_EXTRST = RSTC_CR_EXTRST, //!< External Reset
	RSTC_RST_ALL = (RSTC_PROCRST|RSTC_PERRST|RSTC_EXTRST)
#else
	RSTC_RST_ALL = (RSTC_PROCRST|RSTC_PERRST)
#endif
} rstc_reset_mode_t;
//! @}

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#if NRST_IS_INPUT_ONLY==0
/**
 * \brief Initialize external reset with giving timing length
 * \param p_rstc Pointer to a rstc registers set instance
 * \param dw_length The length of external reset
 */
extern uint32_t rstc_init_external_reset( Rstc* p_rstc, uint32_t dw_length ) ;
#endif

#ifndef SAMA5 //ERr SAMA5
/**
 * \brief Enable the detection of user reset
 * \param p_rstc Pointer to a rstc registers set instance
 */
extern void rstc_enable_user_reset( Rstc* p_rstc ) ;
/**
 * \brief Disable the detection of user reset
 * \param p_rstc Pointer to a rstc registers set instance
 */
extern void rstc_disable_user_reset( Rstc* p_rstc ) ;
/**
 * \brief Enable user reset interrupt
 * \param p_rstc Pointer to a rstc registers set instance
 */
extern void rstc_enable_interrupt( Rstc* p_rstc ) ;

/**
 * \brief Disable user reset interrupt
 * \param p_rstc Pointer to a rstc registers set instance
 */
extern void rstc_disable_interrupt( Rstc* p_rstc ) ;
#endif //ERr SAMA5


/**
 * \brief Performed software reset with giving reset mode.
 * \param p_rstc Pointer to a rstc registers set instance
 * \param dw_mode The mode of software reset in bitmap:\n
 *                - \ref RSTC_PROCRST: reset processor\n
 *                - \ref RSTC_PERRST: reset peripherals\n
 *                - \ref RSTC_EXTRST: reset external
 */
extern void rstc_software_reset( Rstc* p_rstc , uint32_t dw_mode ) ;

/**
 * \brief Get rtsc status
 * \param p_rstc Pointer to a rstc registers set instance
 * \return value of status register
 */
extern uint32_t rstc_read_status( Rstc* p_rstc ) ;

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* #ifndef _SAM_RSTC_ */

