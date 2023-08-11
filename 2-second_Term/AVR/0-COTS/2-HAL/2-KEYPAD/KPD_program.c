 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  12/3/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

u8 KPD_u8_Get_key_state(u8 * copy_pu8_Returned_Key)
{
	* copy_pu8_Returned_Key=KPD_u8_KEY_NOT_PRESSED;
	u8 lacal_u8ErrorState = STD_TYPE_OK,local_u8RowsCounter,local_u8ColsCounter,local_u8PIN_Value,local_u8flag=0;
	const u8 KPD_Au8KEYS[KPD_ROWS][KPD_COLS]=KPD_KEYS;
	const u8 KPD_Au8RowsPORTS[KPD_ROWS]={KPD_u8_R1_PIN_INPORT,KPD_u8_R2_PIN_INPORT,KPD_u8_R3_PIN_INPORT,KPD_u8_R4_PIN_INPORT};
	const u8 KPD_AuCOLSsPORTS[KPD_COLS]={KPD_u8_C1_PIN_INPORT,KPD_u8_C2_PIN_INPORT,KPD_u8_C3_PIN_INPORT,KPD_u8_C4_PIN_INPORT};
	const u8 KPD_Au8RowsPins[KPD_ROWS]={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
	const u8 KPD_Au8COLsPins[KPD_COLS]={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};
	if(copy_pu8_Returned_Key != NULL)
	{
		for(local_u8RowsCounter=0;local_u8RowsCounter < KPD_ROWS;local_u8RowsCounter++)
		{
			DIO_u8SetpinValue(KPD_Au8RowsPORTS[local_u8RowsCounter],KPD_Au8RowsPins[local_u8RowsCounter],DIO_u8_LOW);
			for(local_u8ColsCounter=0;local_u8ColsCounter < KPD_COLS;local_u8ColsCounter++)
			{
				DIO_u8GetPinValue(KPD_AuCOLSsPORTS[local_u8ColsCounter],KPD_Au8COLsPins[local_u8ColsCounter],&local_u8PIN_Value);
				if(local_u8PIN_Value==DIO_u8_LOW)
				{
					_delay_ms(20);
					DIO_u8GetPinValue(KPD_AuCOLSsPORTS[local_u8ColsCounter],KPD_Au8COLsPins[local_u8ColsCounter],&local_u8PIN_Value);
					while(local_u8PIN_Value==DIO_u8_LOW)
					{
						DIO_u8GetPinValue(KPD_AuCOLSsPORTS[local_u8ColsCounter],KPD_Au8COLsPins[local_u8ColsCounter],&local_u8PIN_Value);
					}
					*copy_pu8_Returned_Key=KPD_Au8KEYS[local_u8RowsCounter][local_u8ColsCounter];
					local_u8flag=1;
					break;
				}
			}
			DIO_u8SetpinValue(KPD_Au8RowsPORTS[local_u8RowsCounter],KPD_Au8RowsPins[local_u8RowsCounter],DIO_u8_HIGH);
			if(local_u8flag==1)
			{
				break;
			}
		}
	}
	else
	{
		lacal_u8ErrorState=STD_TYPE_NOK;
	}
	return lacal_u8ErrorState; 
}