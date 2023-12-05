/*
 * TIMER2_REG.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef TIMER2_REG_H_
#define TIMER2_REG_H_

/* Section : Includes */

/*First: Defining Timer2 Related Registers*/
#define TIMER2_TCCR2_REG 	HWREG8(0x45)		//TIMER2 Timer/Counter Control Register
#define TIMER2_TCNT2_REG	HWREG8(0x44)		//TIMER2 Timer Counter Register
#define TIMER2_OCR2_REG		HWREG8(0x43)		//TIMER2 Output Compare Register
#define TIMER2_ASSR_REG		HWREG8(0x42)		//TIMER2 Asynchronous Status Register

/*Second: Defining Bits of Timer2 Related Registers*/
//TCCR2 Register Bits:
#define TIMER2_TCCR2_CS20_BIT		0	//TIMER2 Clock Selection Bit0
#define TIMER2_TCCR2_CS21_BIT		1	//TIMER2 Clock Selection Bit1
#define TIMER2_TCCR2_CS22_BIT		2	//TIMER2 Clock Selection Bit2
#define TIMER2_TCCR2_WGM21_BIT		3	//TIMER2 Mode Selection Bit1
#define TIMER2_TCCR2_COM20_BIT		4	//TIMER2 Compare Match Output Modes Bit0
#define TIMER2_TCCR2_COM21_BIT		5	//TIMER2 Compare Match Output Modes Bit1
#define TIMER2_TCCR2_WGM20_BIT		6	//TIMER2 Mode Selection Bit0
#define TIMER2_TCCR2_FOC2_BIT		7	//TIMER2 Force Output Compare Match Bit

//ASSR Register Bits:
#define TIMER2_ASSR_TCR2UB_BIT			0	//TIMER2 Timer/Counter Control Register2 Update Busy Bit
#define TIMER2_ASSR_OCR2UB_BIT			1	//TIMER2 Output Compare Register2 Update Busy Bit
#define TIMER2_ASSR_TCN2UB_BIT			2	//TIMER2 Timer/Counter2 Update Busy Bit
#define TIMER2_ASSR_AS2_BIT				3	//TIMER2 Asynchronous Timer/Counter2 Bit

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* TIMER2_REG_H_ */
