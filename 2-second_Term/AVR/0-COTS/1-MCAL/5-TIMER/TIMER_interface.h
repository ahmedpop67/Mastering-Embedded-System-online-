 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  1/17/2022    **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
 
 #ifndef TIMER_INTERFACE_H
 #define TIMER_INTERFACE_H

 //mode of timer 0 or 2                               
 #define TIMER_u8Normal_mode                   0
 #define TIMER_u8CTC_mode                      1
 #define TIMER_u8Fast_PWM_mode                 2
 #define TIMER_u8Phase_PWM_mode                3
 //Compare Match Output Mode
 #define TIMER_u8OC_Disconnect_CTC_Mode        0
 #define TIMER_u8OC_Toggle_CTC_Mode            1
 #define TIMER_u8OC_Clear_CTC_Mode             2
 #define TIMER_u8OC_Set_CTC_Mode               3
											   
 //Compare Output Mode, Fast PWM Mode OR Phase pwm
 #define TIMER_u8OC_Disconnect_PWM_Mode        4
 #define TIMER_u8OC_Togle_PWM_Mode             5
 #define TIMER_u8OC_Clear_PWM_Mode             6
 #define TIMER_u8OC_Set_PWM_Mode               7
											   
 //Clock Select  for timer 0 or 1              
 #define  TIMER_u8_NO_CLOCK                    0
 #define  TIMER_u8_1_Presc                     1
 #define  TIMER_u8_8_Presc                     2
 #define  TIMER_u8_64_Presc                    3
 #define  TIMER_u8_256_Presc                   4
 #define  TIMER_u8_1024_Presc                  5
 #define  TIMER_u8_Ext_Fal_Edge                6
 #define  TIMER_u8_Ext_Ris_Edge                7

//Clock Select  for timer 2
 #define  TIMER2_u8_NO_CLOCK                   0
 #define  TIMER2_u8_1_Presc                    1
 #define  TIMER2_u8_8_Presc                    2
 #define  TIMER2_u8_32_Presc                   3
 #define  TIMER2_u8_64_Presc                   4
 #define  TIMER2_u8_128_Presc                  5
 #define  TIMER2_u8_256_Presc                  6
 #define  TIMER2_u8_1024_Presc                 7
 #define  TIMER_u8_Ext_Clock                   8


 //Timer/Counter0 Overflow Interrupt Enable
 #define TIMER_u8_Ovf_Interrupt_Disable        0
 #define TIMER_u8_Ovf_Interrupt_Enable         1

 //Timer/Counter0 Output Compare Match Interrupt Enable
 #define TIMER_u8_CTC_Interrupt_Disable        2
 #define TIMER_u8_CTC_Interrupt_Enable         3
 /* for timer1*/
 #define TIMER_u8_CTCA_Interrupt_Disable       4
 #define TIMER_u8_CTCB_Interrupt_Enable        5
 #define TIMER_u8_Cpture_Interrupt_Disable     6
 #define TIMER_u8_Cpture_Interrupt_Enable      7

 struct TIMER{
 u8   mode :             3;
 u8   OC_mode:           3;
 u8   clock:             3;
 u16  TIMER_Value;       
 u16  Compare_Value;     
 u16  Compare_ValueB;    
 u8   overflow_interrupt:3;
 u8   ctc_interrupt:     3;
 };
 typedef struct TIMER TIMER_str;

 //chose timer index for set_callback
 #define TIMER_u8Timer0_Ovf                    0
 #define TIMER_u8Timer0_CTC                    1
 #define TIMER_u8Timer1_Ovf                    2
 #define TIMER_u8Timer1_CTCA                   3
 #define TIMER_u8Timer1_CTCB                   4
 #define TIMER_u8Timer1_Capt                   5
 #define TIMER_u8Timer2_Ovf                    6
 #define TIMER_u8Timer2_CTC                    7
									           
 //choose counter index                        
 #define TIMER_u8_Counter0_REG                 0
 #define TIMER_u8_Compare0_REG                 1
 #define TIMER_u8_Counter1_REG                 2
 #define TIMER_u8_CompareA0_REG                3
 #define TIMER_u8_CompareB0_REG                4
 #define TIMER_u8_Counter2_REG                 5
 #define TIMER_u8_Compare2_REG                 6
 #define TIMER_u8_ICR1_REG                     7

 void TIMER_Voidinit(void);
 
 void TIMER0_Start(void);
 void TIMER1_Start(void);
 void TIMER2_Start(void);

 u8 TIMER0_Init(TIMER_str *Copy_Pstr_timer);
 u8 TIMER1_Init(TIMER_str *Copy_Pstr_timer);
 u8 TIMER2_Init(TIMER_str *Copy_Pstr_timer);

 u8 TIMER_u8TIMER_Reed_Counter(u8 Copy_u8Counter_Index,u16 *Copy_u16pCounter_Value);

 u8 TIMER_u8Timer_SetCallBack(void(*Copy_pf)(void),u8 Copy_u8Timer_Index);

 u8 TIMER_u8TIMER_Write_Counter(u8 Copy_u8Counter_Index,u16 Copy_u16Counter_Value);

 void TIMER0_Stop(void);
 void TIMER1_Stop(void);
 void TIMER2_Stop(void);


 #endif