#ifndef IL_VALUE_H
#define IL_VALUE_H

#include <string>

#include <variant>

namespace il_machine::values
{
    class IlNumberValue
    {
        double _contained_num;
    public:
        IlNumberValue(double contained_num);
        double contained_num() const;
    };

    class IlStringValue
    {
        std::string _contained_string;
    public:
        IlStringValue(std::string contained_string);
        std::string contained_string() const;
    };

    class IlValueContainer
    {
    private:
        std::variant<IlNumberValue, IlStringValue> _contained_value;
    public:
        IlValueContainer(std::variant<IlNumberValue, IlStringValue> contained_value);
        IlValueContainer(IlNumberValue contained_value);
        IlValueContainer(IlStringValue contained_value);

        const std::variant<IlNumberValue, IlStringValue> & contained_value() const;
    };
}

#endif
