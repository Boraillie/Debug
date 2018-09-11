/*! \file *********************************************************************
 *
 * \brief PIO driver for SAM3.
 *
 * $asf_license$
 *
 * Parallel Input/Output (PIO) Controller driver module for SAM3 MCUs.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  All SAM devices.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.com/
 *
 ******************************************************************************/

//#include "compiler.h" //ERr => moved to pio.h
#include "pio.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#ifndef PIO_WPMR_WPKEY_VALUE
#ifdef PIO_WPMR_WPKEY_PASSWD
  #define PIO_WPMR_WPKEY_VALUE PIO_WPMR_WPKEY_PASSWD
#else
  #define PIO_WPMR_WPKEY_VALUE PIO_WPMR_WPKEY(0x50494Fu)
#endif
#endif
  
/**
 * \brief Configures Pio internal pull-up.
 *
 * \param p_pio             Pointer to a PIO controller.
 * \param dw_mask           Bitmask of one or more pin(s) to configure.
 * \param dw_pull_up_enable Indicates if the pin(s) internal pull-up shall be
 * configured.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root void pio_pull_up(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_pull_up_enable)
{
	/* Enable the pull-up(s) if necessary */
	if (dw_pull_up_enable) {
		p_pio->PIO_PUER = dw_mask;
	} else {
		p_pio->PIO_PUDR = dw_mask;
	}
}

/**
 * \brief Configures Glitch or Debouncing filter for the specified input(s).
 *
 * \param p_pio       Pointer to a PIO controller.
 * \param dw_mask     Bitmask of one or more pin(s) to configure.
 * \param dw_cut_off  Cutt off frequency for debounce filter.
 */
void pio_set_debounce_filter(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_cut_off)
{
#if (SIRIUS||SAM3S || SAM3S8 || SAM3N || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 || SAMG53 || LIMES || SAMG55 || CANOPUS || SAM9X6 )      //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2 AYI SAM4C MNn SAM9X6
	p_pio->PIO_IFSCER = dw_mask;	/* set Debouncing, 0 bit field no effect */
#elif (SAM3XA || SAM3U)
	p_pio->PIO_DIFSR = dw_mask;	/* set Debouncing, 0 bit field no effect */
#else
#error "Unsupported device"
#endif

	/* The debouncing filter can filter a pulse of less than 1/2 Period of a */
	/* programmable Divided Slow Clock: Tdiv_slclk = ((DIV+1)*2).Tslow_clock */
	p_pio->PIO_SCDR = PIO_SCDR_DIV((32678 / (2 * (dw_cut_off))) - 1);	
}

/**
 * \brief Sets a high output level on all the PIOs defined in dw_mask.
 * This has no immediate effects on PIOs that are not output, but the PIO
 * controller will save the value if they are changed to outputs.
 *
 * \param p_pio       Pointer to a PIO controller.
 * \param dw_mask     Bitmask of one or more pin(s) to configure.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root void pio_set(Pio * p_pio, const uint32_t dw_mask)
{
	p_pio->PIO_SODR = dw_mask;
}

/**
 * \brief Sets a low output level on all the PIOs defined in dw_mask.
 * This has no immediate effects on PIOs that are not output, but the PIO
 * controller will save the value if they are changed to outputs.
 *
 * \param p_pio       Pointer to a PIO controller.
 * \param dw_mask     Bitmask of one or more pin(s) to configure.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root void pio_clear(Pio * p_pio, const uint32_t dw_mask)
{
	p_pio->PIO_CODR = dw_mask;
}

/**
 * \brief Returns 1 if one or more PIO of the given Pin instance currently have
 * a high level; otherwise returns 0. This method returns the actual value that
 * is being read on the pin. To return the supposed output value of a pin, use
 * pio_get_output_data_status() instead.
 *
 * \param p_pio       Pointer to a PIO controller.
 * \param dw_type     PIO type.
 * \param dw_mask     Bitmask of one or more pin(s) to configure.
 *
 * \retval 1 at least one PIO currently has a high level.
 * \retval 0 all PIO have a low level.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root uint32_t pio_get(Pio * p_pio, const pio_type_t dw_type,
		const uint32_t dw_mask)
{
	uint32_t dw_reg;

	if ((dw_type == PIO_OUTPUT_0) || (dw_type == PIO_OUTPUT_1)) {
		dw_reg = p_pio->PIO_ODSR;
	} else {
		dw_reg = p_pio->PIO_PDSR;
	}

	if ((dw_reg & dw_mask) == 0) {
		return 0;
	} else {
		return 1;
	}
}

/**
 * \brief Configures IO of a PIO controller as being controlled by a specific 
 * peripheral.
 *
 * \param p_pio    Pointer to a PIO controller.
 * \param dw_type  PIO type.
 * \param dw_mask  Bitmask of one or more pin(s) to configure.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root void pio_set_peripheral(Pio * p_pio, const pio_type_t dw_type,
		const uint32_t dw_mask)
{
	uint32_t dw_sr;

	/* Disable interrupts on the pin(s) */
	p_pio->PIO_IDR = dw_mask;

