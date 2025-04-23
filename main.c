#include "HAL/Lcd/Header/Lcd.h"
#include "MCAL/Adc/Header/Adc.h"
#include "MCAL/Uart/Header/Uart.h"
#include "HAL/CustomChar/Header/CustomChar.h"
#include "HAL/FlexSensor/Header/FlexSensor.h"
#include <util/delay.h>
#include <string.h>  // Include this for strcmp
#define F_CPU 8000000UL  // 8 MHz
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1



int main(void) {
	setup();

	u16 FlexSensorRead1=0 ,FlexSensorRead2=0 ,FlexSensorRead3=0 ,FlexSensorRead4=0 ,FlexSensorRead5=0;
	float bend1=0 ,bend2=0 ,bend3=0 ,bend4=0 ,bend5=0;
	char buffer[20];  // enough for short words

    while (1) {
    	  FlexSensorRead1 = M_Adc_Read(1);
    	  _delay_ms(10);
    	  FlexSensorRead2 = M_Adc_Read(2);
    	  _delay_ms(10);
    	  FlexSensorRead3 = M_Adc_Read(3);
    	  _delay_ms(10);
    	  FlexSensorRead4 = M_Adc_Read(4);
    	  _delay_ms(10);
    	  FlexSensorRead5 = M_Adc_Read(5);
    	  _delay_ms(10);

    	  bend1 = get_flex_bending_angle(FlexSensorRead1);
    	  _delay_ms(10);
    	  bend2 = get_flex_bending_angle(FlexSensorRead2);
    	  _delay_ms(10);
    	  bend3 = get_flex_bending_angle(FlexSensorRead3);
    	  _delay_ms(10);
    	  bend4 = get_flex_bending_angle(FlexSensorRead4);
    	  _delay_ms(10);
    	  bend5 = get_flex_bending_angle(FlexSensorRead5);
    	  _delay_ms(10);

    	UART_TransmitBendData(bend1, bend2, bend3, bend4, bend5);
        UART_ReceiveString(buffer, 20);  // receive full string
        ConvertFromFancToArb(buffer);    // pass string to your function
    }

    return 0;
}

void setup()
{
 M_Adc_Init();
 UART_Init(MYUBRR);
 H_Lcd_Init();
}
void ConvertFromFancToArb(char* Local_u8_Str)
{
    if (strcmp(Local_u8_Str, "2na") == 0)
    {
        H_Lcd_Clr();
        H_CustomChar_WriteAna();
        _delay_ms(1000);
    }
    else if (strcmp(Local_u8_Str, "27b") == 0)
    {
        H_Lcd_Clr();
        H_CustomChar_WriteAoheb();
        _delay_ms(1000);
    }
    else if (strcmp(Local_u8_Str, "Gid") == 0)
    {
        H_Lcd_Clr();
        H_CustomChar_WriteGaed();
        _delay_ms(1000);
    }
    else if (strcmp(Local_u8_Str, "8al") == 0)
    {
        H_Lcd_Clr();
        H_CustomChar_WriteKhal();
        _delay_ms(1000);
    }
    else if (strcmp(Local_u8_Str, "Al27d") == 0)
    {
        H_Lcd_Clr();
        H_CustomChar_WriteAL_Ahed();
        _delay_ms(1000);
    }
    else
    {
        H_Lcd_Clr();
        H_Lcd_WriteString("detect");
    }
}
void UART_TransmitString(const char* str) {
    while (*str) {
        UART_Transmit(*str++);
    }
}
