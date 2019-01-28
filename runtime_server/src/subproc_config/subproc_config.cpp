#include <vector>
#include <string>

#include "subproc_config.hpp"

namespace subproc_config
{
    SubprocConfig::SubprocConfig(
        std::string exec_name,
        std::vector<std::string> args,
        io_types::IoType input_type,
        io_types::IoType output_type)
    : _exec_name(exec_name),
    _args(args),
    _input_type(input_type),
    _output_type(output_type)
    {
    }

    std::vector<std::string> SubprocConfig::args() const
    {
        return _args;
    }

    std::string SubprocConfig::exec_name() const
    {
        return _exec_name;
    }

    io_types::IoType SubprocConfig::input_type() const
    {
        return _input_type;
    }

    io_types::IoType SubprocConfig::output_type() const
    {
        return _output_type;
    }
}
