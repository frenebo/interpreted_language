#ifndef IL_INSTRUCTIONS_H
#define IL_INSTRUCTIONS_H

#include <string>
#include <variant>

namespace intermediate_lang::instructions
{
    class IntAddInstruction
    {
    public:
        IntAddInstruction();
    };

    class IntSubtractInstruction
    {
    public:
        IntSubtractInstruction();
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
            IntAddInstruction,
            IntSubtractInstruction,
            LogValueInstruction
        > _contained_instruction;
    public:
        InstructionContainer(
            std::variant<
                LoadConstNumberInstruction,
                LoadConstStringInstruction,
                IntAddInstruction,
                IntSubtractInstruction,
                LogValueInstruction
            > contained_instruction
        );

        InstructionContainer(LoadConstNumberInstruction contained_instruction);
        InstructionContainer(LoadConstStringInstruction contained_instruction);
        InstructionContainer(IntAddInstruction contained_instruction);
        InstructionContainer(IntSubtractInstruction contained_instruction);
        InstructionContainer(LogValueInstruction contained_instruction);

        const std::variant<
            LoadConstNumberInstruction,
            LoadConstStringInstruction,
            IntAddInstruction,
            IntSubtractInstruction,
            LogValueInstruction
        > & contained_instruction() const;
    };
}

#endif
