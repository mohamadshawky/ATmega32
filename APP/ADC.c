/*
 * main.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Mohamed
 */

#include "Utils/BIT_MATH.h"
#include "Utils/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/ADC/ADC_interface.h"


int main(){

	u8 Local_u8ADCReading;

	DIO_SetPortDirection(DIO_PORTA, DIO_INPUT);
	DIO_SetPortDirection(DIO_PORTB, DIO_OUTPUT);

	MADC_vInit();

	while(1){

		Local_u8ADCReading= MADC_u16ReadDigitalValue_synch(0);
		DIO_SetPortValue(DIO_PORTB, Local_u8ADCReading);

	}
}
