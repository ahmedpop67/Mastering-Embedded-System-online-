/*
 * FIFO.c
 *
 *  Created on: Jul 3, 2023
 *      Author: Egypt_Laptop
 */
#include "FIFO.h"

FIFO_status FIFO_enqueue(FIFO_BUF_t*fifo_buf,FIFO_data_type item)
{
	if(!fifo_buf->base || !fifo_buf->base || !fifo_buf->tail)
		return FIFO_NULL;
	if(FIFO_IS_FULL(fifo_buf)==FIFO_full)
		return FIFO_full;
	*(fifo_buf->head)=item;
	fifo_buf->count++;
	if (fifo_buf->head == fifo_buf->base + (fifo_buf->length)*sizeof(FIFO_data_type))
		fifo_buf->head=fifo_buf->base;
	else
		fifo_buf->head++;
	return FIFO_no_error;
}
FIFO_status FIFO_dequeue(FIFO_BUF_t*fifo_buf,FIFO_data_type* item)
{
	if(!fifo_buf->base || !fifo_buf->base || !fifo_buf->tail)
		return FIFO_NULL;
	*item=*(fifo_buf->tail);
	if (fifo_buf->tail == fifo_buf->base + (fifo_buf->length)*sizeof(FIFO_data_type))
		fifo_buf->tail=fifo_buf->base;
	else
		fifo_buf->tail++;
	fifo_buf->count--;
	return FIFO_no_error;
}
FIFO_status FIFO_init(FIFO_BUF_t*fifo_buf,FIFO_data_type* buf,unsigned int length)
{
	if(fifo_buf!=NULL){
		fifo_buf->base=buf;
		fifo_buf->head=buf;
		fifo_buf->tail=buf;
		fifo_buf->length=length;
		fifo_buf->count=0;
		return FIFO_no_error;
	}
	return FIFO_NULL;
}
FIFO_status FIFO_IS_FULL(FIFO_BUF_t*fifo_buf)
{
	if(fifo_buf->count==fifo_buf->length)
		return FIFO_full;
	return FIFO_no_error;
}
void FIFO_print(FIFO_BUF_t*fifo_buf)
{

}

