// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 11/10/2022
// Archivo  lenguajes.h.
//    Contiene la declaración de la clase Lenguaje.

#include <iostream>
#include <set>

#include "cadenas.h"
#include "alfabetos.h"

# pragma once

class Lenguaje {
  public:
    Lenguaje();
    Lenguaje (Alfabeto& alfabeto_entrada);

    void InsertarCadena(Cadena& cadena_entrada);
    void InsertarCadenaVacia(Lenguaje& lenguaje);

    Lenguaje Concatenacion(Lenguaje& lenguaje_entrada);
    Lenguaje Union(Lenguaje& lenguaje_entrada);
    Lenguaje Interseccion(Lenguaje& lenguaje_entrada);
    Lenguaje Diferencia(Lenguaje& lenguaje_entrada);
    Lenguaje Inversa();
    Lenguaje Potencia();

    Alfabeto GetAlfabeto();

    friend std::ostream& operator<<(std::ostream& os, Lenguaje& lenguaje);
  private:
    std::set<Cadena> lenguaje_;
    Alfabeto alfabeto_;
};