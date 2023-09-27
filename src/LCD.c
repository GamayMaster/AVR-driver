/*
 * LCD.c
 *
 * micro controller name: Atmega32
 *  Created on: Sep 18, 2023
 *      Author: Ahmed Gamal
 */

#include "macro.h"
#include "LCD.h"


void LCD_Init(void)
{
#if defined _8BIT_MODE
	SET_BYTE(LCD_DATA_DIR, 0xFF);
	SET_BIT(LCD_CTRL_DIR, E);
	SET_BIT(LCD_CTRL_DIR, RS);
	#if defined RW_PIN
	SET_BIT(LCD_CTRL_DIR, RW);
	#endif

	LCD_SendCommand(EIGHT_BIT_MODE);
	LCD_SendCommand(CURSOR_OFF);
	LCD_SendCommand(CLEAR_COMMAND);

#elif defined _4BIT_MODE
	#if defined LOW
	SET_LOW(LCD_DATA_DIR);
	#elif defined HIGH
	SET_HIGH(LCD_DATA_DIR);
	#else
	SET_BYTE(LCD_DATA_DIR, 0xFF);
	#endif

	SET_BIT(LCD_CTRL_DIR, E);
	SET_BIT(LCD_CTRL_DIR, RS);
	#if defined RW_PIN
	SET_BIT(LCD_CTRL_DIR, RW);
	#endif

	LCD_SendCommand(EIGHT_BIT_MODE);
	LCD_SendCommand(CURSOR_OFF);
	LCD_SendCommand(CLEAR_COMMAND);

#endif
}

void LCD_SendCommand(byte data)
{
	CLR_BIT(LCD_CTRL_PORT, RS);
	#if defined RW_PIN
	CLR_BIT(LCD_CTRL_PORT, RW);
	#endif
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);

	#if defined _8BIT_MODE
	SET_BYTE(LCD_DATA_PORT, data);

	#elif defined _4BIT_MODE

	#if defined LOW
	SET_BYTE(LCD_DATA_PORT, (data>>4));
	SET_BYTE(LCD_DATA_PORT, data);
	#elif defined HIGH
	SET_BYTE(LCD_DATA_PORT, data);
	SET_BYTE(LCD_DATA_PORT, (data<<4));
	#endif

	#endif

	_delay_ms(1);
	CLR_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
}

void LCD_SendChar(byte data)
{
	SET_BIT(LCD_CTRL_PORT, RS);
	#if defined RW_PIN
	CLR_BIT(LCD_CTRL_PORT, RW);
	#endif
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);

	#if defined _8BIT_MODE
	SET_BYTE(LCD_DATA_PORT, data);
	
	#elif defined _4BIT_MODE

	#if defined LOW
	SET_BYTE(LCD_DATA_PORT, (data>>4));
	SET_BYTE(LCD_DATA_PORT, data);
	#elif defined HIGH
	SET_BYTE(LCD_DATA_PORT, data);
	SET_BYTE(LCD_DATA_PORT, (data<<4));
	#endif

	#endif

	_delay_ms(1);
	CLR_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
}

void LCD_SendString(byte *str)
{
	while(*str != '\0')
	{
		LCD_SendChar(*str);
		str++;
	}
}

void LCD_GoToRowCol(byte row, byte col)
{
	byte address;
	switch (row)
	{
		case 0:
			address = col;
			break;
		case 1:
			address = col + 0x40;
			break;
	}
	LCD_SendCommand(address | SET_CURSOR_LOCATION);
}

void LCD_SendStringRowCol(byte row, byte col, byte *str)
{
	LCD_GoToRowCol(row,col);
	LCD_SendString(str);
}

void LCD_Int2Char(byte data)
{
	LCD_SendChar((data + 0x30));
}

void LCD_Int2Str(byte *data)
{
	while(*data != '\0')
	{
		LCD_SendChar((*data + 0x30));
		data++;
	}
}

void LCD_ClearScreen()
{
	LCD_SendCommand(CLEAR_COMMAND);
}
