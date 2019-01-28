#include <vector>

#include "../tokens/tokens.hpp"
#include "parser.hpp"
#include "node_parsers/parse_result.hpp"
#include "node_parsers/statement_sequence/parse_statement_sequence.hpp"
#include "../syntax_tree/statement_sequence/statement_sequence.hpp"

namespace parser
{
    Parser::Parser()
    {
        // @TODO : parser options?
    }

    ParseResult<syntax_tree::statement_sequence::StatementSequence> Parser::parse_tokens(const std::vector<Token> & toks) const
    {
        return parser::statement_sequence::parse_statement_sequence(toks, 0, TokenType::END_OF_INPUT);
    }
}
