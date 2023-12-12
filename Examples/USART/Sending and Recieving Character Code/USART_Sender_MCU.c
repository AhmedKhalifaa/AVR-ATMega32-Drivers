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
#include "../1_MCAL/USART/USART.h"
#include "../2_ECUAL/LCD/LCD.h"
#include "../2_ECUAL/LED/LED.h"
#include "util/delay.h"
#include <stdlib.h>

LED_t Red_LED = {DIO_PORTB, DIO_PIN0, LED_ON};
LED_t Blue_LED = {DIO_PORTD, DIO_PIN7, LED_OFF};
int main(){
	LCD_4Bit_t My_LCD = {.LCD_RSPin = {DIO_PORTD, DIO_PIN4, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_RWPin = {DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT, DIO_PIN_LOW},
						 .LCD_ENPin = {DIO_PORTD, DIO_PIN6, DIO_PIN_OUTPUT, DIO_PIN_LOW},
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
	USART_Cfg_t USART_Cfg = {.USART_BaudRate = 4800,
							 .USART_CharacterSize = USART_CHARACTER_SIZE_8BITS,
							 .USART_OperationMode = USART_OPERATION_MODE_ASYNCHRONOUS,
							 .USART_ParityMode = USART_PARITY_MODE_ODD_PARITY,
							 .USART_CommunicationMode = USART_COMMUNICATION_MODE_SINGLE_PROCESSOR,
							 .USART_ClockPolarity = USART_CLOCK_POLARITY_TRANSMIT_ON_RISING_EDGE,
							 .USART_StopBit = USART_STOP_BITS_1BIT,
							 .USART_TransmissionMode = USART_TRANSMISSION_MODE_FULL_DUPLEX,
							 .USART_TransmissionSpeed = USART_TRANSMISSION_SPEED_NORMAL
	};
	uint16_t temperature = 0;
	uint16_t Rx_Buffer;
	LCD_4BitInit(&My_LCD);
	ADC_Initialize(&LM35_Sensor);
	TIMER0_Cfg_t TIMER0 = {	.TIMER0_Clock = TIMER0_CLOCK_DIV_1,
							.TIMER0_OperationMode = TIMER0_OPERATION_MODE_NORMAL,
							.TIMER0_OutputCompare_Mode = TIMER0_OUTPUT_COMPARE_MODE_CLEAR_ON_COMPARE_MATCH};
	TIMER0_Initialize(&TIMER0);
	LED_Initialize(&Red_LED);
	LED_Initialize(&Blue_LED);
	USART_Initialize(&USART_Cfg);
	uint16_t USART_Buffer[10];
	//SEI();
		while(1){
			USART_WriteByteBlocking(&USART_Cfg, 'A');
	}
}
