/*****************************************************************************/
/***************************  NAME  :  ahmed hassan **************************/
/***************************  DATE  :  3/30/2022   **************************/
/*************************  VERSION :  1.0          **************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
 
void ISP_VoidInit(void)
{
	#if SPI_u8_SPI_State  ==SPI_u8_DISBLE
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPE_BIT);
	#elif SPI_u8_SPI_State==SPI_u8_ENABLE
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPE_BIT);
	#endif
	#if SPI_u8_INTERUPT_STATE  ==SPI_u8_SPI_Interupt_Disable
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPIE_BIT);
	#elif SPI_u8_INTERUPT_STATE==SPI_u8_SPI_Interupt_Enable
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPIE_BIT);
	#endif
	#if SPI_u8_Data_Order  ==SPI_u8_LSB_MODE
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_DORD_BIT);
	#elif SPI_u8_Data_Order==SPI_u8_MSB_MODE
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_DORD_BIT);
	#endif
	#if SPI_u8_Select_MODE  ==SPI_u8_Master_Mode
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_MSTR_BIT);
	#elif SPI_u8_Select_MODE==SPI_u8_Slave_Mode
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_MSTR_BIT);
	#endif
	#if SPI_u8_clock_mode   ==SPI_u8_Sample_Rising_Loading_Edge
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_CPOL_BIT);
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_CPHA_BIT);
	#elif SPI_u8_clock_mode==SPI_u8_Sample_Falling_Loading_Edge
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_CPOL_BIT);
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_CPHA_BIT);
	#elif SPI_u8_clock_mode==SPI_u8_Setup_Rising_Loading_Edge
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_CPOL_BIT);
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_CPHA_BIT);
	#elif SPI_u8_clock_mode==SPI_u8_Setup_Falling_Loading_Edge
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_CPOL_BIT);
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_CPHA_BIT);
	#endif
	#if   SPI_u8_clock_Rate==SPI_u8_Clock_Div_4
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPI2X_BIT);
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
	#elif SPI_u8_clock_Rate==SPI_u8_Clock_Div_16
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPI2X_BIT);
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
	#elif SPI_u8_clock_Rate==SPI_u8_Clock1_Div_64
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPI2X_BIT);
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
	#elif SPI_u8_clock_Rate==SPI_u8_Clock_Div_128
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPI2X_BIT);
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
	#elif SPI_u8_clock_Rate==SPI_u8_Clock_Div_2
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPI2X_BIT);
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
	#elif SPI_u8_clock_Rate==SPI_u8_Clock_Div_8
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPI2X_BIT);
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
	#elif SPI_u8_clock_Rate==SPI_u8_Clock_Div_32
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPI2X_BIT);
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
	   CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
	#elif SPI_u8_clock_Rate==SPI_u8_Clock2_Div_64
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPI2X_BIT);
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
	   SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
	#endif
} 

u8 ISP_u8TRA_REC_DATABIT(u8 copy_u8DataByte,u8 *copy_pu8DataString)
{
	u8 lacal_u8ErrorState = STD_TYPE_OK;
	 if(copy_pu8DataString!=NULL)
	 {
		 SPI_u8_SPDR_REG=copy_u8DataByte;
		 while(!GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT));
		 *copy_pu8DataString=SPI_u8_SPDR_REG;
	 }
	 else lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
}

void ISP_u8SEND_DATABIT(u8 copy_u8DataByte)
{
	#if SPI_u8_Select_MODE==SPI_u8_Master_Mode
	   SPI_u8_SPDR_REG=copy_u8DataByte;
	   while(!GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT));
	#elif SPI_u8_Select_MODE==SPI_u8_Slave_Mode
	   SPI_u8_SPDR_REG=copy_u8DataByte;
	#endif
	
}
u8 ISP_u8REC_DATABIT(u8 *copy_pu8DataString)
{
	u8 lacal_u8ErrorState = STD_TYPE_OK;
	 if(copy_pu8DataString!=NULL)
	 {
		 while(!GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT));
		 *copy_pu8DataString=SPI_u8_SPDR_REG;
	 }
	 else lacal_u8ErrorState=STD_TYPE_NOK;
	 return lacal_u8ErrorState;
}