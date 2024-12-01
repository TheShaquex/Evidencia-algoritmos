# CMakeLists.txt en la raíz del proyecto

cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(EvidenciaAlgoritmos)

# Habilitar cobertura de código (si es necesario)
option(CODE_COVERAGE "Enable coverage reporting" ON)

# Si se habilita la cobertura, agregar las banderas necesarias
if(CODE_COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    set(CMAKE_CXX_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/coverage")
    set(CMAKE_C_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/coverage")
endif()

# Configurar la salida de los archivos ejecutables en la raíz
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Agregar subdirectorios (fuentes, pruebas)
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)
