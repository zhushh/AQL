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
        do {
            cur++;
            document_text.push_back(top);
        } while (fin.get(top) && (top == ' ' || top == '\t' || top == '\n'));

        if (fin.eof()) break;

        if (isdigit(top)) {
            int from = cur;
            std::string number = "";
            do {
                number.push_back(top);
                document_text.push_back(top);
                cur++;
            } while(fin.get(top) && isdigit(top));
            document_tokens.push_back(Document_token(number, from, cur));
        }
        else if (isalpha(top)) {
            int from = cur;
            std::string word = "";
            do {
                word.push_back(top);
                document_text.push_back(top);
                cur++;
            } while (fin.get(top) && isalpha(top));
            document_tokens.push_back(Document_token(word, from, cur));
        }
        else {
            document_text.push_back(top);
            document_tokens.push_back(Document_token(std::string{top}, cur, cur+1));
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