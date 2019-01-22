#include "parse_nodes.hpp"
#include <vector>
#include "tokens.hpp"
#include <optional>

namespace parse_nodes
{
    ProgramNode::ProgramNode()
    {

    }

    std::optional<ProgramNode> ProgramNode::parse_tokens(const std::vector<Token> & toks, long start_idx)
    {
        std::vector<StatementNode> statement_nodes;

        // long toks_consumed = toks;

        // StatementNode::parse_tokens(toks);
        // return ProgramNode();
    }
}