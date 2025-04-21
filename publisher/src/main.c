#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "utils.h"

void print_help(){
    printf("Publisher TinyIoT\n");
    printf("This program has the goal of simulating two sensors working concurrently.\n");
    printf("Currently, there are only two sensors working. [Temperature (Celsius) and Humidity (Percent)]\n");
    printf("\n");
}

int main(int argc, char **argv){
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
    
    while(1){
        float generated_value = generate_rand_number(15.0, 30.0);
        printf("\tValue: %f\n", generated_value);
        sleep(1);
        
    }
    return 0;
}