#if (SIRIUS ||SAM3S || SAM3S8 || SAM3N || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 || SAMG53 || LIMES || SAMG55 || CANOPUS || SAM9X6) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2 AYI SAM4C MNn SAM9X6
	switch (dw_type) {
	case PIO_PERIPH_A:
		dw_sr = p_pio->PIO_ABCDSR[0];
		p_pio->PIO_ABCDSR[0] &= (~dw_mask & dw_sr);

		dw_sr = p_pio->PIO_ABCDSR[1];
		p_pio->PIO_ABCDSR[1] &= (~dw_mask & dw_sr);
		break;

	case PIO_PERIPH_B:
		dw_sr = p_pio->PIO_ABCDSR[0];
		p_pio->PIO_ABCDSR[0] = (dw_mask | dw_sr);

		dw_sr = p_pio->PIO_ABCDSR[1];
		p_pio->PIO_ABCDSR[1] &= (~dw_mask & dw_sr);
		break;
#if PIO_HAS_PERIPH_C
	case PIO_PERIPH_C:
		dw_sr = p_pio->PIO_ABCDSR[0];
		p_pio->PIO_ABCDSR[0] &= (~dw_mask & dw_sr);

		dw_sr = p_pio->PIO_ABCDSR[1];
		p_pio->PIO_ABCDSR[1] = (dw_mask | dw_sr);
		break;
#endif
#if PIO_HAS_PERIPH_D
	case PIO_PERIPH_D:
		dw_sr = p_pio->PIO_ABCDSR[0];
		p_pio->PIO_ABCDSR[0] = (dw_mask | dw_sr);

		dw_sr = p_pio->PIO_ABCDSR[1];
		p_pio->PIO_ABCDSR[1] = (dw_mask | dw_sr);
		break;
#endif
		// other types are invalid in this function
	case PIO_INPUT:
	case PIO_OUTPUT_0:
	case PIO_OUTPUT_1:
	case PIO_NOT_A_PIN:
		return;
	}
#elif (SAM3XA|| SAM3U)
	switch (dw_type) {
	case PIO_PERIPH_A:
		dw_sr = p_pio->PIO_ABSR;
		p_pio->PIO_ABSR &= (~dw_mask & dw_sr);
		break;

	case PIO_PERIPH_B:
		dw_sr = p_pio->PIO_ABSR;
		p_pio->PIO_ABSR = (dw_mask | dw_sr);
		break;

		// other types are invalid in this function
	case PIO_INPUT:
	case PIO_OUTPUT_0:
	case PIO_OUTPUT_1:
	case PIO_NOT_A_PIN:
		return;
	}
#else
#error "Unsupported device"
#endif

	// Remove the pins from under the control of PIO
	p_pio->PIO_PDR = dw_mask;
}

