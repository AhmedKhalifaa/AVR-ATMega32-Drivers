/*
 * SPI_REG.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef SPI_REG_H_
#define SPI_REG_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/*First: Defining SPI Related Registers*/
#define SPI_SPCR_REG    HWREG8(0X2D)		//SPI Control Register
#define SPI_SPSR_REG    HWREG8(0X2E)		//SPI Status Register
#define SPI_SPDR_REG    HWREG8(0X2F)		//SPI Data Register

/*Second: Defining Bits of SPI Related Registers*/
//SPI SPCR Register Bits:
#define SPI_SPCR_SPR0_BIT		0		//SPI Clock Rate Select Bit0
#define SPI_SPCR_SPR1_BIT		1		//SPI Clock Rate Select Bit1
#define SPI_SPCR_CPHA_BIT		2		//SPI Clock Phase Bit
#define SPI_SPCR_CPOL_BIT		3		//SPI Clock Polarity Bit
#define SPI_SPCR_MSTR_BIT		4		//SPI Master/Slave Select Bit
#define SPI_SPCR_DORD_BIT		5		//SPI Data Order Bit
#define SPI_SPCR_SPE_BIT		6		//SPI Enable Bit
#define SPI_SPCR_SPIE_BIT		7		//SPI Interrupt Enable Bit

//SPI SPSR Register Bits:
#define SPI_SPSR_SPI2X_BIT		0		//SPI Double Speed Bit
#define SPI_SPSR_WCOL_BIT		6		//SPI Write Collision Flag Bit
#define SPI_SPSR_SPIF_BIT		7		//SPI Interrupt Flag Bit

/*Defining SPI Pins*/
#define SPI_SS_PIN				DIO_PIN4
#define SPI_MOSI_PIN			DIO_PIN5
#define SPI_MISO_PIN			DIO_PIN6
#define SPI_SCLK_PIN			DIO_PIN7

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* SPI_REG_H_ */
