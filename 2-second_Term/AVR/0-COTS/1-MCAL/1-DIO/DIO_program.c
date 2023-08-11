 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  11/25/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidInit (void)
{
	DIO_u8_DDRA_REG = conc(DIO_u8_PA7_INTIAL_DIRECTION,DIO_u8_PA6_INTIAL_DIRECTION,DIO_u8_PA5_INTIAL_DIRECTION,DIO_u8_PA4_INTIAL_DIRECTION,
	DIO_u8_PA3_INTIAL_DIRECTION,DIO_u8_PA2_INTIAL_DIRECTION,DIO_u8_PA1_INTIAL_DIRECTION,DIO_u8_PA0_INTIAL_DIRECTION);
	DIO_u8_DDRB_REG = conc(DIO_u8_PB7_INTIAL_DIRECTION,DIO_u8_PB6_INTIAL_DIRECTION,DIO_u8_PB5_INTIAL_DIRECTION,DIO_u8_PB4_INTIAL_DIRECTION,
	DIO_u8_PB3_INTIAL_DIRECTION,DIO_u8_PB2_INTIAL_DIRECTION,DIO_u8_PB1_INTIAL_DIRECTION,DIO_u8_PB0_INTIAL_DIRECTION);
	DIO_u8_DDRC_REG = conc(DIO_u8_PC7_INTIAL_DIRECTION,DIO_u8_PC6_INTIAL_DIRECTION,DIO_u8_PC5_INTIAL_DIRECTION,DIO_u8_PC4_INTIAL_DIRECTION,
	DIO_u8_PC3_INTIAL_DIRECTION,DIO_u8_PC2_INTIAL_DIRECTION,DIO_u8_PC1_INTIAL_DIRECTION,DIO_u8_PC0_INTIAL_DIRECTION);
	DIO_u8_DDRD_REG = conc(DIO_u8_PD7_INTIAL_DIRECTION,DIO_u8_PD6_INTIAL_DIRECTION,DIO_u8_PD5_INTIAL_DIRECTION,DIO_u8_PD4_INTIAL_DIRECTION,
	DIO_u8_PD3_INTIAL_DIRECTION,DIO_u8_PD2_INTIAL_DIRECTION,DIO_u8_PD1_INTIAL_DIRECTION,DIO_u8_PD0_INTIAL_DIRECTION);
	DIO_u8_PORTA_REG = conc(DIO_u8_PA7_INTIAL_VALUE,DIO_u8_PA6_INTIAL_VALUE,DIO_u8_PA5_INTIAL_VALUE,DIO_u8_PA4_INTIAL_VALUE,
	DIO_u8_PA3_INTIAL_VALUE,DIO_u8_PA2_INTIAL_VALUE,DIO_u8_PA1_INTIAL_VALUE,DIO_u8_PA0_INTIAL_VALUE);
	DIO_u8_PORTB_REG = conc(DIO_u8_PB7_INTIAL_VALUE,DIO_u8_PB6_INTIAL_VALUE,DIO_u8_PB5_INTIAL_VALUE,DIO_u8_PB4_INTIAL_VALUE,
	DIO_u8_PB3_INTIAL_VALUE,DIO_u8_PB2_INTIAL_VALUE,DIO_u8_PB1_INTIAL_VALUE,DIO_u8_PB0_INTIAL_VALUE);
	DIO_u8_PORTC_REG = conc(DIO_u8_PC7_INTIAL_VALUE,DIO_u8_PC6_INTIAL_VALUE,DIO_u8_PC5_INTIAL_VALUE,DIO_u8_PC4_INTIAL_VALUE,
	DIO_u8_PC3_INTIAL_VALUE,DIO_u8_PC2_INTIAL_VALUE,DIO_u8_PC1_INTIAL_VALUE,DIO_u8_PC0_INTIAL_VALUE);
	DIO_u8_PORTD_REG = conc(DIO_u8_PD7_INTIAL_VALUE,DIO_u8_PD6_INTIAL_VALUE,DIO_u8_PD5_INTIAL_VALUE,DIO_u8_PD4_INTIAL_VALUE,
	DIO_u8_PD3_INTIAL_VALUE,DIO_u8_PD2_INTIAL_VALUE,DIO_u8_PD1_INTIAL_VALUE,DIO_u8_PD0_INTIAL_VALUE);
}
u8 DIO_u8SetpinDirection(u8 copy_u8portID,u8 copy_u8PinID,u8 copy_u8PinDirection)
{
	u8 lacal_u8ErrorState = STD_TYPE_OK;
	if((copy_u8portID <= DIO_u8_PORTD)&& (copy_u8PinID <= DIO_u8_PIN7)&& ((copy_u8PinDirection == DIO_u8_OUTPUT) || (copy_u8PinDirection ==DIO_u8_INPUT)))
	{ 
		switch(copy_u8portID){
			case DIO_u8_PORTA:
			switch (copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRA_REG,copy_u8PinID);break;
				case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRA_REG,copy_u8PinID);break;
			}
			break;
			case DIO_u8_PORTB:
			switch (copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRB_REG,copy_u8PinID);break;
				case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRB_REG,copy_u8PinID);break;
			}
			break;
			case DIO_u8_PORTC:
			switch (copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRC_REG,copy_u8PinID);break;
				case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRC_REG,copy_u8PinID);break;
			}
			break;
			case DIO_u8_PORTD:
			switch (copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRD_REG,copy_u8PinID);break;
				case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRD_REG,copy_u8PinID);break;
			}
			break;
		}
	}
	else
	{
		lacal_u8ErrorState=STD_TYPE_NOK;
	}
	return lacal_u8ErrorState;
}


