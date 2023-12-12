/*
 * app.c
 *
 *      Author: Ahmed Khalifa
 */
#include "../0_Lib/STD_TYPES.h"
#include "../0_Lib/BIT_MATH.h"
#include "../1_MCAL/DIO/DIO.h"
#include "../1_MCAL/INTERRUPTS/GLOB_INT.h"
#include "../1_MCAL/INTERRUPTS/EXTINT.h"
#include "../1_MCAL/ADC/ADC.h"
#include "../1_MCAL/TIMERS/TIMER0/TIMER0.h"
#include "../2_ECUAL/LCD/LCD.h"
#include "../2_ECUAL/LED/LED.h"
#include "util/delay.h"
#include <stdlib.h>

int main(){
	LED_t Red_LED = {DIO_PORTB, DIO_PIN0, LED_ON};
	LED_t Blue_LED = {DIO_PORTD, DIO_PIN7, LED_ON};
	LCD_4Bit_t My_LCD = {.LCD_RSPin = {DIO_PORTD, DIO_PIN0, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_RWPin = {DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_ENPin = {DIO_PORTD, DIO_PIN2, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_DataPins[0] = {DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_DataPins[1] = {DIO_PORTA, DIO_PIN1, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_DataPins[2] = {DIO_PORTA, DIO_PIN2, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_DataPins[3] = {DIO_PORTA, DIO_PIN3, DIO_PIN_OUTPUT, DIO_PIN_LOW}};
	ADC_Cfg_t LM35_Sensor = {.ADC_Channel = ADC_CHANNEL_ADC7,
							 .ADC_Prescaler = ADC_PRESCALER_DIV_1,
							 .ADC_TriggerSource = ADC_TRIGGER_SOURCE_FREE_RUNNING,
							 .ADC_VoltageReference = ADC_VOLTAGE_AVCC,
							 .ADC_AutoTriggerStatus = ADC_AUTOTRIGGER_ENABLED,
							 .ADC_ResultAdjust = ADC_RIGHT_ADJUST};
	uint16_t temperature = 0;
	LCD_4BitInit(&My_LCD);
	ADC_Initialize(&LM35_Sensor);
	TIMER0_Cfg_t TIMER0 = {	.TIMER0_Clock = TIMER0_CLOCK_DIV_1024,
							.TIMER0_OperationMode = TIMER0_OPERATION_MODE_NORMAL,
							.TIMER0_OutputCompare_Mode = TIMER0_OUTPUT_COMPARE_MODE_CLEAR_ON_COMPARE_MATCH};
	TIMER0_Initialize(&TIMER0);
	uint8_t Timer0_Value = 0;
	uint8_t Timer0_ValueString[5];
	itoa(Timer0_Value, Timer0_ValueString, 10);
		while(sizeof(TIMER0_Cfg_t) == 1){
			TIMER0_GetTimerValue(&TIMER0, &Timer0_Value);
			itoa(Timer0_Value, Timer0_ValueString, 10);
			LCD_4BitWriteString(&My_LCD, Timer0_ValueString);
			//_delay_ms(500);
			LCD_4BitClearDisplay(&My_LCD);
	}
}

