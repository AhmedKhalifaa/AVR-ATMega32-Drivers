/*
 * TIMER1_REG.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/*First: Defining Timer1 Related Registers*/
#define TIMER1_TCCR1A_REG		HWREG8(0x4F)		//TIMER1 Timer/Counter Control Register A
#define TIMER1_TCCR1B_REG		HWREG8(0x4E)		//TIMER1 Timer/Counter Control Register B
#define TIMER1_TCNT1H_REG		HWREG8(0x4D)		//TIMER1 Timer Counter Register High
#define TIMER1_TCNT1L_REG		HWREG8(0x4C)		//TIMER1 Timer Counter Register Low
#define TIMER1_TCNT1_REG		HWREG16(0x4C)		//TIMER1 Timer Counter Register Read as a 16 Bit Register
#define TIMER1_OCR1AH_REG		HWREG8(0x4B)		//TIMER1 Output Compare A Registers High
#define TIMER1_OCR1AL_REG		HWREG8(0x4A)		//TIMER1 Output Compare A Registers Low
#define TIMER1_OCR1A_REG		HWREG16(0x4A)		//TIMER1 Output Compare A Read as a 16 Bit Register
#define TIMER1_OCRB1H_REG		HWREG8(0x49)		//TIMER1 Output Compare B Registers High
#define TIMER1_OCRB1L_REG		HWREG8(0x48)		//TIMER1 Output Compare B Registers Low
#define	TIMER1_OCRB1_REG		HWREG16(0x48)		//TIMER1 Output Compare B Read as a 16 Bit Register
#define TIMER1_ICR1H_REG		HWREG8(0x47)		//TIMER1 Input Capture Registers High
#define TIMER1_ICR1L_REG		HWREG8(0x46)		//TIMER1 Input Capture Registers Low
#define TIMER1_ICR1_REG			HWREG16(0x46)		//TIMER1 Input Capture Read as a 16 Bit Register

/*Second: Defining Bits of Timer1 Related Registers*/

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* TIMER1_REG_H_ */
