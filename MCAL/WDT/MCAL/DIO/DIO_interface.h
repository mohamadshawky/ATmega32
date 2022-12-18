/*
 * DIO.h
 *
 *  Created on: Aug 23, 2019
 *      Author: Mohamed Shawky
 */


#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_


/* Port Defines */
#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

/* PIN Defines */
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

/* PIN Directions */
#define DIO_INPUT  0
#define DIO_OUTPUT 1

/* PIN Value Options */
#define DIO_HIGH   1
#define DIO_LOW    0

/* Port Handling */
#define ALL_INPUT  0x00
#define ALL_OUTPUT 0xFF

#define ALL_LOW  0x00
#define ALL_HIGH 0xFF


/* IO Pins */
void DIO_SetPinValue (u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue (u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

void DIO_TogPin(u8 u8PortIdCopy, u8 u8PinIdCopy);

/* IO Ports */
void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

u8 DIO_u8GetPortValue(u8 u8PortId);

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);

#endif /* MCAL_DIO_DIO_H_ */
