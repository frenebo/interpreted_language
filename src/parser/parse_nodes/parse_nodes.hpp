#ifndef PARSE_NODES_H
#define PARSE_NODES_H

#include <vector>
#include <optional>
#include <string>

#include "tokens.hpp"
#include "parser/parse_nodes/statements/statement_nodes.hpp"

namespace parse_nodes
{
    class ProgramNode
    {
    private:
        std::vector<statement_nodes::StatementNode> _statement_nodes;
        unsigned long _token_count;
        ProgramNode(std::vector<statement_nodes::StatementNode> statement_nodes, unsigned long token_count);
    public:
        const std::vector<statement_nodes::StatementNode> & statement_nodes();
        unsigned long token_count();
        static ProgramNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(unsigned int indentation_level);
    };
}

#endif
