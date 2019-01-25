#ifndef COMPILER_H
#define COMPILER_H

#include <string>

namespace compiler
{
    class Compiler
    {
    public:
        Compiler();
        void compile_text(std::string text_to_parse) const;
    };
}

#endif
