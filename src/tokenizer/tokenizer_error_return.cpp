#include <iostream>

#include "tokenizer.hpp"

namespace tokenizer
{
    TokenizerErrorReturn::TokenizerErrorReturn(std::string message)
    : _message(message)
    {
    }

    void TokenizerErrorReturn::print_error() const
    {
        std::cout << "Tokenizer Error: " << _message << "\n";
    }
}