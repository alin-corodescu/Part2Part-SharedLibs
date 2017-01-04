//
// Created by alin on 12/30/16.
//

#include "../include/FileDescription.h"

FileDescription::FileDescription() {

}

int FileDescription::getFileSize() {
    return size;
}

std::string FileDescription::getFileName() {
    return file_name;
}

std::string FileDescription::getHash() {
    return hash;
}

std::string FileDescription::toString() {
    using std::string;
    string data;
    data.append("{\n");
    data.append(jsonFormat("name",file_name));
    data.append(jsonFormat("description",description));
    data.append(jsonFormat("size",size));
    data.append(jsonFormat("hash",hash));
    data.append(jsonFormat("type",type,true));
    data.append("}\n");
    return data;
}

bool FileDescription::operator<(const FileDescription &fileDescription) const {
    return hash < fileDescription.hash;
}

std::string FileDescription::jsonFormat(std::string key, std::string value, bool last) {
    std::string format;
    format.append(key);
    format.append(" : ");
    format.append("\"");
    format.append(value);
    format.append("\"");
    if (last) format.append("\n");
    else format.append(",\n");
    return format;
}

std::string FileDescription::jsonFormat(std::string key, int value,bool last) {
    char number[10];
    sprintf(number,"%d",value);

    std::string format;
    format.append(key);
    format.append(" : ");
    format.append(number);
    if (last) format.append("\n");
    else format.append(",\n");
    return format;
}

const std::string &FileDescription::getDescription() const {
    return description;
}

const std::string &FileDescription::getType() const {
    return type;
}
