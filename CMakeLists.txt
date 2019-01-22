cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE proj_SRC
    "src/*.h"
    "src/*.hpp"
    "src/*.cpp"
)

add_executable(lang ${proj_SRC})

