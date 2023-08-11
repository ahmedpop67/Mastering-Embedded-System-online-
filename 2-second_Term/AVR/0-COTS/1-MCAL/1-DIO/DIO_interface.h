 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  11/25/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/* macros for PortsID */
#define DIO_u8_PORTA           0
#define DIO_u8_PORTB           1
#define DIO_u8_PORTC           2
#define DIO_u8_PORTD           3

/* macros for PinsID */
#define DIO_u8_PIN0            0
#define DIO_u8_PIN1            1
#define DIO_u8_PIN2            2
#define DIO_u8_PIN3            3
#define DIO_u8_PIN4            4
#define DIO_u8_PIN5            5
#define DIO_u8_PIN6            6
#define DIO_u8_PIN7            7

/* macros for PIN_Direction */
#define DIO_u8_OUTPUT          1
#define DIO_u8_INPUT           0

/* macros for PIN_Value */
#define DIO_u8_HIGH            1
#define DIO_u8_LOW             0
void DIO_voidInit (void);

u8 DIO_u8SetpinDirection      (u8 copy_u8portID,u8 copy_u8PinID,u8 copy_u8PinDirection);

u8 DIO_u8SetpinValue          (u8 copy_u8portID,u8 copy_u8PinID,u8 copy_u8PinValue);

u8 DIO_u8GetPinValue          (u8 copy_u8portID,u8 copy_u8PinID,u8 * copy_pu8ReturnPinValue);

u8 DIO_u8SetPortDirection     (u8 copy_u8portID,u8 copy_u8PortDirection);

u8 DIO_u8SetPortValue         (u8 copy_u8portID,u8 copy_u8PortValue);

u8 DIO_u8GetPortValue         (u8 copy_u8portID,u8 * copy_pu8ReturnPortValue);

#endif




