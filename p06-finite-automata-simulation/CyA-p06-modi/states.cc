// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  states.cc: funciones de la clase State.
//    Contiene las funciones implementadas para la clase State.

#include "states.h"

State::State() {
  id_ = "";
  is_initial_ = false;
  is_final_ = false;
}

State::State(std::string& id, bool is_initial, bool is_final) {
  id_ = id;
  is_initial_ = is_initial;
  is_final_ = is_final;
}

std::string State::GetId() const {
  return id_;
}

bool State::GetIsInitial() const {
  return is_initial_;
}

bool State::GetIsFinal() const {
  return is_final_;
}

void State::SetIsFinal(bool is_final) {
  is_final_ = is_final;
}

std::ostream& operator<<(std::ostream& os, const State& State) {
  // os << "q" << State.id_ << " " << State.is_initial_ << " " << State.is_final_;
  os << "q" << State.id_;
  return os;
}

bool State::operator==(const State& State) const {
  return (id_ == State.id_);
}