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

int Command::toString(char *buffer) {

    bcopy(buffer,(char*) this->buffer.data(), this->buffer.size());
    return this->buffer.size();
}

Command::Command(CommandTypes type) {
    this->type = type;
    char *comm = (char*) malloc(COMM_LENGTH);
    comm[0] = 0;
    strcat(comm,commandName(type));
    buffer.append(comm);
    free(comm);
}

int Command::length() {
    return buffer.size();
}
