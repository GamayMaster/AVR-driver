/*
 * USART.c
 *
 *  Created on: sept 25, 2023
 *      Author: Ahmed Gamal
 */

#include <avr/io.h>
#include "../macro.h"

// Asyn double speed
void UART_Init(dword baud)
{
    word UBRR;
    UBRR    = ((F_CPU / 8 * baud) - 1);
    UBRRH   = (byte)(UBRR>>8);
    UBRRL   = (byte)UBRR;

    SET_BIT(UCSRB, TXEN);
    SET_BIT(UCSRB, RXEN);

    SET_BIT(UCSRC, UCSZ0);
    SET_BIT(UCSRC, UCSZ1);
    SET_BIT(UCSRC, URSEL);
}

void UART_SendByte(byte data)
{
    while (READ_BIT(UCSRA, UDRE) == 0);
    UDR = data;
}

byte UART_RecvByte(void)
{
    while (READ_BIT(UCSRA, RXC) == 0);
    return UDR;
}
