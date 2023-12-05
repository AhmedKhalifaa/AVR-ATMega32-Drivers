/*
 * LED_TYPES.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef LED_TYPES_H_
#define LED_TYPES_H_

/* Section : Includes */

/* Section: Data Type Declarations */
typedef enum{
    LED_OFF,
    LED_ON
}LED_Status_t;

typedef struct{
	DIO_PortID_t PortID		: 3;
	DIO_PinID_t  PinID 		: 3;
    LED_Status_t LED_Status : 1;
}LED_t;
/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* 2_ECUAL_LED_LED_TYPES_H_ */
