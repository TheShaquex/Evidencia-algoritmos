// Copyright (c) 2024, Isaac Alejandro Enriquez Trejo y Kaled Noe Enriquez Trejo
// Todos los derechos reservados.
//
// Licenciado bajo la Licencia MIT. Ver el archivo LICENSE para más detalles.
#include "funciones.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string leerArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string contenido;
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            contenido += linea + "\n";
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
    return contenido;
}

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

bool buscarPatron(const string &texto, const string &patron, int &posicionInicio) {
    string concatenado = patron + "$" + texto;
    vector<int> Z = calcularZ(concatenado);

    for (int i = 0; i < Z.size(); ++i) {
        if (Z[i] == patron.size()) {
            posicionInicio = i - patron.size() - 1;
            return true;
        }
    }
    return false;
}

pair<int, int> manacher(const string &s, string &palindromo) {
    int n = s.size();
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

        while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int longitudMaxima = 0;
    int centroIndex = 0;
    for (int i = 1; i < m - 1; ++i) {
        if (P[i] > longitudMaxima) {
            longitudMaxima = P[i];
            centroIndex = i;
        }
    }

    int inicio = (centroIndex - longitudMaxima) / 2;
    int fin = inicio + longitudMaxima - 1;

    palindromo = s.substr(inicio, longitudMaxima);
    palindromo.erase(remove_if(palindromo.begin(), palindromo.end(), [](unsigned char c) { return c == '\n'; }), palindromo.end());

    return {inicio + 1, fin + 1};
}

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
