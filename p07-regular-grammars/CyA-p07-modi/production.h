#ifndef PRODUCTION_H
#define PRODUCTION_H

#include "non_terminal_symbol.h"
#include "symbol.h"

class NonTerminalSymbol;

class Production {
  public:
    /**
     * @brief Construct a new Production object
     */
    Production();

    /**
     * @brief Construct a new Production object
     * @param Symbol
     */
    Production(Symbol& symbol);

    /**
     * @brief Construct a new Production object
     * @param non_terminal_symbol 
     * @param symbol 
     */
    Production(Symbol& symbol, NonTerminalSymbol& non_terminal_symbol);

    /**
     * @brief Return the symbol of the production
     */
    Symbol GetSymbol() const;

    NonTerminalSymbol* GetNonTerminalSymbol() const;

    /**
     * @brief Overload operator <<
     */
    friend std::ostream& operator<<(std::ostream& os, const Production& production);
  private:
    /** @brief Symbol of the production */
    Symbol symbol_;

    /** @brief Non terminal symbol of the production */
    NonTerminalSymbol* non_terminal_symbol_;

};

#endif // PRODUCTION_H