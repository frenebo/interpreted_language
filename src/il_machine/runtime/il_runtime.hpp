#ifndef IL_RUNTIME_H
#define IL_RUNTIME_H

#include <vector>

#include "../il_runtime.hpp"
#include "../../intermediate_lang/instructions/instructions.hpp"
#include "../stack/stack.hpp"

namespace il_machine::runtime
{
    class IlRuntime
    {
        il_runtime::stack::IlStack _stack;

    public:
        IlRuntime();
        void start();
    };
}

#endif
