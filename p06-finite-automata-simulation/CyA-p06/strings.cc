// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  strings.cc: funciones de la clase String.
//    Contiene las funciones implementadas para la clase String.

#include "strings.h"

String::String() {
  string_.clear();
}

String::String(Alphabet& input_alphabet, std::vector<Symbol>& cadena) {
  alphabet_ = input_alphabet;
  string_ = cadena;
}

String::String(Alphabet& alfabeto, std::string& cadena_entrada) {
  alphabet_ = alfabeto;
  string_.clear();
  int iterador = 1;
  int longitud = cadena_entrada.length();
  while(cadena_entrada != "") {
    std::string simbolo_entrada = cadena_entrada.substr(0, iterador);
    Symbol simbolo(simbolo_entrada);
    if (alfabeto.SearchSymbol(simbolo)) {
      string_.push_back(simbolo);
      cadena_entrada.erase(0, iterador);
      iterador = 1;
    } else {
      iterador++;
    }
    if (iterador > longitud) {
      std::cout << "Error: El simbolo " << simbolo_entrada << " no pertenece al alfabeto" << std::endl;
      string_.clear();
      break;
    }
  }
}

void String::SetAlphabet(Alphabet& input_alphabet) {
  alphabet_ = input_alphabet;
}

void String::InsertSymbol(Symbol& simbolo_entrada) {
  string_.push_back(simbolo_entrada);
}

void String::InsertEmptyString(std::vector<String>& strings) {
  Symbol empty_symbol(EMPTY);
  String empty_string;
  empty_string.InsertSymbol(empty_symbol);
  strings.push_back(empty_string);
}

std::vector<Symbol> String::GetCadena() {
  return string_;
}

bool String::operator==(String& cadena) {
  if (string_.size() != cadena.string_.size()) {
    return false;
  }
  for (unsigned int index = 0; index < string_.size(); index++) {
    if (string_[index] != cadena.string_[index]) {
      return false;
    }
  }
  return true;
}

std::ostream& operator<<(std::ostream& os, String& cadena) {
  for (unsigned int index = 0; index < cadena.string_.size(); index++) {
    os << cadena.string_[index];
  }
  return os;
}
