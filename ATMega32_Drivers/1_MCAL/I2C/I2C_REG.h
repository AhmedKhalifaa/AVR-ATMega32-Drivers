/*
 * I2C_REG.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef I2C_REG_H_
#define I2C_REG_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/*First: Defining I2C Related Registers*/
#define I2C_TWBR_REG    HWREG8(0x20)	//I2C TWI Bit Rate Register
#define I2C_TWSR_REG    HWREG8(0x21)	//I2C TWI Status Register
#define I2C_TWAR_REG    HWREG8(0x22)	//I2C TWI (Slave) Address Register
#define I2C_TWDR_REG    HWREG8(0x23)	//I2C TWI Data Register
#define I2C_TWCR_REG    HWREG8(0x56)	//I2C TWI Control Register

/*Second: Defining Bits of I2C Related Registers*/
//I2C TWSR Register Bits:
#define I2C_TWSR_TWPS0_BIT		0		//I2C Prescaler Bit0
#define I2C_TWSR_TWPS1_BIT		1		//I2C Prescaler Bit1
#define I2C_TWSR_TWS3_BIT		3		//I2C Status Bit3
#define I2C_TWSR_TWS4_BIT		4		//I2C Status Bit4
#define I2C_TWSR_TWS5_BIT		5		//I2C Status Bit5
#define I2C_TWSR_TWS6_BIT		6		//I2C Status Bit6
#define I2C_TWSR_TWS7_BIT		7		//I2C Status Bit7

//I2C TWAR Register Bits:
#define I2C_TWAR_TWGCE_BIT		0		//I2C General Call Recognition Enable Bit

//I2C TWCR Register Bits:
#define I2C_TWCR_TWIE_BIT		0		//I2C Interrupt Enable Bit
#define I2C_TWCR_TWEN_BIT		2		//I2C Enable Bit
#define I2C_TWCR_TWWC_BIT		3		//I2C Write Collision Flag Bit
#define I2C_TWCR_TWSTO_BIT		4		//I2C STOP Condition Bit
#define I2C_TWCR_TWSTA_BIT		5		//I2C START Condition Bit
#define I2C_TWCR_TWEA_BIT		6		//I2C Enable Acknowledge Bit
#define I2C_TWCR_TWINT_BIT		7		//I2C Interrupt Flag Bit

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* I2C_REG_H_ */