/**
 * \brief Configures one or more pin(s) or a PIO controller as inputs. 
 * Optionally, the corresponding internal pull-up(s) and glitch filter(s) can 
 * be enabled.
 *
 * \param p_pio        Pointer to a PIO controller.
 * \param dw_mask      Bitmask indicating which pin(s) to configure as input(s).
 * \param dw_attribute PIO attribute.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root void pio_set_input(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_attribute)
{
	pio_disable_interrupt(p_pio, dw_mask);
	pio_pull_up(p_pio, dw_mask, dw_attribute & PIO_PULLUP);

	/* Enable Input Filter if necessary */
	if (dw_attribute & (PIO_DEGLITCH | PIO_DEBOUNCE)) {
		p_pio->PIO_IFER = dw_mask;
	} else {
		p_pio->PIO_IFDR = dw_mask;
	}

#if (SIRIUS ||SAM3S || SAM3S8 || SAM3N || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 || SAMG53 || LIMES || SAMG55||CANOPUS || SAM9X6) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2 AYi SAM4C MNn SAM9X6
	/* Enable de-glitch or de-bounce if necessary */
	if (dw_attribute & PIO_DEGLITCH) {
		p_pio->PIO_IFSCDR = dw_mask;
	} else {
		if (dw_attribute & PIO_DEBOUNCE) {
			p_pio->PIO_IFSCER = dw_mask;
		}
	}
#elif (SAM3XA|| SAM3U)
	/* Enable de-glitch or de-bounce if necessary */
	if (dw_attribute & PIO_DEGLITCH) {
		p_pio->PIO_SCIFSR = dw_mask;
	} else {
		if (dw_attribute & PIO_DEBOUNCE) {
			p_pio->PIO_SCIFSR = dw_mask;
		}
	}
#else
#error "Unsupported device"
#endif

	/* Configure pin as input */
	p_pio->PIO_ODR = dw_mask;
	p_pio->PIO_PER = dw_mask;
}

/**
 * \brief Configures one or more pin(s) of a PIO controller as outputs, with 
 * the given default value. Optionally, the multi-drive feature can be enabled
 * on the pin(s).
 *
 * \param p_pio                Pointer to a PIO controller.
 * \param dw_mask              Bitmask indicating which pin(s) to configure.
 * \param dw_default_level     Default level on the pin(s).
 * \param dw_multidrive_enable Indicates if the pin(s) shall be configured as 
 * open-drain.
 * \param dw_pull_up_enable    Indicates if the pin shall have its pull-up 
 * activated.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root void pio_set_output(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_default_level,
		const uint32_t dw_multidrive_enable,
		const uint32_t dw_pull_up_enable)
{
	pio_disable_interrupt(p_pio, dw_mask);
	pio_pull_up(p_pio, dw_mask, dw_pull_up_enable);

	/* Enable multi-drive if necessary */
	if (dw_multidrive_enable) {
		p_pio->PIO_MDER = dw_mask;
	} else {
		p_pio->PIO_MDDR = dw_mask;
	}

	/* Set default value */
	if (dw_default_level) {
		p_pio->PIO_SODR = dw_mask;
	} else {
		p_pio->PIO_CODR = dw_mask;
	}

	/* Configure pin(s) as output(s) */
	p_pio->PIO_OER = dw_mask;
	p_pio->PIO_PER = dw_mask;
}

/**
 * \brief Perform complete pins configuration; general attributes and PIO init 
 * if necessary.
 *
 * \param p_pio Pointer to a PIO instance.
 * \param dw_type PIO type.
 * \param dw_mask Bitmask of one or more pin(s) to configure.
 * \param dw_attribute Pins attributes.
 *
 * \return Whether the pins have been configured properly.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root uint32_t pio_configure(Pio * p_pio, const pio_type_t dw_type,
		const uint32_t dw_mask, const uint32_t dw_attribute)
{
	/* Configure pins */
	switch (dw_type) {
	case PIO_PERIPH_A:
	case PIO_PERIPH_B:
#if (SIRIUS ||SAM3S || SAM3S8 || SAM3N || SAM4S || SAMA5) //ERr SAM4S SAM3S8 SAMA5
	case PIO_PERIPH_C:
	case PIO_PERIPH_D:
#endif
		pio_set_peripheral(p_pio, dw_type, dw_mask);
		pio_pull_up(p_pio, dw_mask, (dw_attribute & PIO_PULLUP));
		break;

	case PIO_INPUT:
		pio_set_input(p_pio, dw_mask, dw_attribute);
		break;

	case PIO_OUTPUT_0:
	case PIO_OUTPUT_1:
		pio_set_output(p_pio, dw_mask, (dw_type == PIO_OUTPUT_1),
				(dw_attribute & PIO_OPENDRAIN) ? 1 : 0,
				(dw_attribute & PIO_PULLUP) ? 1 : 0);
		break;

	default:
		return 0;
	}

	return 1;
}

