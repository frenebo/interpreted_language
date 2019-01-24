#include <vector>

#include "statement_nodes.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"

namespace parse_nodes::statement_nodes
{
    IfStatementNode::IfStatementNode(
        parse_nodes::compound_expression::CompoundExpNode if_condition_exp,
        parse_nodes::StatementSequenceNode _if_body,
        unsigned long token_count)
    : _if_condition_exp(if_condition_exp),
    _token_count(token_count)
    {
    }

    parse_nodes::StatementSequenceNode IfStatementNode::if_body() const 
    {
        return _if_body;
    }
}