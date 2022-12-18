/*
 * main.c
 *
 *  Created on: Sep 2, 2022
 *      Author: Mohamed
 */
#include "Utils/STD_TYPES.h"
#include "Utils/BIT_MATH.h"

#include <avr/io.h>
#include <util/delay.h>

#define SNAKE  		0
#define PINGPONG 	0
#define DIPSWITCH 	0

int main(void)
{
#if PINGPONG

	DDRA = 0xFF;
	DDRB = 0x00;
	PORTB =0xFF; 	//enable the internal pull up resistors

	while(1)
	{		//run while power on, and in this block only in flash
		for (int i = 7; i>= 0; i--){
			SET_BIT(PORTA, i);
			_delay_ms(100);
		}
		for (int i = 7; i >= 0; i--){
			CLR_BIT(PORTA, i);
			_delay_ms(100);
		}
	}

#endif

#if DIPSWITCH

	if(GET_BIT(PINB,0)==0) // switch is closed
	{SET_BIT(PORTC,0);}
	else{CLR_BIT(PORTC,0);}

#endif

#if SNAKE

	DDRA = 0xFF;
	DDRB = 0x00;
	PORTB =0xFF; 	// enable the internal pull up resistors

	for(int x=0; x<8; x++){
		SET_BIT(PORTA,x);
		_delay_ms(200);
	}

	for(int x=0 ;x<8;x++){
		CLR_BIT(PORTA,x);
		_delay_ms(200);
	}

#endif
}
