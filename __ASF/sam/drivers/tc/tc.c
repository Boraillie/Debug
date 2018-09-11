/*! \file *********************************************************************
 *
 * \brief TC driver for SAM3.
 *
 * TC (Timer Counter) driver module for SAM MCUs.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  All SAM devices.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.com/
 *
 ******************************************************************************/

/* $asf_license$ */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include <assert.h>
#include "tc.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/*----------------------------------------------------------------------------
 *        Global Functions
 *----------------------------------------------------------------------------*/
/**
 * \brief Configure TC for timer, waveform generation or capture.
 *
 * \param tc Pointer to the TC peripheral to configure.
 * \param ul_channel Channel to configure.
 * \param ul_mode Control mode register value to set.
 */
void tc_init(Tc * p_tc, uint32_t ul_channel, uint32_t ul_mode)
{
	TcChannel *tc_channel;

	assert(ul_channel <
			(sizeof(p_tc->TC_CHANNEL) / sizeof(p_tc->TC_CHANNEL[0])));
	tc_channel = p_tc->TC_CHANNEL + ul_channel;

	/*  Disable TC clock */
	tc_channel->TC_CCR = TC_CCR_CLKDIS;

	/*  Disable interrupts */
	tc_channel->TC_IDR = 0xFFFFFFFF;

	/*  Clear status register */
	tc_channel->TC_SR;

	/*  Set mode */
	tc_channel->TC_CMR = ul_mode;
}

/**
 * \brief Configure TC for Quadrature Decoder Logic.
 * Note : tc_init must be called first.
 *
 * \param tc Pointer to the TC peripheral to configure.
 * \param ul_blockmode Block mode register value to set.
 *
 * \return 0 for OK.
 */
uint32_t tc_init_quad_dec(Tc * p_tc, uint32_t ul_blockmode)
{
	p_tc->TC_BMR = ul_blockmode;
	return 0;
}

//#if (SAM3S || SAM3N || SAM3XA || SAM4S) //ERr SAM4S
#if (TC_HAS_SMMR == 1)
/**
 * \brief Configure TC for 2-bit Gray Counter for Stepper Motor.
 * Note : tc_init must be called first.
 *
 * \param tc Pointer to the TC peripheral to configure.
 * \param ul_channel Channel to configure.
 * \param ul_steppermode Stepper motor mode register value to set.
 *
 * \return 0 for OK.
 */
uint32_t tc_init_2bit_gray(Tc * p_tc, uint32_t ul_channel,
		uint32_t ul_steppermode)
{
	TcChannel *tc_channel;

	assert(ul_channel <
			(sizeof(p_tc->TC_CHANNEL) / sizeof(p_tc->TC_CHANNEL[0])));
	tc_channel = p_tc->TC_CHANNEL + ul_channel;
	tc_channel->TC_SMMR = ul_steppermode;
	return 0;
}
#endif
/**
 * \brief Enable TC clock counter on the selected channel.
 *
 * \param tc Pointer to an TC peripheral.
 * \param ul_channel Channel to configure.
 */
void tc_enable(Tc * p_tc, uint32_t ul_channel)
{
	TcChannel *tc_channel;

	assert(ul_channel <
			(sizeof(p_tc->TC_CHANNEL) / sizeof(p_tc->TC_CHANNEL[0])));

	tc_channel = p_tc->TC_CHANNEL + ul_channel;
	tc_channel->TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
}

/**
 * \brief Disable TC clock counter on the selected channel.
 *
 * \param tc Pointer to an TC peripheral.
 * \param ul_channel Channel to configure.
 */
void tc_disable(Tc * p_tc, uint32_t ul_channel)
{
	TcChannel *tc_channel;

	assert(ul_channel <
			(sizeof(p_tc->TC_CHANNEL) / sizeof(p_tc->TC_CHANNEL[0])));

	tc_channel = p_tc->TC_CHANNEL + ul_channel;
	tc_channel->TC_CCR = TC_CCR_CLKDIS;
}

/** 
 * \brief Enable TC interrupts on the selected channel.
 *
 * \param tc pointer to an Tc instance.
 * \param ul_channel Channel to configure.
 * \param ul_sources interrupt sources bit map.
 */
void tc_enable_interrupt(Tc * p_tc, uint32_t ul_channel,
		uint32_t ul_sources)
{
	TcChannel *tc_channel;

	assert(ul_channel <
			(sizeof(p_tc->TC_CHANNEL) / sizeof(p_tc->TC_CHANNEL[0])));
	tc_channel = p_tc->TC_CHANNEL + ul_channel;
	tc_channel->TC_IER = ul_sources;
}

/** 
 * \brief Disable TC interrupts on the selected channel.
 *
 * \param tc pointer to an Tc instance.
 * \param ul_channel Channel to configure.
 * \param ul_sources interrupt sources bit map.
 */
