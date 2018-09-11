/*! \file *********************************************************************
 *
 * \brief Reset Controller (RSTC) driver implement for AT91SAM devices.
 *
 * - Compiler:           IAR EWARM and CodeSourcery GCC for ARM
 * - Supported devices:  All SAM devices can be used.
 * - AppNote:
 *
 ******************************************************************************/
// $asf_license$

#include  "rstc.h"

#define RSTC_KEY    0xA5u

#if !defined(NRST_IS_INPUT_ONLY) || (NRST_IS_INPUT_ONLY==0)
uint32_t rstc_init_external_reset( Rstc* p_rstc, uint32_t dw_length )
{
	uint32_t dw_mr = p_rstc->RSTC_MR & (~(RSTC_MR_ERSTL_Msk|RSTC_MR_KEY_Msk));
	p_rstc->RSTC_MR = RSTC_MR_KEY(RSTC_KEY) | dw_mr | RSTC_MR_ERSTL(dw_length);
    return 0;
}
#endif

#ifndef SAMA5 //ERr SAMA5
void rstc_enable_user_reset( Rstc* p_rstc )
{
	uint32_t dw_mr = p_rstc->RSTC_MR & (~RSTC_MR_KEY_Msk);
	p_rstc->RSTC_MR = RSTC_MR_KEY(RSTC_KEY) | dw_mr | RSTC_MR_URSTEN;
}
void rstc_disable_user_reset( Rstc* p_rstc )
{
	uint32_t dw_mr = p_rstc->RSTC_MR & (~(RSTC_MR_URSTEN|RSTC_MR_KEY_Msk));
	p_rstc->RSTC_MR = RSTC_MR_KEY(RSTC_KEY) | dw_mr;
}
void rstc_enable_interrupt( Rstc* p_rstc )
{
	uint32_t dw_mr = p_rstc->RSTC_MR & (~RSTC_MR_KEY_Msk);
	p_rstc->RSTC_MR = RSTC_MR_KEY(RSTC_KEY) | dw_mr | RSTC_MR_URSTIEN;
}
void rstc_disable_interrupt( Rstc* p_rstc )
{
	uint32_t dw_mr = p_rstc->RSTC_MR & (~(RSTC_MR_URSTIEN|RSTC_MR_KEY_Msk));
	p_rstc->RSTC_MR = RSTC_MR_KEY(RSTC_KEY) | dw_mr;
}
#endif //ERr SAMA5


void rstc_software_reset( Rstc* p_rstc , uint32_t dw_mode )
{
	p_rstc->RSTC_CR = RSTC_CR_KEY(RSTC_KEY) | (dw_mode & RSTC_RST_ALL);
}

uint32_t rstc_read_status( Rstc* p_rstc )
{
	return p_rstc->RSTC_SR;
}

