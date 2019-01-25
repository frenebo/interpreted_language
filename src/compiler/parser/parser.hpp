#ifndef PARSER_H
#define PARSER_H

#include "../tokens/tokens.hpp"
#include "parse_nodes/parse_nodes.hpp"
#include <vector>
#include <string>

namespace parser
{
    class ParseResult
    {
    private:
        parse_nodes::StatementSequenceNode _statement_seq;
    public:
        ParseResult(parse_nodes::StatementSequenceNode statement_seq)
        : _statement_seq(statement_seq)
        {
        }

        const parse_nodes::StatementSequenceNode & statement_seq() const { return _statement_seq; }
    };
    
    class ParseException: public std::exception {
    private:
        std::string message_;
    public:
        explicit ParseException(const std::string& message) : message_(message) {};
        virtual const char* what() const throw() {
            return message_.c_str();
        }
    };

    class Parser
    {
    public:
        Parser();
        ParseResult parse_tokens(const std::vector<Token> & toks) const;
    };
}


#endif
