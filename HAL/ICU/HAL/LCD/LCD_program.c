/*
 * LCD_program.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Mohamed
 */
#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include <util/delay.h>
#include <avr/io.h>

#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_CFG.h"


void HLCD_vSendChar(u8 A_u8character){

	SET_BIT(PORTD, PIN0);	// display data

	CLR_BIT(PORTD, PIN1);	// write operation

	PORTA = A_u8character;	// put data on LCD pins

	/* pulse on Enable */
	SET_BIT(PORTD, PIN2);
	_delay_ms(1);
	CLR_BIT(PORTD, PIN2);
	_delay_ms(1);
}

void HLCD_vSendCMD(char A_u8cmd){
	/* select RS -> 0 */
	CLR_BIT(PORTD, PIN0);	// instruction code
	/* select RW -> 0 */
	CLR_BIT(PORTD, PIN1);	// write operation
	/* Put data on LCD pins */
	PORTA = A_u8cmd;		 //Put data on LCD pins
	/* pulse on Enable */
	SET_BIT(PORTD, PIN2);
	_delay_ms(1);
	CLR_BIT(PORTD, PIN2);
	_delay_ms(1);
}

void HLCD_vInit(void){

	/* Set The Data Port To Be Output */
	DDRA = 0xff ;

	/* Set The Control Pins To Be Output */
	SET_BIT(DDRD, PIN0);
	SET_BIT(DDRD, PIN1);
	SET_BIT(DDRD, PIN2);

	/* initialization configuration sequence */
	_delay_ms(50);

	HLCD_vSendCMD(0b00111000);	 // font 5*7; 2 line display
	_delay_ms(1) ;
	HLCD_vSendCMD(0b00001100);	 // display ON
	_delay_ms(1) ;
	HLCD_vSendCMD(0b00000001);
	_delay_ms(2) ;
	HLCD_vSendCMD(0b00000110); 	 // increment mode
	_delay_ms(1) ;
}

void HLCD_vPrintString(char* A_pu8str){
	//for (u8 i = 0; str[i] != '\0'; i++){	//length of integer is larger than ram
	//HLCD_SendChar(str[i]);
	//}
	//another approach
	while( *A_pu8str != '\0'){		//if size of ram is large so segmentation fault
		HLCD_vSendChar(*A_pu8str);
		A_pu8str++;
	}
}

void HLCD_vPrintNumber(s32 A_s32num){
	s32 number = A_s32num ;
	u32 reversed_num = 0, digit = 0;
	if (number < 0){
		number *= -1;
		HLCD_vSendChar('-');
	}
	if(A_s32num%10==0)
		number += 1;

	while(number != 0){
		digit = number%10;
		reversed_num = (reversed_num*10) + digit;
		number /= 10;}

	while(reversed_num != 0){
		if( (reversed_num == 1) && (A_s32num % 10 == 0) )
			reversed_num =0;
		HLCD_vSendChar((reversed_num%10)+'0');
		reversed_num /= 10;
	}
}

void HLCD_vDisplayCustomCharacter(u8 A_u8ID){
	if (A_u8ID < 8){
		HLCD_vSendChar(A_u8ID);
	}

}

void HLCD_vSaveCustomCharacter(u8 A_pu8Arr[], u8 A_u8CharID){

	HLCD_vSendCMD(GCRAM_ADDRESS + (8 * A_u8CharID));

	if (A_u8CharID < 8){
		for (u32 i = 0; i<8; i++){
			HLCD_vSendChar(A_pu8Arr[i]);
		}
		HLCD_vSendCMD(DDRAM_ADDRESS);
	}
}

void HLCD_vClear(void){
	HLCD_vSendCMD(lcd_Clear);
}

void HLCD_vSetCursorPos(u8 A_u8LinePos, u8 A_u8LineNumber){
	if (A_u8LinePos >= 0 && A_u8LinePos <= 15){
		switch(A_u8LineNumber){
		case 0:
			HLCD_vSendCMD(lcd_SetCursor + 0 + A_u8LinePos);				//0-15
			break;
		case 1:
			HLCD_vSendCMD(lcd_SetCursor + 0x40 + A_u8LinePos);			//64 - 103
			break;
		default:
			break;
		}
	}
	HLCD_vSendCMD(A_u8LinePos * A_u8LineNumber);
}
