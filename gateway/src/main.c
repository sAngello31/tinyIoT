#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <limits.h>

#include "socket.h"

void print_help(){
    printf("TinyIoT Gateway\n");
    printf("Flags:");
    printf("\t[h] - Display help section");
    printf("\t[p] - Set a custom port (Port 8080 by default)");
}

int main(int argc, char **argv){
    int opt;
    int port = DEFAULT_PORT;
    
    while ((opt = getopt(argc, argv, "hp")) != -1){
        switch (opt)
        {
        case 'h':
            print_help();
            return 0;
        case 'p':
            port = atoi(argv[2]);
            if(port <= 0 || port > USHRT_MAX){
                fprintf(stderr, "Invalid %s port, to set a custom port enter a number between 1 and %d\n",argv[2], USHRT_MAX);
                return -1;
            }
            break;
        default:
            fprintf(stderr, "use: %s -p <port> (to change the default port)\n", argv[0]);
            fprintf(stderr, "use: %s -h to display help section\n", argv[0]);
            return -1;
        }
    }
    

    printf("Starting Gateway Server...\n");
    printf("Listening in the port [%i]\n", port);
    return 0;
}