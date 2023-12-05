/*
 * DIO_REG.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */
/*Defining DDRx Registers*/
#define DIO_DDRA_REG 		HWREG8(0x3A)
#define DIO_DDRB_REG 		HWREG8(0x37)
#define DIO_DDRC_REG 		HWREG8(0x34)
#define DIO_DDRD_REG 		HWREG8(0x31)

/*Defining PORTx Registers*/
#define DIO_PORTA_REG 		HWREG8(0x3B)
#define DIO_PORTB_REG 		HWREG8(0x38)
#define DIO_PORTC_REG 		HWREG8(0x35)
#define DIO_PORTD_REG 		HWREG8(0x32)

/*Defining PINx Registers*/
#define DIO_PINA_REG 		HWREG8(0x39)
#define DIO_PINB_REG 		HWREG8(0x36)
#define DIO_PINC_REG 		HWREG8(0x33)
#define DIO_PIND_REG 		HWREG8(0x30)

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* DIO_REG_H_ */
