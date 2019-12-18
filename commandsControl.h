//
// Created by shaiac on 17/12/2019.
//

#ifndef EX3_COMMANDSCONTROL_H
#define EX3_COMMANDSCONTROL_H
#include "commands.h"

class Parser {
protected:
    string* lexer;
    map<string, Command*> commandsMap;
public:
    Parser();
    void initializeCommandsMap();
    void runCommands();
};

#endif //EX3_COMMANDSCONTROL_H
