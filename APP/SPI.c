/*
 * main.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Mohamed
 *      Descritption: Loop back test
 */

#include "Utils/BIT_MATH.h"
#include "Utils/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/SPI/SPI_interface.h"

#define SPI_SYNC		0
#define SPI_ASYNC		1

volatile u8 c;

void SPI_BlinkLed(){
	DIO_SetPortDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	if (c == 'M'){
			DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
		}
		else{
			DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
		}
}

int main (void){

#if SPI_SYNC

	/* setting loop back mechanism */
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);	/* MOSI */
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_INPUT);	/* MISO */
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);	/* SCK */

	DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_HIGH);

	SPI_vInit();

	u8 c = 0;
	c = SPI_u8Transceive('M');

	if (c == 'M'){
		DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	}
	else{
		DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
	}

	while(1){

	}
#endif

#if SPI_ASYNC

	/* setting loop back mechanism */
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);	/* MOSI */
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_INPUT);	/* MISO */
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);	/* SCK */

	DIO_SetPortDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);

	SPI_vInit();

	SPI_vSetCallback(SPI_BlinkLed);
	MGIE_vEnable();

	c = SPI_u8Transceive();

	while (1){

	}

#endif
}

