/*
 * Reg.h
 *
 *  Created on: Jul 1, 2024
 *      Author: Hp
 */

#ifndef REG_H_
#define REG_H_
/*************************************_DIO_REGISTERS_*********************************/

#define DDRA  *((volatile u8*)0x3A)
#define DDRB  *((volatile u8*)0x37)
#define DDRC  *((volatile u8*)0x34)
#define DDRD  *((volatile u8*)0x31)

#define PORTA *((volatile u8*)0x3B)
#define PORTB *((volatile u8*)0x38)
#define PORTC *((volatile u8*)0x35)
#define PORTD *((volatile u8*)0x32)

#define PINA  *((volatile u8*)0x39)
#define PINB  *((volatile u8*)0x36)
#define PINC  *((volatile u8*)0x33)
#define PIND  *((volatile u8*)0x30)
/*************************************_SREG_REGISTER_*********************************/
#define SREG  *((volatile u8*)0x5F)
/*************************************_EXT_INT_REGISTERS_*********************************/
#define MCUCR *((volatile u8*)0x55)
#define GICR  *((volatile u8*)0x5B)
/*************************************_ADC_REGISTERS_*********************************/
#define ADMUX       *((volatile u8*)0x27)
#define ADCSRA		*((volatile u8*)0x26)
#define ADCH		*((volatile u8*)0x25)
#define ADCL		*((volatile u8*)0x24)
#define ADC_VALUE        *((volatile u16*)0x24)
#define SFIOR		*((volatile u8*)0x50)
/*************************************_TIMER0_REGISTERS_*********************************/
#define TCNT0      *((volatile u8*)0x52)
#define TCCR0      *((volatile u8*)0x53)
#define TIMSK      *((volatile u8*)0x59)
#define OCR0       *((volatile u8*)0x5C)
/*************************************_TIMER1_REGISTERS_*********************************/
#define TCNT1      *((volatile u16*)0x4C)
#define TCCR1A     *((volatile u8*)0x4F)
#define TCCR1B     *((volatile u8*)0x4E)
#define OCR1A      *((volatile u16*)0x4A)
#define OCR1B      *((volatile u16*)0x48)
#define ICR1       *((volatile u16*)0x46)

#define COM1A1     7
/*************************************_WDT_REGISTERS_*********************************/
#define WDTCR      *((volatile u16*)0x41)
/*************************************_UART_REGISTERS_*********************************/
#define UDR        *((volatile u16*)0x2C)
#define UCSRA      *((volatile u16*)0x2B)
#define UCSRB      *((volatile u16*)0x2A)
#define UCSRC      *((volatile u16*)0x40)
#define UBRRL      *((volatile u16*)0x29)
#define UBRRH      *((volatile u16*)0x40)
#define WDTCR      *((volatile u16*)0x41)
/*************************************_SPI_REGISTERS_*********************************/
#define SPCR       *((volatile u16*)0x2D)
#define SPDR       *((volatile u16*)0x2F)
#define SPSR       *((volatile u16*)0x2E)

#endif /* REG_H_ */
