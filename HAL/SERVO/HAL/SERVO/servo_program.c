/*
 * servo_program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Mohamed
 */

#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER1/timer_interface.h"

#include "../../HAL/SERVO/servo_interface.h"

void vInit_SERVO(void){		/* PIN Dir, TIMER_init(), setICR1(), TIMERS_vStartTimer()*/
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN5, DIO_OUTPUT);
	TIMER1_vInit();
	TIMER1_vSetICR1(20000);
	TIMER1_vStartTimer();
}

void vSet_SEVRO_ANGLE(u16 A_u8Angle){
	u16 Local_CompareVal = 1000 + A_u8Angle * (1000.0f/180.0f);
	TIMER1_vSetCompareMatchValue(Local_CompareVal);
}
