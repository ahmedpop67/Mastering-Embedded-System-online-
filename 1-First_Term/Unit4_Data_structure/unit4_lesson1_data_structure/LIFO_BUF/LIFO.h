/*
 * LIFO.H
 *
 *  Created on: Jul 2, 2023
 *      Author: Egypt_Laptop
 */

#ifndef LIFO_H_
#define LIFO_H_

#define LIFO_size   unsigned int

#include<stdio.h>
#include <stdlib.h>

typedef struct LIFO
{
	LIFO_size length;
	LIFO_size count;
	LIFO_size * base;
	LIFO_size * head;
}LIFO_BUF_t;

typedef enum
{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_NULL
}LIFO_status;

LIFO_status LIFO_push_item(LIFO_BUF_t*lifo_buf,LIFO_size item);
LIFO_status LIFO_pop_item(LIFO_BUF_t*lifo_buf,LIFO_size* item);
LIFO_status LIFO_init(LIFO_BUF_t*lifo_buf,LIFO_size* buf,unsigned int length);

#endif /* LIFO_H_ */
