#include "../../expressions/simple_expressions/simple_expressions.hpp"
#include "../../node_parse_exception.hpp"

#include "../../../../tokens/tokens.hpp"

#include <vector>
#include <iostream>
#include <string>

namespace parse_nodes::simple_expressions
{
    IdentifierExpNode IdentifierExpNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        if (toks[start_idx].get_type() == TokenType::IDENTIFIER)
        {
            return IdentifierExpNode(toks[start_idx].get_contents(), 1);
        }
        else
        {
            throw NodeParseException("Expected Identifier");
        }
    }
    
    bool IdentifierExpNode::look_ahead(TokenType next_tok_type)
    {
        return next_tok_type == TokenType::IDENTIFIER;
    }
    
    IdentifierExpNode::IdentifierExpNode(std::string identifier_str, unsigned long token_count)
    : _identifier_str(identifier_str),
    _token_count(token_count)
    {
    }

    unsigned long IdentifierExpNode::token_count() const
    {
        return this->_token_count;
    }

    std::string IdentifierExpNode::identifier_str() const
    {
        return this->_identifier_str;
    }

    void IdentifierExpNode::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << "Identifier expression node: " + _identifier_str + "\n";
    }
}
