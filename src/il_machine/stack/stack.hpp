#ifndef IL_STACK_H
#define IL_STACK_H

#include <vector>

#include "../values/values.hpp"

namespace il_machine::stack
{
    class IlStack
    {
        std::vector<il_runtime::values::IlValueContainer> _value_stack;
    public:
        IlStack();
        void push(il_runtime::values::IlValueContainer val);
        il_runtime::values::IlValueContainer pop();
    };
}

#endif
