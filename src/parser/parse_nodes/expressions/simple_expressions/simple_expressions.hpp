#ifndef SIMPLE_EXPRESSIONS_H
#define SIMPLE_EXPRESSIONS_H

#include <variant>

namespace parse_nodes::simple_expressions
{
    class IdentifierExpNode;
    // class ParenthesizedExpNode;
    
    class SimpleExpNode
    {
    private:
        std::variant<IdentifierExpNode> _contained_exp_node;
        unsigned long _token_count;
        SimpleExpNode(std::variant<IdentifierExpNode> contained_exp_node, unsigned long token_count);
    public:
        unsigned long token_count() const;
        std::variant<IdentifierExpNode> contained_exp_node() const;
        static SimpleExpNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(int indentation_level);
    };

    class IdentifierExpNode
    {
    private:
        std::string _identifier_str;
        unsigned long _token_count;
        IdentifierExpNode(std::string identifier_str, unsigned long token_count);
    public:
        std::string identifier_str();
        unsigned long token_count();
        static IdentifierExpNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(int indentation_level);
    };

    // class ParenthesizedExpNode
    // {
    // private:
    //     unsigned long _token_count;
    //     ParenthesizedExpNode(std::variant<SimpleExpNode> contained_exp_node, unsigned long token_count);
    // public:
    //     unsigned long token_coun
    // };
}

#endif
