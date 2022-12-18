/*
 * ICU_private.h
 *
 *  Created on: Oct 1, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_ICU_ICU_PRIVATE_H_
#define MCAL_ICU_ICU_PRIVATE_H_

/* PRESCALER */
#define PS_NOCLK		0
#define PS_1			1
#define PS_8			2
#define PS_64			3
#define PS_256			4
#define PS_1024			5

#define WGM11			1
#define WGM10			0
#define WGM13			4
#define WGM12			3
#define COM1A1			7
#define COM1A0			6
#define COM1B1			5
#define COM1B0			4

#define TCNT0 	*((volatile u8*)(0x52))
#define TCCR0 	*((volatile u8*)(0x53))
#define OCR0 	*((volatile u8*)(0x5C))
#define TIMSK 	*((volatile u8*)(0x59))
#define TIFR    *((volatile u8*)(0x58))
#define TCCR1A 	*((volatile u8*)(0x4F))
#define TCCR1B	*((volatile u8*)(0x4E))
#define TCNT1 	*((volatile u16*)(0x4C))
#define OCR1A 	*((volatile u16*)(0x4A))
#define OCR1B 	*((volatile u16*)(0x48))
#define ICR1 	*((volatile u16*)(0x46))

#endif /* MCAL_ICU_ICU_PRIVATE_H_ */
