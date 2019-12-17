//
// Created by omer on 16.12.2019.
//
#include <fstream>
#include <iostream>
#include "lexer.h"

using namespace std;

void lexer::SepALine(string line) {
    int i = 0;
    string single = "";
    bool isequal = false;
    bool isgeresh = false;
    while (true) {
        char check = line[i];
        if (check == '!') {
            if (line[i + 1] == '=') {
                if (single != "") {
                    this->cmdAndPr.push_back(single);
                }
                this->cmdAndPr.push_back("!=");
                i += 2;
                single = "";
                continue;
            }
        }
        if (line[i + 1] == '{' || line[i + 1] == '}') {
            if (single != "") {
                if (check != ' ') {
                    single += check;
                }
                this->cmdAndPr.push_back(single);
            }
            single = "";
            i++;
            continue;
        }
        if (check == '>' || check == '<') {
            if (line[i - 1] != '-' && line[i + 1] != '-') {
                if (single != "") {
                    this->cmdAndPr.push_back(single);
                }
                single = line[i];
                if (line[i + 1] == '=') {
                    single += '=';
                    i++;
                }
                this->cmdAndPr.push_back(single);
                isequal = true;
            } else {
                if (line[i - 1] == '-') {
                    if (single != "" && single != "-") {
                        single.erase(single.size() - 1);
                        this->cmdAndPr.push_back(single);
                    }
                    single = "->";
                    this->cmdAndPr.push_back(single);
                } else if (line[i + 1] == '-') {
                    if (single != "") {
                        this->cmdAndPr.push_back(single);
                    }
                    i++;
                    single = "<-";
                    this->cmdAndPr.push_back(single);
                }
            }
            single = "";
            i++;
            continue;
        }
        if (check == '=') {
            if (single != "") {
                this->cmdAndPr.push_back(single);
            }
            single = "=";
            if (line[i + 1] == '=') {
                single += '=';
                i++;
            }
            this->cmdAndPr.push_back(single);
            single = "";
            isequal = true;
            i++;
            continue;
        }
        if (check == '"') {
            if (isgeresh) {
                single += 34;
                this->cmdAndPr.push_back(single);
                isgeresh = false;
                single = "";
            } else if (!isgeresh) {
                if (single != "") {
                    this->cmdAndPr.push_back(single);
                }
                single = "";
                single += 34;
                isgeresh = true;
            }
            i++;
            continue;
        }
        if (check == '\n' || check == '\000') {
            if (single != "") {
                this->cmdAndPr.push_back(single);
            }
            break;
        }
        if ((check == ' ' || check == ',' || check == '(' || check == ')' || check == '\t') && (!isequal) &&
            (!isgeresh)) {
            if (single != "") {
                this->cmdAndPr.push_back(single);
            }
            single = "";
            i++;
            continue;
        }
        if (single == "" && check == ' ') {
            i++;
            continue;
        }
        single += line[i];
        i++;
    }
}

void lexer::ReadFile(const char *file_path) {
    ifstream file;
    file.open(file_path);
    if (!file.is_open()) {
        throw "bad file";
    }
    string line;
    string sep = "";
    while (getline(file, line)) {
        this->SepALine(line);
    }
    file.close();
}

void lexer::Print() {
    list<string>::iterator b = this->cmdAndPr.begin();
    while (b != this->cmdAndPr.end()) {
        cout << (b.operator*()) + '\n';
        b++;
    }
}
