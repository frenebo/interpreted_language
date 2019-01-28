#include "../intermediate_lang/instructions/instructions.hpp"
#include "il_machine.hpp"
#include "runtime/runtime.hpp"
#include "stack/stack.hpp"
#include "instruction_memory/instruction_memory.hpp"

namespace il_machine
{
    il_machine::runtime::IlRuntime create_runtime_from_bytecode(
        std::vector<intermediate_lang::instructions::InstructionContainer> instructions)
    {
        il_machine::stack::IlStack stack = il_machine::stack::IlStack();

        il_machine::instruction_memory::InstructionMemory instruction_memory = il_machine::instruction_memory::InstructionMemory(instructions);

        return il_machine::runtime::IlRuntime(
            stack,
            instructions
        );
    }
}
