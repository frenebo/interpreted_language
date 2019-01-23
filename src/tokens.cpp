#include "tokens.hpp"
#include <string>


Token::Token(TokenType tokenType, std::string contents)
{
    this->tok_type = tokenType;
    this->contents = contents;
}

TokenType Token::get_type() const
{
    return this->tok_type;
}

std::string Token::get_contents() const
{
    return this->contents;
}

std::string token_type_to_string(TokenType tok_type)
{
    switch (tok_type)
    {
    case TokenType::SEMICOLON_CH:
        return "Semicolon Character";
    case TokenType::IDENTIFIER:
        return "Identifier";
    case TokenType::WHITESPACE:
        return "Whitespace";
    case TokenType::MINUS_CH:
        return "Minus Sign";
    case TokenType::PLUS_CH:
        return "Plus Sign";
    case TokenType::DIVIDE_CH:
        return "Forward Slash";
    case TokenType::ASTERISK_CH:
        return "Asterisk";
    case TokenType::EQUALS_CH:
        return "Equals Sign";
    case TokenType::PERIOD_CH:
        return "Period";
    case TokenType::NUMBER:
        return "Number";
    case TokenType::OPEN_PAREN_CH:
        return "Open Parenthesis";
    case TokenType::CLOSE_PAREN_CH:
        return "Close Parenthesis";
    case TokenType::OPEN_BRACE_CH:
        return "Open Brace";
    case TokenType::CLOSE_BRACE_CH:
        return "Close Brace";
    }
}