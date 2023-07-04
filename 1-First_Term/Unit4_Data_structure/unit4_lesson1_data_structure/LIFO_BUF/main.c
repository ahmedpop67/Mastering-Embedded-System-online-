/*
 * main.c
 *
 *  Created on: Jul 2, 2023
 *      Author: Egypt_Laptop
 */
#include "LIFO.h"

unsigned int buffer1[5];
int val=0;
void main(){
   LIFO_BUF_t uart_lifo , I2C_lifo;
   LIFO_init(&uart_lifo, buffer1,5);

   unsigned int buffer2=(unsigned int*) malloc(5*sizeof(unsigned int));
   LIFO_init(&I2C_lifo, buffer2,5);

   for (int i=0;i<5;i++){
	  if(LIFO_push_item(&uart_lifo, i) == LIFO_no_error)
	   printf("uart lifo add : %d \n",i);
   }
   for (int i=0;i<5;i++){
   	  if(LIFO_pop_item(&uart_lifo,&val) == LIFO_no_error)
   	   printf("uart lifo pop : %d \n",val);
      }
   for (int i=0;i<5;i++){
	   if(LIFO_push_item(&I2C_lifo, i) == LIFO_no_error)
  	   printf("i2c lifo add : %d \n",i);
     }

}


