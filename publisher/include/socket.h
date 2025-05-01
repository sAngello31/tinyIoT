#ifndef SOCKET_H
#define SOCKET_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "sensor.h"

#define DEFAULT_PORT "8080"
#define DEFAULT_HOSTNAME "127.0.0.1"

int open_clientfd(char* hostname, char* port);
int send_data(sensor* data);
int error_connection(int connfd);

#endif