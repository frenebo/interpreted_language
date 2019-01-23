#ifndef STATEMENT_NODES_H
#define STATEMENT_NODES_H

#include <vector>
#include <variant>
#include "tokens.hpp"

namespace parse_nodes::statement_nodes
{
    class ExpressionStatementNode
    {
    private:
        unsigned long _token_count;
        ExpressionStatementNode(unsigned long token_count);
    public:
        unsigned long token_count();
        static ExpressionStatementNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
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
    };
}

#endif