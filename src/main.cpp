#include "tokenizer/tokenizer.hpp"
#include <vector>
#include "tokens.hpp"
#include "token_logger/token_logger.hpp"
#include "parser/parser.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"
#include <iostream>

int main()
{
    Tokenizer tokenizer;
    
    std::vector<Token> toks = tokenizer.tokenize(
        "a;a;"
    );
    try
    {
        parse_nodes::ProgramNode program_node = Parser().parse_tokens(toks);
        program_node.print_node(0);
    }
    catch (const ParseException & ex)
    {
        std::cout << "Parse Error: " << ex.what() << "\n";
    }
}