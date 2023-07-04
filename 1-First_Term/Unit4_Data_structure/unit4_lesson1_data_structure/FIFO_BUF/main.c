/*
 * main.c
 *
 *  Created on: Jul 3, 2023
 *      Author: Egypt_Laptop
 */

#include "FIFO.h"

unsigned int buffer1[5];
int val2=0;
void main(){
   FIFO_BUF_t uart_FIFO , I2C_FIFO;
   FIFO_init(&uart_FIFO, buffer1,5);

   unsigned int buffer2=(unsigned int*) malloc(5*sizeof(unsigned int));
   FIFO_init(&I2C_FIFO, buffer2,5);

   for (int i=0;i<5;i++){
	  if(FIFO_enqueue(&uart_FIFO, i) == FIFO_no_error)
	   printf("UART FIFO enqueue : %d \n",i);
   }
   printf("\n");
   for (int i=0;i<5;i++){
   	  if(FIFO_dequeue(&uart_FIFO,&val2) == FIFO_no_error)
   	   printf("UART FIFO dequeue : %d \n",val2);
      }
}
