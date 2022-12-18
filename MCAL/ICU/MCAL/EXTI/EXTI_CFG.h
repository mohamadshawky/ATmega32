/*
 * EXTI_CFG.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Mohamed Shawky
 */

#ifndef MCAL_EXTI_EXTI_CFG_H_
#define MCAL_EXTI_EXTI_CFG_H_

/*
 * H/W Schematic:
 * 					INT_TYPE	PIN_NUM		Capabilities
 * 					INT_0:		PD2			Edge (falling - rising) - Low_level
 * 					INT_1:   	PD3			Edge (falling - rising) - Low_level
 * 					INT_2:   	PB2			Edge (falling - rising) only
 * */

/********_SELECT_THE_SENSE_TRIGGER_CONTROL_OPTIONS_FOR_INT0_INT1_AND_INT2_OTIONS_3_4_ONLY ********/
/*_OPTIONS_1_-> [_FALLING_EDGE_] ********/
/*_OPTIONS_2_-> [_RISING_EDGE_] ********/
/*_OPTIONS_3_-> [_LOW_LEVEL_] ********/
/*_OPTIONS_4_-> [_ANY_LOGICAL_CHANGE] ********/

#define INT0_TRIG_MODE	_RISING_EDGE_
#define INT1_TRIG_MODE	_FALLING_EDGE_
#define INT2_TRIG_MODE	_FALLING_EDGE_

/* Options:
 *			 ENABLE
 * 			 DISABLE
 */
#define EXTI_INT0_ENABLE        ENABLE
#define EXTI_INT1_ENABLE        DISABLE
#define EXTI_INT2_ENABLE        DISABLE

#define EXTI_INT0_PULLUP        ENABLE
#define EXTI_INT1_PULLUP        DISABLE
#define EXTI_INT2_PULLUP        DISABLE

#endif /* MCAL_EXTI_EXTI_CFG_H_ */
