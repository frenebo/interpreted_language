#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "tokens.hpp"
#include <string>
#include <vector>
#include <optional>
#include <map>
#include <string>
#include <exception>

class TokenizerException: public std::exception {
private:
    std::string message_;
public:
    explicit TokenizerException(const std::string& message) : message_(message) {};
    virtual const char* what() const throw() {
        return message_.c_str();
    }
};

class Tokenizer
{
private:
    std::map<TokenType, std::string> simple_tok_strings;
    std::optional<Token> try_match_longest_simple_token(const std::string & input_str, unsigned long input_start_idx) const;
    std::optional<Token> try_match_longest_token(const std::string & input_str, unsigned long input_start_idx) const;
public:
    Tokenizer();
    std::vector<Token> tokenize(const std::string & input_str) const;
};

#endif