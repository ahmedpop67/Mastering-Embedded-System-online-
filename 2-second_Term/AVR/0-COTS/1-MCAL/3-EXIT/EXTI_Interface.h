 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  1/7/2023   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
														
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_u8_INT0                     0
#define EXTI_u8_INT1                     1
#define EXTI_u8_INT2                     2
								         
#define EXTI_u8_RISING_EDGE              0
#define EXTI_u8_FALLING_EDGE             1
#define EXTI_u8_LOW_LEVEL                2 
#define EXTI_u8_ANY_LOGIC_CHANGE         3

u8 EXTI_u8EXTIEnable(u8 Copy_u8EXTIIndex,u8 Copy_u8EdgeIndex);

u8 EXTI_u8EXTIDisable(u8 Copy_u8EXTIIndex);

u8 EXTI_u8EXTISetCallBack(u8 Copy_u8EXTIIndex,void(*copy_pf)(void));

#endif