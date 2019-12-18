#include "commandsControl.h"

//
// Created by shaiac on 17/12/2019.
//
Parser::Parser() {
    //this->lexer = makelexer()
    this->initializeCommandsMap();
}

void Parser::initializeCommandsMap() {
    this->commandsMap["openDataServer"] = new OpenServerCommand;
    this->commandsMap["connectControlClient"] = new ConnectCommand;
    this->commandsMap["var"] = new DefineVarCommand;
    this->commandsMap["Print"] = new PrintCommand;
    this->commandsMap["Sleep"] = new SleepCommand;
    //this->commandsMap["while"] = new loopCommand;
    //this->commandsMap["if"] = new ifCommand;
}

void Parser::runCommands() {
    int index = 0;
    while (index < this->lexer->size()) {

    }
}