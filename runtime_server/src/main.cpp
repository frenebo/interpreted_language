#include <iostream>
#include "file_system_utils/file_system_utils.hpp"

int main()
{
    std::cout << "Hello, World!\n";
    file_system_utils::FileSystemUtils::required_dirs_exist();
}
