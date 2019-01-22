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