#include "../../parser_exception.hpp"
#include "parse_simple_expression.hpp"

namespace parser::simple_expression
{
    parser::ParseResult<syntax_tree::simple_expressions::IdentifierExpression> parse_identifier_expression(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        TokenType expect_identifier_type = toks[start_idx].get_type();

        if (expect_identifier_type != TokenType::IDENTIFIER)
        {
            throw ParserException(
                "Expected " + token_type_to_string(TokenType::IDENTIFIER) +
                ", got " + token_type_to_string(expect_identifier_type)
            );
        }

        return parser::ParseResult<syntax_tree::simple_expressions::IdentifierExpression>(
            syntax_tree::simple_expressions::IdentifierExpression(toks[start_idx].get_contents()),
            1 // one for the single identifier token
        );
    }

    parser::ParseResult<syntax_tree::simple_expressions::NumberExpression> parse_number_expression(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        TokenType expect_identifier_type = toks[start_idx].get_type();

        if (expect_identifier_type != TokenType::NUMBER)
        {
            throw ParserException(
                "Expected " + token_type_to_string(TokenType::NUMBER) +
                ", got " + token_type_to_string(expect_identifier_type)
            );
        }

        return parser::ParseResult<syntax_tree::simple_expressions::NumberExpression>(
            syntax_tree::simple_expressions::NumberExpression(toks[start_idx].get_contents()),
            1 // one for the single identifier token
        );
    }

    parser::ParseResult<syntax_tree::simple_expressions::SimpleExpressionContainer> parse_simple_expression(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        TokenType next_tok_type = toks[start_idx].get_type();

        if (next_tok_type == TokenType::IDENTIFIER)
        {
            auto identifier_parse_result = parse_identifier_expression(toks, start_idx);
            auto simple_container = syntax_tree::simple_expressions::SimpleExpressionContainer(identifier_parse_result.parsed_val());

            return parser::ParseResult<syntax_tree::simple_expressions::SimpleExpressionContainer>(
                simple_container,
                identifier_parse_result.token_count()
            );
        }
        else if (next_tok_type == TokenType::NUMBER)
        {
            auto number_parse_result = parse_number_expression(toks, start_idx);
            auto simple_container = syntax_tree::simple_expressions::SimpleExpressionContainer(number_parse_result.parsed_val());

            return parser::ParseResult<syntax_tree::simple_expressions::SimpleExpressionContainer>(
                simple_container,
                number_parse_result.token_count()
            );
            // auto number_parse_result = parse_number_expression(toks, start_idx);
        }
        else
        {
            throw ParserException(
                "Expected expression, got " + token_type_to_string(next_tok_type)
            );
        }
    }
}
