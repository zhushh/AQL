#include <iostream>
#include <fstream>
#include <cctype>
#include "Lexer.h"

Lexer::Lexer(const std::string& in) {
    fin.open(in.c_str(), std::ifstream::in);
    peek = ' ';
    line = column = 0;
    keywords["create"] = CREATE;
    keywords["view"] = VIEW;

    keywords["as"] = AS;
    keywords["output"] = OUTPUT;
    keywords["alias"] = ALIAS;
    keywords["select"] = SELECT;

    keywords["from"] = FROM;
    keywords["extract"] = EXTRACT;
    keywords["regex"] = REGEX;

    keywords["on"] = ON;
    keywords["column"] = COLUMN;
    keywords["return"] = RETURN;

    keywords["and"] = AND;
    keywords["group"] = GROUP;

    keywords["pattern"] = PATTERN;
    keywords["token"] = TOKEN;
}
Lexer::~Lexer() { fin.close(); }
bool Lexer::canMove() { return !(fin.eof()); }
void Lexer::getchar() { column++; fin.get(peek); }
bool Lexer::readch(char c) {
    if (peek != c) return false;
    peek = ' ';
    return true;
}
Token Lexer::scan() {
    for (;; getchar()) {
        if (peek == ' ' || peek == '\t') continue;
        if (peek == '\n') line++;
        else break;
    }
    if (readch('{')) return Token("{", LB_L);
    if (readch('}')) return Token("}", RB_L);
    if (readch('(')) return Token("(", LB_S);
    if (readch(')')) return Token(")", RB_S);
    if (readch('<')) return Token("<", LB_M);
    if (readch('>')) return Token(">", RB_M);
    if (readch('.')) return Token(".", DOT);
    if (readch(',')) return Token(",", COMMA);
    if (readch(';')) return Token(";", SIMICOLON);
    if (readch('/')) {
        std::string w = "";
       for (getchar(); peek != '/'; getchar()) {
            if (peek == '\\') {
                w.push_back('\\');
                getchar();
            }
            w.push_back(peek);
       }
       getchar();
       return Token(w, REG);
    }
    if (isdigit(peek)) {
        std::string num = "";
        while (isdigit(peek)) {
            num.push_back(peek);
            getchar();
        }
        return Token(num, NUM);
    }

    std::string keyword = "";
    while (isalnum(peek) || peek == '_') {
        keyword.push_back(peek);
        getchar();
    }
    if (keywords.find(keyword) == keywords.end()) {
        return Token(keyword, ID);
    } else {
        return Token(keyword, keywords[keyword]);
    }
}