 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  8/30/2023    **************************/
 /***************************  VERSION :  1.0        **************************/
 /*****************************************************************************/
 
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 
 #include "NVIC_interface.h"
 #include "NVIC_private.h"
 #include "NVIC_config.h"
 
void NVIC_voidEnableInterrupt(uint8 copy_uint8IntNumber)
{
	if(copy_uint8IntNumber<31)
	{
		NVIC_ISER0=1<<copy_uint8IntNumber;
	}
	else if(copy_uint8IntNumber<63)
	{
		copy_uint8IntNumber-=31;
		NVIC_ISER1=1<<copy_uint8IntNumber;
	}
	else if(copy_uint8IntNumber<95)
	{
		copy_uint8IntNumber-=63;
		NVIC_ISER2=1<<copy_uint8IntNumber;
	}
}
void NVIC_voidDisableInterrupt(uint8 copy_uint8IntNumber)
{
	if(copy_uint8IntNumber<31)
	{
		NVIC_ICER0=1<<copy_uint8IntNumber;
	}
	else if(copy_uint8IntNumber<63)
	{
		copy_uint8IntNumber-=31;
		NVIC_ICER1=1<<copy_uint8IntNumber;
	}
	else if(copy_uint8IntNumber<95)
	{
		copy_uint8IntNumber-=63;
		NVIC_ICER2=1<<copy_uint8IntNumber;
	}
}
void NVIC_voidSetPeningFlag(uint8 copy_uint8IntNumber)
{
	if(copy_uint8IntNumber<31)
	{
		NVIC_ISPR0=1<<copy_uint8IntNumber;
	}
	else if(copy_uint8IntNumber<63)
	{
		copy_uint8IntNumber-=31;
		NVIC_ISPR1=1<<copy_uint8IntNumber;
	}
	else if(copy_uint8IntNumber<95)
	{
		copy_uint8IntNumber-=63;
		NVIC_ISPR2=1<<copy_uint8IntNumber;
	}
}
void NVIC_voidClearPeningFlag(uint8 copy_uint8IntNumber)
{
	if(copy_uint8IntNumber<31)
	{
		NVIC_ICPR0=1<<copy_uint8IntNumber;
	}
	else if(copy_uint8IntNumber<63)
	{
		copy_uint8IntNumber-=31;
		NVIC_ICPR1=1<<copy_uint8IntNumber;
	}
	else if(copy_uint8IntNumber<95)
	{
		copy_uint8IntNumber-=63;
		NVIC_ICPR2=1<<copy_uint8IntNumber;
	}
}
uint8 NVIC_voidGetActiveFlag(uint8 copy_uint8IntNumber)
{
	uint8 local_Active_flag;
	if(copy_uint8IntNumber<31)
	{
		local_Active_flag=GET_BIT(NVIC_IABR0,copy_uint8IntNumber);
	}
	else if(copy_uint8IntNumber<63)
	{
		copy_uint8IntNumber-=31;
		local_Active_flag=GET_BIT(NVIC_IABR1,copy_uint8IntNumber);
	}
	else if(copy_uint8IntNumber<95)
	{
		copy_uint8IntNumber-=63;
		local_Active_flag=GET_BIT(NVIC_IABR2,copy_uint8IntNumber);
	}
	return local_Active_flag;
}
void NVIC_voidSetPriority(uint8 copy_uint8IntID,uint8 copy_uint8Group_ID,uint8 copy_uint8Sub_ID)
{
	if(copy_uint8IntID<60)
	{
		SCB_AIRCR=NVIC_GROUP_SUB_DISTRIBTION;
		uint8 local_NVIC_priority=copy_uint8Sub_ID|(copy_uint8Group_ID<<((NVIC_GROUP_SUB_DISTRIBTION-0x05FA0300)/256));
		NVIC_IPR[copy_uint8IntID]=local_NVIC_priority<<4;
	}
}
