 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  3/30/2022   ***************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/

 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "UART_interface.h"
 #include "UART_private.h"
 #include "UART_config.h"
 u8 *local_pu8TXDataString=NULL;
 u8 *local_pu8RXDataString=NULL;
 static void(*UART_ApfUART[3])(void)={NULL,NULL,NULL};
 u8 local_u8_SizeString=0;
 u8 local_u8_counter=0;
 u8 local_u8_TX_Busyflag=0;
 u8 local_u8_RX_Busyflag=0;
 u8 local_u8_TRA_DONE=0;
 u8 local_u8_REC_DONE=0;
 u32 local_u32TRA_TIMEOUT=0;
 u32 local_u32TRASTR_TIMEOUT=0;
 u32 local_u32REC_TIMEOUT=0;
 u32 local_u32RECSTR_TIMEOUT=0;
 void UART_voidInit(u8 Copy_u8UBRR)
 {
	 u8 local_u8UCSRCValue=0b00000000;
	 UART_u8_UBRBL_REG=(u8)Copy_u8UBRR;
	 UART_u8_UBRBH_REG=(u8)(Copy_u8UBRR>>8);
	 //config of mode
	 local_u8UCSRCValue=0b10000000;
	 #if UART_u8_Mode==UART_u8_Asyn_Mode
	 CLR_BIT(local_u8UCSRCValue,UART_u8_UMSEL_BIT);
	 #if UART_u8_ASYN_Mode  ==UART_u8_Normal_Mode
	 CLR_BIT(UART_u8_UCSRA_REG,UART_u8_U2X_BIT);
	 #elif UART_u8_ASYN_Mode==UART_u8_Normal_Mode
	 SET_BIT(UART_u8_UCSRA_REG,UART_u8_U2X_BIT);
	 #endif
	 #elif UART_u8_Mode==UART_u8_Syn_Mode
	 SET_BIT(local_u8UCSRCValue,UART_u8_UMSEL_BIT);
	 #if UART_Clock_Polarity  ==UART_Rising_XCK_Edge
	 CLR_BIT(local_u8UCSRCValue,UART_u8_UCPOL_BIT);
	 #elif UART_Clock_Polarity==Falling_Rising_XCK_Edge
	 SET_BIT(local_u8UCSRCValue,UART_u8_UCPOL_BIT);
	 #endif
	 #endif
	 #if UART_u8_MPCM_Mode  ==UART_u8_MPCM_Disable
	 CLR_BIT(UART_u8_UCSRA_REG,UART_u8_MPCM_BIT);
	 #elif UART_u8_MPCM_Mode==UART_u8_MPCM_Enable
	 SET_BIT(UART_u8_UCSRA_REG,UART_u8_MPCM_BIT);
	 #endif
	 #if UART_Receiver_Mode  ==UART_u8_Receiver_Disable
	 CLR_BIT(UART_u8_UCSRB_REG,UART_u8_RXEN_BIT);
	 #elif UART_Receiver_Mode==UART_u8_Receiver_Enable
	 SET_BIT(UART_u8_UCSRB_REG,UART_u8_RXEN_BIT);
	 #endif
	 #if UART_Transmitter_Mode  ==UART_u8_Transmitter_Disable
	 CLR_BIT(UART_u8_UCSRB_REG,UART_u8_TXEN_BIT);
	 #elif UART_Transmitter_Mode==UART_u8_Transmitter_Enable
	 SET_BIT(UART_u8_UCSRB_REG,UART_u8_TXEN_BIT);
	 #endif
	 #if UART_RX_Interrupt  ==UART_RX_Interrupt_Disable
	 CLR_BIT(UART_u8_UCSRB_REG,UART_u8_RXCIE_BIT);
	 #elif UART_RX_Interrupt==UART_RX_Interrupt_Enable
	 SET_BIT(UART_u8_UCSRB_REG,UART_u8_RXCIE_BIT);
	 #endif
	 #if UART_TX_Interrupt  ==UART_TX_Interrupt_Disable
	 CLR_BIT(UART_u8_UCSRB_REG,UART_u8_TXCIE_BIT);
	 #elif UART_TX_Interrupt==UART_TX_Interrupt_Enable
	 SET_BIT(UART_u8_UCSRB_REG,UART_u8_TXCIE_BIT);
	 #endif
	 #if   UART_Data_REmpty_Interrupt ==UART_Data_REmpty_Interrupt_Disable
	 CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UDRIE_BIT);
	 #elif UART_Data_REmpty_Interrupt ==UART_Data_REmpty_Interrupt_Enable
	 SET_BIT(UART_u8_UCSRB_REG,UART_u8_UDRIE_BIT);
	 #endif
	 #if UART_Parity_Mode ==UART_Disable_Parity
	 CLR_BIT(local_u8UCSRCValue,UART_u8_UPM1_BIT);
	 CLR_BIT(local_u8UCSRCValue,UART_u8_UPM0_BIT);
	 #elif UART_Parity_Mode==UART_Even_Parity
	 SET_BIT(local_u8UCSRCValue,UART_u8_UPM1_BIT);
	 CLR_BIT(local_u8UCSRCValue,UART_u8_UPM0_BIT);
	 #elif UART_Parity_Mode==UART_Odd_Parity
	 SET_BIT(local_u8UCSRCValue,UART_u8_UPM1_BIT);
	 SET_BIT(local_u8UCSRCValue,UART_u8_UPM0_BIT);
	 #endif
	 #if   UART_STOP_BIT==UART_One_STOP_BIT
	 CLR_BIT(local_u8UCSRCValue,UART_u8_USBS_BIT);
	 #elif UART_STOP_BIT==UART_Two_STOP_BIT
	 SET_BIT(local_u8UCSRCValue,UART_u8_USBS_BIT);
	 #endif
	 #if   UART_Charcter_Size==UART_5BIT_Charcter_Size
	 CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT);
	 CLR_BIT(local_u8UCSRCValue,UART_u8_UCSZ1_BIT);
	 CLR_BIT(local_u8UCSRCValue,UART_u8_UCSZ0_BIT);
	 #elif UART_Charcter_Size==UART_6BIT_Charcter_Size
	 CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT);
	 CLR_BIT(local_u8UCSRCValue,UART_u8_UCSZ1_BIT);
	 SET_BIT(local_u8UCSRCValue,UART_u8_UCSZ0_BIT);
	 #elif UART_Charcter_Size==UART_7BIT_Charcter_Size
	 CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT);
	 SET_BIT(local_u8UCSRCValue,UART_u8_UCSZ1_BIT);
	 CLR_BIT(local_u8UCSRCValue,UART_u8_UCSZ0_BIT);
	 #elif UART_Charcter_Size==UART_8BIT_Charcter_Size
	 CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT);
	 SET_BIT(local_u8UCSRCValue,UART_u8_UCSZ1_BIT);
	 SET_BIT(local_u8UCSRCValue,UART_u8_UCSZ0_BIT);
	 #elif UART_Charcter_Size==UART_9BIT_Charcter_Size
	 SET_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT);
	 SET_BIT(local_u8UCSRCValue,UART_u8_UCSZ1_BIT);
	 SET_BIT(local_u8UCSRCValue,UART_u8_UCSZ0_BIT);
	 #endif
	 UART_u8_UCSRC_REG=local_u8UCSRCValue;
 }

 void UART_voidsendByte_Syn(u8 copy_u8DataByte)
 {
	 local_u32TRA_TIMEOUT=0;
	 while(!GET_BIT(UART_u8_UCSRA_REG,UART_u8_UDRE_BIT)&&local_u32TRA_TIMEOUT<=UART_u32_TRA_char_TIME_OUT)
	 {
		 local_u32TRA_TIMEOUT++;
	 }
	 if(local_u32TRA_TIMEOUT<UART_u32_TRA_char_TIME_OUT){
		 UART_u8_UDR_REG=copy_u8DataByte;
		 local_u8_TRA_DONE=1;
	 }
	 else
	 {
		 local_u8_TRA_DONE=0;
	 }
 }
 u8 UART_voidReciveByte_Syn(u8 *copy_pu8DataByte)
 {
	 local_u32REC_TIMEOUT=0;
	 u8 lacal_u8ErrorState = STD_TYPE_OK;
	 if(copy_pu8DataByte!=NULL)
	 {
		 while(!GET_BIT(UART_u8_UCSRA_REG,UART_u8_RXC_BIT)&&local_u32REC_TIMEOUT<=UART_u32_REC_char_TIME_OUT)
		 {
			 local_u32REC_TIMEOUT++;
		 }
		 if(local_u32REC_TIMEOUT<UART_u32_REC_char_TIME_OUT)
		 {
			 *copy_pu8DataByte=UART_u8_UDR_REG;
			 local_u8_REC_DONE=1;
		 }
		 else
		 {
			 local_u8_REC_DONE=0;
			 lacal_u8ErrorState=STD_TYPE_NOK;
		 }
	 }
	 else lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
 }

 void UART_voidsendString_Syn(u8 *copy_pu8DataString)
 {
	 local_u32TRASTR_TIMEOUT=0;
	 while(*copy_pu8DataString&&local_u32TRASTR_TIMEOUT<=UART_u32_TRA_string_TIME_OUT)
	 {
		 local_u32TRASTR_TIMEOUT++;
		 UART_voidsendByte_Syn(* copy_pu8DataString);
		 if(local_u8_TRA_DONE==1)
		 copy_pu8DataString++;
	 }
 }
 u8 UART_voidReciveString_Syn(u8 *copy_pu8DataString,u8 copy_u8_SizeString)
 {
	 u8 lacal_u8ErrorState = STD_TYPE_OK;
	 if(copy_pu8DataString!=NULL)
	 {
		 local_u32RECSTR_TIMEOUT=0;
		 while(copy_u8_SizeString && local_u32RECSTR_TIMEOUT<=UART_u32_REC_string_TIME_OUT)
		 {
			 UART_voidReciveByte_Syn(copy_pu8DataString);
			 if(local_u8_REC_DONE==1)
			 {
				 copy_pu8DataString++;
				 copy_u8_SizeString--;
			 }
		 }
	 }
	 else lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
 }

 void UART_voidsendString_ASyn(u8 *copy_pu8DataString,void(*copy_pISRF)(void))
 {
	 if(copy_pu8DataString!=NULL && local_u8_TX_Busyflag==0)
	 {
		 local_u8_TX_Busyflag=1;
		 UART_ApfUART[UART_u8_EMPTY_INTERUPT]=copy_pISRF;
		 local_pu8TXDataString=copy_pu8DataString;
		 SET_BIT(UART_u8_UCSRB_REG,UART_u8_UDRIE_BIT);
	 }
 }

