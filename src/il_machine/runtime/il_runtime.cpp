#include <vector>

#include "il_runtime.hpp"
#include "../../intermediate_lang/instructions/instructions.hpp"
#include "../stack/stack.hpp"

namespace il_machine::runtime
{
    // @TODO runtime options
    IlRuntime::IlRuntime()
    {
        _stack = il_runtime::stack::IlStack();
    }

    void IlRuntime::start()
    {

    }

    IlRuntime IlRuntime::run_bytecode(const std::vector<intermediate_lang::instructions::InstructionContainer> & instructions)
    {
        IlRuntime runtime = IlRuntime();

        return runtime;
    }
}
