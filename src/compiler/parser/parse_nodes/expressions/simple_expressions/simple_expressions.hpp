#ifndef SIMPLE_EXPRESSIONS_H
#define SIMPLE_EXPRESSIONS_H

#include <variant>
#include <string>
#include <vector>

#include "../../../../tokens/tokens.hpp"

namespace parse_nodes::simple_expressions
{
    class IdentifierExpNode
    {
    private:
        std::string _identifier_str;
        unsigned long _token_count;
        IdentifierExpNode(std::string identifier_str, unsigned long token_count);
    public:
        std::string identifier_str() const;
        unsigned long token_count() const;
        static IdentifierExpNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        static bool look_ahead(TokenType next_tok_type);
        void print_node(unsigned int indentation_level) const;
    };

    class NumberNode
    {
    private:
        std::string _number_str;
        unsigned long _token_count;
        NumberNode(std::string number_str, unsigned long token_count);
    public:
        std::string number_str() const;
        unsigned long token_count() const;
        static NumberNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        static bool look_ahead(TokenType next_tok_type);
        void print_node(unsigned int indentation_level) const;
    };
    
    class SimpleExpNode
    {
    private:
        std::variant<IdentifierExpNode, NumberNode> _contained_exp_node;
        unsigned long _token_count;
        SimpleExpNode(std::variant<IdentifierExpNode, NumberNode> contained_exp_node, unsigned long token_count);
    public:
        unsigned long token_count() const;
        std::variant<IdentifierExpNode, NumberNode> contained_exp_node() const;
        void print_node(unsigned int indentation_level) const;
        static SimpleExpNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
    };
}

#endif
