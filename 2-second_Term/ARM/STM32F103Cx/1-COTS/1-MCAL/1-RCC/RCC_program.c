 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  8/30/2023    **************************/
 /***************************  VERSION :  1.0        **************************/
 /*****************************************************************************/
													
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_config.h"
#include "RCC_private.h"
#include "RCC_interface.h"


void RCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		SET_BIT(RCC_CR,16);
		SET_BIT(RCC_CR,18);
		SET_BIT(RCC_CFGR,0);
		CLR_BIT(RCC_CFGR,1);
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		SET_BIT(RCC_CR,16);
		CLR_BIT(RCC_CR,18);
		SET_BIT(RCC_CFGR,0);
		CLR_BIT(RCC_CFGR,1);
	#elif RCC_CLOCK_TYPE == RCC_HSI
	    SET_BIT(RCC_CR,0);
		CLR_BIT(RCC_CFGR,0);
		CLR_BIT(RCC_CFGR,1);
	#elif RCC_CLOCK_TYPE == RCC_PLL
		#if RCC_PLL_CLOCK   == RCC_PLL_IN_HSI_DIV_2
		    SET_BIT(RCC_CR,0);
			CLR_BIT(RCC_CFGR,0);
			CLR_BIT(RCC_CFGR,1);
			CLR_BIT(RCC_CFGR,16);
		#elif RCC_PLL_CLOCK == RCC_PLL_IN_HSE_DIV_2
			SET_BIT(RCC_CR,16);
			SET_BIT(RCC_CR,18);
			SET_BIT(RCC_CFGR,0);
			CLR_BIT(RCC_CFGR,1);
			SET_BIT(RCC_CFGR,17);
			SET_BIT(RCC_CFGR,16);
		#elif RCC_PLL_CLOCK == RCC_PLL_IN_HSE
			SET_BIT(RCC_CR,16);
			SET_BIT(RCC_CR,18);
			SET_BIT(RCC_CFGR,0);
			CLR_BIT(RCC_CFGR,1);
			CLR_BIT(RCC_CFGR,17);
			SET_BIT(RCC_CFGR,16);
		#else #error("wrong choise")
		#endif
		#if RCC_PLL_MUL  ==RCC_PLL_IN_MUL_2
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_3
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_4
		    CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_5
		    SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_6
		    CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_7
		    SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_8
		    CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_9
		    SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_10
		    CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_11
		    SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_12
		    CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_13
		    SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_14
		    CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_15
		    SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL==RCC_PLL_IN_MUL_16
		    CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#else #error("wrong choise")
		#endif
		SET_BIT(RCC_CR,24);
		CLR_BIT(RCC_CFGR,0);
		SET_BIT(RCC_CFGR,1);
	#else #error("wrong choise")
	#endif
	#if RCC_AHP_PRESCALER   ==RCC_AHP_DIV_1
		CLR_BIT(RCC_CFGR,7);
	#elif RCC_AHP_PRESCALER ==RCC_AHP_DIV_2
	     CLR_BIT(RCC_CFGR,4);
	     CLR_BIT(RCC_CFGR,5);
	     CLR_BIT(RCC_CFGR,6);
	     SET_BIT(RCC_CFGR,7);
	#elif RCC_AHP_PRESCALER ==RCC_AHP_DIV_4
		 SET_BIT(RCC_CFGR,4);
	     CLR_BIT(RCC_CFGR,5);
	     CLR_BIT(RCC_CFGR,6);
	     SET_BIT(RCC_CFGR,7);
	#elif RCC_AHP_PRESCALER ==RCC_AHP_DIV_8
	     CLR_BIT(RCC_CFGR,4);
	     SET_BIT(RCC_CFGR,5);
	     CLR_BIT(RCC_CFGR,6);
	     SET_BIT(RCC_CFGR,7);
	#elif RCC_AHP_PRESCALER ==RCC_AHP_DIV_16
	     SET_BIT(RCC_CFGR,4);
	     SET_BIT(RCC_CFGR,5);
	     CLR_BIT(RCC_CFGR,6);
	     SET_BIT(RCC_CFGR,7);
	#elif RCC_AHP_PRESCALER ==RCC_AHP_DIV_64
	     CLR_BIT(RCC_CFGR,4);
	     CLR_BIT(RCC_CFGR,5);
	     SET_BIT(RCC_CFGR,6);
	     SET_BIT(RCC_CFGR,7);
	#elif RCC_AHP_PRESCALER ==RCC_AHP_DIV_128
	     SET_BIT(RCC_CFGR,4);
	     CLR_BIT(RCC_CFGR,5);
	     SET_BIT(RCC_CFGR,6);
	     SET_BIT(RCC_CFGR,7);
	#elif RCC_AHP_PRESCALER ==RCC_AHP_DIV_256
	     CLR_BIT(RCC_CFGR,4);
	     SET_BIT(RCC_CFGR,5);
	     SET_BIT(RCC_CFGR,6);
	     SET_BIT(RCC_CFGR,7);
	#elif RCC_AHP_PRESCALER ==RCC_AHP_DIV_512
	     SET_BIT(RCC_CFGR,4);
	     SET_BIT(RCC_CFGR,5);
	     SET_BIT(RCC_CFGR,6);
	     SET_BIT(RCC_CFGR,7);
	#else #error("wrong choise")
	#endif
	#if RCC_APB1_PRESCALER   ==RCC_APB1_DIV_1
		CLR_BIT(RCC_CFGR,8);
	#elif RCC_APB1_PRESCALER ==RCC_APB1_DIV_2
		CLR_BIT(RCC_CFGR,8);
	    CLR_BIT(RCC_CFGR,9);
	    SET_BIT(RCC_CFGR,10);
	#elif RCC_APB1_PRESCALER ==RCC_APB1_DIV_4
		SET_BIT(RCC_CFGR,8);
	    CLR_BIT(RCC_CFGR,9);
	    SET_BIT(RCC_CFGR,10);
	#elif RCC_APB1_PRESCALER ==RCC_APB1_DIV_8
		CLR_BIT(RCC_CFGR,8);
	    SET_BIT(RCC_CFGR,9);
	    SET_BIT(RCC_CFGR,10);
	#elif RCC_APB1_PRESCALER ==RCC_APB1_DIV_16
		SET_BIT(RCC_CFGR,8);
	    SET_BIT(RCC_CFGR,9);
	    SET_BIT(RCC_CFGR,10);
	#else #error("wrong choise")
	#endif
	#if RCC_APB2_PRESCALER   ==RCC_APB2_DIV_1
		CLR_BIT(RCC_CFGR,11);
	#elif RCC_APB2_PRESCALER ==RCC_APB2_DIV_2
		CLR_BIT(RCC_CFGR,11);
	    CLR_BIT(RCC_CFGR,12);
	    SET_BIT(RCC_CFGR,13);
	#elif RCC_APB2_PRESCALER ==RCC_APB2_DIV_4
		SET_BIT(RCC_CFGR,11);
	    CLR_BIT(RCC_CFGR,12);
	    SET_BIT(RCC_CFGR,13);
	#elif RCC_APB2_PRESCALER ==RCC_APB2_DIV_8
		CLR_BIT(RCC_CFGR,11);
	    SET_BIT(RCC_CFGR,12);
	    SET_BIT(RCC_CFGR,13);
	#elif RCC_APB2_PRESCALER ==RCC_APB2_DIV_16
		SET_BIT(RCC_CFGR,11);
	    SET_BIT(RCC_CFGR,12);
	    SET_BIT(RCC_CFGR,13);
	#else #error("wrong choise")
	#endif
}

void RCC_voidEnableClock(uint8 copy_uint8_BusId,uint8 copy_uint8_PortId)
{
	if(copy_uint8_PortId<=31)
	{
		switch(copy_uint8_BusId)
		{
			case RCC_AHP :SET_BIT(RCC_AHBENR,copy_uint8_PortId); break; 
			case RCC_APB1:SET_BIT(RCC_APB1ENR,copy_uint8_PortId);break;
			case RCC_APB2:SET_BIT(RCC_APB2ENR,copy_uint8_PortId);break;
			default : break;
		}
		
	}
}
void RCC_voidDisableClock(uint8 copy_uint8_BusId,uint8 copy_uint8_PortId)
{
	if(copy_uint8_BusId <= 2 && copy_uint8_PortId<=31)
	{
		switch(copy_uint8_BusId)
		{
			case RCC_AHP :CLR_BIT(RCC_AHBENR,copy_uint8_PortId); break; 
			case RCC_APB1:CLR_BIT(RCC_APB1ENR,copy_uint8_PortId);break;
			case RCC_APB2:CLR_BIT(RCC_APB2ENR,copy_uint8_PortId);break;
			default : break;
		}
		
	}
}


