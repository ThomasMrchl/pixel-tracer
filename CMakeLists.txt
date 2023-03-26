cmake_minimum_required(VERSION 3.24)
project(pixel_tracer C)

set(CMAKE_C_STANDARD 11)

add_executable(pixel_tracer
        main.c point.c point.h line.c line.h circle.c circle.h square.h square.c rectangle.h rectangle.c polygon.c polygon.h main.c main.c point.c)
