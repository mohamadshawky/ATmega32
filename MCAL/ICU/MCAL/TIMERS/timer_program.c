/*
 * timer_program.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */

#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "timer_interface.h"
#include "timer_private.h"
#include "timer_CFG.h"

static void(*TIMER0_OVF_Callback)(void);
static void(*TIMER0_COMP_Callback)(void);
static void(*TIMER1_OVF_Callback)(void);

void TIMERS_vInit(void){

#if TIMER0_ENABLE == ENABLE
	/* select wave generation mode as fast PWM 	*/
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	/*select compare match output mode Non-Inverted */
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
	/* set preload value = 0  */
	TCNT0 =TIMER0_PRELOAD;
	/* Disable overflow & compare match Interrupts */
	CLR_BIT(TIMSK,TOV0);
	CLR_BIT(TIMSK, OCIE0);
#endif

#if TIMER1_ENABLE == ENABLE
	/* clear all modes to capture input signal by SW */
	CLR_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);

	CLR_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1B1);
	CLR_BIT(TCCR1A,COM1B0);

	/* set prescaler /8 */
	SET_BIT(TCCR1B,CS11);

	/* set TIMER1 OV Interrupt */
	SET_BIT(TIMSK,TOIE1);

#endif
}

void TIMERS_vEnableInturrupt(u8 A_u8TimerId, u8 A_u8InterruptSource){
	switch (A_u8TimerId){
		case TIMER0:
			if (A_u8InterruptSource == TOIE0) {SET_BIT(TIMSK, TOIE0);}
			else if (A_u8InterruptSource == OCIE0) {SET_BIT(TIMSK, OCIE0);}
			else { /* Do nothing */ }
			break;
		case TIMER1:
			if (A_u8InterruptSource == TOIE1) {SET_BIT(TIMSK, TOIE1);}
			else if (A_u8InterruptSource == OCIE1B) {SET_BIT(TIMSK, OCIE1B);}
			if (A_u8InterruptSource == OCIE1A) {SET_BIT(TIMSK, OCIE1A);}
			else if (A_u8InterruptSource == TICIE1) {SET_BIT(TIMSK, TICIE1);}
			else { /* Do nothing*/ }
			break;
		case TIMER2:
			if (A_u8InterruptSource == TOIE2) {SET_BIT(TIMSK, TOIE2);}
			else if (A_u8InterruptSource == OCIE2) {SET_BIT(TIMSK, OCIE2);}
			else { /* Do nothing*/ }
			break;
	}
}

void TIMERS_vDisableInturrupt(u8 A_u8TimerId, u8 A_u8InterruptSource){
	switch (A_u8TimerId){
		case TIMER0:
			if (A_u8InterruptSource == TOIE0) {CLR_BIT(TIMSK, TOIE0);}
			else if (A_u8InterruptSource == OCIE0) {CLR_BIT(TIMSK, OCIE0);}
			else { /* Do nothing */ }
			break;
		case TIMER1:
			if (A_u8InterruptSource == TOIE1) {CLR_BIT(TIMSK, TOIE1);}
			else if (A_u8InterruptSource == OCIE1B) {CLR_BIT(TIMSK, OCIE1B);}
			if (A_u8InterruptSource == OCIE1A) {CLR_BIT(TIMSK, OCIE1A);}
			else if (A_u8InterruptSource == TICIE1) {CLR_BIT(TIMSK, TICIE1);}
			else { /* Do nothing*/ }
			break;
		case TIMER2:
			if (A_u8InterruptSource == TOIE2) {CLR_BIT(TIMSK, TOIE2);}
			else if (A_u8InterruptSource == OCIE2) {CLR_BIT(TIMSK, OCIE2);}
			else { /* Do nothing*/ }
			break;
	}
}

void TIMERS_vStartTimer(u8 A_u8TimerId){
	switch(A_u8TimerId){
		case TIMER0:
			TCNT0 = 0;
			TCCR0 = (TCCR0 & ~0b111) | (TIMER0_PRESCALER);		break;
		case TIMER1:
			TCNT1 = 0;
			TCCR1B = (TCCR1B & ~0b111) | (TIMER1_PRESCALER);	break;

		default:												break;

	}
}

void TIMERS_vStopTimer(u8 A_u8TimerId){
	switch(A_u8TimerId){
		case TIMER0:
			TCCR0 =(TCCR0 & ~0b111) | (PS_NOCLK);	break;
		case TIMER1:
			TCCR1B =(TCCR1B & ~0b111) | (PS_NOCLK);	break;
		default:									break;
	}
}

void TIMERS_vSetPreloadValue(u8 A_u8TimerId, u16 A_u16Preload){
	switch(A_u8TimerId){
		case TIMER0:
			TCNT0 =A_u16Preload;	break;
		case TIMER1:
			TCNT1 =A_u16Preload;	break;
		default:					break;
		}
}

void TIMERS_vSetCompareMatchValue(u8 A_u8TimerId, u16 A_u16OctValue){
	switch(A_u8TimerId){
		case TIMER0:
			OCR0 = A_u16OctValue;	break;
		case TIMER1:
			OCR1A = A_u16OctValue;	break;

		default:					break;
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void){
	if(TIMER0_OVF_Callback!=NULL){
		TIMER0_OVF_Callback();
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	if(TIMER0_COMP_Callback!=NULL){
		TIMER0_COMP_Callback();
	}
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void){
	if(TIMER1_OVF_Callback != NULL){
		TIMER1_OVF_Callback();
	}
}



