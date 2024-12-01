/*
 * MIT License
 * 
 * Copyright (c) 2024 Isaac Alejandro Enríquez Trejo, Kaled Noé Enríquez Trejo
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "funciones.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string transmission1 = leer_archivo("transmission1.txt");
    string transmission2 = leer_archivo("transmission2.txt");
    string mcode1 = leer_archivo("mcode1.txt");
    string mcode2 = leer_archivo("mcode2.txt");
    string mcode3 = leer_archivo("mcode3.txt");

    vector<string> mcode = {mcode1, mcode2, mcode3};
    vector<string> transmissions = {transmission1, transmission2};

    cout << "Parte 1:" << endl;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            int posicionInicio;
            bool encontrado = buscar_patron(transmissions[i], mcode[j], posicionInicio);
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
    sub_comun_largo(transmission1, transmission2, inicio, fin, substring);
    cout << inicio + 1 << " " << fin + 1 << " " << substring << endl;

    return 0;
}
