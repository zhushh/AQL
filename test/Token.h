#ifndef __WORD__
#define __WORD__

#include <string>

enum Tag {
    CREATE, VIEW, ID, AS, OUTPUT, ALIAS, SELECT,
    FROM, EXTRACT, REGEX, REG, ON, COLUMN, RETURN, 
    AND, GROUP, NUM, PATTERN, TOKEN, TEMP, BACKSLASH, 
    DOT, COMMA, LB_L, RB_L, LB_M, RB_M, LB_S, RB_S,
    SIMICOLON
};

typedef struct Token {
    std::string word;
    Tag tag;
    Token(std::string w, Tag t) : word(w), tag(t) {}
} Token;

#endif

