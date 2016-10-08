#ifndef __PARSER__
#define __PARSER__

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
using namespace std;

#include "Lexer.h"
#include "Tokenizer.h"

class View {
private:
    std::string name_;
    std::map<std::string, std::vector<Document_token> > tables;
public:
    View(std::string name) : name_(name) {}
    void put(std::string name, std::vector<Document_token> document_tokens) {
        tables[name] = document_tokens;
    }
    std::vector<Document_token> get(std::string name) {
        return tables[name];
    }

    void show_line(const std::vector<int>& v) {
        std::cout << "+-";
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i]; j++) {
                std::cout << "-";
            }
            std::cout << "-+";
        }
        std::cout << std::endl;
    }
    void show() {
        std::cout << "View: " << name_ << std::endl;
        if (!tables.empty()) {
            vector<int> widths;
            for (auto ptr = tables.begin(); ptr != tables.end(); ptr++) {
                int max_width = 0;
                for (auto i : (ptr->second)) {
                    if (i.to - i.from > max_width) {
                        max_width = i.to - i.from;
                    }
                }
                widths.push_back(max_width);
            }

            show_line(widths);
            // int k = 0;
            // for (auto ptr = tables.begin(); ptr != tables.end(); ptr++, k++) {
            //     std::cout << "| ";
            //     std::cout << std::left << std::setw(widths[k]) << ptr->first;
            //     std::cout << " ";
            // }
            // show_line(widths);
            // // show document_token data
            // int rows = ((tables.begin())->second).size();
            // for (int i = 0; i < rows; i++) {
            //     for (auto ptr = tables.begin(); ptr != tables.end(); ptr++) {
            //         Document_token t = (ptr->second)[i];
            //         std::cout << "| ";
            //         std::cout << std::left << std::setw(widths[i]) << t.text << ":(" << t.from << ", " << t.to << ")";
            //         std::cout << " ";
            //     }
            //     std::cout << "|" << std::endl;
            // }
            // show_line(widths);
        }
    }
};

#endif
