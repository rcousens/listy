# 
# Project Configuration
#
cmake_minimum_required(VERSION 2.6)
project(C_PROJECT_TEMPLATE)

#
# Sends the -std=c99 flag to the gcc compiler
#
add_definitions(-std=c99)

#
# Compile executables.
#
FILE(GLOB_RECURSE SourceFiles src/*.c src/*.h)
add_executable(bin/main ${SourceFiles})

list(REMOVE_ITEM SourceFiles "${CMAKE_BINARY_DIR}/src/main.c")
message( ${SourceFiles} )
add_executable(bin/tests tests/main.c ${SourceFiles})