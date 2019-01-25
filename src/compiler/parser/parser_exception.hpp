#ifndef PARSE_EXCEPTION_H
#define PARSE_EXCEPTION_H

#include <string>
#include <exception>

namespace parser
{
    class ParserException: public std::exception {
    private:
        std::string message_;
    public:
        explicit ParserException(const std::string& message) : message_(message) {};

        virtual const char* what() const throw() {
            return message_.c_str();
        }
    };
}

#endif
