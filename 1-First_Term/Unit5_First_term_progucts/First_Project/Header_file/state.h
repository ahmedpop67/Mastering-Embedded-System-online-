/*
 * state.h
 *
 *  Created on: Jun 27, 2023
 *      Author: Egypt_Laptop
 */

#ifndef STATE_H_
#define STATE_H_

#include "STD_TYPES.h"

#define STATE_define(_state_)  void st_##_state_()
#define STATE(_state_)         st_##_state_

void set_pressure_val(uint8 prev);

void high_presure_detect();

void start_alarm();

void stop_alarm();

#endif /* STATE_H_ */
