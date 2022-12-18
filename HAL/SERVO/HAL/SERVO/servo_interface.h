/*
 * servo_interface.h
 *
 *  Created on: Sep 28, 2022
 *      Author: Mohamed
 */

#ifndef HAL_SERVO_INTERFACE_H_
#define HAL_SERVO_INTERFACE_H_

void vInit_SERVO(void);		/* PIN Dir, TIMER_init(), setICR1(), TIMERS_vStartTimer()*/
void vSet_SEVRO_ANGLE(u16 A_u8Angle);

#endif /* HAL_SERVO_INTERFACE_H_ */
