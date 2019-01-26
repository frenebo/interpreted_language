#ifndef IL_INSTRUCTIONS_H
#define IL_INSTRUCTIONS_H

#include <variant>

namespace intermediate_lang::instructions
{
    class AddNumbersInstruction
    {
    public:
        AddNumbersInstruction();
    };

    class LoadConstNumberInstruction
    {
        double _contained_num;
    public:
        LoadConstNumberInstruction(double contained_num);
        double get_value() const;
    };

    class LogValueInstruction
    {
    public:
        LogValueInstruction();
    };

    class InstructionContainer
    {
        std::variant<
            LoadConstNumberInstruction,
            AddNumbersInstruction,
            LogValueInstruction
        > _contained_instruction;
    public:
        InstructionContainer(
            std::variant<
                LoadConstNumberInstruction,
                AddNumbersInstruction,
                LogValueInstruction
            > contained_instruction
        );
        InstructionContainer(LoadConstNumberInstruction contained_instruction);
        InstructionContainer(AddNumbersInstruction contained_instruction);
        InstructionContainer(LogValueInstruction contained_instruction);

        const std::variant<
            LoadConstNumberInstruction,
            AddNumbersInstruction,
            LogValueInstruction
        > & contained_instruction() const;
    };
}

#endif