void tc_disable_interrupt(Tc * p_tc, uint32_t ul_channel,
		uint32_t ul_sources)
{
	TcChannel *tc_channel;

	assert(ul_channel <
			(sizeof(p_tc->TC_CHANNEL) / sizeof(p_tc->TC_CHANNEL[0])));
	tc_channel = p_tc->TC_CHANNEL + ul_channel;
	tc_channel->TC_IDR = ul_sources;
}

/** 
 * \brief Read TC interrupt mask on the selected channel.
 *
 * \param tc pointer to an Tc instance.
 * \param ul_channel Channel to configure.
 *
 * \return The interrupt mask value.
 */
uint32_t tc_get_interrupt_mask(Tc * p_tc, uint32_t ul_channel)
{
	TcChannel *tc_channel;

	assert(ul_channel <
			(sizeof(p_tc->TC_CHANNEL) / sizeof(p_tc->TC_CHANNEL[0])));
	tc_channel = p_tc->TC_CHANNEL + ul_channel;
	return tc_channel->TC_IMR;
}

/**
 * \brief Get current status on the selected channel.
 *
 * \param tc Pointer to an Tc instance.
 * \param ul_channel Channel to configure.
 *
 * \return The current TC status.
 */
uint32_t tc_get_status(Tc * p_tc, uint32_t ul_channel)
{
	TcChannel *tc_channel;

	assert(ul_channel <
			(sizeof(p_tc->TC_CHANNEL) / sizeof(p_tc->TC_CHANNEL[0])));
	tc_channel = p_tc->TC_CHANNEL + ul_channel;
	return tc_channel->TC_SR;
}

/**
 * \brief Find best MCK divisor
 *
 * Finds the best MCK divisor given the timer frequency and MCK. The result
 * is guaranteed to satisfy the following equation:
 * \code
 *   (MCK / (DIV * 65536)) <= freq <= (MCK / DIV)
 * \endcode
 * with DIV being the highest possible value.
 *
 * \param ul_freq  Desired timer frequency.
 * \param ul_mck  Master clock frequency.
 * \param p_uldiv  Divisor value.
 * \param p_ultcclks  TCCLKS field value for divisor.
 * \param ul_boardmck  Board clock frequency.
 *
 * \return 1 if a proper divisor has been found, otherwise 0.
 */
uint32_t tc_find_mck_divisor(uint32_t ul_freq, uint32_t ul_mck,
		uint32_t * p_uldiv, uint32_t * p_ultcclks, uint32_t ul_boardmck)
{
	const uint32_t adwDivisors[5] = { 2, 8, 32, 128, ul_boardmck / 32768 };

	uint32_t dwIndex = 0;

	/*  Satisfy lower bound */
	while (ul_freq < ((ul_mck / adwDivisors[dwIndex]) / 65536)) {
		dwIndex++;

		/*  If no divisor can be found, return 0 */
		if (dwIndex == (sizeof(adwDivisors) / sizeof(adwDivisors[0]))) {
			return 0;
		}
	}

	/*  Try to maximize DIV while satisfying upper bound */
	while (dwIndex < 4) {

		if (ul_freq > (ul_mck / adwDivisors[dwIndex + 1])) {
			break;
		}
		dwIndex++;
	}

	/*  Store results */
	if (p_uldiv) {
		*p_uldiv = adwDivisors[dwIndex];
	}
	if (p_ultcclks) {
		*p_ultcclks = dwIndex;
	}

	return 1;
}

#if (TC_HAS_QDEC == 1) //ERr
/** 
 * \brief Enable TC QDEC interrupts.
 *
 * \param tc pointer to an Tc instance.
 * \param ul_sources interrupt sources bit map.
 */
void tc_enable_qdec_interrupt(Tc * p_tc, uint32_t ul_sources)
{
	p_tc->TC_QIER = ul_sources;
}

/** 
 * \brief Disable TC QDEC interrupts.
 *
 * \param tc pointer to an Tc instance.
 * \param ul_sources interrupt sources bit map.
 */
void tc_disable_qdec_interrupt(Tc * p_tc, uint32_t ul_sources)
{
	p_tc->TC_QIDR = ul_sources;
}

/** 
 * \brief Read TC QDEC interrupt mask.
 *
 * \param tc pointer to an Tc instance.
 *
 * \return The interrupt mask value.
 */
uint32_t tc_get_qdec_interrupt_mask(Tc * p_tc)
{
	return p_tc->TC_QIMR;
}

/**
 * \brief Get current QDEC status.
 *
 * \param tc Pointer to an Tc instance.
 *
 * \return The current TC status.
 */
uint32_t tc_get_qdec_interrupt_status(Tc * p_tc)
{
	return p_tc->TC_QISR;
}
#endif

//#if (SAM3S || SAM3N || SAM3XA || SAM4S) //ERr SAM4S
#if (TC_HAS_WR_PROTECT == 1) //ERr
/** 
 * \brief Enable/Disable write protect of TC registers.
 *
 * \param tc pointer to TC registers set instance.
 * \param ul_enable 1 to enable, 0 to disable.
 */
void tc_set_writeprotect(Tc * p_tc, uint32_t ul_enable)
{
	p_tc->TC_WPMR |= ul_enable;
}
#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
