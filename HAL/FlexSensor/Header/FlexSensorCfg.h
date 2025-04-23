/*
 * FlexSensorCfg.h
 *
 *  Created on: Aug 9, 2024
 *      Author: Hp
 */

#ifndef HAL_FLEXSENSOR_HEADER_FLEXSENSORCFG_H_
#define HAL_FLEXSENSOR_HEADER_FLEXSENSORCFG_H_

/*******************************************_SELECT_DELAY_TIME_********************************************/

/*********************************************_SELECT_LED_PIN_********************************************/

#define V_REF 5.0           // Reference voltage for ADC
#define ADC_RESOLUTION 1024 // 10-bit ADC resolution
#define FLEX_MIN_RESISTANCE 25000  // Resistance at 0° (25kΩ)
#define FLEX_MAX_RESISTANCE 50000  // Resistance at 90° (50kΩ)
#define fixed_resistor      10000


#endif /* HAL_FLEXSENSOR_HEADER_FLEXSENSORCFG_H_ */
