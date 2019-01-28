#include "values.hpp"

namespace il_machine::values
{
    IlIntValue::IlIntValue(int contained_num)
    : _contained_num(contained_num)
    {
    }

    int IlIntValue::contained_num() const
    {
        return _contained_num;
    }
}
