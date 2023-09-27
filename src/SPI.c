/*
 * SPI.c
 *
 *  Created on: sept 22, 2023
 *      Author: Ahmed Gamal
 */

#include <avr/io.h>
#include "../macro.h"
#include "../SPI.h"

void SPI_MasterInit(void)
{
    SET_BIT(DIR, 4);
    SET_BIT(DIR, 5);
    SET_BIT(DIR, 7);

    SET_BIT(SPCR, MSTR);
    SET_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPE);
    SET_BIT(SPCR, SPIE);

    SET_BIT(PORT, 4);
}

void SPI_SlaveInit(void)
{
    SET_BIT(SPCR, SPE);
    SET_BIT(DIR, 6);
}

void SPI_MasterSendChar(byte data)
{
    CLR_BIT(PORT, 4);
    SET_BYTE(SPDR, data); // WRITE DATA IN SPDR RIGISTERS
    while(READ_BIT(SPSR, SPIF) == 0);
}

byte SPI_MasterTransmitChar(byte data)
{
    CLR_BIT(PORT, 4);
    SET_BYTE(SPDR, data); // WRITE DATA IN SPDR RIGISTERS
    while(READ_BIT(SPSR, SPIF) == 0);

    return SPDR;
}

void SPI_MasterSendString(byte *ptr)
{
    while ((*ptr) != 0) {
        SPI_MasterSendChar(*ptr);
        ptr++;
    }
}

void SPI_SlaveRecvChar(byte data)
{
    SET_BYTE(SPDR, data);   // WRITE DATA IN SPDR RIGISTERS
    while(READ_BIT(SPSR, SPIF) == 0);
}

byte SPI_SlaveReceiveChar(byte data)
{
    SET_BYTE(SPDR, data);   // WRITE DATA IN SPDR RIGISTERS
    while(READ_BIT(SPSR, SPIF) == 0);
    return SPDR;
}
