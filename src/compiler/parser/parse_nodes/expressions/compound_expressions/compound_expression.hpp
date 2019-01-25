#ifndef OLD_COMPOUND_EXPRESSION_H
#define OLD_COMPOUND_EXPRESSION_H

#include <vector>

#include "../../../../tokens/tokens.hpp"
#include "../simple_expressions/simple_expressions.hpp"
#include "operator_suffixes/operator_suffixes.hpp"

namespace parse_nodes::compound_expression
{
    class CompoundExpNode
    {
    private:
        parse_nodes::simple_expressions::SimpleExpNode _first_exp_node;
        std::vector<parse_nodes::operator_suffixes::OperatorSuffixContainer> _operator_suffixes;
        unsigned long _token_count;
        
        CompoundExpNode(
            parse_nodes::simple_expressions::SimpleExpNode first_exp_node,
            std::vector<parse_nodes::operator_suffixes::OperatorSuffixContainer> operator_suffixes,
            unsigned long token_count
        );
    public:
        unsigned long token_count() const;
        const std::vector<parse_nodes::operator_suffixes::OperatorSuffixContainer> & operator_suffixes() const;
        parse_nodes::simple_expressions::SimpleExpNode first_exp_node() const;

        void print_node(unsigned int indentation_level) const;

        static CompoundExpNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
    };
}

#endif