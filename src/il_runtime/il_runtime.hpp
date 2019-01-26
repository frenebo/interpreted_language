#ifndef IL_RUNTIME_H
#define IL_RUNTIME_H

#include <vector>

#include "il_runtime.hpp"
#include "../intermediate_lang/instructions/instructions.hpp"

namespace il_runtime
{
    class IlRuntime
    {
    public:
        // @TODO add options?
        IlRuntime();

        void run_bytecode(const std::vector<intermediate_lang::instructions::InstructionContainer> & instructions);
    };
}

#endif
