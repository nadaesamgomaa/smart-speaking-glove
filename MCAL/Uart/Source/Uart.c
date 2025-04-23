#include"../Header/Uart.h"

void UART_Init(unsigned int ubrr) {
    // Set baud rate
    UBRRH = (unsigned char)(ubrr >> 8);
    UBRRL = (unsigned char)ubrr;

    // Enable receiver and transmitter
    UCSRB = (1 << RXEN) | (1 << TXEN);

    // Set frame format: 8 data bits, 1 stop bit, no parity
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void UART_Transmit(u8 data) {
    // Wait for empty transmit buffer
    while (!(UCSRA & (1 << UDRE)));

    // Put data into buffer, sends the data
    UDR = data;
}

u8 UART_Receive(void) {
    // Wait for data to be received
    while (!(UCSRA & (1 << RXC)));

    // Get and return received data from buffer
    return UDR;
}

void UART_TransmitString(char* str) {
    while (*str) {
        UART_Transmit(*str++);
    }
}
void UART_ReceiveString(char* buffer, u8 maxLength) {
    u8 i = 0;
    char received;
    while (i < maxLength - 1) {
        received = UART_Receive();
        if (received == '\n' || received == '\r') {  // End on newline
            break;
        }
        buffer[i++] = received;
    }
    buffer[i] = '\0';  // Null-terminate
}
