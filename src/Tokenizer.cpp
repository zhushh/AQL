#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

#include "Tokenizer.h"

Tokenizer::Tokenizer(const char* file_path) {
    std::ifstream fin(file_path, std::ifstream::in);
    int cur = 0;
    char top = ' ';
    for (;;) {
        if (fin.eof()) break;
        while (top == ' ' || top == '\t' || top == '\n') { cur++, fin.get(top); document_text.push_back(top); }

        if (isdigit(top)) {
            int from = cur;
            std::string number = "";
            for (; isdigit(top); fin.get(top), cur++) {
                number.push_back(top);
                document_text.push_back(top);
            }
            document_tokens.push_back(Document_token(number, from, cur));
        }
        else if (isalpha(top)) {
            int from = cur;
            std::string word = "";
            for (; isalpha(top); fin.get(top), cur++) {
                word.push_back(top);
                document_text.push_back(top);
            }
            document_tokens.push_back(Document_token(word, from, cur));
        }
        else {
            std::string s = "";
            s.push_back(top);
            document_text.push_back(top);
            document_tokens.push_back(Document_token(s, cur, cur+1));
            top = ' ';
        }
    }
}
Tokenizer::~Tokenizer() {}

std::vector<Document_token> Tokenizer::get_document_tokens() {
    return document_tokens;
}

std::string Tokenizer::get_document_text() {
    return document_text;
}