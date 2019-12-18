//
// Created by shaiac on 17/12/2019.
//

#ifndef EX3_SYMBOLTABLE_H
#define EX3_SYMBOLTABLE_H
#include <string>
#include <map>

using namespace std;
struct var {
    float value;
    string sim;
    string condition;
};

class SymbolTables {
private:
    map<string,var> simulatorVars;
    map<string,var> programVars;
public:
    SymbolTables();
    void initializeSimulator();
    var getVar(string name);
    void setProgramVars(string, var);
    void updateSimulatorVars(string);
    void updateVarValue(string, float);
};
#endif //EX3_SYMBOLTABLE_H
