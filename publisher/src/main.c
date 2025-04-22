#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#include "utils.h"
#include "sensor.h"

void print_help(){
    printf("Publisher TinyIoT\n");
    printf("This program has the goal of simulating two sensors working concurrently.\n");
    printf("Currently, there are only two sensors working. [Temperature (Celsius) and Humidity (Percent)]\n");
    printf("\n");
}

int main(int argc, char **argv){
    sensor sensors_array[NUM_SENSORS];
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
    init_sensors(sensors_array);
    int result = pthread_create(&thread_temperature, NULL, start_simulation, &sensors_array[0]);
    if(result != 0){
        printf("Error in creating the temperature thread: %s\n", strerror(result));
    }
    result = pthread_create(&thread_humidity, NULL, start_simulation, &sensors_array[1]);
    if(result != 0){
        printf("Error in creating the humidity thread: %s\n", strerror(result));
    }

    pthread_join(thread_temperature, NULL);
    pthread_join(thread_humidity,NULL);

    return 0;
}
