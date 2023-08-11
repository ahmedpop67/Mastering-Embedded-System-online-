/*****************************************************************************/
/***************************  NAME  :  ahmed hassan **************************/
/***************************  DATE  :  11/25/2022   **************************/
/*************************  VERSION :  1.0          **************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(VAR,BIT_NUM) VAR|=(1<<BIT_NUM)
#define CLR_BIT(VAR,BIT_NUM) VAR&=~(1<<BIT_NUM)
#define TOG_BIT(VAR,BIT_NUM) VAR^=(1<<BIT_NUM)
#define GET_BIT(VAR,BIT_NUM) (VAR>>BIT_NUM)&1


#endif

