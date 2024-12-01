# CMakeLists.txt en la raíz del proyecto

cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(EvidenciaAlgoritmos)

# Habilitar cobertura de código (si es necesario)
option(CODE_COVERAGE "Enable coverage reporting" ON)

# Si se habilita la cobertura, agregar las banderas necesarias
if(CODE_COVERAGE)
    # Para compiladores compatibles con gcov, como GCC y Clang
    add_compile_options(--coverage)
    link_libraries(--coverage)
endif()

# Configurar la salida de los archivos ejecutables en la raíz
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Habilitar las pruebas
enable_testing()

# Agregar subdirectorios para fuentes, aplicaciones y pruebas
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)
