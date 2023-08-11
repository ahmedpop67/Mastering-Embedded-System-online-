 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  3/30/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
 
 #ifndef UART_INTERFACE_H
 #define UART_INTERFACE_H

 //without interupt
 void UART_voidInit(u8 Copy_u8UBRR);
 
 void UART_voidsendByte_Syn(u8 copy_u8DataByte);
 void UART_voidsendString_Syn(u8 *copy_pu8DataString);

 u8 UART_voidReciveByte_Syn(u8 *copy_pu8DataByte);
 u8 UART_voidReciveString_Syn(u8 *copy_pu8DataString,u8 copy_u8_SizeString);


 //by interupt



 void UART_voidsendString_ASyn(u8 *copy_pu8DataString,void(*copy_pISRF)(void));

 u8 UART_voidReciveString_ASyn(u8 *copy_pu8DataString,u8 copy_u8_SizeString,void(*copy_pISRF)(void));



 #endif