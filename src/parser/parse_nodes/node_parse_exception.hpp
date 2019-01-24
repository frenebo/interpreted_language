#ifndef NODE_PARSE_EXCEPTION
#define NODE_PARSE_EXCEPTION

#include <string>
#include <exception>

class NodeParseException: public std::exception {
private:
    std::string message_;
public:
    explicit NodeParseException(const std::string& message) : message_(message) {};
    virtual const char* what() const throw() {
        return message_.c_str();
    }
};

#endif