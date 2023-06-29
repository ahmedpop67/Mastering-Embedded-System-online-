/*
 * detect.c
 *
 *  Created on: Jun 27, 2023
 *      Author: Egypt_Laptop
 */

#include "detect.h"
#include "STD_TYPES.h"

uint8 pre_val=0;
uint8 last_val=0;
uint8 threshold=20;

void (*detect_st)();

detect_st_en detect_st_id;

void set_pressure_val(uint8 pval)
{
	last_val=pre_val;
	pre_val=pval;
}


STATE_define(pressure_detect)
{
	detect_st_id=pressure_detect;
	if (pre_val > threshold && pre_val!=last_val)
	{
		high_presure_detect();
		detect_st=STATE(pressure_detect);
	}
	else
	{
		detect_st=STATE(pressure_detect);
	}
}


