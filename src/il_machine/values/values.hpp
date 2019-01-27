#ifndef IL_VALUE_H
#define IL_VALUE_H

#include <string>

#include <variant>

namespace il_machine::values
{
    class IlIntValue
    {
        int _contained_num;
    public:
        IlIntValue(int contained_num);
        int contained_num() const;
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
        std::variant<IlIntValue, IlStringValue> _contained_value;
    public:
        IlValueContainer(std::variant<IlIntValue, IlStringValue> contained_value);
        IlValueContainer(IlIntValue contained_value);
        IlValueContainer(IlStringValue contained_value);

        const std::variant<IlIntValue, IlStringValue> & contained_value() const;
    };
}

#endif
