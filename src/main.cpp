#include <iostream>
#include "tokenizer/tokenizer.hpp"
#include <vector>
#include "tokens.hpp"
#include "token_logger/token_logger.hpp"

int main()
{
    std::vector<Token> toks = Tokenizer::tokenize(";;;");
    TokenLogger::log_tokens(toks);
}