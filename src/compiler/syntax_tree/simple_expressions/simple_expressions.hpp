#ifndef SIMPLE_EXPRESSIONS_H
#define SIMPLE_EXPRESSIONS_H

#include <variant>

namespace syntax_tree::simple_expressions
{
    class IdentifierExpression
    {
    };
    
    class SimpleExpressionContainer
    {
        std::variant<IdentifierExpression> _contained_expression;
    public:
        SimpleExpressionContainer(std::variant<IdentifierExpression> contained_expression)
        : _contained_expression(contained_expression)
        {
        }

        const std::variant<IdentifierExpression> & contained_expression() const
        {
            return _contained_expression;
        }
    };
}

#endif
