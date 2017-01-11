//
// Created by alin on 12/21/16.
//

#include <netinet/in.h>
#include "../include/CommandBuilder.h"

Command* CommandBuilder::build() {
    return stub;
}

void CommandBuilder::setType(CommandTypes t) {
    stub = new Command(t);
}

void CommandBuilder::addArgument(CommandArgument *arg) {
    using std::string;
    string data = arg->toString();
    addArgument(data.size(),INT);
    stub->buffer.append(data);
}

void CommandBuilder::addArgument(unsigned int number,int type) {
    if (type == INT) {
        unsigned int networkByteOrder = htonl(number);
        char *nr = static_cast<char*>(static_cast<void*> (&networkByteOrder));
        stub->buffer.append(nr, sizeof(unsigned int));
    }

    if (type == SHORT) {
        unsigned short networkByteOrder = htons(number);
        char *nr = static_cast<char*>(static_cast<void*> (&networkByteOrder));
        stub->buffer.append(nr, sizeof(unsigned short));
    }
}
