#include <string>
#include <iostream>
#include <vector>

#include "tokens.hpp"
#include "statement_nodes.hpp"
#include "parser/parse_nodes/node_parse_exception.hpp"

namespace parse_nodes::statement_nodes
{
    IfStatementNode::IfStatementNode(unsigned long token_count)
    : _token_count(token_count)
    {
    }

    unsigned long IfStatementNode::token_count() const
    {
        return _token_count;
    }

    void IfStatementNode::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << "If Statement Node\n";
    }

    bool IfStatementNode::look_ahead(TokenType next_token_type)
    {
        return next_token_type == TokenType::IF_KEYWORD;
    }

    IfStatementNode IfStatementNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        TokenType start_tok_type = toks[start_idx].get_type();
        
        if (start_tok_type != TokenType::IF_KEYWORD)
        {
            throw NodeParseException(
                "Expected " + token_type_to_string(TokenType::IF_KEYWORD) +
                ", got " + token_type_to_string(start_tok_type)
            );
        }
    }
}
