# CMakeLists.txt en src/

# Definir las fuentes
add_library(funciones STATIC
    funciones.cpp
)

# Establecer el directorio de salida de los archivos objeto y librerías
set_target_properties(funciones PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
