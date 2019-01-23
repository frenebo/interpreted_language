#include "expressions_nodes.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"
#include <vector>
#include <optional>
#include "tokens.hpp"

namespace parse_nodes::expressions
{
    ExpressionNode ExpressionNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        unsigned long longest_match = 0;
        std::optional<IdentifierExpressionNode> identifier_node;
        
        // Try to parse an identifier
        try
        {
            identifier_node = IdentifierExpressionNode::parse_tokens(toks, start_idx);

            if (identifier_node->token_count() > longest_match)
            {
                longest_match = identifier_node->token_count();
            }
        }
        catch(const parse_nodes::NodeParseException & ex)
        {
            // Do nothing?
        }

        if (identifier_node.has_value() && identifier_node->token_count() >= longest_match)
        {
            return ExpressionNode(
                identifier_node->token_count(),
                *identifier_node
            );
        }
        else
        {
            throw parse_nodes::NodeParseException("Expected expression");
        }
    }

    ExpressionNode::ExpressionNode(unsigned long token_count, std::variant<IdentifierExpressionNode> child_exp_node)
    : _token_count(token_count),
    _child_exp_node(child_exp_node)
    {
    }
    
    unsigned long ExpressionNode::token_count()
    {
        return this->_token_count;
    }
}