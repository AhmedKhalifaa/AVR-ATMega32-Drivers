/*
 * EXTINT.c
 *
 *      Author: Ahmed Khalifa
 */

#include "../../0_Lib/STD_TYPES.h"
#include "../../0_Lib/BIT_MATH.h"
#include "../../1_MCAL/DIO/DIO.h"
#include "EXTINT.h"

/*We will start by defining pointers to the callback functions*/
static void (*EXTINT0_CallBack)(void) = NULL;
static void (*EXTINT1_CallBack)(void) = NULL;
static void (*EXTINT2_CallBack)(void) = NULL;

/* Next, The External Interrupt Relevant Interfaces*/
Std_ReturnType EXTINT_Initialize(EXTINT_InterruptConfig_t* _EXTINT_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _EXTINT_CFG){
		ret = E_NOK;
	}
	else{
		ret = DIO_PinIntialize(&(_EXTINT_CFG->EXTINT_PinCfg));
		ret = EXTINT_Enable(_EXTINT_CFG);
		ret = EXTINT_SetTrigger(_EXTINT_CFG, (_EXTINT_CFG->EXTINT_InterruptTrigger));
	}
	return ret;
};

Std_ReturnType EXTINT_Enable(EXTINT_InterruptConfig_t* _EXTINT_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _EXTINT_CFG){
		ret = E_NOK;
	}
	else{
		switch(_EXTINT_CFG->EXTINT_InterruptID){
			case EXTINT_INT0:
				SET_BIT(EXTINT_GICR_REG, EXTINT_INT0_BIT);
				_EXTINT_CFG->EXTINT_InterruptStatus = EXTINT_ENABLED;
				break;
			case EXTINT_INT1:
				SET_BIT(EXTINT_GICR_REG, EXTINT_INT1_BIT);
				_EXTINT_CFG->EXTINT_InterruptStatus = EXTINT_ENABLED;
				break;
			case EXTINT_INT2:
				SET_BIT(EXTINT_GICR_REG, EXTINT_INT2_BIT);
				_EXTINT_CFG->EXTINT_InterruptStatus = EXTINT_ENABLED;
				break;
			default:
				ret = E_NOK;
				break;
		}
	}
	return ret;
	}

Std_ReturnType EXTINT_Disable(EXTINT_InterruptConfig_t* _EXTINT_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _EXTINT_CFG){
		ret = E_NOK;
	}
	else{
		switch(_EXTINT_CFG->EXTINT_InterruptID){
			case EXTINT_INT0:
				CLR_BIT(EXTINT_GICR_REG, EXTINT_INT0_BIT);
				_EXTINT_CFG->EXTINT_InterruptStatus = EXTINT_DISABLED;
				break;
			case EXTINT_INT1:
				CLR_BIT(EXTINT_GICR_REG, EXTINT_INT1_BIT);
				_EXTINT_CFG->EXTINT_InterruptStatus = EXTINT_DISABLED;
				break;
			case EXTINT_INT2:
				CLR_BIT(EXTINT_GICR_REG, EXTINT_INT2_BIT);
				_EXTINT_CFG->EXTINT_InterruptStatus = EXTINT_DISABLED;
				break;
			default:
				ret = E_NOK;
				break;
		}
	}
	return ret;
	}

