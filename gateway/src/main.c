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
    int opt, listenfd, connfd;
    char *port = DEFAULT_PORT;

    unsigned int clientlen;
    // address and connections
    struct sockaddr_in clientaddr;
    struct hostent *hp;
    char *haddrp; // client ip in string format

    while ((opt = getopt(argc, argv, "hp")) != -1){
        switch (opt)
        {
        case 'h':
            print_help();
            return 0;
        case 'p':
            int port_n = atoi(argv[2]);
            if(port_n <= 0 || port_n > USHRT_MAX){
                fprintf(stderr, "Invalid %s port, to set a custom port enter a number between 1 and %d\n",argv[2], USHRT_MAX);
                return -1;
            }else
                port = argv[2];
            break;
        default:
            fprintf(stderr, "use: %s -p <port> (to change the default port)\n", argv[0]);
            fprintf(stderr, "use: %s -h to display help section\n", argv[0]);
            return -1;
        }
    }

    listenfd = open_listenfd(port);
    if (listenfd < 0) {
        return error_connection(listenfd);
    }

    printf("Gateway Server listening in the port [%s]\n", port);

    while(1){
        clientlen = sizeof(clientaddr);
        connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
        hp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
        haddrp = inet_ntoa(clientaddr.sin_addr);
        printf("Server connected to: %s (%s)\n", hp->h_name, haddrp);
        printf("Processing request...\n");
        
        close(connfd);
    }
    return 0;
}