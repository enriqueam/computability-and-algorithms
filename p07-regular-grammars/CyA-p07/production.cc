#include "production.h"

Production::Production() {
  non_terminal_symbol_ = new NonTerminalSymbol();
  symbol_ = Symbol();
}

Production::Production(Symbol& symbol) {
  symbol_ = symbol;
  non_terminal_symbol_ = nullptr;
}

Production::Production(Symbol& symbol, NonTerminalSymbol& non_terminal_symbol) {
  non_terminal_symbol_ = new NonTerminalSymbol(non_terminal_symbol);
  symbol_ = symbol;
}

Symbol Production::GetSymbol() const {
  return symbol_;
}

std::ostream& operator<<(std::ostream& os, const Production& production) {
  if (production.non_terminal_symbol_ != nullptr) {
    os << production.symbol_ << production.non_terminal_symbol_->GetId() << " ";
  } else {
    os << production.symbol_;
  }
  return os;
}