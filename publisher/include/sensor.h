#ifndef SENSOR_H
#define SENSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"
#include "socket.h"

#define ROOT_LEVEL "sensors"
#define SENSOR_TEMPERATURE "Temperature"
#define SENSOR_HUMIDITY "Humidity"
#define NUM_SENSORS 2
#define NUM_SENSOR_TOPICS 6


typedef struct {
    char* topic;
    float data_value;
    float limit_min;
    float limit_max;
} sensor;


#pragma pack(1)
typedef struct {
    char* topic;
    float data_value;
} sensor_data_to_send;
#pragma pack()

sensor** init_sensors();
void* start_simulation(void*  arg);
int send_data(sensor* data);
char *get_sensor_topic(int sensor_type);

#endif 