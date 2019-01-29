#ifndef FILE_SYSTEM_UTILS_HPP
#define FILE_SYSTEM_UTILS_HPP

#include <string>

namespace file_system_utils
{
    class FileSystemUtils
    {
    private:
        static std::string named_pipe_dir_name();
    public:
        static bool try_make_pipe(std::string pipe_name);
        static bool required_dirs_exist();
        static bool create_required_dirs();
    };
}

#endif
