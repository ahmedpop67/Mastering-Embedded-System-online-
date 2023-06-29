
#include "driver.h"
#include "pressure_sensor.h"
#include "alarm_monitor.h"
#include "alarm.h"
#include "detect.h"
#include "STD_TYPES.h"

void setup()
{
	GPIO_INITIALIZATION();
	pre_sen_init();
	detect_st=STATE(pressure_detect);
	alr_mon_st=STATE(alarm_off);
	alarm_init();
}
int main(){
	setup();
	while(1)
	{
		pre_st();
		detect_st();
		alr_mon_st();
		alarm_st();
	}
}
