/*
 * timer_program.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */
#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "timer_interface.h"
#include "timer_private.h"
#include "timer_CFG.h"

void TIMER1_vInit(void){
	/* Fast PWM Non-inverting */
	SET_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);

	/* Timer mode fast PWM */
	SET_BIT(TCCR1B, WGM13);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);

	OCR1A = 0;	/* reset compare match value */

	/* Setting Prescaler */
	TCCR1B &= TIMERS_PRESCALLER_MASK;
	TCCR1B |= TIMER1_PRESCALER;
}

void TIMER1_vStartTimer(void){
	TCNT1 = 0 ;
	TCCR1B = ((TCCR1B & ~(0b111)) | TIMER1_PRESCALER);
}

//void TIMER1_vStopTimer(u8 A_u8TimerId){
//	TCCR1B = ((TCCR1B & ~(0b111)) | PS_NOCLK);
//}

//void TIMER1_vSetPreloadValue(u16 A_u16Preload){
//	TCNT1 = A_u16Preload;
//}

void TIMER1_vSetCompareMatchValue(u16 A_u16OctValue){
	OCR1A = A_u16OctValue;
}

void TIMER1_vSetICR1(u16 A_16TopValue){
	ICR1 = A_16TopValue;
}



