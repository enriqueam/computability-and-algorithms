// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  alphabets.cc: funciones de la clase Alphabet.
//    Contiene las funciones implementadas para la clase Alphabet.

#include "alphabets.h"

Alphabet::Alphabet() {
  alphabet_.clear();
}

void Alphabet::InsertSymbol(Symbol& simbolo_entrada) {
  alphabet_.push_back(simbolo_entrada);
}

bool Alphabet::SearchSymbol(Symbol& simbolo_entrada) {
  for (unsigned int index = 0; index < alphabet_.size(); index++) {
    if (alphabet_[index] == simbolo_entrada) {
      return true;
    }
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, const Alphabet& alfabeto_entrada) {
  for (unsigned int index = 0; index < alfabeto_entrada.alphabet_.size(); index++) {
    os << alfabeto_entrada.alphabet_[index] << " ";
  }
  return os;
}
