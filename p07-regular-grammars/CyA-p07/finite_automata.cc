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

#include "finite_automata.h"

FiniteAutomata::FiniteAutomata() {
  result_ = false;
}

FiniteAutomata::FiniteAutomata(std::string& input_file_name) {
  result_ = false;
  states_ = std::vector<State>();
  std::vector<std::string> fa_input = ReadFile(input_file_name);
  alphabet_ = Alphabet(fa_input[0]);
  std::string id_initial_state = fa_input[2];
  bool initial_setted = false;
  for (unsigned int index = 3; index < fa_input.size(); index++) {
    ExtractState(fa_input[index], initial_setted, id_initial_state);
  }
  for (unsigned int index = 3; index < fa_input.size(); index++) {
    ExtractTransitions(fa_input[index]);
  }
}

void FiniteAutomata::ExtractState(std::string& line, bool& initial_setted,
                                   std::string& id_initial_state) {
  State state(line);
  if (state.GetId() == id_initial_state && !initial_setted) {
    state.SetIsInitial(true);
    initial_setted = true;
  }
  states_.push_back(state);
}

void FiniteAutomata::ExtractTransitions(std::string& line) {
  std::string id_state = std::string(1, line[0]);
  int index = SearchState(id_state);
  for (int iterator = 0; iterator < 3; iterator++) {
    line.erase(0, line.find(SPACE) + 1);
  }
  while (line != "") {
    std::size_t space_position = line.find(" ");
    if (space_position != std::string::npos) {
      Symbol symbol(line.substr(0, space_position));
      line.erase(0, space_position + 1);
      if (alphabet_.SearchSymbol(symbol)) {
        std::size_t space_position = line.find(" ");
        std::string id_state = line.substr(0, space_position);
        line.erase(0, space_position + 1);
        int index_transition = SearchState(id_state);
        Transition transition(states_[index], symbol, states_[index_transition]);
        states_[index].AddTransition(transition);
      } else {
        std::cout << "Symbol " << symbol << " not found in alphabet" << " on line: " << line << std::endl;
      }
    } else {
      line = "";
    }
  }
}

int FiniteAutomata::SearchState(std::string& id_state) {
  for (unsigned int index = 0; index < states_.size(); index++) {
    if (states_[index].GetId() == id_state) {
      return index;
    }
  }
  std::cout << "State " << id_state << " not found" << std::endl;
  return -1;
}

std::vector<std::string> FiniteAutomata::ReadFile(std::string& input_file_name) {
  std::ifstream input_file(input_file_name);
  std::string line;
  std::vector<std::string> vector_entrada;
  while (std::getline(input_file, line)) {
    vector_entrada.push_back(line);
  }
  return vector_entrada;
}

FiniteAutomata::FiniteAutomata(std::vector<State>& states, std::vector<Transition>& transitions, Alphabet& alphabet) {
  states_ = states;
  std::cout << std::endl;
  transitions_ = transitions;
  result_ = false;
  alphabet_ = alphabet;
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
  std::vector<State> posibilities = state.GetNextTransitions(String.GetCadena()[index_cadena]);
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

Alphabet FiniteAutomata::GetAlphabet() {
  return alphabet_;
}

bool FiniteAutomata::IsDeterministic() {
  for (unsigned int index = 0; index < states_.size(); index++) {
    for (unsigned int index_symbol = 0; index_symbol < alphabet_.GetSymbols().size(); index_symbol++) {
      if (states_[index].GetNextTransitions(alphabet_.GetSymbols()[index_symbol]).size() > 1) {
        return false;
      }
    }
  }
  return true;
}

Grammar FiniteAutomata::ConvertToGrammar() {
  if (IsDeterministic()) {
    Grammar grammar(alphabet_, states_);
    return grammar;
  }
  std::cout << "Can not convert to grammar, the automata is not deterministic" << std::endl;
  return Grammar();
}

std::ostream& operator<<(std::ostream& os, const FiniteAutomata& FiniteAutomata) {
  os << " - Alphabet: ";
  os << FiniteAutomata.alphabet_ << std::endl;
  os << " - Estados: " << std::endl;
  for (unsigned int index = 0; index < FiniteAutomata.states_.size(); index++) {
    os << "   " << FiniteAutomata.states_[index] << std::endl;
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
  os << " - Transiciones: " << std::endl;
  for (unsigned int index = 0; index < FiniteAutomata.states_.size(); index++) {
    os << "   " << FiniteAutomata.states_[index] << " -> ";
    for (unsigned int index_transition = 0; index_transition < FiniteAutomata.states_[index].GetTransitions().size(); index_transition++) {
      os <<FiniteAutomata.states_[index].GetTransitions()[index_transition] << " ";
    }
    os << std::endl;
  }
  return os;
}