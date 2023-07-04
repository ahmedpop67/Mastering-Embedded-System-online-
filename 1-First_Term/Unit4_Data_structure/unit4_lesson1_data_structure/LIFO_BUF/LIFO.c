/*
 * LIFO.C
 *
 *  Created on: Jul 2, 2023
 *      Author: Egypt_Laptop
 */

#include "LIFO.h"

LIFO_status LIFO_push_item(LIFO_BUF_t*lifo_buf,LIFO_size item)
{
	if(!lifo_buf->base || !lifo_buf->base)
		return LIFO_NULL;
	if(lifo_buf->count==lifo_buf->length)
		return LIFO_full;
	*(lifo_buf->head)=item;
	  lifo_buf->head++;
	  lifo_buf->count++;
	  return LIFO_no_error;
}
LIFO_status LIFO_pop_item(LIFO_BUF_t*lifo_buf,LIFO_size* item)
{
	if(!lifo_buf->base || !lifo_buf->base)
		return LIFO_NULL;
	if(lifo_buf->count==0)
		return LIFO_empty;
	lifo_buf->head--;
	*item=*(lifo_buf->head);
	lifo_buf->count--;
	return LIFO_no_error;
}
LIFO_status LIFO_init(LIFO_BUF_t*lifo_buf,LIFO_size* buf,unsigned int length)
{
	if(lifo_buf!=NULL)
	lifo_buf->base=buf;
	lifo_buf->head=buf;
	lifo_buf->length=length;
	lifo_buf->count=0;
}

