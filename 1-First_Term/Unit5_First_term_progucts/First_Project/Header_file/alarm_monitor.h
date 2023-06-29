/*
 * alarm_monitor.h
 *
 *  Created on: Jun 27, 2023
 *      Author: Egypt_Laptop
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"

extern void (*alr_mon_st)();

typedef enum{
	alarm_off,
	alarm_on,
	timer_waiting
}alr_mon_st_en;

extern alr_mon_st_en alr_mon_st_id;

STATE_define(alarm_off);
STATE_define(alarm_on);
STATE_define(timer_waiting);

#endif /* ALARM_MONITOR_H_ */
