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
        TokenType next_tok_type = toks[start_idx].get_type();

        if (IdentifierExpNode::look_ahead(next_tok_type))
        {
            IdentifierExpNode parsed_node = IdentifierExpNode::parse_tokens(toks, start_idx);
            
            return SimpleExpNode(
                parsed_node,
                parsed_node.token_count()
            );
        }
        else if (NumberNode::look_ahead(next_tok_type))
        {
            NumberNode parsed_node = NumberNode::parse_tokens(toks, start_idx);

            return SimpleExpNode(
                parsed_node,
                parsed_node.token_count()
            );
        }
        else
        {
            throw NodeParseException("Expected expression");
        }
    }
    
    SimpleExpNode::SimpleExpNode(std::variant<IdentifierExpNode, NumberNode> contained_exp_node, unsigned long token_count)
    : _contained_exp_node(contained_exp_node),
    _token_count(token_count)
    {
    }

    std::variant<IdentifierExpNode, NumberNode> SimpleExpNode::contained_exp_node() const
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
        else if (std::holds_alternative<NumberNode>(_contained_exp_node))
        {
            std::get<NumberNode>(_contained_exp_node).print_node(indentation_level + 1);
        }
        else
        {
            std::cout << std::string(indentation_level + 1, ' ') << "Child print unimplemented\n";
        }
    }
}