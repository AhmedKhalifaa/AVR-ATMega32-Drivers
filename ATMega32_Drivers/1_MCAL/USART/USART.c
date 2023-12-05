/*
 * USART.c
 *
 *      Author: Ahmed Khalifa
 */

#include "../../0_Lib/STD_TYPES.h"
#include "../../0_Lib/BIT_MATH.h"
#include "../../1_MCAL/DIO/DIO.h"
#include "USART.h"

static void(*USART_TxCompleteCallBack)(void) = NULL;
static void(*USART_RxCompleteCallBack)(void) = NULL;
static void(*USART_DataRegisterEmptyCallBack)(void) = NULL;

Std_ReturnType USART_Initialize(USART_Cfg_t* _USART_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		ret = USART_SetBaudRate(_USART_CFG, _USART_CFG->USART_BaudRate);
		ret = USART_SetClockPolarity(_USART_CFG, _USART_CFG->USART_ClockPolarity);
		ret = USART_SetCharacterSize(_USART_CFG,_USART_CFG->USART_CharacterSize);
		ret = USART_SelectOperationMode(_USART_CFG,_USART_CFG->USART_OperationMode);
		ret = USART_SelectCommunicationMode(_USART_CFG, _USART_CFG->USART_CommunicationMode);
		ret = USART_SelectClockParity(_USART_CFG, _USART_CFG->USART_ParityMode);
		ret = USART_SelectStopBit(_USART_CFG, _USART_CFG->USART_StopBit);
		ret = USART_SetTransmissionSpeed(_USART_CFG, _USART_CFG->USART_TransmissionSpeed);
		ret = USART_SetTransmissionMode(_USART_CFG, _USART_CFG->USART_TransmissionMode);
	}
	return ret;
}

Std_ReturnType USART_DeInitialize(USART_Cfg_t* _USART_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		ret = USART_SetTransmissionMode(_USART_CFG, USART_TRANSMISSION_MODE_DISABLED);
		ret = USART_SetTransmissionSpeed(_USART_CFG, USART_TRANSMISSION_SPEED_NORMAL);
		ret = USART_DisableDataRegisterEmptyInterrupt();
		ret = USART_DisableTxCompleteInterrupt();
		ret = USART_DisableRxCompleteInterrupt();
	}
	return ret;
}

Std_ReturnType USART_SetClockPolarity(USART_Cfg_t* _USART_CFG, USART_ClockPolarity_t _clock_polarity){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		switch(_clock_polarity){
		case USART_CLOCK_POLARITY_TRANSMIT_ON_RISING_EDGE:
			CLR_BIT(USART_UCSRC_REG, USART_UCSRC_UCPOL_BIT);
			break;
		case USART_CLOCK_POLARITY_TRANSMIT_ON_FALLING_EDGE:
			SET_BIT(USART_UCSRC_REG, USART_UCSRC_UCPOL_BIT);
			break;
		default:
			ret = E_NOK;
			break;
		}
	}
	return ret;
}

Std_ReturnType USART_SetCharacterSize(USART_Cfg_t* _USART_CFG, USART_CharacterSize_t _character_size){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		USART_UCSRC_REG &= USART_CHARACTER_SIZE_MASK;
		CLR_BIT(USART_UCSRB_REG, USART_UCSRB_UCSZ2_BIT);
		switch (_character_size){
			case USART_CHARACTER_SIZE_5BITS:
				break;
			case USART_CHARACTER_SIZE_6BITS:
				SET_BIT(USART_UCSRC_REG, USART_UCSRC_UCSZ0_BIT);
				break;
			case USART_CHARACTER_SIZE_7BITS:
				SET_BIT(USART_UCSRC_REG, USART_UCSRC_UCSZ1_BIT);
				break;
			case USART_CHARACTER_SIZE_8BITS:
				SET_BIT(USART_UCSRC_REG, USART_UCSRC_UCSZ0_BIT);
				SET_BIT(USART_UCSRC_REG, USART_UCSRC_UCSZ1_BIT);
				break;
			case USART_CHARACTER_SIZE_9BITS:
				USART_UCSRC_REG |= (USART_CHARACTER_SIZE_8BITS<<USART_UCSRC_UCSZ0_BIT);
				SET_BIT(USART_UCSRB_REG, USART_UCSRB_UCSZ2_BIT);
				break;
			default:
				ret = E_NOK;
		}
	}
	return ret;
}

