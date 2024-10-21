#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "production.h"
#include "non_terminal_symbol.h"
#include "alphabet.h"
#include "state.h"

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Grammar {
  public:
    /**
     * @brief Construct a new Grammar object
    */
    Grammar();

    /**
     * @brief Construct a new Grammar object
     * @param alphabet 
     * @param states 
    */
    Grammar(Alphabet& alphabet, std::vector<State>& state);

    /**
     * @brief Create non terminal symbols
     * @param number_of_non_terminal_symbols
    */
    void CreateNonTerminalSymbols(int& number_of_non_terminal_symbols, int& index_final_state);

    /**
     * @brief Extract productions
     * @param states 
    */
    void ExtractProductions(std::vector<State>& states);

    /**
     * @brief Overload operator <<
    */
    friend std::ostream& operator<<(std::ostream& os, const Grammar& grammar);
  private:
    /** @brief Terminal symbols */
    Alphabet alphabet_;

    /** @brief Set of Non terminal symbols */
    std::vector<NonTerminalSymbol>* non_terminal_symbols_;

    /** @brief Set of productions */
    std::vector<Production>* productions_;

    /** @brief Boot symbol */
    NonTerminalSymbol* boot_symbol_;
};