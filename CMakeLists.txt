cmake_minimum_required(VERSION 3.9)
project(ProjetoListaProntos C)

set(CMAKE_C_STANDARD 99)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(SOURCE_FILES main.c)
add_executable(ProjetoListaProntos main.c)