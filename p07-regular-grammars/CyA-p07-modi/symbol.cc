// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  symbols.cc: funciones de la clase Symbol.
//    Contiene las funciones implementadas para la clase Symbol.

#include "symbol.h"

Symbol::Symbol() {
  symbol_ = "";
}

Symbol::Symbol(std::string& simbolo_entrada) {
  symbol_ = simbolo_entrada;
}

Symbol::Symbol(const std::string& simbolo_entrada) {
  symbol_ = simbolo_entrada;
}

bool Symbol::operator==(const Symbol& simbolo_entrada) const {
  return symbol_ == simbolo_entrada.symbol_;
}

bool Symbol::operator!=(const Symbol& simbolo_entrada) const {
  return symbol_ != simbolo_entrada.symbol_;
}

std::ostream& operator<<(std::ostream& os, const Symbol& simbolo_entrada) {
  os << simbolo_entrada.symbol_;
  return os;
}