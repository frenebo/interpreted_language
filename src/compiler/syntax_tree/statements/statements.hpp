#ifndef STATEMENTS_H
#define STATEMENTS_H

#include <variant>

#include "../compound_expression/compound_expression.hpp"

namespace syntax_tree::statements
{
    class ExpressionStatement
    {
    // private:
    };
    
    class StatementContainer
    {
    private:
        std::variant<ExpressionStatement> _contained_statement;
    public:
        StatementContainer(std::variant<ExpressionStatement> contained_statement)
        : _contained_statement(contained_statement)
        {
        }

        const std::variant<ExpressionStatement> & contained_statement() const
        {
            return _contained_statement;
        }
    };
}

#endif
