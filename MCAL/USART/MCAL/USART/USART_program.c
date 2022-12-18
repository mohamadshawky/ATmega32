/*
 * USART_program.c
 *
 *  Created on: Oct 7, 2022
 *      Author: Mohamed
 */
#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include "USART_private.h"
#include "USART_interface.h"
#include "USART_CFG.h"

static void (*GS_USART_RXC_Callback)(u8 data);
//static void (*UART_DR_EMPTY_callback)    (void);
//static void (*UART_TX_COMPLETE_callback) (void);
/* Async Communcation (No shared clock) */

void USART_vInit(){

	/* Initialization routine:
	 * 1. Interrupts enable
	 * a. Rx interrupt enable
	 * b. Tx interrupt enable
	 * c. UDRE interrupt enable
	 * 2. character size
	 * 3. USART mode (synch/as)
	 * 4. parity mode
	 * 5. stop bit
	 * */

#if SYNC_MODE
	u8 ucsrc_setting = 0;

	/* Tx enable - Rx enable */
	SET_BIT(ucsra_setting, TXEN);
	SET_BIT(ucsra_setting, RXEN);

	/* set chaharcter size to 8 bits */
	SET_BIT(ucsra_setting, UCSZ0);
	SET_BIT(ucsra_setting, UCSZ1);
	/* selects to write in UCSRC */
	SET_BIT(ucsra_setting, URSEL);

	UCSRC = ucsra_setting;

	UBRRL = 51;

#endif

#if RX_ASYNC_MODE

	UCSRB = 0b10011000; 	/* enable RX complete interrupt */
	UCSRC = 0b10000110;	 	/* enables async approach */
	UBRRL = 51;				/* set baud rate @ sunc com mode */

#endif
}

void USART_vTransmitByte_sync(u8 A_u8Byte){
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
		;
	/* Put data into buffer, sends the data */
	UDR = A_u8Byte;
}

u8	 USART_vRecieveByte_sync(void){
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
		;
	/* Get and return received data from buffer */
	return UDR;
}


void USART_vPrintString(char str[]){
	while (*str != '\0'){
		USART_vTransmitByte_sync(*str);
		str++;
	}
}

void USART_vReadString(char str[], u32 size){
	for (u32 i = 0; i < size-1; i++){
		str[i] = USART_vRecieveByte_sync();
		if (str[i] == '\n' ||
				str[i] == '\r'){	 // some systems use '\r' instead of '\n'
			str[i] = '\0';
			break;
		}
		str[size-1] = '\0';
	}
}

void USART_vTransmitByte_async(u8 data){
	// TO DO
}

u8 USART_u8RecieveByte_async(void){
	return UDR;
}


void USART_vSetBaudRate(u32 A_32BaudRate){
	// TO DO
}

void USART_vSetCallback(void(*fptr)(u8)){
	GS_USART_RXC_Callback = fptr;
}

void __vector_13(void) __attribute__ ((signal));
void __vector_13(void){
	if (GS_USART_RXC_Callback != NULL){
		GS_USART_RXC_Callback(UDR);
	}
}


//void __vector_14(void) __attribute((signal));
//void __vector_14(void)
//{
//    if (UART_DR_EMPTY_callback != NULL) {
//        UART_DR_EMPTY_callback();
//    }
//}
//
//void __vector_15(void) __attribute((signal));
//void __vector_15(void)
//{
//    if (UART_TX_COMPLETE_callback != NULL) {
//        UART_TX_COMPLETE_callback();
//    }
//}
