# Incluir CTest
include(CTest)

# Especifica los archivos fuente para las pruebas
set(TEST_SOURCES
    ../src/funciones.cpp
    test.cpp
)

# Crear el ejecutable para las pruebas
add_executable(test_runner ${TEST_SOURCES})

# Asegúrate de que los encabezados del proyecto sean encontrados
include_directories(${CMAKE_SOURCE_DIR}/src)

# Agregar pruebas con CTest
add_test(NAME TestBuscarPatron COMMAND test_runner)

# Si estás usando cobertura
if(CODE_COVERAGE)
    target_compile_options(test_runner PRIVATE --coverage)
    target_link_options(test_runner PRIVATE --coverage)
endif()