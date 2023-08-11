/*****************************************************************************/
/***************************  NAME  :  ahmed hassan **************************/
/***************************  DATE  :  3/30/2022   **************************/
/*************************  VERSION :  1.0          **************************/
/*****************************************************************************/

#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

typedef enum
{
	TWI_OK=1,
	TWI_SC_Error,
	TWI_RSC_Error,
	TWI_SLA_W_Error,
	TWI_SLA_R_Error,
	TWI_SD_Error,
	TWI_RD_Error,
}TWI_ErrorState;

void           TWI_u8MaterInit(void);

TWI_ErrorState TWI_u8SlaveInit(u8 copy_u8Address);

TWI_ErrorState TWI_u8SendStartCondition(void);

TWI_ErrorState TWI_u8SendReStartCondition(void);

TWI_ErrorState TWI_u8SendReStopCondition(void);

TWI_ErrorState TWI_u8SendSlaveAddWrite(u8 copy_u8Address);

TWI_ErrorState TWI_u8SendSlaveAddReed(u8 copy_u8Address);

TWI_ErrorState TWI_u8SendDataByte(u8 copy_u8DataByte);

TWI_ErrorState TWI_u8ReciveDataByte(u8 *copy_pu8ReturnDataByte);



#endif