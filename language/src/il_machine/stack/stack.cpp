#include <vector>

#include "../values/values.hpp"
#include "stack.hpp"
#include "../il_runtime_exception.hpp"

namespace il_machine::stack
{
    IlStack::IlStack()
    {
        _value_stack = std::vector<il_machine::values::IlValueContainer>();
    }

    void IlStack::push(il_machine::values::IlValueContainer val)
    {
        _value_stack.push_back(val);
    }

    il_machine::values::IlValueContainer IlStack::pop()
    {
        if (_value_stack.size() == 0)
        {
            throw IlRuntimeException("Stack is empty, could not pop value");
        }

        il_machine::values::IlValueContainer last_item = _value_stack.back();

        _value_stack.pop_back();

        return last_item;
    }
}
