/*
 * Uart.h
 *
 *  Created on: Feb 16, 2025
 *      Author: Hp
 */

#ifndef MCAL_UART_HEADER_UART_H_
#define MCAL_UART_HEADER_UART_H_

/*************************************************_INCLUDES_********************************************/
#include"UartCfg.h"
#include"../../../Common/Reg.h"
#include"../../../Common/Bitmath.h"
#include"../../../Common/StdTypes.h"
#include <avr/io.h>
#include <avr/interrupt.h>
/**************************************************_MACROS_*********************************************/
#define PARITY_DISABLE            1
#define PARITY_ODD                2
#define PARITY_EVEN               3
/************************************************_PROTOTYPES_********************************************/
void UART_Init(unsigned int);
void UART_Transmit(u8);
u8   UART_Receive(void);
void UART_TransmitString(char *);
void UART_ReceiveString(char* , u8 );
#endif /* MCAL_UART_HEADER_UART_H_ */
