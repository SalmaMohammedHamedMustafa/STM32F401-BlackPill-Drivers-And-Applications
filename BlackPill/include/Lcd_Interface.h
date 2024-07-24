/*
 * Lcd_Interface.h
 *
 *  Created on: Sep 15, 2023
 *      Author: hisha
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_



void LCD_voidSendCommand(u8 command);
void LCD_voidSendData(u8 data);
void LCD_voidInit();
void LCD_voidSendString(u8 String[]);
void LCD_voidSendNumber (s32 num);
void LCD_voidSetPos(u8 x, u8 Y);
void LCD_voidSpecialCharacter (u8 block_no , u8 *special, u8 x, u8 y);
void LCD_voidClear();

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
