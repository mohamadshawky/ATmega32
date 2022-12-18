/*
 * ICU_program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Mohamed
 */

#include "ICU_interface.h"
#include "ICU_private.h"
#include "ICU_CFG.h"

static void (*TIMER1_ICU_Callback)(void);

void TIMERS_vSetICR1(u16 A_16IcrValue){
	ICR1 = A_16IcrValue;
}

u16  TIMERS_u16GetICR1(void)
{
	return ICR1;
}

void TIMERS_vSetICUSenseCtrl(u8 A_u8SenseCtrl){
	switch(A_u8SenseCtrl){
		case ICU_RISING:
			SET_BIT(TCCR1B, 6); // ICES1
			break;

		case ICU_FALLING:
			CLR_BIT(TCCR1B, 6); // ICES1
			break;
		}
}

void TIMERS_vSetCallback(void (*fptr)(void)){
	TIMER1_ICU_Callback = fptr ;
}

u16 TIMERS_u16GETELAPSEDTIME(void){
	u16 L_u16TimerValue=0;
	L_u16TimerValue = TCNT1;
	return L_u16TimerValue;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void){
	TIMER1_ICU_Callback();
}
