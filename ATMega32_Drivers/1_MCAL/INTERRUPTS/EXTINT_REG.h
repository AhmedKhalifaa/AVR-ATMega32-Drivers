/*
 * EXTINT_REG.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef EXTINT_REG_H_
#define EXTINT_REG_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */
/*Defining The External Interrupts' Registers*/
#define EXTINT_GICR_REG 		HWREG8(0x5B)		//General Interrupt Control Register
#define EXTINT_GIFR_REG 		HWREG8(0x5A)		//General Interrupt Flag Register
#define EXTINT_MCUCR_REG 		HWREG8(0x55)		//MCU Control Register
#define EXTINT_MCUCSR_REG 		HWREG8(0x54)		//MCU Control & Status Register

/*Defining The Interrupt Enable: INT0, INT1 & INT2 Bits' Positions in the GICR*/
#define EXTINT_INT0_BIT 6
#define EXTINT_INT1_BIT 7
#define EXTINT_INT2_BIT 5

/*Defining The Interrupt Flags: INTF0, INTF1 & INTF2 Bits' Positions in the GIFR*/
#define EXTINT_INTF0_BIT 6
#define EXTINT_INTF1_BIT 7
#define EXTINT_INTF2_BIT 5

/*Defining The Interrupt Sense Control Bits: ISC00 & ISC01 for INT0, ISC10 & ISC11 for INT1 Bits' Positions in the MCUCR*/
#define EXTINT_ISC00_BIT 0
#define EXTINT_ISC01_BIT 1
#define EXTINT_ISC10_BIT 2
#define EXTINT_ISC11_BIT 3

/*Defining The Interrupt Sense Control Bit: ISC2 for INT2 Bit's Position in the MCUCSR*/
#define EXTINT_ISC2_BIT 6

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* EXTINT_REG_H_ */
