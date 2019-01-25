#include <vector>

#include "../check_for_tok_type/check_for_tok_type.hpp"
#include "../../../tokens/tokens.hpp"
#include "../parse_result.hpp"
#include "../../parser_exception.hpp"
#include "../../../syntax_tree/compound_expression/compound_expression.hpp"
#include "../simple_expression/parse_simple_expression.hpp"

namespace parser::compound_expression
{
    ParseResult<syntax_tree::compound_expression::operator_suffixes::DotOperatorSuffix> parse_dot_op_suffix(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        parser::check_for_tok_type(TokenType::PERIOD_CH, toks, start_idx);
        unsigned long consumed = 1; // one for the equals ch

        auto next_simple_exp_result = parser::simple_expression::parse_simple_expression(toks, start_idx + consumed);

        consumed += next_simple_exp_result.token_count();

        return ParseResult(
            syntax_tree::compound_expression::operator_suffixes::DotOperatorSuffix(
                next_simple_exp_result.parsed_val()
            ),
            consumed
        );
    }

    ParseResult<syntax_tree::compound_expression::operator_suffixes::AssignmentOperatorSuffix> parse_assignment_suffix(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        parser::check_for_tok_type(TokenType::EQUALS_CH, toks, start_idx);

        // one for the equals ch
        unsigned long consumed = 1;

        auto next_simple_exp_result = parser::simple_expression::parse_simple_expression(toks, start_idx + consumed);

        consumed += next_simple_exp_result.token_count();

        return ParseResult(
            syntax_tree::compound_expression::operator_suffixes::AssignmentOperatorSuffix(
                next_simple_exp_result.parsed_val()
            ),
            consumed
        );
    }

    ParseResult<syntax_tree::compound_expression::operator_suffixes::AdditionOperatorSuffix> parse_addition_suffix(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        parser::check_for_tok_type(TokenType::PLUS_CH, toks, start_idx);

        // one for the plus ch
        unsigned long consumed = 1;

        auto next_simple_exp_result = parser::simple_expression::parse_simple_expression(toks, start_idx + consumed);

        consumed += next_simple_exp_result.token_count();

        return ParseResult(
            syntax_tree::compound_expression::operator_suffixes::AdditionOperatorSuffix(
                next_simple_exp_result.parsed_val()
            ),
            consumed
        );
    }

    ParseResult<syntax_tree::compound_expression::CompoundExpression> parse_compound_expression(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        auto start_exp_result = parser::simple_expression::parse_simple_expression(toks, start_idx);

        std::vector<syntax_tree::compound_expression::operator_suffixes::OperatorSuffixContainer> op_suffix_containers;

        unsigned long consumed = start_exp_result.token_count(); // for the start expression

        while (true)
        {
            TokenType next_tok_type = toks[start_idx + consumed].get_type();

            if (next_tok_type == TokenType::PLUS_CH)
            {
                auto add_parse_result = parse_addition_suffix(toks, start_idx + consumed);

                auto suffix_cont = syntax_tree::compound_expression::operator_suffixes::OperatorSuffixContainer(
                    add_parse_result.parsed_val()
                );

                op_suffix_containers.push_back(suffix_cont);
                consumed += add_parse_result.token_count();
            }
            else if (next_tok_type == TokenType::EQUALS_CH)
            {
                auto assign_parse_result = parse_assignment_suffix(toks, start_idx + consumed);

                auto suffix_container = syntax_tree::compound_expression::operator_suffixes::OperatorSuffixContainer(
                    assign_parse_result.parsed_val()
                );

                op_suffix_containers.push_back(suffix_container);
                consumed += assign_parse_result.token_count();
            }
            else if (next_tok_type == TokenType::PERIOD_CH)
            {
                auto dot_op_parse_result = parse_dot_op_suffix(toks, start_idx + consumed);

                auto suffix_container = syntax_tree::compound_expression::operator_suffixes::OperatorSuffixContainer(
                    dot_op_parse_result.parsed_val()
                );

                op_suffix_containers.push_back(suffix_container);
                consumed += dot_op_parse_result.token_count();
            }
            else
            {
                break;
            }
        }

        return ParseResult<syntax_tree::compound_expression::CompoundExpression>(
            syntax_tree::compound_expression::CompoundExpression(
                start_exp_result.parsed_val(),
                op_suffix_containers
            ),
            consumed
        );
    }
}
