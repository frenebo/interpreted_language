#ifndef CHECK_FOR_TOK_TYPE_H
#define CHECK_FOR_TOK_TYPE_H

#include <vector>

#include "../../../tokens/tokens.hpp"

namespace parser
{
    void check_for_tok_type(
        TokenType expected_type,
        const std::vector<Token> & toks,
        unsigned long start_idx
    );
}

#endif
