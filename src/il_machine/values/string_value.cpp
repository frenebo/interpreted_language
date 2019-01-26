#include <string>

#include "values.hpp"

namespace il_machine::values
{
    IlStringValue::IlStringValue(std::string contained_string)
    : _contained_string(contained_string)
    {
    }

    std::string IlStringValue::contained_string() const
    {
        return _contained_string;
    }
}
