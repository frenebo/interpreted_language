#include "instructions.hpp"

namespace intermediate_lang::instructions
{
    LoadConstNumberInstruction::LoadConstNumberInstruction(double contained_num)
    : _contained_num(contained_num)
    {
    }

    double LoadConstNumberInstruction::get_value() const
    {
        return _contained_num;
    }
}
