#ifndef STATEMENT_NODES_H
#define STATEMENT_NODES_H

#include <vector>
#include <variant>
#include "tokens.hpp"
#include "parser/parse_nodes/expressions/expression_nodes.hpp"

namespace parse_nodes::statement_nodes
{
    class ExpressionStatementNode
    {
    private:
        unsigned long _token_count;
        parse_nodes::expressions::ExpressionNode _exp_node;
        ExpressionStatementNode(
            parse_nodes::expressions::ExpressionNode exp_node,
            unsigned long token_count);
    public:
        unsigned long token_count();
        static ExpressionStatementNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(int indentation_level);
    };
    
    class StatementNode
    {
    private:
        std::variant<ExpressionStatementNode> _child_statement;
        unsigned long _token_count;
        StatementNode(unsigned long token_count, std::variant<ExpressionStatementNode> child_statement);
    public:
        unsigned long token_count();
        static StatementNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(int indentation_level);
    };
}

#endif