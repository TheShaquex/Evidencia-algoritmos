#include <iostream>
#include "main.cpp" // Incluye las funciones de main.cpp

int testBuscarPatron() {
    std::string texto = "abcdabcabcd";
    std::string patron = "abc";
    int posicionInicio;
    if (buscarPatron(texto, patron, posicionInicio) && posicionInicio == 0) {
        return 0; // Éxito
    }
    return 1; // Fallo
}

int testManacher() {
    std::string texto = "abacdfgdcaba";
    std::string palindromo;
    auto resultado = manacher(texto, palindromo);
    if (resultado.first == 1 && resultado.second == 3 && palindromo == "aba") {
        return 0; // Éxito
    }
    return 1; // Fallo
}

int main() {
    int result = 0;

    // Ejecutar pruebas
    result += testBuscarPatron();
    result += testManacher();

    if (result == 0) {
        std::cout << "Todas las pruebas pasaron correctamente." << std::endl;
        return 0; // Éxito total
    } else {
        std::cerr << "Algunas pruebas fallaron." << std::endl;
        return result; // Fallos
    }
}
