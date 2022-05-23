cmake_minimum_required(VERSION 3.18)

project(aoc-compile-time)

set(CMAKE_CXX_STANDARD 20)

file(READ "day01.txt" input_text)
#set(input_text text,1)
string(CONCAT input_text "${input_text}")
string(REPLACE \n \\n input_text "${input_text}")


add_definitions(-DINPUT="${input_text}")

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
    # message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

include_directories(${SOURCE_DIR})
add_executable(aoc-compile-time "day01.cpp")
