#include <vector>

#include "operator_suffixes.hpp"
#include "../../../../../tokens.hpp"
#include "../../simple_expressions/simple_expressions.hpp"

namespace parse_nodes::operator_suffixes
{
    AdditionOperatorSuffix AdditionOperatorSuffix::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        BaseSimpleOperatorSuffix::SimpleOperatorParseResult simple_parse_result = BaseSimpleOperatorSuffix::parse_simple_op(
            TokenType::PLUS_CH,
            toks,
            start_idx
        );

        return AdditionOperatorSuffix(
            simple_parse_result.contained_exp_node(),
            simple_parse_result.token_count()
        );
    }

    TokenType AdditionOperatorSuffix::possible_first_token_type()
    {
        return TokenType::PLUS_CH;
    }

    AdditionOperatorSuffix::AdditionOperatorSuffix(
        parse_nodes::simple_expressions::SimpleExpNode simple_exp_node,
        unsigned long token_count)
    : BaseSimpleOperatorSuffix(
        "Addition Operator Suffix",
        simple_exp_node,
        token_count
    )
    {
    }
}