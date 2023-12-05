/*
 * TIMER0.c
 *
 *      Author: Ahmed Khalifa
 */

#include "../../../0_Lib/STD_TYPES.h"
#include "../../../0_Lib/BIT_MATH.h"
#include "../../../1_MCAL/DIO/DIO.h"
#include "TIMER0.h"

static void(*TIMER0_OverFlowCallBack)(void) = NULL;
static void(*TIMER0_CompareMatchCallBack)(void) = NULL;

Std_ReturnType TIMER0_Initialize(TIMER0_Cfg_t* _TIMER0_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG){
		ret = E_NOK;
	}
	else{
		ret = TIMER0_SelectClock(_TIMER0_CFG, _TIMER0_CFG->TIMER0_Clock);
		ret = TIMER0_SelectMode(_TIMER0_CFG, _TIMER0_CFG->TIMER0_OperationMode, _TIMER0_CFG->TIMER0_OutputCompare_Mode);
	}
	return ret;
}

Std_ReturnType TIMER0_DeInitialize(TIMER0_Cfg_t* _TIMER0_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG){
		ret = E_NOK;
	}
	else{
		ret = TIMER0_Stop(_TIMER0_CFG);
		ret = TIMER0_DisableOverFlowInterrupt();
		ret = TIMER0_DisableCompareMatchInterrupt();
	}
	return ret;
}

Std_ReturnType TIMER0_Stop(TIMER0_Cfg_t* _TIMER0_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG){
		ret = E_NOK;
	}
	else{
		TIMER0_TCCR0_REG &= (TIMER0_CLOCK_SELECT_MASK);
	}
	return ret;
}

Std_ReturnType TIMER0_SetTimerValue(TIMER0_Cfg_t* _TIMER0_CFG, uint8_t _ticks){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG || _ticks < 0 || _ticks > 255){
		ret = E_NOK;
	}
	else{
		TIMER0_TCNT0_REG = _ticks;
	}
	return ret;
}

Std_ReturnType TIMER0_GetTimerValue(TIMER0_Cfg_t* _TIMER0_CFG, uint8_t* _ticks){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG || NULL == _ticks){
		ret = E_NOK;
	}
	else{
		*_ticks = TIMER0_TCNT0_REG;
	}
	return ret;
}

Std_ReturnType TIMER0_SetCompareMatchValue(TIMER0_Cfg_t* _TIMER0_CFG, uint8_t _ticks){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG || _ticks < 0 || _ticks > 255){
		ret = E_NOK;
	}
	else{
		TIMER0_OCR0_REG = _ticks;
	}
	return ret;
}

Std_ReturnType TIMER0_GetCompareMatchValue(TIMER0_Cfg_t* _TIMER0_CFG, uint8_t* _ticks){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG || NULL == _ticks){
		ret = E_NOK;
	}
	else{
		*_ticks = TIMER0_OCR0_REG;
	}
	return ret;
}

Std_ReturnType TIMER0_SetPWMDutyCycle(TIMER0_Cfg_t* _TIMER0_CFG, uint8_t _duty_cycle){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG || _duty_cycle > 100 || _duty_cycle < 0){
		ret = E_NOK;
	}
	else{
		TIMER0_OCR0_REG = (uint8_t)((_duty_cycle*255)/100);
	}
	return ret;
}

Std_ReturnType TIMER0_SelectClock(TIMER0_Cfg_t* _TIMER0_CFG, TIMER0_ClockSource_t _clock_source){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG){
		ret = E_NOK;
	}
	else{
		TIMER0_TCCR0_REG &= TIMER0_CLOCK_SELECT_MASK;
		TIMER0_TCCR0_REG |= _clock_source;
	}
	return ret;
}

Std_ReturnType TIMER0_SelectMode(TIMER0_Cfg_t* _TIMER0_CFG, TIMER0_OperationMode_t _operation_mode, uint8_t _output_compare_mode){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG){
		ret = E_NOK;
	}
	else{
		TIMER0_TCCR0_REG &= (TIMER0_MODE_SELECT_MASK & TIMER0_COMPARE_MODE_SELECT_MASK);
		TIMER0_TCCR0_REG |= (_output_compare_mode<<TIMER0_TCCR0_COM00_BIT);
		switch(_operation_mode){
			case TIMER0_OPERATION_MODE_NORMAL:
				break;
			case TIMER0_OPERATION_MODE_PHASE_CORRECT_PWM:
				SET_BIT(TIMER0_TCCR0_REG,TIMER0_TCCR0_WGM00_BIT);
				break;
			case TIMER0_OPERATION_MODE_CTC:
				SET_BIT(TIMER0_TCCR0_REG,TIMER0_TCCR0_WGM01_BIT);
				break;
			case TIMER0_OPERATION_MODE_FAST_PWM:
				SET_BIT(TIMER0_TCCR0_REG,TIMER0_TCCR0_WGM00_BIT);
				SET_BIT(TIMER0_TCCR0_REG,TIMER0_TCCR0_WGM01_BIT);
				break;
			default:
				ret = E_NOK;
				break;
		}
	}
	return ret;
}

Std_ReturnType TIMER0_EnableOverFlowInterrupt(void){
	Std_ReturnType ret = E_OK;
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE0_BIT);
	return ret;
}

Std_ReturnType TIMER0_DisableOverFlowInterrupt(void){
	Std_ReturnType ret = E_OK;
	CLR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE0_BIT);
	return ret;
}

Std_ReturnType TIMER0_EnableCompareMatchInterrupt(void){
	Std_ReturnType ret = E_OK;
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE0_BIT);
	return ret;
}

Std_ReturnType TIMER0_DisableCompareMatchInterrupt(void){
	Std_ReturnType ret = E_OK;
	CLR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE0_BIT);
	return ret;
}

Std_ReturnType TIMER0_SetOverFlowCallBacK(TIMER0_Cfg_t* _TIMER0_CFG, void(*_callbackfunctionptr)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG || NULL == _callbackfunctionptr){
		ret = E_NOK;
	}
	else{
		TIMER0_OverFlowCallBack = _callbackfunctionptr;
	}
	return ret;
}

Std_ReturnType TIMER0_SetCompareMatchCallBacK(TIMER0_Cfg_t* _TIMER0_CFG, void(*_callbackfunctionptr)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER0_CFG || NULL == _callbackfunctionptr){
		ret = E_NOK;
	}
	else{
		TIMER0_CompareMatchCallBack = _callbackfunctionptr;
	}
	return ret;
}

ISR(TIMER0_OVF0_VECTOR){
	if(NULL != TIMER0_OverFlowCallBack){
		TIMER0_OverFlowCallBack();
	}
}

ISR(TIMER0_OC0_VECTOR){
	if(NULL != TIMER0_CompareMatchCallBack){
		TIMER0_CompareMatchCallBack();
	}
}
