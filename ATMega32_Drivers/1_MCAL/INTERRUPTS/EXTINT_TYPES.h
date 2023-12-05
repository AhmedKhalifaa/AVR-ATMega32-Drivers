/*
 * EXTINT_TYPES.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef EXTINT_TYPES_H_
#define EXTINT_TYPES_H_

/* Section : Includes */

/* Section: Data Type Declarations */
typedef enum{
	EXTINT_INT0,
	EXTINT_INT1,
	EXTINT_INT2
} EXTINT_InterruptID_t ;

typedef enum {
	EXTINT_TRIGGER_ON_LOW_LEVEL,
	EXTINT_TRIGGER_ON_BOTH_EDGES,
	EXTINT_TRIGGER_ON_FALLING_EDGE,
	EXTINT_TRIGGER_ON_RISING_EDGE
} EXTINT_InterruptTrigger_t ;

typedef enum{
	EXTINT_DISABLED,
	EXTINT_ENABLED
} EXTINT_InterruptStatus_t;

typedef struct {
	DIO_PinCfg_t 				EXTINT_PinCfg;
	EXTINT_InterruptID_t 		EXTINT_InterruptID : 2;
	EXTINT_InterruptTrigger_t	EXTINT_InterruptTrigger : 2;
	EXTINT_InterruptStatus_t	EXTINT_InterruptStatus : 1;
} EXTINT_InterruptConfig_t;


/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* EXTINT_TYPES_H_ */
