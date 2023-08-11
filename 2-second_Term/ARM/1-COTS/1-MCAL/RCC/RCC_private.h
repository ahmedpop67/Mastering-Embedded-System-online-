 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  8/30/2023    **************************/
 /***************************  VERSION :  1.0        **************************/
 /*****************************************************************************/
														
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register definitions */

#define RCC_BASE                 0x40021000
#define RCC_CR                   *((volatile uint32*) (RCC+0x00))
#define RCC_CFGR                 *((volatile uint32*) (RCC+0x04))
#define RCC_CIR                  *((volatile uint32*) (RCC+0x08))
#define RCC_APB2RSTR             *((volatile uint32*) (RCC+0x0c))
#define RCC_APB1RSTR             *((volatile uint32*) (RCC+0x010))
#define RCC_AHBENR               *((volatile uint32*) (RCC+0x14))
#define RCC_APB2ENR              *((volatile uint32*) (RCC+0x18))
#define RCC_APB1ENR              *((volatile uint32*) (RCC+0x1c))
#define RCC_BDCR                 *((volatile uint32*) (RCC+0x20))
#define RCC_CSR                  *((volatile uint32*) (RCC+0x24))
						        
						        
						        
//RCC_CLOCK_TYPES               
#define RCC_HSE_CRYSTAL          0
#define RCC_HSE_RC               1
#define RCC_HSI#endif            2
#define RCC_PLL                  3


//RCC_PLL_CLOCK_TYPE
#define RCC_PLL_IN_HSI_DIV_2     0
#define RCC_PLL_IN_HSE_DIV_2     1
#define RCC_PLL_IN_HSE           2


//RCC_PLL_MUL
#define RCC_PLL_IN_MUL_2         0
#define RCC_PLL_IN_MUL_3         1
#define RCC_PLL_IN_MUL_4         2
#define RCC_PLL_IN_MUL_5         3
#define RCC_PLL_IN_MUL_6         4
#define RCC_PLL_IN_MUL_7         5
#define RCC_PLL_IN_MUL_8         6
#define RCC_PLL_IN_MUL_9         7
#define RCC_PLL_IN_MUL_10        8
#define RCC_PLL_IN_MUL_11        9
#define RCC_PLL_IN_MUL_12        10
#define RCC_PLL_IN_MUL_13        11
#define RCC_PLL_IN_MUL_14        12
#define RCC_PLL_IN_MUL_15        13
#define RCC_PLL_IN_MUL_16        14

//AHP prescaler 
#define RCC_AHP_DIV_1            0
#define RCC_AHP_DIV_2            1
#define RCC_AHP_DIV_4            2
#define RCC_AHP_DIV_8            3
#define RCC_AHP_DIV_16           4
#define RCC_AHP_DIV_64           5
#define RCC_AHP_DIV_128          6
#define RCC_AHP_DIV_256          7
#define RCC_AHP_DIV_512          8



//APB1 prescaler  
#define RCC_APB1_DIV_1           0
#define RCC_APB1_DIV_2           1
#define RCC_APB1_DIV_4           2
#define RCC_APB1_DIV_8           3
#define RCC_APB1_DIV_16          4



#define RCC_APB2_DIV_1           0
#define RCC_APB2_DIV_2           1
#define RCC_APB2_DIV_4           2
#define RCC_APB2_DIV_8           3
#define RCC_APB2_DIV_16          4
		 
		 
#endif 