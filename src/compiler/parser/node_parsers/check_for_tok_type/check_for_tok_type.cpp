#include <vector>

#include "../../../tokens/tokens.hpp"
#include "../../parser_exception.hpp"

namespace parser
{
    void check_for_tok_type(
        TokenType expected_type,
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {
        if (toks[start_idx].get_type() != expected_type)
        {
            throw ParserException(
                "Expected " + token_type_to_string(expected_type) +
                ", got " + token_type_to_string(toks[start_idx].get_type())
            );
        }
    }
}
