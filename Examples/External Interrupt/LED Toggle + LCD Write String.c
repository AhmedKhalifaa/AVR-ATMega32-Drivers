/*
 * app.c
 *
 *      Author: Ahmed Khalifa
 */
#include "../0_Lib/STD_TYPES.h"
#include "../0_Lib/BIT_MATH.h"
#include "../1_MCAL/DIO/DIO.h"
#include "../2_ECUAL/LCD/LCD.h"
#include "../2_ECUAL/LED/LED.h"
#include "../1_MCAL/INTERRUPTS/GLOB_INT.h"
#include "../1_MCAL/INTERRUPTS/EXTINT.h"
#include "util/delay.h"

void InterruptsTest_LEDToggle(void);
LED_t Red_LED = {DIO_PORTB, DIO_PIN0, LED_ON};

int main(){
	LED_t Blue_LED = {DIO_PORTD, DIO_PIN7, LED_ON};
	LCD_4Bit_t My_LCD = {.LCD_RSPin = {DIO_PORTD, DIO_PIN0, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_RWPin = {DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_ENPin = {DIO_PORTD, DIO_PIN2, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_DataPins[0] = {DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_DataPins[1] = {DIO_PORTA, DIO_PIN1, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_DataPins[2] = {DIO_PORTA, DIO_PIN2, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_DataPins[3] = {DIO_PORTA, DIO_PIN3, DIO_PIN_OUTPUT, DIO_PIN_LOW}};

void InterruptsTest_LEDToggle(void){
	LED_Toggle(&Red_LED);
	LCD_4BitClearDisplay(&My_LCD);
	LCD_4BitWriteString(&My_LCD,"Holy Roman Empire XD");
}
	EXTINT_InterruptConfig_t External_Interrupt2 = {.EXTINT_PinCfg = {DIO_PORTB, DIO_PIN2, DIO_PIN_INPUT, DIO_PIN_LOW},
													.EXTINT_InterruptID = 2,
													.EXTINT_InterruptStatus = EXTINT_ENABLED,
													.EXTINT_InterruptTrigger = EXTINT_TRIGGER_ON_RISING_EDGE};
	SEI();
	LCD_4BitInit(&My_LCD);
	LED_Initialize(&Blue_LED);
	LED_Initialize(&Red_LED);
	EXTINT_Initialize(&External_Interrupt2);
	EXTINT_Enable(&External_Interrupt2);
	EXTINT_SetCallBack(&External_Interrupt2, &InterruptsTest_LEDToggle);
	while(1){
		LED_Toggle(&Blue_LED);
		_delay_ms(500);
	}

	return 0;
}