u8 DIO_u8SetpinValue(u8 copy_u8portID,u8 copy_u8PinID,u8 copy_u8PinValue)
{
	u8 lacal_u8ErrorState= STD_TYPE_OK;
	if((copy_u8portID <= DIO_u8_PORTD)&& (copy_u8PinID <= DIO_u8_PIN7))
	{
		switch(copy_u8portID)
		{
			case DIO_u8_PORTA:
			switch(copy_u8PinValue)
			{
				case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTA_REG,copy_u8PinID);break;
				case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTA_REG,copy_u8PinID);break;
				default : lacal_u8ErrorState= STD_TYPE_NOK;break;
			}
			break;
			case DIO_u8_PORTB:
			switch(copy_u8PinValue)
			{
				case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTB_REG,copy_u8PinID);break;
				case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTB_REG,copy_u8PinID);break;
				default : lacal_u8ErrorState= STD_TYPE_NOK;break;
			}
			break;
			case DIO_u8_PORTC:
			switch(copy_u8PinValue)
			{
				case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTC_REG,copy_u8PinID);break;
				case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTC_REG,copy_u8PinID);break;
				default : lacal_u8ErrorState= STD_TYPE_NOK;break;
			}
			break;
			case DIO_u8_PORTD:
			switch(copy_u8PinValue)
			{
				case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTD_REG,copy_u8PinID);break;
				case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTD_REG,copy_u8PinID);break;
				default : lacal_u8ErrorState= STD_TYPE_NOK;break;
			}
			break;
		}
	}
	else
	{
		lacal_u8ErrorState= STD_TYPE_NOK;
	}
	return lacal_u8ErrorState;
}


