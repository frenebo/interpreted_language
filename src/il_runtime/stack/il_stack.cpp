#include <vector>

#include "../values/il_values.hpp"
#include "il_stack.hpp"

namespace il_runtime::stack
{
    IlStack::IlStack()
    {
        _value_stack = std::vector<il_runtime::values::IlValueContainer>();
    }

    void IlStack::push(il_runtime::values::IlValueContainer val)
    {
        _value_stack.push_back(val);
    }

    il_runtime::values::IlValueContainer IlStack::pop()
    {
        il_runtime::values::IlValueContainer last_item = _value_stack.back();

        _value_stack.pop_back();

        return last_item;
    }
}
