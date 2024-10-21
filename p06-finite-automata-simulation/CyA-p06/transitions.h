// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  transitions.h: cabecera de la clase Transition.
//    Contiene la definición de la clase Transition.

#include <iostream>
#include "states.h"
#include "symbols.h"

# pragma once

/**
 * @brief Class Transition. Represent a transition of a Finite Automata.
 */
class Transition {
  public:
    /**
     * @brief Constructor por defecto
     * @param actual_state Estado actual.
     * @param symbol Símbolo a evaluar.
     * @param next_state Estado siguiente.
     */
    Transition(State& actual_state, Symbol& symbol, State& state);

    friend std::ostream& operator<<(std::ostream& os, const Transition& transition);

    /**
     * @brief Método que devuelve el estado actual.
     * @return Estado actual.
     */
    State GetActualState() const;
    
    /**
     * @brief Método que devuelve el estado siguiente.
     * @return Estado siguiente.
     */
    State GetNextState() const;
    
    /**
     * @brief Método que devuelve el símbolo.
     * @return Símbolo.
     */
    Symbol GetSymbol() const;
  private:
    /** @brief Estado actual. */
    State actual_state_;
    /** @brief Estado siguiente. */
    State next_state_;
    /** @brief Símbolo. */
    Symbol symbol_;
};