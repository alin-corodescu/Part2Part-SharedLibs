//
// Created by alin on 12/26/16.
//
#pragma once
#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H
#define COMM_LENGTH 13

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
    TRANSFERRING
};

const char* commandName(CommandTypes type);
class Command {
public:
    int toString(char* buffer);
    int length();
};


#endif //CLIENT_COMMAND_H
