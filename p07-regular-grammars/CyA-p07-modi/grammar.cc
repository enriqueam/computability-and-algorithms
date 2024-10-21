#include "grammar.h"

Grammar::Grammar() {
  non_terminal_symbols_ = new std::vector<NonTerminalSymbol>();
  boot_symbol_ = new NonTerminalSymbol();
  productions_ = new std::vector<Production>();
}

Grammar::Grammar(Alphabet& alphabet, std::vector<State>& states) {
  boot_symbol_ = new NonTerminalSymbol();
  alphabet_ = alphabet;
  non_terminal_symbols_ = new std::vector<NonTerminalSymbol>();
  productions_ = new std::vector<Production>();
  int number_of_non_terminal_symbols = states.size();
  int index_final_state = 0;
  for (unsigned int index = 0; index < states.size(); index++) {
    if (states[index].GetIsFinal()) {
      index_final_state = index;
    }
  }
  CreateNonTerminalSymbols(number_of_non_terminal_symbols, index_final_state);
  ExtractProductions(states);
}

void Grammar::CreateNonTerminalSymbols(int& number_of_non_terminal_symbols, int& index_final_state) {
  for (int i = 0; i < number_of_non_terminal_symbols; i++) {
    if (i == index_final_state) {
      std::string id = std::string(1, alphabet[i]);      
      NonTerminalSymbol non_terminal_symbol(id);
      non_terminal_symbol.SetIsFinal(true);
      non_terminal_symbols_->push_back(non_terminal_symbol);
    } else {
      std::string id = std::string(1, alphabet[i]);
      NonTerminalSymbol non_terminal_symbol(id);
      non_terminal_symbols_->push_back(non_terminal_symbol);
    }
  }
}

void Grammar::ExtractProductions(std::vector<State>& states) {
  for (unsigned int index = 0; index < states.size(); index++) {
    if (states[index].GetIsInitial()) {
      non_terminal_symbols_->at(index).SetIsInitial(true);
      boot_symbol_ = &non_terminal_symbols_->at(index);
    }
    if (states[index].GetIsFinal()) {
      Symbol symbol("&");
      Production production(symbol);
      non_terminal_symbols_->at(index).AddProduction(production);
      productions_->push_back(production);
    }
    for (unsigned int index_transition = 0; index_transition < states[index].GetTransitions().size(); index_transition++) {
      std::string id_state = states[index].GetTransitions()[index_transition].GetNextState().GetId();
      NonTerminalSymbol non_terminal_symbol = non_terminal_symbols_->at(stoi(id_state));
      Symbol symbol = states[index].GetTransitions()[index_transition].GetSymbol();
      Production production(symbol, non_terminal_symbol);
      productions_->push_back(production);
      non_terminal_symbols_->at(index).AddProduction(production);
    }
    
  }
}

bool Grammar::Resolve(String& String, unsigned int index_cadena, const NonTerminalSymbol* non_terminal_symbol) {
  if (index_cadena == String.GetCadena().size() && non_terminal_symbol->GetIsFinal()) {
    return true;
  }
  std::vector<NonTerminalSymbol>* posibilities = non_terminal_symbol->GetNextNonTerminalSymbols(String.GetCadena()[index_cadena]);
  for (unsigned int index = 0; index < posibilities->size(); index++) {
    if (Resolve(String, index_cadena + 1, &posibilities->at(index))) {
      return true;
    }
  }
  return false;
}

bool Grammar::IsProduced(String& string) {
  std::cout << "String: " << string << std::endl;
  if (Resolve(string, 0, boot_symbol_)) {
    return true;
  } else {
    return false;
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, const Grammar& grammar) {
  /* os << "G = (V, T, P, S)" << std::endl;
  os << "V = {";
  for (auto non_terminal_symbol : *grammar.non_terminal_symbols_) {
    os << non_terminal_symbol.GetId() << ", ";
  }
  os << "}" << std::endl;
  os << "T = {" << grammar.alphabet_ << "}" << std::endl;
  os << "P = {" << std::endl;
  for (auto non_terminal_symbol : *grammar.non_terminal_symbols_) {
    os <<  "  " << non_terminal_symbol << std::endl;
  }
  os << "}" << std::endl;
  os << "S = " << grammar.boot_symbol_->GetId() << std::endl; */
  os << grammar.alphabet_.GetSymbols().size() << std::endl;
  for (auto symbol : grammar.alphabet_.GetSymbols()) {
    os << symbol << std::endl;
  }
  os << grammar.non_terminal_symbols_->size() << std::endl;
  for (auto non_terminal_symbol : *grammar.non_terminal_symbols_) {
    os << non_terminal_symbol.GetId() << std::endl;
  }
  os << grammar.boot_symbol_->GetId() << std::endl;
  os << grammar.productions_->size() << std::endl;
  for (auto non_terminal_symbol : *grammar.non_terminal_symbols_) {
    for (auto production : *non_terminal_symbol.GetProductions()) {
      os << non_terminal_symbol.GetId() << " -> " << production << std::endl;
    }
  }
  return os;
}

