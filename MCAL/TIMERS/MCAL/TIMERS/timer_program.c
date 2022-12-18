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

#define OV_MODE_CFG		0
#define CTC_MODE_CFG 	0
#define PWM_MODE_CFG	0

static void (*TIMER0_OVF_Callback)(void);
static void (*TIMER0_CTC_Callback)(void);


void TIMERS_vInit(void){

#if TIMER0 == ENABLE
	/*1. Select wave generation mode*/
	//CLR_BIT(TCCR0, WGM00);			/* OV Mode*/
	//CLR_BIT(TCCR0, WGM01);

	//CLR_BIT(TCCR0, WGM00);			/* CTC Mode*/
	//SET_BIT(TCCR0, WGM01);

	SET_BIT(TCCR0, WGM00);				/* PWM Mode*/
	SET_BIT(TCCR0, WGM01);

	/*2. Output compare mode*/
	CLR_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);

	CLR_BIT(TCCR0, COM00);			/* PWM Mode */
	SET_BIT(TCCR0, COM01);

	/*3. Preload*/
	TCNT0 = TIMER0_PRELOAD;		/* @ OV, CTC, PWM Mode */

	/*4. Interrupt EN\DIS*/
	//SET_BIT(TIMSK, TOV0);		/* OV Mode */
	SET_BIT(TIMSK, OCIE0);
#endif

	/* Timer mode */
	SET_BIT(TCCR1B, 4);		//WGM13
	SET_BIT(TCCR1B, 3);		//WGM12
	SET_BIT(TCCR1A, 1);		//WGM11
	CLR_BIT(TCCR1A, 0);		//WGM10

	/* fast PWM Non-inverting */
	SET_BIT(TCCR1A, 7);		//COM1A1
	CLR_BIT(TCCR1A, 6);		//COM1A0

	/* ICU */
	TCCR0 = 0b01101010;
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000010;
	TIMSK = 0b00000100;

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

void TIMERS_vSetBusyWait(/* TimerId, */u32 A_u32Ticks){

}


void TIMERS_vStartTimer(u8 A_u8TimerId){
	switch (A_u8TimerId){
	case TIMER0:
		TCNT0	= 0 ;
		TCCR0 = ((TCCR0 & ~(0b111)) | TIMER0_PRESCALER);
		break;

	case TIMER1:			/* naming A or B is or none up to you */
		TCNT1	= 0 ;		/*ICU*/
		TCCR1B = ((TCCR1B & ~(0b111)) | TIMER1_PRESCALER);
		break;
	}
}

void TIMERS_vStopTimer(u8 A_u8TimerId){
	switch (A_u8TimerId){
	case TIMER0:
		TCCR0 = ((TCCR0 & ~(0b111)) | PS_NOCLK);
		break;

	case TIMER1:
		TCCR1B = ((TCCR1B & ~(0b111)) | PS_NOCLK);
		break;
	}
}

void TIMERS_vSetCallback(/* TimerId, */ void (*fptr)(void)){
	//TIMER0_OVF_Callback = fptr;
	TIMER0_CTC_Callback=  fptr;
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void){
	if (TIMER0_OVF_Callback != NULL)
		TIMER0_OVF_Callback();
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	if (TIMER0_CTC_Callback != NULL)
		TIMER0_CTC_Callback();
}


void TIMERS_vSetPreloadValue(u8 A_u8TimerId, u16 A_u16Preload){			/* OV Mode */
	switch (A_u8TimerId){
		case TIMER0:
			TCNT0 = A_u16Preload;
			break;

		case TIMER1:
			TCNT1 = A_u16Preload;
			break;
	}
}

void TIMERS_vSetCompareMatchValue(u8 A_u8TimerId, u16 A_u16OctValue){	/* CTC Mode*/
	switch (A_u8TimerId){
		case TIMER0:
			OCR0 = A_u16OctValue;
			break;

		case TIMER1:
			OCR1A = A_u16OctValue;
			break;
	}

}




