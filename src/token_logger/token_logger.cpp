#include "token_logger.hpp"

#include <vector>
#include "../tokens.hpp"
#include <iostream>

void TokenLogger::log_tokens(const std::vector<Token> & toks)
{
    for (Token i : toks)
    {
        TokenLogger::log_token(i);
    }
}

void TokenLogger::log_token(const Token & tok)
{
    switch (tok.get_type())
    {
    case TokenType::SEMICOLON_CH:
        std::cout << "Semicolon Token\n";
        return;
    case TokenType::PERIOD_CH:
        std::cout << "Period Token\n";
        return;
    case TokenType::OPEN_PAREN_CH:
        std::cout << "Open Parenthesis Token\n";
        return;
    case TokenType::CLOSE_PAREN_CH:
        std::cout << "Close Parenthesis Token\n";
        return;
    case TokenType::OPEN_BRACE_CH:
        std::cout << "Open Brace Token\n";
        return;
    case TokenType::CLOSE_BRACE_CH:
        std::cout << "Close Brace Token\n";
        return;
    case TokenType::MINUS_CH:
        std::cout << "Minus Sign Token\n";
        return;
    case TokenType::PLUS_CH:
        std::cout << "Plus Sign Token\n";
        return;
    case TokenType::DIVIDE_CH:
        std::cout << "Divide Sign Token\n";
        return;
    case TokenType::ASTERISK_CH:
        std::cout << "Asterisk Token\n";
        return;
    case TokenType::EQUALS_CH:
        std::cout << "Equals sign Token" << "\n";
        return;
    case TokenType::IDENTIFIER:
        std::cout << "Identifier Token: " << tok.get_contents() << "\n";
        return;
    case TokenType::NUMBER:
        std::cout << "Number Token: " << tok.get_contents() << "\n";
        return;
    default:
        std::cout << "Unimplemented token log\n";
    }
}