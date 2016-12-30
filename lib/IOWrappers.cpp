//
// Created by alin on 12/27/16.
//

#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>
#include "../include/IOWrappers.h"

void readUInt(int socketDescriptor, unsigned int &integer) {
    long long int status;
    size_t size = sizeof(unsigned int);
    status = read(socketDescriptor, &integer, size);
    if (status < sizeof(unsigned int)) {
    //error occured
        if (status == -1) {

        }
    } else {
        integer = ntohl(integer);
    }
}

void readUShort(int socketDescriptor, unsigned short &shrt)
{
    long long int status;
    size_t size = sizeof(unsigned short);
    status = read(socketDescriptor, &shrt, size);
    if (status < sizeof(unsigned int)) {
        //error occured
        if (status == -1) {

        }
    } else {
        shrt = ntohs(shrt);
    }
}
char* readString(int socketDescriptor, unsigned int size)
{
    char* buffer = (char*) malloc(size);

    long long int status;
    long long int done = 0;
    while (done < size) {
        status = read(socketDescriptor, buffer + done, size - done);
        if (status <= 0)
        {
            //treat errors.
            throw "something happened";
            break;
        }
        done += status;
    }


    return buffer;
}

void readULLInt(int socketDescriptor, unsigned long long &llint) {


}

void writeString(int socketDescriptor,char* buffer, unsigned int count) {
    long long int status;

    long long int done = 0;
    while (done < count)
    {
        status = write(socketDescriptor,buffer+done, count - (int)done);
        if (status <= 0)
        {
            throw "Something happened";
        }
        done += status;
    }


}
