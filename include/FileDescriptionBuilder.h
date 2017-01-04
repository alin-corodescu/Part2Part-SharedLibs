//
// Created by alin on 12/21/16.
//
#pragma once
#ifndef CLIENT_FILEDESCRIPTIONBUILDER_H
#define CLIENT_FILEDESCRIPTIONBUILDER_H


#include <FileDescription.h>
#include "FileDescription.h"

class FileDescriptionBuilder {
private:
    FileDescription* stub;
public:
    FileDescription* buildFromString(char* string);
    FileDescription* readFromFile(FILE* file);
    void init();
    void addName(const char* name);
    void addSize(int size);
    void addHash(const char* hash);
    void addType(const char* type);
    void addDescription(const char* description);
    FileDescription* build();
};


#endif //CLIENT_FILEDESCRIPTIONBUILDER_H
