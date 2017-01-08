//
// Created by alin on 12/28/16.
//
#include <netinet/in.h>
#include "../include/NetworkWrappers.h"

int connectTo(unsigned int ip, unsigned short port)
{
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(ip);
    server.sin_port = htons(port);

    int sock;
    sock = socket(AF_INET,SOCK_STREAM,0);
    if (connect(sock, (struct sockaddr*)&server,sizeof(server)) == 0)
        return sock;
    else
        throw ("Couldn't connect to the server");
}