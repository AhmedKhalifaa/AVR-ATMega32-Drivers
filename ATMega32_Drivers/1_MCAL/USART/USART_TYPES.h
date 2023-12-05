/*
 * USART_TYPES.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef USART_TYPES_H_
#define USART_TYPES_H_

/* Section : Includes */

/* Section: Data Type Declarations */
typedef enum
{
	USART_OPERATION_MODE_ASYNCHRONOUS,
	USART_OPERATION_MODE_SYNCHRONOUS
} USART_OperationMode_t;

typedef enum{
	USART_TRANSMISSION_MODE_DISABLED,
	USART_TRANSMISSION_MODE_HALF_DUPLEX_TRANSMITTER,
	USART_TRANSMISSION_MODE_HALF_DUPLEX_RECIEVER,
	USART_TRANSMISSION_MODE_FULL_DUPLEX
} USART_TransmissionMode_t;

typedef enum
{
	USART_TRANSMISSION_SPEED_NORMAL,
	USART_TRANSMISSION_SPEED_DOUBLE
} USART_TransmissionSpeed_t;

typedef enum
{
	USART_COMMUNICATION_MODE_SINGLE_PROCESSOR,
	USART_COMMUNICATION_MODE_MULTI_PROCESSOR
} USART_CommunicationMode_t;

typedef enum
{
	USART_PARITY_MODE_DISABLE,
	USART_PARITY_MODE_EVEN_PARITY = 2,
	USART_PARITY_MODE_ODD_PARITY = 3
} USART_ParityMode_t;

typedef enum
{
	USART_STOP_BITS_1BIT,
	USART_STOP_BITS_2BITS
} USART_StopBit_t;

typedef enum
{
	USART_CHARACTER_SIZE_5BITS,
	USART_CHARACTER_SIZE_6BITS,
	USART_CHARACTER_SIZE_7BITS,
	USART_CHARACTER_SIZE_8BITS,
	USART_CHARACTER_SIZE_9BITS = 7
} USART_CharacterSize_t;

typedef enum
{
	USART_CLOCK_POLARITY_TRANSMIT_ON_RISING_EDGE,
	USART_CLOCK_POLARITY_TRANSMIT_ON_FALLING_EDGE
} USART_ClockPolarity_t;

typedef struct{
	uint32_t 						USART_BaudRate;
	USART_CharacterSize_t			USART_CharacterSize : 3;
	USART_ParityMode_t				USART_ParityMode : 2;
	USART_TransmissionMode_t 		USART_TransmissionMode : 2;
	USART_OperationMode_t 			USART_OperationMode : 1;
	USART_TransmissionSpeed_t		USART_TransmissionSpeed : 1;
	USART_CommunicationMode_t		USART_CommunicationMode : 1;
	USART_StopBit_t					USART_StopBit : 1;
	USART_ClockPolarity_t			USART_ClockPolarity : 1;
} USART_Cfg_t;

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Defining Masks for USART Registers' Bits*/
#define USART_CHARACTER_SIZE_MASK	0xF9
#define USART_CLOCK_PARITY_MASK		0xCF

/* Section: Function Declarations */

#endif /* USART_TYPES_H_ */
