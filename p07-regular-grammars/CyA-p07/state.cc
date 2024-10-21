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

#include "state.h"

State::State() {}

State::State(std::string& id, bool is_initial, bool is_final) {
  id_ = id;
  is_initial_ = is_initial;
  is_final_ = is_final;
}

State::State(std::string file_input_line) {
  std::size_t space_position = file_input_line.find(" ");
  id_ = file_input_line.substr(0, space_position);
  file_input_line.erase(0, space_position + 1);
  is_initial_ = false;
  space_position = file_input_line.find(" ");
  std::string final = file_input_line.substr(0, space_position);
  if (final == "1") {
    is_final_ = true;
  } else {
    is_final_ = false;
  }
}

void State::AddTransition(Transition& transition) {
  transitions_.push_back(transition);
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

std::vector<State> State::GetNextTransitions(Symbol& symbol) const {
  std::vector<State> states;
  for (unsigned int index = 0; index < transitions_.size(); index++) {
    if (transitions_[index].GetSymbol() == symbol) {
      states.push_back(transitions_[index].GetNextState());
    }
  }
  return states;
}

std::vector<Transition> State::GetTransitions() const {
  return transitions_;
}

void State::SetIsFinal(bool is_final) {
  is_final_ = is_final;
}

void State::SetIsInitial(bool is_initial) {
  is_initial_ = is_initial;
}

std::ostream& operator<<(std::ostream& os, const State& State) {
  os << "q" << State.id_ << " " << State.is_initial_ << " " << State.is_final_;
  /* os << " - Transiciones: ";
  for (unsigned int index = 0; index < State.transitions_.size(); index++) {
    os << State.transitions_[index] << " ";
  } */
  //os << "q" << State.id_;
  return os;
}

bool State::operator==(const State& State) const {
  return (id_ == State.id_);
}