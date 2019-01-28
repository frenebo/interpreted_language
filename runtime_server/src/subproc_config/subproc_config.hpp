#ifndef SUBPROC_CONFIG_HPP
#define SUBPROC_CONFIG_HPP

#include <string>
#include <vector>

#include "../io_types/io_types.hpp"

namespace subproc_config
{
    class SubprocConfig
    {
        std::string _exec_name;
        std::vector<std::string> _args;
        io_types::IoType _input_type;
        io_types::IoType _output_type;
    public:
        SubprocConfig(
            std::string exec,
            std::vector<std::string> args,
            io_types::IoType input_type,
            io_types::IoType output_type);

        std::string exec_name() const;
        std::vector<std::string> args() const;
        io_types::IoType input_type() const;
        io_types::IoType output_type() const;
    };

    SubprocConfig create_python3_subproc_config(
        std::string script_path,
        io_types::IoType input_type,
        io_types::IoType output_type);
}

#endif