u8 DIO_u8GetPinValue (u8 copy_u8portID,u8 copy_u8PinID,u8 * copy_pu8ReturnPinValue)
{
	u8 lacal_u8ErrorState= STD_TYPE_OK;
	u8 lacal_u8PinValue;
	if((copy_u8portID <= DIO_u8_PORTD)&& (copy_u8PinID <= DIO_u8_PIN7) && copy_pu8ReturnPinValue != NULL )
	{
		switch(copy_u8portID)
		{
			case DIO_u8_PORTA:
			lacal_u8PinValue=GET_BIT(DIO_u8_PINA_REG,copy_u8PinID);
			if(lacal_u8PinValue == 0)
			{
				*copy_pu8ReturnPinValue = DIO_u8_LOW;
			}
			else
			{
				*copy_pu8ReturnPinValue = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTB:
			lacal_u8PinValue=GET_BIT(DIO_u8_PINB_REG,copy_u8PinID);
			if(lacal_u8PinValue == 0)
			{
				*copy_pu8ReturnPinValue = DIO_u8_LOW;
			}
			else
			{
				*copy_pu8ReturnPinValue = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTC:
			lacal_u8PinValue=GET_BIT(DIO_u8_PINC_REG,copy_u8PinID);
			if(lacal_u8PinValue == 0)
			{
				*copy_pu8ReturnPinValue = DIO_u8_LOW;
			}
			else
			{
				*copy_pu8ReturnPinValue = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTD:
			lacal_u8PinValue=GET_BIT(DIO_u8_PIND_REG,copy_u8PinID);
			if(lacal_u8PinValue == 0)
			{
				*copy_pu8ReturnPinValue = DIO_u8_LOW;
			}
			else
			{
				*copy_pu8ReturnPinValue = DIO_u8_HIGH;
			}
			break;
		}
	}
	else
	{
		lacal_u8ErrorState= STD_TYPE_NOK;
	}
	return lacal_u8ErrorState;
}


u8 DIO_u8SetPortDirection  (u8 copy_u8portID,u8 copy_u8PortDirection)
{
	u8 lacal_u8ErrorState= STD_TYPE_OK;
	if((copy_u8portID <= DIO_u8_PORTD) && ((copy_u8PortDirection == DIO_u8_OUTPUT) || (copy_u8PortDirection ==DIO_u8_INPUT)))
	{
		switch(copy_u8portID)
		{
			case DIO_u8_PORTA:
			switch (copy_u8PortDirection)
			{
				case DIO_u8_OUTPUT:DIO_u8_DDRA_REG == 0X0FF;break;
				case DIO_u8_INPUT: DIO_u8_DDRA_REG == 0X00;break;
			}
			break;
			case DIO_u8_PORTB:
			switch (copy_u8PortDirection)
			{
				case DIO_u8_OUTPUT:DIO_u8_DDRB_REG == 0X0FF;break;
				case DIO_u8_INPUT: DIO_u8_DDRB_REG == 0X00;break;
			}
			break;
			case DIO_u8_PORTC:
			switch (copy_u8PortDirection)
			{
				case DIO_u8_OUTPUT:DIO_u8_DDRC_REG == 0X0FF;break;
				case DIO_u8_INPUT: DIO_u8_DDRC_REG == 0X00;break;
			}
			break;
			case DIO_u8_PORTD:
			switch (copy_u8PortDirection)
			{
				case DIO_u8_OUTPUT:DIO_u8_DDRD_REG == 0X0FF;break;
				case DIO_u8_INPUT: DIO_u8_DDRD_REG == 0X00;break;
			}
			break;
		}
	}
	else
	{
		lacal_u8ErrorState= STD_TYPE_NOK;
	}
	return lacal_u8ErrorState;
	
}

u8 DIO_u8SetPortValue(u8 copy_u8portID,u8 copy_u8PortValue)
{
	u8 lacal_u8ErrorState= STD_TYPE_OK;
	if((copy_u8portID <= DIO_u8_PORTD))
	{
		switch(copy_u8portID)
		{
			case DIO_u8_PORTA:DIO_u8_PORTA_REG = copy_u8PortValue;break;
			case DIO_u8_PORTB:DIO_u8_PORTB_REG = copy_u8PortValue;break;
			case DIO_u8_PORTC:DIO_u8_PORTC_REG = copy_u8PortValue;break;
			case DIO_u8_PORTD:DIO_u8_PORTD_REG = copy_u8PortValue;break;
		}
	}
	else
	{
		lacal_u8ErrorState= STD_TYPE_NOK;
	}
	return lacal_u8ErrorState;
}

u8 DIO_u8GetPortValue      (u8 copy_u8portID,u8 * copy_pu8ReturnPortValue)
{
	u8 lacal_u8ErrorState= STD_TYPE_OK;
	if((copy_u8portID <= DIO_u8_PORTD) && copy_pu8ReturnPortValue != NULL )
	{
		switch(copy_u8portID)
		{
			case DIO_u8_PORTA: * copy_pu8ReturnPortValue = DIO_u8_PINA_REG;break;
			case DIO_u8_PORTB: * copy_pu8ReturnPortValue = DIO_u8_PINB_REG;break;
			case DIO_u8_PORTC: * copy_pu8ReturnPortValue = DIO_u8_PINC_REG;break;
			case DIO_u8_PORTD: * copy_pu8ReturnPortValue = DIO_u8_PIND_REG;break;
		}
	}
	else
	{
		lacal_u8ErrorState= STD_TYPE_NOK;
	}
	return lacal_u8ErrorState;
}

u8 DIO_u8TogPinValue(u8 copy_u8portID,u8 copy_u8PinID)
{
	u8 lacal_u8ErrorState=STD_TYPE_OK;
	if((copy_u8portID <= DIO_u8_PORTD)&& (copy_u8PinID <= DIO_u8_PIN7))
	{
		switch(copy_u8portID)
		{
			case DIO_u8_PORTA:TOG_BIT(DIO_u8_PORTA_REG,copy_u8PinID);break;
			case DIO_u8_PORTB:TOG_BIT(DIO_u8_PORTB_REG,copy_u8PinID);break;
			case DIO_u8_PORTC:TOG_BIT(DIO_u8_PORTC_REG,copy_u8PinID);break;
			case DIO_u8_PORTD:TOG_BIT(DIO_u8_PORTD_REG,copy_u8PinID);break;
		}
	}
	else
	{
		lacal_u8ErrorState=STD_TYPE_NOK;
	}
	return lacal_u8ErrorState;
}
