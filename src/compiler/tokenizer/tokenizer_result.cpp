#include <vector>

#include "tokenizer.hpp"
#include "../tokens/tokens.hpp"

namespace tokenizer
{
    TokenizerResult::TokenizerResult(std::vector<Token> tokens)
    : _tokens(tokens)
    {
    }

    const std::vector<Token> & TokenizerResult::tokens() const
    {
        return _tokens;
    }
}