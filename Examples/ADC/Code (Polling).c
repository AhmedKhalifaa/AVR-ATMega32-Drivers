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
#include "../2_ECUAL/LCD/LCD.h"
#include "../2_ECUAL/LED/LED.h"
#include "util/delay.h"

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
		while(!READ_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADSC_BIT)){
			ADC_StartConversion();
			_delay_us(20);
			ADC_ReadResult(&LM35_Sensor, &temperature);
			if(temperature>=640){
				LCD_4BitWriteString(&My_LCD, (uint8_t*)"Too Hot!");
			}
			else if(temperature<384){
				LCD_4BitWriteString(&My_LCD, (uint8_t*)"Too Cold!");
			}
			else{
				LCD_4BitWriteString(&My_LCD, (uint8_t*)"Just Right + Cozy!");
		}
		_delay_ms(1000);
		temperature = 0;
		LCD_4BitClearDisplay(&My_LCD);
	}
}
