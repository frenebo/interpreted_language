#include "parser.hpp"
#include <vector>
#include <string>

#include "tokens.hpp"
#include "parser/parse_nodes/node_parse_exception.hpp"

Parser::Parser()
{

}

parse_nodes::ProgramNode Parser::parse_tokens(const std::vector<Token> & toks) const
{
    try
    {
        parse_nodes::ProgramNode program_node = parse_nodes::ProgramNode::parse_tokens(toks, 0);

        return program_node;
    }
    catch (const NodeParseException & ex)
    {
        throw ParseException(std::string(ex.what()));
    }
}
