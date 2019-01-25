#ifndef PARSER_COMPOUND_EXPRESSION_H
#define PARSER_COMPOUND_EXPRESSION_H

namespace parser::compound_expression
{
    ParseResult<syntax_tree::compound_expression::operator_suffixes::DotOperatorSuffix> parse_dot_op_suffix(
        const std::vector<Token> & toks,
        unsigned long start_idx
    );

    ParseResult<syntax_tree::compound_expression::operator_suffixes::AssignmentOperatorSuffix> parse_assignment_suffix(
        const std::vector<Token> & toks,
        unsigned long start_idx
    );

    ParseResult<syntax_tree::compound_expression::operator_suffixes::AdditionOperatorSuffix> parse_addition_suffix(
        const std::vector<Token> & toks,
        unsigned long start_idx
    );

    ParseResult<syntax_tree::compound_expression::CompoundExpression> parse_compound_expression(
        const std::vector<Token> & toks,
        unsigned long start_idx
    );
}

#endif
