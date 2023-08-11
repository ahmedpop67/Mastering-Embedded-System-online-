 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  1/17/2022    **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
 
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "TIMER_interface.h"
 #include "TIMER_private.h"
 #include "TIMER_config.h"
 //static void(*TIMER0_pfTimerOVF)(void)=NULL;
 static void(*TIMER_pfTimerOVF[8])(void)={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
 static u8 local_u8_start_flag[3] ={0};
 static u8 local_u8_timer_clock[3]={0};
 void TIMER_Voidinit(void)
 {
	 /////////////////////////////////TIMER0///////////////////////////////////
	 /*Select mode*/
	 #if TIMER0_u8_ENA_DIS==TIMER0_u8_EANBLE
	 #if TIMER0_u8Mode==TIMER0_u8Normal_mode
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01);
	 #if TIMER0_u8OC0_CTC_Mode==TIMER0_u8OC0_Disconnect_CTC_Mode
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #elif TIMER0_u8OC0_CTC_Mode==TIMER0_u8OC0_Toggle_CTC_Mode
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #elif TIMER0_u8OC0_CTC_Mode==TIMER0_u8OC0_Clear_CTC_Mode
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #elif TIMER0_u8OC0_CTC_Mode==TIMER0_u8OC0_Set_CTC_Mode
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #endif
	 #elif TIMER0_u8Mode==TIMER0_u8CTC_mode
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00);
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01);
	 #if TIMER0_u8OC0_CTC_Mode==TIMER0_u8OC0_Disconnect_CTC_Mode
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #elif TIMER0_u8OC0_CTC_Mode==TIMER0_u8OC0_Toggle_CTC_Mode
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #elif TIMER0_u8OC0_CTC_Mode==TIMER0_u8OC0_Clear_CTC_Mode
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #elif TIMER0_u8OC0_CTC_Mode==TIMER0_u8OC0_Set_CTC_Mode
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #endif
	 #elif TIMER0_u8Mode==TIMER0_u8Fast_PWM_mode
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00);
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01);
	 #if TIMER0_u8OC0_PWM_Mode==TIMER0_u8OC0_Disconnect_PWM_Mode
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #elif TIMER0_u8OC0_PWM_Mode==TIMER0_u8OC0_Clear_PWM_Mode
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #elif TIMER0_u8OC0_PWM_Mode==TIMER0_u8OC0_Set_PWM_Mode
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #endif
	 #elif TIMER0_u8Mode==TIMER0_u8Phase_PWM_mode
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01);
	 #if TIMER0_u8OC0_PWM_Mode==TIMER0_u8OC0_Disconnect_PWM_Mode
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #elif TIMER0_u8OC0_PWM_Mode==TIMER0_u8OC0_Clear_PWM_Mode
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #elif TIMER0_u8OC0_PWM_Mode==TIMER0_u8OC0_Set_PWM_Mode
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
	 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
	 #endif
	 #endif
	 //enable ovf
	 #if TIMER0_u8_Ovf_Interrupt_State==TIMER0_u8_Ovf_Interrupt_Disable
	 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER0_u8_TOIE0);
	 #elif TIMER0_u8_Ovf_Interrupt_State==TIMER0_u8_Ovf_Interrupt_Enable
	 SET_BIT(TIMER_u8_TIMSK_REG,TIMER0_u8_TOIE0);
	 #endif
	 
	 #if TIMER0_u8_CTC_Interrupt_State==TIMER0_u8_CTC_Interrupt_Disable
	 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER0_u8_OCIE0);
	 #elif TIMER0_u8_CTC_Interrupt_State==TIMER0_u8_CTC_Interrupt_Enable
	 SET_BIT(TIMER_u8_TIMSK_REG,TIMER0_u8_OCIE0);
	 #endif
	 
	 TIMER0_u8_TCNT0_REG=TIMER0_u8Counter_Write;
	 TIMER0_u8_OCR0_REG=TIMER0_u8Compere_Write;
	 
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
	 #endif
	 
	 /////////////////////////////////TIMER1///////////////////////////////////
	 /*Select mode*/
	 #if TIMER1_u8_ENA_DIS==TIMER1_u8_EANBLE
	 #if TIMER1_u8Mode==TIMER1_u8Normal_mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #elsif TIMER1_u8Mode==TIMER1_u8PhaseC_PWM_8_bit_mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #elsif TIMER1_u8Mode==TIMER1_u8PhaseC_PWM_9_bit_mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #elsif TIMER1_u8Mode==TIMER1_u8PhaseC_PWM_10_bit_mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #elsif TIMER1_u8Mode==TIMER1_u8CTC_mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #elsif TIMER1_u8Mode==TIMER1_u8Fast_PWM_8_bi_mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #elsif TIMER1_u8Mode==TIMER1_u8Fast_PWM_9_bit_mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #elsif TIMER1_u8Mode==TIMER1_u8Fast_PWM_10_bit_mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #elsif TIMER1_u8Mode==TIMER1_u8_Phase_Freq_PWM_ICR1_mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 TIMER1_u16_ICR1_REG=TIMER1_u8ICR1_Write;
	 #elsif TIMER1_u8Mode==TIMER1_u8_Phase_Freq_PWM_OCR1A_mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #elsif TIMER1_u8Mode==TIMER1_u8_PhaseC_PWM_ICR1_mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 TIMER1_u16_ICR1_REG=TIMER1_u8ICR1_Write;
	 #elsif TIMER1_u8Mode==TIMER1_u8_PhaseC_PWM_OCR1A_mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #elsif TIMER1_u8Mode==TIMER1_u8_CTC_ICR1_mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 TIMER1_u16_ICR1_REG=TIMER1_u8ICR1_Write;
	 #elsif TIMER1_u8Mode==TIMER1_u8_Fast_PWM_ICR1_mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 TIMER1_u16_ICR1_REG=TIMER1_u8ICR1_Write;
	 #elsif TIMER1_u8Mode==TIMER1_u8_Fast_PWM_OCR1A_mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM13);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM12);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM11);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_WGM10);
	 #endif
	 #if (TIMER1_u8Mode==TIMER1_u8Normal_mode || TIMER1_u8Mode==TIMER1_u8CTC_mode || TIMER1_u8Mode==TIMER1_u8_CTC_ICR1_mode)
	 #if TIMER1_u8OC1A_CTC_Mode==TIMER1_u8OC1A_Disconnect_CTC_Mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A1);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A0);
	 #elif TIMER1_u8OC1A_CTC_Mode==TIMER1_u8OC1A_Toggle_CTC_Mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A1);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A0);
	 #elif TIMER1_u8OC1A_CTC_Mode==TIMER1_u8OC1A_Clear_CTC_Mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A1);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A0);
	 #elif TIMER1_u8OC1A_CTC_Mode==TIMER1_u8OC1A_Set_CTC_Mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A1);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A0);
	 #endif
	 #if TIMER1_u8OC1B_CTC_Mode==TIMER1_u8OC1B_Disconnect_CTC_Mode
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B1);
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B0);
	 #elif TIMER1_u8OC1B_CTC_Mode==TIMER1_u8OC1B_Toggle_CTC_Mode
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B1);
	 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B0);
	 #elif TIMER1_u8OC1B_CTC_Mode==TIMER1_u8OC1B_Clear_CTC_Mode
	 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B1);
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B0);
	 #elif TIMER1_u8OC1B_CTC_Mode==TIMER1_u8OC1B_Set_CTC_Mode
	 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B1);
	 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B0);
	 #endif
	 #else
	 #if TIMER1_u8OC1A_PWM_Mode==TIMER1_u8OC1A_Disconnect_PWM_Mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A1);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A0);
	 #elif TIMER1_u8OC1A_PWM_Mode==TIMER1_u8OC1_Togle_PWM_Mode
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A1);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A0);
	 #elif TIMER1_u8OC1A_PWM_Mode==TIMER1_u8OC1A_Clear_PWM_Mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A1);
	 CLR_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A0);
	 #elif TIMER1_u8OC1A_PWM_Mode==TIMER1_u8OC1A_Set_PWM_Mode
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A1);
	 SET_BIT(TIMER1_u8_TCCRA1_REG,TIMER1_u8_COM1A0);
	 #endif
	 #if TIMER1_u8OC1B_PWM_Mode==TIMER1_u8OC1B_Disconnect_PWM_Mode
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B1);
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B0);
	 #elif TIMER1_u8OC1B_PWM_Mode==TIMER1_u8OC1_Togle_PWM_Mode
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B1);
	 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B0);
	 #elif TIMER1_u8OC1B_PWM_Mode==TIMER1_u8OC1B_Clear_PWM_Mode
	 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B1);
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B0);
	 #elif TIMER1_u8OC1B_PWM_Mode==TIMER1_u8OC1B_Set_PWM_Mode
	 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B1);
	 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_COM1B0);
	 #endif
	 #endif
	 #if TIMER1_u8_Ovf_Interrupt_State  ==TIMER1_u8_Ovf_Interrupt_Disable
	 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER1_u8_TOIE1);
	 #elif TIMER1_u8_Ovf_Interrupt_State== TIMER1_u8_Ovf_Interrupt_Enable
	 SET_BIT(TIMER_u8_TIMSK_REG,TIMER1_u8_TOIE1);
	 #endif
	 #if TIMER1_u8_CTCA_Interrupt_State==TIMER1_u8_CTCA_Interrupt_Disable
	 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER1_u8_OCIE1A);
	 #elif TIMER1_u8_CTCA_Interrupt_State==TIMER1_u8_CTCA_Interrupt_Enable
	 SET_BIT(TIMER_u8_TIMSK_REG,TIMER1_u8_OCIE1A);
	 #endif
	 #if TIMER1_u8_CTCB_Interrupt_State==TIMER1_u8_CTCB_Interrupt_Disable
	 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER1_u8_OCIE1B);
	 #elif TIMER1_u8_CTCB_Interrupt_State==TIMER1_u8_CTCB_Interrupt_Enable
	 SET_BIT(TIMER_u8_TIMSK_REG,TIMER1_u8_OCIE1B);
	 #endif
	 #if TIMER1_u8_InCap_NOISE_Canc==TIMER1_u8_InCap_NOISE_Canc_Enable
	 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_ICNC1);
	 #if   TIMER1_u8_InCap_Edge==TIMER1_u8_InCap_Falling_Edge
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_ICES1);
	 #elif TIMER1_u8_InCap_Edge==TIMER1_u8_InCap_Raising_Edge
	 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_ICES1);
	 #endif
	 #endif
	 #if TIMER1_u8_InCap_Interrupt_State==TIMER1_u8_ICI_Interrupt_Enable
	 SET_BIT(TIMER_u8_TIMSK_REG,TIMER1_u8_TICIE1);
	 #endif
	 TIMER1_u16_TCNT1_REG=TIMER1_u8Counter_Write;
	 TIMER1_u16_OCR1A_REG=TIMER1_u8CompereA_Write;
	 TIMER1_u16_OCR1B_REG=TIMER1_u8CompereB_Write;
	 #endif

	 /////////////////////////////////TIMER2///////////////////////////////////
	 
	 /*Select mode*/
	 #if TIMER2_u8_ENA_DIS==TIMER2_u8_EANBLE
	 #if TIMER2_u8Mode==TIMER2_u8Normal_mode
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM20);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM21);
	 #if TIMER2_u8OC2_CTC_Mode==TIMER2_u8OC2_Disconnect_CTC_Mode
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #elif TIMER2_u8OC2_CTC_Mode==TIMER2_u8OC2_Toggle_CTC_Mode
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #elif TIMER2_u8OC2_CTC_Mode==TIMER2_u8OC2_Clear_CTC_Mode
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #elif TIMER2_u8OC2_CTC_Mode==TIMER2_u8OC2_Set_CTC_Mode
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #endif
	 #elif TIMER2_u8Mode==TIMER2_u8CTC_mode
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM20);
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM21);
	 #if TIMER2_u8OC2_CTC_Mode==TIMER2_u8OC2_Disconnect_CTC_Mode
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #elif TIMER2_u8OC2_CTC_Mode==TIMER2_u8OC2_Toggle_CTC_Mode
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #elif TIMER2_u8OC2_CTC_Mode==TIMER2_u8OC2_Clear_CTC_Mode
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #elif TIMER2_u8OC2_CTC_Mode==TIMER2_u8OC2_Set_CTC_Mode
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #endif
	 #elif TIMER2_u8Mode==TIMER2_u8Fast_PWM_mode
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM20);
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM21);
	 #if TIMER2_u8OC2_PWM_Mode==TIMER2_u8OC2_Disconnect_PWM_Mode
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #elif TIMER2_u8OC2_PWM_Mode==TIMER2_u8OC2_Clear_PWM_Mode
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #elif TIMER2_u8OC2_PWM_Mode==TIMER2_u8OC2_Set_PWM_Mode
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #endif
	 #elif TIMER2_u8Mode==TIMER2_u8Phase_PWM_mode
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM20);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM21);
	 #if TIMER2_u8OC2_PWM_Mode==TIMER2_u8OC2_Disconnect_PWM_Mode
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #elif TIMER2_u8OC2_PWM_Mode==TIMER2_u8OC2_Clear_PWM_Mode
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #elif TIMER2_u8OC2_PWM_Mode==TIMER2_u8OC2_Set_PWM_Mode
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
	 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
	 #endif
	 #endif
	 //enable ovf
	 #if TIMER2_u8_Ovf_Interrupt_State==TIMER2_u8_Ovf_Interrupt_Disable
	 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER2_u8_TOIE2);
	 #elif TIMER2_u8_Ovf_Interrupt_State==TIMER2_u8_Ovf_Interrupt_Enable
	 SET_BIT(TIMER_u8_TIMSK_REG,TIMER2_u8_TOIE2);
	 #endif
	 
	 #if TIMER2_u8_CTC_Interrupt_State==TIMER2_u8_CTC_Interrupt_Disable
	 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER2_u8_OCIE2);
	 #elif TIMER2_u8_CTC_Interrupt_State==TIMER2_u8_CTC_Interrupt_Enable
	 SET_BIT(TIMER_u8_TIMSK_REG,TIMER2_u8_OCIE2);
	 #endif
	 
	 TIMER2_u8_TCNT2_REG=TIMER2_u8Counter_Write;
	 TIMER2_u8_OCR2_REG=TIMER2_u8Compere_Write;
	 
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
	 #endif
	 
	 
	 
 }
 void TIMER0_Start(void)
 {
	 if (local_u8_start_flag[0]==0)
	 {
		 #if TIMER0_u8_Clock==TIMER0_u8_NO_CLOCK
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
		 #elif TIMER0_u8_Clock==TIMER0_u8_1_Prescaler
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
		 #elif TIMER0_u8_Clock==TIMER0_u8_8_Prescaler
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
		 #elif TIMER0_u8_Clock==TIMER0_u8_64_Prescaler
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
		 #elif TIMER0_u8_Clock==TIMER0_u8_256_Prescaler
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
		 #elif TIMER0_u8_Clock==TIMER0_u8_1024_Prescaler
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
		 #elif TIMER0_u8_Clock==TIMER0_u8_Ext_Fal_Edge
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
		 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
		 #elif TIMER0_u8_Clock==TIMER0_u8_Ext_Ris_Edge
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
		 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
		 #endif
	 }
	 else if(local_u8_start_flag[0]==1)
	 {
		 switch(local_u8_timer_clock[0])
		 {
			 case TIMER_u8_NO_CLOCK:
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
			 break;
			 case TIMER_u8_1_Presc:
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
			 break;
			 case TIMER_u8_8_Presc:
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
			 break;
			 case TIMER_u8_64_Presc:
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
			 break;
			 case TIMER_u8_256_Presc:
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
			 break;
			 case TIMER_u8_1024_Presc:
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
			 break;
			 case TIMER_u8_Ext_Fal_Edge:
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
			 break;
			 case TIMER_u8_Ext_Ris_Edge:
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
			 break;
			 default:break;
		 }
	 }
 }
 
 void TIMER1_Start(void)
 {
	 if (local_u8_start_flag[1]==0)
	 {
		 #if TIMER0_u8_Clock==TIMER1_u8_NO_CLOCK
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
		 #elif TIMER0_u8_Clock==TIMER1_u8_1_Prescaler
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
		 #elif TIMER1_u8_Clock==TIMER1_u8_8_Prescaler
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
		 #elif TIMER1_u8_Clock==TIMER1_u8_64_Prescaler
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
		 #elif TIMER1_u8_Clock==TIMER1_u8_256_Prescaler
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
		 #elif TIMER1_u8_Clock==TIMER1_u8_1024_Prescaler
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
		 #elif TIMER1_u8_Clock==TIMER1_u8_Ext_Fal_Edge
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
		 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
		 #elif TIMER1_u8_Clock==TIMER1_u8_Ext_Ris_Edge
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
		 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
		 #endif
	 }
	 else if(local_u8_start_flag[1]==1)
	 {
		 switch(local_u8_timer_clock[1])
		 {
			 case TIMER_u8_NO_CLOCK:
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
			 break;
			 case TIMER_u8_1_Presc:
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
			 break;
			 case TIMER_u8_8_Presc:
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
			 break;
			 case TIMER_u8_64_Presc:
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
			 break;
			 case TIMER_u8_256_Presc:
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
			 break;
			 case TIMER_u8_1024_Presc:
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
			 break;
			 case TIMER_u8_Ext_Fal_Edge:
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
			 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
			 break;
			 case TIMER_u8_Ext_Ris_Edge:
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
			 SET_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
			 break;
			 default:break;
		 }
	 }
 }
 
 
 void TIMER2_Start(void)
 {
	 
	 if (local_u8_start_flag[2]==0)
	 {
		 #if TIMER2_u8_Clock==TIMER2_u8_NO_CLOCK
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
		 #elif TIMER2_u8_Clock==TIMER2_u8_1_Prescaler
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
		 #elif TIMER2_u8_Clock==TIMER2_u8_8_Prescaler
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
		 #elif TIMER2_u8_Clock==TIMER2_u8_32_Prescaler
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
		 #elif TIMER2_u8_Clock==TIMER2_u8_64_Prescaler
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
		 #elif TIMER2_u8_Clock==TIMER2_u8_128_Prescaler
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
		 #elif TIMER2_u8_Clock==TIMER2_u8_256_Prescaler
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
		 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
		 #elif TIMER2_u8_Clock==TIMER2_u8_1024_Prescaler
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
		 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
		 #endif
	 }
	 else if(local_u8_start_flag[2]==1)
	 {
		 switch(local_u8_timer_clock[2])
		 {
			 case TIMER2_u8_NO_CLOCK:
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
			 break;
			 case TIMER2_u8_1_Presc:
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
			 break;
			 case TIMER_u8_8_Presc:
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
			 break;
			 case TIMER2_u8_32_Presc:
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
			 break;
			 case TIMER2_u8_64_Presc:
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
			 break;
			 case TIMER2_u8_128_Presc:
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
			 break;
			 case TIMER2_u8_256_Presc:
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
			 break;
			 case TIMER2_u8_1024_Presc:
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
			 break;
			 default:break;
		 }
	 }
 }

 u8 TIMER0_Init(TIMER_str *Copy_Pstr_timer)
 {
	 u8 lacal_u8ErrorState=STD_TYPE_OK;
	 if(Copy_Pstr_timer!=NULL)
	 {
		 switch(Copy_Pstr_timer->mode)
		 {
			 case TIMER_u8Normal_mode:
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00);
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01);
			 switch(Copy_Pstr_timer->OC_mode)
			 {
				 case TIMER_u8OC_Disconnect_CTC_Mode:
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 case TIMER_u8OC_Toggle_CTC_Mode:
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 case TIMER_u8OC_Clear_CTC_Mode:
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 case TIMER_u8OC_Set_CTC_Mode:
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
			 }
			 break;
			 case TIMER_u8CTC_mode:
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01);
			 switch(Copy_Pstr_timer->OC_mode)
			 {
				 case TIMER_u8OC_Disconnect_CTC_Mode:
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 case TIMER_u8OC_Toggle_CTC_Mode:
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 case TIMER_u8OC_Clear_CTC_Mode:
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 case TIMER_u8OC_Set_CTC_Mode:
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
			 }
			 break;
			 case TIMER_u8Fast_PWM_mode:
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01);
			 switch(Copy_Pstr_timer->OC_mode)
			 {
				 case TIMER_u8OC_Disconnect_PWM_Mode:
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 case TIMER_u8OC_Clear_PWM_Mode:
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 case TIMER_u8OC_Set_PWM_Mode:
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
			 }
			 break;
			 case TIMER_u8Phase_PWM_mode:
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00);
			 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01);
			 switch(Copy_Pstr_timer->OC_mode)
			 {
				 case TIMER_u8OC_Disconnect_PWM_Mode:
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 case TIMER_u8OC_Clear_PWM_Mode:
				 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 case TIMER_u8OC_Set_PWM_Mode:
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00);
				 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01);
				 break;
				 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
			 }
			 break;
			 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
		 }
		 TIMER0_u8_TCNT0_REG=Copy_Pstr_timer->TIMER_Value;
		 TIMER0_u8_OCR0_REG =Copy_Pstr_timer->Compare_Value;
		 switch(Copy_Pstr_timer->overflow_interrupt)
		 {
			 case TIMER_u8_Ovf_Interrupt_Disable:
			 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER0_u8_TOIE0);
			 break;
			 case TIMER_u8_Ovf_Interrupt_Enable:
			 SET_BIT(TIMER_u8_TIMSK_REG,TIMER0_u8_TOIE0);
			 break;
			 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
		 }
		 switch(Copy_Pstr_timer->ctc_interrupt)
		 {
			 case TIMER_u8_CTC_Interrupt_Disable:
			 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER0_u8_OCIE0);
			 break;
			 case TIMER_u8_CTC_Interrupt_Enable:
			 SET_BIT(TIMER_u8_TIMSK_REG,TIMER0_u8_OCIE0);
			 break;
			 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
		 }
		 local_u8_timer_clock[0]=Copy_Pstr_timer->clock;
		 local_u8_start_flag[0]=1;

	 }
	 else lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
 }

 u8 TIMER2_Init(TIMER_str *Copy_Pstr_timer)
 {
	 u8 lacal_u8ErrorState=STD_TYPE_OK;
	 if(Copy_Pstr_timer!=NULL)
	 {
		 switch(Copy_Pstr_timer->mode)
		 {
			 case TIMER_u8Normal_mode:
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM20);
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM21);
			 switch(Copy_Pstr_timer->OC_mode)
			 {
				 case TIMER_u8OC_Disconnect_CTC_Mode:
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 case TIMER_u8OC_Toggle_CTC_Mode:
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 case TIMER_u8OC_Clear_CTC_Mode:
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 case TIMER_u8OC_Set_CTC_Mode:
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
			 }
			 break;
			 case TIMER_u8CTC_mode:
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM20);
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM21);
			 switch(Copy_Pstr_timer->OC_mode)
			 {
				 case TIMER_u8OC_Disconnect_CTC_Mode:
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 case TIMER_u8OC_Toggle_CTC_Mode:
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 case TIMER_u8OC_Clear_CTC_Mode:
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 case TIMER_u8OC_Set_CTC_Mode:
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
			 }
			 break;
			 case TIMER_u8Fast_PWM_mode:
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER2_u8_WGM20);
			 SET_BIT(TIMER0_u8_TCCR0_REG,TIMER2_u8_WGM21);
			 switch(Copy_Pstr_timer->OC_mode)
			 {
				 case TIMER_u8OC_Disconnect_PWM_Mode:
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 case TIMER_u8OC_Clear_PWM_Mode:
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 case TIMER_u8OC_Set_PWM_Mode:
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
			 }
			 break;
			 case TIMER_u8Phase_PWM_mode:
			 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM20);
			 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_WGM21);
			 switch(Copy_Pstr_timer->OC_mode)
			 {
				 case TIMER_u8OC_Disconnect_PWM_Mode:
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 case TIMER_u8OC_Clear_PWM_Mode:
				 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 case TIMER_u8OC_Set_PWM_Mode:
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM20);
				 SET_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_COM21);
				 break;
				 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
			 }
			 break;
			 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
		 }
		 TIMER2_u8_TCNT2_REG=Copy_Pstr_timer->TIMER_Value;
		 TIMER2_u8_OCR2_REG =Copy_Pstr_timer->Compare_Value;
		 switch(Copy_Pstr_timer->overflow_interrupt)
		 {
			 case TIMER_u8_Ovf_Interrupt_Disable:
			 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER2_u8_TOIE2);
			 break;
			 case TIMER_u8_Ovf_Interrupt_Enable:
			 SET_BIT(TIMER_u8_TIMSK_REG,TIMER2_u8_TOIE2);
			 break;
			 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
		 }
		 switch(Copy_Pstr_timer->ctc_interrupt)
		 {
			 case TIMER_u8_CTC_Interrupt_Disable:
			 CLR_BIT(TIMER_u8_TIMSK_REG,TIMER2_u8_OCIE2);
			 break;
			 case TIMER_u8_CTC_Interrupt_Enable:
			 SET_BIT(TIMER_u8_TIMSK_REG,TIMER2_u8_OCIE2);
			 break;
			 default:lacal_u8ErrorState=STD_TYPE_NOK;break;
		 }
		 local_u8_timer_clock[2]=Copy_Pstr_timer->clock;
		 local_u8_start_flag[2]=1;

	 }
	 else lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
 }



 void TIMER0_Stop(void)
 {
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01);
	 CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00);
 }

 void TIMER1_Stop(void)
 {
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS12);
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS11);
	 CLR_BIT(TIMER1_u8_TCCRB1_REG,TIMER1_u8_CS10);
 }

 void TIMER2_Stop(void)
 {
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS22);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS21);
	 CLR_BIT(TIMER2_u8_TCCR2_REG,TIMER2_u8_CS20);
 }
 u8 TIMER_u8TIMER_Write_Counter(u8 Copy_u8Counter_Index,u16 Copy_u16Counter_Value)
 {
	 u8 lacal_u8ErrorState=STD_TYPE_OK;
	 if(Copy_u8Counter_Index<=TIMER_u8_Compare2_REG)
	 {
		 switch(Copy_u8Counter_Index)
		 {
			 case TIMER_u8_Counter0_REG : TIMER0_u8_TCNT0_REG=Copy_u16Counter_Value    ;break;
			 case TIMER_u8_Compare0_REG : TIMER0_u8_OCR0_REG =Copy_u16Counter_Value    ;break;
			 case TIMER_u8_Counter1_REG : TIMER1_u16_TCNT1_REG =Copy_u16Counter_Value  ;break;
			 case TIMER_u8_CompareA0_REG: TIMER1_u16_OCR1A_REG =Copy_u16Counter_Value  ;break;
			 case TIMER_u8_CompareB0_REG: TIMER1_u16_OCR1B_REG =Copy_u16Counter_Value  ;break;
			 case TIMER_u8_Counter2_REG : TIMER2_u8_TCNT2_REG  =Copy_u16Counter_Value  ;break;
			 case TIMER_u8_Compare2_REG : TIMER2_u8_OCR2_REG   =Copy_u16Counter_Value  ;break;
			 case TIMER_u8_ICR1_REG     : TIMER1_u16_ICR1_REG  =Copy_u16Counter_Value  ;break;
			 default:break;
		 }
	 }
	 else
	 lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
 }

 u8 TIMER_u8TIMER_Reed_Counter(u8 Copy_u8Counter_Index,u16 *Copy_u16pCounter_Value)
 {
	 u8 lacal_u8ErrorState=STD_TYPE_OK;
	 if(Copy_u8Counter_Index<=TIMER_u8_Compare2_REG && Copy_u16pCounter_Value!=NULL)
	 {
		 switch(Copy_u8Counter_Index)
		 {
			 case TIMER_u8_Counter0_REG : *Copy_u16pCounter_Value=TIMER0_u8_TCNT0_REG  ;break;
			 case TIMER_u8_Compare0_REG : *Copy_u16pCounter_Value=TIMER0_u8_OCR0_REG   ;break;
			 case TIMER_u8_Counter1_REG : *Copy_u16pCounter_Value=TIMER1_u16_TCNT1_REG ;break;
			 case TIMER_u8_CompareA0_REG: *Copy_u16pCounter_Value=TIMER1_u16_OCR1A_REG ;break;
			 case TIMER_u8_CompareB0_REG: *Copy_u16pCounter_Value=TIMER1_u16_OCR1B_REG ;break;
			 case TIMER_u8_Counter2_REG : *Copy_u16pCounter_Value=TIMER2_u8_TCNT2_REG  ;break;
			 case TIMER_u8_Compare2_REG : *Copy_u16pCounter_Value=TIMER2_u8_OCR2_REG   ;break;
			 case TIMER_u8_ICR1_REG     : *Copy_u16pCounter_Value=TIMER1_u16_ICR1_REG  ;break;
			 default:break;
		 }
	 }
	 else
	 lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
 }
 u8 TIMER_u8Timer_SetCallBack(void(*Copy_pf)(void),u8 Copy_u8Timer_Index)
 {
	 u8 lacal_u8ErrorState=STD_TYPE_OK;
	 if(Copy_u8Timer_Index<=TIMER_u8Timer2_CTC && Copy_pf!=NULL)
	 {
		 TIMER_pfTimerOVF[Copy_u8Timer_Index]=Copy_pf;
	 }
	 else
	 lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
 }
 void __vector_11(void)    __attribute__((signal));
 void __vector_11(void)
 {
	 static u16 local_u16CouterOVF =0;
	 local_u16CouterOVF++;
	 if(local_u16CouterOVF == 3907){
		 TIMER0_u8_TCNT0_REG=192;
		 local_u16CouterOVF = 0;
		 if(TIMER_pfTimerOVF[TIMER_u8Timer0_Ovf]!=NULL)
		 {
			 TIMER_pfTimerOVF[TIMER_u8Timer0_Ovf]();
		 }
	 }
 }
 
 void __vector_10(void)    __attribute__((signal));
 void __vector_10(void)
 {
	 static u16 local_u16CouterOVF =0;
	 local_u16CouterOVF++;
	 if(local_u16CouterOVF == 10000){
		 local_u16CouterOVF = 0;
		 if(TIMER_pfTimerOVF[TIMER_u8Timer0_CTC]!=NULL)
		 {
			 TIMER_pfTimerOVF[TIMER_u8Timer0_CTC]();
		 }
	 }
 }
 
 void __vector_5(void)    __attribute__((signal));
 void __vector_5(void)
 {
	 static u16 local_u16CouterOVF =0;
	 local_u16CouterOVF++;
	 if(local_u16CouterOVF == 3907){
		 TIMER2_u8_TCNT2_REG=192;
		 local_u16CouterOVF = 0;
		 if(TIMER_pfTimerOVF[TIMER_u8Timer2_Ovf]!=NULL)
		 {
			 TIMER_pfTimerOVF[TIMER_u8Timer2_Ovf]();
		 }
	 }
 }
 
 void __vector_4(void)    __attribute__((signal));
 void __vector_4(void)
 {
	 static u16 local_u16CouterOVF =0;
	 local_u16CouterOVF++;
	 if(local_u16CouterOVF == 10000){
		 local_u16CouterOVF = 0;
		 if(TIMER_pfTimerOVF[TIMER_u8Timer2_CTC]!=NULL)
		 {
			 TIMER_pfTimerOVF[TIMER_u8Timer2_CTC]();
		 }
	 }
 }
 
 void __vector_9(void)    __attribute__((signal));
 void __vector_9(void)
 {
	 static u16 local_u16CouterOVF =0;
	 local_u16CouterOVF++;
	 if(local_u16CouterOVF == 3907){
		 TIMER2_u8_TCNT2_REG=192;
		 local_u16CouterOVF = 0;
		 if(TIMER_pfTimerOVF[TIMER_u8Timer1_Ovf]!=NULL)
		 {
			 TIMER_pfTimerOVF[TIMER_u8Timer1_Ovf]();
		 }
	 }
 }
 
 
 void __vector_7(void)    __attribute__((signal));
 void __vector_7(void)
 {
	 static u16 local_u16CouterOVF =0;
	 local_u16CouterOVF++;
	 if(local_u16CouterOVF == 10000){
		 local_u16CouterOVF = 0;
		 if(TIMER_pfTimerOVF[TIMER_u8Timer1_CTCA]!=NULL)
		 {
			 TIMER_pfTimerOVF[TIMER_u8Timer1_CTCA]();
		 }
	 }
 }
 
 void __vector_8(void)    __attribute__((signal));
 void __vector_8(void)
 {
	 static u16 local_u16CouterOVF =0;
	 local_u16CouterOVF++;
	 if(local_u16CouterOVF == 10000){
		 local_u16CouterOVF = 0;
		 if(TIMER_pfTimerOVF[TIMER_u8Timer1_CTCB]!=NULL)
		 {
			 TIMER_pfTimerOVF[TIMER_u8Timer1_CTCB]();
		 }
	 }
 }
 
 void __vector_6(void)    __attribute__((signal));
 void __vector_6(void)
 {
	 if(TIMER_pfTimerOVF[TIMER_u8Timer1_CTCB]!=NULL)
	 {
		 TIMER_pfTimerOVF[TIMER_u8Timer1_Capt]();
	 }
 }
 