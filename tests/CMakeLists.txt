# CMakeLists.txt en la carpeta tests

# Incluir CTest
include(CTest)
include(GoogleTest)  # Si estás usando Google Test

# Especifica los archivos fuente para las pruebas
set(TEST_SOURCES
    ../src/funciones.cpp  # Asegúrate de que todas las dependencias de las pruebas estén aquí
    test.cpp
)

# Crear el ejecutable para las pruebas
add_executable(test_runner ${TEST_SOURCES})

# Vincular bibliotecas de pruebas (si estás usando Google Test)
# find_package(GTest REQUIRED)
# target_link_libraries(test_runner GTest::GTest GTest::Main)

# Asegúrate de que los encabezados del proyecto sean encontrados
include_directories(${CMAKE_SOURCE_DIR}/src)

# Agregar pruebas con CTest
add_test(NAME TestBuscarPatron COMMAND test_runner)

# Si estás usando cobertura
if(CODE_COVERAGE)
    target_compile_options(test_runner PRIVATE --coverage)
    target_link_options(test_runner PRIVATE --coverage)
endif()