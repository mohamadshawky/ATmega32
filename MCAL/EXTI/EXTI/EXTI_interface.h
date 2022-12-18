/*
 * EXTI_interface.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Mohamed Shawky
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

typedef enum{
	_EXTI_0 = 0U ,
	_EXTI_1      ,
	_EXTI_2      ,
}EXTIx_e;

#define _FALLING_EDGE_			0b10U
#define _RISING_EDGE_			0b11U
#define _LOW_LEVEL_				0b00U
#define _ANY_LOGICAL_CHANGE		0b01U

#define ENABLE 					1U
#define DISABLE					0U

void MEXTI_vInit(void);
void MEXTI_vSetSenseCtrl(u8 A_u8ExtIPin, u8 A_u8SenseCtrl);
void MEXTI_vEnableInterrupt(EXTIx_e A_u8ExtIPin);
void MEXTI_vDisableInterrupt(u8 A_u8ExtIPin);
void MEXTI_vRegisterCallback(u8 A_u8ExtIPin, void (*fptr) (void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
