#ifndef SIMPLE_EXPRESSIONS_H
#define SIMPLE_EXPRESSIONS_H

#include <variant>
#include <string>

namespace syntax_tree::simple_expressions
{
    class IdentifierExpression
    {
        std::string _identifier_string;
    public:
        IdentifierExpression(std::string identifier_string)
        : _identifier_string(identifier_string)
        {
        }

        std::string identifier_string() const { return _identifier_string; }
    };

    class NumberExpression
    {
        std::string _number_string;
    public:
        NumberExpression(std::string number_string)
        : _number_string(number_string)
        {
        }

        std::string number_string() const { return _number_string; }
    };

    class SimpleExpressionContainer
    {
        std::variant<IdentifierExpression, NumberExpression> _contained_expression;
    public:
        SimpleExpressionContainer(std::variant<IdentifierExpression, NumberExpression> contained_expression)
        : _contained_expression(contained_expression)
        {
        }

        SimpleExpressionContainer(IdentifierExpression contained_expression)
        : _contained_expression(contained_expression)
        {
        }

        SimpleExpressionContainer(NumberExpression contained_expression)
        : _contained_expression(contained_expression)
        {
        }

        const std::variant<IdentifierExpression, NumberExpression> & contained_expression() const
        {
            return _contained_expression;
        }
    };
}

#endif
