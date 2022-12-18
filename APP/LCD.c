/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: Mohamed Shawky
 */
#include "Utils/BIT_MATH.h"
#include "Utils/STD_TYPES.h"
#include "util/delay.h"

#include "HAL/LCD/LCD_interface.h"
#include "MCAL/DIO/DIO_interface.h"

int main (){

	HLCD_vInit();
//	HLCD_vSendChar('M');
//	HLCD_vPrintNumber(-122);
//	HLCD_vPrintString("OFF");
//
	u8 CustomChar[] = {	0B00000,
			0B01010,
			0B11111,
			0B11111,
			0B01110,
			0B00100,
			0B00000,
			0B00000};

	u8 M[] = {
			  0B00000,
			  0B00000,
			  0B00111,
			  0B11101,
			  0B00111,
			  0B00000,
			  0B00000,
			  0B00000
	};
	u8 H[] = {
			  0B00000,
			  0B00000,
			  0B00111,
			  0B00001,
			  0B11111,
			  0B00000,
			  0B00000,
			  0B00000
	};

	u8 D[]={
			 0B00000,
			 0B00000,
			 0B00010,
			 0B00010,
			 0B01110,
			 0B00000,
			 0B00000,
			 0B00000
	};

	HLCD_vSaveCustomCharacter(CustomChar,0);
	HLCD_vSaveCustomCharacter(M,1);
	HLCD_vSaveCustomCharacter(H,2);
	HLCD_vSaveCustomCharacter(D,3);

	//HLCD_vDisplayCustomCharacter(0);
	u8 x = 0;

	while (1){
		for(u8 y=0; y<20; y++){
			HLCD_vSetCursorPos(y, (x++) % 2);		// pos, line
			HLCD_vDisplayCustomCharacter(3);
			HLCD_vDisplayCustomCharacter(1);
			HLCD_vDisplayCustomCharacter(2);
			HLCD_vDisplayCustomCharacter(1);
			_delay_ms(500);
			HLCD_vClear();
		}
	}
}

