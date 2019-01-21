#include "token_logger.hpp"

#include <vector>
#include "../tokens.hpp"
#include <iostream>

void TokenLogger::log_tokens(std::vector<Token> toks)
{
    for (Token i : toks)
    {
        TokenLogger::log_token(i);
    }
}

void TokenLogger::log_token(Token tok)
{
    switch (tok)
    {
    case Token::SEMICOLON_CH:
        std::cout << "Semicolon Token" << std::endl;
        return;
    default:
        std::cout << "Unimplemented token log" << std::endl;
    }
}