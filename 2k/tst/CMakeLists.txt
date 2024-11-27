cmake_minimum_required(VERSION 3.27)
project(tst C)

set(CMAKE_C_STANDARD 11)

add_executable(tst
        main.c
        my_lib.c
        my_lib.h)
