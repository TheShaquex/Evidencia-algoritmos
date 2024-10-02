#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Función para cargar el contenido de un archivo
string leerArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    string contenido, linea;
    while (getline(archivo, linea))
    {
        contenido += linea;
    }
    return contenido;
}

// Algoritmo Z para buscar patrón
vector<int> calcularZ(const string &s)
{
    int n = s.size();
    vector<int> Z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= R)
        {
            Z[i] = min(R - i + 1, Z[i - L]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
        {
            ++Z[i];
        }
        if (i + Z[i] - 1 > R)
        {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

// Buscar si el patrón está en el texto
bool buscarPatron(const string &texto, const string &patron, int &posicionInicio)
{
    string concatenado = patron + "$" + texto;
    vector<int> Z = calcularZ(concatenado);
    for (int i = 0; i < Z.size(); ++i)
    {
        if (Z[i] == patron.size())
        {
            posicionInicio = i - patron.size() - 1;
            return true;
        }
    }
    return false;
}

// Algoritmo Manacher para encontrar el palíndromo más largo
pair<int, int> manacher(const string &s)
{
    int n = s.size();
    vector<int> p(2 * n + 1, 0);
    int c = 0, r = 0, maxLen = 0, centerIndex = 0;
    string t = "@";
    for (char ch : s)
    {
        t += "#";
        t += ch;
    }
    t += "#$";

    for (int i = 1; i < t.size() - 1; ++i)
    {
        int mirror = 2 * c - i;
        if (i < r)
            p[i] = min(r - i, p[mirror]);
        while (t[i + p[i] + 1] == t[i - p[i] - 1])
            p[i]++;
        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }
        if (p[i] > maxLen)
        {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    int inicio = (centerIndex - maxLen) / 2;
    return {inicio, inicio + maxLen - 1};
}

// Longest Common Substring (LCS) para encontrar la subcadena común más larga
pair<int, int> LCS(const string &s1, const string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0, endPos = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    endPos = i;
                }
            }
        }
    }

    return {endPos - maxLen + 1, endPos};
}

int main()
{
    // Leer archivos de transmisión y de código malicioso
    string transmission1 = leerArchivo("transmission1.txt");
    string transmission2 = leerArchivo("transmission2.txt");
    string mcode1 = leerArchivo("mcode1.txt");
    string mcode2 = leerArchivo("mcode2.txt");
    string mcode3 = leerArchivo("mcode3.txt");

    // Parte 1: Buscar códigos maliciosos en las transmisiones
    vector<string> mcode = {mcode1, mcode2, mcode3};
    vector<string> transmissions = {transmission1, transmission2};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int posicionInicio = -1;
            bool encontrado = buscarPatron(transmissions[i], mcode[j], posicionInicio);
            if (encontrado)
            {
                cout << "true " << posicionInicio + 1 << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
    }

    cout << "Parte 2:" << endl;

    // Parte 2: Buscar el palíndromo más largo en cada transmisión
    for (int i = 0; i < 2; ++i)
    {
        pair<int, int> palindromo = manacher(transmissions[i]);
        cout << palindromo.first + 1 << " " << palindromo.second + 1 << endl;
    }

    cout << "Parte 3:" << endl;

    // Parte 3: Subcadena común más larga entre transmission1 y transmission2
    pair<int, int> lcs = LCS(transmission1, transmission2);
    cout << lcs.first << " " << lcs.second << endl;

    return 0;
}
