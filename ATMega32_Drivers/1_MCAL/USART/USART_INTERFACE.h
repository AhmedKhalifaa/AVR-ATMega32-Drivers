/*
 * USART_INTERFACE.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/* Defining the USART Interrupt Vectors*/
#define USART_RXC_VECTOR	__vector_13
#define USART_UDRE_VECTOR	__vector_14
#define USART_TXC_VECTOR	__vector_15

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */
Std_ReturnType USART_Initialize(USART_Cfg_t* _USART_CFG);
Std_ReturnType USART_DeInitialize(USART_Cfg_t* _USART_CFG);
Std_ReturnType USART_SetClockPolarity(USART_Cfg_t* _USART_CFG, USART_ClockPolarity_t _clock_polarity);
Std_ReturnType USART_SetCharacterSize(USART_Cfg_t* _USART_CFG, USART_CharacterSize_t _character_size);
Std_ReturnType USART_SelectOperationMode(USART_Cfg_t* _USART_CFG, USART_OperationMode_t _operation_mode);
Std_ReturnType USART_SelectCommunicationMode(USART_Cfg_t* _USART_CFG, USART_CommunicationMode_t _communication_mode);
Std_ReturnType USART_SelectClockParity(USART_Cfg_t* _USART_CFG, USART_ClockPolarity_t _clock_parity);
Std_ReturnType USART_SelectStopBit(USART_Cfg_t* _USART_CFG, USART_StopBit_t _stop_bit);
Std_ReturnType USART_SetTransmissionSpeed(USART_Cfg_t* _USART_CFG, USART_TransmissionSpeed_t _transmission_speed);
Std_ReturnType USART_SetBaudRate(USART_Cfg_t* _USART_CFG, uint32_t _baud_rate);
Std_ReturnType USART_SetTransmissionMode(USART_Cfg_t* _USART_CFG, USART_TransmissionMode_t _transmission_mode);
Std_ReturnType USART_WriteByteBlocking(USART_Cfg_t* _USART_CFG, uint16_t _byte);
Std_ReturnType USART_WriteByteNonBlocking(USART_Cfg_t* _USART_CFG, uint16_t _byte);
Std_ReturnType USART_ReadByteBlocking(USART_Cfg_t* _USART_CFG, uint16_t* _byte);
Std_ReturnType USART_ReadByteNonBlocking(USART_Cfg_t* _USART_CFG, uint16_t* _byte);
Std_ReturnType USART_WriteStringBlocking(USART_Cfg_t* _USART_CFG, uint8_t* _str);
Std_ReturnType USART_WriteStringNonBlocking(USART_Cfg_t* _USART_CFG, uint8_t* _str);
Std_ReturnType USART_EnableTxCompleteInterrupt(void);
Std_ReturnType USART_DisableTxCompleteInterrupt(void);
Std_ReturnType USART_EnableRxCompleteInterrupt(void);
Std_ReturnType USART_DisableRxCompleteInterrupt(void);
Std_ReturnType USART_EnableDataRegisterEmptyInterrupt(void);
Std_ReturnType USART_DisableDataRegisterEmptyInterrupt(void);
Std_ReturnType USART_SetTxCompleteCallBack(USART_Cfg_t* _USART_CFG, void(*_callbackfunctionptr)(void));
Std_ReturnType USART_SetRxCompleteCallBack(USART_Cfg_t* _USART_CFG, void(*_callbackfunctionptr)(void));
Std_ReturnType USART_SetDataRegisterEmptyCallBack(USART_Cfg_t* _USART_CFG, void(*_callbackfunctionptr)(void));

#endif /* USART_INTERFACE_H_ */
