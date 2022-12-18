/*
 * DIO.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Mohamed Shawky
 */

#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include "DIO_REG.h"
#include "DIO_CFG.h"
#include "DIO_interface.h"

/* IO Pins */
void DIO_SetPinValue(u8 A_u8PortIdCopy, u8 A_u8PinIdCopy, u8 A_u8PinValCopy) {
	if (A_u8PinValCopy == DIO_HIGH) {
		switch (A_u8PortIdCopy) {
			case DIO_PORTA:
				SET_BIT(PORTA_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTB:
				SET_BIT(PORTB_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTC:
				SET_BIT(PORTC_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTD:
				SET_BIT(PORTD_Register, A_u8PinIdCopy);
				break;
			default:
				break;
		}
	} else if (A_u8PinValCopy == DIO_LOW) {
		switch (A_u8PortIdCopy) {
			case DIO_PORTA:
				CLR_BIT(PORTA_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTB:
				CLR_BIT(PORTB_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTC:
				CLR_BIT(PORTC_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTD:
				CLR_BIT(PORTD_Register, A_u8PinIdCopy);
				break;
			default:
				break;
			}
	} else {
		/* No thing */
	}

}

u8 DIO_GetPinValue(u8 A_u8PortIdCopy, u8 A_u8PinIdCopy) {
	u8 nvalue = 0;
	switch (A_u8PortIdCopy) {
		case DIO_PORTA:
			nvalue = GET_BIT(PINA_Register, A_u8PinIdCopy);
			break;
		case DIO_PORTB:
			nvalue = GET_BIT(PINB_Register, A_u8PinIdCopy);
			break;
		case DIO_PORTC:
			nvalue = GET_BIT(PINC_Register, A_u8PinIdCopy);
			break;
		case DIO_PORTD:
			nvalue = GET_BIT(PIND_Register, A_u8PinIdCopy);
			break;
		default:
			break;
		}
	return nvalue;
}

void DIO_SetPinDirection(u8 A_u8PortIdCopy, u8 A_u8PinIdCopy, u8 A_u8PinDirCopy) {
	if (A_u8PinDirCopy == DIO_OUTPUT) {
		switch (A_u8PortIdCopy) {
			case DIO_PORTA:
				SET_BIT(DDRA_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTC:
				SET_BIT(DDRC_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTD:
				SET_BIT(DDRD_Register, A_u8PinIdCopy);
				break;
			default:
				break;
		}
	} else if (A_u8PinDirCopy == DIO_INPUT) {
		switch (A_u8PortIdCopy) {
			case DIO_PORTA:
				CLR_BIT(DDRA_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTB:
				CLR_BIT(DDRB_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTC:
				CLR_BIT(DDRC_Register, A_u8PinIdCopy);
				break;
			case DIO_PORTD:
				CLR_BIT(DDRD_Register, A_u8PinIdCopy);
				break;
			default:
				break;
		}
	} else {
		/* No thing */
	}
}

void DIO_TogPin(u8 A_u8PortIdCopy, u8 A_u8PinIdCopy){

	switch (A_u8PinIdCopy) {
		case DIO_PORTA:
			TOG_BIT(PINA_Register, A_u8PinIdCopy);
			break;
		case DIO_PORTB:
			TOG_BIT(PINB_Register, A_u8PinIdCopy);
			break;
		case DIO_PORTC:
			TOG_BIT(PINC_Register, A_u8PinIdCopy);
			break;
		case DIO_PORTD:
			TOG_BIT(PIND_Register, A_u8PinIdCopy);
			break;
		default:
			break;
		}
}

/* IO Ports */
void DIO_SetPortDirection(u8 A_u8PortId, u8 A_u8PortDir) {
	switch (A_u8PortId) {
		case DIO_PORTA:
			DDRA_Register = A_u8PortDir;
			break;
		case DIO_PORTB:
			DDRB_Register = A_u8PortDir;
			break;
		case DIO_PORTC:
			DDRC_Register = A_u8PortDir;
			break;
		case DIO_PORTD:
			DDRD_Register = A_u8PortDir;
			break;
		default:
			break;
		}
}

u8 DIO_u8GetPortValue(u8 A_u8PortId){
	u8 PortVal;
	switch(A_u8PortId){
		case DIO_PORTA:
			PortVal=PINA_Register;
			break ;
		case DIO_PORTB:
			PortVal=PINB_Register;
			break ;
		case DIO_PORTC:
			PortVal=PINC_Register;
			break ;
		case DIO_PORTD:
			PortVal=PIND_Register;
			break ;
		default :
			PortVal=-1;
			break;
	}
	return PortVal;
}

void DIO_SetPortValue(u8 A_u8PortId, u8 A_u8PortVal) {
	switch (A_u8PortId) {
		case DIO_PORTA:
			PORTA_Register = A_u8PortVal;
			break;
		case DIO_PORTB:
			PORTB_Register = A_u8PortVal;
			break;
		case DIO_PORTC:
			PORTC_Register = A_u8PortVal;
			break;
		case DIO_PORTD:
			PORTD_Register = A_u8PortVal;
			break;
		default:
			break;
	}
}
