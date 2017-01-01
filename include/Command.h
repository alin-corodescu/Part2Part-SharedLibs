//
// Created by alin on 12/26/16.
//
#pragma once
#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H
#define COMM_LENGTH 14
#include <string>

enum CommandTypes {
    QUERY,
    JOIN,
    PUBLISH,
    FIND,
    UNPUBLISH,
    NOTIFIY,
    BYE,
    RESULTS,
    REQUEST,
    OPEN,
    PROVIDE,
    TRANSFERRING,
    HEARTBEAT,
    IDENTITY;
};

const char* commandName(CommandTypes type);
class Command {
    friend class CommandBuilder;
    //the builder will add other arguments
private:
    CommandTypes type;
    std::string buffer;
    Command(CommandTypes type);
public:
    int toString(char* buffer);
    int length();
};


#endif //CLIENT_COMMAND_H
