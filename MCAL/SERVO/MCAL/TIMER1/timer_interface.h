/*
 * timer_interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_TIMER_INTERFACE_H_
#define MCAL_TIMER_INTERFACE_H_

//#define TIMER0		0
//#define TIMER1		1
//#define TIMER2		2

void TIMER1_vInit(void);

void TIMER1_vStartTimer(void);
void TIMER1_vStopTimer(u8 A_u8TimerId);
void TIMER1_vSetCallback(void (*fptr)(void));

void TIMER1_vSetPreloadValue(u16 A_u16Preload);
void TIMER1_vSetCompareMatchValue(u16 A_u16OctValue);
void TIMER1_vSetICR1(u16 A_16IcrValue);

#endif /* MCAL_TIMER_INTERFACE_H_ */
