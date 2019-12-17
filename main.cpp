#include <iostream>
#include "lexer.h"

int main() {
    lexer l;
    l.ReadFile("fly.txt");
    l.Print();
    return 0;
}