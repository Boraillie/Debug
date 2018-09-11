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

#ifndef PIO_H_INCLUDED
#define PIO_H_INCLUDED

#include "compiler.h"

typedef enum _pio_type {
	PIO_NOT_A_PIN,	/* The pin is not a function pin. */
	PIO_PERIPH_A,	/* The pin is controlled by the peripheral A. */
	PIO_PERIPH_B,	/* The pin is controlled by the peripheral B. */
#if (SIRIUS ||SAM3S || SAM3S8 || SAM3N || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 | CANOPUS || SAM9X6 ) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2 AYi SAM4C MNn SAM9X6
	PIO_PERIPH_C,	/* The pin is controlled by the peripheral C. */
	PIO_PERIPH_D,	/* The pin is controlled by the peripheral D. */
#endif
	PIO_INPUT,	/* The pin is an input. */
	PIO_OUTPUT_0,	/* The pin is an output and has a default level of 0. */
	PIO_OUTPUT_1	/* The pin is an output and has a default level of 1. */
} pio_type_t;

/*  Default pin configuration (no attribute). */
#define PIO_DEFAULT                 (0u << 0)
/*  The internal pin pull-up is active. */
#define PIO_PULLUP                  (1u << 0)
/*  The internal glitch filter is active. */
#define PIO_DEGLITCH                (1u << 1)
/*  The pin is open-drain. */
#define PIO_OPENDRAIN               (1u << 2)

/*  The internal debouncing filter is active. */
#define PIO_DEBOUNCE                (1u << 3)

/*  Enable additional interrupt modes. */
#define PIO_IT_AIME                 (1u << 4)

/*  Interrupt High Level/Rising Edge detection is active. */
#define PIO_IT_RE_OR_HL             (1u << 5)
/*  Interrupt Edge detection is active. */
#define PIO_IT_EDGE                 (1u << 6)

/*  Low level interrupt is active */
#define PIO_IT_LOW_LEVEL            (0               | 0 | PIO_IT_AIME)
/*  High level interrupt is active */
#define PIO_IT_HIGH_LEVEL           (PIO_IT_RE_OR_HL | 0 | PIO_IT_AIME)
/*  Falling edge interrupt is active */
#define PIO_IT_FALL_EDGE            (0               | PIO_IT_EDGE | PIO_IT_AIME)
/*  Rising edge interrupt is active */
#define PIO_IT_RISE_EDGE            (PIO_IT_RE_OR_HL | PIO_IT_EDGE | PIO_IT_AIME)

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/*
 *  The #attribute# field is a bitmask that can either be set to PIO_DEFAULT,
 *  or combine (using bitwise OR '|') any number of the following constants:
 *     - PIO_PULLUP
 *     - PIO_DEGLITCH
 *     - PIO_DEBOUNCE
 *     - PIO_OPENDRAIN
 *     - PIO_IT_LOW_LEVEL
 *     - PIO_IT_HIGH_LEVEL
 *     - PIO_IT_FALL_EDGE
 *     - PIO_IT_RISE_EDGE
 */
extern void pio_pull_up(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_pull_up_enable);
extern void pio_set_debounce_filter(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_cut_off);

extern void pio_set(Pio * p_pio, const uint32_t dw_mask);
extern void pio_clear(Pio * p_pio, const uint32_t dw_mask);
extern uint32_t pio_get(Pio * p_pio, const pio_type_t dw_type,
		const uint32_t dw_mask);

extern void pio_set_peripheral(Pio * p_pio, const pio_type_t dw_type,
		const uint32_t dw_mask);
extern void pio_set_input(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_attribute);
extern void pio_set_output(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_default_level,
		const uint32_t dw_multidrive_enable,
		const uint32_t dw_pull_up_enable);

extern uint32_t pio_configure(Pio * p_pio, const pio_type_t dw_type,
		const uint32_t dw_mask, const uint32_t dw_attribute);

extern uint32_t pio_get_output_data_status(const Pio * p_pio,
		const uint32_t dw_mask);

extern void pio_set_multi_driver(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_multi_driver_enable);
extern uint32_t pio_get_multi_driver_status(const Pio * p_pio);

#if (SIRIUS ||SAM3S || SAM3S8 || SAM3N || SAM4S || SAMA5) //ERr SAM4S SAM3S8 SAMA5
extern void pio_pull_down(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_pull_down_enable);
#endif

extern void pio_enable_output_write(Pio * p_pio, const uint32_t dw_mask);
extern void pio_disable_output_write(Pio * p_pio, const uint32_t dw_mask);
extern uint32_t pio_get_output_write_status(const Pio * p_pio);
extern void pio_sync_output_write(Pio * p_pio, const uint32_t dw_mask);

#if (SIRIUS ||SAM3S || SAM3S8 || SAM3N || SAM4S || SAMA5) //ERr SAM4S SAM3S8 SAMA5
extern void pio_set_schmitt_trigger(Pio * p_pio, const uint32_t dw_mask);
extern uint32_t pio_get_schmitt_trigger(const Pio * p_pio);
#endif

extern void pio_enable_interrupt(Pio * p_pio, const uint32_t dw_mask);
extern void pio_disable_interrupt(Pio * p_pio, const uint32_t dw_mask);
extern uint32_t pio_get_interrupt_status(const Pio * p_pio);
extern uint32_t pio_get_interrupt_mask(const Pio * p_pio);
extern void pio_set_additional_interrupt_mode(Pio * p_pio,
		const uint32_t dw_mask, const uint32_t dw_attribute);

extern void pio_set_writeprotect(Pio * p_pio, const uint32_t dw_enable);
extern uint32_t pio_get_writeprotect_status(const Pio * p_pio);

#if (SIRIUS ||SAM3S || SAM3S8 || SAM4S) //ERr SAM4S SAM3S8
extern void pio_capture_set_mode(Pio * p_pio, uint32_t dw_mode);
extern void pio_capture_enable(Pio * p_pio);
extern void pio_capture_disable(Pio * p_pio);
extern uint32_t pio_capture_read(const Pio * p_pio, uint32_t * pdw_data);
extern void pio_capture_enable_interrupt(Pio * p_pio, const uint32_t dw_mask);
extern void pio_capture_disable_interrupt(Pio * p_pio, const uint32_t dw_mask);
extern uint32_t pio_capture_get_interrupt_status(const Pio * p_pio);
extern uint32_t pio_capture_get_interrupt_mask(const Pio * p_pio);
extern Pdc *pio_capture_get_pdc_base(const Pio * p_pio);
#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* PIO_H_INCLUDED */
