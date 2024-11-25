// Copyright (c) 2024, Isaac Alejandro Enriquez Trejo y Kaled Noe Enriquez Trejo
// Todos los derechos reservados.
//
// Licenciado bajo la Licencia MIT. Ver el archivo LICENSE para más detalles.
#include "funciones.h"
#include <iostream>
#include <cassert>

using namespace std;

void testBuscarPatron() {
    string texto = "hola mundo";
    string patron = "mundo";
    int posicionInicio;
    bool encontrado = buscarPatron(texto, patron, posicionInicio);
    assert(encontrado == true);
    assert(posicionInicio == 5);
}

void testManacher() {
    string texto = "abacabad";
    string palindromo;
    pair<int, int> resultado = manacher(texto, palindromo);
    assert(resultado.first == 1 && resultado.second == 7);
    assert(palindromo == "abacaba");
}

int main() {
    testBuscarPatron();
    testManacher();
    std::cout << "Todas las pruebas pasaron." << std::endl;
    return 0;
}
