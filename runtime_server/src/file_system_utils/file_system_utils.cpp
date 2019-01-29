#include "file_system_utils.hpp"
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>

namespace file_system_utils
{
    std::string FileSystemUtils::named_pipe_dir_name()
    {
        return "named_pipes";
    }

    bool dir_exists(std::string path_name)
    {
        struct stat info;

        // nothing found with given name
        if (stat(path_name.c_str(), &info) != 0)
        {
            return false;
        }
        // is a directory
        else if (info.st_mode & S_IFDIR)
        {
            return true;
        }
        // is a file
        else
        {
            return false;
        }
    }

    bool file_exists(std::string path_name)
    {
        struct stat info;

        // nothing found with given name
        if (stat(path_name.c_str(), &info) != 0)
        {
            return false;
        }
        // is a directory
        else if (info.st_mode & S_IFDIR)
        {
            return false;
        }
        // is a file
        else
        {
            return true;
        }
    }

    bool fs_remove(std::string path_name)
    {
        return remove(path_name.c_str()) == 0;
    }

    bool fs_create_dir(std::string path_name)
    {
        return mkdir(path_name.c_str(), 0775) == 0;
    }

    // @TODO check for files that have the names that dirs should have?
    bool FileSystemUtils::required_dirs_exist()
    {
        return dir_exists(named_pipe_dir_name());
    }

    bool FileSystemUtils::create_required_dirs()
    {
        if (!dir_exists(named_pipe_dir_name()))
        {
            if (file_exists(named_pipe_dir_name()))
            {
                bool could_remove = fs_remove(named_pipe_dir_name());

                if (!could_remove) return false;
            }

            bool could_create = fs_create_dir(named_pipe_dir_name());

            if (!could_create) return false;
        }

        return true;
    }

    bool FileSystemUtils::try_make_pipe(std::string pipe_name)
    {
        int return_code = mkfifo(pipe_name.c_str(), 0666);

        return return_code == 0;
    }
}