Std_ReturnType USART_SelectOperationMode(USART_Cfg_t* _USART_CFG, USART_OperationMode_t _operation_mode){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		SET_BIT(USART_UCSRC_REG, USART_UCSRC_URSEL_BIT);
		switch(_operation_mode){
		case USART_OPERATION_MODE_ASYNCHRONOUS:
			CLR_BIT(USART_UCSRC_REG, USART_UCSRC_UMSEL_BIT);
			break;
		case USART_OPERATION_MODE_SYNCHRONOUS:
			SET_BIT(USART_UCSRC_REG, USART_UCSRC_UMSEL_BIT);
			break;
		default:
			ret = E_NOK;
			break;
		}
	}
	return ret;
}

Std_ReturnType USART_SelectCommunicationMode(USART_Cfg_t* _USART_CFG, USART_CommunicationMode_t _communication_mode){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		SET_BIT(USART_UCSRC_REG, USART_UCSRC_URSEL_BIT);
		switch(_communication_mode){
		case USART_COMMUNICATION_MODE_SINGLE_PROCESSOR:
			CLR_BIT(USART_UCSRA_REG, USART_UCSRA_MPCM_BIT);
			break;
		case USART_COMMUNICATION_MODE_MULTI_PROCESSOR:
			SET_BIT(USART_UCSRA_REG, USART_UCSRA_MPCM_BIT);
			break;
		default:
			ret = E_NOK;
			break;
		}
	}
	return ret;
}

Std_ReturnType USART_SelectClockParity(USART_Cfg_t* _USART_CFG, USART_ClockPolarity_t _clock_parity){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		SET_BIT(USART_UCSRC_REG, USART_UCSRC_URSEL_BIT);
		USART_UCSRC_REG &= USART_CLOCK_PARITY_MASK;
		switch(_clock_parity){
		case USART_PARITY_MODE_DISABLE:
			break;
		case USART_PARITY_MODE_EVEN_PARITY:
			USART_UCSRC_REG |= (USART_PARITY_MODE_EVEN_PARITY<<USART_UCSRC_UPM0_BIT);
			break;
		case USART_PARITY_MODE_ODD_PARITY:
			USART_UCSRC_REG |= (USART_PARITY_MODE_ODD_PARITY<<USART_UCSRC_UPM0_BIT);
			break;
		default:
			ret = E_NOK;
			break;
		}
	}
	return ret;
}

Std_ReturnType USART_SelectStopBit(USART_Cfg_t* _USART_CFG, USART_StopBit_t _stop_bit){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		SET_BIT(USART_UCSRC_REG, USART_UCSRC_URSEL_BIT);
		switch(_stop_bit){
		case USART_STOP_BITS_1BIT:
			CLR_BIT(USART_UCSRC_REG, USART_UCSRC_USBS_BIT);
			break;
		case USART_STOP_BITS_2BITS:
			SET_BIT(USART_UCSRC_REG, USART_UCSRC_USBS_BIT);
			break;
		default:
			ret = E_NOK;
			break;
		}
	}
	return ret;
}

Std_ReturnType USART_SetTransmissionSpeed(USART_Cfg_t* _USART_CFG, USART_TransmissionSpeed_t _transmission_speed){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		switch(_transmission_speed){
		case USART_TRANSMISSION_SPEED_NORMAL:
			CLR_BIT(USART_UCSRA_REG, USART_UCSRA_U2X_BIT);
			break;
		case USART_TRANSMISSION_SPEED_DOUBLE:
			SET_BIT(USART_UCSRA_REG, USART_UCSRA_U2X_BIT);
			break;
		default:
			ret = E_NOK;
			break;
		}
	}
	return ret;
}

