 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  1/17/2022    **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
 
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////<TIMER0>////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

/*ENABLE TIMER0
1-     TIMER0_u8_DISABLE
2-     TIMER0_u8_EANBLE
*/

#define TIMER0_u8_ENA_DIS                    TIMER0_u8_DISABLE           

/*Clock Select
1-     TIMER0_u8_NO_CLOCK
2_     TIMER0_u8_1_Prescaler
3_     TIMER0_u8_8_Prescaler
4_     TIMER0_u8_64_Prescaler
5_     TIMER0_u8_256_Prescaler
6_     TIMER0_u8_1024_Prescaler
6_     TIMER0_u8_Ext_Fal_Edge   ---->External clock source on T0 pin. Clock on falling edge
7_     TIMER0_u8_Ext_Ris_Edge   ---->External clock source on T0 pin. Clock on rising edge
*/
#define TIMER0_u8_Clock                      TIMER0_u8_8_Prescaler

/*Choose generation timers mode
1-     TIMER0_u8Normal_mode
2-     TIMER0_u8CTC_mode
3-     TIMER0_u8Fast_PWM_mode
4-     TIMER0_u8Phase_PWM_mode
*/
#define TIMER0_u8Mode                        TIMER0_u8Normal_mode

#define TIMER0_u8Counter_Write               192

#define TIMER0_u8Compere_Write               0

/*Timer/Counter0 Ovf Interrupt Enable
1-    TIMER0_u8_Ovf_Interrupt_Disable
2-    TIMER0_u8_Ovf_Interrupt_Enable 
*/
#define TIMER0_u8_Ovf_Interrupt_State        TIMER0_u8_Ovf_Interrupt_Disable


/*Timer/Counter0 Output Compare Match Interrupt Enable
1-    TIMER0_u8_CTC_Interrupt_Disable
2-    TIMER0_u8_CTC_Interrupt_Enable 
*/
#define TIMER0_u8_CTC_Interrupt_State        TIMER0_u8_CTC_Interrupt_Disable


/*2-Compare Match Output Mode
1-     TIMER0_u8OC0_Disconnect_CTC_Mode
2-     TIMER0_u8OC0_Toggle_CTC_Mode
3-     TIMER0_u8OC0_Clear_CTC_Mode
4-     TIMER0_u8OC0_Set_CTC_Mode
*/
#define TIMER0_u8OC0_CTC_Mode                TIMER0_u8OC0_Disconnect_CTC_Mode

/*Compare Output Mode, Fast PWM Mode
1-     TIMER0_u8OC0_Disconnect_PWM_Mode
2-     TIMER0_u8OC0_Clear_PWM_Mode   ---->Clear OC0 on compare match, set OC0 at TOP
3-     TIMER0_u8OC0_Set_PWM_Mode     ---->Set OC0 on compare match, clear OC0 at TOP
*/
#define TIMER0_u8OC0_PWM_Mode                TIMER0_u8OC0_Set_PWM_Mode



///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////<TIMER1>////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//Configuration of timer1

/*ENABLE TIMER0
1-     TIMER1_u8_DISABLE
2-     TIMER1_u8_EANBLE
*/

#define TIMER1_u8_ENA_DIS                   TIMER1_u8_DISABLE 

/*Clock Select
1-     TIMER1_u8_NO_CLOCK
2_     TIMER1_u8_1_Prescaler
3_     TIMER1_u8_8_Prescaler
4_     TIMER1_u8_64_Prescaler
5_     TIMER1_u8_256_Prescaler
6_     TIMER1_u8_1024_Prescaler
6_     TIMER1_u8_Ext_Fal_Edge   ---->External clock source on T1 pin. Clock on falling edge
7_     TIMER1_u8_Ext_Ris_Edge   ---->External clock source on T1 pin. Clock on rising edge
*/

#define TIMER1_u8_Clock                      TIMER1_u8_NO_CLOCK

