/*****************************************************************************/
/***************************  NAME  :  ahmed hassan **************************/
/***************************  DATE  :  3/30/2022   **************************/
/*************************  VERSION :  1.0          **************************/
/*****************************************************************************/

#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H
// TWBR TWCR  TWSR  TWDR  TWAR 
#define TWI_u8_TWBR_REG                   *((volatile u8 *)0x20)
#define TWI_u8_TWCR_REG                   *((volatile u8 *)0x56)
#define TWI_u8_TWSR_REG                   *((volatile u8 *)0x21)
#define TWI_u8_TWDR_REG                   *((volatile u8 *)0x23)
#define TWI_u8_TWAR_REG                   *((volatile u8 *)0x22)
 
 
//BIT IN REG TWCR                    
#define TWI_u8_TWIE                   0
#define TWI_u8_TWEN                   2
#define TWI_u8_TWWC                   3
#define TWI_u8_TWSTO                  4
#define TWI_u8_TWSTA                  5
#define TWI_u8_TWEA                   6
#define TWI_u8_TWINT                  7

//BIT IN REG TWSR                    
#define TWI_u8_TWPS0                  0
#define TWI_u8_TWPS1                  1
#define TWI_u8_TWS3                   3
#define TWI_u8_TWS4                   4
#define TWI_u8_TWS5                   5
#define TWI_u8_TWS6                   6
#define TWI_u8_TWS7                   7

//BIT IN REG TWSR                    
#define TWI_u8_TWGCE                  0
#define TWI_u8_TWA0                   1
#define TWI_u8_TWA1                   2
#define TWI_u8_TWA2                   3
#define TWI_u8_TWA3                   4
#define TWI_u8_TWA4                   5
#define TWI_u8_TWA5                   6
#define TWI_u8_TWA6                   7



#endif