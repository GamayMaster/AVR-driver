/*
 * keypad.h
 *
 *  Created on: sept 9, 2023
 *      Author: Ahmed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "macro.h"

/*
 * How to use a library LCD
 * DIR      DIRECTORY TO CONNECT PINS WITH KEYPAD PINS
 * PORT     THIS PORT WRITE DATA
 * Example:-
 * #define DIR      DDRA
 * #define PORT     PORTA
*/

void Keypad_Init(void);
byte Keypad_CheckPress(void);

#endif  
