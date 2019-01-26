#ifndef IL_STACK_H
#define IL_STACK_H

#include <vector>

#include "../values/values.hpp"

namespace il_machine::stack
{
    class IlStack
    {
        std::vector<il_machine::values::IlValueContainer> _value_stack;
    public:
        IlStack();
        void push(il_machine::values::IlValueContainer val);
        il_machine::values::IlValueContainer pop();
    };
}

#endif
