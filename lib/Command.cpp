//
// Created by alin on 12/26/16.
//

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
    }
}