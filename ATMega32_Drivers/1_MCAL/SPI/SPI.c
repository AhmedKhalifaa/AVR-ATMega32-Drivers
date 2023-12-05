/*
 * SPI.c
 *
 *      Author: Ahmed Khalifa
 */

#include "../../0_Lib/STD_TYPES.h"
#include "../../0_Lib/BIT_MATH.h"
#include "../../1_MCAL/DIO/DIO.h"
#include "SPI.h"

static void(*SPI_SerialTransferCompleteCallBack)(void) = NULL;

Std_ReturnType SPI_Initialize(SPI_Cfg_t* _SPI_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		ret = SPI_SelectOperationMode(_SPI_CFG,_SPI_CFG->SPI_OperationMode);
		ret = SPI_SetPinsDirection(_SPI_CFG);
		ret = SPI_SelectDataOrder(_SPI_CFG, _SPI_CFG->SPI_DataOrder);
		ret = SPI_SelectClockFrequency(_SPI_CFG, _SPI_CFG->SPI_SerialClockFrequency, _SPI_CFG->SPI_DoubleSpeedMode);
		ret = SPI_SelectClockPolarity(_SPI_CFG, _SPI_CFG->SPI_ClockPolarity);
		ret = SPI_SelectClockPhase(_SPI_CFG, _SPI_CFG->SPI_ClockPhase);
		ret = SPI_Enable(_SPI_CFG);
	}
	return ret;
}

Std_ReturnType SPI_DeInitialize(SPI_Cfg_t* _SPI_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		ret = SPI_Disable(_SPI_CFG);
		ret = SPI_DisableInterrupt();
	}
	return ret;
}

Std_ReturnType SPI_Enable(SPI_Cfg_t* _SPI_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		SET_BIT(SPI_SPCR_REG, SPI_SPCR_SPE_BIT);
	}
	return ret;
}

Std_ReturnType SPI_Disable(SPI_Cfg_t* _SPI_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		CLR_BIT(SPI_SPCR_REG, SPI_SPCR_SPE_BIT);
	}
	return ret;
}

Std_ReturnType SPI_SelectDataOrder(SPI_Cfg_t* _SPI_CFG, SPI_DataOrder_t _data_order){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		switch(_data_order){
			case SPI_DATA_ORDER_MSB_FIRST:
				CLR_BIT(SPI_SPCR_REG, SPI_SPCR_DORD_BIT);
				break;
			case SPI_DATA_ORDER_LSB_FIRST:
				SET_BIT(SPI_SPCR_REG, SPI_SPCR_DORD_BIT);
				break;
			default:
				ret = E_NOK;
				break;
		}
	}
	return ret;
}

Std_ReturnType SPI_SelectOperationMode(SPI_Cfg_t* _SPI_CFG, SPI_OperationMode_t _operation_mode){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		switch(_operation_mode){
			case SPI_OPERATION_MODE_SLAVE:
				CLR_BIT(SPI_SPCR_REG, SPI_SPCR_MSTR_BIT);
				break;
			case SPI_OPERATION_MODE_MASTER:
				SET_BIT(SPI_SPCR_REG, SPI_SPCR_MSTR_BIT);
				break;
			default:
				ret = E_NOK;
		}
	}
	return ret;
}

Std_ReturnType SPI_SetPinsDirection(SPI_Cfg_t* _SPI_CFG){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		//Clearing Directions For All SPI Pins From DDR Registers
		DIO_DDRB_REG &= SPI_PINS_OPERATION_MASK;
		//Setting User-Defined Directions for the SPI Pins
		DIO_DDRB_REG |= ( ((_SPI_CFG->SPI_SS_PinDirection)<<(SPI_SS_PIN)) |
						  ((_SPI_CFG->SPI_MOSI_PinDirection)<<(SPI_MOSI_PIN)) |
						  ((_SPI_CFG->SPI_MISO_PinDirection)<<(SPI_MISO_PIN)) |
						  ((_SPI_CFG->SPI_SCLK_PinDirection)<<(SPI_SCLK_PIN))
						 );
		}
	return ret;
}

