# CMakeLists.txt en tests/
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")

# Incluir el directorio src para acceder a funciones.h y funciones.cc
include_directories(${CMAKE_SOURCE_DIR}/src)

# Definir el ejecutable para las pruebas
add_executable(test_pruebas test.cpp)

# Especificar las dependencias
target_link_libraries(test_pruebas funciones)

# Establecer el directorio de salida del ejecutable
set_target_properties(test_pruebas PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
