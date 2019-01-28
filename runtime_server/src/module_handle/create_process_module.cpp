#include "process_handle/process_handle.hpp"
#include "module_handle.hpp"
#include "../subproc_config/subproc_config.hpp"

namespace module_handle
{
    ModuleHandle create_process_module(subproc_config::SubprocConfig subproc_config)
    {
        std::string exec_command = subproc_config.exec_name();
        for (std::string arg : subproc_config.args())
        {
            exec_command += " " + arg;
        }

        auto proc_handle = module_handle::process_handle::ProcessHandle(
            exec_command
        );

        auto module_handle = ModuleHandle(
            subproc_config.input_type(),
            subproc_config.output_type(),
            proc_handle);

        return module_handle;
    }
}