/**
 * \brief Returns 1 if one or more PIO of the given Pin are configured to 
 * output a high level (even if they are not output).
 * To get the actual value of the pin, use PIO_Get() instead.
 *
 * \param p_pio  Pointer to a Pin instance describing one or more pins.
 * \param dw_mask Bitmask of one or more pin(s).
 *
 * \retval 1 at least one PIO is configured to output a high level.
 * \retval 0 all PIOs are configued to output a low level.
 */
uint32_t pio_get_output_data_status(const Pio * p_pio,
		const uint32_t dw_mask)
{
	if ((p_pio->PIO_ODSR & dw_mask) == 0) {
		return 0;
	} else {
		return 1;
	}
}

/**
 * \brief Configures Pio pin multi-driver.
 *
 * \param p_pio                  Pointer to a PIO controller.
 * \param dw_mask                Bitmask of one or more pin(s) to configure.
 * \param dw_multi_driver_enable Indicates if the pin(s) multi-driver shall be 
 * configured.
 */
void pio_set_multi_driver(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_multi_driver_enable)
{
	/* Enable the multi-driver if necessary */
	if (dw_multi_driver_enable) {
		p_pio->PIO_MDER = dw_mask;
	} else {
		p_pio->PIO_MDDR = dw_mask;
	}
}

/**
 * \brief Get multi-driver status.
 *
 * \param p_pio  Pointer to a Pin instance describing one or more pins.
 *
 * \return The multi-driver mask value.
 */
uint32_t pio_get_multi_driver_status(const Pio * p_pio)
{
	return p_pio->PIO_MDSR;
}


#if (SAM3S || SAM3N)
/**
 * \brief Configures Pio pin internal pull-down.
 *
 * \param p_pio               Pointer to a PIO controller.
 * \param dw_mask             Bitmask of one or more pin(s) to configure.
 * \param dw_pull_down_enable Indicates if the pin(s) internal pull-down shall 
 * be configured.
 */
void pio_pull_down(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_pull_down_enable)
{
	/* Enable the pull-down if necessary */
	if (dw_pull_down_enable) {
		p_pio->PIO_PPDER = dw_mask;
	} else {
		p_pio->PIO_PPDDR = dw_mask;
	}
}
#endif

/**
 * \brief Enables PIO output write for synchronous data output.
 *
 * \param p_pio   Pointer to a PIO instance.
 * \param dw_mask Bitmask of one or more pin(s) to configure.
 */
void pio_enable_output_write(Pio * p_pio, const uint32_t dw_mask)
{
	p_pio->PIO_OWER = dw_mask;
}

/**
 * \brief Disables PIO output write.
 *
 * \param p_pio   Pointer to a PIO instance.
 * \param dw_mask Bitmask of one or more pin(s) to configure.
 */
void pio_disable_output_write(Pio * p_pio, const uint32_t dw_mask)
{
	p_pio->PIO_OWDR = dw_mask;
}

/**
 * \brief Reads PIO output write status.
 *
 * \param p_pio Pointer to a PIO instance.
 *
 * \return The output write mask value.
 */
uint32_t pio_get_output_write_status(const Pio * p_pio)
{
	return p_pio->PIO_OWSR;
}

/**
 * \brief Synchronously writes on output pins.
 * \note Only bits unmasked by PIO_OWSR (Output Write Status Register) are 0
 * written.
 *
 * \param p_pio   Pointer to a PIO instance.
 * \param dw_mask Bitmask of one or more pin(s) to configure.
 */
