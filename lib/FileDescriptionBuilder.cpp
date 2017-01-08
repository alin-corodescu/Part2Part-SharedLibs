//
// Created by alin on 12/21/16.
//

#include "../include/FileDescription.h"
#include "../include/FileDescriptionBuilder.h"

FileDescription* FileDescriptionBuilder::buildFromString(char *string) {
    FileDescription fd;
}

FileDescription* FileDescriptionBuilder::readFromFile(FILE *file) {
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
