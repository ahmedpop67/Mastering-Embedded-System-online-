 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  22/4/2023    **************************/
 /*************************  VERSION :  2.0          **************************/
 /*****************************************************************************/
 
 #ifndef STD_TYPES_H_
 #define STD_TYPES_H_
 
 #include<stdbool.h>
 //#include<stdint.h>
 
 #ifndef _Bool
 #define _Bool                               unsigned char
 #endif                                      
						                     
 #define CPU_TYPES                           CPU_TYPES_32       
 #define CPU_BIT_ORDER                       MSP_FIRST       
 #define CPU_BYTE_ORDER                      HIGH_BYTE_FIRST
						                     
 #ifndef FALSE                               
 #define FALSE                              (boolean)false
 #endif                                      
						                     
 #ifndef TRUE                                
 #define TRUE                               (boolean)true
 #endif                            
						           
 typedef _Bool                               boolean;
						                     
 typedef signed char                         sint8;
 typedef unsigned char                       uint8;
						                     
 typedef char                                char_t;
						                     
 typedef signed short int                    sint16;
 typedef unsigned short int                  uint16;
						                     
 typedef signed long int                     sint32;
 typedef unsigned long int                   uint32;
						                     
 typedef signed long long int                sint64;
 typedef signed long long int                uint64;
 
 typedef float                               f32;
 typedef double                              f64;
 typedef long double                         f96;
						                     
 typedef volatile signed char                vsint8;
 typedef volatile unsigned char              vuint8;
						          
 typedef volatile signed short int           vsint16;
 typedef volatile unsigned short int         vuint16;
						          
 typedef volatile signed long int            vsint32;
 typedef volatile unsigned long int          vuint32;
						          
 typedef volatile long long int              vsint64;
 typedef volatile long long int              vuint64;
 
 typedef volatile float                      vf32;
 typedef volatile double                     vf64;
 typedef volatile long double                vf96;
 
 #ifndef NULL
 #define NULL                                ((volatile void *)0)
 #endif
 
 #ifndef STD_TYPE_OK
 #define STD_TYPE_OK                          1
 #endif
 
 #ifndef STD_TYPE_NOK
 #define STD_TYPE_NOK                         0
 #endif
 
 #endif
