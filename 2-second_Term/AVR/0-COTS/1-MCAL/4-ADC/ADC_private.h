 /*************************  VERSION :  1.0          **************************/
 /***************************  DATE  :  1/7/2023     **************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /*****************************************************************************/
 /*****************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADC_u8_ADMUX_REG       *(volatile u8*)0x27)
#define ADC_u8_ADCSRA_REG      *(volatile u8*)0x26)
#define ADC_u8_SFIOR_REG       *(volatile u8*)0x50)

#define ADC_u8_ADCL_REG        *(volatile u8*)0x24)
#define ADC_u8_ADCH_REG        *(volatile u8*)0x25)
#define ADC_u16_ADC_REG        *(volatile u16*)0x24)

#define ADC_u8_Reference_AREF       0
#define ADC_u8_Reference_AVCC       1
#define ADC_u8_Reference_Internal   2

#define ADC_u8_Left                 0
#define ADC_u8_Right                1

#define ADC_u8_REFS1                7
#define ADC_u8_REFS0                6
#define ADC_u8_ADLAR                5
#define ADC_u8_ADEN                 7
#define ADC_u8_ADSC                 6
#define ADC_u8_ADATE                5
#define ADC_u8_ADIF                 4
#define ADC_u8_ADIE                 3
#define ADC_u8_ADPS2                2
#define ADC_u8_ADPS1                1
#define ADC_u8_ADPS0                0
#define ADC_u8_ADTS2                7
#define ADC_u8_ADTS0                6
#define ADC_u8_ADTS0                5


#endif
