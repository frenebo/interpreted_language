#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "../tokens/tokens.hpp"
#include <string>
#include <vector>
#include <optional>
#include <map>
#include <string>
#include <variant>

namespace tokenizer
{
    class TokenizerException: public std::exception {
    private:
        std::string message_;
    public:
        explicit TokenizerException(const std::string& message) : message_(message) {};
        virtual const char* what() const throw() {
            return message_.c_str();
        }
    };

    class TokenizerResult
    {
    private:
        std::vector<Token> _tokens;
    public:
        TokenizerResult(std::vector<Token> tokens);
        const std::vector<Token> & tokens() const;
    };

    class Tokenizer
    {
    private:
        std::map<TokenType, std::string> simple_tok_strings;
        std::optional<Token> try_match_longest_simple_token(const std::string & input_str, unsigned long input_start_idx) const;
        std::optional<Token> try_match_longest_token(const std::string & input_str, unsigned long input_start_idx) const;
    public:
        Tokenizer();
        TokenizerResult tokenize(const std::string & input_str) const;
    };
}

#endif
