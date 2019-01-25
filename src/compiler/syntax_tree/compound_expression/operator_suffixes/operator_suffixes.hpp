#ifndef OPERATOR_SUFFIXES_H
#define OPERATOR_SUFFIXES_H

#include <variant>

#include "../../simple_expressions/simple_expressions.hpp"

namespace syntax_tree::compound_expression::operator_suffixes
{
    class BaseOperatorSuffix
    {
        syntax_tree::simple_expressions::SimpleExpressionContainer _right_hand_simple_exp;
    public:
        BaseOperatorSuffix(syntax_tree::simple_expressions::SimpleExpressionContainer right_hand_simple_exp)
        : _right_hand_simple_exp(right_hand_simple_exp)
        {
        }

        const syntax_tree::simple_expressions::SimpleExpressionContainer & right_hand_simple_exp() const
        {
            return _right_hand_simple_exp;
        }        
    };
    
    class AdditionOperatorSuffix : BaseOperatorSuffix
    {

    };

    class OperatorSuffixContainer
    {
        std::variant<AdditionOperatorSuffix> _contained_operator_suffix;
    public:
        OperatorSuffixContainer(std::variant<AdditionOperatorSuffix> contained_operator_suffix)
        : _contained_operator_suffix(contained_operator_suffix)
        {
        }

        const std::variant<AdditionOperatorSuffix> & contained_operator_suffix() const
        {
            return _contained_operator_suffix;
        }
    };
}

#endif
