 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  1/7/2023     **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/						
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*select reference voltage 
     1-ADC_u8_Reference_AREF
	 2-ADC_u8_Reference_AVCC
	 3-ADC_u8_Reference_Internal  ----->2.56v*/
	 
/*select ADLAR 1-ADC_u8_Left  2-ADC_u8_Right*/

#define ADC_u8_Reference             ADC_u8_Reference_AREF

#define ADC_u8_ADC_Result            ADC_u8_Left


#define ADC_u32_TimeOut_Counter      5000


#endif