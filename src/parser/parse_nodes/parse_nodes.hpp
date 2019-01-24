#ifndef PARSE_NODES_H
#define PARSE_NODES_H

#include <vector>
#include <optional>
#include <string>

#include "tokens.hpp"
#include "parser/parse_nodes/statements/statement_nodes.hpp"

namespace parse_nodes
{
    class StatementSequenceNode
    {
    private:
        std::vector<statement_nodes::StatementNodeContainer> _statement_nodes;
        unsigned long _token_count;
        StatementSequenceNode(std::vector<statement_nodes::StatementNodeContainer> statement_nodes, unsigned long token_count);
    public:
        const std::vector<statement_nodes::StatementNodeContainer> & statement_nodes();
        unsigned long token_count();
        static StatementSequenceNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        void print_node(unsigned int indentation_level);
    };
}

#endif
