//
// Created by alin on 12/27/16.
//

#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>
#include "../include/IOWrappers.h"

void readUInt(int socketDescriptor, unsigned int &integer) {
    int status;
    size_t size = 4;
    status = read(socketDescriptor, &integer, size);
    if (status < sizeof(unsigned int)) {
    //error occured
        if (status == -1) {

        }
    } else {
        integer = ntohl(integer);
    }
}

char* readString(int socketDescriptor, unsigned int size)
{
    char* buffer = (char*) malloc(size);

    int status;

    status = read(socketDescriptor, buffer, size);


    return buffer;
}