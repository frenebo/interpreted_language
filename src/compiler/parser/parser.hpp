#ifndef PARSER_H
#define PARSER_H

#include "../tokens/tokens.hpp"
#include "parse_nodes/parse_nodes.hpp"
#include <vector>
#include <string>


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
    parse_nodes::StatementSequenceNode parse_tokens(const std::vector<Token> & toks) const;
};


#endif
