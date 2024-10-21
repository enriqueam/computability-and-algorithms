#ifndef NON_TERMINAL_SYMBOL_H
#define NON_TERMINAL_SYMBOL_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "production.h"
#include "symbol.h"

class Production;

class NonTerminalSymbol {
  public:
    /**
     * @brief Construct a new Non Terminal Symbol object
     */
    NonTerminalSymbol();

    /**
     * @brief Construct a new Non Terminal Symbol object
     * @param id String with the id of the non terminal symbol
     */
    NonTerminalSymbol(std::string& id);

    /**
     * @brief Set the non terminal symbol as boot symbol
     * @param boot_symbol Boolean value
     */
    void SetIsInitial(bool is_initial);

    /**
     * @brief Set the non terminal symbol as final symbol
     * @param is_final 
     */
    void SetIsFinal(bool is_final);

    /**
     * @brief Add a production to the non terminal symbol
     * @param production Production to add
     */
    void AddProduction(Production& production);

    /**
     * @brief Return the id of the non terminal symbol
     */
    std::string GetId() const;

    /**
     * @brief Return the productions of the non terminal symbol
     */
    std::vector<Production>* GetProductions() const;

    std::vector<NonTerminalSymbol>* GetNextNonTerminalSymbols(Symbol& symbol) const;

    bool GetIsFinal() const;

    /**
     * @brief Overload operator <<
     */
    friend std::ostream& operator<<(std::ostream& os, const NonTerminalSymbol& non_terminal_symbol);
  private:
    /** @brief Id of the non terminal symbol */
    std::string id_;

    /** @brief Boolean value to know if the non terminal symbol is initial */
    bool is_initial_;

    /** @brief Boolean value to know if the non terminal symbol is final */
    bool is_final_;

    /** @brief Set of productions of the non terminal symbol */
    std::vector<Production>* productions_;
};

#endif // NON_TERMINAL_SYMBOL_H