/*
 * TIMER0_INTERFACE.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/* Defining the TIMER0 Interrupt Vectors*/
#define TIMER0_OC0_VECTOR	__vector_10
#define TIMER0_OVF0_VECTOR	__vector_11

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */
Std_ReturnType TIMER0_Initialize(TIMER0_Cfg_t* _TIMER0_CFG);
Std_ReturnType TIMER0_DeInitialize(TIMER0_Cfg_t* _TIMER0_CFG);
Std_ReturnType TIMER0_Stop(TIMER0_Cfg_t* _TIMER0_CFG);
Std_ReturnType TIMER0_SetTimerValue(TIMER0_Cfg_t* _TIMER0_CFG, uint8_t _ticks);
Std_ReturnType TIMER0_GetTimerValue(TIMER0_Cfg_t* _TIMER0_CFG, uint8_t* _ticks);
Std_ReturnType TIMER0_SetCompareMatchValue(TIMER0_Cfg_t* _TIMER0_CFG, uint8_t _ticks);
Std_ReturnType TIMER0_GetCompareMatchValue(TIMER0_Cfg_t* _TIMER0_CFG, uint8_t* _ticks);
Std_ReturnType TIMER0_SetPWMDutyCycle(TIMER0_Cfg_t* _TIMER0_CFG, uint8_t _duty_cycle);
Std_ReturnType TIMER0_SelectClock(TIMER0_Cfg_t* _TIMER0_CFG, TIMER0_ClockSource_t _clock_source);
Std_ReturnType TIMER0_SelectMode(TIMER0_Cfg_t* _TIMER0_CFG, TIMER0_OperationMode_t _operation_mode, uint8_t _output_compare_mode);
Std_ReturnType TIMER0_EnableOverFlowInterrupt(void);
Std_ReturnType TIMER0_DisableOverFlowInterrupt(void);
Std_ReturnType TIMER0_EnableCompareMatchInterrupt(void);
Std_ReturnType TIMER0_DisableCompareMatchInterrupt(void);
Std_ReturnType TIMER0_SetOverFlowCallBacK(TIMER0_Cfg_t* _TIMER0_CFG, void(*_callbackfunctionptr)(void));
Std_ReturnType TIMER0_SetCompareMatchCallBacK(TIMER0_Cfg_t* _TIMER0_CFG, void(*_callbackfunctionptr)(void));

#endif /* TIMER0_INTERFACE_H_ */
