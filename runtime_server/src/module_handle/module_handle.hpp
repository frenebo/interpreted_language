#ifndef MODULE_HANDLE_HPP
#define MODULE_HANDLE_HPP

#include "../io_types/io_types.hpp"
#include "process_handle/process_handle.hpp"
#include "../subproc_config/subproc_config.hpp"

namespace module_handle
{
    class ModuleHandle
    {
    private:
        io_types::IoType _input_type;
        io_types::IoType _output_type;
        process_handle::ProcessHandle _proc_handle;
    public:
        ModuleHandle(
            io_types::IoType input_type,
            io_types::IoType output_type,
            process_handle::ProcessHandle proc_handle);
    };

    ModuleHandle create_process_module(subproc_config::SubprocConfig config);
}

#endif
