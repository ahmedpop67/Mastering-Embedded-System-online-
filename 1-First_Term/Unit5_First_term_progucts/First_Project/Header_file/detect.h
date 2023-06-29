/*
 * detect.h
 *
 *  Created on: Jun 27, 2023
 *      Author: Egypt_Laptop
 */

#ifndef DETECT_H_
#define DETECT_H_

#include "state.h"

extern void (*detect_st)();

typedef enum{
	pressure_detect
}detect_st_en;

extern detect_st_en detect_st_id;

STATE_define(pressure_detect);




#endif /* DETECT_H_ */
