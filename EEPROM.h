/*
 * EEPROM.h
 *
 *  Created on: sept 20, 2023
 *      Author: Ahmed Gamal
 */

#ifndef EEPROM_H
#define EEPROM_H

#include "macro.h"

void EEPROM_WriteByte(word addr, byte data);
byte EEPROM_ReadByte(word addr);

#endif
