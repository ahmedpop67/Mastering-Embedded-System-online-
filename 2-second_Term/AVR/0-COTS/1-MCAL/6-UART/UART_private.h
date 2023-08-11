 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  3/30/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/

 #ifndef UART_PRIVATE_H
 #define UART_PRIVATE_H
 // UDR  UCSRA  UCSRB UCSRC  UBRRH UBRRL
 #define UART_u8_UDR_REG                      *((volatile u8 *)0x2C)
 #define UART_u8_UCSRA_REG                    *((volatile u8 *)0x2B)
 #define UART_u8_UCSRB_REG                    *((volatile u8 *)0x2A)
 #define UART_u8_UCSRC_REG                    *((volatile u8 *)0x40)
 #define UART_u8_UBRBL_REG                    *((volatile u8 *)0x29)
 #define UART_u8_UBRBH_REG                    *((volatile u8 *)0x40)
 
 //BIT IN REG UCSRA
 #define UART_u8_MPCM_BIT                     0
 #define UART_u8_U2X_BIT                      1
 #define UART_u8_PE_BIT                       2
 #define UART_u8_DOR_BIT                      3
 #define UART_u8_FE_BIT                       4
 #define UART_u8_UDRE_BIT                     5
 #define UART_u8_TXC_BIT                      6
 #define UART_u8_RXC_BIT                      7
 
 //BIT IN REG UCSRB
 #define UART_u8_TXB8_BIT                     0
 #define UART_u8_RXB8_BIT                     1
 #define UART_u8_UCSZ2_BIT                    2
 #define UART_u8_TXEN_BIT                     3
 #define UART_u8_RXEN_BIT                     4
 #define UART_u8_UDRIE_BIT                    5
 #define UART_u8_TXCIE_BIT                    6
 #define UART_u8_RXCIE_BIT                    7
 
 //BIT IN REG UCSRC
 #define UART_u8_UCPOL_BIT                    0
 #define UART_u8_UCSZ0_BIT                    1
 #define UART_u8_UCSZ1_BIT                    2
 #define UART_u8_USBS_BIT                     3
 #define UART_u8_UPM0_BIT                     4
 #define UART_u8_UPM1_BIT                     5
 #define UART_u8_UMSEL_BIT                    6
 #define UART_u8_URSEL_BIT                    7
 
 //chooser mode of uart
 #define UART_u8_Asyn_Mode                    0
 #define UART_u8_Syn_Mode                     1
 
 //chooser mode of asyn uart
 #define UART_u8_Normal_Mode                  0
 #define UART_u8_Double_Speed_Mode            1
 
 // MPCM
 #define UART_u8_MPCM_Disable		          0
 #define UART_u8_MPCM_Enable			      1

 //Receiver Transmitter and mode
 #define UART_u8_Receiver_Disable		      0
 #define UART_u8_Receiver_Enable              1
 #define UART_u8_Transmitter_Disable          2
 #define UART_u8_Transmitter_Enable           3
 
 //RX TX Complete Interrupt and USART Data Register Empty Interrupt
 #define UART_RX_Interrupt_Disable            0
 #define UART_RX_Interrupt_Enable             1
 #define UART_TX_Interrupt_Disable            2
 #define UART_TX_Interrupt_Enable             3
 #define UART_Data_REmpty_Interrupt_Disable   4
 #define UART_Data_REmpty_Interrupt_Enable    5

 //parity mode
 #define UART_Disable_Parity                  0
 #define UART_Even_Parity                     1
 #define UART_Odd_Parity                      2
 
 //stop bit
 #define UART_One_STOP_BIT                    0
 #define UART_Two_STOP_BIT                    1
 
 //character size
 #define UART_5BIT_Charcter_Size              0
 #define UART_6BIT_Charcter_Size              1
 #define UART_7BIT_Charcter_Size              2
 #define UART_8BIT_Charcter_Size              3
 #define UART_9BIT_Charcter_Size              4
 
 
 // Clock Polarity in Synchronous mode
 #define UART_Rising_XCK_Edge                 0
 #define Falling_Rising_XCK_Edge              1

 #define UART_u8_TX_INTERUPT                  0
 #define UART_u8_RX_INTERUPT                  1
 #define UART_u8_EMPTY_INTERUPT               2
 #endif