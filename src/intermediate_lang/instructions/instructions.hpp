#ifndef IL_INSTRUCTIONS_H
#define IL_INSTRUCTIONS_H

#include <variant>

namespace intermediate_lang::instructions
{
    class LoadConstNumberInstruction
    {
        double _contained_num;
    public:
        LoadConstNumberInstruction(double contained_num);
        double get_value() const;
    };

    class InstructionContainer
    {
        std::variant<LoadConstNumberInstruction> _contained_instruction;
    public:
        InstructionContainer(LoadConstNumberInstruction contained_instruction);
        InstructionContainer(std::variant<LoadConstNumberInstruction> contained_instruction);

        const std::variant<LoadConstNumberInstruction> & contained_instruction() const;
    };
}

#endif
