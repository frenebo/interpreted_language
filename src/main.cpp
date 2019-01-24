#include <iostream>
#include <vector>

#include "tokens.hpp"
#include "parser/parser.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"
#include "tokenizer/tokenizer.hpp"

int main()
{
    try
    {
        std::vector<Token> toks = Tokenizer().tokenize(
            "a + b +;"
        );
    
        parse_nodes::ProgramNode program_node = Parser().parse_tokens(toks);
        program_node.print_node(0);
    }
    catch (const TokenizerException &ex)
    {
        std::cout << "Tokenizer Error: " << ex.what() << "\n";
    }
    catch (const ParseException & ex)
    {
        std::cout << "Parse Error: " << ex.what() << "\n";
    }
}