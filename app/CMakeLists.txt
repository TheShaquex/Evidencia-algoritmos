# CMakeLists.txt en app/

# Incluir el directorio src para acceder a funciones.h y funciones.cc
include_directories(${CMAKE_SOURCE_DIR}/src)

# Definir el ejecutable
add_executable(main main.cpp)

# Especificar las dependencias
target_link_libraries(main funciones)

# Establecer el directorio de salida del ejecutable
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
