#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Función para cargar el contenido de un archivo
string leerArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string contenido;
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            contenido += linea + "\n"; // Agregar cada línea y un salto de línea
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
    return contenido;
}

// Algoritmo Z para buscar patrón
vector<int> calcularZ(const string &s) {
    int n = s.size();
    vector<int> Z(n);
    int L = 0, R = 0;

    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R] == s[R - L]) {
                R++;
            }
            Z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1) {
                Z[i] = Z[k];
            } else {
                L = i;
                while (R < n && s[R] == s[R - L]) {
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}

// Buscar si el patrón está en el texto
bool buscarPatron(const string &texto, const string &patron, int &posicionInicio) {
    string concatenado = patron + "$" + texto;
    vector<int> Z = calcularZ(concatenado);

    for (int i = 0; i < Z.size(); ++i) {
        // Si Z[i] es igual a la longitud del patrón, significa que se encontró el patrón
        if (Z[i] == patron.size()) {
            posicionInicio = i - patron.size() - 1; // Ajustar la posición
            return true;
        }
    }
    return false;
}

int main() {
    // Leer archivos de transmisión y de código malicioso
    string transmission1 = leerArchivo("transmission1.txt");
    string transmission2 = leerArchivo("transmission2.txt");
    string mcode1 = leerArchivo("mcode1.txt");
    string mcode2 = leerArchivo("mcode2.txt");
    string mcode3 = leerArchivo("mcode3.txt");

    vector<string> mcode = {mcode1, mcode2, mcode3};
    vector<string> transmissions = {transmission1, transmission2};

    cout << "Parte 1:" << endl;

    // Analizar si los códigos maliciosos están en las transmisiones
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

    cout << "Parte 3:" << endl;

    return 0;
}
