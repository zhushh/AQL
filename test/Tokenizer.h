#ifndef __TOKENIZER__
#define __TOKENIZER__

#include <vector>
#include <string>

typedef struct Document_token {
    int from;
    int to;
    std::string text;
    Document_token(std::string w, int f, int t) : text(w), from(f), to(t) {}
} Document_token;

class Tokenizer {
private:
    std::vector<Document_token> document_tokens;
    std::string document_text;
public:
    Tokenizer(const char* file_path);
    ~Tokenizer();
    std::vector<Document_token> get_document_tokens();
    std::string get_document_text();
};

#endif
