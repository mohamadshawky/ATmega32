/*
 * UART_interface.h
 *
 *  Created on: Oct 7, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

void USART_vInit();

/* Sync functions */
void USART_vTransmitByte_sync(u8 A_u8Byte);
u8	 USART_vRecieveByte_sync(void);

void USART_vPrintString(char str[]);
void USART_vReadString(char str[], u32 size);	/* size of read data */
void USART_vSetBaudRate(u32 A_32BaudRate);

/* Async functions */
void USART_vTransmitByte_async(u8 data);
u8 USART_u8RecieveByte_async(void);


#endif /* MCAL_USART_USART_INTERFACE_H_ */
