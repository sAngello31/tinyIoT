#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

#pragma pack(1)
typedef struct {
    char name[15];
    float data_value;
    uint32_t timestamps;
} sensor;
#pragma pack()

// Void for now
// This function will send the data to the gateway
void send_data(sensor* sensor_data);

#endif 