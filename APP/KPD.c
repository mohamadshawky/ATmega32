/*
 * main.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Mohamed
 */

#include "Utils/STD_TYPES.h"
#include "Utils/BIT_MATH.h"

#include "avr/io.h"
#include <util/delay.h>

#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/KPD/KPD_interface.h"

#define DEBOUNCING_BUSY_WAIT 0
#define DELAY_LOOP    		 0
#define KPD_LCD_COUNT 		 0
#define KPD_LCD_NUM			 1

int main(){

	/* KPD CFG */

	//	SET_BIT(DDRA,1);			// pin 1 output
	//	CLR_BIT(DDRA,0);			// pin 0 input
	//	SET_BIT(PORTA,0);			// activate pull up

#if DEBOUNCING_BUSY_WAIT

	while (1){
		if (GET_BIT(PINA,0) == 0){
			_delay_ms(150);
			if (GET_BIT(PINA,0) == 0){
				TOG_BIT(PORTA,1);
			}
		}
	}

#endif

#if DELAY_LOOP

	while (1){
		if (GET_BIT(PINA,0) == 0){
			while (GET_BIT(PINA,0) == 0);
			TOG_BIT(PORTA,1);
		}
	}

#endif

#if KPD_LCD_COUNT

	HLCD_vInit();
	u8 count = 0;
	while (1){
		if (GET_BIT(PINA,0) == 0){
			while (GET_BIT(PINA,0) == 0);
			count ++;
			HLCD_vPrintNumber(count);
		}
	}

#endif

#if KPD_LCD_NUM

	HLCD_vInit();
	HKPD_vInit();
	u8 value;
	value = HKPD_u8GetPressedKey();
	while (1){
		if(value != -1)
			HLCD_vPrintNumber(value);
	}
#endif

}
