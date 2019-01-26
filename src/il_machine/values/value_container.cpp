#include "values.hpp"

namespace il_machine::values
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
