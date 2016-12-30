//
// Created by alin on 12/27/16.
//
#pragma once
#ifndef CLIENT_COMMANDARGUMENT_H
#define CLIENT_COMMANDARGUMENT_H
#include <string>
/**
 * interface for classes that can be passed as argument
 */
class CommandArgument {
public:
    virtual std::string toString() = 0;
};


#endif //CLIENT_COMMANDARGUMENT_H
