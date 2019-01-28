#include "instructions.hpp"

namespace intermediate_lang::instructions
{
    LoadConstStringInstruction::LoadConstStringInstruction(std::string contained_string)
    : _contained_string(contained_string)
    {
    }

    std::string LoadConstStringInstruction::get_value() const
    {
        return _contained_string;
    }
}
