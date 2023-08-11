 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  30/1/2023    **************************/
 /***************************VERSION :  1.0          **************************/
 /*****************************************************************************/
 
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define UART_u32_TRA_char_TIME_OUT            30000
#define UART_u32_TRA_string_TIME_OUT          50000
#define UART_u32_REC_char_TIME_OUT            30000
#define UART_u32_REC_string_TIME_OUT          50000

/*
1-   UART_u8_Asyn_Mode
1-   UART_u8_Syn_Mode
*/
#define UART_u8_Mode                   UART_u8_Asyn_Mode    

/*chooser mode of asyn uart
1-   UART_u8_Normal_Mode
2-   UART_u8_Double_Speed_Mode
*/
#define UART_u8_ASYN_Mode              UART_u8_Normal_Mode

/*
1-   UART_u8_MPCM_Disable
2-   UART_u8_MPCM_Enable
*/
#define UART_u8_MPCM_Mode              UART_u8_MPCM_Disable

/*Receiver mode
1-   UART_u8_Receiver_Disable
2-   UART_u8_Receiver_Enable
*/ 
#define UART_Receiver_Mode             UART_u8_Receiver_Enable

/*RX Complete Interrupt
1-  UART_RX_Interrupt_Disable
1-  UART_RX_Interrupt_Enable
*/
#define UART_RX_Interrupt              UART_RX_Interrupt_Disable

/*Receiver mode
1-   UART_u8_Transmitter_Disable
2-   UART_u8_Transmitter_Enable
*/

#define UART_Transmitter_Mode          UART_u8_Transmitter_Enable

/*RX Complete Interrupt
1-  UART_TX_Interrupt_Disable
1-  UART_TX_Interrupt_Enable
*/
#define UART_TX_Interrupt              UART_TX_Interrupt_Disable

/*USART Data Register Empty Interrupt Enable
1-  UART_Data_REmpty_Interrupt_Disable
1-  UART_Data_REmpty_Interrupt_Enable
*/
#define UART_Data_REmpty_Interrupt      UART_Data_REmpty_Interrupt_Disable

/*parity mode
1-   UART_Disable_Parity
2-   UART_Even_Parity
3-   UART_Odd_Parity
 */
#define UART_Parity_Mode               UART_Disable_Parity

/*stop bit
1-   UART_One_STOP_BIT
2-   UART_Two_STOP_BIT
*/
#define UART_STOP_BIT                  UART_One_STOP_BIT

/*character size
1-   UART_5BIT_Charcter_Size
2-   UART_6BIT_Charcter_Size
3-   UART_7BIT_Charcter_Size
4-   UART_8BIT_Charcter_Size
5-   UART_9BIT_Charcter_Size
*/
#define UART_Charcter_Size            UART_8BIT_Charcter_Size

/* Clock Polarity in Synchronous mode
1-   UART_Rising_XCK_Edge
2-   Falling_Rising_XCK_Edge
*/
#define UART_Clock_Polarity           UART_Rising_XCK_Edge
#endif