/*
 * TIMER_REG.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef TIMER_H_
#define TIMER_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/*Fisrt: Defining Common Timer Registers*/
#define TIMER_TIMSK_REG		HWREG8(0X59)	// Timer/Counter Interrupt Mask Register
#define TIMER_TIFR_REG		HWREG8(0X58)	// Timer/Counter Interrupt Flag Register
#define TIMER_SFIOR_REG		HWREG(0x50)		//Special Function Input Output Register

/*Second: Defining Bits of Common Timer Related Registers*/
//TIMSK Register Bits:
#define TIMER_TIMSK_TOIE0_BIT	0	    //TIMER0 Overflow Interrupt Enable
#define TIMER_TIMSK_OCIE0_BIT	1	    //TIMER0 Output Compare Match Interrupt Enable
#define TIMER_TIMSK_TOIE1_BIT	2	    //TIMER1 Overflow Interrupt Enable
#define TIMER_TIMSK_OCIE1B_BIT	3   	//TIMER1 Output Compare B Match Interrupt Enable
#define TIMER_TIMSK_OCIE1A_BIT	4    	//TIMER1 Output Compare A Match Interrupt Enable
#define TIMER_TIMSK_TICIE1_BIT	5   	//TIMER1 Input Capture Interrupt Enable
#define TIMER_TIMSK_TOIE2_BIT	6	    //TIMER2 Overflow Interrupt Enable
#define TIMER_TIMSK_OCIE2_BIT	7	    //TIMER2 Output Compare Match Interrupt Enable

//TIFR Register Bits:
#define TIMER_TIFR_TOV0_BIT		0		//TIMER0 Overflow Interrupt Flag
#define TIMER_TIFR_OCF0_BIT		1		//TIMER0 Output Compare Match Interrupt Flag
#define TIMER_TIFR_TOV1_BIT		2		//TIMER1 Overflow Interrupt Flag
#define TIMER_TIFR_OCF1B_BIT	3		//TIMER1 Output Compare B Match Interrupt Flag
#define TIMER_TIFR_OCF1A_BIT	4		//TIMER1 Output Compare A Match Interrupt Flag
#define TIMER_TIFR_ICF1_BIT		5		//TIMER1 Input Capture Interrupt Flag
#define TIMER_TIFR_TOV2_BIT		6		//TIMER2 Overflow Interrupt Flag
#define TIMER_TIFR_OCF2_BIT		7		//TIMER2 Output Compare Match Interrupt Flag

//SFIOR Register Bits:
#define TIMER_SFIOR_PSR10		0		//TIMER0 & TIMER1 Prescaler Reset Bit
#define TIMER_SFIOR_PSR2		1		//TIMER2 Prescaler Reset Bit
/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* TIMER_H_ */
