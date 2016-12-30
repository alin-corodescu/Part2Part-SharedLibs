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
    std::string file_name;
    std::string hash;
    std::string description;
    std::string type;
    std::string jsonFormat(std::string key, std::string value,bool last = true);
    std::string jsonFormat(std::string key, int value, bool last = false);
public:
    int getFileSize();
    std::string getFileName();
    std::string getHash();
    std::string toString();
    bool operator<(const FileDescription& fileDescription) const;
};
