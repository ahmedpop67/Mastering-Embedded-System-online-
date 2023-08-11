 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  3/30/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

//SPCR SPSR SPDR

#define SPI_u8_SPCR_REG                      *((volatile u8 *)0x2D)
#define SPI_u8_SPSR_REG                      *((volatile u8 *)0x2E)
#define SPI_u8_SPDR_REG                      *((volatile u8 *)0x2F)

//SPCR_REG BITS
#define SPI_u8_SPR0_BIT                      0
#define SPI_u8_SPR1_BIT                      1
#define SPI_u8_CPHA_BIT                      2
#define SPI_u8_CPOL_BIT                      3
#define SPI_u8_MSTR_BIT                      4
#define SPI_u8_DORD_BIT                      5
#define SPI_u8_SPE_BIT                       6
#define SPI_u8_SPIE_BIT                      7

//SPSR_REG BITS
#define SPI_u8_SPI2X_BIT                     0
#define SPI_u8_WCOL_BIT                      6
#define SPI_u8_SPIF_BIT                      7

//SPI ENABLE 
#define SPI_u8_DISBLE                        0
#define SPI_u8_ENABLE                        1


// MODE OF  SPI
#define SPI_u8_Master_Mode                   0
#define SPI_u8_Slave_Mode                    1

//clock plarity AND PHASE
#define SPI_u8_Sample_Rising_Loading_Edge    0
#define SPI_u8_Sample_Falling_Loading_Edge   1
#define SPI_u8_Setup_Rising_Loading_Edge     2
#define SPI_u8_Setup_Falling_Loading_Edge    3


//clock rate 
#define SPI_u8_Clock_Div_4                   0
#define SPI_u8_Clock_Div_16                  1
#define SPI_u8_Clock1_Div_64                 2
#define SPI_u8_Clock_Div_128                 3
#define SPI_u8_Clock_Div_2                   4
#define SPI_u8_Clock_Div_8                   5
#define SPI_u8_Clock_Div_32                  6
#define SPI_u8_Clock2_Div_64                 7

//SPI INTERUPT STATE
#define SPI_u8_SPI_Interupt_Disable          0
#define SPI_u8_SPI_Interupt_Enable           1

#endif