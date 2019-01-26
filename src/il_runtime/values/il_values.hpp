#ifndef IL_VALUE_H
#define IL_VALUE_H

#include <variant>

namespace il_runtime::values
{
    class IlNumberValue
    {
    public:
        IlNumberValue();
    };

    class IlValueContainer
    {
    private:
        std::variant<IlNumberValue> _contained_value;
    public:
        IlValueContainer(std::variant<IlNumberValue> contained_value);
        IlValueContainer(IlNumberValue contained_value);
    };
}

#endif
