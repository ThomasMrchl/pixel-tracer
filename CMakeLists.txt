cmake_minimum_required(VERSION 3.24)
project(pixel_tracer C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(pixel_tracer
        circle.c
        circle.h
        line.c
        line.h
        main.c
        point.c
        point.h
        polygon.c
        polygon.h
        rectangle.c
        rectangle.h
        shapes.c
        shapes.h
        square.c
        square.h id.c id.h)
