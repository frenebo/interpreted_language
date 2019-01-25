#include "statements.hpp"
#include "../compound_expression/compound_expression.hpp"
#include "../statement_sequence/statement_sequence.hpp"

namespace syntax_tree::statements
{
    IfStatement::IfStatement(
        syntax_tree::compound_expression::CompoundExpression if_condition,
        syntax_tree::statement_sequence::StatementSequence if_body)
    : _if_condition(if_condition),
    _if_body(new syntax_tree::statement_sequence::StatementSequence(if_body))
    {
    }

    IfStatement::IfStatement(const IfStatement & other)
    : _if_condition(other.if_condition()),
    _if_body(new syntax_tree::statement_sequence::StatementSequence(other.if_body()))
    {
    }

    IfStatement& IfStatement::operator=(const IfStatement & rhs)
    {
        _if_condition = rhs.if_condition();

        delete _if_body;

        _if_body = new syntax_tree::statement_sequence::StatementSequence(rhs.if_body());

        return *this;
    }

    IfStatement::~IfStatement()
    {
        delete _if_body;
    }

    const syntax_tree::compound_expression::CompoundExpression & IfStatement::if_condition() const
    {
        return _if_condition;
    }

    const syntax_tree::statement_sequence::StatementSequence & IfStatement::if_body() const
    {
        return *_if_body;
    }
    // class IfStatement
    // {
    //     syntax_tree::compound_expression::CompoundExpression _if_condition;
    //     syntax_tree::statement_sequence::StatementSequence* _if_body;
    // public:
    //     IfStatement(
    //         syntax_tree::compound_expression::CompoundExpression if_condition,
    //         syntax_tree::statement_sequence::StatementSequence* if_body
    //     );
    // };
}