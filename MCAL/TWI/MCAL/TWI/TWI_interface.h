/*
 * TWI_interface.h
 *
 *  Created on: Oct 14, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

#define TWI_READ  1
#define TWI_WRITE 0



void TWI_vInit(void);
u8   TWI_u8SendStartCondition(void);
u8   TWI_u8SendSlaveAddress(u8 A_u8Sla, u8 A_u8Rw);
u8   TWI_u8SendByte(u8 A_u8Byte);
u8   TWI_u8RecvByte(u8* A_pu8Byte, u8 A_u8Ack);
u8   TWI_u8SendStopCondition(void);
u8   TWI_u8SendRepeatedStart(void);
u8   TWI_u8GetStatusCode(void);
void TWI_vSetOwnSlaveAddress(u8 A_u8OwnSlave);
void TWI_vSetBitRate(u32 A_u32BitRate);

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
