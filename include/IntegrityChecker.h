//
// Created by alin on 12/30/16.
//

#ifndef SHARED_LIBRARIES_INTEGRITYCHECKER_H
#define SHARED_LIBRARIES_INTEGRITYCHECKER_H
#include <string>

class IntegrityChecker
{
private:
    std::string hashForFile(const char* path);
};
#endif //SHARED_LIBRARIES_INTEGRITYCHECKER_H
