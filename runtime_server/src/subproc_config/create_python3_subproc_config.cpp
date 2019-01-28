#include <string>
#include <vector>

#include "subproc_config.hpp"

namespace subproc_config
{
    SubprocConfig create_python3_subproc_config(
        std::string script_path,
        io_types::IoType input_type,
        io_types::IoType output_type)
    {
        std::vector<std::string> args = std::vector<std::string>();

        args.push_back(script_path);

        return SubprocConfig(
            "python3",
            args,
            input_type,
            output_type
        );
    }
}
