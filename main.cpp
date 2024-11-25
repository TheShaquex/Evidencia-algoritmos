// Copyright (c) 2024, Isaac Alejandro Enriquez Trejo y Kaled Noe Enriquez Trejo
// Todos los derechos reservados.
//
// Licenciado bajo la Licencia MIT. Ver el archivo LICENSE para más detalles.
#include "funciones.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string transmission1 = leerArchivo("transmission1.txt");
    string transmission2 = leerArchivo("transmission2.txt");
    string mcode1 = leerArchivo("mcode1.txt");
    string mcode2 = leerArchivo("mcode2.txt");
    string mcode3 = leerArchivo("mcode3.txt");

    vector<string> mcode = {mcode1, mcode2, mcode3};
    vector<string> transmissions = {transmission1, transmission2};

    cout << "Parte 1:" << endl;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            int posicionInicio;
            bool encontrado = buscarPatron(transmissions[i], mcode[j], posicionInicio);
            if (encontrado) {
                cout << "true " << posicionInicio + 1 << endl;
            } else {
                cout << "false" << endl;
            }
        }
    }

    cout << "Parte 2:" << endl;

    for (const auto &transmission : transmissions) {
        string palindromo;
        pair<int, int> resultado = manacher(transmission, palindromo);
        cout << resultado.first << " " << resultado.second << " " << palindromo << endl;
    }

    cout << "Parte 3:" << endl;

    int inicio, fin;
    string substring;
    encontrarSubstringComunMasLargo(transmission1, transmission2, inicio, fin, substring);
    cout << inicio + 1 << " " << fin + 1 << " " << substring << endl;

    return 0;
}