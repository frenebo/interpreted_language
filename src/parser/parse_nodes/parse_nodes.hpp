#ifndef PARSE_NODES_H
#define PARSE_NODES_H

#include <vector>
#include <optional>
#include "tokens.hpp"
#include "statements/statement_nodes.hpp"

namespace parse_nodes
{
    class NodeParseException: public std::exception {
    private:
        std::string message_;
    public:
        explicit NodeParseException(const std::string& message) : message_(message) {};
        virtual const char* what() const throw() {
            return message_.c_str();
        }
    };

    class ExpressionNode
    {
    private:
        unsigned long _token_count;
        ExpressionNode();
    public:
        unsigned long token_count();
        static ExpressionNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
    };
    
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
    };
}

#endif
