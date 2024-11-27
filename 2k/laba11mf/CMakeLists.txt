cmake_minimum_required(VERSION 3.27)
project(laba11mf C)

set(CMAKE_C_STANDARD 11)

add_executable(laba11mf
        main.c
        my_libs/Student.c
        my_libs/Student.h
        my_libs/Tree.c
        my_libs/Tree.h)
