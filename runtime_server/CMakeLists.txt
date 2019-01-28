cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE proj_SRC
    "src/*.h"
    "src/*.hpp"
    "src/*.cpp"
)

add_executable(runtime_server ${proj_SRC})

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wswitch-enum -lboost_system-mt")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

find_package(Boost REQUIRED COMPONENTS system filesystem)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(runtime_server ${Boost_LIBRARIES})
