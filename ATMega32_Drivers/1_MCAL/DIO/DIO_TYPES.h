/*
 * DIO_TYPES.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

/* Section : Includes */

/* Section: Data Type Declarations */
typedef enum {
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
	} DIO_PortID_t;

typedef enum {
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
	} DIO_PinID_t;

typedef enum {
	DIO_PORT_INPUT=0X00,
	DIO_PORT_OUTPUT=0XFF
	} DIO_PortDir_t;

typedef enum {
	DIO_PIN_INPUT,
	DIO_PIN_OUTPUT
	} DIO_PinDir_t;

typedef enum {
	DIO_PORT_LOW=0X00,
	DIO_PORT_HIGH=0XFF
	} DIO_PortLvl_t;

typedef enum {
	DIO_PIN_LOW,
	DIO_PIN_HIGH
	} DIO_PinLvl_t;

typedef struct {
	DIO_PortID_t PortID : 3;
	DIO_PinID_t  PinID  : 3;
	DIO_PinDir_t PinDir : 1;
	DIO_PinLvl_t PinLvl : 1;
	}DIO_PinCfg_t;

/* Section: Macro Declarations */
#define MAX_PORT_ID 3
#define MAX_PIN_ID  7

#define MAX_PORT_NUMBER 4
#define MAX_PIN_NUMBER  8

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* 1_MCAL_DIO_DIO_TYPES_H_ */
