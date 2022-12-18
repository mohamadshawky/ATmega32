/*
 * main.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Mohamed
 */

#include "Utils/BIT_MATH.h"
#include "Utils/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"

#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/GIE/GIE_interface.h"

void toggle(){
	DIO_TogPin(DIO_PORTA, DIO_PIN0);
}

int main(){

	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0, DIO_OUTPUT);

	MEXTI_vRegisterCallback(_EXTI_0, toggle);

	MEXTI_vInit();
	MGIE_vEnable();

	while (1){

	}

	return 0;
}
