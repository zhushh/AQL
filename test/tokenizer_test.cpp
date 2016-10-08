#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Tokenizer.h"

int main()
{
    const char *file = "../dataset/perloc/PerLoc.input";
    Tokenizer tok(file);
    vector<Document_token> v = tok.get_document_tokens();
    for (auto i : v) {
        cout << i.text << ": (" << i.from << ", " << i.to << ")" << endl;
    }
    cout << tok.get_document_text() << endl;
    return 0;
}