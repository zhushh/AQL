#include <iostream>
#include <map>
#include <string>
using namespace std;

#include "Lexer.h"

int main() {
    const char *aql = "PerLoc.aql";
    Lexer lex(aql);
    while (lex.canMove()) {
        cout << lex.scan().word << endl;
    }
    return 0;
}
