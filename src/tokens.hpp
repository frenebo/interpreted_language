#ifndef TOKENS_H
#define TOKENS_H

#include <string>

enum TokenType {
    SEMICOLON_CH,
    IDENTIFIER,
    WHITESPACE,
    MINUS_CH,
    PLUS_CH,
    DIVIDE_CH,
    ASTERISK_CH,
    EQUALS_CH,
    PERIOD_CH,
    NUMBER,
    OPEN_PAREN_CH,
    CLOSE_PAREN_CH,
    OPEN_BRACE_CH,
    CLOSE_BRACE_CH,
};

class Token
{
private:
    TokenType tok_type;
    std::string contents;
public:
    Token(TokenType tokType, std::string contents);
    TokenType get_type() const;
    std::string get_contents() const;
};

#endif