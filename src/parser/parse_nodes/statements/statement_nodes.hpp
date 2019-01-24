#ifndef STATEMENT_NODES_H
#define STATEMENT_NODES_H

#include <vector>
#include <variant>
#include <memory>
#include "tokens.hpp"
#include "parser/parse_nodes/expressions/compound_expressions/compound_expression.hpp"

namespace parse_nodes
{
    class StatementSequenceNode;
}

namespace parse_nodes::statement_nodes
{
    class IfStatementNode
    {
    private:
        unsigned long _token_count;

        IfStatementNode(unsigned long token_count);
    public:
        unsigned long token_count() const;
        void print_node(unsigned int indentation_level) const;
        static bool look_ahead(TokenType next_tok_type);
        static IfStatementNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
    };
    
    class ExpressionStatementNode
    {
    private:
        parse_nodes::compound_expression::CompoundExpNode  _exp_node;
        unsigned long _token_count;
        ExpressionStatementNode(
            parse_nodes::compound_expression::CompoundExpNode exp_node,
            unsigned long token_count);
    public:
        unsigned long token_count() const;
        static ExpressionStatementNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(unsigned int indentation_level) const;
    };
    
    class StatementNodeContainer
    {
    private:
        std::variant<ExpressionStatementNode, IfStatementNode> _child_statement;
        unsigned long _token_count;
        StatementNodeContainer(unsigned long token_count, std::variant<ExpressionStatementNode, IfStatementNode> child_statement);
    public:
        unsigned long token_count() const;
        static StatementNodeContainer parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(unsigned int indentation_level) const;
    };
}

#endif