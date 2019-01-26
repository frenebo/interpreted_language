#ifndef IL_RUNTIME_H
#define IL_RUNTIME_H

#include <vector>

#include "../stack/stack.hpp"
#include "../../intermediate_lang/instructions/instructions.hpp"
#include "../stack/stack.hpp"

namespace il_machine::runtime
{
    class IlRuntime
    {
        il_machine::stack::IlStack _stack;

    public:
        IlRuntime(
            il_machine::stack::IlStack stack
        );
        void start();
    };
}

#endif
