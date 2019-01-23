#include "statement_nodes.hpp"
#include <vector>
#include "tokens.hpp"

namespace parse_nodes::statement_nodes
{
    ExpressionStatementNode ExpressionStatementNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        // parse_nodes::expressions::ExpressionNode::parse_tokens
    }

    ExpressionStatementNode::ExpressionStatementNode(unsigned long token_count)
    : _token_count(token_count)
    {
    }

    unsigned long ExpressionStatementNode::token_count()
    {
        return this->_token_count;
    }
}