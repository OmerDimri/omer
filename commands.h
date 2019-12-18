//
// Created by shaiac on 16/12/2019.
//

#ifndef EX3_COMMANDS_H
#define EX3_COMMANDS_H
using namespace std;
#include "iostream"
#include "symbolTable.h"
#include <vector>
#include <list>
class Command {
protected:
    SymbolTables* symbolTable;
public:
    Command();
    virtual int execute(vector<string>);
    virtual ~Command() {}
};

class OpenServerCommand: public Command {
protected:

public:
    int execute(vector<string>);
    ~OpenServerCommand() override {}
};

class ConnectCommand: public Command {
protected:

public:
    int execute(vector<string>);
    ~ConnectCommand() override {}
};

class DefineVarCommand: public Command {
public:
    DefineVarCommand();
    int execute(vector<string>);
    ~DefineVarCommand() override {}
};

class PrintCommand: public Command {
public:
    int execute(vector<string>);
    ~PrintCommand() override {}
};

class SleepCommand: public Command {
public:
    int execute(vector<string>);
    ~SleepCommand() override {}
};
/**class ConditionParser: public Command {
protected:

public:
    int execute(vector<string>);
    ~ConditionParser() override {}
};

class IfCommand: public ConditionParser {
protected:

public:
    int execute(vector<string>);
    ~IfCommand() override {}
};

class LoopCommand: public ConditionParser {
protected:

public:
    int execute(vector<string>);
    ~LoopCommand() override {}
};
*/
#endif //EX3_COMMANDS_H
