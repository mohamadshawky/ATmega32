/*
 * ADC_incterface.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

/*============================================================================
  ==================_ADC_Channels======================
  ============================================================================*/
#define ADC_CHANNEL_0		0U	//(default)
#define ADC_CHANNEL_1		1U
#define ADC_CHANNEL_2		2U
#define ADC_CHANNEL_3		3U
#define ADC_CHANNEL_4		4U
#define ADC_CHANNEL_5		5U
#define ADC_CHANNEL_6		6U
#define ADC_CHANNEL_7		7U

/***************_FUNCTION_PROTOTYPE_************/
void MADC_vInit(void);
u16	 MADC_u16ReadDigitalValue_synch(u8 Copy_u8Channel); //Synchronous Function
void MADC_vSetCallback(void (*Fptr)(void)); /*or SetCallback*/
void MADC_vEnableInterrupt(void);
void MADC_vDisableInterrupt(void);
void MADC_vSelectChannel(u8 Copy_u8Channel);
void MADC_vStartConversion(u8 Copy_u8Channel);
u16	 MADC_u16ReadDigitalValue_asynch(u8 Copy_u8Channel); //Synchronous Function
void MADC_StartConversion(u8 Copy_u8Channel);
u16 MADC_u16ReadDigitalValue_Asynch(void);//ASynchronous Function for Interrupt

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
