/*
 * alarm.c
 *
 *  Created on: Jun 27, 2023
 *      Author: Egypt_Laptop
 */

#include "alarm.h"
#include "driver.h"

void (*alarm_st)();

alarm_st_en alarm_st_id;

void alarm_init()
{
   //alarm_init
	alarm_st=STATE(alarm_waiting);
}

void start_alarm()
{
	alarm_st=STATE(alarm_start);
}

void stop_alarm()
{
	alarm_st=STATE(alarm_stop);
}

STATE_define(alarm_start)
{
	alarm_st_id=alarm_start;
	Set_Alarm_actuator(0);
	Delay(2000000);
	alarm_st=STATE(alarm_waiting);
}

STATE_define(alarm_stop)
{
	alarm_st_id=alarm_stop;
	Set_Alarm_actuator(1);
	alarm_st=STATE(alarm_waiting);
}

STATE_define(alarm_waiting)
{
	alarm_st_id=alarm_waiting;
}
