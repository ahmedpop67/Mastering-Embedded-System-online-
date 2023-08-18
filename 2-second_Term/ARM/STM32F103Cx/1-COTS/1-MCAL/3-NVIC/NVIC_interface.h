 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  8/30/2023    **************************/
 /***************************  VERSION :  1.0        **************************/
 /*****************************************************************************/
														
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void NVIC_voidEnableInterrupt(uint8 copy_uint8IntNumber);
void NVIC_voidDisableInterrupt(uint8 copy_uint8IntNumber);
void NVIC_voidSetPeningFlag(uint8 copy_uint8IntNumber);
void NVIC_voidClearPeningFlag(uint8 copy_uint8IntNumber);
uint8 NVIC_voidGetActiveFlag(uint8 copy_uint8IntNumber);
void NVIC_voidSetPriority(uint8 copy_uint8IntID,uint8 copy_uint8Group_ID,uint8,Sub_ID);

#endif
