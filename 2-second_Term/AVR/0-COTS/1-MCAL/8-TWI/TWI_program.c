 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  3/30/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/

 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "TWI_interface.h"
 #include "TWI_private.h"
 #include "TWI_config.h"
 
 static u32 TWI_u8_SC_TIMEOUT=0;
 void TWI_u8MaterInit(void)
 {
	 //PRESCALER
	 #if   TWI_u8precaler==1
	 CLR_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS1);
	 CLR_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS0);
	 #elif TWI_u8precaler==4
	 CLR_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS1);
	 SET_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS0);
	 #elif TWI_u8precaler==16
	 SET_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS1);
	 CLR_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS0);
	 #elif TWI_u8precaler==64
	 SET_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS1);
	 SET_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS0);
	 #endif
	 //BIT RATE
	 TWI_u8_TWBR_REG=TWI_u8BIT_RATE;
	 //ENABLE ACK
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEA);
	 //ENABLE TWI
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEN);
 }

 TWI_ErrorState TWI_u8SlaveInit(u8 copy_u8Address)
 {
	 TWI_ErrorState lacal_enumErrorState = TWI_OK;
	 //SET SLAVE ADDRESS
	 TWI_u8_TWAR_REG=copy_u8Address << 1;
	 //ENABLE ACK
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEA);
	 //ENABLE TWI
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEN);
	 return lacal_enumErrorState;
 }


 TWI_ErrorState TWI_u8SendStartCondition(void)
 {
	 TWI_ErrorState lacal_enumErrorState = TWI_OK;
	 //CLEAR INTERRUPT FLAG
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT);
	 //TWI START Condition
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWSTA);
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEN);
	 //WAIT FOR FLAG TO BE HIGH
	 while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT)/*&& TWI_u8_SC_TIMEOUT<=TWI_u8_START_CONDITION_TIMEOUT*/);
	 if(TWI_u8_SC_TIMEOUT<TWI_u8_START_CONDITION_TIMEOUT) //check time out
	 {
		 //CHECK THE STATUS CODE
		 if (TWI_u8_TWSR_REG && 0xF8!=0x08)
		 {
			 lacal_enumErrorState=TWI_SC_Error;
		 }
	 }
	 //clear start condition
	 //CLR_BIT(TWI_u8_TWCR_REG,TWI_u8_TWSTA);
	 return lacal_enumErrorState;
 }

 TWI_ErrorState TWI_u8SendReStartCondition(void)
 {
	 TWI_u8_SC_TIMEOUT=0;
	 TWI_ErrorState lacal_enumErrorState = TWI_OK;
	 //CLEAR INTERRUPT FLAG
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT);
	 //TWI START Condition
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWSTA);
	 //WAIT FOR FLAG TO BE HIGH
	 while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT)/*&& TWI_u8_SC_TIMEOUT<=TWI_u8_START_CONDITION_TIMEOUT*/);
	 if(TWI_u8_SC_TIMEOUT<TWI_u8_START_CONDITION_TIMEOUT) //check time out
	 {
		 //CHECK THE STATUS CODE
		 if (TWI_u8_TWSR_REG && 0xF8!=0x10)
		 {
			 lacal_enumErrorState=TWI_RSC_Error;
		 }
	 }
	 //clear start condition
	 CLR_BIT(TWI_u8_TWCR_REG,TWI_u8_TWSTA);
	 return lacal_enumErrorState;
 }

 TWI_ErrorState TWI_u8SendStopCondition(void)
 {
	 TWI_ErrorState lacal_enumErrorState = TWI_OK;
	 //CLEAR INTERRUPT FLAG
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT);
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEN);
	 //TWI STOP Condition
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWSTO);
	 return lacal_enumErrorState;
 }

 TWI_ErrorState TWI_u8SendSlaveAddWrite(u8 copy_u8Address)
 {
	 TWI_ErrorState lacal_enumErrorState = TWI_OK;
	 TWI_u8_SC_TIMEOUT=0;
	 TWI_u8_TWDR_REG=copy_u8Address<<1;
	 CLR_BIT(TWI_u8_TWDR_REG,0);
	 //CLEAR INTERRUPT FLAG
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT);
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEN);
	 while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT)/*&& TWI_u8_SC_TIMEOUT<=TWI_u8_START_CONDITION_TIMEOUT*/);
		 if (TWI_u8_TWSR_REG&&0xF8!=0x18)
		 {
			 lacal_enumErrorState=TWI_SLA_W_Error;
		 }

	 return lacal_enumErrorState;
 }

 TWI_ErrorState TWI_u8SendSlaveAddReed(u8 copy_u8Address)
 {
	 TWI_ErrorState lacal_enumErrorState = TWI_OK;
	 TWI_u8_SC_TIMEOUT=0;
	 TWI_u8_TWDR_REG=copy_u8Address<<1;
	 SET_BIT(TWI_u8_TWDR_REG,0);
	 //CLEAR INTERRUPT FLAG
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT);
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEN);
	 while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT)/*&& TWI_u8_SC_TIMEOUT<=TWI_u8_START_CONDITION_TIMEOUT*/);
		 if (TWI_u8_TWSR_REG&&0xF8!=0x40)
		 {
			 lacal_enumErrorState=TWI_SLA_R_Error;
		 }
	 return lacal_enumErrorState;
 }

 TWI_ErrorState TWI_u8SendDataByte(u8 copy_u8DataByte)
 {
	 TWI_ErrorState lacal_enumErrorState = TWI_OK;
	 TWI_u8_SC_TIMEOUT=0;
	 TWI_u8_TWDR_REG=copy_u8DataByte;
	 //CLEAR INTERRUPT FLAG
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT);
	 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEN);
	 while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT)/*&& TWI_u8_SC_TIMEOUT<=TWI_u8_START_CONDITION_TIMEOUT*/);
		 if (TWI_u8_TWSR_REG&&0xF8!=0x28)
		 {
			 lacal_enumErrorState=TWI_SD_Error;
		 }
	 return lacal_enumErrorState;
 }

 TWI_ErrorState TWI_u8ReciveDataByte(u8 *copy_pu8ReturnDataByte)
 {
	 TWI_ErrorState lacal_enumErrorState = TWI_OK;
	 TWI_u8_SC_TIMEOUT=0;
	 if(copy_pu8ReturnDataByte!=NULL)
	 {
		 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT);
		 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEA);
		 SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEN);
		 while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT)/*&& TWI_u8_SC_TIMEOUT<=TWI_u8_START_CONDITION_TIMEOUT*/);
			 if ((TWI_u8_TWSR_REG && 0xF8)!=0x50)
			 {
				 lacal_enumErrorState=TWI_RD_Error;
			 }
			 {
				 *copy_pu8ReturnDataByte=TWI_u8_TWDR_REG;
			 }
	 }
	 else lacal_enumErrorState=TWI_RD_Error;
	 return lacal_enumErrorState;
 }
u8 TWI_GetStatus(void)
{
  u8 status;
  status = TWI_u8_TWSR_REG & 0xF8;
  return status;
}
 