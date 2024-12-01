# CMakeLists.txt en src/

# Asegúrate de incluir las banderas de cobertura en el subdirectorio
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")

# Definir las fuentes
add_library(funciones STATIC
    funciones.cpp
)

# Establecer el directorio de salida de los archivos objeto y librerías
set_target_properties(funciones PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
