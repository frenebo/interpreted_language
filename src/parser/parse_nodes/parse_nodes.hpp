#ifndef PARSE_NODES_H
#define PARSE_NODES_H

#include <vector>
#include <optional>
#include "tokens.hpp"

namespace parse_nodes
{
    class LoadException: public std::exception {
    private:
        std::string message_;
    public:
        explicit LoadException(const std::string& message) : message_(message) {};
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

    class StatementNode
    {
    private:
        unsigned long _token_count;
        StatementNode(unsigned long token_count);
    public:
        unsigned long token_count();
        static StatementNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
    };
    
    class ProgramNode
    {
    private:
        std::vector<StatementNode> _statement_nodes;
        unsigned long _token_count;
        ProgramNode(std::vector<StatementNode> statement_nodes, unsigned long token_count);
    public:
        const std::vector<StatementNode> & statement_nodes();
        unsigned long token_count();
        static ProgramNode parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
    };
}

#endif
