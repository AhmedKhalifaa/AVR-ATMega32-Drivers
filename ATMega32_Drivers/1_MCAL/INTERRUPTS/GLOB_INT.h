/*
 * GLOB_INT.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef GLOB_INT_H_
#define GLOB_INT_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */
/*First, we will define ISR function like Macro.
 We used the Attribute ((signal)) to indicate that the call back can be generated using external
 signal, so when the context switching happens, to avoid data loss, the compiler pushes necessary
 registers into the stack, and after the ISR is served, this data is popped again.
 We added the __VA_ARGS__ in case we wanted to add other attributes like ISR_NOBLOCK or ISR_NAKED... etc.
 */
#define ISR(vector,...)\
void vector(void) __attribute__((signal))__VA_ARGS__;\
void vector(void)

/*Second, we Define The SREG Register, responsible for the General Interrupt Enable, and the General Interrupt
  Enable bit (Bit 7)
 */
#define GLOBINT_SREG_REG HWREG8(0x5F)
#define GLOBINT_GIE 7

/* Section: Macro Functions Declarations */
#define SEI() SET_BIT(GLOBINT_SREG_REG,GLOBINT_GIE)
#define CLI() CLR_BIT(GLOBINT_SREG_REG,GLOBINT_GIE)

/* Section: Function Declarations */

#endif /* GLOB_INT_H_ */
