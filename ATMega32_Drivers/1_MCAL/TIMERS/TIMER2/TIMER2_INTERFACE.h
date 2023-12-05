/*
 * TIMER2_INTERFACE.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/* Defining the TIMER2 Interrupt Vectors*/
#define TIMER2_OC2_VECTOR	__vector_4
#define TIMER2_OVF2_VECTOR	__vector_5

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */
Std_ReturnType TIMER2_Initialize(TIMER2_Cfg_t* _TIMER2_CFG);
Std_ReturnType TIMER2_DeInitialize(TIMER2_Cfg_t* _TIMER2_CFG);
Std_ReturnType TIMER2_Stop(TIMER2_Cfg_t* _TIMER2_CFG);
Std_ReturnType TIMER2_SetTimerValue(TIMER2_Cfg_t* _TIMER2_CFG, uint8_t _ticks);
Std_ReturnType TIMER2_GetTimerValue(TIMER2_Cfg_t* _TIMER2_CFG, uint8_t* _ticks);
Std_ReturnType TIMER2_SetCompareMatchValue(TIMER2_Cfg_t* _TIMER2_CFG, uint8_t _ticks);
Std_ReturnType TIMER2_GetCompareMatchValue(TIMER2_Cfg_t* _TIMER2_CFG, uint8_t* _ticks);
Std_ReturnType TIMER2_SetPWMDutyCycle(TIMER2_Cfg_t* _TIMER2_CFG, uint8_t _duty_cycle);
Std_ReturnType TIMER2_SelectClock(TIMER2_Cfg_t* _TIMER2_CFG, TIMER2_ClockSource_t _clock_source);
Std_ReturnType TIMER2_SelectMode(TIMER2_Cfg_t* _TIMER2_CFG, TIMER2_OperationMode_t _operation_mode, uint8_t _output_compare_mode);
Std_ReturnType TIMER2_EnableOverFlowInterrupt(void);
Std_ReturnType TIMER2_DisableOverFlowInterrupt(void);
Std_ReturnType TIMER2_EnableCompareMatchInterrupt(void);
Std_ReturnType TIMER2_DisableCompareMatchInterrupt(void);
Std_ReturnType TIMER2_SetOverFlowCallBacK(TIMER2_Cfg_t* _TIMER2_CFG, void(*_callbackfunctionptr)(void));
Std_ReturnType TIMER2_SetCompareMatchCallBacK(TIMER2_Cfg_t* _TIMER2_CFG, void(*_callbackfunctionptr)(void));

#endif /* TIMER2_INTERFACE_H_ */
