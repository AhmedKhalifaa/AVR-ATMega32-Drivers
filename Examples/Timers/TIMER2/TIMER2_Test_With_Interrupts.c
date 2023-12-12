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
#include "../1_MCAL/TIMERS/TIMER2/TIMER2.h"
#include "../2_ECUAL/LCD/LCD.h"
#include "../2_ECUAL/LED/LED.h"
#include "util/delay.h"
#include <stdlib.h>

LED_t Red_LED = {DIO_PORTB, DIO_PIN0, LED_ON};
LED_t Blue_LED = {DIO_PORTB, DIO_PIN3, LED_OFF};
static uint16_t OverFlows = 0;
void TIMER2_Test(void);
int main(){
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
	TIMER2_Cfg_t TIMER2 = {	.TIMER2_Clock = TIMER2_CLOCK_DIV_1,
							.TIMER2_OperationMode = TIMER2_OPERATION_MODE_NORMAL,
							.TIMER2_OutputCompare_Mode = TIMER2_OUTPUT_COMPARE_MODE_CLEAR_ON_COMPARE_MATCH};
	TIMER2_Initialize(&TIMER2);
	//TIMER2_SetPWMDutyCycle(&TIMER2, 50);
	LED_Initialize(&Red_LED);
	LED_Initialize(&Blue_LED);
	uint8_t TIMER2_Value = 0;
	uint8_t TIMER2_ValueString[5];
	TIMER2_SetOverFlowCallBacK(&TIMER2, TIMER2_Test);
	SEI();
	TIMER2_EnableOverFlowInterrupt();
		while(1){

	}
}

void TIMER2_Test(void){
	if(OverFlows<3922){
		OverFlows+=1;
	}
	else{
		LED_Toggle(&Red_LED);
		LED_Toggle(&Blue_LED);
		OverFlows=0;
	}
}
