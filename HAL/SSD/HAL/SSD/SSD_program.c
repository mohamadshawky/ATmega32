/*
 * SSD_program.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Mohamed
 */

#ifndef HAL_SSD_PROGRAM_C_
#define HAL_SSD_PROGRAM_C_

#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_CFG.h"

static u8 su8SSD_Index[10] = { 0b00111111, /* 0 */			
		0b00000110, /* 1 */
		0b01011011, /* 2 */
		0b01001111, /* 3 */
		0b01100110, /* 4 */
		0b01101101, /* 5 */
		0b01111101, /* 6 */
		0b00000111, /* 7 */
		0b01111111, /* 8 */
		0b01101111 /* 9 */
};


void HSSD_vInit(u8 Copy_u8Type, u8 Copy_u8PortID){

	if(Copy_u8Type == ANODE){
		DIO_SetPortDirection(Copy_u8PortID,0xFF);
		DIO_SetPortValue(Copy_u8PortID,~su8SSD_Index[number_0]);
	}
	else if(Copy_u8Type == CATHOD){
		DIO_SetPortDirection(Copy_u8PortID,0xFF);
		DIO_SetPortValue(Copy_u8PortID,su8SSD_Index[number_0]);
	}
}

void HSSD_vNumber(SSD_t Copy_xSSD, u8 Copy_u8Number)
{
	if( Copy_xSSD.SSD_u8Type == ANODE )
		DIO_SetPortValue(Copy_xSSD.SSD_u8PortID,~su8SSD_Index[Copy_u8Number]);
	else if(Copy_xSSD.SSD_u8Type == CATHOD)
		DIO_SetPortValue(Copy_xSSD.SSD_u8PortID,su8SSD_Index[Copy_u8Number]);
}

#endif /* HAL_SSD_PROGRAM_C_ */
