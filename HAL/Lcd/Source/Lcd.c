/*
 * Lcd.c
 *
 *  Created on: Jul 5, 2024
 *      Author: Hp
 */

#include"../Header/Lcd.h"
void H_Lcd_Init(void)
{
	#if LCD_MODE  == _8_BIT_MODE
	M_Dio_PinMode(LCD_DATA0_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA1_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA2_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA3_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA4_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA5_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA6_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA7_PIN,OUTPUT);

	M_Dio_PinMode(LCD_RS_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RW_PIN,OUTPUT);
	M_Dio_PinWrite(LCD_RW_PIN,LOW);
	M_Dio_PinMode(LCD_EN_PIN,OUTPUT);
	_delay_ms(1000);//because mc of lcd is slower than the mc
	H_Lcd_WriteCommand(LCD_8_BIT_MODE);//to send order
	H_Lcd_WriteCommand(LCD_DISLPAY_ON_CURSUR_OFF);
	H_Lcd_WriteCommand(LCD_CLEAR);
	H_Lcd_WriteCommand(LCD_RETURN_HOME);

	#elif LCD_MODE  == _4_BIT_MODE
	M_Dio_PinMode(LCD_DATA4_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA5_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA6_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA7_PIN,OUTPUT);

	M_Dio_PinMode(LCD_RS_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RW_PIN,OUTPUT);
	M_Dio_PinWrite(LCD_RW_PIN,LOW);
	M_Dio_PinMode(LCD_EN_PIN,OUTPUT);
	_delay_ms(1000);//because mc of lcd is slower than the mc
	H_Lcd_WriteCommand(LCD_4_BIT_MODE_1);//to send order
	H_Lcd_WriteCommand(LCD_4_BIT_MODE_2);
	H_Lcd_WriteCommand(LCD_4_BIT_MODE_3);
	H_Lcd_WriteCommand(LCD_DISLPAY_ON_CURSUR_OFF);
	H_Lcd_WriteCommand(LCD_CLEAR);
	H_Lcd_WriteCommand(LCD_RETURN_HOME);
	#endif
}
void H_Lcd_WriteCharacter(u8 Local_u8_Character)
{
   #if LCD_MODE  == _8_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,HIGH);
	LCD_DATA_PORT = Local_u8_Character;
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5); //because mc don`t work at the same fq
	#elif LCD_MODE  == _4_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,HIGH);
	LCD_DATA_PORT = ((Local_u8_Character & 0xF0) | (LCD_DATA_PORT & 0x0F));
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);//half of the order
	_delay_ms(5);
	LCD_DATA_PORT = (Local_u8_Character << 4) | (LCD_DATA_PORT & 0x0F);
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}
void H_Lcd_WriteCustomCharacter(u8* Local_u8_Arr , u8 Local_u8_BlockNo , u8 Local_u8_XPos , u8 Local_u8_YPos)
{
	u8 Local_u8_CGRAM_Address = 0;
	Local_u8_CGRAM_Address = Local_u8_BlockNo*8;
	H_Lcd_WriteCommand(Lcd_SetCGRAM+Local_u8_CGRAM_Address);
	for( int i=0;i<8;i++)
	{
	H_Lcd_WriteCharacter(Local_u8_Arr[i]);
	}
	H_Lcd_GoTo(Local_u8_XPos , Local_u8_YPos);
	H_Lcd_WriteCharacter(Local_u8_BlockNo);
}
void H_Lcd_WriteCommand(u8 Local_u8_Command)
{
	#if LCD_MODE  == _8_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,LOW);
	LCD_DATA_PORT = Local_u8_Command;
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5); //because mc don`t work at the same fq
	#elif LCD_MODE  == _4_BIT_MODE
	M_Dio_PinWrite(LCD_RS_PIN,LOW);
	LCD_DATA_PORT = ((Local_u8_Command & 0xF0)| (LCD_DATA_PORT & 0x0F));
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);//half of the order
	_delay_ms(5);
	LCD_DATA_PORT = (Local_u8_Command << 4) | (LCD_DATA_PORT & 0x0F);
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}
void H_Lcd_WriteString(u8* Local_u8_Ptr)
{
	u8 Local_u8_Counter = 0;
	while(Local_u8_Ptr[Local_u8_Counter] != NULL_)
	{
	H_Lcd_WriteCharacter(Local_u8_Ptr[Local_u8_Counter]);
	Local_u8_Counter++;
	}
}
void H_Lcd_WriteNumber(s32 Local_s32_Number)// ---> 124 ---> 1 2 4
{
	u8 Local_u8_Arr [10] = {0};
	s8 Local_s8_Counter  = 0;
	u8 Local_u8_Digit    = 0;
	if(Local_s32_Number == 0)
	{
		H_Lcd_WriteCharacter('0');
	}
	else
	{
		if(Local_s32_Number < 0)
		{
			H_Lcd_WriteCharacter('-');
			Local_s32_Number = Local_s32_Number * -1;
		}
	while(Local_s32_Number != 0)
	{
	   Local_u8_Digit = Local_s32_Number % 10;//--> 4
	   Local_u8_Arr[Local_s8_Counter] = Local_u8_Digit;
	   Local_s8_Counter++;
	   Local_s32_Number =  Local_s32_Number / 10;// ---> 12
	}
	Local_s8_Counter--;
	while(Local_s8_Counter >= 0)
	{
		H_Lcd_WriteCharacter(Local_u8_Arr[Local_s8_Counter] + 48);
		Local_s8_Counter--;
	}
	}
}
void H_Lcd_WriteFloat(float Local_f32_Number) {
    s32 Local_s32_IntegerPart;    // To store the integer part of the float
    float Local_f32_FractionPart; // To store the fractional part of the float
    s32 Local_s32_FractionAsInt;  // Fractional part as an integer for display
    u8 Local_u8_NumDecimalPlaces = 2; // Number of decimal places to display

    // Handle negative numbers
    if (Local_f32_Number < 0) {
        H_Lcd_WriteCharacter('-'); // Write '-' for negative numbers
        Local_f32_Number = -Local_f32_Number; // Convert to positive
    }

    // Separate integer and fractional parts
    Local_s32_IntegerPart = (s32)Local_f32_Number;           // Get integer part
    Local_f32_FractionPart = Local_f32_Number - Local_s32_IntegerPart; // Get fractional part

    // Write integer part
    H_Lcd_WriteNumber(Local_s32_IntegerPart);

    // Write decimal point
    H_Lcd_WriteCharacter('.');

    // Convert fractional part to an integer for specified decimal places
    Local_f32_FractionPart *= 10 * Local_u8_NumDecimalPlaces;
    Local_s32_FractionAsInt = (s32)(Local_f32_FractionPart + 0.5); // Round to nearest

    // Write fractional part
    H_Lcd_WriteNumber(Local_s32_FractionAsInt);
}
void H_Lcd_Clr(void)
{
	H_Lcd_WriteCommand(LCD_CLEAR);
}
void H_Lcd_GoTo(u8 Local_u8_Row,u8 Local_u8_Col)
{
	u8 Local_u8_Arr[2] = {0x80,0xC0};
	H_Lcd_WriteCommand(Local_u8_Arr[Local_u8_Row] + Local_u8_Col);
}
void H_Lcd_ShiftRight(void)
{
	H_Lcd_WriteCommand(LCD_SHIFT_RIGHT);
}
void H_Lcd_ShiftLeftt(void)
{
	H_Lcd_WriteCommand(LCD_SHIFT_LEFT);
}
/*
void H_Lcd_CustomCharacterMoveToLeftFromTop(u8* Local_u8_CustomChar , u8 Local_u8_YPos)
{
	for(u8 Local_u8_Count=0 ; Local_u8_Count<=16 ; Local_u8_Count++)
	{
		H_Lcd_WriteCustomCharacter(Local_u8_CustomChar,0,0,Local_u8_YPos);
		H_Lcd_ShiftLeftt();
		_delay_ms(500);
		H_Lcd_Clr();
	}
}
void H_Lcd_CustomCharacterMoveToLeftFromDown(u8* Local_u8_CustomChar , u8 Local_u8_YPos)
{
	for(u8 Local_u8_Count=0 ; Local_u8_Count<=16 ; Local_u8_Count++)
	{
		H_Lcd_WriteCustomCharacter(Local_u8_CustomChar,0,1,Local_u8_YPos);
		H_Lcd_ShiftLeftt();
		_delay_ms(500);
		H_Lcd_Clr();
	}
}
*/

