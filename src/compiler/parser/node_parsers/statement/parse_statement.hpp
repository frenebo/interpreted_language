#ifndef PARSE_STATEMENT_H
#define PARSE_STATEMENT_H

#include <vector>

#include "../../../tokens/tokens.hpp"
#include "../parse_result.hpp"
#include "../../../syntax_tree/statements/statements.hpp"

namespace parser::statement
{
    ParseResult<syntax_tree::statements::StatementContainer> parse_statement(
        const std::vector<Token> & toks,
        unsigned long start_idx
    );
}

#endif
