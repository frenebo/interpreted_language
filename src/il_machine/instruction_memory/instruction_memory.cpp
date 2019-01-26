#include "instruction_memory.hpp"
#include "../../intermediate_lang/instructions/instructions.hpp"

namespace il_machine::instruction_memory
{
    InstructionMemory::InstructionMemory()
    {
        _instruction_containers = std::vector<intermediate_lang::instructions::InstructionContainer>();
    }

    InstructionMemory::InstructionMemory(std::vector<intermediate_lang::instructions::InstructionContainer> instruction_containers)
    : _instruction_containers(instruction_containers)
    {
    }

    const std::vector<intermediate_lang::instructions::InstructionContainer> & InstructionMemory::instruction_containers() const
    {
        return _instruction_containers;
    }
}
