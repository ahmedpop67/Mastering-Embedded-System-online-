/*
 * pressure_sensor.h
 *
 *  Created on: Jun 27, 2023
 *      Author: Egypt_Laptop
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"

extern void (*pre_st)();

typedef enum{
	read_pressure,
	waiting
}pre_state_en;

extern pre_state_en pre_state_id;

STATE_define(read_pressure);

STATE_define(waiting);

void pre_sen_init();




#endif /* PRESSURE_SENSOR_H_ */
