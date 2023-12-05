/*
 * SPI_INTERFACE.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */
/* Defining the SPI Interrupt Vector*/
#define SPI_STC_VECTOR	__vector_12

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */
Std_ReturnType SPI_Initialize(SPI_Cfg_t* _SPI_CFG);
Std_ReturnType SPI_DeInitialize(SPI_Cfg_t* _SPI_CFG);
Std_ReturnType SPI_Enable(SPI_Cfg_t* _SPI_CFG);
Std_ReturnType SPI_Disable(SPI_Cfg_t* _SPI_CFG);
Std_ReturnType SPI_SelectDataOrder(SPI_Cfg_t* _SPI_CFG, SPI_DataOrder_t _data_order);
Std_ReturnType SPI_SelectOperationMode(SPI_Cfg_t* _SPI_CFG, SPI_OperationMode_t _operation_mode);
Std_ReturnType SPI_SetPinsDirection(SPI_Cfg_t* _SPI_CFG);
Std_ReturnType SPI_SelectClockFrequency(SPI_Cfg_t* _SPI_CFG, SPI_SerialClockFrequency_t _clock_frequency, SPI_DoubleSpeedMode_t _double_speed_status);
Std_ReturnType SPI_SelectClockPolarity(SPI_Cfg_t* _SPI_CFG, SPI_ClockPolarity_t _clock_polarity);
Std_ReturnType SPI_SelectClockPhase(SPI_Cfg_t* _SPI_CFG, SPI_ClockPhase_t _clock_phase);
Std_ReturnType SPI_SendByteBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t _byte);
Std_ReturnType SPI_SendByteNonBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t _byte);
Std_ReturnType SPI_ReadByteBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t* _byte);
Std_ReturnType SPI_ReadByteNonBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t* _byte);
Std_ReturnType SPI_WriteStringBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t* _str);
Std_ReturnType SPI_WriteStringNonBlocking(SPI_Cfg_t* _SPI_CFG, uint8_t* _str);
Std_ReturnType SPI_EnableInterrupt(void);
Std_ReturnType SPI_DisableInterrupt(void);
Std_ReturnType SPI_SetCallBack(SPI_Cfg_t* _SPI_CFG, void(*_callbackfunctionptr)(void));

#endif /* SPI_INTERFACE_H_ */
