cmake_minimum_required(VERSION 3.0)
project(listy)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -ggdb")

FILE(GLOB_RECURSE SOURCE_FILES src/*.c src/*.h)

add_executable(listy src/listy.c src/single-list/single-linked-list.h src/single-list/single-linked-list.c)

