// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 04/10/2022
// Archivo  alfabetos.h: cabecera de la clase Alfabeto.
//    Contiene las funciones declaradas para la clase Alfabeto.

#include <iostream>
#include <vector>

#include "simbolos.h"

#pragma once

class Alfabeto {
  public:
    Alfabeto();

    void InsertarSimbolo(Simbolo& simbolo_entrada);
    bool BuscarSimbolo(Simbolo& simbolo_entrada);

    friend std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto_entrada);

  private:
    std::vector<Simbolo> alfabeto_;
};