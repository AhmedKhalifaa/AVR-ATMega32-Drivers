/*
 * ADC_INTERFACE.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/* Defining the ADC Interrupt Vector*/
#define ADC_VECTOR __vector_16

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */
Std_ReturnType ADC_Initialize(ADC_Cfg_t* _ADC_CFG);
Std_ReturnType ADC_Deinitilaze(ADC_Cfg_t* _ADC_CFG);
Std_ReturnType ADC_Enable(void);
Std_ReturnType ADC_Disable(void);
Std_ReturnType ADC_SetPrescaler(ADC_Cfg_t* _ADC_CFG, ADC_PrescalerSelect_t _prescaler);
Std_ReturnType ADC_SelectChannel(ADC_Cfg_t* _ADC_CFG, ADC_ChannelSelect_t _channel);
Std_ReturnType ADC_EnableInterrupt(void);
Std_ReturnType ADC_DisableInterrupt(void);
Std_ReturnType ADC_SelectVoltageReference(ADC_Cfg_t* _ADC_CFG, ADC_VoltageReference_t _voltage);
Std_ReturnType ADC_EnableAutoTrigger(ADC_Cfg_t* _ADC_CFG);
Std_ReturnType ADC_DisableAutoTrigger(ADC_Cfg_t* _ADC_CFG);
Std_ReturnType ADC_SetTriggerSource(ADC_Cfg_t* _ADC_CFG, ADC_TriggerSource_t _trigger);
Std_ReturnType ADC_ReadResult(ADC_Cfg_t* _ADC_CFG, uint16_t* _adc_result);
Std_ReturnType ADC_SetCallBack(ADC_Cfg_t* _ADC_CFG, void(*_callbackfunctionptr)(void));
Std_ReturnType ADC_StartConversion();

#endif /* ADC_INTERFACE_H_ */
