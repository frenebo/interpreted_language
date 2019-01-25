#ifndef SIMPLE_EXPRESSION_PARSER_H
#define SIMPLE_EXPRESSION_PARSER_H

#include <vector>

#include "../../../tokens/tokens.hpp"
#include "../../../syntax_tree/simple_expressions/simple_expressions.hpp"
#include "../parse_result.hpp"

namespace parser::simple_expression
{
    parser::ParseResult<syntax_tree::simple_expressions::SimpleExpressionContainer> parse_simple_expression(
        const std::vector<Token> & toks,
        unsigned long start_idx
    );
}

#endif
