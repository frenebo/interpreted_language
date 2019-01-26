#include "instructions.hpp"

namespace intermediate_lang::instructions
{
    InstructionContainer::InstructionContainer(
        std::variant<
            LoadConstNumberInstruction,
            AddNumbersInstruction,
            LogValueInstruction
        > contained_instruction
    )
    : _contained_instruction(contained_instruction)
    {
    }

    InstructionContainer::InstructionContainer(LoadConstNumberInstruction contained_instruction)
    : _contained_instruction(contained_instruction)
    {
    }

    InstructionContainer::InstructionContainer(AddNumbersInstruction contained_instruction)
    : _contained_instruction(contained_instruction)
    {
    }

    InstructionContainer::InstructionContainer(LogValueInstruction contained_instruction)
    : _contained_instruction(contained_instruction)
    {
    }

    const std::variant<
        LoadConstNumberInstruction,
        AddNumbersInstruction,
        LogValueInstruction
    > & InstructionContainer::contained_instruction() const
    {
        return _contained_instruction;
    }
}
