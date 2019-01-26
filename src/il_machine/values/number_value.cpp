#include "values.hpp"

namespace il_machine::values
{
    IlNumberValue::IlNumberValue(double contained_num)
    : _contained_num(contained_num)
    {
    }

    double IlNumberValue::contained_num() const
    {
        return _contained_num;
    }
}
