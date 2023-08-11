/*****************************************************************************/
/***************************  NAME  :  ahmed hassan **************************/
/***************************  DATE  :  11/30/2022   **************************/
/*************************  VERSION :  1.0          **************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_interface.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"


u8 EEPROM_u8writeDataByte(u16 copy_u16ADD,u8 copy_u8Data)
{
	u8 lacal_u8ErrorState=STD_TYPE_OK;
	TWI_ErrorState lacal_enumErrorState = TWI_OK;
	//send start condition
	lacal_enumErrorState = TWI_u8SendStartCondition();
	lacal_u8ErrorState=private_u8checkerror(lacal_enumErrorState);
	//SENDSLAVE ADD WITH WRITE
	TWI_u8SendSlaveAddWrite(EEPROM_u8_FIXED_ADD | (EPROM_u8_A2_ADD<<2) | (copy_u8ADD>>8));
	lacal_u8ErrorState=private_u8checkerror(lacal_enumErrorState);
    //send address 
	lacal_enumErrorState=TWI_u8SendDataByte((u8)copy_u16ADD);
	lacal_u8ErrorState=private_u8checkerror(lacal_enumErrorState);
	//send data
	lacal_enumErrorState=TWI_u8SendDataByte(copy_u8Data);
	lacal_u8ErrorState=private_u8checkerror(lacal_enumErrorState);
	//stop condition
	TWI_u8SendReStopCondition();
    _delay_ms(5);
	return lacal_u8ErrorState;
}


u8 EEPROM_u8reedDataByte(u16 copy_u8ADD,u8 *copy_pu8Data)
{
	u8 lacal_u8ErrorState=STD_TYPE_OK;
	TWI_ErrorState lacal_enumErrorState = TWI_OK;
	if(copy_pu8Data!NULL)
	{
		//send start condition
	    lacal_enumErrorState = TWI_u8SendStartCondition();
	    lacal_u8ErrorState=private_u8checkerror(lacal_enumErrorState);
		//SENDSLAVE ADD WITH WRITE
	    TWI_u8SendSlaveAddWrite(EEPROM_u8_FIXED_ADD | (EPROM_u8_A2_ADD<<2) | (copy_u8ADD>>8));
	    lacal_u8ErrorState=private_u8checkerror(lacal_enumErrorState);
		//send address 
	    lacal_enumErrorState=TWI_u8SendDataByte((u8)copy_u16ADD);
	    lacal_u8ErrorState=private_u8checkerror(lacal_enumErrorState);
		//SEND REPEATED START CONDITION
		lacal_enumErrorState = TWI_u8SendReStartCondition();
	    lacal_u8ErrorState=private_u8checkerror(lacal_enumErrorState);
		//SENDSLAVE ADD WITH REED
	    TWI_u8SendSlaveAddReed(EEPROM_u8_FIXED_ADD | (EPROM_u8_A2_ADD<<2) | (copy_u8ADD>>8));
	    lacal_u8ErrorState=private_u8checkerror(lacal_enumErrorState);
		//REED DATA
		TWI_u8ReciveDataByte(copy_pu8Data);
		lacal_u8ErrorState=private_u8checkerror(lacal_enumErrorState);
		//stop condition
	    TWI_u8SendReStopCondition();
       _delay_ms(5);
	}
	else 
		lacal_u8ErrorState=STD_TYPE_NOK
	
	return lacal_u8ErrorState;
}

static u8 private_u8checkerror(TWI_ErrorState lacal_enumErrorState)
{
	u8 lacal_u8ErrorState=STD_TYPE_OK;
	if(lacal_enumErrorState!=TWI_OK)
	{
		lacal_u8ErrorState=STD_TYPE_NOK
	}
	return lacal_u8ErrorState;
}



