#include <iostream>

#include "simple_expressions.hpp"
#include "parser/parse_nodes/node_parse_exception.hpp"

namespace parse_nodes::simple_expressions
{
    NumberNode::NumberNode(std::string number_str, unsigned long token_count)
    : _number_str(number_str),
    _token_count(token_count)
    {
    }


    std::string NumberNode::number_str() const
    {
        return _number_str;
    }
    
    unsigned long NumberNode::token_count() const
    {
        return _token_count;
    }
    
    NumberNode NumberNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        // throw NodeP
    }
    
    void NumberNode::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << "Number Node: " << _number_str;
    }
}