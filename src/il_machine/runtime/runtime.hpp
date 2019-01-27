#ifndef IL_RUNTIME_H
#define IL_RUNTIME_H

#include <vector>

#include "../stack/stack.hpp"
#include "../instruction_memory/instruction_memory.hpp"
#include "../../intermediate_lang/instructions/instructions.hpp"

namespace il_machine::runtime
{
    class IlRuntime
    {
        il_machine::stack::IlStack _stack;
        il_machine::instruction_memory::InstructionMemory _instruction_memory;

        void execute_add_ints();
        void execute_subtract_ints();
        void execute_log_value();
        void execute_load_const_string(intermediate_lang::instructions::LoadConstStringInstruction instruction);
        void execute_load_const_num(intermediate_lang::instructions::LoadConstNumberInstruction instruction);

    public:
        IlRuntime(
            il_machine::stack::IlStack stack,
            il_machine::instruction_memory::InstructionMemory instruction_memory
        );
        void start();
    };
}

#endif
