cmake_minimum_required(VERSION 3.27)
project(laba14 C)

set(CMAKE_C_STANDARD 23)

add_executable(laba14 main.c
        libs/Student.c
        libs/List.c
        libs/File.c
        libs/File.h)
