/*
 * keypad.c
 *
 *  Created on: sept 9, 2023
 *      Author: Ahmed Gamal
 */

#include "../macro.h"


void Keypad_Init(void)
{
    CLR_BYTE(DIR);      // DIRECTORY IS EQUAL 0x00
    SET_LOW(DIR);       // DIRECTORY 0:3 OUT PINS
    SET_HIGH(PORT);     // INTERNAL PULLUP 4:7 PINS
}

byte Keypad_CheckPress(void)
{
    byte row, col, x, val = 0xFF;
    byte arr[4][4] = {{'7', '8', '9', '/'}, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, {'A', '0', '=', '+'}};

    for (row = 0; row < 4; row++)
    {
        SET_LOW(PORT);
        CLR_BIT(PORT, row);

        for (col = 0; col < 4; col++)
        {
            x = READ_BIT(PORT, (col + 4));
            if (x == 0)
            {
                val = arr[row][col];
                break;
            }
        }
        if (x == 0)
        {
            break;
        }
    }
    return val;
}
