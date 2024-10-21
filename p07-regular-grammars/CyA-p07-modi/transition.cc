// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  transitions.cc: funciones de la clase Transition.
//    Contiene las funciones implementadas para la clase Transition.

#include "transition.h"

Transition::Transition() {
  actual_state_ = nullptr;
  next_state_ = nullptr;
  symbol_ = Symbol();
}

Transition::Transition(State& actual_state, Symbol& symbol, State& state) {
  actual_state_ = &actual_state;
  next_state_ = &state;
  symbol_ = symbol;
}

std::ostream& operator<<(std::ostream& os, const Transition& transition) {
  os << "q" << transition.actual_state_->GetId() << " " << transition.symbol_ << " q" << transition.next_state_->GetId();
  return os;
}

State Transition::GetActualState() const {
  return *actual_state_;
}

State Transition::GetNextState() const {
  return *next_state_;
}

Symbol Transition::GetSymbol() const {
  return symbol_;
}

