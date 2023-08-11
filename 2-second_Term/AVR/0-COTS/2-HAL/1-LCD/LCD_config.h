 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  11/30/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
  /*****************************************************************************/
														
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*LCD_u8_MODE_8_BIT  --> 8BIT
  LCD_u8_MODE_4_BIT  --> 4BIT*/
#define LCD_u8_MODE                 LCD_u8_MODE_4_BIT 

#define LCD_u8_RS_INPORT            DIO_u8_PORTA
#define LCD_u8_RS_PIN               DIO_u8_PIN0
#define LCD_u8_RW_INPORT            DIO_u8_PORTA
#define LCD_u8_RW_PIN               DIO_u8_PIN1
#define LCD_u8_E_INPORT             DIO_u8_PORTA
#define LCD_u8_E_PIN                DIO_u8_PIN2

   /* IF LCD_u8_MODE = LCD_u8_MODE_8_BIT */
   
#define LCD_u8_DATA_PORT            DIO_u8_PORTB

   /* IF LCD_u8_MODE = LCD_u8_MODE_4_BIT
      OPTION(1) 1:DIO_u8_PORTA
	            2:DIO_u8_PORTB
	            3:DIO_u8_PORTC
	            4:DIO_u8_PORTD
				
      OPTION(2) 1:DIO_u8_PIN(0-->7) */
			 
#define LCD_u8_DATA_PIN0_INPORT     DIO_u8_PORTA
#define LCD_u8_DATA_PIN0            DIO_u8_PIN3
#define LCD_u8_DATA_PIN1_INPORT 	DIO_u8_PORTA
#define LCD_u8_DATA_PIN1            DIO_u8_PIN4
#define LCD_u8_DATA_PIN2_INPORT    	DIO_u8_PORTA
#define LCD_u8_DATA_PIN2            DIO_u8_PIN5
#define LCD_u8_DATA_PIN3_INPORT 	DIO_u8_PORTA
#define LCD_u8_DATA_PIN3            DIO_u8_PIN6

#endif