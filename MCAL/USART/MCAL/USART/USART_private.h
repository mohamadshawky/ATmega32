/*
 * UART_private.h
 *
 *  Created on: Oct 7, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

/* USART I/O Data Register – UDR */
#define UDR 		 *((volatile u8*)0x2C)

/* USART Control and Status Register A – UCSRA */
#define UCSRA 		 *((volatile u8*)0x2B)
#define MPCM			0			/* Multi-processor Communication Mode */
#define U2X				1			/* Double the USART Transmission Speed */
#define PE				2			/* Parity Error */
#define DOR				3			/* Data OverRun */
#define FE				4			/* Frame Error */
#define UDRE			5			/* USART Data Register Empty */
#define TXC				6			/* USART Transmit Complete */
#define RXC				7			/* USART Receive Complete */

/* USART Control and Status Register B – UCSRB */
#define UCSRB 		 *((volatile u8*)0x2A)
#define TXB8			0			/* Transmit Data Bit 8 */
#define RXB8			1           /* Receive Data Bit 8 */
#define UCSZ2			2           /* Character Size */
#define TXEN			3           /* Transmitter Enable */
#define	RXEN			4           /* Receiver Enable */
#define UDRIE			5           /* USART Data Register Empty Interrupt Enable */
#define	TXCIE			6           /* TX Complete Interrupt Enable */
#define	RXCIE			7           /* RX Complete Interrupt Enable */

/* USART Control and Status Register C – UCSRC */
#define UCSRC 		 *((volatile u8*)0x40)
#define	UCPOL		    0			/* Clock Polarity */
#define	UCSZ0           1           /* Character Size */
#define	UCSZ1           2           /* Character Size */
#define	USBS            3           /* Parity Mode */
#define	UPM0            4           /* Parity Mode */
#define	UPM1            5           /* Parity Mode */
#define	UMSEL           6           /* USART Mode Select */
#define	URSEL           7           /* Register Select */

/* USART Baud Rate Registers – UBRRL and UBRRH */
#define UBRRL 		 *((volatile u8*)0x29)
#define UBRRH 		 *((volatile u8*)0x40)




#endif /* MCAL_USART_USART_PRIVATE_H_ */
