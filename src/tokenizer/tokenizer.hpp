#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "tokens.hpp"
#include <string>
#include <vector>
#include <optional>
#include <map>

class Tokenizer
{
private:
    std::map<TokenType, std::string> simple_tok_strings;
    std::optional<Token> try_match_longest_simple_token(const std::string & input_str, long input_start_idx) const;
    std::optional<Token> try_match_longest_token(const std::string & input_str, long input_start_idx) const;
public:
    Tokenizer();
    std::vector<Token> tokenize(const std::string & input_str) const;
};

#endif