/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Hassan
 * @brief          : Toggle a led
 ******************************************************************************
 */
#include "STD_TYPES.H"
#include "BIT_MATH.h"

#define RCC_BASE    0x40021000
#define GPIOA_BASE  0X40010800

#define RCC_ARP2ENR *(vuint32 *)(RCC_BASE + 0X18)
#define GPIOA_CRH   *(vuint32 *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR   *(vuint32 *)(GPIOA_BASE + 0x0c)


typedef union
{
	vsint32 all_fields;
	struct
	{
		vsint32 reserved :13;
		vsint32 pin_13 	 :1;
	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);


int main(void)
{
	SET_BIT(RCC_ARP2ENR,2);
    GPIOA_CRH &= 0xff0fffff;  //MODE PIN13 = 2
	GPIOA_CRH |= 0x00200000;
    /* Loop forever */
    while(1){
    	SET_BIT(GPIOA_ODR,13);
    //	R_ODR->Pin.pin_13 = 1;
    	for(uint32 i=0;i<50000;i++);
    // 	R_ODR->Pin.pin_13 = 0;
    	CLR_BIT(GPIOA_ODR,13);
    	for(uint32 i=0;i<50000;i++);
    }
}
