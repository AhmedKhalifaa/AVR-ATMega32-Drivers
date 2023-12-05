/*
 * LCD_TYPES.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef LCD_TYPES_H_
#define LCD_TYPES_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* LCD Commands */
typedef enum {
	/*Display Clear and Return Home Commands*/
	LCD_DISP_CLR = 0X01,
	LCD_RET_HOME = 0X02,

	/*Defining LCD Commands*/
	LCD_SET_EIGHT_BIT = 0X38, //Sets 2 Lines and 5x7 Matrix (D0 - D7, 8 Bit)
	LCD_SET_FOUR_BIT  = 0X28, //Sets 2 Lines and 5x7 Matrix (D4 - D7, 4 Bit)

	/*Display On Commands*/
	LCD_DISP_ON_CURS_OFF   = 0X0C, //Display On Cursor Off
	LCD_DISP_ON_CURS_ON    = 0X0E, //Display On Cursor On
	LCD_DISP_ON_CURS_BLINK = 0X0F, //Display On Cursor Blinking

	/*Display Off Commands*/
	LCD_DISP_OFF_CURS_OFF   = 0X08, //Display Off Cursor Off
	LCD_DISP_OFF_CURS_ON    = 0X0A, //Display Off Cursor On
	LCD_DISP_SHIFT_RIGHT	= 0X1C, //Shift The Entire Display to the Right
	LCD_DISP_SHIFT_LEFT		= 0X18, //Shift The Entire Display to the Left

	/*Cursor Commands*/
	LCD_CURS_INC             = 0X06, //Shift Cursor Right
	LCD_CURS_DEC             = 0X04, //Shift Cursor Left
	LCD_CURS_RIGHT           = 0X14, //Shift Cursor Position to the Right
	LCD_CURS_LEFT            = 0X10, //Shift Cursor Position to the Left
	LCD_CURS_FIRST_LINE      = 0X80, //Force Cursor Position to beginning of the First Line
	LCD_CURS_SECOND_LINE     = 0XC0 //Force Cursor Position to beginning of the Second Line

} LCD_Cmd_t;

/* LCD Object Type */
typedef struct {
	DIO_PinCfg_t LCD_RSPin;
	DIO_PinCfg_t LCD_RWPin;
	DIO_PinCfg_t LCD_ENPin;
	DIO_PinCfg_t LCD_DataPins [4];
} LCD_4Bit_t;


/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

#endif /* LCD_TYPES_H_ */
