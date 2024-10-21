// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  strings.h: cabecera de la clase String.
//    Contiene la declaración de la clase String.

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <vector>

#include "symbol.h"
#include "alphabet.h"

#pragma once

const std::string EMPTY = "&";

/**
 * @brief Class String.
 */
class String {
  public:
    /**
     * @brief Construct a new String object
     */
    String();

    /**
     * @brief Construct a new String object
     * @param input_string 
     */
    String(Alphabet& input_alphabet, std::vector<Symbol>& string);

    /**
     * @brief Construct a new String object
     * @param input_string 
     */
    String(Alphabet& input_alphabet, std::string& string);

    /**
     * @brief Set the Alphabet object
     */
    void SetAlphabet(Alphabet& input_alphabet);

    /**
     * @brief =Insert a symbol in the string
     * @param input_symbol 
     */
    void InsertSymbol(Symbol& input_symbol);

    /**
     * @brief Set the empty string
     * @param string A string that is the empty string symbol
     */
    void InsertEmptyString(std::vector<String>& string);

    /**
     * @brief Get the String object
     * @return std::vector<Symbol> 
     */
    std::vector<Symbol> GetCadena();

    /**
     * @brief Overload the operator <<
     * @param os
     * @param input_string
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, String& string);

    /**
     * @brief Overload of the operator ==
     * @param input_string String object to compare
     * @return true if the Strings objects are equal
     */
    bool operator==(String& string);
  private:
    /** @brief String that is a vector of symbols */
    std::vector<Symbol> string_;
    /** @brief The alphabet of the string */
    Alphabet alphabet_;
};

#endif  // STRING_H