u8 UART_voidReciveString_ASyn(u8 *copy_pu8DataString,u8 copy_u8_SizeString,void(*copy_pISRF)(void))
 {
	 if(copy_pu8DataString!=NULL && local_u8_RX_Busyflag==0)
	 {
		 local_u8_RX_Busyflag=1;
		 UART_ApfUART[UART_u8_RX_INTERUPT]=copy_pISRF;
		 local_pu8RXDataString=copy_pu8DataString;
		 local_u8_SizeString=copy_u8_SizeString;
		 if(GET_BIT(UART_u8_UCSRA_REG,UART_u8_RXC_BIT))
		 {
			 local_pu8RXDataString[local_u8_counter++]=UART_u8_UDR_REG;
		 }
		 SET_BIT(UART_u8_UCSRB_REG,UART_u8_RXCIE_BIT);
	 }
 }
 
 void __vector_14(void)    __attribute__((signal));
 void __vector_14(void)
 {  
	 static u8 counter=0;
 	 if(local_pu8TXDataString[counter])
	 {
		 UART_u8_UDR_REG=local_pu8TXDataString[counter];
		 counter++;
	 }
	 else
	 {
		 CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UDRIE_BIT);
		 local_u8_TX_Busyflag=0;
		 counter;
		 if(UART_ApfUART[UART_u8_EMPTY_INTERUPT]!=NULL)
		 {
			 UART_ApfUART[UART_u8_EMPTY_INTERUPT]();
		 }
	 }
 }
 
 void __vector_13(void)    __attribute__((signal));
 void __vector_13(void)
 {
	 if(local_u8_counter<local_u8_SizeString)
	 {
		 local_pu8RXDataString[local_u8_counter++]=UART_u8_UDR_REG;
	 }
	 if(local_u8_counter>=local_u8_SizeString)
	 {
		CLR_BIT(UART_u8_UCSRB_REG,UART_u8_RXCIE_BIT);
		local_u8_RX_Busyflag=0;
		local_u8_counter=0;
		if(UART_ApfUART[UART_u8_RX_INTERUPT]!=NULL)
		{
			UART_ApfUART[UART_u8_RX_INTERUPT]();
		} 
	 } 
 }