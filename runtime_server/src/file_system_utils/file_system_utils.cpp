#include "file_system_utils.hpp"
// #include <filesyste
#include <boost/filesystem.hpp>
#include <iostream>

namespace file_system_utils
{
    bool FileSystemUtils::required_dirs_exist()
    {
        std::cout << "is directory: " << boost::filesystem::is_directory("a") << "\n";
        return false;
    }
}
