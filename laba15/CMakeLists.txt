cmake_minimum_required(VERSION 3.27)
project(laba15 C)

set(CMAKE_C_STANDARD 23)

add_executable(laba15 main.c
        libs/File.c
        libs/List.c
        libs/Student.c)
