/*
 * Lcd.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Hp
 */

#ifndef HAL_LCD_HEADER_LCD_H_
#define HAL_LCD_HEADER_LCD_H_

/*************************************************_INCLUDES_********************************************/
#include"../../../Common/StdTypes.h"
#include"../../../MCAL/Dio/Header/Dio.h"
#include"LcdCfg.h"
#include<util/delay.h>
/**************************************************_MACROS_*********************************************/
#define _8_BIT_MODE                      1
#define _4_BIT_MODE                      2

#define LCD_8_BIT_MODE                   0x38
#define LCD_4_BIT_MODE_1                 0x33
#define LCD_4_BIT_MODE_2                 0x32
#define LCD_4_BIT_MODE_3                 0x28
#define LCD_DISLPAY_ON_CURSUR_OFF        0x0C
#define LCD_CLEAR                        0x01
#define LCD_RETURN_HOME                  0x02
#define LCD_SHIFT_RIGHT                  0x05
#define LCD_SHIFT_LEFT                   0x07
#define NULL_                            '\0'
#define Lcd_SetCGRAM                     0x40
/************************************************_PROTOTYPES_********************************************/
void H_Lcd_Init(void);
void H_Lcd_WriteCharacter(u8);
void H_Lcd_WriteCustomCharacter(u8*,u8,u8,u8);
void H_Lcd_WriteCommand(u8);
void H_Lcd_WriteString(u8*);
void H_Lcd_WriteNumber(s32);
void H_Lcd_WriteFloat(float);
void H_Lcd_Clr(void);
void H_Lcd_GoTo(u8,u8);
void H_Lcd_ShiftRight(void);
void H_Lcd_ShiftLeftt(void);
void H_Lcd_CustomCharacterMoveToLeftFromTop(u8* , u8);
void H_Lcd_CustomCharacterMoveToLeftFromDown(u8* , u8);


#endif /* HAL_LCD_HEADER_LCD_H_ */
