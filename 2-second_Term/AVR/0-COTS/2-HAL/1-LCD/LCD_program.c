 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  11/30/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/

 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #define F_CPU 8000000UL
 #include <util/delay.h>
 #include "DIO_interface.h"
 #include "LCD_interface.h"
 #include "LCD_private.h"
 #include "LCD_config.h"

 void LCD_voidInit(void)
 {
	 _delay_ms(35);
	 /*function set*/
	 #if   LCD_u8_MODE==LCD_u8_MODE_8_BIT
	 LCD_voidSendCmnd(0b00111000);
	 #elif LCD_u8_MODE==LCD_u8_MODE_4_BIT
	 LCD_voidSendCmnd(0b00000010);
	 LCD_voidSendCmnd(0b00101000);
	 #endif
	 _delay_us(40);
	 /*display ON\OFF CONTROL*/
	 LCD_voidSendCmnd(0b00001100);
	 _delay_us(40);
	 /*DISPLAY CLEAR*/
	 LCD_voidSendCmnd(0x01);
	 _delay_ms(2);
	 /*ENTRY MODE SET*/
	 LCD_voidSendCmnd(0b00000110);
	 _delay_us(40);
 }

 void LCD_voidSendCmnd(u8 copy_u8Cmnd)
 {
	 #if LCD_u8_MODE==LCD_u8_MODE_8_BIT
	 /* step1 RS=0 */
	 DIO_u8SetpinValue(LCD_u8_RS_INPORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	 /*step2 RW=0 */
	 DIO_u8SetpinValue(LCD_u8_RW_INPORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	 /*WRITE CHAR */
	 DIO_u8SetPortValue(LCD_u8_DATA_PORT,copy_u8Cmnd);
	 /* step3 E=1 */
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	 /* step4 E=0 */
	 _delay_us(1);
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_LOW);
	 #elif LCD_u8_MODE==LCD_u8_MODE_4_BIT
	 /* step1 RS=0 */
	 DIO_u8SetpinValue(LCD_u8_RS_INPORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	 /*step2 RW=0 */
	 DIO_u8SetpinValue(LCD_u8_RW_INPORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	 /*WRITE CHAR */
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN0_INPORT,LCD_u8_DATA_PIN0,GET_BIT(copy_u8Cmnd,4));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN1_INPORT,LCD_u8_DATA_PIN1,GET_BIT(copy_u8Cmnd,5));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN2_INPORT,LCD_u8_DATA_PIN2,GET_BIT(copy_u8Cmnd,6));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN3_INPORT,LCD_u8_DATA_PIN3,GET_BIT(copy_u8Cmnd,7));
	 /* step3 E=1 */
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	 /* step4 E=0 */
	 _delay_us(1);
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_LOW);
	 /*WRITE CHAR */
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN0_INPORT,LCD_u8_DATA_PIN0,GET_BIT(copy_u8Cmnd,0));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN1_INPORT,LCD_u8_DATA_PIN1,GET_BIT(copy_u8Cmnd,1));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN2_INPORT,LCD_u8_DATA_PIN2,GET_BIT(copy_u8Cmnd,2));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN3_INPORT,LCD_u8_DATA_PIN3,GET_BIT(copy_u8Cmnd,3));
	 /* step3 E=1 */
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	 /* step4 E=0 */
	 _delay_us(1);
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_LOW);
	 #endif
 }

 void LCD_voidSendChar(u8 copy_u8Char)
 {
	 #if LCD_u8_MODE==LCD_u8_MODE_8_BIT
	 /* step1 RS=1 */
	 DIO_u8SetpinValue(LCD_u8_RS_INPORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	 /*step2 RW=0 */
	 DIO_u8SetpinValue(LCD_u8_RW_INPORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	 /*WRITE CHAR */
	 DIO_u8SetPortValue(LCD_u8_DATA_PORT,copy_u8Char);
	 /* step3 E=1 */
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	 /* step4 E=0 */
	 _delay_us(1);
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_LOW);
	 _delay_us(45);
	 #elif LCD_u8_MODE==LCD_u8_MODE_4_BIT
	 /* step1 RS=1 */
	 DIO_u8SetpinValue(LCD_u8_RS_INPORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	 /*step2 RW=0 */
	 DIO_u8SetpinValue(LCD_u8_RW_INPORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	 /*WRITE CHAR */
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN0_INPORT,LCD_u8_DATA_PIN0,GET_BIT(copy_u8Char,4));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN1_INPORT,LCD_u8_DATA_PIN1,GET_BIT(copy_u8Char,5));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN2_INPORT,LCD_u8_DATA_PIN2,GET_BIT(copy_u8Char,6));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN3_INPORT,LCD_u8_DATA_PIN3,GET_BIT(copy_u8Char,7));
	 /* step3 E=1 */
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	 /* step4 E=0 */
	 _delay_us(1);
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_LOW);
	 /*WRITE CHAR */
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN0_INPORT,LCD_u8_DATA_PIN0,GET_BIT(copy_u8Char,0));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN1_INPORT,LCD_u8_DATA_PIN1,GET_BIT(copy_u8Char,1));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN2_INPORT,LCD_u8_DATA_PIN2,GET_BIT(copy_u8Char,2));
	 DIO_u8SetpinValue(LCD_u8_DATA_PIN3_INPORT,LCD_u8_DATA_PIN3,GET_BIT(copy_u8Char,3));
	 /* step3 E=1 */
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	 /* step4 E=0 */
	 _delay_us(1);
	 DIO_u8SetpinValue(LCD_u8_E_INPORT,LCD_u8_E_PIN,DIO_u8_LOW);
	 _delay_us(45);
	 #endif
 }

 void LCD_voidWriteString(u8 *copy_u8String)
 {
	 while(* copy_u8String)
	 {
		 LCD_voidSendChar(* copy_u8String);
		 copy_u8String++;
		 _delay_us(40);
	 }
 }

 void LCD_voidWriteNUM(f32 copy_u32Num)
 {
	 u8 arr[40]={0};
	 u8 i=0;
	 s32 local_u8Num=copy_u32Num;
	 s32 local_u8fri=(copy_u32Num-local_u8Num)*10;
	 if(local_u8fri==0){
	 if(local_u8Num>0)
	 {
	 while(local_u8Num)
	 {
		 arr[i]=local_u8Num % 10;
		 local_u8Num/=10;
		 i++;	 
	 }
	 for (int k=i-1;k>=0;k--)
	 {
		 LCD_voidSendChar(arr[k]+48);
	 }
	 }
	else if(local_u8Num<0)
	{
	 LCD_voidSendChar('-');
	 local_u8Num=local_u8Num*-1;
    while(local_u8Num)
    {
   	    arr[i]=local_u8Num%10;
   	    local_u8Num/=10;
   	    i++;
    }
    for (int k=i-1;k>=0;k--)
    {
   	    LCD_voidSendChar(arr[k]+48);
    }
    }
	else LCD_voidSendChar('0');
}
else
{
	if(local_u8Num>=0)
	{
		while(local_u8Num)
		{
			arr[i]=local_u8Num % 10;
			local_u8Num/=10;
			i++;
		}
		for (int k=i-1;k>=0;k--)
		{
			LCD_voidSendChar(arr[k]+48);
		}
		LCD_voidSendChar('.');
		while(local_u8fri)
		{
			arr[i]=local_u8fri % 10;
			local_u8fri/=10;
			i++;
		}
		for (int k=i-1;k>=0;k--)
		{
			LCD_voidSendChar(arr[k]+48);
		}
	}
	else if(local_u8Num<0)
	{
		LCD_voidSendChar('-');
		local_u8Num=local_u8Num*-1;
		local_u8fri=local_u8fri*-1;
		while(local_u8Num)
		{
			arr[i]=local_u8Num%10;
			local_u8Num/=10;
			i++;
		}
		for (int k=i-1;k>=0;k--)
		{
			LCD_voidSendChar(arr[k]+48);
		}
		LCD_voidSendChar('.');
			while(local_u8fri)
			{
				arr[i]=local_u8fri % 10;
				local_u8fri/=10;
				i++;
			}
			for (int k=i-1;k>=0;k--)
			{
				LCD_voidSendChar(arr[k]+48);
			}
	}
	else LCD_voidSendChar('0');
}
}
 
 void LCD_voidCLEAR(void)
 {
	 LCD_voidSendCmnd(0x01);
	 _delay_ms(2);
 }

 void LCD_voidReturnHome(void)
 {
	 LCD_voidSendCmnd(0x02);
	 _delay_ms(2);
 }

 u8 LCD_u8GoToXY(u8 copy_u8LineNum,u8 copy_u8Location)
 {
	 u8 lacal_u8ErrorState = STD_TYPE_OK;
	 if(copy_u8Location<=39)
	 {
		 switch(copy_u8LineNum)
		 {
			 case LCD_u8_LINE1:LCD_voidSendCmnd(0x80+copy_u8Location);_delay_us(40);break;
			 case LCD_u8_LINE2:LCD_voidSendCmnd(0xc0+copy_u8Location);_delay_us(40);break;
			 default: lacal_u8ErrorState=STD_TYPE_NOK;
		 }
	 }
	 else
	 {
		 lacal_u8ErrorState=STD_TYPE_NOK;
	 }
	 return lacal_u8ErrorState;
 }

 void lcd_voidDrow(u8 copy_u8CGRAM,u8 *copy_u8Shape,u8 copy_u8LineNum,u8 copy_u8Location)
 {
	 LCD_voidSendCmnd(0b01000000+copy_u8CGRAM*8);
	 u8 i=0;
	 while(i<8)
	 {
		 LCD_voidSendChar(* copy_u8Shape);
		 copy_u8Shape++;
		 i++;
	 }
	 LCD_u8GoToXY(copy_u8LineNum,copy_u8Location);
	 LCD_voidSendChar(copy_u8CGRAM);
 }

 void LCD_Move_Left(void)
 {
	 while(1){
		 LCD_voidSendCmnd(0b00011000);
		 _delay_ms(140);
	 }
 }

 void LCD_Move_Right(void)
 {
	 while(1){
		 LCD_voidSendCmnd(0b00011100);
		 _delay_ms(140);
	 }
 }

