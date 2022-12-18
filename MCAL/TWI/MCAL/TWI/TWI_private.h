/*
 * TWI_private.h
 *
 *  Created on: Oct 14, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_

/* TWI Bit Rate Register – TWBR */
#define TWBR     *((volatile u8*)(0x20))

/* TWI Control Register – TWCR */
#define TWCR     *((volatile u8*)(0x56))
#define TWINT		7							/* TWI Interrupt Flag */
#define TWEA		6							/* TWI Enable Acknowledge Bit */
#define TWSTA		5							/* TWI START Condition Bit */
#define	TWSTO		4							/* TWI STOP Condition Bit */
#define	TWWC		3							/* TWI Write Collision Flag */
#define	TWEN		2							/* TWI Enable Bit */
#define TWIE		0							/* TWI Interrupt Enable */

/* TWI Status Register – TWSR */
#define TWSR     *((volatile u8*)(0x21))
#define	TWS7		7							/* TWI Status Bit7 */
#define	TWS6		6							/* TWI Status Bit6 */
#define TWS5        5                      		/* TWI Status Bit5 */
#define TWS4        4                      		/* TWI Status Bit4 */
#define TWS3        3                           /* TWI Status Bit3 */
#define TWPS1       1                           /* TWI Prescaler Bit1 */
#define TWPS0       0                           /* TWI Prescaler Bit0 */

/* TWI Data Register – TWDR*/
#define TWDR     *((volatile u8*)(0x23))

/* TWI (Slave) Address Register – TWAR */
#define TWAR     *((volatile u8*)(0x22))

#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
