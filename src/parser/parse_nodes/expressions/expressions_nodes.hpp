#ifndef EXPRESSION_NODES_H
#define EXPRESSION_NODES_H

#include <vector>
#include <variant>
#include "tokens.hpp"

namespace parse_nodes::expressions
{
    class IdentifierExpressionNode
    {
    private:
        unsigned long _token_count;
        IdentifierExpressionNode(unsigned long token_count);
    public:
        unsigned long token_count();
        static IdentifierExpressionNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
    };

    class ExpressionNode
    {
    private:
        unsigned long _token_count;
        std::variant<IdentifierExpressionNode> _child_exp_node;
        ExpressionNode(unsigned long token_count, std::variant<IdentifierExpressionNode> identifier_node);
    public:
        unsigned long token_count();
        static ExpressionNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
    };
}

#endif
