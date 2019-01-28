#include "../intermediate_lang/instructions/instructions.hpp"
#include "runtime/runtime.hpp"

namespace il_machine
{
    il_machine::runtime::IlRuntime create_runtime_from_bytecode(std::vector<intermediate_lang::instructions::InstructionContainer> instructions);
}
