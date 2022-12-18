/*
 * KPD_program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Mohamed
 */

#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include "util/delay.h"

#include <avr/io.h>
//#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_CFG.h"



/**
 * INPUT: +   +   +    +
 * r0	  1---5---9 ---13  -
 * r1 	  2---6---10---14  -
 * r2 	  3---7---11---15  -
 * r3 	  4---8---12---16  -
 * OUTPUT:c0  c1  c2   c3
 */

void HKPD_vInit (void)
{
	//DIO_vWritePortDirection(DIO_PORTC,0x0f);
	DDRC = 0x0F;
	//DIO_vWritePortVAlue(DIO_PORTC,0xff);
	PORTC = 0xFF;
}

u8 HKPD_u8GetPressedKey(void)
{
	u8 pressed_key=0;
	u8 col;
	u8 row;
	for(col = 0; col < COLS_N; col++)
	{
		//DIO_vWritePinVAlue(DIO_PORTC,col,DIO_PIN_LOW);
		CLR_BIT(PORTC,col);

		for(row=0;row<ROWS_N;row++)
		{
			if(GET_BIT(PINC,(row+4))/*DIO_u8ReadPinVAlue(DIO_PORTC,row+4)*/==0)
			{
				pressed_key = (row + (col*4) + 1);
			}
			while(GET_BIT(PINC,(row+4))/*DIO_u8ReadPinVAlue(DIO_PORTC,row+4)*/==0){}
			_delay_ms(5);
		}
		//DIO_vWritePinVAlue(DIO_PORTC,col,DIO_PIN_HIGH);
		SET_BIT(PORTC,col);
	}
	return pressed_key;
}


