#ifndef SENSOR_H
#define SENSOR_H

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

#include "socket.h"

#define SENSOR_TEMPERATURE "Temperature"
#define SENSOR_HUMIDITY "Humidity"
#define NUM_SENSORS 2

#pragma pack(1)
typedef struct {
    char* name;
    float data_value;
    time_t timestamps;
} sensor;
#pragma pack()

void init_sensors(sensor sensors_array[]);
void* start_simulation(void*  arg);

#endif 