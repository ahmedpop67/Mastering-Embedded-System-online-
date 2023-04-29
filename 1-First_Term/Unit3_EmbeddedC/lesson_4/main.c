 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  28/4/2023   ***************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
 
 //project :"toggle led in pin 13 portf"
 
#include "STD_TYPES.H"
#include "BIT_MATH.h"

#define SYSTL_RCGC2_R       (*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTF_DATA_R   (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R    (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R    (*((volatile unsigned long *)0x4002551C))



int main(void)
{
	SYSTL_RCGC2_R = 0X00000020;
	for (vuint32 i=0; i<200;i++);
	
	SET_BIT(GPIO_PORTF_DIR_R,3);
	SET_BIT(GPIO_PORTF_DEN_R,3);

    /* Loop forever */
    while(1){
        SET_BIT(GPIO_PORTF_DATA_R,3);
    	for(vuint32 i=0;i<50000;i++);
		
        CLR_BIT(GPIO_PORTF_DATA_R,3);
    	for(vuint32 i=0;i<50000;i++);
    }
}

 
 