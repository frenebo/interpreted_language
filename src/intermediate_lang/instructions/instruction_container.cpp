#include "instructions.hpp"

namespace intermediate_lang::instructions
{
    InstructionContainer::InstructionContainer(
        std::variant<
            LoadConstNumberInstruction,
            LoadConstStringInstruction,
            IntAddInstruction,
            IntSubtractInstruction,
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

    InstructionContainer::InstructionContainer(IntAddInstruction contained_instruction)
    : _contained_instruction(contained_instruction)
    {
    }

    InstructionContainer::InstructionContainer(IntSubtractInstruction contained_instruction)
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
        IntAddInstruction,
        IntSubtractInstruction,
        LogValueInstruction
    > & InstructionContainer::contained_instruction() const
    {
        return _contained_instruction;
    }
}
