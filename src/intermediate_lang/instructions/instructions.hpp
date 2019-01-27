#ifndef IL_INSTRUCTIONS_H
#define IL_INSTRUCTIONS_H

#include <string>
#include <variant>

namespace intermediate_lang::instructions
{
    class AddNumbersInstruction
    {
    public:
        AddNumbersInstruction();
    };

    class SubtractNumbersInstruction
    {
    public:
        SubtractNumbersInstruction();
    };

    class LoadConstNumberInstruction
    {
        double _contained_num;
    public:
        LoadConstNumberInstruction(double contained_num);
        double get_value() const;
    };

    class LoadConstStringInstruction
    {
        std::string _contained_string;
    public:
        LoadConstStringInstruction(std::string contained_num);
        std::string get_value() const;
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
            LoadConstStringInstruction,
            AddNumbersInstruction,
            SubtractNumbersInstruction,
            LogValueInstruction
        > _contained_instruction;
    public:
        InstructionContainer(
            std::variant<
                LoadConstNumberInstruction,
                LoadConstStringInstruction,
                AddNumbersInstruction,
                SubtractNumbersInstruction,
                LogValueInstruction
            > contained_instruction
        );

        InstructionContainer(LoadConstNumberInstruction contained_instruction);
        InstructionContainer(LoadConstStringInstruction contained_instruction);
        InstructionContainer(AddNumbersInstruction contained_instruction);
        InstructionContainer(SubtractNumbersInstruction contained_instruction);
        InstructionContainer(LogValueInstruction contained_instruction);

        const std::variant<
            LoadConstNumberInstruction,
            LoadConstStringInstruction,
            AddNumbersInstruction,
            SubtractNumbersInstruction,
            LogValueInstruction
        > & contained_instruction() const;
    };
}

#endif
