//
// Created by alin on 12/29/16.
//
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>
#include "../include/Address.h"

Address::Address(unsigned int publicIP,unsigned short publicPort,
        unsigned int privateIP,unsigned short privatePort)
{
    this->publicIP = publicIP;
    this-> privateIP = privateIP;
    this->publicPort = publicPort;
    this->privatePort = privatePort;
}

Address::Address(const char *stringAddr) {
    char* buffer;
    buffer = (char*) malloc(strlen(stringAddr));
    char * p;
    p = strtok(buffer,":");

    unsigned int ip = inet_addr(p);
    publicIP = ntohl(ip);

    p = strtok(NULL,":");
    unsigned short port = (unsigned short) atoi(p);
    publicPort = port;



}

void Address::toString() {


}

void Address::setPrivateIP(unsigned int privateIP) {
    Address::privateIP = privateIP;
}

void Address::setPrivatePort(unsigned short privatePort) {
    Address::privatePort = privatePort;
}

void Address::setPublicIP(unsigned int publicIP) {
    Address::publicIP = publicIP;
}

void Address::setPublicPort(unsigned short publicPort) {
    Address::publicPort = publicPort;
}

Address::Address() {
    publicIP = publicPort = privateIP = privatePort = 0;

}
