#pragma once
#include "FileDescription.h"
void readUInt(int socketDescriptor, unsigned int &integer);

char* readString(int socketDescriptor, unsigned int size);

void readUShort(int socketDescriptor, unsigned short &shrt);

void readULLInt(int socketDescriptor,unsigned long long &llint);

void writeString(int socketDescriptor,char* buffer, unsigned int count);
