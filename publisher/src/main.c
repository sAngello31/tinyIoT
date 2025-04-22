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
    pthread_t data_thread;
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
    start_simulation(&sensors_array[0]);

    return 0;
}
