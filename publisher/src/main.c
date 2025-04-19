#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>

bool tflag = false; // Temperature
bool hflag = false; // Humidity

void print_help(){
    printf("Publisher TinyIoT\n");
    printf("\tHelp Command: [-h]\n");
    printf("\tActivate Temperature Sensor: [-T]\n");
    printf("\tActivate Humidity Sensor: [-H]\n");
    printf("\n");
}

int main(int argc, char **argv){
    int opt;
    // Try to change later
    while ((opt = getopt(argc, argv, "h")) != -1)
    {  
        switch (opt)
        {
        case 'h':
            print_help();
            return 0;
        case 'T':
            tflag = true;
            break;
        case 'H':
            hflag = true;
            break;
        case '?':
        default:
            fprintf(stderr, "use: %s [-T] [-H] [arg 1] [arg 2] ... [arg n]\n", argv[0]);
            return -1;
        }
    }
    

    return 0;
}
