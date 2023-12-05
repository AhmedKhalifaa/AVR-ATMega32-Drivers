/*
 * TIMER2.c
 *
 *      Author: Ahmed Khalifa
 */

#include "../../../0_Lib/STD_TYPES.h"
#include "../../../0_Lib/BIT_MATH.h"
#include "../../../1_MCAL/DIO/DIO.h"
#include "TIMER2.h"

static void(*TIMER2_OverFlowCallBack)(void) = NULL;
static void(*TIMER2_CompareMatchCallBack)(void) = NULL;

Std_ReturnType TIMER2_Initialize(TIMER2_Cfg_t* _TIMER2_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG){
		ret = E_NOK;
	}
	else{
		ret = TIMER2_SelectClock(_TIMER2_CFG, _TIMER2_CFG->TIMER2_Clock);
		ret = TIMER2_SelectMode(_TIMER2_CFG, _TIMER2_CFG->TIMER2_OperationMode, _TIMER2_CFG->TIMER2_OutputCompare_Mode);
		//Missing Asynchronous Operation Setup
	}
	return ret;
}

Std_ReturnType TIMER2_DeInitialize(TIMER2_Cfg_t* _TIMER2_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG){
		ret = E_NOK;
	}
	else{
		ret = TIMER2_Stop(_TIMER2_CFG);
		ret = TIMER2_DisableOverFlowInterrupt();
		ret = TIMER2_DisableCompareMatchInterrupt();
	}
	return ret;
}

Std_ReturnType TIMER2_Stop(TIMER2_Cfg_t* _TIMER2_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG){
		ret = E_NOK;
	}
	else{
		TIMER2_TCCR2_REG &= (TIMER2_CLOCK_SELECT_MASK);
	}
	return ret;
}

Std_ReturnType TIMER2_SetTimerValue(TIMER2_Cfg_t* _TIMER2_CFG, uint8_t _ticks){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG || _ticks < 0 || _ticks > 255){
		ret = E_NOK;
	}
	else{
		TIMER2_TCNT2_REG = _ticks;
	}
	return ret;
}

Std_ReturnType TIMER2_GetTimerValue(TIMER2_Cfg_t* _TIMER2_CFG, uint8_t* _ticks){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG || NULL == _ticks){
		ret = E_NOK;
	}
	else{
		*_ticks = TIMER2_TCNT2_REG;
	}
	return ret;
}

Std_ReturnType TIMER2_SetCompareMatchValue(TIMER2_Cfg_t* _TIMER2_CFG, uint8_t _ticks){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG || _ticks < 0 || _ticks > 255){
		ret = E_NOK;
	}
	else{
		TIMER2_OCR2_REG = _ticks;
	}
	return ret;
}

Std_ReturnType TIMER2_GetCompareMatchValue(TIMER2_Cfg_t* _TIMER2_CFG, uint8_t* _ticks){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG || NULL == _ticks){
		ret = E_NOK;
	}
	else{
		*_ticks = TIMER2_OCR2_REG;
	}
	return ret;
}

Std_ReturnType TIMER2_SetPWMDutyCycle(TIMER2_Cfg_t* _TIMER2_CFG, uint8_t _duty_cycle){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG || _duty_cycle > 100 || _duty_cycle < 0){
		ret = E_NOK;
	}
	else{
		TIMER2_OCR2_REG = (uint8_t)((_duty_cycle*255)/100);
	}
	return ret;
}

Std_ReturnType TIMER2_SelectClock(TIMER2_Cfg_t* _TIMER2_CFG, TIMER2_ClockSource_t _clock_source){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG){
		ret = E_NOK;
	}
	else{
		TIMER2_TCCR2_REG &= TIMER2_CLOCK_SELECT_MASK;
		TIMER2_TCCR2_REG |= _clock_source;
	}
	return ret;
}

Std_ReturnType TIMER2_SelectMode(TIMER2_Cfg_t* _TIMER2_CFG, TIMER2_OperationMode_t _operation_mode, uint8_t _output_compare_mode){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG){
		ret = E_NOK;
	}
	else{
		TIMER2_TCCR2_REG &= (TIMER2_MODE_SELECT_MASK & TIMER2_COMPARE_MODE_SELECT_MASK);
		TIMER2_TCCR2_REG |= (_output_compare_mode<<TIMER2_TCCR2_COM20_BIT);
		switch(_operation_mode){
			case TIMER2_OPERATION_MODE_NORMAL:
				break;
			case TIMER2_OPERATION_MODE_PHASE_CORRECT_PWM:
				SET_BIT(TIMER2_TCCR2_REG,TIMER2_TCCR2_WGM20_BIT);
				break;
			case TIMER2_OPERATION_MODE_CTC:
				SET_BIT(TIMER2_TCCR2_REG,TIMER2_TCCR2_WGM21_BIT);
				break;
			case TIMER2_OPERATION_MODE_FAST_PWM:
				SET_BIT(TIMER2_TCCR2_REG,TIMER2_TCCR2_WGM20_BIT);
				SET_BIT(TIMER2_TCCR2_REG,TIMER2_TCCR2_WGM21_BIT);
				break;
			default:
				ret = E_NOK;
				break;
		}
	}
	return ret;
}

Std_ReturnType TIMER2_EnableOverFlowInterrupt(void){
	Std_ReturnType ret = E_OK;
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE2_BIT);
	return ret;
}

Std_ReturnType TIMER2_DisableOverFlowInterrupt(void){
	Std_ReturnType ret = E_OK;
	CLR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE2_BIT);
	return ret;
}

Std_ReturnType TIMER2_EnableCompareMatchInterrupt(void){
	Std_ReturnType ret = E_OK;
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE2_BIT);
	return ret;
}

Std_ReturnType TIMER2_DisableCompareMatchInterrupt(void){
	Std_ReturnType ret = E_OK;
	CLR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE2_BIT);
	return ret;
}

Std_ReturnType TIMER2_SetOverFlowCallBacK(TIMER2_Cfg_t* _TIMER2_CFG, void(*_callbackfunctionptr)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG || NULL == _callbackfunctionptr){
		ret = E_NOK;
	}
	else{
		TIMER2_OverFlowCallBack = _callbackfunctionptr;
	}
	return ret;
}

Std_ReturnType TIMER2_SetCompareMatchCallBacK(TIMER2_Cfg_t* _TIMER2_CFG, void(*_callbackfunctionptr)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == _TIMER2_CFG || NULL == _callbackfunctionptr){
		ret = E_NOK;
	}
	else{
		TIMER2_CompareMatchCallBack = _callbackfunctionptr;
	}
	return ret;
}

ISR(TIMER2_OVF2_VECTOR){
	if(NULL != TIMER2_OverFlowCallBack){
		TIMER2_OverFlowCallBack();
	}
}

ISR(TIMER2_OC2_VECTOR){
	if(NULL != TIMER2_CompareMatchCallBack){
		TIMER2_CompareMatchCallBack();
	}
}


