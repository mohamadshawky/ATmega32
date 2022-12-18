/*
 * timer_CFG.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_TIMER_CFG_H_
#define MCAL_TIMER_CFG_H_
/*
 * Prescaler Options for TIMER0:
 *  				PS_NOCLK
 * 					PS_1
 *					PS_8
 *					PS_64
 *					PS_256
 * 					PS_1024
 */
#define TIMER0_PRESCALER	PS_8
#define TIMER0_PRELOAD		0
#define TIMER0_MODE			FAST_PWM
#define TIMER0_COM_MODE		NON_INVERTING

/*
 * Prescaler Options for TIMER1:
 *  				PS_NOCLK
 * 					PS_1
 *					PS_8
 *					PS_64
 *					PS_256
 * 					PS_1024
 */
#define TIMER1_PRESCALER	PS_256

#endif /* MCAL_TIMER_CFG_H_ */
