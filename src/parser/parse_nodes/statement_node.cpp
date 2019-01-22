#include "parse_nodes.hpp"
#include <vector>
#include <optional>
#include "tokens.hpp"

namespace parse_nodes
{
    StatementNode::StatementNode()
    {

    }

    std::optional<StatementNode> StatementNode::parse_tokens(const std::vector<Token> & toks, long start_idx)
    {
        return StatementNode();
    }
}