/*
 * 	main.c
 *  Created on: Oct 5, 2022
 *      Author: Mohamed Shawky
 * 		Application description: controls limited SERVO motor with PWM signal on TIMER1 (PD5)
 *
 */
#include "Utils/STD_TYPES.h"
#include "Utils/BIT_MATH.h"
#include "util/delay.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER1/timer_interface.h"

#include "HAL/SERVO/servo_interface.h"

int main (void){

/* Different angles */
	vInit_SERVO();
	vSet_SEVRO_ANGLE(0);

	while (1){
		vSet_SEVRO_ANGLE(45);
		_delay_ms(1000);
		vSet_SEVRO_ANGLE(90);
		_delay_ms(1000);
		vSet_SEVRO_ANGLE(135);
		_delay_ms(1000);
		vSet_SEVRO_ANGLE(180);
		_delay_ms(1000);
		vSet_SEVRO_ANGLE(135);
		_delay_ms(1000);
		vSet_SEVRO_ANGLE(90);
		_delay_ms(1000);
		vSet_SEVRO_ANGLE(45);
		_delay_ms(1000);
		vSet_SEVRO_ANGLE(0);
		_delay_ms(1000);
	}

//	DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);
//
//	TIMER1_vInit();
//	TIMERS_vSetICR1(20000);
//
//	u16 Local_u16Iterator = 0;
//
//	while (1){
//		for (Local_u16Iterator = 750; Local_u16Iterator < 2500; Local_u16Iterator++){
//			TIMER1_vSetCompareMatchValue(Local_u16Iterator);
//			_delay_ms(10);
//		}
//		for (Local_u16Iterator = 750; Local_u16Iterator < 2500; Local_u16Iterator++){
//			TIMER1_vSetCompareMatchValue(2500-Local_u16Iterator);
//			_delay_ms(10);
//		}
//	}

}
