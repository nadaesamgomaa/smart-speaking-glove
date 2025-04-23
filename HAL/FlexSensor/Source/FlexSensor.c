#include "../Header/FlexSensor.h"

void H_FlexSensor_Init()
{
	M_Adc_Init();
}
float get_flex_bending_angle(uint16_t adc_value) {
    // Calculate the voltage from the ADC value
    float v_out = (adc_value / (float)ADC_RESOLUTION) * V_REF;

    // Calculate flex sensor resistance
    float r_flex = (v_out * fixed_resistor) / (V_REF - v_out);

    // Map resistance to bending angle
    if (r_flex <= FLEX_MIN_RESISTANCE) {
        return 0.0; // Flat position
    } else if (r_flex >= FLEX_MAX_RESISTANCE) {
        return 90.0; // Fully bent
    } else {
        // Linear mapping between 0° and 90°
        return ((r_flex - FLEX_MIN_RESISTANCE) * 90.0 /
                         (FLEX_MAX_RESISTANCE - FLEX_MIN_RESISTANCE));
    }
}

void signword(u8 Local_u8_bend1,u8 Local_u8_bend2 ,u8 Local_u8_bend3 ,u8 Local_u8_bend4 ,u8 Local_u8_bend5)
{
	if((Local_u8_bend1>=88 && Local_u8_bend1<=90 ) && (Local_u8_bend2>=0 && Local_u8_bend2<=90) && (Local_u8_bend3>=70 && Local_u8_bend3<=90) && Local_u8_bend4==90 && Local_u8_bend5==0)
	{
		H_CustomChar_WriteAna();
		_delay_ms(1000);
		H_Lcd_Clr();
	}
	else if((Local_u8_bend1>=0 && Local_u8_bend1<=35) && (Local_u8_bend2>=78 && Local_u8_bend2<=90) && (Local_u8_bend3>=71 && Local_u8_bend3<=90) && Local_u8_bend4==90 && Local_u8_bend5==0)
	{
		H_CustomChar_WriteGaed();
		_delay_ms(1000);
		H_Lcd_Clr();
	}
	else if((Local_u8_bend1>=89 && Local_u8_bend1<=90) && (Local_u8_bend2>=10 && Local_u8_bend2<=90 ) && (Local_u8_bend3>=46 && Local_u8_bend3<=85 ) && (Local_u8_bend4>=89 && Local_u8_bend4<=90) && Local_u8_bend5==0)
	{
		H_CustomChar_WriteKhal();
		_delay_ms(1000);
		H_Lcd_Clr();
	}
	else if((Local_u8_bend1>=36 && Local_u8_bend1<=87) && (Local_u8_bend2>=0 && Local_u8_bend2<=90) && ( Local_u8_bend3==90) && (Local_u8_bend4>=84 && Local_u8_bend4<=90) && Local_u8_bend5==0)
	{
		H_CustomChar_WriteAoheb();
		_delay_ms(1000);
		H_Lcd_Clr();
	}
	else if((Local_u8_bend1>=80 && Local_u8_bend1<=90) && (Local_u8_bend2>=80 && Local_u8_bend2<=90) && (Local_u8_bend3>=0 && Local_u8_bend3<=45) && (Local_u8_bend4>=89 && Local_u8_bend4<=90) && Local_u8_bend5==0)
	{
		H_CustomChar_WriteAL_Ahed();
		_delay_ms(1000);
		H_Lcd_Clr();
	}
	else
	{
		H_Lcd_WriteCharacter('-');
		_delay_ms(1000);
		H_Lcd_Clr();
	}
}

