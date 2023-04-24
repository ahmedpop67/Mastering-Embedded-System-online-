#include"uart.h"

unsigned char string_buffer[100]="learn_in_depth : Ahmed Hassan";
void main(void)
{
	UART_Send_string(string_buffer);
}