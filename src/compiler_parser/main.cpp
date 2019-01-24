#include <iostream>
#include <vector>
#include <ctime>

#include "tokens.hpp"
#include "parser/parser.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"
#include "tokenizer/tokenizer.hpp"

int main()
{
    std::string to_parse =
        "a + b + 1;"
        "something = 100.0;"
        "if (1) {"
        ""
        "}";

    std::clock_t tokenize_clock_start = std::clock();
    
    auto tokenizer_output = tokenizer::Tokenizer().tokenize(to_parse);

    if (std::holds_alternative<tokenizer::TokenizerErrorReturn>(tokenizer_output))
    {
        std::get<tokenizer::TokenizerErrorReturn>(tokenizer_output).print_error();
        return 1;
    }

    const std::vector<Token> & toks = std::get<tokenizer::TokenizerResult>(tokenizer_output).tokens();

    double tokenize_duration = ( std::clock() - tokenize_clock_start ) / (double) CLOCKS_PER_SEC;
    std::cout<< "Tokenize duration: " << tokenize_duration <<'\n';

    std::clock_t parse_clock_start = std::clock();
    
    try
    {
        parse_nodes::StatementSequenceNode program_node = Parser().parse_tokens(toks);
    }
    catch (const ParseException & ex)
    {
        std::cout << "Parse Error: " << ex.what() << "\n";
    }

    double parse_duration = ( std::clock() - parse_clock_start ) / (double) CLOCKS_PER_SEC;
    std::cout << "Parse duration:    " << parse_duration << "\n";
    std::cout << "Total duration:    " << tokenize_duration + parse_duration << "\n";
}