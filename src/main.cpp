#include <iostream>
#include <vector>
#include <ctime>

#include "compiler/compiler.hpp"

int main()
{
    std::string text_to_compile =
        "a + b + 1;"
        "something = 100.0;"
        "if (1) {"
        ""
        "}";
    
    compiler::Compiler().compile_text(text_to_compile);
}