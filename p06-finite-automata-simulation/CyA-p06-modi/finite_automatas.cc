// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  finite_automatas.cc: funciones de la clase FiniteAutomata.
//    Contiene las funciones implementadas para la clase FiniteAutomata.
#include "finite_automatas.h"

FiniteAutomata::FiniteAutomata() {
  result_ = false;
}

FiniteAutomata::FiniteAutomata(std::vector<State>& states, std::vector<Transition>& transitions, Alphabet& alfabeto) {
  states_ = states;
  std::cout << std::endl;
  transitions_ = transitions;
  result_ = false;
  alfabeto_ = alfabeto;
}

std::vector<State> FiniteAutomata::Posibilities(const State& state, Symbol& symbol) {
  std::vector<State> posibilities;
  for (unsigned int index = 0; index < transitions_.size(); index++) {
    if (transitions_[index].GetActualState() == state && transitions_[index].GetSymbol() == symbol) {
      posibilities.push_back(transitions_[index].GetNextState());
    }
  }
  return posibilities;
}

bool FiniteAutomata::Comprobar(String& String, unsigned int index_cadena, const State& state) {
  // path_ += state.GetId() + " ";
  if (index_cadena == String.GetCadena().size() && state.GetIsFinal()) {
    return true;
  }
  std::vector<State> posibilities = Posibilities(state, String.GetCadena()[index_cadena]);
  for (unsigned int index = 0; index < posibilities.size(); index++) {
    if (Comprobar(String, index_cadena + 1, posibilities[index])) {
      return true;
    }
  }
  return false;
}

bool FiniteAutomata::Resolve(String& String) {
  std::cout << "String: " << String << std::endl;
  State actual_state;
  for (unsigned int index = 0; index < states_.size(); index++) {
    if (states_[index].GetIsInitial()) {
      actual_state = states_[index];
    }
  }
  if (Comprobar(String, 0, actual_state)) {
    std::cout << "String aceptada" << std::endl << std::endl;
    return true;
  } else {
    std::cout << "String no aceptada" << std::endl << std::endl;
    return false;
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, const FiniteAutomata& FiniteAutomata) {
  os << "Alphabet: ";
  os << FiniteAutomata.alfabeto_ << std::endl;
  os << "Estados: ";
  for (unsigned int index = 0; index < FiniteAutomata.states_.size(); index++) {
    os << FiniteAutomata.states_[index] << " ";
  }
  os << std::endl;
  os << " - Inicial: ";
  for (unsigned int index = 0; index < FiniteAutomata.states_.size(); index++) {
    if (FiniteAutomata.states_[index].GetIsInitial()) {
      os << FiniteAutomata.states_[index] << " ";
    }
  }
  os << std::endl;
  os << " - Final(es): ";
  for (unsigned int index = 0; index < FiniteAutomata.states_.size(); index++) {
    if (FiniteAutomata.states_[index].GetIsFinal()) {
      os << FiniteAutomata.states_[index] << " ";
    }
  }
  os << std::endl;
  os << "Transiciones: " << std::endl;
  for (unsigned int index = 0; index < FiniteAutomata.transitions_.size(); index++) {
    os << FiniteAutomata.transitions_[index] << std::endl;
  }
  return os;
}