/*
 * BIT_MATH.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*Mask Macro*/
#define MASK(X) 				((uint8_t)1<<X)

/*Bit Manipulation Macros*/
#define SET_BIT(REG,BIT)  		((REG)|=MASK(BIT))
#define CLR_BIT(REG,BIT)  		((REG)&=~MASK(BIT))
#define TOG_BIT(REG,BIT)  		((REG)^=MASK(BIT))
#define READ_BIT(REG,BIT) 		(((REG)>>BIT)&0x01)

#endif /* BIT_MATH_H_ */
