//
// Created by alin on 12/21/16.
//
#pragma once
#ifndef CLIENT_COMMANDBUILDER_H
#define CLIENT_COMMANDBUILDER_H


#include "Command.h"
#include "CommandArgument.h"
#define SHORT 1
#define INT 2
class CommandBuilder {
private:
    Command* stub;
public:
    Command* build();
    void setType(CommandTypes t);
    void addArgument(CommandArgument* arg);
    void addArgument(unsigned int,int type);
};


#endif //CLIENT_COMMANDBUILDER_H
