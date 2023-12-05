/*
 * SPI_TYPES.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_

/* Section : Includes */

/* Section: Data Type Declarations */
typedef enum{
	SPI_OPERATION_MODE_SLAVE,
	SPI_OPERATION_MODE_MASTER
} SPI_OperationMode_t;

typedef enum{
	SPI_DATA_ORDER_MSB_FIRST,
	SPI_DATA_ORDER_LSB_FIRST
} SPI_DataOrder_t;

typedef enum{
	SPI_CLOCK_DIV_4,
	SPI_CLOCK_DIV_16,
	SPI_CLOCK_DIV_64,
	SPI_CLOCK_DIV_128
} SPI_SerialClockFrequency_t;

typedef enum{
	SPI_CLOCK_POLARITY_RISING_EDGE_LEADING,
	SPI_CLOCK_POLARITY_FALLING_EDGE_LEADING
} SPI_ClockPolarity_t;

typedef enum{
	SPI_CLOCK_PHASE_SAMPLE_ON_LEADING,
	SPI_CLOCK_PHASE_SAMPLE_ON_TRAILING
} SPI_ClockPhase_t;

typedef enum{
	SPI_DOUBLE_SPEED_MODE_DISABLED,
	SPI_DOUBLE_SPEED_MODE_ENABLED
} SPI_DoubleSpeedMode_t;

typedef struct{
	SPI_SerialClockFrequency_t		SPI_SerialClockFrequency : 2;
	SPI_OperationMode_t				SPI_OperationMode : 1;
	SPI_DataOrder_t					SPI_DataOrder : 1;
	SPI_ClockPolarity_t				SPI_ClockPolarity : 1;
	SPI_ClockPhase_t				SPI_ClockPhase : 1;
	SPI_DoubleSpeedMode_t			SPI_DoubleSpeedMode : 1;
	DIO_PinDir_t					SPI_SS_PinDirection : 1;
	DIO_PinDir_t					SPI_MOSI_PinDirection : 1;
	DIO_PinDir_t    				SPI_MISO_PinDirection : 1;
	DIO_PinDir_t    				SPI_SCLK_PinDirection : 1;
} SPI_Cfg_t;

/* Section: Macro Declarations */

/* Defining Masks for SPI Registers' Bits*/
#define SPI_CLOCK_FREQUENCY_MASK	0xFC
#define SPI_PINS_OPERATION_MASK		0xF0

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* SPI_TYPES_H_ */
