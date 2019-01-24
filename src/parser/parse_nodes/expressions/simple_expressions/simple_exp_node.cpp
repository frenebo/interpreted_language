#include <vector>
#include <optional>
#include <iostream>
#include <string>
#include <variant>

#include "tokens.hpp"
#include "simple_expressions.hpp"
#include "parser/parse_nodes/node_parse_exception.hpp"

namespace parse_nodes::simple_expressions
{
    SimpleExpNode SimpleExpNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        unsigned long longest_match_len = 1;
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
        else
        {
            throw NodeParseException("Expected expression");
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

    void SimpleExpNode::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << "Simple Expression Node:\n";

        if (std::holds_alternative<IdentifierExpNode>(_contained_exp_node))
        {
            std::get<IdentifierExpNode>(_contained_exp_node).print_node(indentation_level + 1);
        }
        else
        {
            std::cout << std::string(indentation_level + 1, ' ') << "Child print unimplemented\n";
        }
    }
}