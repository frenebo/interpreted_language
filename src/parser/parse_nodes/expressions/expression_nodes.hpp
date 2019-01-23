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
        std::string _identifier_str;
        unsigned long _token_count;
        IdentifierExpressionNode(std::string identifier_str, unsigned long token_count);
    public:
        std::string identifier_str();
        unsigned long token_count();
        static IdentifierExpressionNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(int indentation_level);
    };

    class ExpressionNode
    {
    private:
        std::variant<IdentifierExpressionNode> _child_exp_node;
        unsigned long _token_count;
        ExpressionNode(unsigned long token_count, std::variant<IdentifierExpressionNode> identifier_node);
    public:
        unsigned long token_count();
        static ExpressionNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(int indentation_level);
    };
}

#endif
