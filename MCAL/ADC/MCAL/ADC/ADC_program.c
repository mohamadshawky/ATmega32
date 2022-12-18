/*
 * ADC_program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Mohamed Shawky
 */

/*===========   INCLUDE LIB   ===========*/
#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_CFG.h"

/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/

static void (*ADC_Callback)(void);

void MADC_vInit(void)
{
	/* 1- Select Reference bits*/
#if ADC_VREF_VOLT == _AVCC
	ADMUX = ((ADMUX & ~(0b11<<6)) |(_AVCC<<6)); // Make Mask to clear bit 6 and 7 and write on them 1 and zero
	//ADMUX &=~(0b11<<6);
	//ADMUX |=(ADC_VREF<<6);
#elif ADC_VREF_VOLT ==_AREF
	ADMUX = ((ADMUX & ~(0b11<<6)) |(_AREF<<6));
#elif ADC_VREF_VOLT == _2_56_INTERNAL_VOLT_
	ADMUX = ((ADMUX & ~(0b11<<6)) |(_2_56_INTERNAL_VOLT_<<6));
#endif

	/* 2- Select data adjust*/
#if ADC_DATA_ADJUST == ADC_RIGHT
	CLR_BIT(ADMUX,ADLAR);
#elif ADC_DATA_ADJUST == ADC_LEFT
	SET_BIT(ADMUX,ADLAR);
#endif

	/* 3- Auto Trigger Disable/Enable*/
#if AUTO_TRIGERING_MODE == ENABLE
	SET_BIT(ADCSRA,ADATE);
	/* 4- select auto trigger source*/
	#if 	ADC_AUTO_TRIG_SOURCE == FREERUNNING
		SFIOR=(SFIOR & 0x1F)|(FREERUNNING<<5);

	#elif	ADC_AUTO_TRIG_SOURCE == ANALOG_COMPARATOR
		SFIOR=(SFIOR & 0x1F)|(ANALOG_COMPARATOR<<5);

	#elif	ADC_AUTO_TRIG_SOURCE == EXT0
		SFIOR=(SFIOR & 0x1F)|(EXT0<<5);

	#elif   ADC_AUTO_TRIG_SOURCE ==	TIMER0_COMPARE
		SFIOR=(SFIOR & 0x1F)|(TIMER0_COMPARE<<5);

	#elif	ADC_AUTO_TRIG_SOURCE == TIMER0_OVERFLOW
		SFIOR=(SFIOR & 0x1F)|(TIMER0_OVERFLOW<<5);

	#elif	ADC_AUTO_TRIG_SOURCE == TIMER_COMPARE_B
		SFIOR=(SFIOR & 0x1F)|(TIMER_COMPARE_B<<5);

	#elif	ADC_AUTO_TRIG_SOURCE == TIMER1_OVERFLOW
		SFIOR=(SFIOR & 0x1F)|(TIMER1_OVERFLOW<<5);

	#elif	ADC_AUTO_TRIG_SOURCE == TIMER1_CAPTURE_EVENT
		SFIOR=(SFIOR & 0x1F)|(TIMER1_CAPTURE_EVENT<<5);

#endif
#elif AUTO_TRIGERING_MODE == DISABLE
	CLR_BIT(ADCSRA,ADATE);

#endif

	/*By Default in Reset*/
	/* 5- Interrupt Enable/Disable*/
#if ADC_INTERRUPT_MODE == DISABLE
	CLR_BIT(ADCSRA,ADIE);
#elif ADC_INTERRUPT_MODE == ENABLE
	SET_BIT(ADCSRA,ADIE);
#endif
	/* 6- Conversion Clock PRESCALER */
	ADCSRA &=~(0b111); //to make mask on register to clear the bits i need to write on it .
	#if   ADC_PRESCALER == PRESCALER_DIV_FACTOR_2_
	ADCSRA |=(PRESCALER_DIV_FACTOR_2_);
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_4_
	ADCSRA |=(PRESCALER_DIV_FACTOR_4_);
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_8_
	ADCSRA |=(PRESCALER_DIV_FACTOR_8_);
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_16_
	ADCSRA |=(PRESCALER_DIV_FACTOR_16_);
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_32_
	ADCSRA |=(PRESCALER_DIV_FACTOR_32_);
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_64_
	ADCSRA |=(PRESCALER_DIV_FACTOR_64_);
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_128_
	ADCSRA |=(PRESCALER_DIV_FACTOR_128_);

	#endif
	/* 3- ADC Enable*/
	SET_BIT(ADCSRA,ADEN);
}
u16	 MADC_u16ReadDigitalValue_synch(u8 Copy_u8Channel)
{
	/* 1- Select Channel*/
	//ADMUX &=~(0b11111); //to make mask on register to clear the bits i need to write on it .
	//ADMUX |=(Copy_u8Channel &0x07); //0x07 3lshan law el user entered wrong channel
			//(Copy_u8Channel %8)	//%8  3lshan law el user entered wrong channel
		if (Copy_u8Channel < 8)
		{
			ADMUX=( (ADMUX & ~(0b11111) ) | (Copy_u8Channel) );
		}
		else{/*Error*/}
	/* 2- Start conversion*/
	SET_BIT(ADCSRA,6);
	/* 3- Wait for conversion complete flag*/
	while((GET_BIT(ADCSRA,4))!= 1){/*Just waiting */}; //this is poling
	/* 4- clear flag*/
	SET_BIT(ADCSRA,4);

	/* 5- Return ADC Value*/
	/*u16 L_u16Value = ( ADCL | ((u16)ADCH<<8) ); //Another Method to Return ADC Value
	  return L_u16Value ;*/
	return ADC_Data;
}

void MADC_StartConversion(u8 Copy_u8Channel)
{
	/*	Select Channel */
	if (Copy_u8Channel < 8)
	{
		ADMUX=( (ADMUX & ~(0b11111) ) | (Copy_u8Channel) );
	}
	else {/*Error*/}
	/* start conversion*/
		SET_BIT(ADCSRA,ADSC);
}

u16 MADC_u16ReadDigitalValue_Asynch(void)
{
	return ADC_Data;

}


void ADC_SetCallBack(void(*fptr)(void))
{
	if (fptr != NULL)
	{
		ADC_Callback = fptr;
	}
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	if (ADC_Callback != NULL)
	{
		ADC_Callback();

	}
}

