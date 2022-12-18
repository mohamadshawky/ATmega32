/*
 * EXTI_program.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Mohamed
 */



/***************************************************************************************

***************************  - EXTI_program.c				 ****************************
***************************   - Created: 23/9/2022			 ****************************
***************************   - Author: Abdelrahman_Kandil     ***************************
***************************   - Version : _1_				 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/
/***
 *      ________   _________ _____    _____
 *     |  ____\ \ / /__   __|_   _|  |  __ \
 *     | |__   \ V /   | |    | |    | |__) | __ ___   __ _ _ __ __ _ _ __ ___
 *     |  __|   > <    | |    | |    |  ___/ '__/ _ \ / _` | '__/ _` | '_ ` _ \
 *     | |____ / . \   | |   _| |_   | |   | | | (_) | (_| | | | (_| | | | | | |
 *     |______/_/ \_\  |_|  |_____|  |_|   |_|  \___/ \__, |_|  \__,_|_| |_| |_|
 *                                                     __/ |
 *                                                    |___/
 */

/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/
/*===========   INCLUDE LIB   ===========*/
#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "../DIO/DIO_interface.h"
#include "../GIE/GIE_interface.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_CFG.h"

/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/
static void (*GPtr_EXTI0_CallBack_Fun)(void) ;
static void (*GPtr_EXTI1_CallBack_Fun)(void) ;
static void (*GPtr_EXTI2_CallBack_Fun)(void) ;


void MEXTI_vInit(void){

	#if EXTI_INT0_ENABLE == ENABLE
		DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);

	#if EXTI_INT0_PULLUP == ENABLE
		DIO_SetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
		#endif

	#if INT0_TRIG_MODE == _FALLING_EDGE_
		CLEAR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);

	#elif  INT0_TRIG_MODE == _RISING_EDGE_
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);

	#elif  INT0_TRIG_MODE == _ANY_LOGICAL_CHANGE
		CLEAR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);

	#elif  INT0_TRIG_MODE == _LOW_LEVEL_
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);

	#else
		#error "EXT_INT_ERROR: INT0->No Trigger Mode selected"
		#endif
	#endif

	#if EXTI_INT1_ENABLE == ENABLE
		DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);

	#if EXTI_INT1_PULLUP == ENABLE
		DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
	#endif

	#if INT1_TRIG_MODE == _FALLING_EDGE_
		CLR_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);

	#elif  INT1_TRIG_MODE == _RISING_EDGE_
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);

	#elif  INT1_TRIG_MODE == _ANY_LOGICAL_CHANGE
		CLEAR_BIT(MCUCR,3);
		SET_BIT(MCUCR,2);

	#elif  INT1_TRIG_MODE == _LOW_LEVEL_
		CLR_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	#else
		#error "EXT_INT_ERROR: INT1->No Trigger Mode selected"
		#endif
	#endif

	#if EXTI_INT2_ENABLE == ENABLE
		MDIO_vSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_INPUT);

	#if EXTI_INT2_PULLUP == ENABLE
		DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
		#endif

	#if INT2_TRIG_MODE == FALLING_EGDE
		CLR_BIT(MCUCSR,6);

	#elif INT2_TRIG_MODE == RISING_EGDE
		SET_BIT(MCUCSR,6);

	#else
		#error "EXT_INT_ERROR: INT2->No Trigger Mode selected"
		#endif
	#endif
}

void MEXTI_vSetSenseCtrl(u8 A_u8ExtIPin, u8 A_u8SenseCtrl){
	switch (A_u8SenseCtrl){
		case _EXTI_0:
			switch(A_u8SenseCtrl){
				case _FALLING_EDGE_:
					CLR_BIT(MCUCR,0);
					SET_BIT(MCUCR,1);
					break;

				case _RISING_EDGE_:
					SET_BIT(MCUCR,0);
					SET_BIT(MCUCR,1);
					break;

				case _LOW_LEVEL_:
					CLR_BIT(MCUCR,0);
					CLR_BIT(MCUCR,1);
					break;

				case _ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,0);
					CLR_BIT(MCUCR,1);
					break;
			}
			break;

		case _EXTI_1:
			switch(A_u8SenseCtrl){
				case _FALLING_EDGE_:
					CLR_BIT(MCUCR,2);
					SET_BIT(MCUCR,3);
					break;

				case _RISING_EDGE_:
					SET_BIT(MCUCR,2);
					SET_BIT(MCUCR,3);
					break;

				case _LOW_LEVEL_:
					CLR_BIT(MCUCR,2);
					CLR_BIT(MCUCR,3);
					break;

				case _ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,2);
					CLR_BIT(MCUCR,3);
					break;
			}
			break;

		case _EXTI_2:

			switch(A_u8SenseCtrl){
				case _FALLING_EDGE_:
					CLR_BIT(MCUCSR,6);
					break;

				case _RISING_EDGE_:
					SET_BIT(MCUCSR,6);
					break;
			}
			break;

		default:
			/* Error */
			break;
	}
}

void MEXTI_vEnableInterrupt(EXTIx_e A_u8ExtIPin){
	switch(A_u8ExtIPin){
		case _EXTI_0:	SET_BIT(GICR,6);				break;
		case _EXTI_1:	SET_BIT(GICR,7);				break;
		case _EXTI_2:	SET_BIT(GICR,5);				break;
		default:										break;
		}
}

void MEXTI_vDisableInterrupt(EXTIx_e A_u8ExtIPin){
	switch(A_u8ExtIPin){
		case _EXTI_0:	CLR_BIT(GICR,6);				break;
		case _EXTI_1:	CLR_BIT(GICR,7);				break;
		case _EXTI_2:	CLR_BIT(GICR,5);				break;
		default:										break;
	}
}

void MEXTI_vRegisterCallback(EXTIx_e A_u8ExtIPin, void (*fptr) (void)){
	switch(A_u8ExtIPin)
		{
		case _EXTI_0:	GPtr_EXTI0_CallBack_Fun = fptr;	break;
		case _EXTI_1:	GPtr_EXTI1_CallBack_Fun = fptr;	break;
		case _EXTI_2:	GPtr_EXTI2_CallBack_Fun = fptr;	break;
		default:										break;
		}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(GPtr_EXTI0_CallBack_Fun !=NULL){
		GPtr_EXTI0_CallBack_Fun();
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(GPtr_EXTI1_CallBack_Fun !=NULL){
		GPtr_EXTI1_CallBack_Fun();
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(GPtr_EXTI2_CallBack_Fun !=NULL){
		GPtr_EXTI2_CallBack_Fun();
	}
}
