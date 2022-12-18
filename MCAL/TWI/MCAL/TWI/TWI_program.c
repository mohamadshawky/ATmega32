/*
 * TWI_program.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Mohamed
 */

#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_CFG.h"


void TWI_vInit(void)
{
	/* Setting Baud Rate to 2 */
	CLR_BIT(TWBR, TWPS0);
	SET_BIT(TWBR, TWPS1);

	/* Setting prescaler to 0 */
	CLR_BIT(TWSR, TWPS0);
	CLR_BIT(TWSR, TWPS1);

	/* 2- Own slave Address */
	TWAR = TWI_OWN_SLA_ADDR;
}

u8 TWI_u8SendStartCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);		/* set start condition, TWINT to start transmission & enable TWI*/
	while (!(TWCR & (1<<TWINT)))				/* wait until status is updated @ TWDR */
		;
	return (TWSR & 0xF8);						/* return status */
}

u8   TWI_u8SendSlaveAddress(u8 A_u8Sla, u8 A_u8Rw)
{
	TWDR = (A_u8Sla<<1) | A_u8Rw;
	CLR_BIT(TWCR, TWSTA);			// Clear start bit
	TWCR = (1<<TWINT) | (1<<TWEN); /* set TWINT to start transmission */
	while (!(TWCR & (1<<TWINT)))
		;
	return (TWSR & 0xF8);
}

u8   TWI_u8SendByte(u8 A_u8Byte)
{
	TWDR = A_u8Byte;				/* write data */
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)))
		;
	return (TWSR & 0xF8);
}

u8   TWI_u8RecvByte(u8* A_pu8Byte, u8 A_u8Ack)
{
	if (A_u8Ack){
		TWCR |= (1 << TWINT) | (1<<TWEN) | (1<<TWEA);
	}else{
		CLR_BIT(TWCR, TWEA);		/* enable ACK (set or clear later) */
		TWCR |= (1 << TWINT) | (1<<TWEN);
	}
	while (!(TWCR & (1<<TWINT)));

	*A_pu8Byte = TWDR;

	return (TWSR & 0xF8);
}

u8   TWI_u8SendStopCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|
			(1<<TWSTO);

	return (TWSR & 0xF8);
}


u8   TWI_u8SendRepeatedStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)))
		;
	return (TWSR & 0xF8);
}

u8   TWI_u8GetStatusCode(void)
{
	return (TWSR & 0xF8);
}

