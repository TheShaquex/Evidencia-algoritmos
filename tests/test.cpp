#include "funciones.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

void test_buscar_patron() {
    // Caso: Patrón encontrado
    string texto = "hola mundo";
    string patron = "mundo";
    int posicionInicio;
    bool encontrado = buscar_patron(texto, patron, posicionInicio);
    assert(encontrado == true);
    assert(posicionInicio == 5);

    // Caso: Patrón no encontrado
    patron = "adios";
    encontrado = buscar_patron(texto, patron, posicionInicio);
    assert(encontrado == false);
}

void test_manacher() {
    // Caso: Palíndromo central
    string texto = "abacabad";
    string palindromo;
    pair<int, int> resultado = manacher(texto, palindromo);
    assert(resultado.first == 1 && resultado.second == 7);
    assert(palindromo == "abacaba");

    // Caso: Palíndromo sencillo
    texto = "racecar";
    resultado = manacher(texto, palindromo);
    assert(resultado.first == 1 && resultado.second == 7);
    assert(palindromo == "racecar");

    // Caso: Sin palíndromos largos
    texto = "abcd";
    resultado = manacher(texto, palindromo);
    assert(resultado.first == 1 && resultado.second == 1);
    assert(palindromo == "a");
}

int main() {
    test_buscar_patron();
    test_manacher();
    std::cout << "Todas las pruebas pasaron correctamente." << std::endl;
    return 0;
}
