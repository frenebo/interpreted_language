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
        break;
    case TokenType::PERIOD_CH:
        std::cout << "Period Token\n";
        break;
    case TokenType::OPEN_PAREN_CH:
        std::cout << "Open Parenthesis Token\n";
        break;
    case TokenType::CLOSE_PAREN_CH:
        std::cout << "Close Parenthesis Token\n";
        break;
    case TokenType::OPEN_BRACE_CH:
        std::cout << "Open Brace Token\n";
        break;
    case TokenType::CLOSE_BRACE_CH:
        std::cout << "Close Brace Token\n";
        break;
    case TokenType::MINUS_CH:
        std::cout << "Minus Sign Token\n";
        break;
    case TokenType::PLUS_CH:
        std::cout << "Plus Sign Token\n";
        break;
    case TokenType::DIVIDE_CH:
        std::cout << "Divide Sign Token\n";
        break;
    case TokenType::ASTERISK_CH:
        std::cout << "Asterisk Token\n";
        break;
    case TokenType::EQUALS_CH:
        std::cout << "Equals sign Token" << "\n";
        break;
    case TokenType::IDENTIFIER:
        std::cout << "Identifier Token: " << tok.get_contents() << "\n";
        break;
    case TokenType::NUMBER:
        std::cout << "Number Token: " << tok.get_contents() << "\n";
        break;
    default:
        std::cout << "Unimplemented token log\n";
    }
}