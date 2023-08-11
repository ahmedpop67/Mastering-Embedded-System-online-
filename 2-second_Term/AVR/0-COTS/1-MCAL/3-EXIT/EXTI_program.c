 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  1/7/2023   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
														
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

static void(*EXTI_ApfEXTI[3])(void)={NULL,NULL,NULL};

u8 EXTI_u8EXTIEnable(u8 Copy_u8EXTIIndex,u8 Copy_u8EdgeIndex)
{
	u8 lacal_u8ErrorState = STD_TYPE_OK;
	if(Copy_u8EXTIIndex<=EXTI_u8_INT2&&Copy_u8EdgeIndex<=EXTI_u8_ANY_LOGIC_CHANGE)
	{
		switch(Copy_u8EXTIIndex){
			case EXTI_u8_INT0:
			  switch(Copy_u8EdgeIndex){
				  case EXTI_u8_RISING_EDGE:
				      SET_BIT(EXTI_u8_MCUCR,1);
				      SET_BIT(EXTI_u8_MCUCR,0);
					  SET_BIT(EXTI_u8_GICR,6);
				      break;
				  case EXTI_u8_FALLING_EDGE:
				      SET_BIT(EXTI_u8_MCUCR,1);
				      CLR_BIT(EXTI_u8_MCUCR,0);
					  SET_BIT(EXTI_u8_GICR,6);
				      break;
				  case EXTI_u8_LOW_LEVEL:
				      CLR_BIT(EXTI_u8_MCUCR,1);
				      CLR_BIT(EXTI_u8_MCUCR,0);
					  SET_BIT(EXTI_u8_GICR,6);
					  break;
				  case EXTI_u8_ANY_LOGIC_CHANGE:
				      SET_BIT(EXTI_u8_MCUCR,0);
				      CLR_BIT(EXTI_u8_MCUCR,1);
					  SET_BIT(EXTI_u8_GICR,6);
				      break;
			  }
			  break;
			case EXTI_u8_INT1:
			  switch(Copy_u8EdgeIndex){
				  case EXTI_u8_RISING_EDGE:
				      SET_BIT(EXTI_u8_MCUCR,3);
				      SET_BIT(EXTI_u8_MCUCR,2);
					  SET_BIT(EXTI_u8_GICR,7);
				      break;
				  case EXTI_u8_FALLING_EDGE:
				      SET_BIT(EXTI_u8_MCUCR,3);
				      CLR_BIT(EXTI_u8_MCUCR,2);
					  SET_BIT(EXTI_u8_GICR,7);
				      break;
				  case EXTI_u8_LOW_LEVEL:
				      CLR_BIT(EXTI_u8_MCUCR,3);
				      CLR_BIT(EXTI_u8_MCUCR,2);
					  SET_BIT(EXTI_u8_GICR,7);
					  break;
				  case EXTI_u8_ANY_LOGIC_CHANGE:
				      SET_BIT(EXTI_u8_MCUCR,2);
				      CLR_BIT(EXTI_u8_MCUCR,3);
					  SET_BIT(EXTI_u8_GICR,7);
				      break;
			  }
			  break;
			case EXTI_u8_INT2:
			  switch(Copy_u8EdgeIndex){
				  case EXTI_u8_RISING_EDGE:
				      SET_BIT(EXTI_u8_MCUCSR,6);
					  SET_BIT(EXTI_u8_GICR,5);
				      break;
				  case EXTI_u8_FALLING_EDGE:
				      CLR_BIT(EXTI_u8_MCUCSR,6);
					  SET_BIT(EXTI_u8_GICR,5);
				      break;
			  }
			  break;
		}
	}
	else
		lacal_u8ErrorState=STD_TYPE_NOK;
	return lacal_u8ErrorState;
}
u8 EXTI_u8EXTIDisable(u8 Copy_u8EXTIIndex)
{
	u8 lacal_u8ErrorState = STD_TYPE_OK;
	switch (Copy_u8EXTIIndex){
		case EXTI_u8_INT0:
		    CLR_BIT(EXTI_u8_GICR,6);
			break;
	    case EXTI_u8_INT1:
		    CLR_BIT(EXTI_u8_GICR,7);
			break;
	    case EXTI_u8_INT2:
		    CLR_BIT(EXTI_u8_GICR,5);
			break;
		default:
		    lacal_u8ErrorState=STD_TYPE_NOK;
			break;
	}
	return lacal_u8ErrorState;
}
u8 EXTI_u8EXTISetCallBack(u8 Copy_u8EXTIIndex,void(*copy_pf)(void))
{
	u8 lacal_u8ErrorState = STD_TYPE_OK;
	if(Copy_u8EXTIIndex<=EXTI_u8_INT2&& copy_pf!=NULL){
		EXTI_ApfEXTI[Copy_u8EXTIIndex]=copy_pf;
	}
	else
		lacal_u8ErrorState=STD_TYPE_NOK;
	return lacal_u8ErrorState;
}

/* Prototype for ISR of EXTI0*/
void __vector_1(void)    __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_ApfEXTI[EXTI_u8_INT0]!=NULL)
		EXTI_ApfEXTI[EXTI_u8_INT0]();
}

/* Prototype for ISR of EXTI1*/
void __vector_2(void)    __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_ApfEXTI[EXTI_u8_INT1]!=NULL)
		EXTI_ApfEXTI[EXTI_u8_INT1]();
}

/* Prototype for ISR of EXTI2*/
void __vector_3(void)    __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_ApfEXTI[EXTI_u8_INT2]!=NULL)
		EXTI_ApfEXTI[EXTI_u8_INT2]();
}