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
        if (Z[i] == patron.size()) {
            posicionInicio = i - patron.size() - 1; // Ajustar la posición
            return true;
        }
    }
    return false;
}

// Función para encontrar el palíndromo más largo usando Manacher
pair<int, int> manacher(const string &s, string &palindromo) {
    int n = s.size();
    
    // Transformamos la cadena para manejar palíndromos pares e impares uniformemente
    string T = "^#";
    for (char c : s) {
        T += c;
        T += '#';
    }
    T += '$';

    int m = T.size();
    vector<int> P(m, 0);
    int C = 0, R = 0;

    for (int i = 1; i < m - 1; ++i) {
        int mirror = 2 * C - i;
        if (i < R) {
            P[i] = min(R - i, P[mirror]);
        }

        // Intenta expandir el palíndromo centrado en i
        while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }

        // Si expande más allá de R, actualizamos el centro y el radio
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Encontrar la longitud máxima del palíndromo
    int longitudMaxima = 0;
    int centroIndex = 0;
    for (int i = 1; i < m - 1; ++i) {
        if (P[i] > longitudMaxima) {
            longitudMaxima = P[i];
            centroIndex = i;
        }
    }

    // Obtener el inicio y el fin del palíndromo en la cadena original
    int inicio = (centroIndex - longitudMaxima) / 2;
    int fin = inicio + longitudMaxima - 1;

    palindromo = s.substr(inicio, longitudMaxima);

    return {inicio + 1, fin + 1}; // Convertimos a base 1
}

// Función para encontrar el substring común más largo
void encontrarSubstringComunMasLargo(const string &a, const string &b, int &inicio, int &fin, string &substring) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> tabla(m + 1, vector<int>(n + 1, 0));

    int longitudMaxima = 0;
    inicio = 0;
    fin = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                tabla[i][j] = tabla[i - 1][j - 1] + 1;
                if (tabla[i][j] > longitudMaxima) {
                    longitudMaxima = tabla[i][j];
                    inicio = i - longitudMaxima;
                    fin = i;
                    substring = a.substr(inicio, longitudMaxima);
                }
            }
        }
    }

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

    // Parte1: Analizar si los códigos maliciosos están en las transmisiones
    for (int i = 0; i < 2; ++i) { // Iterar sobre las transmisiones
        for (int j = 0; j < 3; ++j) { // Iterar sobre los códigos maliciosos
            int posicionInicio;
            bool encontrado = buscarPatron(transmissions[i], mcode[j], posicionInicio);
            if (encontrado) {
                cout << "true " << posicionInicio + 1 << endl;
            } else {
                cout << "false" << endl;
            }
        }
    }

    // Parte 2: Buscar el palíndromo más largo en cada transmisión
    cout << "Parte 2:" << endl;

    for (const auto &transmission : transmissions) {
        string palindromo;
        pair<int, int> resultado = manacher(transmission, palindromo);
        cout << resultado.first << " " << resultado.second << " " << palindromo << endl;
    }

    // Parte 3: Buscar el substring común más largo entre las transmisiones
    cout << "Parte 3:" << endl;

    int inicio, fin;
    string substring;
    encontrarSubstringComunMasLargo(transmission1, transmission2, inicio, fin, substring);
    cout << inicio + 1 << " " << fin + 1 << " " << substring << endl;

    return 0;
}