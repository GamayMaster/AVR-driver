/*
 * SPI.h
 *
 *  Created on: sept 22, 2023
 *      Author: Ahmed Gamal
 */

#ifndef SPI_H
#define SPI_H

#include "macro.h"

/*
 * How to use a library LCD
 * DIR      DIRECTORY TO CONNECT PINS WITH KEYPAD PINS
 * PORT     THIS PORT WRITE DATA
 * Example:-
 * #define DIR      DDRA
 * #define PORT     PORTA
*/

#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPI2X   0
#define WCOL    6
#define SPIF    7


void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_MasterSendChar(byte data);
byte SPI_MasterTransmitChar(byte data);
void SPI_MasterSendString(byte *ptr);
void SPI_SlaveRecvChar(byte data);
byte SPI_SlaveReceiveChar(byte data);

#endif
