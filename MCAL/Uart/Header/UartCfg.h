/*
 * UartCfg.h
 *
 *  Created on: Feb 16, 2025
 *      Author: Hp
 */

#ifndef MCAL_UART_HEADER_UARTCFG_H_
#define MCAL_UART_HEADER_UARTCFG_H_

/***************************************************_SELECT_F_OSC_******************************************/
#define F_OSC                             8
/*************************************************_SELECT_BAUD_RATE_******************************************/
#define BAUD_RATE                        9600
/************************************************_SELECT_PARITY_MODE_******************************************/
//option 1 -> [ PARITY_DISABLE ]
//option 2 -> [ PARITY_ODD     ]
//option 3 -> [ PARITY_EVEN    ]
#define PARITY_MODE                 PARITY_DISABLE

#endif /* MCAL_UART_HEADER_UARTCFG_H_ */
