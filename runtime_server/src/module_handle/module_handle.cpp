#include "module_handle.hpp"
#include "../io_types/io_types.hpp"

namespace module_handle
{
    ModuleHandle::ModuleHandle(
        io_types::IoType input_type,
        io_types::IoType output_type,
        process_handle::ProcessHandle proc_handle)
    : _input_type(input_type),
    _output_type(output_type),
    _proc_handle(proc_handle)
    {
    }
}
