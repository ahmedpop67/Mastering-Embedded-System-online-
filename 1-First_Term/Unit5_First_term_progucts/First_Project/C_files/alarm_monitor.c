/*
 * alarm_monitor.c
 *
 *  Created on: Jun 27, 2023
 *      Author: Egypt_Laptop
 */
#include "alarm_monitor.h"
#include "driver.h"

void (*alr_mon_st)();

alr_mon_st_en alr_mon_st_id;

void high_presure_detect()
{
	alr_mon_st=STATE(alarm_on);
}

STATE_define(alarm_off)
{
	alr_mon_st_id=alarm_off;
	stop_alarm();
}
STATE_define(alarm_on)
{
	alr_mon_st_id=alarm_on;
	start_alarm();
	alr_mon_st=STATE(alarm_off);
}
STATE_define(timer_waiting)
{
	alr_mon_st_id=timer_waiting;
	alr_mon_st=STATE(alarm_off);
}

