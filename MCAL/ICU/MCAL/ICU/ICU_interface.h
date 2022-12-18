/*
 * ICU_interface.h
 *
 *  Created on: Oct 1, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_ICU_ICU_INTERFACE_H_
#define MCAL_ICU_ICU_INTERFACE_H_

#include "../../Utils/BIT_MATH.h"
#include "../../Utils/STD_TYPES.h"

#define ICU_RISING  		 1
#define ICU_FALLING			 2

void TIMERS_vSetICR1(u16 A_16IcrValue);
u16  TIMERS_u16GetICR1(void);
void TIMERS_vSetICUSenseCtrl(u8 A_u8SenseCtrl);
void TIMERS_vSetCallback(void (*fptr)(void));

/* This function to read counts at certain sense control (ICU by S/W) */
u16  TIMERS_u16GETELAPSEDTIME(void);

#endif /* MCAL_ICU_ICU_INTERFACE_H_ */
