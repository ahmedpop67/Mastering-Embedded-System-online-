/*
 * pressure_sensor.c
 *
 *  Created on: Jun 27, 2023
 *      Author: Egypt_Laptop
 */

#include "pressure_sensor.h"
#include "STD_TYPES.h"
#include "driver.h"
uint8 pval=0;

void (*pre_st)();

pre_state_en pre_state_id;

void pre_sen_init()
{
	//init  pre_sensor
	pre_st=STATE(read_pressure);
}

STATE_define(read_pressure)
{
	pre_state_id=read_pressure;
	pval=getPressureVal();
	set_pressure_val(pval);
	pre_st=STATE(read_pressure);
}

STATE_define(waiting)
{
	pre_state_id=waiting;
	pre_st=STATE(read_pressure);
}



