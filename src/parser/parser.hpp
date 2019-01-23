#ifndef PARSER_H
#define PARSER_H

#include "tokens.hpp"
#include <vector>


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
    void parse_tokens(const std::vector<Token> & toks) const;
};


#endif
