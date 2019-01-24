#include "parser.hpp"
#include <vector>
#include <string>

#include "../tokens.hpp"
#include "parse_nodes/node_parse_exception.hpp"

Parser::Parser()
{

}

parse_nodes::StatementSequenceNode Parser::parse_tokens(const std::vector<Token> & toks) const
{
    try
    {
        parse_nodes::StatementSequenceNode program_node =
            parse_nodes::StatementSequenceNode::parse_tokens(toks, 0, TokenType::END_OF_INPUT);

        return program_node;
    }
    catch (const NodeParseException & ex)
    {
        throw ParseException(std::string(ex.what()));
    }
}
