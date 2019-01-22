#include "parse_nodes.hpp"
#include <vector>
#include <optional>
#include "tokens.hpp"
#include <iostream>

namespace parse_nodes
{
    StatementNode::StatementNode(unsigned long token_count): _token_count(token_count) {}

    StatementNode StatementNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        std::cout << "Parsing tokens\n";
        return StatementNode(1);
    }

    unsigned long StatementNode::token_count()
    {
        return this->_token_count;
    }
}