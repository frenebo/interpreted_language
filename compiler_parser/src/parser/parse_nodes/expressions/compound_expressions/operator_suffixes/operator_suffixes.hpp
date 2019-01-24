#ifndef OPERATOR_EXTENSIONS_H
#define OPERATOR_EXTENSIONS_H

#include <vector>
#include <variant>
#include <optional>

#include "tokens.hpp"
#include "parser/parse_nodes/expressions/simple_expressions/simple_expressions.hpp"

namespace parse_nodes::operator_suffixes
{
    class BaseSimpleOperatorSuffix
    {
    private:
        std::string _op_name;
        parse_nodes::simple_expressions::SimpleExpNode _simple_exp_node;
        unsigned long _token_count;

    public:
        parse_nodes::simple_expressions::SimpleExpNode simple_exp_node() const;
        unsigned long token_count() const;
        void print_node(unsigned int indentation_level) const;
        
        BaseSimpleOperatorSuffix(
            std::string op_name,
            parse_nodes::simple_expressions::SimpleExpNode simple_exp_node,
            unsigned long token_count);
        
        class SimpleOperatorParseResult
        {
        private:
            parse_nodes::simple_expressions::SimpleExpNode _contained_exp_node;
            unsigned long _token_count;
        public:
            SimpleOperatorParseResult(
                parse_nodes::simple_expressions::SimpleExpNode contained_exp_node,
                unsigned long token_count)
            : _contained_exp_node(contained_exp_node),
            _token_count(token_count)
            {
            };
            
            parse_nodes::simple_expressions::SimpleExpNode contained_exp_node() const { return _contained_exp_node; };
            unsigned long token_count() const { return _token_count; };
        };

        static SimpleOperatorParseResult parse_simple_op(
            TokenType op_token,
            const std::vector<Token> & toks,
            unsigned long start_idx);
    };
    
    class AdditionOperatorSuffix : public BaseSimpleOperatorSuffix
    {
    private:
        AdditionOperatorSuffix(parse_nodes::simple_expressions::SimpleExpNode simple_exp_node, unsigned long token_count);
    public:
        static AdditionOperatorSuffix parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        static TokenType possible_first_token_type();
    };

    class AssignmentOperatorSuffix : public BaseSimpleOperatorSuffix
    {
    private:
        AssignmentOperatorSuffix(parse_nodes::simple_expressions::SimpleExpNode simple_exp_node, unsigned long token_count);
    public:
        static AssignmentOperatorSuffix parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        static TokenType possible_first_token_type();
    };
    
    class OperatorSuffixContainer
    {
    private:
        std::variant<
            AdditionOperatorSuffix,
            AssignmentOperatorSuffix
        > _contained_op_extension;
        unsigned long _token_count;
        OperatorSuffixContainer(
            std::variant<
                AdditionOperatorSuffix,
                AssignmentOperatorSuffix
            > contained_op_extension,
            unsigned long token_count);
    public:
        static std::optional<OperatorSuffixContainer> try_parse_suffix(const std::vector<Token> & toks, unsigned long start_idx);
        unsigned long token_count() const;
        std::variant<
            AdditionOperatorSuffix,
            AssignmentOperatorSuffix
        > contained_op_extension() const;
        void print_node(unsigned int indentation_level) const;
    };
}


#endif
