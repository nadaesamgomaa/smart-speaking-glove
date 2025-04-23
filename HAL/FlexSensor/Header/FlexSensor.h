#ifndef HAL_FLEXSENSOR_HEADER_FLEXSENSOR_H_
#define HAL_FLEXSENSOR_HEADER_FLEXSENSOR_H_

/*************************************************_INCLUDES_********************************************/
#include "FlexSensorCfg.h"
#include "../../../Common/StdTypes.h"
#include "../../../MCAL/Adc/Header/Adc.h"
#include "../../CustomChar/Header/CustomChar.h"
/**************************************************_MACROS_*********************************************/

/***********************************************_PROTOTYPES_********************************************/
void H_FlexSensor_Init();
float get_flex_bending_angle(uint16_t);
void signword(u8,u8,u8,u8,u8);
#endif /* HAL_FLEXSENSOR_HEADER_FLEXSENSOR_H_ */
