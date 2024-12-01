# Especifica los archivos fuente para las pruebas
set(TEST_SOURCES
    ../src/funciones.cpp  # Asegúrate de que todas las dependencias de las pruebas estén aquí
    test.cpp
)

# Crear el ejecutable para las pruebas
add_executable(test ${TEST_SOURCES})

# Asegúrate de que los encabezados del proyecto sean encontrados
include_directories(${CMAKE_SOURCE_DIR}/src)

# Agregar pruebas con CTest
add_test(NAME test_buscar_patron COMMAND test)
