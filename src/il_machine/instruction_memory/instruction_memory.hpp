#ifndef IL_INSTRUCTION_MEMORY_H
#define IL_INSTRUCTION_MEMORY_H

#include <vector>

#include "../../intermediate_lang/instructions/instructions.hpp"

namespace il_machine::instruction_memory
{
    class InstructionMemory
    {
        std::vector<intermediate_lang::instructions::InstructionContainer> _instruction_containers;
    public:
        InstructionMemory();
        InstructionMemory(std::vector<intermediate_lang::instructions::InstructionContainer> instruction_containers);


        const std::vector<intermediate_lang::instructions::InstructionContainer> & instruction_containers() const;
    };
}

#endif
