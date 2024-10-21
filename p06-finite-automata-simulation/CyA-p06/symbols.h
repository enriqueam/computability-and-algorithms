// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  simbolos.h: cabecera de la clase Symbol.
//    Contiene la definición de la clase Symbol.

#include <iostream>

#pragma once

/** 
 * @brief Class Symbol.
 */
class Symbol {
  public:
    /**
     * @brief Construct a new Symbol object
     */
    Symbol();

    /**
     * @brief Construct a new Symbol object
     * @param input_symbol 
     */
    Symbol(std::string& input_symbol);
    
    /**
     * @brief Get the Simbolo object
     * @return std::string 
     */
    Symbol(const std::string& input_symbol);
    
    /**
     * @brief Overload of the operator ==
     * @param input_symbol
     * @return true if the symbols are equal
     */
    bool operator==(const Symbol& input_symbol) const;
    
    /**
     * @brief Overload of the operator !=
     * @param input_symbol
     * @return true if the symbols are not equal
     */
    bool operator!=(const Symbol& input_symbol) const;


    friend std::ostream& operator<<(std::ostream& os, const Symbol& input_symbol);
  private:
    /** @brief Symbol that is a string */
    std::string symbol_;
};