/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: Mohamed Shawky
 */


#include "Utils/STD_TYPES.h"
#include "Utils/BIT_MATH.h"

#include "util/delay.h"

#include "MCAL/DIO/DIO_interface.h"

#include "HAL/SSD/SSD_interface.h"

int main (){
	SSD_t SSD_1 = {PORTB, ANODE, HSSD_vInit, HSSD_vNumber};

	SSD_1.pHSSD_vINT(SSD_1.SSD_u8Type, SSD_1.SSD_u8PortID);

	while (1){
		for (int i = 0; i < 10; i++){
			HSSD_vNumber(SSD_1, i);
			_delay_ms(500);
		}
		for (int i = 8; i > 0; i--){
			HSSD_vNumber(SSD_1, i);
			_delay_ms(500);
		}
	}
}
