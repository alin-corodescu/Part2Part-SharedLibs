#include "CommandArgument.h"
#include <string>
#pragma once
class FileDescription : public CommandArgument
{
    friend class FileDescriptionBuilder;
    friend class FileReader;
    friend class FileWriter;
private:
    FileDescription();
    int size;
    char* file_name;
    std::string hash;
public:
    int getFileSize();
    char* getFileName();
    std::string getHash();
    std::string toString();
    bool operator<(const FileDescription& fileDescription) const;
};
