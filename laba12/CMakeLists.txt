cmake_minimum_required(VERSION 3.27)
project(laba12 C)

set(CMAKE_C_STANDARD 23)

add_executable(laba12 main.c
        libs/List.c
        libs/List.h
        libs/Student.c
        libs/Student.h)
