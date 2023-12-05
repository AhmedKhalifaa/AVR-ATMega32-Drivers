/*
 * EXTINT_INTERFACE.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef EXTINT_INTERFACE_H_
#define EXTINT_INTERFACE_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/*Defining the EXTINT Vectors*/
#define INT0_VECTOR __vector_1
#define INT1_VECTOR __vector_2
#define INT2_VECTOR __vector_3

/* Section: Function Declarations */
Std_ReturnType EXTINT_Initialize(EXTINT_InterruptConfig_t* _EXTINT_CFG);
Std_ReturnType EXTINT_DeInitialize(EXTINT_InterruptConfig_t* _EXTINT_CFG);
Std_ReturnType EXTINT_Enable(EXTINT_InterruptConfig_t* _EXTINT_CFG);
Std_ReturnType EXTINT_Disable(EXTINT_InterruptConfig_t* _EXTINT_CFG);
Std_ReturnType EXTINT_SetTrigger(EXTINT_InterruptConfig_t* _EXTINT_CFG,EXTINT_InterruptTrigger_t trigger);
Std_ReturnType EXTINT_SetCallBack(EXTINT_InterruptConfig_t* _EXTINT_CFG, void(*_callbackfunctionptr)(void));

#endif /* EXTINT_INTERFACE_H_ */
