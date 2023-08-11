 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  1/17/2022    **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
 
 #ifndef TIMER_PRIVATE_H
 #define TIMER_PRIVATE_H
 
 #define TIMER0_u8_TCCR0_REG 		         *(( volatile u8 *)0x53)
 #define TIMER0_u8_TCNT0_REG 		         *(( volatile u8 *)0x52)
 #define TIMER0_u8_OCR0_REG		             *(( volatile u8 *)0x5C)
 #define TIMER_u8_TIMSK_REG 		         *(( volatile u8 *)0x59)
 #define TIMER_u8_TIFR_REG		             *(( volatile u8 *)0x58)

 #define TIMER1_u8_TCCRA1_REG	             *(( volatile u8 *)0x4F)
 #define TIMER1_u8_TCCRB1_REG	             *(( volatile u8 *)0x4E)
 #define TIMER1_u16_TCNT1_REG	             *(( volatile u16 *)0x4C)
 #define TIMER1_u16_OCR1A_REG	             *(( volatile u16 *)0x4A)
 #define TIMER1_u16_OCR1B_REG	             *(( volatile u16 *)0x48)
 #define TIMER1_u16_ICR1_REG	             *(( volatile u16 *)0x46)

 #define TIMER2_u8_TCCR2_REG 		         *(( volatile u8 *)0x45)
 #define TIMER2_u8_TCNT2_REG 		         *(( volatile u8 *)0x44)
 #define TIMER2_u8_OCR2_REG		             *(( volatile u8 *)0x43)
 #define TIMER2_u8_ASSR_REG		             *(( volatile u8 *)0x42)
 
 //TCCR0 REGISTER BITS
 #define TIMER0_u8_CS00                       0
 #define TIMER0_u8_CS01                       1
 #define TIMER0_u8_CS02                       2
 #define TIMER0_u8_WGM01                      3
 #define TIMER0_u8_COM00                      4
 #define TIMER0_u8_COM01                      5
 #define TIMER0_u8_WGM00                      6
 #define TIMER0_u8_FOC0                       7
 
 //TIMSK REGISTER BITS
 #define TIMER0_u8_TOIE0                      0
 #define TIMER0_u8_OCIE0                      1
 #define TIMER1_u8_TOIE1                      2
 #define TIMER1_u8_OCIE1B                     3
 #define TIMER1_u8_OCIE1A                     4
 #define TIMER1_u8_TICIE1                     5
 #define TIMER2_u8_TOIE2                      6
 #define TIMER2_u8_OCIE2                      7
 
 //TIFR REGISTER BITS
 #define TIMER0_u8_TOV0                       0
 #define TIMER0_u8_OCF0                       1
 #define TIMER1_u8_TOV1                       2
 #define TIMER1_u8_OCF1B                      3
 #define TIMER1_u8_OCF1A                      4
 #define TIMER1_u8_ICF1                       5
 #define TIMER2_u8_TOV2                       6
 #define TIMER2_u8_OCF2                       7

 //TCCR1A REGISTER BITS
 #define TIMER1_u8_WGM10                      0
 #define TIMER1_u8_WGM11                      1
 #define TIMER1_u8_FOC1B                      2
 #define TIMER1_u8_FOC1A                      3
 #define TIMER1_u8_COM1B0                     4
 #define TIMER1_u8_COM1B1                     5
 #define TIMER1_u8_COM1A0                     6
 #define TIMER1_u8_COM1A1                     7

 //TCCR1B REGISTER BITS
 #define TIMER1_u8_CS10                       0
 #define TIMER1_u8_CS11                       1
 #define TIMER1_u8_CS12                       2
 #define TIMER1_u8_WGM12                      3
 #define TIMER1_u8_WGM13                      4
 #define TIMER1_u8_ICES1                      6
 #define TIMER1_u8_ICNC1                      7

 //ASSR REGISTER BITS
 #define TIMER2_u8_TCR2UB                     0
 #define TIMER2_u8_OCR2UB                     1
 #define TIMER2_u8_TCN2UB                     2
 #define TIMER2_u8_AS2                        3

 //TCCR2 REGISTER BITS
 #define TIMER2_u8_CS20                       0
 #define TIMER2_u8_CS21                       1
 #define TIMER2_u8_CS22                       2
 #define TIMER2_u8_WGM21                      3
 #define TIMER2_u8_COM20                      4
 #define TIMER2_u8_COM21                      5
 #define TIMER2_u8_WGM20                      6
 #define TIMER2_u8_FOC2                       7

 //////////////////////////////////////////////
 //////////////////<TIMER0>////////////////////
 //////////////////////////////////////////////

 //Clock Select TIMER0
 #define  TIMER0_u8_NO_CLOCK                  0
 #define  TIMER0_u8_1_Prescaler               1
 #define  TIMER0_u8_8_Prescaler               2
 #define  TIMER0_u8_64_Prescaler              3
 #define  TIMER0_u8_256_Prescaler             4
 #define  TIMER0_u8_1024_Prescaler            5
 #define  TIMER0_u8_Ext_Fal_Edge              6
 #define  TIMER0_u8_Ext_Ris_Edge              7

 //ENABLE TIMER0
 #define TIMER0_u8_DISABLE                    0
 #define TIMER0_u8_EANBLE                     1

 //Timer/Counter0 Overflow Interrupt Enable
 #define TIMER0_u8_Ovf_Interrupt_Disable      0
 #define TIMER0_u8_Ovf_Interrupt_Enable       1

 //Timer/Counter0 Output Compare Match Interrupt Enable
 #define TIMER0_u8_CTC_Interrupt_Disable      0
 #define TIMER0_u8_CTC_Interrupt_Enable       1
 
 //mode OF TIMER0
 #define TIMER0_u8Normal_mode                 0
 #define TIMER0_u8CTC_mode                    1
 #define TIMER0_u8Fast_PWM_mode               2
 #define TIMER0_u8Phase_PWM_mode              3
 
 //Compare Match Output Mode OF TIMER0
 #define TIMER0_u8OC0_Disconnect_CTC_Mode     0
 #define TIMER0_u8OC0_Toggle_CTC_Mode         1
 #define TIMER0_u8OC0_Clear_CTC_Mode          2
 #define TIMER0_u8OC0_Set_CTC_Mode            3
 
 //Compare Output Mode, Fast PWM Mode OF TIMER0
 #define TIMER0_u8OC0_Disconnect_PWM_Mode     4
 #define TIMER0_u8OC0_Clear_PWM_Mode          5
 #define TIMER0_u8OC0_Set_PWM_Mode            6

 //////////////////////////////////////////////
 //////////////////<TIMER1>////////////////////
 //////////////////////////////////////////////

 //ENABLE TIMER0
 #define TIMER1_u8_DISABLE                    0
 #define TIMER1_u8_EANBLE                     1

 // Clock Select
 #define TIMER1_u8_NO_CLOCK			          0
 #define TIMER1_u8_1_Prescaler			      1
 #define TIMER1_u8_8_Prescaler			      2
 #define TIMER1_u8_64_Prescaler			      3
 #define TIMER1_u8_256_Prescaler			  4
 #define TIMER1_u8_1024_Prescaler             5
 #define TIMER1_u8_Ext_Fal_Edge               6
 #define TIMER1_u8_Ext_Ris_Edge               7

 //Timer/Counter1 Overflow Interrupt Enable
 #define TIMER0_u8_Ovf_Interrupt_Disable      0
 #define TIMER0_u8_Ovf_Interrupt_Enable       1

 //Timer/Counter1 Output Compare Match Interrupt Enable
 #define TIMER1_u8_CTCA_Interrupt_Disable     0
 #define TIMER1_u8_CTCA_Interrupt_Enable      1
 #define TIMER1_u8_CTCB_Interrupt_Disable     2
 #define TIMER1_u8_CTCB_Interrupt_Enable      3

 //mode OF TIMER1
 #define TIMER1_u8Normal_mode                 0
 #define TIMER1_u8CTC_mode                    1
 #define TIMER1_u8Fast_PWM_8_bi_mode          2
 #define TIMER1_u8Fast_PWM_9_bit_mode         3
 #define TIMER1_u8Fast_PWM_10_bit_mode        4
 #define TIMER1_u8PhaseC_PWM_8_bit_mode       5
 #define TIMER1_u8PhaseC_PWM_9_bit_mode       6
 #define TIMER1_u8PhaseC_PWM_10_bit_mode      7
 #define TIMER1_u8_Phase_Freq_PWM_ICR1_mode   8
 #define TIMER1_u8_Phase_Freq_PWM_OCR1A_mode  9
 #define TIMER1_u8_PhaseC_PWM_ICR1_mode       10
 #define TIMER1_u8_PhaseC_PWM_OCR1A_mode      11
 #define TIMER1_u8_CTC_ICR1_mode              12
 #define TIMER1_u8_Fast_PWM_ICR1_mode         13
 #define TIMER1_u8_Fast_PWM_OCR1A_mode        14

 //Compare Match Output Mode CH A OF TIMER1
 #define TIMER1_u8OC1A_Disconnect_CTC_Mode    0
 #define TIMER1_u8OC1_Toggle_CTC_Mode         1
 #define TIMER1_u8OC1A_Clear_CTC_Mode         2
 #define TIMER1_u8OC1A_Set_CTC_Mode           3
 #define TIMER1_u8OC1B_Disconnect_CTC_Mode    4
 #define TIMER1_u8OC1B_Clear_CTC_Mode         5
 #define TIMER1_u8OC1B_Set_CTC_Mode           6


 #define TIMER1_u8OC1A_Disconnect_PWM_Mode    0
 #define TIMER1_u8OC1A_Togle_PWM_Mode     	  1
 #define TIMER1_u8OC1A_Clear_PWM_Mode         2
 #define TIMER1_u8OC1A_Set_PWM_Mode           3
 #define TIMER1_u8OC1B_Disconnect_PWM_Mode    4
 #define TIMER1_u8OC1B_Togle_PWM_Mode         5
 #define TIMER1_u8OC1B_Clear_PWM_Mode         6
 #define TIMER1_u8OC1B_Set_PWM_Mode           7

 #define TIMER1_u8_Ovf_Interrupt_Disable      0
 #define TIMER1_u8_Ovf_Interrupt_Enable       1
 #define TIMER1_u8_CTCA_Interrupt_Disable     2
 #define TIMER1_u8_CTCA_Interrupt_Enable      3
 #define TIMER1_u8_CTCB_Interrupt_Disable     4
 #define TIMER1_u8_CTCB_Interrupt_Enable      5



 
 //input capture noise enable
 #define TIMER1_u8_InCap_NOISE_Canc_Disable   0
 #define TIMER1_u8_InCap_NOISE_Canc_Enable    1

 //Input Capture Edge Select
 #define TIMER1_u8_InCap_Falling_Edge         0
 #define TIMER1_u8_InCap_Raising_Edge         1

 //Input Capture Interrupt Enable
 #define TIMER1_u8_ICI_Interrupt_Disable      0
 #define TIMER1_u8_ICI_Interrupt_Enable       1

 //////////////////////////////////////////////
 //////////////////<TIMER2>////////////////////
 //////////////////////////////////////////////

 //Clock Select TIMER2
 #define  TIMER2_u8_NO_CLOCK                 0
 #define  TIMER2_u8_1_Prescaler              1
 #define  TIMER2_u8_8_Prescaler              2
 #define  TIMER2_u8_32_Prescaler             3
 #define  TIMER2_u8_64_Prescaler             4
 #define  TIMER2_u8_128_Prescaler            5
 #define  TIMER2_u8_256_Prescaler            6
 #define  TIMER2_u8_1024_Prescaler           7
 #define  TIMER2_u8_Ext                      8
 
 //ENABLE TIMER2
 #define TIMER2_u8_DISABLE                    0
 #define TIMER2_u8_EANBLE                     1

 //Timer/Counter2 Overflow Interrupt Enable
 #define TIMER2_u8_Ovf_Interrupt_Disable      0
 #define TIMER2_u8_Ovf_Interrupt_Enable       1

 //Timer/Counter2 Output Compare Match Interrupt Enable
 #define TIMER2_u8_CTC_Interrupt_Disable      0
 #define TIMER2_u8_CTC_Interrupt_Enable       1
 
 //mode OF TIMER2
 #define TIMER2_u8Normal_mode                 0
 #define TIMER2_u8CTC_mode                    1
 #define TIMER2_u8Fast_PWM_mode               2
 #define TIMER2_u8Phase_PWM_mode              3
 
 //Compare Match Output Mode OF TIMER2
 #define TIMER2_u8OC2_Disconnect_CTC_Mode     0
 #define TIMER2_u8OC2_Toggle_CTC_Mode         1
 #define TIMER2_u8OC2_Clear_CTC_Mode          2
 #define TIMER2_u8OC2_Set_CTC_Mode            3
 
 //Compare Output Mode, Fast PWM Mode OF TIMER2
 #define TIMER2_u8OC2_Disconnect_PWM_Mode     4
 #define TIMER2_u8OC2_Clear_PWM_Mode          5
 #define TIMER2_u8OC2_Set_PWM_Mode            6



 #endif