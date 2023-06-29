/*
 * alarm.h
 *
 *  Created on: Jun 27, 2023
 *      Author: Egypt_Laptop
 */

#ifndef ALARM_H_
#define ALARM_H_

#include "state.h"

extern void (*alarm_st)();

typedef enum{
	alarm_start,
	alarm_stop,
	alarm_waiting
}alarm_st_en;

extern alarm_st_en alarm_st_id;

STATE_define(alarm_start);
STATE_define(alarm_stop);
STATE_define(alarm_waiting);

void alarm_init();

#endif /* ALARM_H_ */
