/*
 * ADC_CFG.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Mohamed Shawky
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

/*============================================================================
  ==================_Supported Voltage Reference by ADC_======================
  ============================================================================
				_OPTIONS_1_-> [_AREF]
				_OPTIONS_2_-> [_AVCC]
				_OPTIONS_3_-> [_2_56_INTERNAL_VOLT_]
============================================================================*/
#define ADC_VREF_VOLT	_AVCC
/*============================================================================*/

/*============================================================================*/
/*==================_Supported Prescaler Options by ADC_======================
  ============================================================================
		ADC operates within a frequency range of 50kHz to 200kHz
	_OPTIONS_1_->  [PRESCALER_DIV_FACTOR_2_]		// for 16 MHz/2	  = 8   MHz
	_OPTIONS_2_->  [PRESCALER_DIV_FACTOR_4_]        // for 16 MHz/4	  = 4	MHz
	_OPTIONS_3_->  [PRESCALER_DIV_FACTOR_8_]        // for 16 MHz/8	  = 2	MHz
	_OPTIONS_4_->  [PRESCALER_DIV_FACTOR_16_]       // for 16 MHz/16  = 1	MHz
	_OPTIONS_5_->  [PRESCALER_DIV_FACTOR_32_]       // for 16 MHz/32  = 500 KHz
	_OPTIONS_6_->  [PRESCALER_DIV_FACTOR_64_]       // for 16 MHz/64  = 250 KHz
	_OPTIONS_7_->  [PRESCALER_DIV_FACTOR_128_]		// for 16 MHz/128 = 125 KHz
==============================================================================*/
#define ADC_PRESCALER		PRESCALER_DIV_FACTOR_64_
/*============================================================================*/


/********_SELECT_ADJUSTMENT_**********/
/*_OPTIONS_1_-> [ADC_RIGHT] **********/
/*_OPTIONS_2_-> [ADC_LEFT] ***********/
#define ADC_DATA_ADJUST  ADC_RIGHT
/*************************************/

/*******_AUTO_TRIGERING_MODE_**********/
/*_OPTIONS_1_-> [DISABLE] *************/
/*_OPTIONS_2_-> [ENABLE] **************/
#define AUTO_TRIGERING_MODE     DISABLE
/**************************************/

/*============================================================================*/
/*==================_ADC_AUTO_TRIGGER_SOURCE====================================
================================================================================
  ////////	ADC operates within a frequency range of 50kHz to 200kHz ////
			_OPTIONS_1_->  [FREERUNNING]
			_OPTIONS_2_->  [ANALOG_COMPARATOR]
			_OPTIONS_3_->  [EXT0]
			_OPTIONS_4_->  [TIMER0_COMPARE]
			_OPTIONS_5_->  [TIMER0_OVERFLOW]
			_OPTIONS_6_->  [TIMER_COMPARE_B]
			_OPTIONS_7_->  [TIMER1_OVERFLOW]
			_OPTIONS_8_->  [TIMER1_CAPTURE_EVENT] */
/*==============================================================================*/
#define ADC_AUTO_TRIGGER_SOURCE		FREERUNNING
/*==============================================================================*/


/*******_ADC_INTERRUPT_MODE_****************/
/*_OPTIONS_1_-> [DISABLE] ******************/
/*_OPTIONS_2_-> [ENABLE] *******************/
#define ADC_INTERRUPT_MODE			DISABLE
/*******************************************/


#endif /* MCAL_ADC_ADC_CFG_H_ */
