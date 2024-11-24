cmake_minimum_required(VERSION 3.10)
project(EvidenciaAlgoritmos)

set(CMAKE_CXX_STANDARD 17)

# Ejecutable principal
add_executable(evidencia main.cpp)

# Ejecutable para pruebas
add_executable(test test.cpp)

# Habilitar pruebas con CTest
enable_testing()
add_test(NAME PruebasUnitarias COMMAND test)
