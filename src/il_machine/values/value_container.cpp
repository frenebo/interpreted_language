#include <variant>

#include "values.hpp"

namespace il_machine::values
{
    IlValueContainer::IlValueContainer(std::variant<IlNumberValue, IlStringValue> contained_value)
    : _contained_value(contained_value)
    {
    }

    IlValueContainer::IlValueContainer(IlNumberValue contained_value)
    : _contained_value(contained_value)
    {
    }

    IlValueContainer::IlValueContainer(IlStringValue contained_value)
    : _contained_value(contained_value)
    {
    }

    const std::variant<IlNumberValue, IlStringValue> & IlValueContainer::contained_value() const
    {
        return _contained_value;
    }
}
