#include "utils.h"
#include <stdlib.h>

float generate_rand_number(float min, float max){
    return min + ((float)rand()/RAND_MAX) * (max - min);
}

void print_help(){
    printf("Publisher TinyIoT - MQTT\n");
    printf("This program has the goal of simulating two sensors working concurrently.\n");
    printf("Currently, there are only two sensors working. [Temperature (Celsius) and Humidity (Percent)]\n");
    printf("\n");
}