Std_ReturnType USART_SetBaudRate(USART_Cfg_t* _USART_CFG, uint32_t _baud_rate){
	Std_ReturnType ret = E_OK;
	uint32_t _UBRR_value = 0;
	if(NULL == _USART_CFG || 0 == _baud_rate){
		ret = E_NOK;
	}
	else{
		CLR_BIT(USART_UCSRC_REG, USART_UCSRC_URSEL_BIT);
		switch(_USART_CFG->USART_OperationMode){
			case USART_OPERATION_MODE_SYNCHRONOUS:
				_UBRR_value = ((F_CPU/(2*_baud_rate)) - 1);
				break;
			case USART_OPERATION_MODE_ASYNCHRONOUS:
				switch(_USART_CFG->USART_TransmissionSpeed){
				case USART_TRANSMISSION_SPEED_NORMAL:
					_UBRR_value = ((F_CPU/(16*_baud_rate)) - 1);
					break;
				case USART_TRANSMISSION_SPEED_DOUBLE:
					_UBRR_value = ((F_CPU/(8*_baud_rate)) - 1);
					break;
				default:
					ret = E_NOK;
					break;
				}
				break;
			default:
				ret = E_NOK;
				break;
		}
		USART_UBRRL_REG = ((uint8_t)(_UBRR_value));
		USART_UBRRH_REG = ((uint8_t)(_UBRR_value>>8));
	}
	return ret;
}

Std_ReturnType USART_SetTransmissionMode(USART_Cfg_t* _USART_CFG, USART_TransmissionMode_t _transmission_mode){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		switch(_transmission_mode){
		case USART_TRANSMISSION_MODE_DISABLED:
			CLR_BIT(USART_UCSRB_REG,USART_UCSRB_TXEN_BIT);
			CLR_BIT(USART_UCSRB_REG,USART_UCSRB_RXEN_BIT);
			break;
		case USART_TRANSMISSION_MODE_HALF_DUPLEX_TRANSMITTER:
			SET_BIT(USART_UCSRB_REG,USART_UCSRB_TXEN_BIT);
			break;
		case USART_TRANSMISSION_MODE_HALF_DUPLEX_RECIEVER:
			SET_BIT(USART_UCSRB_REG,USART_UCSRB_RXEN_BIT);
			break;
		case USART_TRANSMISSION_MODE_FULL_DUPLEX:
			SET_BIT(USART_UCSRB_REG,USART_UCSRB_TXEN_BIT);
			SET_BIT(USART_UCSRB_REG,USART_UCSRB_RXEN_BIT);
			break;
		default:
			ret = E_NOK;
		}
	}
	return ret;
}

Std_ReturnType USART_WriteByteBlocking(USART_Cfg_t* _USART_CFG, uint16_t _byte){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		while(0 == READ_BIT(USART_UCSRA_REG, USART_UCSRA_UDRE_BIT)){
		};
		if(USART_CHARACTER_SIZE_9BITS == _USART_CFG->USART_CharacterSize){
			CLR_BIT(USART_UCSRB_REG, USART_UCSRB_TXB8_BIT);
			USART_UCSRB_REG |= (READ_BIT(_byte, 9));
			USART_UDR_REG = (uint8_t)_byte;
		}
		else{
			USART_UDR_REG = (uint8_t)_byte;
		}
	}
	return ret;
};

Std_ReturnType USART_WriteByteNonBlocking(USART_Cfg_t* _USART_CFG, uint16_t _byte){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		if(0 != READ_BIT(USART_UCSRA_REG, USART_UCSRA_UDRE_BIT)){
			if(USART_CHARACTER_SIZE_9BITS == _USART_CFG->USART_CharacterSize){
				CLR_BIT(USART_UCSRB_REG, USART_UCSRB_TXB8_BIT);
				USART_UCSRB_REG |= (READ_BIT(_byte, 9));
				USART_UDR_REG = (uint8_t)_byte;
			}
			else{
				USART_UDR_REG = (uint8_t)_byte;
			}
		}
	}
	return ret;
};

Std_ReturnType USART_ReadByteBlocking(USART_Cfg_t* _USART_CFG, uint16_t* _byte){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		while(0 == READ_BIT(USART_UCSRA_REG,USART_UCSRA_RXC_BIT)){

		};
		if(USART_CHARACTER_SIZE_9BITS == _USART_CFG->USART_CharacterSize){
			*_byte |= ((READ_BIT(USART_UCSRB_REG, USART_UCSRB_TXB8_BIT))<<8);
			*_byte |= USART_UDR_REG;
		}
		else{
			*_byte |= USART_UDR_REG;
		}
	}
	return ret;
}

