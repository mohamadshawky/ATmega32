/*
 * main.c
 *
 *  Created on: Sep 17, 2022
 *      Author: Mohamed
 */

#include "Utils/STD_TYPES.h"
#include "Utils/BIT_MATH.h"

#include <util/delay.h>

#include "MCAL/DIO/DIO_interface.h"

#define DC_MOTOR_Transisitor	1

int main(){

#if DC_MOTOR_Transisitor

	DIO_SetPinDirection(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);

	while (1){
		DIO_SetPinValue(DIO_PORTB, DIO_PIN0, DIO_HIGH);
		_delay_ms(1000);
		DIO_SetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
		_delay_ms(1000);
	 }
#endif

}


