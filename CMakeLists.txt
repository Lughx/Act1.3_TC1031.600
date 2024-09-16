cmake_minimum_required(VERSION 3.29)
project(actividad1_3)

set(CMAKE_CXX_STANDARD 20)

include_directories(includes home/lughx/CLionProjects/actividad1.3/includes)

add_executable(actividad1_3 main.cpp
        includes/Orden.h
        includes/Orden.cpp
        includes/Line.cpp
        includes/Line.h
        includes/Line.cpp
        includes/Utils.cpp
        includes/Utils.h
)
