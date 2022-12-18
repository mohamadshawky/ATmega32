/*
 * SSD_interface.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Mohamed
 */

#ifndef HAL_SSD_INTERFACE_H_
#define HAL_SSD_INTERFACE_H_

typedef enum{
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD
}SSD_port_t;

typedef enum {
	ANODE = 0,
	CATHOD
}SSD_type_t;

typedef enum {
	number_0 = 0,
	number_1,
	number_2,
	number_3,
	number_4,
	number_5,
	number_6,
	number_7,
	number_8,
	number_9,
}SSD_number_t;

typedef struct SSD
{
	u8 SSD_u8PortID;
	u8 SSD_u8Type;
	void (*pHSSD_vINT)(u8, u8);
	void (*pHSSD_vSet)(struct SSD, u8);
}SSD_t;

void HSSD_vInit(u8 Copy_u8Type, u8 Copy_u8PortID);
void HSSD_vNumber(struct SSD Copy_xSSD, u8 Copy_u8Number);

#endif /* HAL_SSD_INTERFACE_H_ */
