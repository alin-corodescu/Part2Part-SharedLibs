//
// Created by alin on 12/26/16.
//

#include <cstring>
#include <cstdlib>
#include "../include/Command.h"

const char *commandName(CommandTypes type) {
    switch (type) {
        case QUERY:
            return "QUERY";
        case JOIN:
            return "JOIN";
        case PUBLISH:
            return "PUBLISH";
        case FIND:
            return "FIND";
        case UNPUBLISH:
            return "UNPUBLISH";
        case NOTIFIY:
            return "NOTIFIY";
        case BYE:
            return "BYE";
        case RESULTS:
            return "RESULTS";
        case REQUEST:
            return "REQUEST";
        case OPEN:
            return "OPEN";
        case PROVIDE:
            return "PROVIDE";
        case TRANSFERRING:
            return "TRANSFERRING";
        case HEARTBEAT:
            return "HEARTBEAT";
        case IDENTITY:
            return "IDENTITY";
    }
}

int Command::toString(char*& buffer) {
    int i;
    for (i = 0; i < this->buffer.size(); i++)
        buffer[i] = this->buffer.at(i);
    return this->buffer.size();
}

Command::Command(CommandTypes type) {
    this->type = type;
    int cmdLength = strlen(commandName(type));
    buffer.append(commandName(type));
    int i;
    for (i = cmdLength + 1; i <= COMM_LENGTH; i++)
        buffer.push_back('\0');
}


int Command::length() {
    return buffer.size();
}
