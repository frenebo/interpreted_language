#include "expression_nodes.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"
#include <vector>
#include <iostream>
#include <tokens.hpp>

namespace parse_nodes::expressions
{
    IdentifierExpressionNode IdentifierExpressionNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        if (toks[start_idx].get_type() == TokenType::IDENTIFIER)
        {
            return IdentifierExpressionNode(toks[start_idx].get_contents(), 1);
        }
        else
        {
            throw NodeParseException("Expected Identifier");
        }
    }
    
    IdentifierExpressionNode::IdentifierExpressionNode(std::string identifier_str, unsigned long token_count)
    : _identifier_str(identifier_str),
    _token_count(token_count)
    {
    }

    unsigned long IdentifierExpressionNode::token_count()
    {
        return this->_token_count;
    }

    std::string IdentifierExpressionNode::identifier_str()
    {
        return this->_identifier_str;
    }

    void IdentifierExpressionNode::print_node(int indentation_level)
    {
        std::cout << std::string(indentation_level, ' ') << "Identifier expression node:\n";

        
    }
}
