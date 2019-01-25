#include <vector>

#include "../../../tokens/tokens.hpp"
#include "parse_statement.hpp"
#include "../../parser_exception.hpp"
#include "../compound_expression/parse_compound_expression.hpp"

namespace parser::statement
{
    ParseResult<syntax_tree::statements::ExpressionStatement> parse_expression_statement(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        auto compound_expression_parse_result = parser::compound_expression::parse_compound_expression(
            toks,
            start_idx
        );

        unsigned long consumed = compound_expression_parse_result.token_count();

        TokenType expect_semicolon_type = toks[start_idx + consumed].get_type();

        if (expect_semicolon_type != TokenType::SEMICOLON_CH)
        {
            throw ParserException(
                "Expected " + token_type_to_string(TokenType::SEMICOLON_CH) +
                ", got " + token_type_to_string(expect_semicolon_type)
            );
        }

        consumed++; // for the semicolon ch

        return ParseResult<syntax_tree::statements::ExpressionStatement>(
            syntax_tree::statements::ExpressionStatement(compound_expression_parse_result.parsed_val()),
            consumed
        );
    }
    
    ParseResult<syntax_tree::statements::StatementContainer> parse_statement(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        auto expression_statement_parse_result = parse_expression_statement(toks, start_idx);

        return ParseResult<syntax_tree::statements::StatementContainer>(
            syntax_tree::statements::StatementContainer(expression_statement_parse_result.parsed_val()),
            expression_statement_parse_result.token_count()
        );
    }
}