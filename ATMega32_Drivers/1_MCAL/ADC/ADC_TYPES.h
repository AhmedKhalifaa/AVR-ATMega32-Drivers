/*
 * ADC_TYPES.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

/* Section : Includes */

/* Section: Data Type Declarations */
typedef enum{
	ADC_CHANNEL_ADC0,
	ADC_CHANNEL_ADC1,
	ADC_CHANNEL_ADC2,
	ADC_CHANNEL_ADC3,
	ADC_CHANNEL_ADC4,
	ADC_CHANNEL_ADC5,
	ADC_CHANNEL_ADC6,
	ADC_CHANNEL_ADC7,
} ADC_ChannelSelect_t;

typedef enum{
	ADC_PRESCALER_DIV_1,
	ADC_PRESCALER_DIV_2,
	ADC_PRESCALER_DIV_4,
	ADC_PRESCALER_DIV_8,
	ADC_PRESCALER_DIV_16,
	ADC_PRESCALER_DIV_32,
	ADC_PRESCALER_DIV_64,
	ADC_PRESCALER_DIV_128
} ADC_PrescalerSelect_t;

typedef enum{
	ADC_TRIGGER_SOURCE_FREE_RUNNING,
	ADC_TRIGGER_SOURCE_ANALOG_COMPARATOR,
	ADC_TRIGGER_SOURCE_EXTERNAL_INTERRUPT_REQUEST0,
	ADC_TRIGGER_SOURCE_TIMER0_COMPARE_MATCH,
	ADC_TRIGGER_SOURCE_TIMER0_OVERFLOW,
	ADC_TRIGGER_SOURCE_TIMER1_COMPARE_MATCH_B,
	ADC_TRIGGER_SOURCE_TIMER1_OVERFLOW,
	ADC_TRIGGER_SOURCE_TIMER1_CAPTURE_EVENT
} ADC_TriggerSource_t;

typedef enum {
	ADC_VOLTAGE_AREF = 0,
	ADC_VOLTAGE_AVCC = 1,
	ADC_VOLTAGE_RESERVED = 2,
	ADC_VOLTAGE_INTERNAL = 3
} ADC_VoltageReference_t;

typedef enum{
	ADC_AUTOTRIGGER_DISABLED,
	ADC_AUTOTRIGGER_ENABLED
} ADC_AutoTriggerStatus_t;

typedef enum{
	ADC_RIGHT_ADJUST,
	ADC_LEFT_ADJUST
} ADC_ResultAdjustDirection;

typedef struct{
	ADC_ChannelSelect_t 		ADC_Channel : 3;
	ADC_PrescalerSelect_t 		ADC_Prescaler : 3;
	ADC_TriggerSource_t 		ADC_TriggerSource : 3;
	ADC_VoltageReference_t		ADC_VoltageReference : 2;
	ADC_AutoTriggerStatus_t		ADC_AutoTriggerStatus : 1;
	ADC_ResultAdjustDirection	ADC_ResultAdjust : 1;
} ADC_Cfg_t;

/* Section: Macro Declarations */

/* Defining Masks for ADC Registers' Bits*/
#define ADC_PRESCALER_MASK 				0xF8
#define ADC_MUX_MASK 					0xE0
#define ADC_AUTO_TRIGGER_SOURCE_MASK	0x1F
#define ADC_VOLTAGE_SELECT_MASK			0x3F

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* ADC_TYPES_H_ */
