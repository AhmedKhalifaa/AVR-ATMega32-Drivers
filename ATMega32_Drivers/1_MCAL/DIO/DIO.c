/*
 * DIO.c
 *
 *      Author: Ahmed Khalifa
 */

#include "../../0_Lib/STD_TYPES.h"
#include "../../0_Lib/BIT_MATH.h"
#include "DIO.h"

volatile uint8_t* DDRX[MAX_PORT_NUMBER] = {&DIO_DDRA_REG, &DIO_DDRB_REG, &DIO_DDRC_REG, &DIO_DDRD_REG};

volatile uint8_t* PORTX[MAX_PORT_NUMBER] = {&DIO_PORTA_REG, &DIO_PORTB_REG, &DIO_PORTC_REG, &DIO_PORTD_REG};

volatile uint8_t* PINX[MAX_PORT_NUMBER] = {&DIO_PINA_REG, &DIO_PINB_REG, &DIO_PINC_REG, &DIO_PIND_REG};


Std_ReturnType DIO_PinDirectionIntialize(const DIO_PinCfg_t *_Pinconfig){
	Std_ReturnType ret = E_OK;
	if(NULL ==_Pinconfig || ((_Pinconfig->PortID)>MAX_PORT_ID)||((_Pinconfig->PinID)>MAX_PIN_ID)){
		ret=E_NOK;
	}
	else{
		switch(_Pinconfig->PinDir){
			case DIO_PIN_OUTPUT:
				SET_BIT(*DDRX[_Pinconfig->PortID],(_Pinconfig->PinID));
				break;
			case DIO_PIN_INPUT:
				CLR_BIT(*DDRX[_Pinconfig->PortID],(_Pinconfig->PinID));
				break;
			default:
				ret=E_NOK;
		}
	}
	return ret;
};


Std_ReturnType DIO_PinGetDirectionStatus(const DIO_PinCfg_t *_Pinconfig, DIO_PinDir_t *Directionstatus){
	Std_ReturnType ret = E_OK;
	if(NULL ==_Pinconfig || NULL == Directionstatus || ((_Pinconfig->PortID)>MAX_PORT_ID)||((_Pinconfig->PinID)>MAX_PIN_ID)){
		ret=E_NOK;
	}
	else{
		*Directionstatus = READ_BIT(*DDRX[_Pinconfig->PortID],(_Pinconfig->PinID));
	}
	return ret;
};


Std_ReturnType DIO_PinWriteLogic(const DIO_PinCfg_t *_Pinconfig, DIO_PinLvl_t logic){
	Std_ReturnType ret = E_OK;
	if(NULL ==_Pinconfig || ((_Pinconfig->PortID)>MAX_PORT_ID)||((_Pinconfig->PinID)>MAX_PIN_ID)){
		ret=E_NOK;
	}
	else{
		switch(logic){
			case DIO_PIN_HIGH:
				SET_BIT((*PORTX[_Pinconfig->PortID]),(_Pinconfig->PinID));
				break;
			case DIO_PIN_LOW:
				CLR_BIT((*PORTX[_Pinconfig->PortID]),(_Pinconfig->PinID));
				break;
		}
	}
	return ret;
};


Std_ReturnType DIO_PinReadLogic(const DIO_PinCfg_t *_Pinconfig, DIO_PinLvl_t *logic){
	Std_ReturnType ret = E_OK;
	if(NULL ==_Pinconfig || ((_Pinconfig->PortID)>MAX_PORT_ID)||((_Pinconfig->PinID)>MAX_PIN_ID)){
		ret=E_NOK;
	}
	else{
		*logic = READ_BIT((*PINX[_Pinconfig->PortID]),(_Pinconfig->PinID));
	}

	return ret;
};


Std_ReturnType DIO_PinToggleLogic(const DIO_PinCfg_t *_Pinconfig){
	Std_ReturnType ret = E_OK;
	if(NULL ==_Pinconfig || ((_Pinconfig->PortID)>MAX_PORT_ID)||((_Pinconfig->PinID)>MAX_PIN_ID)){
		ret=E_NOK;
	}
	else{
		TOG_BIT((*PORTX[_Pinconfig->PortID]),(_Pinconfig->PinID));
	}
	return ret;
};


Std_ReturnType DIO_PinIntialize(const DIO_PinCfg_t *_Pinconfig){
	Std_ReturnType ret = E_OK;
	if(NULL ==_Pinconfig || ((_Pinconfig->PortID)>MAX_PORT_ID)||((_Pinconfig->PinID)>MAX_PIN_ID)){
		ret=E_NOK;
	}
	else{
		ret = DIO_PinDirectionIntialize(_Pinconfig);
		ret = DIO_PinWriteLogic(_Pinconfig, _Pinconfig->PinLvl);
	}
	return ret;
};


Std_ReturnType DIO_PortDirectionIntialize(DIO_PortID_t port, DIO_PortDir_t direction){
	Std_ReturnType ret = E_OK;
	if(port>MAX_PORT_ID){
		ret=E_NOK;
	}
	else{
		*DDRX[port] = direction;
	}
	return ret;
};


Std_ReturnType DIO_PortGetDirectionStatus(DIO_PortID_t port, DIO_PortDir_t *Directionstatus){
	Std_ReturnType ret = E_OK;
	if(port>MAX_PORT_ID){
		ret=E_NOK;
	}
	else{
		*Directionstatus = *DDRX[port];
	}
	return ret;
};


Std_ReturnType DIO_PortWriteLogic(DIO_PortID_t port, DIO_PortLvl_t logic){
	Std_ReturnType ret = E_OK;
	if(port>MAX_PORT_ID){
		ret=E_NOK;
	}
	else{
		*PORTX[port] = logic;
	}
	return ret;

};


Std_ReturnType DIO_PortReadLogic(DIO_PortID_t port, DIO_PortLvl_t *logic){
	Std_ReturnType ret = E_OK;
	if(port>MAX_PORT_ID){
		ret=E_NOK;
	}
	else{
		*logic = *PORTX[port];
	}
	return ret;
};


Std_ReturnType DIO_PortToggleLogic(DIO_PortID_t port){
	Std_ReturnType ret = E_OK;
	if(port>MAX_PORT_ID){
		ret=E_NOK;
	}
	else{
		*PORTX[port] ^= 0XFF;
	}
	return ret;
};











