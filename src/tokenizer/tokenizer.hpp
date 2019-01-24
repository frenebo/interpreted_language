#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "tokens.hpp"
#include <string>
#include <vector>
#include <optional>
#include <map>
#include <string>
#include <variant>

namespace tokenizer
{
    class TokenizerResult
    {
    private:
        std::vector<Token> _tokens;
    public:
        TokenizerResult(std::vector<Token> tokens);
        std::vector<Token> tokens() const;
    };
    
    class TokenizerErrorReturn
    {
    private:
        std::string _message;
    public:
        TokenizerErrorReturn(std::string message);
        void print_error() const;
    };

    class Tokenizer
    {
    private:
        std::map<TokenType, std::string> simple_tok_strings;
        std::optional<Token> try_match_longest_simple_token(const std::string & input_str, unsigned long input_start_idx) const;
        std::optional<Token> try_match_longest_token(const std::string & input_str, unsigned long input_start_idx) const;
    public:
        Tokenizer();
        std::variant<TokenizerResult, TokenizerErrorReturn> tokenize(const std::string & input_str) const;
    };
}

#endif