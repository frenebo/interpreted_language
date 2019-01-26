#include "instructions.hpp"

namespace intermediate_lang::instructions
{
    InstructionContainer::InstructionContainer(std::variant<LoadConstNumberInstruction> contained_instruction)
    : _contained_instruction(contained_instruction)
    {
    }

    InstructionContainer::InstructionContainer(LoadConstNumberInstruction contained_instruction)
    : _contained_instruction(contained_instruction)
    {
    }
}
