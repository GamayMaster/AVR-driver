/*
 * LCD.h
 *
 *  Created on: sept 9, 2023
 *      Author: Ahmed Gamal
 */

#ifndef LCD_H_
#define LCD_H_

#include "macro.h"

/*
 * How to use a library LCD
 * LCD_DATA_DIR     DIRECTORY OUT DATA
 * LCD_CTRL_DIR     DIRECTORY OUT CONTROL DATA IN LCD
 * LCD_DATA_PORT    THIS PORT TO WRITE DATA ON PINS
 * LCD_CTRL_PORT    THIS PORT TO WRITE CONTROL DATA ON PINS
 * E                ENABLE PULS CLOCK
 * RS               CONTROL THIS DATA 0 ==> COMMAND OR 1 ==> CHAR DATA
 * RW               CONTROL THIS DATA 0 ==> WRITE OR 1 ==> READ
 * _8BIT_MODE       TOTAL PINS === 8 PIN DATA
 * _4BIT_MODE       TOTAL PINS === 4 PIN DATA
 * LOW              PINS 0:3 FORM PORT
 * HIGH             PINS 4:7 FROM PORT
 * RW_PIN           KNOWN CONNECT PIN RW FOR CONTROLLING
 * Example:-
 * #define LCD_DATA_DIR     DDRA
 * #define LCD_CTRL_DIR     DDRB
 * #define LCD_DATA_PORT    PORTA
 * #define LCD_DATA_PORT    PORTB
 * #define E                0
 * #define RW               1
 * #define RS               2
 * 
*/

#define EIGHT_BIT_MODE      0x38
#define FOUR_BIT_MODE       0x28
#define CLEAR_COMMAND       0x01
#define CURSOR_OFF          0x0C
#define CURSOR_ON           0x0E
#define SET_CURSOR_LOCATION 0x80

void LCD_Init(void);
void LCD_SendCommand(byte data);
void LCD_SendChar(byte data);
void LCD_SendString(byte *str);
void LCD_GoToRowCol(byte row, byte col);
void LCD_SendStringRowCol(byte row, byte col, byte *str);
void LCD_Int2Char(byte data);
void LCD_Int2Str(word data);
void LCD_ClearScreen();

#endif
