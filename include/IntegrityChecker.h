//
// Created by alin on 12/30/16.
//

#ifndef SHARED_LIBRARIES_INTEGRITYCHECKER_H
#define SHARED_LIBRARIES_INTEGRITYCHECKER_H
#include <string>
#include "FileDescription.h"

class IntegrityChecker
{
    friend class FileDescriptionBuilder;
private:
    static std::string hashForFile(const char* path);
public:
    static bool checkIntegrity(FileDescription fileDescription, const char* path);
};
#endif //SHARED_LIBRARIES_INTEGRITYCHECKER_H
