/*
 * LCD_interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Mohamed
 */

#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_


void HLCD_vSendChar(u8 A_u8character);
void HLCD_vSendCMD(char A_u8cmd);
void HLCD_vInit(void);

void HLCD_vPrintString(char* A_pu8str);
void HLCD_vPrintNumber(s32 A_s32num);
void HLCD_vDisplayCustomCharacter(u8 A_u8ID);
void HLCD_vSaveCustomCharacter(u8 A_pu8Arr[], u8 A_u8CharID);
void HLCD_vClear(void);
void HLCD_vSetCursorPos(u8 A_u8LinePos, u8 A_u8LineNumber);


#endif /* HAL_LCD_INTERFACE_H_ */
