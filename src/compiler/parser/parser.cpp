#include "parser.hpp"
#include <vector>
#include <string>

#include "../tokens/tokens.hpp"
#include "parse_nodes/node_parse_exception.hpp"

namespace parser
{
    Parser::Parser()
    {

    }

    ParseResult Parser::parse_tokens(const std::vector<Token> & toks) const
    {
        try
        {
            parse_nodes::StatementSequenceNode program_statement_sequence =
                parse_nodes::StatementSequenceNode::parse_tokens(toks, 0, TokenType::END_OF_INPUT);

            return ParseResult(program_statement_sequence);
        }
        catch (const NodeParseException & ex)
        {
            throw ParseException(std::string(ex.what()));
        }
    }
}