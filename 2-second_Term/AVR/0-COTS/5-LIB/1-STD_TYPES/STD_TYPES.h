/*****************************************************************************/
/***************************  NAME  :  ahmed hassan **************************/
/***************************  DATE  :  11/25/2022   **************************/
/*************************  VERSION :  1.0          **************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char        u8;
typedef unsigned short int   u16;
typedef unsigned long int    u32;


typedef signed char          s8;
typedef signed short int     s16;
typedef signed long int      s32;


typedef float                f32;
typedef double               f64;
typedef long double          f96;

#define DPRINT(debug_level,...) if (debug_level > 1)\
                                    printf("@ Func: %s, File: %s, Line: %d",__FUNC__,__FILE__,__LINE__);\
									printf(">> \t");\
									printf(__VA_ARGS__);
#define STD_TYPE_OK     1
#define STD_TYPE_NOK    0

#define NULL   ((void *)0)

#endif

