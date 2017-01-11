//
// Created by alin on 12/21/16.
//

#include <cstring>
#include <fstream>
#include "../include/FileDescription.h"
#include "../include/FileDescriptionBuilder.h"

FileDescription* FileDescriptionBuilder::buildFromString(char *string) {

    char name[255],desc[500],size[10],hash[50],type[20];

    char *p = strtok(string,"\"");
    p = strtok(NULL,"\"");
    strcpy(name,p);
    p = strtok(NULL,"\"");
    p = strtok(NULL,"\"");
    strcpy(desc,p);
    p = strtok(NULL,"\"");
    p = strtok(NULL,"\"");
    strcpy(size,p);
    p = strtok(NULL,"\"");
    p = strtok(NULL,"\"");
    strcpy(hash,p);
    p = strtok(NULL,"\"");
    p = strtok(NULL,"\"");
    strcpy(type,p);

    stub = new FileDescription();
    stub->size = atoi(size);
    stub->description = std::string(desc);
    stub->file_name = std::string(name);
    stub->hash = std::string(hash);
    stub->type = std::string(type);

    return stub;
    //FileDescription fd;
}

FileDescription* FileDescriptionBuilder::readFromFile(FILE *&file) {
    char * buffer;
    long size;
    long offset = ftell(file);
    fseek( file, 0L , SEEK_END);
    size = ftell( file ) - offset;
    rewind( file );
    fseek(file, offset, SEEK_SET);

    buffer = (char*) calloc( 1, size+1 );
    fread( buffer , size, 1 , file);

    fclose(file);
    stub = buildFromString(buffer);
    free(buffer);
    return stub;
}

void FileDescriptionBuilder::init() {
    stub = new FileDescription();
}

void FileDescriptionBuilder::addName(const char *name) {
    stub->file_name= std::string(name);
}

void FileDescriptionBuilder::addSize(int size) {
    stub->size = size;
}

void FileDescriptionBuilder::addHash(const char *hash) {
    stub->hash = std::string(hash);
}

void FileDescriptionBuilder::addType(const char *type) {
    stub->type = std::string(type);
}

void FileDescriptionBuilder::addDescription(const char *description) {
    stub->description = std::string(description);
}

FileDescription *FileDescriptionBuilder::build() {
    return stub;
}
