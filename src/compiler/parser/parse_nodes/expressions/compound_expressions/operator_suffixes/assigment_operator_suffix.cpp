#include <vector>

#include "operator_suffixes.hpp"
#include "../../../../../tokens/tokens.hpp"
#include "../../simple_expressions/simple_expressions.hpp"

namespace parse_nodes::operator_suffixes
{
    AssignmentOperatorSuffix AssignmentOperatorSuffix::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        BaseSimpleOperatorSuffix::SimpleOperatorParseResult simple_parse_result = BaseSimpleOperatorSuffix::parse_simple_op(
            TokenType::EQUALS_CH,
            toks,
            start_idx
        );

        return AssignmentOperatorSuffix(
            simple_parse_result.contained_exp_node(),
            simple_parse_result.token_count()
        );
    }

    TokenType AssignmentOperatorSuffix::possible_first_token_type()
    {
        return TokenType::EQUALS_CH;
    }

    AssignmentOperatorSuffix::AssignmentOperatorSuffix(
        parse_nodes::simple_expressions::SimpleExpNode simple_exp_node,
        unsigned long token_count)
    : BaseSimpleOperatorSuffix(
        "Assignment Operator Suffix",
        simple_exp_node,
        token_count
    )
    {
    }
}