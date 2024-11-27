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

string leer_archivo(const string &nombre_archivo) {
    ifstream archivo(nombre_archivo);
    string contenido;
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            contenido += linea + "\n";
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombre_archivo << endl;
    }
    return contenido;
}

void procesar_z_block(const string &s, vector<int> &Z, int &L, int &R, int i) {
    L = R = i;
    while (R < s.size() && s[R] == s[R - L]) {
        R++;
    }
    Z[i] = R - L;
    R--;
}

void ajustar_z_block(const string &s, vector<int> &Z, int &L, int &R, int i) {
    int k = i - L;
    if (Z[k] < R - i + 1) {
        Z[i] = Z[k];
    } else {
        procesar_z_block(s, Z, L, R, i);
    }
}

vector<int> calcular_z(const string &s) {
    int n = s.size();
    vector<int> Z(n);
    int L = 0, R = 0;

    for (int i = 1; i < n; ++i) {
        if (i > R) {
            procesar_z_block(s, Z, L, R, i);
        } else {
            ajustar_z_block(s, Z, L, R, i);
        }
    }
    return Z;
}

bool buscar_patron(const string &texto, const string &patron, int &posicion_inicio) {
    string concatenado = patron + "$" + texto;
    vector<int> Z = calcular_z(concatenado);

    for (int i = 0; i < Z.size(); ++i) {
        if (Z[i] == patron.size()) {
            posicion_inicio = i - patron.size() - 1;
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

    int longitud_maxima = 0;
    int centro_index = 0;
    for (int i = 1; i < m - 1; ++i) {
        if (P[i] > longitud_maxima) {
            longitud_maxima = P[i];
            centro_index = i;
        }
    }

    int inicio = (centro_index - longitud_maxima) / 2;
    int fin = inicio + longitud_maxima - 1;

    palindromo = s.substr(inicio, longitud_maxima);

    // Separar las declaraciones en línea única
    auto new_end = remove_if(palindromo.begin(), palindromo.end(), [](unsigned char c) {
        return c == '\n';
    });
    palindromo.erase(new_end, palindromo.end());

    return {inicio + 1, fin + 1};
}

void encontrar_substring_comun_mas_largo(const string &a, const string &b, int &inicio, int &fin, string &substring) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> tabla(m + 1, vector<int>(n + 1, 0));

    int longitud_maxima = 0;
    inicio = 0;
    fin = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                tabla[i][j] = tabla[i - 1][j - 1] + 1;
                if (tabla[i][j] > longitud_maxima) {
                    longitud_maxima = tabla[i][j];
                    inicio = i - longitud_maxima;
                    fin = i;
                    substring = a.substr(inicio, longitud_maxima);
                }
            }
        }
    }
}
