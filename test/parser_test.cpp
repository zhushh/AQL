#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
using namespace std;

#include "Parser.h"

int main()
{
    const char *file = "../dataset/perloc/PerLoc.input";
    Tokenizer tok(file);
    vector<Document_token> v = tok.get_document_tokens();
    View perView("PerLoc");
    perView.put("Percol", v);
    perView.show();
    return 0;
}