/*Choose generation timers mode
1-     TIMER1_u8Normal_mode
2-     TIMER1_u8PhaseC_PWM_8_bit_mode
3-     TIMER1_u8PhaseC_PWM_9_bit_mode
4-     TIMER1_u8PhaseC_PWM_10_bit_mode
5-     TIMER1_u8CTC_mode
6-     TIMER1_u8Fast_PWM_8_bi_mode
7-     TIMER1_u8Fast_PWM_9_bit_mode
8-     TIMER1_u8Fast_PWM_10_bit_mode
9-     TIMER1_u8_Phase_Freq_PWM_ICR1_mode
10-    TIMER1_u8_Phase_Freq_PWM_OCR1A_mode
11-    TIMER1_u8_PhaseC_PWM_ICR1_mode
12-    TIMER1_u8_PhaseC_PWM_OCR1A_mode
13-    TIMER1_u8_CTC_ICR1_mode
14-    TIMER1_u8_Fast_PWM_ICR1_mode
15-    TIMER1_u8_Fast_PWM_OCR1A_mode
*/

#define TIMER1_u8Mode                        TIMER1_u8Normal_mode


/*Timer/Counter0 Ovf Interrupt Enable
1-    TIMER1_u8_Ovf_Interrupt_Disable
2-    TIMER1_u8_Ovf_Interrupt_Enable 
*/
#define TIMER1_u8_Ovf_Interrupt_State        TIMER1_u8_Ovf_Interrupt_Disable


/*Timer/Counter0 Output Compare Match Interrupt Enable
1-    TIMER1_u8_CTCA_Interrupt_Disable
2-    TIMER1_u8_CTCA_Interrupt_Enable 
1-    TIMER1_u8_CTCB_Interrupt_Disable
2-    TIMER1_u8_CTCB_Interrupt_Enable 
*/
#define TIMER1_u8_CTCA_Interrupt_State        TIMER1_u8_CTCA_Interrupt_Disable
#define TIMER1_u8_CTCB_Interrupt_State        TIMER1_u8_CTCB_Interrupt_Disable


/*2-Compare Match Output Mode
1-     TIMER1_u8OC1A_Disconnect_CTC_Mode
2-     TIMER1_u8OC1A_Toggle_CTC_Mode
3-     TIMER1_u8OC1A_Clear_CTC_Mode
4-     TIMER1_u8OC1A_Set_CTC_Mode
5-     TIMER1_u8OC1B_Disconnect_CTC_Mode
6-     TIMER1_u8OC1B_Toggle_CTC_Mode
7-     TIMER1_u8OC1B_Clear_CTC_Mode
8-     TIMER1_u8OC1B_Set_CTC_Mode
*/
#define TIMER1_u8OC1A_CTC_Mode                TIMER1_u8OC1A_Disconnect_CTC_Mode
#define TIMER1_u8OC1B_CTC_Mode                TIMER1_u8OC1B_Disconnect_CTC_Mode

/*Compare Output Mode, Fast PWM Mode
1-     TIMER1_u8OC1A_Disconnect_PWM_Mode
2-     TIMER1_u8OC1_Togle_PWM_Mode        --->WGM13:0 = 15: Toggle OC1A on Compare Match,
                                               OC1B disconnected (normal port operation).
			        					       For all other WGM13:0 settings,normal port operation,OC1A/OC1B disconnected
3-     TIMER1_u8OC1A_Clear_PWM_Mode        ---->Clear OC1A on compare match, set OC1A at TOP
4-     TIMER1_u8OC1A_Set_PWM_Mode          ---->Set OC1A on compare match, clear OC1A at TOP

5-     TIMER1_u8OC1B_Disconnect_PWM_Mode                                       					 
6-     TIMER1_u8OC1B_Clear_PWM_Mode        ---->Clear OC1B on compare match, set OC1A at TOP
7-     TIMER1_u8OC1B_Set_PWM_Mode          ---->Set OC1B on compare match, clear OC1A at TOP
*/
#define TIMER1_u8OC1A_PWM_Mode               TIMER0_u8OC1A_Set_PWM_Mode
#define TIMER1_u8OC1B_PWM_Mode               TIMER0_u8OC1B_Set_PWM_Mode

