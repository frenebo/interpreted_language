#ifndef PARSER_H
#define PARSER_H

#include "tokens.hpp"
#include <vector>

class Parser
{
public:
    Parser();
    void parse_tokens(const std::vector<Token> & toks) const;
};

#endif
