/*
 * TIMER0_REG.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/*First: Defining Timer0 Related Registers*/
#define TIMER0_TCCR0_REG	HWREG8(0x53)	//TIMER0 Timer/Counter Control Register
#define TIMER0_TCNT0_REG	HWREG8(0x52)	//TIMER0 Timer Counter Register
#define TIMER0_OCR0_REG		HWREG8(0x5C)	//TIMER0 Output Compare Register

/*Second: Defining Bits of Timer0 Related Registers*/
//TCCR0 Register Bits:
#define TIMER0_TCCR0_CS00_BIT		0	//Timer0 Clock Selection Bit0
#define TIMER0_TCCR0_CS01_BIT		1	//Timer0 Clock Selection Bit1
#define TIMER0_TCCR0_CS02_BIT		2	//Timer0 Clock Selection Bit2
#define TIMER0_TCCR0_WGM01_BIT		3	//Timer0 Mode Selection Bit1
#define TIMER0_TCCR0_COM00_BIT		4	//Timer0 Compare Match Output Modes Bit0
#define TIMER0_TCCR0_COM01_BIT		5	//Timer0 Compare Match Output Modes Bit1
#define TIMER0_TCCR0_WGM00_BIT		6	//Timer0 Mode Selection Bit0
#define TIMER0_TCCR0_FOC0_BIT		7	//Timer0 Force Output Compare Match Bit

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* TIMER0_REG_H_ */
