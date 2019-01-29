#include "process_handle.hpp"
// #include <boost/process.hpp>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>

namespace module_handle::process_handle
{
    ProcessHandle::ProcessHandle(std::string exec_command)
    {
        // std::system(exec_command.c_str());
        // boost::process::child c(exec_command);


        // c.wait(); //wait for the process to exit
        // int result = c.exit_code();
        // std::cout << "Result: " << result << "\n";
        throw "unimplemented";
    }
}
