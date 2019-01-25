#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

#include "compiler/compiler.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Program takes one argument: input file name\n";
        return 1;
    }
    // std::cout << argc << "\n";
    std::string file_name = std::string(argv[1]);

    std::ifstream input_file = std::ifstream(file_name);

    std::string input_text;
    if (input_file.is_open())
    {
        input_file.seekg(0, std::ios::end);
        input_text.reserve(input_file.tellg());
        input_file.seekg(0, std::ios::beg);

        input_text.assign((std::istreambuf_iterator<char>(input_file)),
                    std::istreambuf_iterator<char>());
    }
    else
    {
        std::cout << "Could not open file \"" << file_name << "\"\n";
    }

    compiler::Compiler().compile_text(input_text);
}
