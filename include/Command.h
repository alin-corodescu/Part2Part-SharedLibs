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

const char* commandName(CommandTypes type) {
    switch (type)
    {
        case QUERY: return "QUERY";
        case JOIN: return "JOIN";
        case PUBLISH: return "PUBLISH";
        case FIND: return "FIND";
        case UNPUBLISH: return "UNPUBLISH";
        case NOTIFIY: return "NOTIFIY";
        case BYE: return "BYE";
        case RESULTS: return "RESULTS";
        case REQUEST: return "REQUEST";
        case OPEN: return "OPEN";
        case PROVIDE: return "PROVIDE";
        case TRANSFERRING: return "TRANSFERRING";
    }
}
class Command {
public:
    int toString(char* buffer);
    int length();
};


#endif //CLIENT_COMMAND_H
