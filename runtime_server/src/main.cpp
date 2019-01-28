#include <iostream>
#include <string>
#include <vector>

#include "io_types/io_types.hpp"
#include "module_handle/module_handle.hpp"
#include "subproc_config/subproc_config.hpp"
// #include "file_system_utils/file_system_utils.hpp"

int main()
{
    auto prog_py_config = subproc_config::create_python3_subproc_config(
        "prog.py",
        io_types::IoType::JSON,
        io_types::IoType::JSON
    );

    auto py_module = module_handle::create_process_module(prog_py_config);

    return 0;
}
