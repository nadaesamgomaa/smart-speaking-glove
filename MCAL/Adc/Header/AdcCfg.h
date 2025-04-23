/*
 * AdcCfg.h
 *
 *  Created on: Jul 18, 2024
 *      Author: Hp
 */

#ifndef HAL_ADC_HEADER_ADCCFG_H_
#define HAL_ADC_HEADER_ADCCFG_H_

/*******************************************_SELECT_ADC_OPERATION_MODE_********************************************/
// option 1 -> [ ADC_INT ]
// option 1 -> [ ADC_POL ]
#define ADC_OPERATION_MODE        ADC_POL
/*********************************************_SELECT_VREF_********************************************/
// option 1 -> [ AVCC     ]
// option 2 -> [ AREF_PIN ]
// option 3 -> [ _2V56    ]
#define VREF                 AVCC

#endif /* HAL_ADC_HEADER_ADCCFG_H_ */

