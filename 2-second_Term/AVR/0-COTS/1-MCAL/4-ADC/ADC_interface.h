 /*****************************************************************************/
 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  1/7/2023     **************************/
 /*************************  VERSION :  1.0          **************************/
														
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

// Copy_u8channelNb (Signal channel)
#define ADC_u8_Single_Channel_ADC0                  0
#define ADC_u8_Single_Channel_ADC1                  1
#define ADC_u8_Single_Channel_ADC2                  3
#define ADC_u8_Single_Channel_ADC3                  3
#define ADC_u8_Single_Channel_ADC4                  4
#define ADC_u8_Single_Channel_ADC5                  5
#define ADC_u8_Single_Channel_ADC6                  6
#define ADC_u8_Single_Channel_ADC7                  7

//double channel
#define ADC_u8_Double_Channel_ADC0_ADC0_10x         8
#define ADC_u8_Double_Channel_ADC1_ADC0_10x         9
#define ADC_u8_Double_Channel_ADC0_ADC0_200x        10
#define ADC_u8_Double_Channel_ADC1_ADC0_200x        11
#define ADC_u8_Double_Channel_ADC2_ADC2_10x         12
#define ADC_u8_Double_Channel_ADC3_ADC2_10x         13
#define ADC_u8_Double_Channel_ADC2_ADC2_200x        14
#define ADC_u8_Double_Channel_ADC3_ADC2_200x        15
#define ADC_u8_Double_Channel_ADC0_ADC1_1x          16
#define ADC_u8_Double_Channel_ADC1_ADC1_1x          17
#define ADC_u8_Double_Channel_ADC2_ADC1_1x          18
#define ADC_u8_Double_Channel_ADC3_ADC1_1x          19
#define ADC_u8_Double_Channel_ADC4_ADC1_1x          20
#define ADC_u8_Double_Channel_ADC5_ADC1_1x          21
#define ADC_u8_Double_Channel_ADC6_ADC1_1x          22
#define ADC_u8_Double_Channel_ADC7_ADC1_1x          23
#define ADC_u8_Double_Channel_ADC0_ADC2_1x          24
#define ADC_u8_Double_Channel_ADC1_ADC2_1x          25
#define ADC_u8_Double_Channel_ADC2_ADC2_1x          26
#define ADC_u8_Double_Channel_ADC3_ADC2_1x          27
#define ADC_u8_Double_Channel_ADC4_ADC2_1x          28
#define ADC_u8_Double_Channel_ADC5_ADC2_1x          29

//TEST channel									     
#define ADC_u8_Test_VBG                             30
#define ADC_u8_Test_GROUND                          31



void ADC_voidInit(void);

u8 ADC_u8GetDgitalValue(u8 Copy_u8channelNb,u16 *copy_pu16DigitalValue);

#endif
