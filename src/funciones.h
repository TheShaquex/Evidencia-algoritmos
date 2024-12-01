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

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <vector>
#include <utility>

/**
 * @brief Lee el contenido de un archivo y lo retorna como un string.
 * 
 * @param nombreArchivo Ruta del archivo a leer.
 * @return El contenido del archivo como un string.
 */
std::string leer_archivo(const std::string &nombre_archivo);

/**
 * @brief Calcula el arreglo Z para un string dado.
 * 
 * @param s El string de entrada.
 * @return Un vector de enteros que contiene los valores del arreglo Z.
 */
std::vector<int> calcular_z(const std::string &s);

/**
 * @brief Busca un patrón dentro de un texto utilizando el algoritmo Z.
 * 
 * @param texto El texto donde buscar.
 * @param patron El patrón a buscar.
 * @param posicion_inicio La posición inicial donde se encuentra el patrón.
 * @return true Si el patrón se encuentra en el texto.
 * @return false Si el patrón no se encuentra en el texto.
 */
bool buscar_patron(const std::string &texto, const std::string &patron, int &posicion_inicio);

/**
 * @brief Encuentra el palíndromo más largo en un string utilizando el algoritmo de Manacher.
 * 
 * @param s El string de entrada.
 * @param palindromo Referencia a un string donde se almacenará el palíndromo encontrado.
 * @return Un par de enteros indicando la posición inicial y final del palíndromo en el string original.
 */
std::pair<int, int> manacher(const std::string &s, std::string &palindromo);

/**
 * @brief Encuentra el substring común más largo entre dos strings.
 * 
 * @param a Primer string de entrada.
 * @param b Segundo string de entrada.
 * @param inicio Referencia al entero donde se almacenará la posición de inicio del substring en el primer string.
 * @param fin Referencia al entero donde se almacenará la posición de fin del substring en el primer string.
 * @param substring Referencia al string donde se almacenará el substring común más largo.
 */
void sub_comun_largo(const std::string &a, const std::string &b, int &inicio, int &fin, std::string &substring);

#endif // FUNCIONES_H
