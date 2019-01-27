#include "instructions.hpp"

namespace intermediate_lang::instructions
{
    InstructionContainer::InstructionContainer(
        std::variant<
            LoadConstNumberInstruction,
            LoadConstStringInstruction,
            AddNumbersInstruction,
            SubtractNumbersInstruction,
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

    InstructionContainer::InstructionContainer(LoadConstStringInstruction contained_instruction)
    : _contained_instruction(contained_instruction)
    {
    }

    InstructionContainer::InstructionContainer(AddNumbersInstruction contained_instruction)
    : _contained_instruction(contained_instruction)
    {
    }

    InstructionContainer::InstructionContainer(SubtractNumbersInstruction contained_instruction)
    : _contained_instruction(contained_instruction)
    {
    }

    InstructionContainer::InstructionContainer(LogValueInstruction contained_instruction)
    : _contained_instruction(contained_instruction)
    {
    }

    const std::variant<
        LoadConstNumberInstruction,
        LoadConstStringInstruction,
        AddNumbersInstruction,
        SubtractNumbersInstruction,
        LogValueInstruction
    > & InstructionContainer::contained_instruction() const
    {
        return _contained_instruction;
    }
}
