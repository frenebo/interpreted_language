#ifndef COMPOUND_EXPRESSION_H
#define COMPOUND_EXPRESSION_H

#include "../simple_expressions/simple_expressions.hpp"
#include "operator_suffixes/operator_suffixes.hpp"

namespace syntax_tree::compound_expression
{
    class CompoundExpression
    {
        syntax_tree::simple_expressions::SimpleExpressionContainer _start_exp;
        std::vector<syntax_tree::compound_expression::operator_suffixes::OperatorSuffixContainer> _operator_suffixes;
    public:
        CompoundExpression(
            syntax_tree::simple_expressions::SimpleExpressionContainer start_exp,
            std::vector<syntax_tree::compound_expression::operator_suffixes::OperatorSuffixContainer> operator_suffixes)
        : _start_exp(start_exp),
        _operator_suffixes(operator_suffixes)
        {
        }

        const syntax_tree::simple_expressions::SimpleExpressionContainer & start_exp() const
        {
            return _start_exp;
        }

        const std::vector<syntax_tree::compound_expression::operator_suffixes::OperatorSuffixContainer> & operator_suffixes() const
        {
            return _operator_suffixes;
        }
    };
}

#endif
