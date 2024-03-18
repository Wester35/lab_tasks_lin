cmake_minimum_required(VERSION 3.27)
project(laba15_ C)

set(CMAKE_C_STANDARD 11)

include_directories(libs)

add_executable(laba15_
        libs/List.c
        libs/List.h
        libs/Student.c
        libs/Student.h
        main.c)
