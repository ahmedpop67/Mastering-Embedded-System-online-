/*
 * FIFO.h
 *
 *  Created on: Jul 3, 2023
 *      Author: Egypt_Laptop
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdlib.h"
#include "stdio.h"

#define FIFO_data_type  unsigned int

typedef struct FIFO
{

	unsigned int count;
	unsigned int length;
	FIFO_data_type* base;
	FIFO_data_type* head;
	FIFO_data_type* tail;
}FIFO_BUF_t;

typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL
}FIFO_status;

FIFO_status FIFO_enqueue(FIFO_BUF_t*fifo_buf,FIFO_data_type item);
FIFO_status FIFO_dequeue(FIFO_BUF_t*fifo_buf,FIFO_data_type* item);
FIFO_status FIFO_init(FIFO_BUF_t*fifo_buf,FIFO_data_type* buf,unsigned int length);
FIFO_status FIFO_IS_FULL(FIFO_BUF_t*fifo_buf);
void FIFO_print(FIFO_BUF_t*fifo_buf);

#endif /* FIFO_H_ */
