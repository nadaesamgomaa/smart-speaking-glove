/*
 * Adc.h
 *
 *  Created on: Jul 18, 2024
 *      Author: Hp
 */

#ifndef HAL_ADC_HEADER_ADC_H_
#define HAL_ADC_HEADER_ADC_H_

/*************************************************_INCLUDES_********************************************/
#include "AdcCfg.h"
#include "../../../Common/StdTypes.h"
#include "../../../Common/BitMath.h"
#include "../../../Common/Reg.h"
#include "../../Dio/Header/Dio.h"
/**************************************************_MACROS_*********************************************/
#define AVCC         1
#define AREF_PIN     2
#define _2V56        3
#define ADC_INT      1
#define ADC_POL      2
/************************************************_PROTOTYPES_********************************************/
void M_Adc_Init(void);
u16  M_Adc_Read(u8);
//#endif

#endif /* HAL_ADC_HEADER_ADC_H_ */
