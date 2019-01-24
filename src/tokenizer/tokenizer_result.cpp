#include <vector>

#include "tokenizer.hpp"
#include "tokens.hpp"

namespace tokenizer
{
    TokenizerResult::TokenizerResult(std::vector<Token> tokens)
    : _tokens(tokens)
    {
    }

    std::vector<Token> TokenizerResult::tokens() const
    {
        return _tokens;
    }
}