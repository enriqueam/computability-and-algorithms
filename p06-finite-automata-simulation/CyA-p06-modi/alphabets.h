// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  alphabets.h: cabecera de la clase Alphabet.
//    Contiene la declaración de la clase Alphabet.

#include <iostream>
#include <vector>

#include "symbols.h"

#pragma once

/**
 * @brief Class Alphabet.
 */
class Alphabet {
  public:
    /**
     * @brief Construct a new Alphabet object
     */
    Alphabet();

    /**
     * @brief Insert a new Symbol object
     * @param input_symbol 
     */
    void InsertSymbol(Symbol& input_symbol);

    /**
     * @brief Search a symbol in the alphabet
     * @param input_symbol
     * @return true If the symbol is in the alphabet
     * @return false If the symbol is not in the alphabet
     */
    bool SearchSymbol(Symbol& input_symbol);

    /**
     * @brief Overload the operator <<
     * @param os
     * @param input_alphabet
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, const Alphabet& input_alphabet);

    /**
     * @biref Return the size of the alphabet_
     * @return size
     */
    int Size() const;

  private:
    /** @brief Vector of symbols */
    std::vector<Symbol> alphabet_;
};