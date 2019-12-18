#include <netinet/in.h>
#include <zconf.h>
#include <sstream>
#include <map>
#include "commands.h"
#include "symbolTable.h"
#include "sys/socket.h"
#include <arpa/inet.h>
#define PORT 5400

//
// Created by shaiac on 16/12/2019.
//

Command::Command() {
    this->symbolTable = new SymbolTables();
}

/**
 * openning the server reading data and updating.
 */
int OpenServerCommand::execute(vector<string>) {
        char buffer[1024] = {0};
        int client_socket, valread;
        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1) {
            cerr << "Error, couldn't open a socket" << endl;
            exit(-1);
        }
        sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);
        if (bind(socketfd, (struct sockaddr*) &address, sizeof(address)) < 0) {
            cerr << "Error, couldn't bind the socket to an IP" << endl;
            exit(-2);
        }
        if (listen(socketfd, 5) < 0)
        {
            cerr << "Error, during the listening command" << endl;
            exit(-3);
        }
        if ((client_socket = accept(socketfd, (struct sockaddr *)&address,
                                    (socklen_t*)&address)) < 0)
        {
            cerr << "Error, during accepting client" << endl;
            exit(-4);
        }
        while(true) {
        valread = read( client_socket , buffer, 1024);
        this->symbolTable->updateSimulatorVars(buffer);
        }
        return 2;
}

int ConnectCommand::execute(vector<string> v ) {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        cerr << "Error, couldn't open a socket" << endl;
        exit(-1);
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(PORT);
    int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
    if (is_connect == -1) {
        cerr << "Error, couldn't connect to host server" << endl;
        exit(-2);
    }
    return 3;
    //int is_sent = send(client_socket, "ddd", strlen(), 0);
}

DefineVarCommand::DefineVarCommand() {
}

int DefineVarCommand::execute(vector<string> v) {
    this->symbolTable->setProgramVars(v.at(0), {0, v.at(2), v.at(1) });
    return 5;
}

int PrintCommand::execute(vector<string> v) {
    cout << v.front() <<endl;
    return 2;
}

int SleepCommand::execute(vector<string> v ) {
    sleep(stof(v.front()));
}

void Command::parser(string lexer[]) {
    int index = 0;
}