/*
 * EEPROM.c
 *
 *  Created on: sept 20, 2023
 *      Author: Ahmed Gamal
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include "../macro.h"
#include "../EEPROM.h"

void EEPROM_WriteByte(word addr, byte data)
{
    cli();
    SET_BYTE(EEARL, (char)addr);
    SET_BYTE(EEARH, (char)(addr>>8));
    SET_BYTE(EEDR, data);
    SET_BIT(EECR, EEMWE);
    SET_BIT(EECR, EEWE);

    while(READ_BIT(EECR, EEWE) == 1);
    sei();
}

byte EEPROM_ReadByte(word addr)
{
    cli();
    SET_BYTE(EEARL, (char)addr);
    SET_BYTE(EEARH, (char)(addr>>8));
    SET_BIT(EECR, EERE);

    return EEDR;
    sei();
}
