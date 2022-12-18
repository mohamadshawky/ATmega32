/*
 * timer_CFG.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_TIMER_CFG_H_
#define MCAL_TIMER_CFG_H_


/*
 * Options:
 * 			ENABLE
 * 			DISABLE
 * */
#define  TIMER0_ENABLE			ENABLE
#define  TIMER1_ENABLE			ENABLE

/*
 * Prescaler Options:
 *  				PS_NOCLK
 * 					PS_1
 *					PS_8
 *					PS_64
 *					PS_256
 * 					PS_1024
 */
#define  TIMER0_PRESCALER 		PS_8
#define  TIMER1_PRESCALER		PS_8

/* Preload values */
#define  TIMER0_PRELOAD			0
#define  TIMER1_PRELOAD	  		0

#endif /* MCAL_TIMER_CFG_H_ */
