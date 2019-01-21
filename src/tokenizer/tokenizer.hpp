#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "tokens.hpp"
#include <string>
#include <vector>

class Tokenizer
{
public:
    static std::vector<Token> tokenize(std::string input_str);
};

#endif