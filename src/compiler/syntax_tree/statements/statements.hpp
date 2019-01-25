#ifndef STATEMENTS_H
#define STATEMENTS_H

#include <variant>
#include <optional>

#include "../compound_expression/compound_expression.hpp"
#include "../simple_expressions/simple_expressions.hpp"

namespace syntax_tree::statement_sequence
{
    class StatementSequence;
}

namespace syntax_tree::statements
{
    class IfStatement
    {
        syntax_tree::compound_expression::CompoundExpression _if_condition;
        syntax_tree::statement_sequence::StatementSequence* _if_body;
    public:
        IfStatement(
            syntax_tree::compound_expression::CompoundExpression if_condition,
            syntax_tree::statement_sequence::StatementSequence if_body
        );

        IfStatement(const IfStatement & other);

        IfStatement & operator=(const IfStatement & rhs);

        ~IfStatement();

        const syntax_tree::compound_expression::CompoundExpression & if_condition() const;

        const syntax_tree::statement_sequence::StatementSequence & if_body() const;
    };

    class VariableDeclaration
    {
        syntax_tree::simple_expressions::IdentifierExpression _variable_identifier;
        std::optional<syntax_tree::compound_expression::CompoundExpression> _assigned_compound_exp;
    public:
        VariableDeclaration(
            syntax_tree::simple_expressions::IdentifierExpression variable_identifier,
            syntax_tree::compound_expression::CompoundExpression assigned_compound_exp)
        : _variable_identifier(variable_identifier),
        _assigned_compound_exp(assigned_compound_exp)
        {
        }

        VariableDeclaration(
            syntax_tree::simple_expressions::IdentifierExpression variable_identifier,
            std::optional<syntax_tree::compound_expression::CompoundExpression> assigned_compound_exp)
        : _variable_identifier(variable_identifier),
        _assigned_compound_exp(assigned_compound_exp)
        {
        }

        VariableDeclaration(
            syntax_tree::simple_expressions::IdentifierExpression variable_identifier)
        : _variable_identifier(variable_identifier)
        {
        }

        const syntax_tree::simple_expressions::IdentifierExpression & variable_identifier() const
        {
            return _variable_identifier;
        }

        const std::optional<syntax_tree::compound_expression::CompoundExpression> & assigned_compound_exp() const
        {
            return _assigned_compound_exp;
        }
    };
    
    class ExpressionStatement
    {
        syntax_tree::compound_expression::CompoundExpression _contained_compound_exp;
    public:
        ExpressionStatement(syntax_tree::compound_expression::CompoundExpression contained_compound_exp)
        : _contained_compound_exp(contained_compound_exp)
        {
        }

        const syntax_tree::compound_expression::CompoundExpression & contained_compound_exp() const
        {
            return _contained_compound_exp;
        }
    };
    
    class StatementContainer
    {
    private:
        std::variant<
            ExpressionStatement,
            IfStatement,
            VariableDeclaration
        > _contained_statement;
    public:
        StatementContainer(std::variant<
            ExpressionStatement,
            IfStatement,
            VariableDeclaration
        > contained_statement)
        : _contained_statement(contained_statement)
        {
        }

        StatementContainer(ExpressionStatement contained_statement)
        : _contained_statement(contained_statement)
        {
        }

        StatementContainer(IfStatement contained_statement)
        : _contained_statement(contained_statement)
        {
        }

        StatementContainer(VariableDeclaration contained_statement)
        : _contained_statement(contained_statement)
        {
        }

        const std::variant<
            ExpressionStatement,
            IfStatement,
            VariableDeclaration
        > & contained_statement() const
        {
            return _contained_statement;
        }
    };
}

#endif
