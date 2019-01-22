#include <iostream>
#include "tokenizer/tokenizer.hpp"
#include <vector>
#include "tokens.hpp"
#include "token_logger/token_logger.hpp"
#include "parser/parser.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"

int main()
{
    Tokenizer tokenizer;
    
    std::vector<Token> toks = tokenizer.tokenize(
        "a=1;b=2;"
    );
    
    TokenLogger::log_tokens(toks);

    Parser parser;
    
    parser.parse_tokens(toks);
}