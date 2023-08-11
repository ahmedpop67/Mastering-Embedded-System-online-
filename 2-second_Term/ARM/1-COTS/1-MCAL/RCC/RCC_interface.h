 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  8/30/2023    **************************/
 /***************************  VERSION :  1.0        **************************/
 /*****************************************************************************/
														
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

//BUS ID//
#define RCC_AHP         0
#define RCC_APB1        1
#define RCC_APB2        2

//PORT ID IN AHP BUS//
#define DMA1            0
#define DMA2            1
#define SRAM            2
#define FLITF           4
#define CRCE            6
#define FSMC            8
#define SDIO            10

//PORT ID IN APB2 BUS//
#define AFIO            0
#define IOPA            2
#define IOPB            3
#define IOPC            4
#define IOPD            5
#define IOPE            6
#define IOPF            7
#define IOPG            8
#define ADC1            9
#define ADC2            10
#define TIM1            11
#define SPI1            12
#define TIM8            13
#define USART1          14
#define ADC3            15
#define TIM9            19
#define TIM10           20
#define TIM11           21

//PORT ID IN APB1//
#define TIM2            0
#define TIM3            1
#define TIM4            2
#define TIM5            3
#define TIM6            4
#define TIM7            5
#define TIM12           6
#define TIM13           7
#define TIM14           8
#define WWDG            11
#define SPI2            14
#define SPI3            15
#define UART2           17
#define UART3           18
#define UART4           19
#define UART5           20
#define I2C1            21
#define I2C2            22
#define USP             23
#define CAN             25
#define BKP             27
#define PWR             28
#define DAC             29

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(uint8 copy_uint8_BusId,uint8 copy_uint8_PortId);
void RCC_voidDisableClock(uint8 copy_uint8_BusId,uint8 copy_uint8_PortId);



#endif