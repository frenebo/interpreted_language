#include "parser/parse_nodes/parse_nodes.hpp"
#include <vector>
#include <optional>
#include <variant>
#include "tokens.hpp"
#include "statement_nodes.hpp"

namespace parse_nodes::statement_nodes
{
    StatementNode::StatementNode(unsigned long token_count, std::variant<ExpressionStatementNode> child_statement)
    : _token_count(token_count),
    _child_statement(child_statement)
    {
    }

    StatementNode StatementNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        try
        {
            ExpressionStatementNode exp_statement_node = ExpressionStatementNode::parse_tokens(toks, start_idx);

            return StatementNode(exp_statement_node.token_count, exp_statement_node);
        }
        catch (const parse_nodes::NodeParseException & ex)
        {
            throw NodeParseException(std::string(ex.what()));
        }
    }

    unsigned long StatementNode::token_count()
    {
        return this->_token_count;
    }
}