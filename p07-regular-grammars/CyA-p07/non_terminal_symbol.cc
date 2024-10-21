#include "non_terminal_symbol.h"

NonTerminalSymbol::NonTerminalSymbol() {
  id_ = "";
  is_initial_ = false;
  is_final_ = false;
  productions_ = new std::vector<Production>();
}

NonTerminalSymbol::NonTerminalSymbol(std::string& id) {
  id_ = id;
  is_initial_ = false;
  is_final_ = false;
  productions_ = new std::vector<Production>();
}

std::string NonTerminalSymbol::GetId() const {
  return id_;
}

std::vector<Production>* NonTerminalSymbol::GetProductions() const {
  return productions_;
}

std::ostream& operator<<(std::ostream& os, const NonTerminalSymbol& non_terminal_symbol) {
  os << non_terminal_symbol.id_ << " -> ";
  for (auto production : *non_terminal_symbol.productions_) {
    os << production;
  }
  return os;
}

void NonTerminalSymbol::SetIsInitial(bool is_initial) {
  this->is_initial_ = is_initial;
}

void NonTerminalSymbol::SetIsFinal(bool is_final) {
  this->is_final_ = is_final;
}

void NonTerminalSymbol::AddProduction(Production& production) {
  productions_->push_back(production);
}