#ifndef STATEMENT_NODES_H
#define STATEMENT_NODES_H

#include <vector>
#include <variant>
#include "tokens.hpp"
#include "parser/parse_nodes/expressions/compound_expressions/compound_expression.hpp"
// #include "parser/parse_nodes/expressions/expression_nodes.hpp"

namespace parse_nodes::statement_nodes
{
    class ExpressionStatementNode
    {
    private:
        parse_nodes::compound_expression::CompoundExpNode  _exp_node;
        unsigned long _token_count;
        ExpressionStatementNode(
            parse_nodes::compound_expression::CompoundExpNode exp_node,
            unsigned long token_count);
    public:
        unsigned long token_count();
        static ExpressionStatementNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(unsigned int indentation_level);
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
        void print_node(unsigned int indentation_level);
    };
}

#endif