void pio_sync_output_write(Pio * p_pio, const uint32_t dw_mask)
{
	p_pio->PIO_ODSR = dw_mask;
}

#if (SAM3S || SAM3N)
/**
 * \brief Configures PIO pin schmitt trigger. By default the Schmitt trigger is
 * active.
 * Disabling the Schmitt Trigger is requested when using the QTouch Library.
 *
 * \param p_pio              Pointer to a PIO controller.
 * \param dw_mask            Bitmask of one or more pin(s) to configure.
 */
void pio_set_schmitt_trigger(Pio * p_pio, const uint32_t dw_mask)
{
	p_pio->PIO_SCHMITT = dw_mask;
}

/**
 * \brief Get PIO pin schmitt trigger status.
 *
 * \param p_pio              Pointer to a PIO controller.
 *
 * \return The schmitt trigger mask value.
 */
uint32_t pio_get_schmitt_trigger(const Pio * p_pio)
{
	return p_pio->PIO_SCHMITT;
}
#endif

/**
 * \brief Enables the given interrupt source.
 * The PIO must be configured as an NVIC interrupt source as well.
 * The status register of the corresponding PIO controller is cleared 
 * prior to enabling the interrupt.
 *
 * \param p_pio   Pointer to a PIO instance.
 * \param dw_mask interrupt sources bit map.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root void pio_enable_interrupt(Pio * p_pio, const uint32_t dw_mask)
{
	p_pio->PIO_ISR;
	p_pio->PIO_IER = dw_mask;
}

/**
 * \brief Disables a given interrupt source, with no added side effects.
 *
 * \param p_pio   Pointer to a PIO instance.
 * \param dw_mask interrupt sources bit map.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root void pio_disable_interrupt(Pio * p_pio, const uint32_t dw_mask)
{
	p_pio->PIO_IDR = dw_mask;
}

/**
 * \brief Reads PIO interrupt status.
 *
 * \param p_pio Pointer to a PIO instance.
 *
 * \return The interrupt status mask value.
 */
uint32_t pio_get_interrupt_status(const Pio * p_pio)
{
	return p_pio->PIO_ISR;
}

/**
 * \brief Reads PIO interrupt mask.
 *
 * \param p_pio Pointer to a PIO instance.
 *
 * \return The interrupt mask value.
 */
uint32_t pio_get_interrupt_mask(const Pio * p_pio)
{
	return p_pio->PIO_IMR;
}

/**
 * \brief Set additional interrupt mode.
 *
 * \param p_pio   		Pointer to a PIO instance.
 * \param dw_mask 		interrupt sources bit map.
 * \param dw_attribute	Pins attributes.
 */
void pio_set_additional_interrupt_mode(Pio * p_pio,
		const uint32_t dw_mask, const uint32_t dw_attribute)
{
	/* Enable additional interrupt mode if needed */
	if (dw_attribute & PIO_IT_AIME) {
		/* Enable additional interrupt mode */
		p_pio->PIO_AIMER = dw_mask;

		/* Configure the Polarity of the event detection */
		/* (Rising/Falling Edge or High/Low Level) */
		if (dw_attribute & PIO_IT_RE_OR_HL) {
			p_pio->PIO_REHLSR = dw_mask;	/* Rising Edge or High Level */
		} else {
			p_pio->PIO_FELLSR = dw_mask;	/* Falling Edge or Low Level */
		}

		/* Configure the type of event detection (Edge or Level) */
		if (dw_attribute & PIO_IT_EDGE) {
			p_pio->PIO_ESR = dw_mask;	/* Edge select */
		} else {
			p_pio->PIO_LSR = dw_mask;	/* Level select */
		}
	} else {
		/* Disable additional interrupt mode */
		p_pio->PIO_AIMDR = dw_mask;
	}
}



/**
 * \brief Enables/Disables write protect of the specified PIO register.
 *
 * \param p_pio Pointer to a PIO instance.
 * \param dw_enable 1 to enable, 0 to disable.
 */
