//
// Created by shaiac on 17/12/2019.
//
#include "symbolTable.h"
#include <vector>

void SymbolTables::initializeSimulator() {
    this->simulatorVars["airspeed-indicator_indicated-speed-kt"] =
            {0, "airspeed-indicator_indicated-speed-kt"};
    this->simulatorVars["altimeter_indicated-altitude-ft"] =
            {0, "/instrumentation/altimeter/indicated-altitude-ft"};
    this->simulatorVars["altimeter_pressure-alt-ft"] =
            {0, "/instrumentation/altimeter/pressure-alt-ft"};
    this->simulatorVars["attitude-indicator_indicated-pitch-deg"] =
            {0, "/instrumentation/attitude-indicator/indicated-pitch-deg"};
    this->simulatorVars["attitude-indicator_indicated-roll-deg"] =
            {0, "/instrumentation/attitude-indicator/indicated-roll-deg"};
    this->simulatorVars["attitude-indicator_internal-pitch-deg"] =
            {0, "/instrumentation/attitude-indicator/internal-pitch-deg"};
    this->simulatorVars["attitude-indicator_internal-roll-deg"] =
            {0, "/instrumentation/attitude-indicator/internal-roll-deg"};
    this->simulatorVars["encoder_indicated-altitude-ft"] =
            {0, "instrumentation/encoder/indicated-altitude-ft"};
    this->simulatorVars["encoder_pressure-alt-ft"] =
            {0, "/instrumentation/encoder/pressure-alt-ft"};
    this->simulatorVars["gps_indicated-altitude-ft"] =
            {0, "/instrumentation/gps/indicated-altitude-ft"};
    this->simulatorVars["gps_indicated-ground-speed-kt"] =
            {0, "/instrumentation/gps/indicated-ground-speed-kt"};
    this->simulatorVars["gps_indicated-vertical-speed"] =
            {0, "/instrumentation/gps/indicated-vertical-speed"};
    this->simulatorVars["indicated-heading-deg"] =
            {0, "/instrumentation/heading-indicator/indicated-heading-deg"};
    this->simulatorVars["magnetic-compass_indicated-heading-deg"] =
            {0, "/instrumentation/magnetic-compass/indicated-heading-deg"};
    this->simulatorVars["slip-skid-ball_indicated-slip-skid"] =
            {0, "/instrumentation/slip-skid-ball/indicated-slip-skid"};
    this->simulatorVars["turn-indicator_indicated-turn-rate"] =
            {0, "/instrumentation/turn-indicator/indicated-turn-rate"};
    this->simulatorVars["vertical-speed-indicator_indicated-speed-fpm"] =
            {0, "/instrumentation/vertical-speed-indicator/indicated-speed-fpm"};
    this->simulatorVars["flight_aileron"] =
            {0, "/controls/flight/aileron"};
    this->simulatorVars["flight_elevator"] =
            {0, "/controls/flight/elevator"};
    this->simulatorVars["flight_rudder"] =
            {0, "/controls/flight/rudder"};
    this->simulatorVars["flight_flaps"] =
            {0, "/controls/flight/flaps"};
    this->simulatorVars["engine_throttle"] =
            {0, "/controls/engines/engine/throttle"};
    this->simulatorVars["engine_rpm"] =
            {0, "/engines/engine/rpm"};
}

SymbolTables::SymbolTables() {
    this->initializeSimulator();
}

/**
 * spliting a string by "," returning a vector.
 */
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    res.push_back (s.substr (pos_start));
    return res;
}

/**
 * updating the symbol table for each info from the app.
 */
void SymbolTables::updateSimulatorVars(string data) {
    vector<string> v = split(data, ",");
    map<string , var>::iterator it;
    for (it = this->simulatorVars.begin(); it != this->simulatorVars.end(); it++ )
    {
        it->second.value = stof(v.front());
        v.erase(v.begin());
    }
}

/**
 * Updating variable value.
 */
void SymbolTables::updateVarValue(string name, float val) {
    this->programVars[name].value = val;
}

void SymbolTables::setProgramVars(string name, var variable ) {
    this->programVars[name] = variable;
}
