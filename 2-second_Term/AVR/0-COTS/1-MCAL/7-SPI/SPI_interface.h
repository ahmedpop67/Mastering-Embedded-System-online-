 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  3/30/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
 
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void ISP_VoidInit(void);
void SPI_VoidSlaveInit(void);
void SPI_VoidMasterInit(void);


u8 ISP_u8TRA_REC_DATABIT(u8 copy_u8DataByte,u8 *copy_pu8DataString);

void ISP_u8SEND_DATABIT(u8 copy_u8DataByte);
u8 ISP_u8REC_DATABIT(u8 *copy_pu8DataString);

#endif