/*
 * ADC.c
 *
 *      Author: Ahmed Khalifa
 */

#include "../../0_Lib/STD_TYPES.h"
#include "../../0_Lib/BIT_MATH.h"
#include "../../1_MCAL/DIO/DIO.h"
#include "ADC.h"

static void(*ADC_CallBack)(void) = NULL;

Std_ReturnType ADC_Initialize(ADC_Cfg_t* _ADC_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _ADC_CFG){
		ret = E_NOK;
	}
	else{
		ret = ADC_Disable();
		ret = ADC_SelectChannel(_ADC_CFG, _ADC_CFG->ADC_Channel);
		ret = ADC_SetPrescaler(_ADC_CFG, _ADC_CFG->ADC_Prescaler);
		ret = ADC_SelectVoltageReference(_ADC_CFG, _ADC_CFG->ADC_VoltageReference);
		if(ADC_AUTOTRIGGER_ENABLED == _ADC_CFG->ADC_AutoTriggerStatus){
			ret = ADC_EnableAutoTrigger(_ADC_CFG);
			ret = ADC_SetTriggerSource(_ADC_CFG, _ADC_CFG->ADC_TriggerSource);
		}
		else{

		}
		ret = ADC_Enable();
	}
	return ret;
};

Std_ReturnType ADC_Deinitilaze(ADC_Cfg_t* _ADC_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _ADC_CFG){
		ret = E_NOK;
	}
	else{
		ret = ADC_Disable();
		ret = ADC_DisableInterrupt();
		ret = ADC_DisableAutoTrigger(_ADC_CFG);
	}
	return ret;
}

Std_ReturnType ADC_Enable(void){
	Std_ReturnType ret = E_OK;
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADEN_BIT);
	return ret;
}

Std_ReturnType ADC_Disable(void){
	Std_ReturnType ret = E_OK;
	CLR_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADEN_BIT);
	return ret;
}

Std_ReturnType ADC_SetPrescaler(ADC_Cfg_t* _ADC_CFG, ADC_PrescalerSelect_t _prescaler){
	Std_ReturnType ret = E_OK;
	if(NULL == _ADC_CFG || _prescaler > ADC_PRESCALER_DIV_128 || _prescaler < ADC_PRESCALER_DIV_1){
		ret = E_NOK;
	}
	else{
		ADC_ADCSRA_REG &= ADC_PRESCALER_MASK;
		ADC_ADCSRA_REG |= _prescaler;
	}
	return ret;
};

Std_ReturnType ADC_SelectChannel(ADC_Cfg_t* _ADC_CFG, ADC_ChannelSelect_t _channel){

	Std_ReturnType ret = E_OK;
	if(NULL == _ADC_CFG || _channel > ADC_CHANNEL_ADC7 || _channel < ADC_CHANNEL_ADC0){
		ret = E_NOK;
	}
	else{
		ADC_ADMUX_REG &= ADC_MUX_MASK;
		ADC_ADMUX_REG |= _channel;
	}
	return ret;
}

Std_ReturnType ADC_EnableInterrupt(void){
	Std_ReturnType ret = E_OK;
	SET_BIT(ADC_ADCSRA_REG, ADC_ADCSRA_ADIE_BIT);
	return ret;
};

Std_ReturnType ADC_DisableInterrupt(void){
	Std_ReturnType ret = E_OK;
	CLR_BIT(ADC_ADCSRA_REG, ADC_ADCSRA_ADIE_BIT);
	return ret;
};

Std_ReturnType ADC_SelectVoltageReference(ADC_Cfg_t* _ADC_CFG, ADC_VoltageReference_t _voltage){
	Std_ReturnType ret = E_OK;
	if(NULL == _ADC_CFG || _voltage > ADC_VOLTAGE_INTERNAL || _voltage < ADC_VOLTAGE_AREF || ADC_VOLTAGE_RESERVED == _voltage){
		ret = E_NOK;
	}
	else{
		ADC_ADMUX_REG &= ADC_VOLTAGE_SELECT_MASK;
		ADC_ADMUX_REG |= (_voltage<<6);
	}
	return ret;
}

Std_ReturnType ADC_EnableAutoTrigger(ADC_Cfg_t* _ADC_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _ADC_CFG){
		ret = E_NOK;
	}
	else{
		SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADATE_BIT);
		_ADC_CFG->ADC_AutoTriggerStatus = ADC_AUTOTRIGGER_ENABLED;
	}
	return ret;
}

Std_ReturnType ADC_DisableAutoTrigger(ADC_Cfg_t* _ADC_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _ADC_CFG){
		ret = E_NOK;
	}
	else{
		CLR_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADATE_BIT);
		_ADC_CFG->ADC_AutoTriggerStatus = ADC_AUTOTRIGGER_DISABLED;
	}
	return ret;
}

Std_ReturnType ADC_SetTriggerSource(ADC_Cfg_t* _ADC_CFG, ADC_TriggerSource_t _trigger){
	Std_ReturnType ret = E_OK;
	if(NULL == _ADC_CFG || _trigger > ADC_TRIGGER_SOURCE_TIMER1_CAPTURE_EVENT || _trigger < ADC_TRIGGER_SOURCE_FREE_RUNNING){
		ret = E_NOK;
	}
	else{
		if(ADC_AUTOTRIGGER_ENABLED == _ADC_CFG->ADC_AutoTriggerStatus){
			ADC_SFIOR_REG &= ADC_AUTO_TRIGGER_SOURCE_MASK;
			ADC_SFIOR_REG |= (_trigger<<5);
			_ADC_CFG->ADC_TriggerSource = _trigger;
		}
		else if(ADC_AUTOTRIGGER_DISABLED == _ADC_CFG->ADC_AutoTriggerStatus){

		}
		else{
			ret = E_NOK;
		}
	}
	return ret;
}

Std_ReturnType ADC_ReadResult(ADC_Cfg_t* _ADC_CFG, uint16_t* _adc_result){
	Std_ReturnType ret = E_OK;
	if(NULL == _ADC_CFG){
		ret = E_NOK;
	}
	else{
		if(ADC_RIGHT_ADJUST == _ADC_CFG->ADC_ResultAdjust){
			*_adc_result = ADC_ADC_REG;
		}
		else if (ADC_LEFT_ADJUST == _ADC_CFG->ADC_ResultAdjust){
			*_adc_result = (ADC_ADC_REG>>6);
		}
		else{
			ret = E_NOK;
		}
	}
	return ret;
};

Std_ReturnType ADC_SetCallBack(ADC_Cfg_t* _ADC_CFG, void(*_callbackfunctionptr)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == _ADC_CFG || NULL == _callbackfunctionptr){
		ret = E_NOK;
	}
	else{
		ADC_CallBack = _callbackfunctionptr;
	}
	return ret;
}

Std_ReturnType ADC_StartConversion(){
	Std_ReturnType ret = E_OK;
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADSC_BIT);
	return ret;
}

ISR(ADC_VECTOR){
	if(NULL != ADC_CallBack){
		ADC_CallBack();
	}
}
