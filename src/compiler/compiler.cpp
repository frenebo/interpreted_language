#include <string>
#include <iostream>
#include <ctime>

#include "compiler.hpp"
#include "tokens/tokens.hpp"
#include "tokenizer/tokenizer.hpp"
#include "parser/parser.hpp"
#include "parser/parser_exception.hpp"
#include "syntax_tree/statement_sequence/statement_sequence.hpp"
#include "syntax_tree/statements/statements.hpp"

namespace compiler
{
    Compiler::Compiler()
    {
        // empty for now. Later: add compiler options?
    }

    void Compiler::compile_text(std::string text_to_parse) const
    {
        try
        {
            std::clock_t tokenizer_clock_start = std::clock();
            tokenizer::TokenizerResult tokenizer_result = tokenizer::Tokenizer().tokenize(text_to_parse);
            double tokenizer_duration = ( std::clock() - tokenizer_clock_start ) / (double) CLOCKS_PER_SEC;

            std::cout << "Tokenizer duration: " << tokenizer_duration << " seconds\n";


            std::clock_t parse_clock_start = std::clock();
            parser::ParseResult parse_result = parser::Parser().parse_tokens(tokenizer_result.tokens());
            double parse_duration = ( std::clock() - parse_clock_start ) / (double) CLOCKS_PER_SEC;

            std::cout << "Parse duration:     " << parse_duration << " seconds\n";
            std::cout << "Total duration:     " << parse_duration + tokenizer_duration << " seconds\n";
        }
        catch (const tokenizer::TokenizerException & ex)
        {
            std::cout << "Tokenizer Error: " << ex.what() << "\n";
        }
        catch (const parser::ParserException & ex)
        {
            std::cout << "Parser Error: " << ex.what() << "\n";
        }
    }
}
