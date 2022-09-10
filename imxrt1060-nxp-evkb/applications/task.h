#ifndef _TASK_H_
#define _TASK_H_

#include <stdio.h>
#include "sensor_asair_aht10.h"

#define AHT10_I2C_BUS  "i2c1"

typedef struct __aht10
{
	float humidity;
	float temperature;
}st_aht10;

#endif

