#include <iostream>
#include <vector>
#include <ctime>

#include "tokens.hpp"
#include "parser/parser.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"
#include "tokenizer/tokenizer.hpp"

int main()
{
    std::string to_parse = "a + b + 1; something = aaa + 3 = 100.0;";

    std::clock_t clock_start = std::clock();
    
    auto tokenizer_output = tokenizer::Tokenizer().tokenize(to_parse);

    if (std::holds_alternative<tokenizer::TokenizerErrorReturn>(tokenizer_output))
    {
        std::get<tokenizer::TokenizerErrorReturn>(tokenizer_output).print_error();
        return 1;
    }

    const std::vector<Token> & toks = std::get<tokenizer::TokenizerResult>(tokenizer_output).tokens();
    
    try
    {
        parse_nodes::StatementSequenceNode program_node = Parser().parse_tokens(toks);
    }
    catch (const ParseException & ex)
    {
        std::cout << "Parse Error: " << ex.what() << "\n";
    }

    double duration = ( std::clock() - clock_start ) / (double) CLOCKS_PER_SEC;

    std::cout<< "duration: "<< duration <<'\n';
}