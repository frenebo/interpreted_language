#include <vector>

#include "runtime.hpp"
#include "../../intermediate_lang/instructions/instructions.hpp"
#include "../stack/stack.hpp"

namespace il_machine::runtime
{
    // @TODO runtime options
    IlRuntime::IlRuntime(il_machine::stack::IlStack stack)
    : _stack(stack)
    {
    }

    void IlRuntime::start()
    {

    }
}
