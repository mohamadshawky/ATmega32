/*
 * timer_private.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_TIMER_PRIVATE_H_
#define MCAL_TIMER_PRIVATE_H_

//#define ENABLE 			1
//#define DISABLE			0

#define	TIMERS_PRESCALLER_MASK		0b11111000

/* PRESCALER */
#define PS_NOCLK		0
#define PS_1			1
#define PS_8			2
#define PS_64			3
#define PS_256			4
#define PS_1024			5

/* TIMER1 Registers */
#define TCCR1A	*((volatile u8*)(0x4F))
#define WGM10			0
#define WGM11			1
#define FOC1B			2
#define FOC1A			3
#define COM1B0			4
#define COM1B1			5
#define COM1A0			6
#define COM1A1			7

#define TCCR1B	*((volatile u8*)(0x4E))
#define CS10			0
#define	CS11			1
#define	CS12			2
#define	WGM12			3
#define	WGM13			4
#define	ICES1			6
#define ICNC1			7
#define TCNT1	*((volatile u16*)(0x4C))
#define OCR1A	*((volatile u16*)(0x4A))
#define OCR1B	*((volatile u16*)(0x48))
#define ICR1	*((volatile u16*)(0x46))

/* Timers Registers */
#define TIMSK	*((volatile u16*)(0x59))
#define TOIE0			0
#define OCIE0			1
#define TOIE1			2
#define OCIE1B			3
#define OCIE1A			4
#define TICIE1			5
#define TOIE2			6
#define OCIE2			7

#define TIFR	*((volatile u16*)(0x58))
#define TOV0			0
#define OCF0			1
#define TOV1			2
#define OCF1B			3
#define OCF1A			4
#define ICF1			5
#define TOV2			6
#define OCF2			7

#endif /* MCAL_TIMER_PRIVATE_H_ */