Std_ReturnType EXTINT_SetTrigger(EXTINT_InterruptConfig_t* _EXTINT_CFG,EXTINT_InterruptTrigger_t trigger){
	Std_ReturnType ret = E_OK;
	switch(_EXTINT_CFG->EXTINT_InterruptID){
		case EXTINT_INT0:
			switch(trigger){
				case EXTINT_TRIGGER_ON_LOW_LEVEL:
					CLR_BIT(EXTINT_MCUCR_REG,EXTINT_ISC00_BIT);
					CLR_BIT(EXTINT_MCUCR_REG,EXTINT_ISC01_BIT);
					_EXTINT_CFG->EXTINT_InterruptTrigger = trigger;
					break;
				case EXTINT_TRIGGER_ON_BOTH_EDGES:
					SET_BIT(EXTINT_MCUCR_REG,EXTINT_ISC00_BIT);
					CLR_BIT(EXTINT_MCUCR_REG,EXTINT_ISC01_BIT);
					_EXTINT_CFG->EXTINT_InterruptTrigger = trigger;
					break;
				case EXTINT_TRIGGER_ON_FALLING_EDGE:
					CLR_BIT(EXTINT_MCUCR_REG,EXTINT_ISC00_BIT);
					SET_BIT(EXTINT_MCUCR_REG,EXTINT_ISC01_BIT);
					_EXTINT_CFG->EXTINT_InterruptTrigger = trigger;
					break;
				case EXTINT_TRIGGER_ON_RISING_EDGE:
					SET_BIT(EXTINT_MCUCR_REG,EXTINT_ISC00_BIT);
					SET_BIT(EXTINT_MCUCR_REG,EXTINT_ISC01_BIT);
					_EXTINT_CFG->EXTINT_InterruptTrigger = trigger;
					break;
				default:
					ret = E_NOK;
					break;
			}
			break;
		case EXTINT_INT1:
			switch(trigger){
				case EXTINT_TRIGGER_ON_LOW_LEVEL:
					CLR_BIT(EXTINT_MCUCR_REG,EXTINT_ISC10_BIT);
					CLR_BIT(EXTINT_MCUCR_REG,EXTINT_ISC11_BIT);
					_EXTINT_CFG->EXTINT_InterruptTrigger = trigger;
					break;
				case EXTINT_TRIGGER_ON_BOTH_EDGES:
					SET_BIT(EXTINT_MCUCR_REG,EXTINT_ISC10_BIT);
					CLR_BIT(EXTINT_MCUCR_REG,EXTINT_ISC11_BIT);
					_EXTINT_CFG->EXTINT_InterruptTrigger = trigger;
					break;
				case EXTINT_TRIGGER_ON_FALLING_EDGE:
					CLR_BIT(EXTINT_MCUCR_REG,EXTINT_ISC10_BIT);
					SET_BIT(EXTINT_MCUCR_REG,EXTINT_ISC11_BIT);
					_EXTINT_CFG->EXTINT_InterruptTrigger = trigger;
					break;
				case EXTINT_TRIGGER_ON_RISING_EDGE:
					SET_BIT(EXTINT_MCUCR_REG,EXTINT_ISC10_BIT);
					SET_BIT(EXTINT_MCUCR_REG,EXTINT_ISC11_BIT);
					_EXTINT_CFG->EXTINT_InterruptTrigger = trigger;
					break;
				default:
					ret = E_NOK;
					break;
			}
			break;
		case EXTINT_INT2:
			switch(trigger){
				case EXTINT_TRIGGER_ON_FALLING_EDGE:
					CLR_BIT(EXTINT_MCUCSR_REG,EXTINT_ISC2_BIT);
					_EXTINT_CFG->EXTINT_InterruptTrigger = trigger;
					break;
				case EXTINT_TRIGGER_ON_RISING_EDGE:
					SET_BIT(EXTINT_MCUCSR_REG,EXTINT_ISC2_BIT);
					_EXTINT_CFG->EXTINT_InterruptTrigger = trigger;
					break;
				default:
					ret = E_NOK;
					break;
			}
			break;
		default:
			ret=E_NOK;
			break;
	}
	return ret;
};

Std_ReturnType EXTINT_SetCallBack(EXTINT_InterruptConfig_t* _EXTINT_CFG, void(*_callbackfunctionptr)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == _callbackfunctionptr){
		ret = E_NOK;
	}
	else{
		switch(_EXTINT_CFG->EXTINT_InterruptID){
			case EXTINT_INT0:
				EXTINT0_CallBack = _callbackfunctionptr;
				break;
			case EXTINT_INT1:
				EXTINT1_CallBack = _callbackfunctionptr;
				break;
			case EXTINT_INT2:
				EXTINT2_CallBack = _callbackfunctionptr;
				break;
			default:
				ret = E_NOK;
				break;
		}
	}
	return ret;
} ;

/* Interrupt Service Routines of the External Interrupts */
ISR(INT0_VECTOR){
	if(NULL != EXTINT0_CallBack){
		EXTINT0_CallBack();
	}
}

ISR(INT1_VECTOR){
	if(NULL != EXTINT1_CallBack){
		EXTINT1_CallBack();
	}
}

ISR(INT2_VECTOR){
	if(NULL != EXTINT2_CallBack){
		EXTINT2_CallBack();
	}
}
