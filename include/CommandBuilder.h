//
// Created by alin on 12/21/16.
//

#ifndef CLIENT_COMMANDBUILDER_H
#define CLIENT_COMMANDBUILDER_H


#include "Command.h"
#include "CommandArgument.h"

class CommandBuilder {
private:

public:
    Command build();
    void setType(CommandTypes t);
    void addArgument(CommandArgument& arg);
};


#endif //CLIENT_COMMANDBUILDER_H
