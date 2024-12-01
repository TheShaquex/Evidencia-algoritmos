cmake_minimum_required(VERSION 3.10)
project(EvidenciaAlgoritmos)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp funciones.cpp)
add_executable(test test.cpp funciones.cpp)

# Habilitar la cobertura de código
option(CODE_COVERAGE "Enable coverage reporting" ON)

if(CODE_COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
endif()
