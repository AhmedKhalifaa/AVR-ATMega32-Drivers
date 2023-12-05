/*
 * LCD_INTERFACE.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */
Std_ReturnType LCD_4BitInit(const LCD_4Bit_t* LCD);
Std_ReturnType LCD_4BitClearDisplay(const LCD_4Bit_t* LCD);
Std_ReturnType LCD_4BitWriteCharacter(const LCD_4Bit_t* LCD, uint8_t character);
Std_ReturnType LCD_4BitWriteString(const LCD_4Bit_t* LCD,const uint8_t* string);

#endif /* LCD_INTERFACE_H_ */
