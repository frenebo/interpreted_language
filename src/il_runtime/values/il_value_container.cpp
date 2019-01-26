#include "il_values.hpp"

namespace il_runtime::values
{
    IlValueContainer::IlValueContainer(std::variant<IlNumberValue> contained_value)
    : _contained_value(contained_value)
    {
    }

    IlValueContainer::IlValueContainer(IlNumberValue contained_value)
    : _contained_value(contained_value)
    {
    }
}
