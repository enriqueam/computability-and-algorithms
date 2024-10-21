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

#include "alphabet.h"

Alphabet::Alphabet() {
  alphabet_.clear();
}

Alphabet::Alphabet(std::string& alphabet_line) {
 while (alphabet_line != "") {
    std::size_t space_position = alphabet_line.find(SPACE);
    if (space_position != std::string::npos) {
      ExtractAlphabet(alphabet_line, space_position);
    } else {
      Symbol symbol(alphabet_line);
      InsertSymbol(symbol);
      alphabet_line.erase(0, alphabet_line.length());
    }
  }
}

void Alphabet::ExtractAlphabet(std::string& line, std::size_t& space_position) {
  std::string input_symbol = line.substr(0, space_position);
  Symbol symbol(input_symbol);
  InsertSymbol(symbol);
  line.erase(0, line.find(SPACE) + 1);
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

std::vector<Symbol> Alphabet::GetSymbols() const {
  return alphabet_;
}

std::ostream& operator<<(std::ostream& os, const Alphabet& alfabeto_entrada) {
  for (unsigned int index = 0; index < alfabeto_entrada.alphabet_.size(); index++) {
    os << alfabeto_entrada.alphabet_[index] << " ";
  }
  return os;
}
