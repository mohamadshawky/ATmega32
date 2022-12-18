/*
 * main.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Mohamed
 */
#include "Utils/STD_TYPES.h"
#include "Utils/BIT_MATH.h"
#include "Util/delay.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/WDT/WDT_interface.h"

int main(void){
	/* TOGGLE Multiple times */
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);

	WDT_vEnable(WDT_PS_sel);
	DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	_delay_ms(500);
	DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
	_delay_ms(500);		// In this case WDT does not encounter a new period to estimate or disabled so RESET.

//	/* TOGGLE ONLY ONCE */
//	DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
//
//	WDT_vEnable(WDT_PS_sel);
//	DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
//	_delay_ms(500);
//	DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
//	WDT_vDisable();			// In this case WDT encounters WDT_vDisable() so stopped to RESET

	while(1){

	}

}
