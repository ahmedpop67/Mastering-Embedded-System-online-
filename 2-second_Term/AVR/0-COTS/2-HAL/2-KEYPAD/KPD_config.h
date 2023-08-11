 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  12/3/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
														
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

#define KPD_ROWS                     4  //PINS
#define KPD_COLS                     4  //PINS

#define KPD_u8_R1_PIN_INPORT         DIO_u8_PORTB
#define KPD_u8_R1_PIN                DIO_u8_PIN0
#define KPD_u8_R2_PIN_INPORT         DIO_u8_PORTB
#define KPD_u8_R2_PIN                DIO_u8_PIN1
#define KPD_u8_R3_PIN_INPORT         DIO_u8_PORTB
#define KPD_u8_R3_PIN                DIO_u8_PIN2
#define KPD_u8_R4_PIN_INPORT         DIO_u8_PORTB
#define KPD_u8_R4_PIN                DIO_u8_PIN3

//#define KPD_u8_R5_PIN_INPORT       DIO_u8_PORTB
//#define KPD_u8_R5_PIN              DIO_u8_PIN3
//#define KPD_u8_R6_PIN_INPORT       DIO_u8_PORTB
//#define KPD_u8_R6_PIN              DIO_u8_PIN3
//#define KPD_u8_R7_PIN_INPORT       DIO_u8_PORTB
//#define KPD_u8_R7_PIN              DIO_u8_PIN3
//#define KPD_u8_R8_PIN_INPORT       DIO_u8_PORTB
//#define KPD_u8_R8_PIN              DIO_u8_PIN3
//#define KPD_u8_R9_PIN_INPORT       DIO_u8_PORTB
//#define KPD_u8_R9_PIN              DIO_u8_PIN3
//#define KPD_u8_R10_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_R10_PIN             DIO_u8_PIN3
//#define KPD_u8_R11_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_R11_PIN             DIO_u8_PIN3
//#define KPD_u8_R12_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_R12_PIN             DIO_u8_PIN3
//#define KPD_u8_R13_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_R13_PIN             DIO_u8_PIN3
//#define KPD_u8_R14_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_R14_PIN             DIO_u8_PIN3
//#define KPD_u8_R15_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_R15_PIN             DIO_u8_PIN3
//#define KPD_u8_R16_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_R16_PIN             DIO_u8_PIN3

#define KPD_u8_C1_PIN_INPORT         DIO_u8_PORTB
#define KPD_u8_C1_PIN                DIO_u8_PIN4
#define KPD_u8_C2_PIN_INPORT         DIO_u8_PORTB
#define KPD_u8_C2_PIN                DIO_u8_PIN5
#define KPD_u8_C3_PIN_INPORT         DIO_u8_PORTB
#define KPD_u8_C3_PIN                DIO_u8_PIN6
#define KPD_u8_C4_PIN_INPORT         DIO_u8_PORTB
#define KPD_u8_C4_PIN                DIO_u8_PIN7

//#define KPD_u8_C5_PIN_INPORT       DIO_u8_PORTB
//#define KPD_u8_C5_PIN              DIO_u8_PIN3
//#define KPD_u8_C6_PIN_INPORT       DIO_u8_PORTB
//#define KPD_u8_C6_PIN              DIO_u8_PIN3
//#define KPD_u8_C7_PIN_INPORT       DIO_u8_PORTB
//#define KPD_u8_C7_PIN              DIO_u8_PIN3
//#define KPD_u8_C8_PIN_INPORT       DIO_u8_PORTB
//#define KPD_u8_C8_PIN              DIO_u8_PIN3
//#define KPD_u8_C9_PIN_INPORT       DIO_u8_PORTB
//#define KPD_u8_C9_PIN              DIO_u8_PIN3
//#define KPD_u8_C10_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_C10_PIN             DIO_u8_PIN3
//#define KPD_u8_C11_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_C11_PIN             DIO_u8_PIN3
//#define KPD_u8_C12_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_C12_PIN             DIO_u8_PIN3
//#define KPD_u8_C13_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_C13_PIN             DIO_u8_PIN3
//#define KPD_u8_C14_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_C14_PIN             DIO_u8_PIN3
//#define KPD_u8_C15_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_C15_PIN             DIO_u8_PIN3
//#define KPD_u8_C16_PIN_INPORT      DIO_u8_PORTB
//#define KPD_u8_C16_PIN             DIO_u8_PIN3

#define KPD_KEYS                     {{'7','8','9','/'}, \
	                                  {'4','5','6','*'}, \
                                      {'1','2','3','-'}, \
                                      {'.','0','=','+'}}
 
#endif