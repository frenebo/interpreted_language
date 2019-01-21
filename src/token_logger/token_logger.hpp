#ifndef TOKEN_LOGGER_H
#define TOKEN_LOGGER_H

#include "../tokens.hpp"

#include <vector>

class TokenLogger
{
public:
    static void log_tokens(std::vector<Token>);

    static void log_token(Token);
};

#endif
