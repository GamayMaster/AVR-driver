/*
 * USART.h
 *
 *  Created on: sept 25, 2023
 *      Author: Ahmed Gamal
 */

#ifndef USART_H
#define USART_H

#include "macro.h"

//UCSRA
#define MPCM    0
#define U2X     1
#define PE      2
#define DOR     3
#define FE      4
#define UDRE    5   // 1 is empty or 0 is not empty 
#define TXC     6   // 1 is empty or 0 is not empty (write)
#define RXC     7   // 1 is not empty or 0 is empty (read)
// UCSRB
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7
// UCSRC
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL   6
#define URSEL   7

void UART_Init(dword baud);
void UART_SendByte(byte data);
byte UART_RecvByte(void);

#endif
