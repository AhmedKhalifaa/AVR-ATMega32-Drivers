/*
 * LED_INTERFACE.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */
Std_ReturnType LED_Initialize(const LED_t *LED);
Std_ReturnType LED_TurnOn(LED_t *LED);
Std_ReturnType LED_TurnOff(LED_t *LED);
Std_ReturnType LED_Toggle(LED_t *LED);

#endif /* 2_ECUAL_LED_LED_INTERFACE_H_ */
