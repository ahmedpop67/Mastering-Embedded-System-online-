 /*****************************************************************************/
 /***************************  NAME  :  ahmed hassan **************************/
 /***************************  DATE  :  11/30/2022   **************************/
 /*************************  VERSION :  1.0          **************************/
 /*****************************************************************************/
														
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_u8_LINE1   1
#define LCD_u8_LINE2   2

void LCD_voidInit(void);

void LCD_voidSendCmnd(u8 copy_u8Cmnd);

void LCD_voidSendChar(u8 copy_u8Char);

void LCD_voidWriteString(u8 *copy_u8String);

void LCD_voidWriteNUM(f32 copy_u32Num);

u8   LCD_u8GoToXY(u8 copy_u8LineNum,u8 copy_u8Location);

void LCD_voidCLEAR(void);

void LCD_voidReturnHome(void);

void lcd_voidDrow(u8 copy_u8CGRAM,u8 *copy_u8Shape,u8 copy_u8LineNum,u8 copy_u8Location);

void LCD_Move_Left(void);

void LCD_Move_Right(void);

#endif