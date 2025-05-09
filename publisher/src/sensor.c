#include "sensor.h"

// Change de init
void init_sensors(sensor sensors_array[]){
    sensors_array[0].name = SENSOR_TEMPERATURE;
    sensors_array[0].data_value = 0;

    sensors_array[1].name = SENSOR_HUMIDITY;
    sensors_array[1].data_value = 0;
}

void* start_simulation(void* arg){
    float min = 0.3;
    float max = 0.7;
    sensor* sensor_data = (sensor*) arg; 
    // Change the way how we can recognize the min and max for the sensors
    if(strcmp(sensor_data->name, SENSOR_TEMPERATURE) == 0){
        min = 15.0;
        max = 30.0;        
    }
    printf("Starting Simulation of %s Sensor...\n", sensor_data->name);
    while(1){
        sensor_data->data_value = generate_rand_number(min, max);
        sensor_data->timestamps = time(NULL);
        send_data(sensor_data);
        printf("\n");
        sleep(1);
    }
    return NULL;
}