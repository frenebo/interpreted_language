#include <vector>
#include <iostream>

#include "../../../tokens/tokens.hpp"
#include "parse_statement.hpp"
#include "../../parser_exception.hpp"
#include "../compound_expression/parse_compound_expression.hpp"
#include "../check_for_tok_type/check_for_tok_type.hpp"
#include "../statement_sequence/parse_statement_sequence.hpp"
#include "../simple_expression/parse_simple_expression.hpp"

namespace parser::statement
{
    ParseResult<syntax_tree::statements::VariableDeclaration> parse_var_declaration(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        unsigned long consumed = 0;

        // variable keyword
        parser::check_for_tok_type(TokenType::VAR_KEYWORD, toks, start_idx + consumed);
        consumed++;

        // variable identifier
        auto var_identifier_parse_result =
            parser::simple_expression::parse_identifier_expression(toks, start_idx + consumed);
        consumed += var_identifier_parse_result.token_count();

        // equals sign
        parser::check_for_tok_type(TokenType::EQUALS_CH, toks, start_idx + consumed);
        consumed++;

        // variable assign expression
        auto var_assign_compound_exp =
            parser::compound_expression::parse_compound_expression(toks, start_idx + consumed);
        consumed += var_assign_compound_exp.token_count();

        // semicolon
        parser::check_for_tok_type(TokenType::SEMICOLON_CH, toks, start_idx + consumed);
        consumed++;

        return ParseResult<syntax_tree::statements::VariableDeclaration>(
            syntax_tree::statements::VariableDeclaration(
                var_identifier_parse_result.parsed_val(),
                var_assign_compound_exp.parsed_val()
            ),
            consumed
        );
    }
    ParseResult<syntax_tree::statements::IfStatement> parse_if_statement(
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        unsigned long consumed = 0;

        // if keyword
        parser::check_for_tok_type(TokenType::IF_KEYWORD, toks, start_idx + consumed);
        consumed++;

        // open parenthesis before if condition
        parser::check_for_tok_type(TokenType::OPEN_PAREN_CH, toks, start_idx + consumed);
        consumed++;

        // if condition compound expression
        auto if_condition_parse_result = parser::compound_expression::parse_compound_expression(toks, start_idx + consumed);
        consumed += if_condition_parse_result.token_count();

        // close parenthesis after if condition
        parser::check_for_tok_type(TokenType::CLOSE_PAREN_CH, toks, start_idx + consumed);
        consumed++;

        // open brace before if body
        parser::check_for_tok_type(TokenType::OPEN_BRACE_CH, toks, start_idx + consumed);
        consumed++;

        // if body statement sequence, with close brace token marking end of block
        auto if_body_parse_result =
            parser::statement_sequence::parse_statement_sequence(toks, start_idx + consumed, TokenType::CLOSE_BRACE_CH);
        consumed += if_body_parse_result.token_count();

        // close brace after if body
        parser::check_for_tok_type(TokenType::CLOSE_BRACE_CH, toks, start_idx + consumed);
        consumed++;

        return ParseResult<syntax_tree::statements::IfStatement>(
            syntax_tree::statements::IfStatement(
                if_condition_parse_result.parsed_val(),
                if_body_parse_result.parsed_val()
            ),
            consumed
        );
    }
    
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
        TokenType next_tok_type = toks[start_idx].get_type();

        if (next_tok_type == TokenType::IF_KEYWORD)
        {
            auto if_statement_parse_result = parse_if_statement(toks, start_idx);

            return ParseResult<syntax_tree::statements::StatementContainer>(
                syntax_tree::statements::StatementContainer(if_statement_parse_result.parsed_val()),
                if_statement_parse_result.token_count()
            );
        }
        else if (next_tok_type == TokenType::VAR_KEYWORD)
        {
            auto var_declaration_parse_result = parse_var_declaration(toks, start_idx);

            return ParseResult<syntax_tree::statements::StatementContainer>(
                syntax_tree::statements::StatementContainer(var_declaration_parse_result.parsed_val()),
                var_declaration_parse_result.token_count()
            );
        }
        else
        {
            auto expression_statement_parse_result = parse_expression_statement(toks, start_idx);

            return ParseResult<syntax_tree::statements::StatementContainer>(
                syntax_tree::statements::StatementContainer(expression_statement_parse_result.parsed_val()),
                expression_statement_parse_result.token_count()
            );
        }
    }
}