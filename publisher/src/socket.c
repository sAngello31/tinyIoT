#include "socket.h"

int open_clientfd(char* hostname, char* port){
    int clientfd;
    struct addrinfo hints, *listp, *p;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_NUMERICSERV;
    hints.ai_flags |= AI_ADDRCONFIG;
    getaddrinfo(hostname, port, &hints, &listp);
    for(p = listp; p; p = p->ai_next){
        if((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0){
            continue;
        }
        if(connect(clientfd, p->ai_addr, p->ai_addrlen) != -1){
            break;
        }
        close(clientfd);
    }
    freeaddrinfo(listp);
    if(!p){
        return -1;
    }
    return clientfd;
}
/*
int send_data(sensor* data){
    printf("%s sensor is connected to gateway socket\n", sensor_data->name);
    printf("%s sensor sending %f...\n", sensor_data->name ,sensor_data->data_value);
    return 0;
}
*/
int error_connection(int connfd){
    fprintf(stderr, "Connection error: %s\n", strerror(connfd));
    close(connfd);
    return -1;
}