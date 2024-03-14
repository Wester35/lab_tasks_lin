cmake_minimum_required(VERSION 3.27)
project(laba13 C)

set(CMAKE_C_STANDARD 23)

add_executable(laba13 main.c
        libs/List.c
        libs/Student.c)
