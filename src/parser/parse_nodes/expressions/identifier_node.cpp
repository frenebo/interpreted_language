#include "expressions_nodes.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"
#include <vector>
#include <tokens.hpp>

namespace parse_nodes::expressions
{
    IdentifierExpressionNode IdentifierExpressionNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        if (toks[start_idx].get_type() == TokenType::IDENTIFIER)
        {
            return IdentifierExpressionNode(1);
        }
        else
        {
            throw NodeParseException("Expected Identifier");
        }
    }
    
    IdentifierExpressionNode::IdentifierExpressionNode(unsigned long token_count)
    : _token_count(token_count)
    {
    }

    unsigned long IdentifierExpressionNode::token_count()
    {
        return this->_token_count;
    }
}
