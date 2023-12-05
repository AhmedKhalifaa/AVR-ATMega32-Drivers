/*
 * STD_TYPES.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/*Numeric Data Types*/
typedef unsigned char 			uint8_t;
typedef unsigned int 			uint16_t;
typedef unsigned long int 		uint32_t;
typedef unsigned long long int 	uint64_t;
typedef signed char 			sint8_t;
typedef signed short int 		sint16_t;
typedef signed long int 		sint32_t;
typedef signed long long int 	sint64_t;
typedef float 					f32_t;
typedef double 					f64_t;
typedef long double 			f128_t;

/*Boolean Data Type*/
typedef enum{
	False,
	True
}bool;

typedef enum {
	E_NOK,
	E_OK
} Std_ReturnType;

/* Section: Macro Declarations */
#define STD_HIGH       0x01
#define STD_LOW        0x00

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

/*Hardware Registers*/
#define HWREG8(REG) 	(*((volatile uint8_t*)(REG)))
#define HWREG16(REG) 	(*((volatile uint16_t*)(REG)))
#define HWREG32(REG) 	(*((volatile uint32_t*)(REG)))

/*Null Pointer*/
#define NULL ((void*) 0)

#define ZERO_INIT 0

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */


#endif /* STD_TYPES_H_ */
