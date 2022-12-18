/*
 * WDT_private.h
 *
 *  Created on: Oct 1, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_WDT_PRIVATE_H_
#define MCAL_WDT_PRIVATE_H_


#define WDTCR		 *((volatile u8*)0x41)
#define WDP0			0
#define WDP1			1
#define WDP2			2
#define WDE				3
#define WDTOE			4

/* WDT Prescaler applying VCC = 5.0V */
#define WDT_PS_16ms			0
#define WDT_PS_32s			1
#define WDT_PS_65ms			2
#define WDT_PS_130ms		3
#define WDT_PS_260ms		4
#define WDT_PS_520ms		5
#define WDT_PS_1000ms		6
#define WDT_PS_2100ms		7

#endif /* MCAL_WDT_PRIVATE_H_ */
