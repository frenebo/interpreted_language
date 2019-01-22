#include "parse_nodes.hpp"
#include <vector>
#include "tokens.hpp"
#include <optional>
#include <iostream>

namespace parse_nodes
{
    ProgramNode ProgramNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        std::vector<StatementNode> statement_nodes;

        long tokens_consumed = 0;

        while (start_idx + tokens_consumed < toks.size())
        {
            StatementNode statement_node = StatementNode::parse_tokens(toks, start_idx + tokens_consumed);

            tokens_consumed += statement_node.token_count();
            statement_nodes.push_back(statement_node);
        }
        
        return ProgramNode(statement_nodes, tokens_consumed);
    }
    
    ProgramNode::ProgramNode(std::vector<StatementNode> statement_nodes, unsigned long token_count)
    {
        this->_statement_nodes = statement_nodes;
        this->_token_count = token_count;
    }

    const std::vector<StatementNode> & ProgramNode::statement_nodes()
    {
        return this->_statement_nodes;
    }

    unsigned long ProgramNode::token_count()
    {
        return this->_token_count;
    }
}