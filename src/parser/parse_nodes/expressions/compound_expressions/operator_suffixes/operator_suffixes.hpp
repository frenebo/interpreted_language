#ifndef OPERATOR_EXTENSIONS_H
#define OPERATOR_EXTENSIONS_H

#include <vector>
#include <variant>
#include <optional>

#include "tokens.hpp"
#include "parser/parse_nodes/expressions/simple_expressions/simple_expressions.hpp"

namespace parse_nodes::operator_suffixes
{
    class AdditionOperatorSuffix
    {
    private:
        parse_nodes::simple_expressions::SimpleExpNode _simple_exp_node;
        unsigned long _token_count;
        
        AdditionOperatorSuffix(parse_nodes::simple_expressions::SimpleExpNode simple_exp_node, unsigned long token_count);
    public:
        static AdditionOperatorSuffix parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        static std::vector<TokenType> possible_first_token_types();
        parse_nodes::simple_expressions::SimpleExpNode simple_exp_node() const;
        unsigned long token_count() const;
        void print_node(unsigned int indentation_level) const;
    };
    
    class OperatorSuffix
    {
    private:
        std::variant<AdditionOperatorSuffix> _contained_op_extension;
        unsigned long _token_count;
        OperatorSuffix(std::variant<AdditionOperatorSuffix> contained_op_extension, unsigned long token_count);
    public:
        static std::optional<OperatorSuffix> try_parse_suffix(const std::vector<Token> & toks, unsigned long start_idx);
        unsigned long token_count() const;
        std::variant<AdditionOperatorSuffix> contained_op_extension() const;
        void print_node(unsigned int indentation_level) const;
    };
}


#endif
