#ifndef SOCKET_H
#define SOCKET_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define DEFAULT_PORT "8080"

int open_listenfd(char *port);
int error_connection(int connfd);

#endif 