#ifndef MODULE_HANDLE_HPP
#define MODULE_HANDLE_HPP

#include "../io_types/io_types.hpp"

namespace module_handle
{
    class ModuleHandle
    {
    private:
        io_types::IoType _input_type;
        io_types::IoType _output_type;
    public:
        ModuleHandle(
            io_types::IoType input_type,
            io_types::IoType output_type);
    };
}

#endif
