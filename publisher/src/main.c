#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "utils.h"
#include "sensor.h"

void print_help(){
    printf("Publisher TinyIoT\n");
    printf("This program has the goal of simulating two sensors working concurrently.\n");
    printf("Currently, there are only two sensors working. [Temperature (Celsius) and Humidity (Percent)]\n");
    printf("\n");
}

int main(int argc, char **argv){
    sensor temperature_sensor;
    sensor humidity_sensor;
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
    strcpy(temperature_sensor.name, "Temperature");
    strcpy(humidity_sensor.name, "Humidity");
    while(1){
        float generated_value = generate_rand_number(15.0, 30.0);
        temperature_sensor.data_value = generated_value;
        send_data(&temperature_sensor);
        sleep(1);
    }

    free(&temperature_sensor);
    free(&humidity_sensor);
    return 0;
}
