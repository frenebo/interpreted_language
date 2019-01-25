#ifndef PARSE_SIMPLE_EXPRESSION_H
#define PARSE_SIMPLE_EXPRESSION_H

#include <vector>

#include "../../../tokens/tokens.hpp"
#include "../../../syntax_tree/statement_sequence/statement_sequence.hpp"
#include "../parse_result.hpp"

namespace parser::statement_sequence
{
    parser::ParseResult<syntax_tree::statement_sequence::StatementSequence> parse_statement_sequence(
        const std::vector<Token> & toks,
        unsigned long start_idx,
        TokenType end_token
    );
}

#endif
