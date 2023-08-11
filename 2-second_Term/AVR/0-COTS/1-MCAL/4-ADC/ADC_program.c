 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  1/7/2023     **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
 
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "ADC_interface.h"
 #include "ADC_private.h"
 #include "ADC_config.h"
 static void(*ADC_pfNotification)(u16);
 static u8 ADC_u8_BuzyFlag=0;
 void ADC_voidInit(void)
 {
	 #if ADC_u8_Reference==ADC_u8_Reference_AREF
	 CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS1);
	 CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS0);
	 #elif ADC_u8_Reference==ADC_u8_Reference_AVCC
	 CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS1);
	 SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS0);
	 #elif ADC_u8_Reference==ADC_u8_Reference_Internal
	 SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS1);
	 SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS0);
	 #endif
	 #if	ADC_u8_ADC_Result==ADC_u8_Left
	 SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADLAR);
	 #elif ADC_u8_ADC_Result==ADC_u8_Right
	 CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADLAR);
	 #endif
	 SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADPS2);
	 SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADPS1);
	 CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADPS0);
	 SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADEN);
 }

 u8 ADC_u8GetDgitalValueSynBlocking(u8 Copy_u8channelNb,u16 *Copy_pu16DigitalValue)
 {
	 u32 local_u32_TimeOutCounter=0;
	 u8 lacal_u8ErrorState=STD_TYPE_OK;
	 if(Copy_u8channelNb<=32&&(Copy_pu16DigitalValue!=NULL) && ADC_u8_BuzyFlag==0)
	 {
		 ADC_u8_BuzyFlag=1;
		 SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC);
		 ADC_u8_ADMUX_REG &= 0b11100000;
		 ADC_u8_ADMUX_REG |= Copy_u8channelNb;
		 while(GET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIF)==0 && (local_u32_TimeOutCounter<ADC_u32_TimeOut_Counter))
		 {
			 local_u32_TimeOutCounter++;
		 }
		 if(local_u32_TimeOutCounter!=ADC_u32_TimeOut_Counter)
		 {
			 SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIF);
			 if(GET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADLAR))
			 *Copy_pu16DigitalValue=ADC_u16_ADC_REG>>6;
			 else
			 *Copy_pu16DigitalValue=ADC_u16_ADC_REG;
			 ADC_u8_BuzyFlag=0;
		 }
		 else 	lacal_u8ErrorState=STD_TYPE_NOK;
	 }
	 else lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
 }
 u8 ADC_u8GetDgitalValueASyn(u8 Copy_u8channelNb,void (*Copy_pfNotification)(u16))
 {
	 u8 lacal_u8ErrorState=STD_TYPE_OK;
	 if(Copy_u8channelNb<=32 && ADC_u8_BuzyFlag==0)
	 {
		 SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIE);
		 ADC_pfNotification=Copy_pfNotification;
		 ADC_u8_BuzyFlag=1;
		 SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC);
		 ADC_u8_ADMUX_REG &= 0b11100000;
		 ADC_u8_ADMUX_REG |= Copy_u8channelNb;
	 }
	 else lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
 }
 void __vector_16(void)    __attribute__((signal));
 void __vector_16(void)
 {
	 if(ADC_pfNotification != NULL)
	 {
		 CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIE);
		 ADC_u8_BuzyFlag=0;
		 if(GET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADLAR))
		 ADC_pfNotification(ADC_u16_ADC_REG>>6);
		 else
		 ADC_pfNotification(ADC_u16_ADC_REG);
	 }
 }