cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(Arithmetic)

include(cmake/function.cmake)

add_subdirectory(list)
add_subdirectory(stackonlist)
add_subdirectory(lib_arithmetic)

add_subdirectory(main)

option(BTEST "build test?" ON)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()
