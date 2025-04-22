#ifndef SENSOR_H
#define SENSOR_H

#include <time.h>

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

// Void for now
// This function will send the data to the gateway
void send_data(sensor* sensor_data);
void init_sensors(sensor sensors_array[]);
void start_simulation(sensor*  sensor_data);

#endif 