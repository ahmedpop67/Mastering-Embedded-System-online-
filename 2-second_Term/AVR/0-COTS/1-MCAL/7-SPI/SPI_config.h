 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  30/1/2023    **************************/
 /***************************VERSION :  1.0          **************************/
 /*****************************************************************************/
 
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*SPI ENABLE 
1- SPI_u8_DISBLE
2- SPI_u8_ENABLE
*/
#define SPI_u8_SPI_State         SPI_u8_DISBLE

/* MODE OF  SPI
1-   SPI_u8_Master_Mode
2-   SPI_u8_Slave_Mode
*/
#define SPI_u8_Select_MODE       SPI_u8_Master_Mode

/*clock plarity AND PHASE
1-   SPI_u8_Sample_Rising_Loading_Edge
2-   SPI_u8_Sample_Falling_Loading_Edge
3-   SPI_u8_Setup_Rising_Loading_Edge
4-   SPI_u8_Setup_Falling_Loading_Edge
*/

#define SPI_u8_clock_mode        SPI_u8_Sample_Rising_Loading_Edge

/*clock rate 
1-   SPI_u8_Clock_Div_4
2-   SPI_u8_Clock_Div_16
3-   SPI_u8_Clock1_Div_64
4-   SPI_u8_Clock_Div_128
5-   SPI_u8_Clock_Div_2
6-   SPI_u8_Clock_Div_8
7-   SPI_u8_Clock_Div_32
8-   SPI_u8_Clock2_Div_64
*/
#define SPI_u8_clock_Rate        SPI_u8_Clock_Div_4

/*DATA ORDER 
1-  SPI_u8_LSB_MODE
2-  SPI_u8_MSB_MODE
*/
#define SPI_u8_Data_Order        SPI_u8_LSB_MODE

/*SPI INTERUPT STATE
1-  SPI_u8_SPI_Interupt_Disable
2-  SPI_u8_SPI_Interupt_Enable
*/
#define SPI_u8_INTERUPT_STATE    SPI_u8_SPI_Interupt_Disable

#endif