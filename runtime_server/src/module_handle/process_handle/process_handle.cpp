#include "process_handle.hpp"
#include <boost/process.hpp>
#include <iostream>
#include <string>
#include <vector>

namespace module_handle::process_handle
{
    ProcessHandle::ProcessHandle(std::string exec_command)
    {
        boost::process::child c(exec_command);


        c.wait(); //wait for the process to exit
        int result = c.exit_code();
        std::cout << "Result: " << result << "\n";
    }
}
