/*
 * timer_interface.h
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_TIMER_INTERFACE_H_
#define MCAL_TIMER_INTERFACE_H_

#define TIMER0		0
#define TIMER1		1
#define TIMER2		2

void TIMERS_vInit(void);
void TIMERS_vEnableInturrupt(u8 A_u8TimerId, u8 A_u8InterruptSource);
void TIMERS_vDisableInturrupt(u8 A_u8TimerId, u8 A_u8InterruptSource);
void TIMERS_vSetBusyWait(u32 A_u32Ticks);

void TIMERS_vStartTimer(u8 A_u8TimerId);
void TIMERS_vStopTimer(u8 A_u8TimerId);
void TIMERS_vSetCallback( void (*fptr)(void));

void TIMERS_vSetPreloadValue(u8 A_u8TimerId, u16 A_u16Preload);
void TIMERS_vSetCompareMatchValue(u8 A_u8TimerId, u16 A_u16OctValue);

#endif /* MCAL_TIMER_INTERFACE_H_ */
