/*
 * 	main.c
 *  Created on: Oct 7, 2022
 *      Author: Mohamed Shawky
 * 		Application description:
 * 		
 */

#include "Utils/STD_TYPES.h"
#include "Utils/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/USART/USART_interface.h"

#define USART_SYNC_APP		0
#define USART_ASYNC_APP		1

volatile char buffer[50];
volatile u8 usart_flag = 0;

void usart_recieve_cbk(u8 data){
	static u32 buffer_idx = 0;
	buffer[buffer_idx] = data;
	buffer_idx++;

	if (buffer_idx == sizeof(buffer)/sizeof(buffer[0]) - 1 ||
			buffer[buffer_idx] == '\n' ||
			buffer[buffer_idx] == '\r')
	{
		buffer[buffer_idx] = '\0';
		buffer_idx = 0;
		usart_flag = 1;
	}
	buffer_idx++;
}

int main (void){

#if USART_SYNC_APP
	USART_vInit();		/* sync approach */
	//u8 c = USART_vRecieveByte_sync();
	char arr[] = "Ahmed";
	USART_vPrintString(arr);
	while (1){
		//	USART_vTransmitByte_sync(c);
		USART_vReadString(arr, sizeof(arr)/sizeof(char));
	}
#endif

#if USART_ASYNC_APP

	USART_vInit();		/* async approach */
	USART_vSetCallback(usart_recieve_cbk);
	MGIE_vEnable();

	while (1) {
		USART_vPrintString("Mohamed");	/* output: print many times */
//		if (uart_flag == 1) {
//			USART_vPrintString(buffer);	/* output: print only once */
//			usart_flag = 0;
//		}
	}

#endif
}
