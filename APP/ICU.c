/*
 * main.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Mohamed
 */

#include "Utils/BIT_MATH.h"
#include "Utils/STD_TYPES.h"
#include "util/delay.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/TIMERS/timer_interface.h"
#include "MCAL/ICU/ICU_interface.h"
#include "HAL/LCD/LCD_interface.h"

/* Shared global variables between ISR and App to implement ICU using S/W */
volatile u16 Tper = 0;
volatile u16 Ton = 0, T = 0;
volatile u8 flag = 0;7

/* ICU using S/W */
void _ICU_(void){
	static u32 counter =0 ;
	counter++;

	if(counter == 1){
		TIMERS_vStartTimer(TIMER1);					/* Initialize Timer: TCNT = 0, set Prescaler */
		MEXTI_vSetSenseCtrl(_EXTI_0,_RISING_EDGE_);	/* Position (1): Set sense control rising edge */

	}else if (counter == 2){
		Tper = TIMERS_u16GETELAPSEDTIME();			 /* Position (2): Get number of counts in period time*/
		MEXTI_vSetSenseCtrl(_EXTI_0,_FALLING_EDGE_); /* Set sense control rising edge */

	}else if (counter == 3){
		T=TIMERS_u16GETELAPSEDTIME();
		Ton=T-Tper;									 /* Position (3): Get Ton */
		flag = 1;
		counter = 0;
		MEXTI_vDisableInterrupt(_EXTI_0);
		TIMERS_vStopTimer(TIMER1);
	}
}

/* ICU using H/W */
void ICU(void){
	static u8 counter = 0;
	counter++;
	switch(counter){
		case 1:
			TIMERS_vStartTimer(TIMER1);
			TIMERS_vSetICUSenseCtrl(ICU_RISING);
			break;

		case 2:
			Tper = TIMERS_u16GetICR1();
			TIMERS_vSetICUSenseCtrl(ICU_FALLING);
			break;

		case 3:
			Ton  = TIMERS_u16GetICR1() - Tper ;
			TIMERS_vDisableInturrupt(TIMER1,_EXTI_0);
			TIMERS_vStopTimer(TIMER1);
			counter = 0;
			flag = 1 ;
			break;

		default:
			break;
	}
}

int main(void){

	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);	/* PB3 output regarding EXTI0 signal */

	HLCD_vInit();
	HLCD_vClear();

	MEXTI_vRegisterCallback(_EXTI_0, _ICU_);
	MEXTI_vInit();

	TIMERS_vInit();

	TIMERS_vStartTimer(TIMER0);
	TIMERS_vSetCompareMatchValue(TIMER0, 64); 	/* for duty cycle 25% */

	MGIE_vEnable();


	while(1){
		if(flag == 1){
			HLCD_vSetCursorPos(0, 0);
			HLCD_vPrintString("ton = 0");
			HLCD_vSetCursorPos(5, 0);
			HLCD_vPrintNumber(Ton);
			HLCD_vSetCursorPos(0, 1);
			HLCD_vPrintString("tper = 0");
			HLCD_vSetCursorPos(5,1);
			HLCD_vPrintNumber(Tper);
			flag = 0;
			//MEXTI_vSetSenseCtrl(EXTI_0,rising_edge);
			MEXTI_vEnableInterrupt(_EXTI_0);
		}
	}

}

