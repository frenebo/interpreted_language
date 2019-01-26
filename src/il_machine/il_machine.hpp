#include "../intermediate_lang/instructions/instructions.hpp"
#include "runtime/runtime.hpp"

namespace il_machine
{
    il_machine::runtime::IlRuntime run_bytecode(std::vector<intermediate_lang::instructions::InstructionContainer> instructions);
}
