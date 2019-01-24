#include "parser/parse_nodes/node_parse_exception.hpp"
#include <vector>
#include <optional>
#include <variant>
#include <iostream>
#include <string>

#include "tokens.hpp"
#include "statement_nodes.hpp"

namespace parse_nodes::statement_nodes
{
    StatementNodeContainer::StatementNodeContainer(unsigned long token_count, std::variant<ExpressionStatementNode> child_statement)
    : _child_statement(child_statement),
    _token_count(token_count)
    {
    }

    StatementNodeContainer StatementNodeContainer::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        ExpressionStatementNode exp_statement_node = ExpressionStatementNode::parse_tokens(toks, start_idx);

        return StatementNodeContainer(exp_statement_node.token_count(), exp_statement_node);
    }

    unsigned long StatementNodeContainer::token_count()
    {
        return this->_token_count;
    }

    void StatementNodeContainer::print_node(unsigned int indentation_level)
    {
        std::cout << std::string(indentation_level, ' ') << "Statement Node Container:\n";
        if (std::holds_alternative<ExpressionStatementNode>(this->_child_statement))
        {
            std::get<ExpressionStatementNode>(this->_child_statement).print_node(indentation_level + 1);
        }
    }
}