#define TIMER1_u8Counter_Write               0
 
#define TIMER1_u8CompereA_Write              0     
#define TIMER1_u8CompereB_Write              0
     
#define TIMER1_u8ICR1_Write                  0     


/*INPUT CAPTURE NOISE ENABLE
1-    TIMER1_u8_InCap_NOISE_Canc_Disable
2-    TIMER1_u8_InCap_NOISE_Canc_Enable
*/
#define TIMER1_u8_InCap_NOISE_Canc          TIMER1_u8_InCap_NOISE_Canc_Disable
										    
/*Input Capture Edge Select                 
1-    TIMER1_u8_InCap_Falling_Edge          
2-    TIMER1_u8_InCap_Raising_Edge          
*/                                          
#define TIMER1_u8_InCap_Edge                TIMER1_u8_InCap_Falling_Edge
 /* Input Capture Interrupt Enable          
1-    TIMER1_u8_ICI_Interrupt_Disable       
2-    TIMER1_u8_ICI_Interrupt_Enable        
*/                                          
#define TIMER1_u8_InCap_Interrupt_State     TIMER1_u8_ICI_Interrupt_Disable 

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////<TIMER2>////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//Configuration of timer0

/*ENABLE TIMER0
1-     TIMER2_u8_DISABLE
2-     TIMER2_u8_EANBLE
*/

#define TIMER2_u8_ENA_DIS                   TIMER2_u8_EANBLE

/*Clock Select
1-     TIMER2_u8_NO_CLOCK
2_     TIMER2_u8_1_Prescaler
3_     TIMER2_u8_8_Prescaler
4_     TIMER2_u8_32_Prescaler
5_     TIMER2_u8_64_Prescaler
6_     TIMER2_u8_128_Prescaler
7_     TIMER2_u8_256_Prescaler
8_     TIMER2_u8_1024_Prescaler
9_     TIMER2_u8_Ext
*/

#define TIMER2_u8_Clock                      TIMER2_u8_8_Prescaler

/*Choose generation timers mode
1-     TIMER2_u8Normal_mode
2-     TIMER2_u8CTC_mode
3-     TIMER2_u8Fast_PWM_mode
4-     TIMER2_u8Phase_PWM_mode
*/

#define TIMER2_u8Mode                        TIMER2_u8Normal_mode

#define TIMER2_u8Counter_Write               192

#define TIMER2_u8Compere_Write               100

/*Timer/Counter2 Ovf Interrupt Enable
1-    TIMER2_u8_Ovf_Interrupt_Disable
2-    TIMER2_u8_Ovf_Interrupt_Enable 
*/
#define TIMER2_u8_Ovf_Interrupt_State        TIMER2_u8_Ovf_Interrupt_Enable


/*Timer/Counter2 Output Compare Match Interrupt Enable
1-    TIMER2_u8_CTC_Interrupt_Disable
2-    TIMER2_u8_CTC_Interrupt_Enable 
*/
#define TIMER2_u8_CTC_Interrupt_State        TIMER2_u8_CTC_Interrupt_Disable


/*2-Compare Match Output Mode
1-     TIMER2_u8OC2_Disconnect_CTC_Mode
2-     TIMER2_u8OC2_Toggle_CTC_Mode
3-     TIMER2_u8OC2_Clear_CTC_Mode
4-     TIMER2_u8OC2_Set_CTC_Mode
*/
#define TIMER2_u8OC2_CTC_Mode                TIMER2_u8OC2_Set_CTC_Mode

/*Compare Output Mode, Fast PWM Mode
1-     TIMER2_u8OC2_Disconnect_PWM_Mode
2-     TIMER2_u8OC2_Clear_PWM_Mode   ---->Clear OC2 on compare match, set OC0 at TOP
3-     TIMER2_u8OC2_Set_PWM_Mode     ---->Set OC2 on compare match, clear OC0 at TOP
*/
#define TIMER2_u8OC2_PWM_Mode                TIMER2_u8OC2_Set_PWM_Mode


#endif