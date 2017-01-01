//
// Created by alin on 12/21/16.
//

#include <netinet/in.h>
#include "../include/CommandBuilder.h"

Command CommandBuilder::build() {
    return *stub;
}

void CommandBuilder::setType(CommandTypes t) {
    stub = new Command(t);
}

void CommandBuilder::addArgument(CommandArgument *arg) {
    using std::string;
    string data = arg->toString();
    addArgument(data.size());
    stub->buffer.append(data);
}

void CommandBuilder::addArgument(unsigned int number) {
    unsigned int networkByteOrder = htonl(number);
    char* nr = (char*) &networkByteOrder;
    stub->buffer.append(nr,sizeof(unsigned int));
}

void CommandBuilder::addArgmuent(unsigned short number) {
    unsigned short networkByteOrder = htons(number);
    char* nr = (char*) &networkByteOrder;
    stub->buffer.append(nr,sizeof(unsigned short));
}
