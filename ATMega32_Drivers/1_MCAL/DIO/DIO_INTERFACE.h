/*
 * DIO_INTERFACE.h
 *
 *      Author: Ahmed Khalifa
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Section : Includes */

/* Section: Data Type Declarations */

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */
Std_ReturnType DIO_PinDirectionIntialize(const DIO_PinCfg_t *_Pinconfig);
Std_ReturnType DIO_PinGetDirectionStatus(const DIO_PinCfg_t *_Pinconfig, DIO_PinDir_t *Directionstatus);
Std_ReturnType DIO_PinWriteLogic(const DIO_PinCfg_t *_Pinconfig, DIO_PinLvl_t logic);
Std_ReturnType DIO_PinReadLogic(const DIO_PinCfg_t *_Pinconfig, DIO_PinLvl_t *logic);
Std_ReturnType DIO_PinToggleLogic(const DIO_PinCfg_t *_Pinconfig);
Std_ReturnType DIO_PinIntialize(const DIO_PinCfg_t *_Pinconfig);

Std_ReturnType DIO_PortDirectionIntialize(DIO_PortID_t port, DIO_PortDir_t direction);
Std_ReturnType DIO_PortGetDirectionStatus(DIO_PortID_t port, DIO_PortDir_t *Directionstatus);
Std_ReturnType DIO_PortWriteLogic(DIO_PortID_t port, DIO_PortLvl_t logic);
Std_ReturnType DIO_PortReadLogic(DIO_PortID_t port, DIO_PortLvl_t *logic);
Std_ReturnType DIO_PortToggleLogic(DIO_PortID_t port);

#endif /* DIO_INTERFACE_H_ */
