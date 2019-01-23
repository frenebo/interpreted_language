#include "parser.hpp"
#include <vector>
#include "tokens.hpp"
#include "parse_nodes/parse_nodes.hpp"

Parser::Parser()
{

}

void Parser::parse_tokens(const std::vector<Token> & toks) const
{
    try
    {
        parse_nodes::ProgramNode program_node = parse_nodes::ProgramNode::parse_tokens(toks, 0);
    }
    catch (const parse_nodes::NodeParseException & ex)
    {
        throw ParseException(std::string(ex.what()));
    }
}