Std_ReturnType SPI_SelectClockFrequency(SPI_Cfg_t* _SPI_CFG, SPI_SerialClockFrequency_t _clock_frequency, SPI_DoubleSpeedMode_t _double_speed_status){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		CLR_BIT(SPI_SPSR_REG, SPI_SPSR_SPI2X_BIT);
		SPI_SPCR_REG &= SPI_CLOCK_FREQUENCY_MASK;
		switch(_double_speed_status){
			case SPI_DOUBLE_SPEED_MODE_DISABLED:
				switch(_clock_frequency){
					case SPI_CLOCK_DIV_4:
						break;
					case SPI_CLOCK_DIV_16:
						SPI_SPCR_REG |= SPI_CLOCK_DIV_16;
						break;
					case SPI_CLOCK_DIV_64:
						SPI_SPCR_REG |= SPI_CLOCK_DIV_64;
						break;
					case SPI_CLOCK_DIV_128:
						SPI_SPCR_REG |= SPI_CLOCK_DIV_128;
						break;
					default:
						ret = E_NOK;
						break;
				}
				break;
			case SPI_DOUBLE_SPEED_MODE_ENABLED:
				SET_BIT(SPI_SPSR_REG, SPI_SPSR_SPI2X_BIT);
				switch(_clock_frequency){
					case SPI_CLOCK_DIV_4:
						break;
					case SPI_CLOCK_DIV_16:
						SPI_SPCR_REG |= SPI_CLOCK_DIV_16;
						break;
					case SPI_CLOCK_DIV_64:
						SPI_SPCR_REG |= SPI_CLOCK_DIV_64;
						break;
					case SPI_CLOCK_DIV_128:
						SPI_SPCR_REG |= SPI_CLOCK_DIV_128;
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
	}
	return ret;
}

Std_ReturnType SPI_SelectClockPolarity(SPI_Cfg_t* _SPI_CFG, SPI_ClockPolarity_t _clock_polarity){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		switch(_clock_polarity){
			case SPI_CLOCK_POLARITY_RISING_EDGE_LEADING:
				CLR_BIT(SPI_SPCR_REG, SPI_SPCR_CPOL_BIT);
				break;
			case SPI_CLOCK_POLARITY_FALLING_EDGE_LEADING:
				SET_BIT(SPI_SPCR_REG, SPI_SPCR_CPOL_BIT);
				break;
			default:
				ret =  E_NOK;
				break;
		}
	}
	return ret;
}

Std_ReturnType SPI_SelectClockPhase(SPI_Cfg_t* _SPI_CFG, SPI_ClockPhase_t _clock_phase){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		switch(_clock_phase){
			case SPI_CLOCK_PHASE_SAMPLE_ON_LEADING:
				CLR_BIT(SPI_SPCR_REG, SPI_SPCR_CPHA_BIT);
				break;
			case SPI_CLOCK_PHASE_SAMPLE_ON_TRAILING:
				SET_BIT(SPI_SPCR_REG, SPI_SPCR_CPHA_BIT);
				break;
			default:
				ret =  E_NOK;
				break;
		}
	}
	return ret;
}

Std_ReturnType SPI_SendByteBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t _byte){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		SPI_SPDR_REG = _byte;
		while(0 == READ_BIT(SPI_SPSR_REG,SPI_SPSR_SPIF_BIT)){
		//Do Nothing Until the Transfer is completed
		};
		SET_BIT(SPI_SPSR_REG, SPI_SPSR_SPIF_BIT);	//Clear Interrupt Flag
	}
	return ret;
}

Std_ReturnType SPI_SendByteNonBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t _byte){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		if(1 == READ_BIT(SPI_SPSR_REG, SPI_SPSR_SPIF_BIT)){
		SET_BIT(SPI_SPSR_REG, SPI_SPSR_SPIF_BIT);	//Clear Interrupt Flag
		}
		SPI_SPDR_REG = _byte;
	}
	return ret;
}

Std_ReturnType SPI_ReadByteBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t* _byte){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		while(0 == READ_BIT(SPI_SPSR_REG,SPI_SPSR_SPIF_BIT)){
		//Do Nothing Until the Transfer is completed
		};
		*_byte = SPI_SPDR_REG;
		SET_BIT(SPI_SPSR_REG, SPI_SPSR_SPIF_BIT);	//Clear Interrupt Flag
	}
	return ret;
}

Std_ReturnType SPI_ReadByteNonBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t* _byte);

Std_ReturnType SPI_WriteStringBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t* _str){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG){
		ret = E_NOK;
	}
	else{
		while('\0' != *_str){
			SPI_WriteStringBlocking(_SPI_CFG, *_str);
			_str++;
		}
	}
	return ret;
}

Std_ReturnType SPI_WriteStringNonBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t* _str);

Std_ReturnType SPI_EnableInterrupt(void){
	Std_ReturnType ret = E_OK;
	SET_BIT(SPI_SPCR_REG, SPI_SPCR_SPIE_BIT);
	return ret;
}

Std_ReturnType SPI_DisableInterrupt(void){
	Std_ReturnType ret = E_OK;
	CLR_BIT(SPI_SPCR_REG, SPI_SPCR_SPIE_BIT);
	return ret;
}

Std_ReturnType SPI_SetCallBack(SPI_Cfg_t* _SPI_CFG, void(*_callbackfunctionptr)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == _SPI_CFG || NULL == _callbackfunctionptr){
		ret = E_NOK;
	}
	else{
		SPI_SerialTransferCompleteCallBack = _callbackfunctionptr;
	}
	return ret;
}

ISR(SPI_STC_VECTOR){
	if(NULL != SPI_SerialTransferCompleteCallBack){
		SPI_SerialTransferCompleteCallBack();
	}
}
