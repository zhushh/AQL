#ifndef __LEXER__
#define __LEXER__

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include "Token.h"

class Lexer {
private:
    int line;
    int column;
    std::map<std::string, Tag> keywords;
    char peek;
    std::ifstream fin;
public:
    Lexer(const std::string& in);
    ~Lexer();
    bool canMove();
    void getchar();
    bool readch(char c);
    Token scan();
};

#endif