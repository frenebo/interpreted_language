#include <vector>
#include <optional>
#include <variant>
#include <iostream>
#include <string>

#include "../node_parse_exception.hpp"
#include "../../../tokens/tokens.hpp"
#include "statement_nodes.hpp"

namespace parse_nodes::statement_nodes
{
    StatementNodeContainer::StatementNodeContainer(
        unsigned long token_count,
        std::variant<ExpressionStatementNode, IfStatementNode> child_statement)
    : _child_statement(child_statement),
    _token_count(token_count)
    {
    }

    StatementNodeContainer StatementNodeContainer::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        TokenType next_tok_type = toks[start_idx].get_type();
        
        if (IfStatementNode::look_ahead(next_tok_type))
        {
            IfStatementNode if_statement_node = IfStatementNode::parse_tokens(toks, start_idx);

            return StatementNodeContainer(
                if_statement_node.token_count(),
                std::variant<ExpressionStatementNode, IfStatementNode>(if_statement_node)
            );
        }
        else
        {
            ExpressionStatementNode exp_statement_node = ExpressionStatementNode::parse_tokens(toks, start_idx);

            return StatementNodeContainer(
                exp_statement_node.token_count(),
                std::variant<ExpressionStatementNode, IfStatementNode>(exp_statement_node)
            );
        }
    }

    unsigned long StatementNodeContainer::token_count() const
    {
        return this->_token_count;
    }

    void StatementNodeContainer::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << "Statement Node Container:\n";
        if (std::holds_alternative<ExpressionStatementNode>(this->_child_statement))
        {
            std::get<ExpressionStatementNode>(this->_child_statement).print_node(indentation_level + 1);
        }
    }
}