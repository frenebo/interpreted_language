#ifndef IL_MACHINE_EXCEPTION_H
#define IL_MACHINE_EXCEPTION_H

#include <exception>
#include <string>

namespace il_machine
{
    class IlRuntimeException: public std::exception {
    private:
        std::string message_;
    public:
        explicit IlRuntimeException(const std::string& message) : message_(message) {};

        virtual const char* what() const throw() {
            return message_.c_str();
        }
    };
}

#endif
