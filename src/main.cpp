#include <iostream>
#include <vector>

#include "tokens.hpp"
#include "parser/parser.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"
#include "tokenizer/tokenizer.hpp"

int main()
{
    auto tokenizer_output = tokenizer::Tokenizer().tokenize(
        "a + b + 1; something = aaa + 100.0;"
    );

    if (std::holds_alternative<tokenizer::TokenizerErrorReturn>(tokenizer_output))
    {
        std::get<tokenizer::TokenizerErrorReturn>(tokenizer_output).print_error();
        return 1;
    }

    std::vector<Token> toks = std::get<tokenizer::TokenizerResult>(tokenizer_output).tokens();
    
    try
    {
        // @TODO have parse_tokens return variant instead of throwing
        
        parse_nodes::ProgramNode program_node = Parser().parse_tokens(toks);
        program_node.print_node(0);
    }
    catch (const ParseException & ex)
    {
        std::cout << "Parse Error: " << ex.what() << "\n";
    }
}