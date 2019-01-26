#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

#include "compiler/compiler.hpp"
#include "il_machine/il_machine.hpp"
#include "il_machine/il_runtime_exception.hpp"
#include "intermediate_lang/instructions/instructions.hpp"

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

        input_text.assign(
            std::istreambuf_iterator<char>(input_file),
            std::istreambuf_iterator<char>()
        );
    }
    else
    {
        std::cout << "Could not open file \"" << file_name << "\"\n";
        return 1;
    }

    compiler::Compiler().compile_text(input_text);

    std::vector<intermediate_lang::instructions::InstructionContainer> instructions;

    for (int i = 0; i < 100; i++) {
        instructions.push_back(
            intermediate_lang::instructions::LoadConstNumberInstruction(10)
        );

        instructions.push_back(
            intermediate_lang::instructions::LoadConstNumberInstruction(20)
        );

        instructions.push_back(
            intermediate_lang::instructions::AddNumbersInstruction()
        );

        instructions.push_back(
            intermediate_lang::instructions::LoadConstNumberInstruction(20)
        );

        instructions.push_back(
            intermediate_lang::instructions::AddNumbersInstruction()
        );

        instructions.push_back(
            intermediate_lang::instructions::LogValueInstruction()
        );

        instructions.push_back(
            intermediate_lang::instructions::LoadConstStringInstruction("Hello, World!")
        );

        instructions.push_back(
            intermediate_lang::instructions::LogValueInstruction()
        );
    }

    try
    {
        std::clock_t machine_clock_start = std::clock();
        auto runtime = il_machine::create_runtime_from_bytecode(
            instructions
        );
        runtime.start();
        double machine_duration = ( std::clock() - machine_clock_start ) / (double) CLOCKS_PER_SEC;

        std::cout << "Machine duration: " << machine_duration << " seconds\n";
    }
    catch (const il_machine::IlRuntimeException & ex)
    {
        std::cout << "RUNTIME EXCEPTION: " << ex.what() << "\n";
    }
}
