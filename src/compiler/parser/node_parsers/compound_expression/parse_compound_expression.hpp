#ifndef PARSER_COMPOUND_EXPRESSION_H
#define PARSER_COMPOUNE_EXPRESSION_H

namespace parser::compound_expression
{
    ParseResult<syntax_tree::compound_expression::CompoundExpression> parse_compound_expression(
        const std::vector<Token> & toks,
        unsigned long start_idx
    );
}

#endif
