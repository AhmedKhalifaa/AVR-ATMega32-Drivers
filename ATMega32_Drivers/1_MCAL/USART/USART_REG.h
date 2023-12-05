/*
 * USART_REG.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef USART_REG_H_
#define USART_REG_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/*First: Defining USART Related Registers*/
#define USART_UDR_REG		HWREG8(0x2C)		//USART I/O Data Register
#define USART_UCSRA_REG		HWREG8(0x2B)		//USART Control and Status Register A
#define USART_UCSRB_REG		HWREG8(0x2A)		//USART Control and Status Register B
#define USART_UCSRC_REG		HWREG8(0x40)		//USART Control and Status Register C
#define USART_UBRRL_REG		HWREG8(0x29)		//USART Baud Rate Register Low
#define USART_UBRRH_REG		HWREG8(0x40)		//USART Baud Rate Register High

/*Second: Defining Bits of USART Related Registers*/
//USART UCSRA Register Bits:
#define USART_UCSRA_MPCM_BIT	0		//USART Multi-processor Communication Mode Bit
#define USART_UCSRA_U2X_BIT		1		//USART Double the USART Transmission Speed Bit
#define USART_UCSRA_PE_BIT		2		//USART Parity Error Bit
#define USART_UCSRA_DOR_BIT		3       //USART Data OverRun Bit
#define USART_UCSRA_FE_BIT		4       //USART Frame Error Bit
#define USART_UCSRA_UDRE_BIT	5       //USART Data Register Empty
#define USART_UCSRA_TXC_BIT		6       //USART Transmit Complete
#define USART_UCSRA_RXC_BIT		7       //USART Receive Complete

//USART UCSRB Register Bits:
#define USART_UCSRB_TXB8_BIT	0		//USART Transmit Data Bit8
#define USART_UCSRB_RXB8_BIT	1       //USART Receive Data Bit8
#define USART_UCSRB_UCSZ2_BIT	2       //USART Character Size Bit2
#define USART_UCSRB_TXEN_BIT	3       //USART Transmitter Enable
#define USART_UCSRB_RXEN_BIT	4       //USART Receiver Enable
#define USART_UCSRB_UDRIE_BIT	5       //USART Data Register Empty Interrupt Enable
#define USART_UCSRB_TXCIE_BIT	6       //USART TX Complete Interrupt Enable
#define USART_UCSRB_RXCIE_BIT	7       //USART RX Complete Interrupt Enable

//USART UCSRC Register Bits:
#define USART_UCSRC_UCPOL_BIT	0		//USART	Clock Polarity Bit
#define USART_UCSRC_UCSZ0_BIT	1       //USART Character Size Bit0
#define USART_UCSRC_UCSZ1_BIT	2       //USART Character Size Bit1
#define USART_UCSRC_USBS_BIT	3		//USART Stop Bit Select Bit
#define USART_UCSRC_UPM0_BIT	4		//USART Parity Mode Bit0
#define USART_UCSRC_UPM1_BIT	5       //USART Parity Mode Bit1
#define USART_UCSRC_UMSEL_BIT	6		//USART Mode Select Bit
#define USART_UCSRC_URSEL_BIT	7		//USART	Register Select Bit

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* USART_REG_H_ */
