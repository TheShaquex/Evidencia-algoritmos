#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <vector>
#include <utility>

// Declaraciones de las funciones
std::string leerArchivo(const std::string &nombreArchivo);
std::vector<int> calcularZ(const std::string &s);
bool buscarPatron(const std::string &texto, const std::string &patron, int &posicionInicio);
std::pair<int, int> manacher(const std::string &s, std::string &palindromo);
void encontrarSubstringComunMasLargo(const std::string &a, const std::string &b, int &inicio, int &fin, std::string &substring);

#endif // FUNCIONES_H