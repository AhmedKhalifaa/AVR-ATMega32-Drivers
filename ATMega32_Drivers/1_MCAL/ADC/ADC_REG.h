/*
 * ADC_REG.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/*First: Defining ADC Related Registers*/
#define ADC_ADMUX_REG 		HWREG8(0x27)		//ADC Multiplexer Selection Register
#define ADC_ADCSRA_REG 		HWREG8(0x26)		//ADC Control and Status Register A
#define ADC_ADCH_REG		HWREG8(0x25)		//ADC Data Register High Byte
#define ADC_ADCL_REG		HWREG8(0x24)		//ADC Data Register Low Byte
#define ADC_ADC_REG			HWREG16(0x24)		//ADC Data Byte Read as a 16 Bit Register
#define ADC_SFIOR_REG		HWREG8(0x50)		//Special Function Input Output Register

/*Second: Defining Bits of ADC Related Registers*/
//ADMUX Register Bits:
#define ADC_ADMUX_MUX0_BIT		0	//Analog Channel and Gain Selection Bit 0
#define ADC_ADMUX_MUX1_BIT		1	//Analog Channel and Gain Selection Bit 1
#define ADC_ADMUX_MUX2_BIT		2	//Analog Channel and Gain Selection Bit 2
#define ADC_ADMUX_MUX3_BIT		3	//Analog Channel and Gain Selection Bit 3
#define ADC_ADMUX_MUX4_BIT		4	//Analog Channel and Gain Selection Bit 4
#define ADC_ADMUX_ADLAR_BIT		5	//ADC Left Adjust Result Bit
#define ADC_ADMUX_REFS0_BIT		6	//Reference Selection Bit 0
#define ADC_ADMUX_REFS1_BIT		7	//Reference Selection Bit 1

//ADCSRA Register Bits:
#define ADC_ADCSRA_ADPS0_BIT	0	//ADC Prescaler Select Bit 0
#define ADC_ADCSRA_ADPS1_BIT	1	//ADC Prescaler Select Bit 1
#define ADC_ADCSRA_ADPS2_BIT	2	//ADC Prescaler Select Bit 2
#define ADC_ADCSRA_ADIE_BIT		3	//ADC Interrupt Enable Bit
#define ADC_ADCSRA_ADIF_BIT		4	//ADC Interrupt Flag Bit
#define ADC_ADCSRA_ADATE_BIT	5	//ADC Auto Trigger Enable Bit
#define ADC_ADCSRA_ADSC_BIT		6	//ADC Start Conversion Bit
#define ADC_ADCSRA_ADEN_BIT		7	//ADC Enable Bit

//SFIOR Register Bits:
#define ADC_SFIOR_ADTS0_BIT		5	//ADC Auto Trigger Source Selection Bit 0
#define ADC_SFIOR_ADTS1_BIT		6	//ADC Auto Trigger Source Selection Bit 1
#define ADC_SFIOR_ADTS2_BIT		7	//ADC Auto Trigger Source Selection Bit 2

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* ADC_REG_H_ */
