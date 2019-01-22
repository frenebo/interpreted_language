#ifndef PARSE_NODES_H
#define PARSE_NODES_H

#include <vector>
#include <optional>
#include "tokens.hpp"

namespace parse_nodes
{
    class ProgramNode
    {
    private:
        ProgramNode();
    public:
        long token_count() const;
        static std::optional<ProgramNode> parse_tokens(const std::vector<Token> & toks, long start_idx);
    };

    class StatementNode
    {
    private:
        StatementNode();
    public:
        static std::optional<StatementNode> parse_tokens(const std::vector<Token> & toks, long start_idx);
    };
}

#endif
