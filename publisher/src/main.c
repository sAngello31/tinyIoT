#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#include "utils.h"
#include "sensor.h"


void* start_thread(void* arg){
    sensor* sensor_data = (sensor*) arg;
    printf("Starting Simulation of %s Sensor...\n", sensor_data->topic);
    while(1){
        sensor_data->data_value = generate_rand_number(sensor_data->limit_min, sensor_data->limit_max);
        send_data(sensor_data);  
        printf("\n");
        sleep(1);
    }

}

int main(int argc, char **argv){
    sensor** sensors_array;
    pthread_t thread_temperature, thread_humidity;
    int opt;

    while ((opt = getopt(argc, argv, "h")) != -1)
    {  
        switch (opt)
        {
        case 'h':
            print_help();
            return 0;
        case '?':
        default:
            fprintf(stderr, "use: %s [-h] to find help\n", argv[0]);
            return -1;
        }
    }

    srand(time(NULL));
    sensors_array = init_sensors();
    
    for(int i = 0; i < NUM_SENSORS; i++){
        printf("Sensor %d initialized with topic: %s\n", i, sensors_array[i]->topic);
        printf("Sensor %d limits: %f - %f\n\n", i, sensors_array[i]->limit_min, sensors_array[i]->limit_max);

    }
    
    int result = pthread_create(&thread_temperature, NULL, start_thread, sensors_array[0]);
    if(result != 0){
        printf("Error in creating the temperature thread: %s\n", strerror(result));
    }
    result = pthread_create(&thread_humidity, NULL, start_thread, sensors_array[1]);
    if(result != 0){
        printf("Error in creating the humidity thread: %s\n", strerror(result));
    }

    pthread_join(thread_temperature, NULL);
    pthread_join(thread_humidity,NULL);
    
    return 0;
}
