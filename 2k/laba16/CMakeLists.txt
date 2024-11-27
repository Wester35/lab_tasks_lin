cmake_minimum_required(VERSION 3.27)
project(laba16 C)

set(CMAKE_C_STANDARD 11)

include_directories(libs)

add_executable(laba16
        libs/List.c
        libs/List.h
        libs/Student.c
        libs/Student.h
        main.c)
