/*
 * LcdCfg.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Hp
 */

#ifndef HAL_LCD_HEADER_LCDCFG_H_
#define HAL_LCD_HEADER_LCDCFG_H_

/*******************************************_SELECT_LCD_MODE_********************************************/
//option 1 ---> [_4_BIT_MODE]
//option 2 ---> [_8_BIT_MODE]
#define LCD_MODE          _4_BIT_MODE
/*********************************************_SELECT_LCD_PIN_********************************************/
#define LCD_DATA_PORT     PORTC
#define LCD_DATA0_PIN     PC0
#define LCD_DATA1_PIN     PC1
#define LCD_DATA2_PIN     PC2
#define LCD_DATA3_PIN     PC3
#define LCD_DATA4_PIN     PC4
#define LCD_DATA5_PIN     PC5
#define LCD_DATA6_PIN     PC6
#define LCD_DATA7_PIN     PC7


#define LCD_RS_PIN        PB1
#define LCD_RW_PIN        PB2
#define LCD_EN_PIN        PB3
#endif /* HAL_LCD_HEADER_LCDCFG_H_ */
