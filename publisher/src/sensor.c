#include <stdio.h>
#include "sensor.h"

void send_data(sensor* sensor_data){
    printf("%s sensor sending %f...\n", sensor_data->name ,sensor_data->data_value);
}