Std_ReturnType USART_ReadByteNonBlocking(USART_Cfg_t* _USART_CFG, uint16_t* _byte){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG){
		ret = E_NOK;
	}
	else{
		if(0 != READ_BIT(USART_UCSRA_REG,USART_UCSRA_RXC_BIT)){
			if(USART_CHARACTER_SIZE_9BITS == _USART_CFG->USART_CharacterSize){
				*_byte |= ((READ_BIT(USART_UCSRB_REG, USART_UCSRB_TXB8_BIT))<<8);
				*_byte |= USART_UDR_REG;
			}
			else{
				*_byte |= USART_UDR_REG;
			}
		}
	}
	return ret;
}

Std_ReturnType USART_WriteStringBlocking(USART_Cfg_t* _USART_CFG, uint8_t* _str){
	Std_ReturnType ret = E_OK;
	while('\0' != *_str){
		USART_WriteByteBlocking(_USART_CFG, *_str);
		_str++;
	}
	return ret;
}

Std_ReturnType USART_WriteStringNonBlocking(USART_Cfg_t* _USART_CFG, uint8_t* _str);

Std_ReturnType USART_EnableTxCompleteInterrupt(void){
	Std_ReturnType ret = E_OK;
	SET_BIT(USART_UCSRB_REG,USART_UCSRB_TXCIE_BIT);
	return ret;
}

Std_ReturnType USART_DisableTxCompleteInterrupt(void){
	Std_ReturnType ret = E_OK;
	CLR_BIT(USART_UCSRB_REG,USART_UCSRB_TXCIE_BIT);
	return ret;
}

Std_ReturnType USART_EnableRxCompleteInterrupt(void){
	Std_ReturnType ret = E_OK;
	SET_BIT(USART_UCSRB_REG,USART_UCSRB_RXCIE_BIT);
	return ret;
}

Std_ReturnType USART_DisableRxCompleteInterrupt(void){
	Std_ReturnType ret = E_OK;
	CLR_BIT(USART_UCSRB_REG,USART_UCSRB_RXCIE_BIT);
	return ret;
}

Std_ReturnType USART_EnableDataRegisterEmptyInterrupt(void){
	Std_ReturnType ret = E_OK;
	SET_BIT(USART_UCSRB_REG,USART_UCSRB_UDRIE_BIT);
	return ret;
}

Std_ReturnType USART_DisableDataRegisterEmptyInterrupt(void){
	Std_ReturnType ret = E_OK;
	CLR_BIT(USART_UCSRB_REG,USART_UCSRB_UDRIE_BIT);
	return ret;
}

Std_ReturnType USART_SetTxCompleteCallBack(USART_Cfg_t* _USART_CFG, void(*_callbackfunctionptr)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG || NULL == _callbackfunctionptr){
		ret = E_NOK;
	}
	else{
		USART_TxCompleteCallBack = _callbackfunctionptr;
	}
	return ret;
}

Std_ReturnType USART_SetRxCompleteCallBack(USART_Cfg_t* _USART_CFG, void(*_callbackfunctionptr)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG || NULL == _callbackfunctionptr){
		ret = E_NOK;
	}
	else{
		USART_RxCompleteCallBack = _callbackfunctionptr;
	}
	return ret;
}

Std_ReturnType USART_SetDataRegisterEmptyCallBack(USART_Cfg_t* _USART_CFG, void(*_callbackfunctionptr)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == _USART_CFG || NULL == _callbackfunctionptr){
		ret = E_NOK;
	}
	else{
		USART_DataRegisterEmptyCallBack = _callbackfunctionptr;
	}
	return ret;
}

ISR(USART_TXC_VECTOR){
	if(NULL != USART_TxCompleteCallBack){
		USART_TxCompleteCallBack();
	}
}

ISR(USART_RXC_VECTOR){
	if(NULL != USART_RxCompleteCallBack){
		USART_RxCompleteCallBack();
	}
}

ISR(USART_UDRE_VECTOR){
	if(NULL != USART_DataRegisterEmptyCallBack){
		USART_DataRegisterEmptyCallBack();
	}
}
