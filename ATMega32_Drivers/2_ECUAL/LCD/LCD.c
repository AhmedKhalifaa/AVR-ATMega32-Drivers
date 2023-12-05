/*
 * LCD.c
 *
 *      Author: Ahmed Khalifa
 */
#include <util/delay.h>
#include "../../0_Lib/STD_TYPES.h"
#include "../../0_Lib/BIT_MATH.h"
#include "../../1_MCAL/DIO/DIO.h"
#include "LCD.h"

static Std_ReturnType LCD_LatchEnable(const LCD_4Bit_t* LCD){
	Std_ReturnType ret = E_OK;
	if(NULL == LCD){
		ret = E_NOK;
	}
	else{
		ret = DIO_PinWriteLogic(&(LCD->LCD_ENPin), DIO_PIN_HIGH);
		_delay_us(5);
		ret = DIO_PinWriteLogic(&(LCD->LCD_ENPin), DIO_PIN_LOW);
	}
	return ret;
};

static Std_ReturnType LCD_4BitSendCommand(const LCD_4Bit_t* LCD, uint8_t cmd){
	Std_ReturnType ret=E_OK;

	if(NULL == LCD){
		ret=E_NOK;
	}
	else {
		ret = DIO_PinWriteLogic(&(LCD->LCD_RSPin),DIO_PIN_LOW);	//RS=0 To Send Command
		ret = DIO_PinWriteLogic(&(LCD->LCD_RWPin),DIO_PIN_LOW);	//RW=0 To Write to LCD

		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[0]),READ_BIT(cmd,4));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[1]),READ_BIT(cmd,5));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[2]),READ_BIT(cmd,6));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[3]),READ_BIT(cmd,7));

		ret = LCD_LatchEnable(LCD);

		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[0]),READ_BIT(cmd,0));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[1]),READ_BIT(cmd,1));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[2]),READ_BIT(cmd,2));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[3]),READ_BIT(cmd,3));

		ret = LCD_LatchEnable(LCD);
	}
	return ret;
};

Std_ReturnType LCD_4BitInit(const LCD_4Bit_t* LCD){
	uint8_t LCD_DataPinIndex=0;
	Std_ReturnType ret = E_OK;
	if(NULL == LCD){
		ret = E_NOK;
	}
	else{
		ret = DIO_PinIntialize(&(LCD->LCD_RSPin));
		ret = DIO_PinIntialize(&(LCD->LCD_ENPin));
		ret = DIO_PinIntialize(&(LCD->LCD_RWPin));
		for(LCD_DataPinIndex=0;LCD_DataPinIndex<4;LCD_DataPinIndex++){
			ret = DIO_PinIntialize(&(LCD->LCD_DataPins[LCD_DataPinIndex]));
		}
        _delay_ms(15);
		ret = LCD_4BitSendCommand(LCD, 0x33);
		_delay_ms(5);
		ret = LCD_4BitSendCommand(LCD, 0x32);
		_delay_us(150);
		ret = LCD_4BitSendCommand(LCD, 0x38);
		ret = LCD_4BitSendCommand(LCD, 0x01);
		ret = LCD_4BitSendCommand(LCD, 0x02);
		ret = LCD_4BitSendCommand(LCD, 0x06);
		ret = LCD_4BitSendCommand(LCD, 0x0C);
		ret = LCD_4BitSendCommand(LCD, 0x28);
		ret = LCD_4BitSendCommand(LCD, 0x80);

		/*		_delay_us(2000);
		ret = LCD_4BitSendCommand(LCD, LCD_DISP_ON_CURS_OFF);
		_delay_ms(1);
		ret = LCD_4BitSendCommand(LCD, LCD_CURS_INC);
		_delay_ms(5);
		ret = LCD_4BitSendCommand(LCD, LCD_DISP_CLR);
		_delay_ms(2);
		ret = LCD_4BitSendCommand(LCD, LCD_CURS_FIRST_LINE);
		_delay_ms(5);
*/	}
	return ret;
};

Std_ReturnType LCD_4BitClearDisplay(const LCD_4Bit_t* LCD){
	Std_ReturnType ret = E_OK;
	if(NULL == LCD){
		ret = E_NOK;
	}
	else{
		ret = LCD_4BitSendCommand(LCD, LCD_DISP_CLR);
		_delay_ms(2);
	}
	return ret;
};

Std_ReturnType LCD_4BitWriteCharacter(const LCD_4Bit_t* LCD, uint8_t character)
{
	Std_ReturnType ret = E_OK;
	if(NULL == LCD){
		ret = E_NOK;
	}
	else {
		ret = DIO_PinWriteLogic(&(LCD->LCD_RSPin),DIO_PIN_HIGH); //RS=1 to Send Data.
		ret = DIO_PinWriteLogic(&(LCD->LCD_RWPin),DIO_PIN_LOW);  //RW=0 to Write to LCD.

		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[0]),READ_BIT(character,4));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[1]),READ_BIT(character,5));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[2]),READ_BIT(character,6));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[3]),READ_BIT(character,7));

		ret = LCD_LatchEnable(LCD);

		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[0]),READ_BIT(character,0));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[1]),READ_BIT(character,1));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[2]),READ_BIT(character,2));
		ret = DIO_PinWriteLogic(&(LCD->LCD_DataPins[3]),READ_BIT(character,3));

		ret = LCD_LatchEnable(LCD);
	}
	return ret;
}


Std_ReturnType LCD_4BitWriteString(const LCD_4Bit_t* LCD, const uint8_t* string){
	Std_ReturnType ret = E_OK;
	uint8_t character_index=0;
	if(NULL == LCD){
		ret = E_NOK;
	}
	else{
		while(string[character_index]){
			ret = LCD_4BitWriteCharacter(LCD,string[character_index]);
			character_index++;
		}
	}
	return ret;
}
