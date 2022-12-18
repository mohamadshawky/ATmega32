/*
 * main.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */
#include "Utils/STD_TYPES.h"
#include "Utils/BIT_MATH.h"
#include "Util/delay.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/TIMERS/timer_interface.h"

#define OV_MODE		0
#define CTC_MODE	0
#define FADE		0
#define SERVO		0

/* if main.h is exists so place it */
volatile u16 OnTime = 0;		// counts
volatile u16 PeriodicTime = 0;
volatile u8 CycleFlag =0;

#if OV_MODE
void Led_toggle(){
	static u32 counter = 0;
	counter ++;
	if (counter == 1954){
		counter = 0;
		TIMERS_vSetPreloadValue(224);		// error of pre-load before counting /* not accurate time */
		DIO_TogPin(DIO_PORTA, DIO_PIN0);
	}
}
#endif

#if CTC_MODE

void Led_toggle(){
	static u32 counter = 0;
	counter ++;
	if (counter == 4000){
		counter = 0;
		DIO_TogPin(DIO_PORTA, DIO_PIN0);
	}
}

#endif

int main (){

	//DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);	/* TIMER0: OV Mode */
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);	/* TIMER0: CTC Mode */
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);	/* TIMER1: fast PWM */

	TIMERS_vInit();
	MEXTI_vInit();

	//	TIMERS_vSetCallback(Led_toggle);
	//MGIE_vEnable();

	//TIMER_vSetCompareMatchValue(250);			/* CTC Mode */

	//TIMERS0_vSetICR1(624);					/* TIMER1 fast PWM */
	//TIMERS_vStartTimer(TIMER1);

	/* PWM Test */
	TIMERS_vStartTimer(TIMER0);
	TIMER_vSetCompareMatchValue(64);

	while (1){
#if FADE
		//fade in
		for (u16 i = 0; i < 255; i++ /*i+=5*/){		//iterator increase	to notice speed change
			TIMER_vSetCompareMatchValue(i);
			_delay_ms(4);							//delay increase
		}
		// fade out
		for (u16 i = 0; i < 255; i++){				//255 = 1/4 second
			TIMER_vSetCompareMatchValue(255-i);
			_delay_ms(4);							//255*4 = 1 second
		}
#endif

#if SERVO
			for (u16 i = 32; i < 64; i++ /*i+=5*/){
				TIMER_vSetCompareMatchValue(TIMER1, i);
				_delay_ms(10);
			}
			for (u16 i = 64; i < 32; i--){		// Note: Unsigned with --
				TIMER_vSetCompareMatchValue(TIMER1, i);
				_delay_ms(10);
			}
#endif


	}


}
