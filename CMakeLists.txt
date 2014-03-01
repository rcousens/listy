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
FILE(GLOB_RECURSE SourceFiles src/c*.c src/*.h)
add_executable(bin/main ${SourceFiles})