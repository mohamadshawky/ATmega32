/*
 * LCD_private.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Mohamed
 */

#ifndef HAL_LCD_PRIVATE_H_
#define HAL_LCD_PRIVATE_H_


#define lcd_Clear           0x01          // replace all characters with ASCII 'space'                       */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position
#define DDRAM_ADDRESS		0b10000000	  // set DDRAM address in address counter
#define GCRAM_ADDRESS  	    0b01000000	  // set CGRAM Address in address counter

#define FONT_5X10		0
#define FONT_5X7		1

#define ONE_LINE		0
#define TWO_LINES		1

#define _4BIT_DATA		0
#define _8BIT_DATA		1

#define MOVE_RIGHT		1
#define MOVE_LEFT		0

#define SHIFT_LEFT		0
#define SHIFT_RIGHT		1

#if ( LCD_FONT == _5x10 && LINE_NUM == TWO_LINES )
#pragma GCC error "You cannot Have Two Lines LCD with 5 * 10"
#endif

#endif /* HAL_LCD_PRIVATE_H_ */