void pio_set_writeprotect(Pio * p_pio, const uint32_t dw_enable)
{
	p_pio->PIO_WPMR = PIO_WPMR_WPKEY_VALUE | dw_enable;
}

/**
 * \brief Reads write protect status.
 *
 * \param p_pio Pointer to a PIO instance.
 *
 * \return Return write protect status.
 */
uint32_t pio_get_writeprotect_status(const Pio * p_pio)
{
	return p_pio->PIO_WPSR;
}

#if (SAM3S)
/**
 * \brief Configures PIO capture mode.
 * \note PIO capture mode will be disabled automatically.
 *
 * \param p_pio    Pointer to a PIO instance.
 * \param dw_mode  Bitmask of one or more modes.
 */
void pio_capture_set_mode(Pio * p_pio, uint32_t dw_mode)
{
	dw_mode &= (~PIO_PCMR_PCEN);	/* Disable PIO capture mode */
	p_pio->PIO_PCMR = dw_mode;
}

/**
 * \brief Enables PIO capture mode.
 *
 * \param p_pio    Pointer to a PIO instance.
 */
void pio_capture_enable(Pio * p_pio)
{
	p_pio->PIO_PCMR |= PIO_PCMR_PCEN;
}

/**
 * \brief Disables PIO capture mode.
 *
 * \param p_pio    Pointer to a PIO instance.
 */
void pio_capture_disable(Pio * p_pio)
{
	p_pio->PIO_PCMR &= (~PIO_PCMR_PCEN);
}

/**
 * \brief Reads from Capture Reception Holding Register.
 * Data presence should be tested before any read attempt.
 *
 * \param p_pio    Pointer to a PIO instance.
 * \param pdw_data Pointer to store the data.
 *
 * \retval 0 Success.
 * \retval 1 I/O Failure, Capture data is not ready.
 */
uint32_t pio_capture_read(const Pio * p_pio, uint32_t * pdw_data)
{
	/* Check if the data is ready */
	if ((p_pio->PIO_PCISR & PIO_PCISR_DRDY) == 0) {
		return 1;
	}

	/* Read data */
	*pdw_data = p_pio->PIO_PCRHR;
	return 0;
}

/**
 * \brief Enables the given interrupt source of PIO capture. The status
 * register of the corresponding PIO capture controller is cleared prior
 * to enabling the interrupt.
 *
 * \param p_pio   Pointer to a PIO instance.
 * \param dw_mask interrupt sources bit map.
 */
void pio_capture_enable_interrupt(Pio * p_pio, const uint32_t dw_mask)
{
	p_pio->PIO_PCISR;
	p_pio->PIO_PCIER = dw_mask;
}

/**
 * \brief Disables a given interrupt source of PIO capture.
 *
 * \param p_pio   Pointer to a PIO instance.
 * \param dw_mask interrupt sources bit map.
 */
void pio_capture_disable_interrupt(Pio * p_pio, const uint32_t dw_mask)
{
	p_pio->PIO_PCIDR = dw_mask;
}

/**
 * \brief Reads PIO interrupt status of PIO capture.
 *
 * \param p_pio Pointer to a PIO instance.
 *
 * \return The interrupt status mask value.
 */
uint32_t pio_capture_get_interrupt_status(const Pio * p_pio)
{
	return p_pio->PIO_PCISR;
}

/**
 * \brief Reads PIO interrupt mask of PIO capture.
 *
 * \param p_pio Pointer to a PIO instance.
 *
 * \return The interrupt mask value.
 */
uint32_t pio_capture_get_interrupt_mask(const Pio * p_pio)
{
	return p_pio->PIO_PCIMR;
}

/**
 * \brief Get PDC registers base address
 *
 * \param p_pio Pointer to an PIO peripheral.
 *
 * \return PDC registers base for PDC driver to access.
 */
Pdc *pio_capture_get_pdc_base(const Pio * p_pio)
{
	p_pio = p_pio;	/* Stop warning */
	return PDC_PIOA;
}

#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
