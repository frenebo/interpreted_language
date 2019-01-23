#include <vector>

#include "tokens.hpp"
#include "simple_expressions.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"

namespace parse_nodes::simple_expressions
{
    SimpleExpNode SimpleExpNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        unsigned long longest_match_len;
        std::optional<IdentifierExpNode> identifier_exp_match;

        try
        {
            identifier_exp_match = IdentifierExpNode::parse_tokens(toks, start_idx);

            if (identifier_exp_match->token_count() > longest_match_len)
            {
                longest_match_len = identifier_exp_match->token_count();
            }
        }
        catch (const NodeParseException & ex)
        {
            // do nothing?
        }
        
        if (identifier_exp_match.has_value() && identifier_exp_match->token_count() >= longest_match_len)
        {
            return SimpleExpNode(
                *identifier_exp_match,
                longest_match_len
            );
        }
    }
    
    SimpleExpNode::SimpleExpNode(std::variant<IdentifierExpNode> contained_exp_node, unsigned long token_count)
    : _contained_exp_node(contained_exp_node),
    _token_count(token_count)
    {
    }

    std::variant<IdentifierExpNode> SimpleExpNode::contained_exp_node() const
    {
        return _contained_exp_node;
    }

    unsigned long SimpleExpNode::token_count() const
    {
        return _token_count;
    }
}