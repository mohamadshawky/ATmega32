/*
 * ADC_private.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Mohamed Shawky
 */
/*===============================================================================================
	  - Developer can't Edit in it
	  - Register _ Definition
	  - Design :
					- #define	:	Yes
					- Union		:	NO
					- Structure	:	NO

===================================================================================================*/
#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/* ADC operates within a frequency range of 50kHz to 200kHz */
#define PRESCALER_DIV_FACTOR_2_		0b001		// for 16 MHz/2	  = 8   MHz
#define PRESCALER_DIV_FACTOR_4_		0b010		// for 16 MHz/4	  = 4	MHz
#define PRESCALER_DIV_FACTOR_8_		0b011		// for 16 MHz/8	  = 2	MHz
#define PRESCALER_DIV_FACTOR_16_	0b100		// for 16 MHz/16  = 1	MHz
#define PRESCALER_DIV_FACTOR_32_	0b101		// for 16 MHz/32  = 500 KHz
#define PRESCALER_DIV_FACTOR_64_	0b110		// for 16 MHz/64  = 250 KHz
#define PRESCALER_DIV_FACTOR_128_	0b111		// for 16 MHz/128 = 125 KHz

#define _AVCC          					  0b01
#define _AREF         					  0b00
#define _2_56_INTERNAL_VOLT_              0b11

#define     ADC_LEFT    1
#define     ADC_RIGHT   0

#define FREERUNNING				0b000
#define	ANALOG_COMPARATOR		0b001
#define	EXT0					0b010
#define	TIMER0_COMPARE			0b011
#define	TIMER0_OVERFLOW			0b100
#define TIMER_COMPARE_B			0b101
#define	TIMER1_OVERFLOW			0b110
#define TIMER1_CAPTURE_EVENT	0b111

#define ENABLE		1
#define	DISABLE		0

/***************_ADC_REGISTERS_**************/
#define ADC_CHANNEL_0		0U	//(default)
#define ADC_CHANNEL_1		1U
#define ADC_CHANNEL_2		2U
#define ADC_CHANNEL_3		3U
#define ADC_CHANNEL_4		4U
#define ADC_CHANNEL_5		5U
#define ADC_CHANNEL_6		6U
#define ADC_CHANNEL_7		7U

/* ADC Multiplexer Selection Register*/
#define ADMUX     (*(volatile u8*)(0x27))
#define REFS1      7							// Reference selection bit1
#define REFS0      6							// Reference selection bit0
#define ADLAR      5							// ADC Left Adjust result
#define MUX4       4							// Analog channel and gain selection bit4
#define MUX3       3                            // Analog channel and gain selection bit3
#define MUX2       2                            // Analog channel and gain selection bit2
#define MUX1       1                            // Analog channel and gain selection bit1
#define MUX0       0                            // Analog channel and gain selection bit0

/* ADC Control and Status Register A */
#define ADCSRA     (*(volatile u8*)(0x26))
#define ADEN       7							// ADC Enable
#define ADSC       6							// ADC Start Conversion
#define ADATE      5							// ADC Auto Trigger Enable
#define ADIF       4							// ADC Interrupt flag
#define ADIE       3							// ADC Interrupt Enable
#define ADPS2      2							// Prescaler bit2
#define ADPS1      1                            // Prescaler bit1
#define ADPS0      0                            // Prescaler bit0

#define ADCH            (*(volatile u8*)(0x25)) 	/*ADC Data Register High –> ADCH */
#define ADCL            (*(volatile u8*)(0x24))		/*ADC Data Register LOW –> ADCL */
#define SFIOR           (*(volatile u8*)(0x50))		/*Special Function IO Register –> SFIOR*/
#define ADC_Data        (*(volatile u16*)(0x24))	/*To READ 2 REGISTER ARE JUST SEQUENTIALY 0X25 + 0X24 */

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
