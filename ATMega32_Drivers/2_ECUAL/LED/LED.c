/*
 * LED.c
 *
 *      Author: Ahmed Khalifa
 */

#include "../../0_Lib/STD_TYPES.h"
#include "../../0_Lib/BIT_MATH.h"
#include "../../1_MCAL/DIO/DIO.h"
#include "LED.h"

Std_ReturnType LED_Initialize(const LED_t *LED){
	Std_ReturnType ret = E_OK;
	if(NULL == LED || ((LED->PortID)>MAX_PORT_ID) || ((LED->PinID)>MAX_PIN_ID)){
		ret = E_NOK;
	}
	else{
		DIO_PinCfg_t LED_Pin = {LED->PortID, LED->PinID, DIO_PIN_OUTPUT, LED->LED_Status};
		DIO_PinIntialize(&LED_Pin);
	}
	return ret;
};


Std_ReturnType LED_TurnOn(LED_t *LED){
	Std_ReturnType ret = E_OK;
	if(NULL == LED || ((LED->PortID)>MAX_PORT_ID) || ((LED->PinID)>MAX_PIN_ID)){
		ret = E_NOK;
	}
	else{
		DIO_PinCfg_t LED_Pin = {LED->PortID, LED->PinID, DIO_PIN_OUTPUT, LED->LED_Status};
		DIO_PinWriteLogic(&LED_Pin, DIO_PIN_HIGH);
		LED->LED_Status = LED_ON;
	}
	return ret;
};


Std_ReturnType LED_TurnOff(LED_t *LED){
	Std_ReturnType ret = E_OK;
	if(NULL == LED || ((LED->PortID)>MAX_PORT_ID) || ((LED->PinID)>MAX_PIN_ID)){
		ret = E_NOK;
	}
	else{
		DIO_PinCfg_t LED_Pin = {LED->PortID, LED->PinID, DIO_PIN_OUTPUT, LED->LED_Status};
		DIO_PinWriteLogic(&LED_Pin, DIO_PIN_LOW);
		LED->LED_Status = LED_OFF;
	}
	return ret;
};


Std_ReturnType LED_Toggle(LED_t *LED){
	Std_ReturnType ret = E_OK;
	if(NULL == LED || ((LED->PortID)>MAX_PORT_ID) || ((LED->PinID)>MAX_PIN_ID)){
		ret = E_NOK;
	}
	else{
		DIO_PinCfg_t LED_Pin = {LED->PortID, LED->PinID, DIO_PIN_OUTPUT, DIO_PIN_LOW};
		DIO_PinToggleLogic(&LED_Pin);
		LED->LED_Status ^= 0X01;
	}
	return ret;
};

